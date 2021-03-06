-- Gkyl ------------------------------------------------------------------------
--
-- Test for Euler equations
--    _______     ___
-- + 6 @ |||| # P ||| +
--------------------------------------------------------------------------------

local ffi  = require "ffi"
local Unit = require "Unit"
local Euler = require "Eq.Euler"
local Lin = require "Lib.Linalg"

local assert_equal = Unit.assert_equal
local stats = Unit.stats

function test_1()
   local euler = Euler { gasGamma = 1.4 }

   assert_equal(5, euler:numEquations(), "No of equations")
   assert_equal(3, euler:numWaves(), "No of wave")

   local rho, u, v, w, pr = 1.0, 2.1, 3.1, 4.1, 0.1
   local q = Lin.Vec(5)
   q[1] = rho
   q[2], q[3], q[4] = rho*u, rho*v, rho*w
   q[5] = pr/(euler:gasGamma()-1) + 0.5*rho*(u*u+v*v+w*w)

   local prOut = euler:pressure(q)
   assert_equal(pr, prOut, "Checking pressure")

   local flux = Lin.Vec(5)
   euler:flux(1, q, flux)
   assert_equal(flux[1], rho*u, "Checking flux")
   assert_equal(flux[2], rho*u*u+pr, "Checking flux")
   assert_equal(flux[3], rho*u*v, "Checking flux")
   assert_equal(flux[4], rho*u*w, "Checking flux")
   assert_equal(flux[5], (q[5]+pr)*u, "Checking flux")

   rho , u, v, w, pr = -1.0, 1.0, 0.0, 0.0, 0.1
   q[1] = rho
   q[2], q[3], q[4] = rho*u, rho*v, rho*w
   q[5] = pr/(euler:gasGamma()-1) + 0.5*rho*(u*u+v*v+w*w)
   assert_equal(false, euler:isPositive(q), "Checking positivity")

   rho , u, v, w, pr = 1.0, 1.0, 0.0, 0.0, -0.1
   q[1] = rho
   q[2], q[3], q[4] = rho*u, rho*v, rho*w
   q[5] = pr/(euler:gasGamma()-1) + 0.5*rho*(u*u+v*v+w*w)
   assert_equal(false, euler:isPositive(q), "Checking positivity")
end

local function calcq(gg, v)
   local rho, u, v, w, pr = v[1], v[2], v[3], v[4], v[5]
   q = Lin.Vec(5)
   q[1] = rho
   q[2], q[3], q[4] = rho*u, rho*v, rho*w
   q[5] = pr/(gg-1) + 0.5*rho*(u*u+v*v+w*w)
   return q
end

function test_2()
   local euler = Euler { gasGamma = 1.4 }

   local ql = calcq(euler:gasGamma(), {1.0, 1.0, 0.0, 0.0, 1.0})
   local qr = calcq(euler:gasGamma(), {0.1, 1.0, 0.0, 0.0, 1.0})

   local delta = Lin.Vec(5)
   for m = 1, 5 do delta[m] = qr[m]-ql[m] end

   local waves = Lin.Mat(euler:numWaves(), euler:numEquations())
   local s = Lin.Vec(5)
   euler:rp(1, delta, ql, qr, waves, s)
   local amdq, apdq = Lin.Vec(5), Lin.Vec(5)
   euler:qFluctuations(1, ql, qr, waves, s, amdq, apdq)

   local sumFluct = Lin.Vec(5)
   for m = 1, 5 do sumFluct[m] = amdq[m]+apdq[m] end
   local fluxr, fluxl, df = Lin.Vec(5), Lin.Vec(5), Lin.Vec(5)
   euler:flux(1, ql, fluxl)
   euler:flux(1, qr, fluxr)
   for m = 1, 5 do df[m] = fluxr[m]-fluxl[m] end

   for m = 1, 5 do
      assert_equal(df[m], sumFluct[m], "Checking jump in flux is sum of fluctuations")
   end
end

function test_3()
   local euler = Euler { gasGamma = 1.4 }

   local ql = calcq(euler:gasGamma(), {0.1, 2.0, 3.0, 4.0, 0.1})
   local qr = calcq(euler:gasGamma(), {1.0, 1.0, 2.0, 3.0, 1.0})

   local delta = Lin.Vec(5)
   for m = 1, 5 do delta[m] = qr[m]-ql[m] end

   local waves = Lin.Mat(euler:numWaves(), euler:numEquations())
   local s = Lin.Vec(5)
   euler:rp(1, delta, ql, qr, waves, s)
   local amdq, apdq = Lin.Vec(5), Lin.Vec(5)
   euler:qFluctuations(1, ql, qr, waves, s, amdq, apdq)

   local sumFluct = Lin.Vec(5)
   for m = 1, 5 do sumFluct[m] = amdq[m]+apdq[m] end
   local fluxr, fluxl, df = Lin.Vec(5), Lin.Vec(5), Lin.Vec(5)
   euler:flux(1, ql, fluxl)
   euler:flux(1, qr, fluxr)
   for m = 1, 5 do df[m] = fluxr[m]-fluxl[m] end

   for m = 1, 5 do
      assert_equal(df[m], sumFluct[m], "Checking jump in flux is sum of fluctuations")
   end
end

function test_4()
   local euler = Euler {
      gasGamma = 1.4,
      numericalFlux = "lax",
   }

   assert_equal(5, euler:numEquations(), "No of equations")
   assert_equal(1, euler:numWaves(), "No of wave")

   local ql = calcq(euler:gasGamma(), {0.1, 2.0, 3.0, 4.0, 0.1})
   local qr = calcq(euler:gasGamma(), {1.0, 1.0, 2.0, 3.0, 1.0})

   local delta = Lin.Vec(5)
   for m = 1, 5 do delta[m] = qr[m]-ql[m] end

   local waves = Lin.Mat(euler:numWaves(), euler:numEquations())
   local s = Lin.Vec(5)
   euler:rp(1, delta, ql, qr, waves, s)
   local amdq, apdq = Lin.Vec(5), Lin.Vec(5)
   euler:qFluctuations(1, ql, qr, waves, s, amdq, apdq)

   local sumFluct = Lin.Vec(5)
   for m = 1, 5 do sumFluct[m] = amdq[m]+apdq[m] end
   local fluxr, fluxl, df = Lin.Vec(5), Lin.Vec(5), Lin.Vec(5)
   euler:flux(1, ql, fluxl)
   euler:flux(1, qr, fluxr)
   for m = 1, 5 do df[m] = fluxr[m]-fluxl[m] end

   for m = 1, 5 do
      assert_equal(df[m], sumFluct[m], "Checking jump in flux is sum of fluctuations")
   end
end

function test_5()
   local euler = Euler { gasGamma = 1.4 }
   local bcConst = Euler:bcConst(1.0, 0.0, 0.0, 0.1)
end

test_1()
test_2()
test_3()
test_4()
test_5()

if stats.fail > 0 then
   print(string.format("\nPASSED %d tests", stats.pass))
   print(string.format("**** FAILED %d tests", stats.fail))
else
   print(string.format("PASSED ALL %d tests!", stats.pass))
end
