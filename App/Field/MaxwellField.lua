-- Gkyl ------------------------------------------------------------------------
--
-- App support code: Maxwell field objects.
--
--    _______     ___
-- + 6 @ |||| # P ||| +
--------------------------------------------------------------------------------

local AdiosCartFieldIo = require "Io.AdiosCartFieldIo"
local DataStruct       = require "DataStruct"
local FieldBase        = require "App.Field.FieldBase"
local LinearDecomp     = require "Lib.LinearDecomp"
local LinearTrigger    = require "LinearTrigger"
local Mpi              = require "Comm.Mpi"
local PerfMaxwell      = require "Eq.PerfMaxwell"
local Proto            = require "Lib.Proto"
local Time             = require "Lib.Time"
local Updater          = require "Updater"
local BoundaryCondition = require "Updater.BoundaryCondition"
local xsys             = require "xsys"
local ffi              = require "ffi"

-- MaxwellField ---------------------------------------------------------------------
--
-- Electromagnetic field (Maxwell equation are evolved).
--------------------------------------------------------------------------------

local MaxwellField = Proto(FieldBase.FieldBase)

-- Add constants to object indicate various supported boundary conditions.
local EM_BC_REFLECT  = 1
local EM_BC_SYMMETRY = 2
local EM_BC_COPY     = 3
-- AHH: This was 2 but seems that is unstable. So using plain copy.
local EM_BC_OPEN     = EM_BC_COPY

MaxwellField.bcOpen     = EM_BC_OPEN    -- Zero gradient.
MaxwellField.bcCopy     = EM_BC_COPY    -- Copy fields.
MaxwellField.bcReflect  = EM_BC_REFLECT -- Perfect electric conductor.
MaxwellField.bcSymmetry = EM_BC_SYMMETRY

-- Function to check if BC type is good.
local function isBcGood(bcType)
   if bcType == EM_BC_OPEN or bcType == EM_BC_REFLECT or bcType == EM_BC_SYMMETRY then
      return true
   end
   if type(bcType) == "table" then
     return true
   end
   return false
end

-- This ctor simply stores what is passed to it and defers actual
-- construction to the fullInit() method below.
function MaxwellField:init(tbl)
   MaxwellField.super.init(self, tbl)
   self.tbl = tbl
end

