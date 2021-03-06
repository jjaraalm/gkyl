// Gkyl ------------------------------------------------------------------------
//
//    _______     ___
// + 6 @ |||| # P ||| +
//------------------------------------------------------------------------------

#ifndef GKYL_HYPER_DISCONT_H
#define GKYL_HYPER_DISCONT_H

// Gkyl includes
#include <GkylCudaConfig.h>
#include <GkylEquation.h>
#include <GkylCartField.h>

extern "C" 
{
  typedef struct {
      int updateDirs[6];
      bool zeroFluxFlags[6];
      int32_t numUpdateDirs;
      bool updateVolumeTerm;
      double dt;
      GkylEquation_t *equation;
      GkylCartField_t *cflRateByCell;
      GkylCartField_t *maxsByCell;
      double *maxs;
  } GkylHyperDisCont_t;
    
  void advanceOnDevice(const int numBlocks, const int numThreads, const int numComponents, const GkylHyperDisCont_t *hyper, GkylCartField_t *fIn, GkylCartField_t *fRhsOut);
  void advanceOnDevice_shared(int numBlocks, int numThreads, int numComponents, GkylHyperDisCont_t *hyper, GkylCartField_t *fIn, GkylCartField_t *fRhsOut);
  void setDtAndCflRate(GkylHyperDisCont_t *hyper, double dt, GkylCartField_t *cflRate);
}

#endif // GKYL_HYPER_DISCONT_H