-- Actual function for initialization. This indirection is needed as
-- we need the app top-level table for proper initialization.
function MaxwellField:fullInit(appTbl)
   local tbl = self.tbl -- Previously store table.
   
   self.epsilon0 = tbl.epsilon0
   self.mu0 = tbl.mu0
   self.ioMethod = "MPI"
   self.evolve = xsys.pickBool(tbl.evolve, true) -- By default evolve field.
   -- By default, do not write data if evolve is false.
   self.forceWrite = xsys.pickBool(tbl.forceWrite, false)

   self.ce = tbl.elcErrorSpeedFactor and tbl.elcErrorSpeedFactor or 0.0
   self.cb = tbl.mgnErrorSpeedFactor and tbl.mgnErrorSpeedFactor or 1.0

   self.hasMagField = xsys.pickBool(tbl.hasMagneticField, true) -- By default there is a magnetic field.

   self.lightSpeed = 1/math.sqrt(self.epsilon0*self.mu0)

   -- tau parameter used for adding extra (less) diffusion to
   -- Ampere-Maxwell, while adding less (more) diffusion to Faraday
   -- equation if no tau parameter is specified, Eq object defaults to
   -- the speed of light.
   self.tau = tbl.tau

   -- Create triggers to write fields.
   if tbl.nFrame then
      self.ioTrigger = LinearTrigger(0, appTbl.tEnd, tbl.nFrame)
   else
      self.ioTrigger = LinearTrigger(0, appTbl.tEnd, appTbl.nFrame)
   end

   self.ioFrame = 0 -- Frame number for IO.

   self._hasSsBnd = tbl.hasSsBnd
   self._inOutFunc = tbl.inOutFunc

   -- No ghost current by default.
   self.useGhostCurrent = xsys.pickBool(tbl.useGhostCurrent, false)

   -- Store initial condition function (this is a wrapper around user
   -- supplied function as we need to add correction potential ICs
   -- here).
   self.initFunc = function (t, xn)
      local ex, ey, ez, bx, by, bz = tbl.init(t, xn)
      return ex, ey, ez, bx, by, bz, 0.0, 0.0
   end

   self.hasNonPeriodicBc = false -- To indicate if we have non-periodic BCs.
   self.bcx, self.bcy, self.bcz = { }, { }, { }
   
   -- Read in boundary conditions.
   if tbl.bcx then
      self.bcx[1], self.bcx[2] = tbl.bcx[1], tbl.bcx[2]
      assert(isBcGood(self.bcx[1]) and isBcGood(self.bcx[2]), "MaxwellField: Incorrect X BC type specified!")
      self.hasNonPeriodicBc = true
   end
   if tbl.bcy then
      self.bcy[1], self.bcy[2] = tbl.bcy[1], tbl.bcy[2]
      assert(isBcGood(self.bcy[1]) and isBcGood(self.bcy[2]), "MaxwellField: Incorrect Y BC type specified!")
      self.hasNonPeriodicBc = true
   end
   if tbl.bcz then
      self.bcz[1], self.bcz[2] = tbl.bcz[1], tbl.bcz[2]
      assert(isBcGood(self.bcz[1]) and isBcGood(self.bcz[2]), "MaxwellField: Incorrect Z BC type specified!")
      self.hasNonPeriodicBc = true
   end

   -- For storing integrated energy components.
   self.emEnergy = DataStruct.DynVector { numComponents = 8 }

   self.tmCurrentAccum   = 0.0 -- Time spent in current accumulate.
   self.integratedEMTime = 0.0 -- Time spent integrating EM fields.

   -- Create trigger for how frequently to compute integrated EM fields.
   self.calcIntEMQuantFlag = false
   if appTbl.calcIntQuantEvery then
      self.calcIntEMQuantTrigger = LinearTrigger(0, appTbl.tEnd,  math.floor(1/appTbl.calcIntQuantEvery))
   else
      self.calcIntEMQuantFlag = true
   end

   self.limiter = self.tbl.limiter and self.tbl.limiter or "monotonized-centered"

   -- numFlux used for selecting which type of numerical flux function to use
   -- defaults to "upwind" in Eq object, supported options: "central," "upwind"
   -- only used for DG Maxwell.
   self.numFlux = tbl.numFlux

   self._isFirst = true
end

-- Methods for EM field object.
function MaxwellField:hasEB() return true, self.hasMagField end
function MaxwellField:setCfl(cfl) self.cfl = cfl end
function MaxwellField:getCfl() return self.cfl end
function MaxwellField:setIoMethod(ioMethod) self.ioMethod = ioMethod end
function MaxwellField:setBasis(basis) self.basis = basis end
function MaxwellField:setGrid(grid) self.grid = grid end

function MaxwellField:getEpsilon0() return self.epsilon0 end
function MaxwellField:getMu0() return self.mu0 end
function MaxwellField:getElcErrorSpeedFactor() return self.ce end
function MaxwellField:getMgnErrorSpeedFactor() return self.cb end

function MaxwellField:alloc(nRkDup)
   local nGhost = 2
   if self.basis:numBasis() > 1 then
      nGhost = 1
   end
   
   -- Allocate fields needed in RK update.
   self.em = {}
   for i = 1, nRkDup do
      self.em[i] = DataStruct.Field {
	 onGrid        = self.grid,
	 numComponents = 8*self.basis:numBasis(),
	 ghost         = {nGhost, nGhost}
      }
   end
      
   -- Create Adios object for field I/O.
   self.fieldIo = AdiosCartFieldIo {
      elemType = self.em[1]:elemType(),
      method   = self.ioMethod,
      metaData = {
	 polyOrder = self.basis:polyOrder(),
	 basisType = self.basis:id()
      },
   }

   -- Array with one component per cell to store cflRate in each cell.
   self.cflRateByCell = DataStruct.Field {
	onGrid        = self.grid,
	numComponents = 1,
	ghost         = {1, 1},
   }
   self.cflRateByCell:clear(0.0)
   self.cflRatePtr  = self.cflRateByCell:get(1)
   self.cflRateIdxr = self.cflRateByCell:genIndexer()
   self.dt          = ffi.new("double[2]")
   self.dtGlobal    = ffi.new("double[2]")
end

function MaxwellField:createSolver()
   local maxwellEqn = PerfMaxwell {
      lightSpeed          = self.lightSpeed,
      elcErrorSpeedFactor = self.ce,
      mgnErrorSpeedFactor = self.cb,
      tau                 = self.tau,
      numFlux             = self.numFlux,
      basis               = self.basis:numBasis() > 1 and self.basis or nil,
   }

   self.fieldSlvr, self.fieldHyperSlvr = nil, {}
   if self.basis:numBasis() > 1 then
      -- Using DG scheme.
      self.fieldSlvr = Updater.HyperDisCont {
	 onGrid   = self.grid,
	 basis    = self.basis,
	 cfl      = self.cfl,
	 equation = maxwellEqn,
      }
   else
      -- Using FV scheme.
   if self._hasSsBnd then
      self._inOut = DataStruct.Field {
         onGrid        = self.grid,
         numComponents = 1,
         ghost         = {2, 2}
      }
      local project = Updater.ProjectOnBasis {
         onGrid          = self.grid,
         basis           = self.basis,
         evaluate        = self._inOutFunc,
         projectOnGhosts = true,
      }
      project:advance(0.0, {}, {self._inOut})
      self.fieldIo:write(self._inOut, string.format("%s_inOut.bp", self.name), 0, 0)
   end

      local ndim = self.grid:ndim()
      for d = 1, ndim do
	 self.fieldHyperSlvr[d] = Updater.WavePropagation {
	    onGrid           = self.grid,
	    equation         = maxwellEqn,
	    limiter          = self.limiter,
	    cfl              = self.cfl,
	    updateDirections = {d},
            hasSsBnd         = self._hasSsBnd,
            inOut            = self._inOut
	 }
      end
   end

   self.emEnergyCalc = Updater.CartFieldIntegratedQuantCalc {
      onGrid        = self.grid,
      basis         = self.basis,
      numComponents = 8,
      quantity      = "V2"
   }

   -- Function to construct a BC updater.
   local function makeBcUpdater(dir, edge, bcList)
      return Updater.Bc {
	 onGrid             = self.grid,
	 boundaryConditions = bcList,
	 dir                = dir,
	 edge               = edge,
      }
   end

   -- Indices for tangent and normal components of E and B for dir.
   local idxEt = {{2, 3}, {1, 3}, {1, 2}}
   local idxEn = {1, 2, 3}
   local idxBt = {{5, 6}, {4, 6}, {4, 5}}
   local idxBn = {4, 5, 6}

   -- Various functions to apply BCs of different types.
   local function bcOpen(dir, tm, xc, fIn, fOut)
      local nb = self.basis:numBasis()
      local fInData, fOutData = fIn:data(), fOut:data()
      for i = 1, 8 do
	 self.basis:flipSign(dir, fInData+(i-1)*nb-1, fOutData+(i-1)*nb-1)
      end
   end
   local function bcCopy(dir, tm, xc, fIn, fOut)
      for i = 1, 8*self.basis:numBasis() do
	 fOut[i] = fIn[i]
      end
   end 
   local function bcReflect(dir, tm, xc, fIn, fOut)
      local nb = self.basis:numBasis()
      local fInData, fOutData = fIn:data(), fOut:data()
      -- Zero gradient for all the components.
      for i = 1, 8 do
	 self.basis:flipSign(dir, fInData+(i-1)*nb-1, fOutData+(i-1)*nb-1)
      end
      for i = 1, self.basis:numBasis() do
	 -- Zero tangent for electric field.
	 fOutData[(idxEt[dir][1]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxEt[dir][1]-1)*nb + i - 1]
	 fOutData[(idxEt[dir][2]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxEt[dir][2]-1)*nb + i - 1]
	 -- Zero normal for magnetic field.
	 fOutData[(idxBn[dir]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxBn[dir]-1)*nb + i - 1]
      end
   end
   local function bcSymmetry(dir, tm, xc, fIn, fOut)
      local nb = self.basis:numBasis()
      local fInData, fOutData = fIn:data(), fOut:data()
      -- Zero gradient for all the components.
      for i = 1, 8 do
	 self.basis:flipSign(dir, fInData+(i-1)*nb-1, fOutData+(i-1)*nb-1)
      end
      for i = 1, self.basis:numBasis() do
	 -- Zero normal for electric field.
	 fOutData[(idxEn[dir]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxEn[dir]-1)*nb + i - 1]
	 -- Zero tangent for magnetic field.
	 fOutData[(idxBt[dir][1]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxBt[dir][1]-1)*nb + i - 1]
	 fOutData[(idxBt[dir][2]-1)*nb + i - 1] = 
	    -1.0 * fOutData[(idxBt[dir][2]-1)*nb + i - 1]
      end
   end

   -- Functions to make life easier while reading in BCs to apply.
   self.boundaryConditions = { } -- List of Bcs to apply.
   local function appendBoundaryConditions(dir, edge, bcType)
      if bcType == EM_BC_OPEN then
	 table.insert(self.boundaryConditions,
		      makeBcUpdater(dir, edge, { bcCopy }))
      elseif bcType == EM_BC_COPY then
	 table.insert(self.boundaryConditions,
		      makeBcUpdater(dir, edge, { bcCopy }))
      elseif bcType == EM_BC_REFLECT then
	 table.insert(self.boundaryConditions,
		      makeBcUpdater(dir, edge, { bcReflect }))
      elseif bcType == EM_BC_SYMMETRY then
	 table.insert(self.boundaryConditions,
		      makeBcUpdater(dir, edge, { bcSymmetry }))
      elseif type(bcType) == "table" then
	 table.insert(self.boundaryConditions,
		      makeBcUpdater(dir, edge, bcType))
      else
	 assert(false, "MaxwellField: Unsupported BC type!")
      end
   end

   local function handleBc(dir, bc)
      if bc[1] then
	 appendBoundaryConditions(dir, "lower", bc[1])
      end
      if bc[2] then
	 appendBoundaryConditions(dir, "upper", bc[2])
      end
   end
   
   -- Add various BCs to list of BCs to apply.
   handleBc(1, self.bcx)
   handleBc(2, self.bcy)
   handleBc(3, self.bcz)

   self.bcTime = 0.0 -- Timer for BCs.
end

function MaxwellField:createDiagnostics()
end

function MaxwellField:initField()
   local project = Updater.ProjectOnBasis {
      onGrid = self.grid,
      basis = self.basis,
      evaluate = self.initFunc
   }
   project:advance(0.0, {}, {self.em[1]})
   self:applyBc(0.0, self.em[1])
end

function MaxwellField:write(tm, force)
   if self.evolve or self.forceWrite then
      local tmStart = Time.clock()
      -- Compute EM energy integrated over domain.
      if self.calcIntEMQuantFlag == false then
         if self.calcIntEMQuantTrigger(tm) then
            self.emEnergyCalc:advance(tm, { self.em[1] }, { self.emEnergy })
         end
      else
         self.emEnergyCalc:advance(tm, { self.em[1] }, { self.emEnergy })
      end
      -- Time computation of integrated moments.
      self.integratedEMTime = self.integratedEMTime + Time.clock() - tmStart

      if self.ioTrigger(tm) or force then
	 self.fieldIo:write(self.em[1], string.format("field_%d.bp", self.ioFrame), tm, self.ioFrame)
	 self.emEnergy:write(string.format("fieldEnergy_%d.bp", self.ioFrame), tm, self.ioFrame)
	 
	 self.ioFrame = self.ioFrame+1
      end
   else
      -- If not evolving species, don't write anything except initial conditions.
      if self.ioFrame == 0 then
	 self.fieldIo:write(self.em[1], string.format("field_%d.bp", self.ioFrame), tm, self.ioFrame)
      end
      self.ioFrame = self.ioFrame+1
   end
end

function MaxwellField:writeRestart(tm)
   -- (the final "false" prevents writing of ghost cells)
   self.fieldIo:write(self.em[1], "field_restart.bp", tm, self.ioFrame, false)

   -- (the final "false" prevents flushing of data after write)
   self.emEnergy:write("fieldEnergy_restart.bp", tm, self.ioFrame, false)
end

function MaxwellField:readRestart()
   local tm, fr = self.fieldIo:read(self.em[1], "field_restart.bp")
   self:applyBc(tm, self.em[1])
   self.em[1]:sync() -- Must get all ghost-cell data correct.
     
   self.emEnergy:read("fieldEnergy_restart.bp", tm)
   self.ioFrame = fr
   -- Iterate triggers.
   self.ioTrigger(tm)

   return tm
end

function MaxwellField:rkStepperFields()
   return self.em
end

-- For RK timestepping.
function MaxwellField:copyRk(outIdx, aIdx)
   if self:rkStepperFields()[aIdx] then self:rkStepperFields()[outIdx]:copy(self:rkStepperFields()[aIdx]) end
end
-- For RK timestepping
function MaxwellField:combineRk(outIdx, a, aIdx, ...)
   if self:rkStepperFields()[aIdx] then 
      local args  = {...} -- Package up rest of args as table.
      local nFlds = #args/2
      self:rkStepperFields()[outIdx]:combine(a, self:rkStepperFields()[aIdx])
      for i = 1, nFlds do -- Accumulate rest of the fields.
         self:rkStepperFields()[outIdx]:accumulate(args[2*i-1], self:rkStepperFields()[args[2*i]])
      end	 
   end
end
-- Take forwardEuler step 
function MaxwellField:forwardEuler(tCurr, dt, inIdx, outIdx)
   -- NOTE: order of these arguments matters... outIdx must come before inIdx.
   self:combineRk(outIdx, dt, outIdx, 1.0, inIdx)
end

function MaxwellField:suggestDt()
   -- Loop over local region. 
   local grid = self.grid
   self.dt[0] = GKYL_MAX_DOUBLE

   local tId              = grid:subGridSharedId() -- Local thread ID.
   local localRange       = self.cflRateByCell:localRange()
   local localRangeDecomp = LinearDecomp.LinearDecompRange {
	 range = localRange, numSplit = grid:numSharedProcs() }

   for idx in localRangeDecomp:rowMajorIter() do
      -- Calculate local min dt from local cflRates.
      self.cflRateByCell:fill(self.cflRateIdxr(idx), self.cflRatePtr)
      self.dt[0] = math.min(self.dt[0], self.cfl/self.cflRatePtr:data()[0])
   end

   -- All reduce to get global min dt.
   Mpi.Allreduce(self.dt, self.dtGlobal, 1, Mpi.DOUBLE, Mpi.MIN, grid:commSet().comm)

   return math.min(self.dtGlobal[0], GKYL_MAX_DOUBLE)
end

function MaxwellField:clearCFL()
   -- Clear cflRateByCell for next cfl calculation.
   self.cflRateByCell:clear(0.0)
end

function MaxwellField:accumulateCurrent(current, emRhs)
   if current == nil then return end

   -- Barrier before doing accumulating current.
   Mpi.Barrier(self.grid:commSet().sharedComm)

   local tmStart = Time.clock()

   local cItr, eItr   = current:get(1), emRhs:get(1)
   local cIdxr, eIdxr = current:genIndexer(), emRhs:genIndexer()

   -- If we are to use ghost currents, compute mean current first.
   local ghostCurrent = 0.0
   if self.useGhostCurrent then
      local nx               = self.grid:numCells(1)
      local localMeanCurrent = ffi.new("double[2]")
      for idx in emRhs:localRangeIter() do
	 current:fill(cIdxr(idx), cItr)
	 localMeanCurrent[0] = localMeanCurrent[0]+cItr[1]
      end
      local globalMeanCurrent = ffi.new("double[2]")
      Mpi.Allreduce(localMeanCurrent, globalMeanCurrent, 1, Mpi.DOUBLE, Mpi.SUM, self.grid:commSet().comm)
      ghostCurrent = globalMeanCurrent[0]/nx
   end

   for idx in emRhs:localRangeIter() do
      current:fill(cIdxr(idx), cItr)
      emRhs:fill(eIdxr(idx), eItr)
      eItr[1] = eItr[1]-1.0/self.epsilon0*(cItr[1]-ghostCurrent)
      for i = 2, current:numComponents() do
         eItr[i] = eItr[i]-1.0/self.epsilon0*cItr[i]
      end
   end
   self.tmCurrentAccum = self.tmCurrentAccum + Time.clock()-tmStart
end

function MaxwellField:advance(tCurr, species, inIdx, outIdx)
   if self._isFirst then
      -- Create field for total current density. need to do this here because
      -- field object does not know about vdim.
      do
         local c = 0
         for _, s in pairs(species) do
            if c == 0 then
               self.currentDens = s:allocMomCouplingFields().currentDensity
            end
            c = c+1
         end
      end
      self._isFirst = false
   end

   local emIn     = self:rkStepperFields()[inIdx]
   local emRhsOut = self:rkStepperFields()[outIdx]
   if self.evolve then
      self.fieldSlvr:setDtAndCflRate(self.dtGlobal[0], self.cflRateByCell)
      self.fieldSlvr:advance(tCurr, {emIn}, {emRhsOut})
      if self.currentDens then -- No currents for source-free Maxwell.
	 self.currentDens:clear(0.0)
	 for nm, s in pairs(species) do
	    self.currentDens:accumulate(s:getCharge(), s:getMomDensity())
	 end
	 self:accumulateCurrent(self.currentDens, emRhsOut)
      end
   else
      emRhsOut:clear(0.0) -- no RHS
   end
end

function MaxwellField:updateInDirection(dir, tCurr, dt, fIn, fOut)
   local status, dtSuggested = true, GKYL_MAX_DOUBLE
   if self.evolve then
      self:applyBc(tCurr, fIn)
      self.fieldHyperSlvr[dir]:setDtAndCflRate(dt, nil)
      status, dtSuggested = self.fieldHyperSlvr[dir]:advance(tCurr, {fIn}, {fOut})
   else
      fOut:copy(fIn)
   end
   return status, dtSuggested   
end

function MaxwellField:applyBcIdx(tCurr, idx)
   self:applyBc(tCurr, self:rkStepperFields()[idx])
end 

function MaxwellField:applyBc(tCurr, emIn)
   local tmStart = Time.clock()
   if self.hasNonPeriodicBc then
      for _, bc in ipairs(self.boundaryConditions) do
	 bc:advance(tCurr, {}, {emIn})
      end
   end   
   emIn:sync()
   self.bcTime = self.bcTime + Time.clock()-tmStart
end
 
MaxwellField.bcConst = function(Ex, Ey, Ez, Bx, By, Bz, phiE, phiB)
   local bc = BoundaryCondition.Const {
      components = {1, 2, 3, 4, 5, 6, 7, 8},
      values     = {Ex, Ey, Ez, Bx, By, Bz, phiE, phiB}
   }
   return { bc }
end
  
function MaxwellField:totalSolverTime()
   local ftm = 0.0
   if self.fieldSlvr then
      ftm = self.fieldSlvr.totalTime
   else
      for d = 1, self.grid:ndim() do
	 ftm = ftm+self.fieldHyperSlvr[d].totalTime
      end
   end
   return ftm + self.tmCurrentAccum
end

function MaxwellField:totalBcTime()
   return self.bcTime
end

function MaxwellField:energyCalcTime()
   return self.integratedEMTime
end

-- FuncMaxwellField ---------------------------------------------------------------------
--
-- A field object with EM fields specified as a time-dependent function.
--------------------------------------------------------------------------------

local FuncMaxwellField = Proto(FieldBase.FuncFieldBase)

-- Methods for no field object.
function FuncMaxwellField:init(tbl)
   FuncMaxwellField.super.init(self, tbl)
   self.tbl = tbl
end

function FuncMaxwellField:fullInit(appTbl)
   local tbl = self.tbl -- Previously store table.

   self.ioMethod = "MPI"
   self.evolve = xsys.pickBool(tbl.evolve, true) -- By default evolve field.

   -- Create triggers to write fields.
   if tbl.nFrame then
      self.ioTrigger = LinearTrigger(0, appTbl.tEnd, tbl.nFrame)
   else
      self.ioTrigger = LinearTrigger(0, appTbl.tEnd, appTbl.nFrame)
   end

   self.ioFrame = 0 -- Frame number for IO.
   
   -- Store function to compute EM field.
   self.emFunc = function (t, xn)
      local ex, ey, ez, bx, by, bz = tbl.emFunc(t, xn)
      return ex, ey, ez, bx, by, bz, 0.0, 0.0
   end
end

function FuncMaxwellField:hasEB()
   return true, true
end

function FuncMaxwellField:setCfl() end
function FuncMaxwellField:setIoMethod(ioMethod) self.ioMethod = ioMethod end
function FuncMaxwellField:setBasis(basis) self.basis = basis end
function FuncMaxwellField:setGrid(grid) self.grid = grid end

function FuncMaxwellField:alloc(nField)
   -- Allocate fields needed in RK update.
   self.em = DataStruct.Field {
      onGrid        = self.grid,
      numComponents = 8*self.basis:numBasis(),
      ghost         = {1, 1}
   }
      
   -- Create Adios object for field I/O.
   self.fieldIo = AdiosCartFieldIo {
      elemType = self.em:elemType(),
      method   = self.ioMethod,
      metaData = {
	 polyOrder = self.basis:polyOrder(),
	 basisType = self.basis:id()
      },

   }   
end

function FuncMaxwellField:createSolver()
   self.fieldSlvr = Updater.ProjectOnBasis {
      onGrid   = self.grid,
      basis    = self.basis,
      evaluate = self.emFunc
   }
end

function FuncMaxwellField:createDiagnostics()
end

function FuncMaxwellField:initField()
   self.fieldSlvr:advance(0.0, {}, {self.em})
   self:applyBc(0.0, self.em)
end

function FuncMaxwellField:write(tm, force)
   if self.evolve or self.forceWrite then
      if self.ioTrigger(tm) or force then
	 self.fieldIo:write(self.em, string.format("func_field_%d.bp", self.ioFrame), tm, self.ioFrame)
	 
	 self.ioFrame = self.ioFrame+1
      end
   else
      -- If not evolving species, don't write anything except initial conditions.
      if self.ioFrame == 0 then
	 self.fieldIo:write(self.em, string.format("func_field_%d.bp", self.ioFrame), tm, self.ioFrame)
      end
      self.ioFrame = self.ioFrame+1
   end
end

function FuncMaxwellField:writeRestart(tm)
   self.fieldIo:write(self.em, "func_field_restart.bp", tm, self.ioFrame)
end

function FuncMaxwellField:readRestart()
   local tm, fr = self.fieldIo:read(self.em, "func_field_restart.bp")
   self.em:sync() -- Must get all ghost-cell data correct.
   
   self.ioFrame = fr
end

function FuncMaxwellField:rkStepperFields()
   return { self.em, self.em, self.em, self.em }
end

function FuncMaxwellField:advance(tCurr)
   local emOut = self:rkStepperFields()[1]
   if self.evolve then
      self.fieldSlvr:advance(tCurr, {}, {emOut})
      self:applyBc(tCurr, emOut)
   end
end

function FuncMaxwellField:applyBcIdx(tCurr, idx)
   self:applyBc(tCurr, self:rkStepperFields()[1])
end

function FuncMaxwellField:applyBc(tCurr, emIn)
   emIn:sync()
end

function FuncMaxwellField:totalSolverTime()
   return self.fieldSlvr.totalTime
end

function FuncMaxwellField:totalBcTime() return 0.0 end
function FuncMaxwellField:energyCalcTime() return 0.0 end

return {
   MaxwellField     = MaxwellField,
   FuncMaxwellField = FuncMaxwellField,
}
