#include <math.h> 
#include <DistFuncMomentCalcModDecl.h> 
void GkMomentCalc2x2vMax_Dens_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  out[0] += 2.0*f[0]*volFact; 
  out[1] += 2.0*f[1]*volFact; 
  out[2] += 2.0*f[2]*volFact; 
} 
void GkMomentCalc2x2vMax_Dens_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  out[0] += 2.0*f[0]*volFact; 
  out[1] += 2.0*f[1]*volFact; 
  out[2] += 2.0*f[2]*volFact; 
  out[3] += 2.0*f[5]*volFact; 
  out[4] += 2.0*f[11]*volFact; 
  out[5] += 2.0*f[12]*volFact; 
} 
void GkMomentCalc2x2vMax_Dens_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  out[0] += 2.0*f[0]*volFact; 
  out[1] += 2.0*f[1]*volFact; 
  out[2] += 2.0*f[2]*volFact; 
  out[3] += 2.0*f[5]*volFact; 
  out[4] += 2.0*f[11]*volFact; 
  out[5] += 2.0*f[12]*volFact; 
  out[6] += 2.0*f[19]*volFact; 
  out[7] += 2.0*f[20]*volFact; 
  out[8] += 2.0*f[31]*volFact; 
  out[9] += 2.0*f[32]*volFact; 
} 
void GkMomentCalc2x2vMax_Dens_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  out[0] += 2.0*f[0]*volFact; 
  out[1] += 2.0*f[1]*volFact; 
  out[2] += 2.0*f[2]*volFact; 
  out[3] += 2.0*f[5]*volFact; 
  out[4] += 2.0*f[11]*volFact; 
  out[5] += 2.0*f[12]*volFact; 
  out[6] += 2.0*f[19]*volFact; 
  out[7] += 2.0*f[20]*volFact; 
  out[8] += 2.0*f[31]*volFact; 
  out[9] += 2.0*f[32]*volFact; 
  out[10] += 2.0*f[48]*volFact; 
  out[11] += 2.0*f[54]*volFact; 
  out[12] += 2.0*f[55]*volFact; 
  out[13] += 2.0*f[66]*volFact; 
  out[14] += 2.0*f[67]*volFact; 
} 
void GkMomentCalc2x2vMax_Upar_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1+0.5773502691896258*f[3]*dv1*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1; 
  out[2] += 2.0*f[2]*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Upar_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1+0.5773502691896258*f[3]*dv1*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1+0.5773502691896258*f[6]*dv1*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1+0.5773502691896258*f[7]*dv1*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1; 
  out[4] += 2.0*f[11]*volFact*wx1; 
  out[5] += 2.0*f[12]*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Upar_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1+0.5773502691896258*f[3]*dv1*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1+0.5773502691896258*f[6]*dv1*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1+0.5773502691896258*f[7]*dv1*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1+0.5773502691896258*f[15]*dv1*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1+0.5773502691896257*f[21]*dv1*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1+0.5773502691896257*f[22]*dv1*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1; 
  out[7] += 2.0*f[20]*volFact*wx1; 
  out[8] += 2.0*f[31]*volFact*wx1; 
  out[9] += 2.0*f[32]*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Upar_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1+0.5773502691896258*f[3]*dv1*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1+0.5773502691896258*f[6]*dv1*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1+0.5773502691896258*f[7]*dv1*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1+0.5773502691896258*f[15]*dv1*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1+0.5773502691896257*f[21]*dv1*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1+0.5773502691896257*f[22]*dv1*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1+0.5773502691896257*f[36]*dv1*volFact; 
  out[7] += 2.0*f[20]*volFact*wx1+0.5773502691896257*f[37]*dv1*volFact; 
  out[8] += 2.0*f[31]*volFact*wx1+0.5773502691896256*f[56]*dv1*volFact; 
  out[9] += 2.0*f[32]*volFact*wx1+0.5773502691896256*f[57]*dv1*volFact; 
  out[10] += 2.0*f[48]*volFact*wx1; 
  out[11] += 2.0*f[54]*volFact*wx1; 
  out[12] += 2.0*f[55]*volFact*wx1; 
  out[13] += 2.0*f[66]*volFact*wx1; 
  out[14] += 2.0*f[67]*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Ppar_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1_sq+1.154700538379252*f[3]*dv1*volFact*wx1+0.1666666666666667*f[0]*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1_sq+0.1666666666666667*f[1]*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1_sq+0.1666666666666667*f[2]*dv1_sq*volFact; 
} 
void GkMomentCalc2x2vMax_Ppar_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1_sq+1.154700538379252*f[3]*dv1*volFact*wx1+0.149071198499986*f[13]*dv1_sq*volFact+0.1666666666666667*f[0]*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1_sq+1.154700538379252*f[6]*dv1*volFact*wx1+0.1666666666666667*f[1]*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1_sq+1.154700538379252*f[7]*dv1*volFact*wx1+0.1666666666666667*f[2]*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1_sq+0.1666666666666667*f[5]*dv1_sq*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1_sq+0.1666666666666667*f[11]*dv1_sq*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1_sq+0.1666666666666667*f[12]*dv1_sq*volFact; 
} 
void GkMomentCalc2x2vMax_Ppar_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1_sq+1.154700538379252*f[3]*dv1*volFact*wx1+0.149071198499986*f[13]*dv1_sq*volFact+0.1666666666666667*f[0]*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1_sq+1.154700538379252*f[6]*dv1*volFact*wx1+0.149071198499986*f[23]*dv1_sq*volFact+0.1666666666666667*f[1]*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1_sq+1.154700538379252*f[7]*dv1*volFact*wx1+0.149071198499986*f[24]*dv1_sq*volFact+0.1666666666666667*f[2]*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1_sq+1.154700538379252*f[15]*dv1*volFact*wx1+0.1666666666666667*f[5]*dv1_sq*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1_sq+1.154700538379251*f[21]*dv1*volFact*wx1+0.1666666666666667*f[11]*dv1_sq*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1_sq+1.154700538379251*f[22]*dv1*volFact*wx1+0.1666666666666667*f[12]*dv1_sq*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1_sq+0.1666666666666667*f[19]*dv1_sq*volFact; 
  out[7] += 2.0*f[20]*volFact*wx1_sq+0.1666666666666667*f[20]*dv1_sq*volFact; 
  out[8] += 2.0*f[31]*volFact*wx1_sq+0.1666666666666667*f[31]*dv1_sq*volFact; 
  out[9] += 2.0*f[32]*volFact*wx1_sq+0.1666666666666667*f[32]*dv1_sq*volFact; 
} 
void GkMomentCalc2x2vMax_Ppar_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1_sq+1.154700538379252*f[3]*dv1*volFact*wx1+0.149071198499986*f[13]*dv1_sq*volFact+0.1666666666666667*f[0]*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1_sq+1.154700538379252*f[6]*dv1*volFact*wx1+0.149071198499986*f[23]*dv1_sq*volFact+0.1666666666666667*f[1]*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1_sq+1.154700538379252*f[7]*dv1*volFact*wx1+0.149071198499986*f[24]*dv1_sq*volFact+0.1666666666666667*f[2]*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1_sq+1.154700538379252*f[15]*dv1*volFact*wx1+0.149071198499986*f[38]*dv1_sq*volFact+0.1666666666666667*f[5]*dv1_sq*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1_sq+1.154700538379251*f[21]*dv1*volFact*wx1+0.149071198499986*f[49]*dv1_sq*volFact+0.1666666666666667*f[11]*dv1_sq*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1_sq+1.154700538379251*f[22]*dv1*volFact*wx1+0.149071198499986*f[50]*dv1_sq*volFact+0.1666666666666667*f[12]*dv1_sq*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1_sq+1.154700538379251*f[36]*dv1*volFact*wx1+0.1666666666666667*f[19]*dv1_sq*volFact; 
  out[7] += 2.0*f[20]*volFact*wx1_sq+1.154700538379251*f[37]*dv1*volFact*wx1+0.1666666666666667*f[20]*dv1_sq*volFact; 
  out[8] += 2.0*f[31]*volFact*wx1_sq+1.154700538379251*f[56]*dv1*volFact*wx1+0.1666666666666667*f[31]*dv1_sq*volFact; 
  out[9] += 2.0*f[32]*volFact*wx1_sq+1.154700538379251*f[57]*dv1*volFact*wx1+0.1666666666666667*f[32]*dv1_sq*volFact; 
  out[10] += 2.0*f[48]*volFact*wx1_sq+0.1666666666666667*f[48]*dv1_sq*volFact; 
  out[11] += 2.0*f[54]*volFact*wx1_sq+0.1666666666666667*f[54]*dv1_sq*volFact; 
  out[12] += 2.0*f[55]*volFact*wx1_sq+0.1666666666666667*f[55]*dv1_sq*volFact; 
  out[13] += 2.0*f[66]*volFact*wx1_sq+0.1666666666666667*f[66]*dv1_sq*volFact; 
  out[14] += 2.0*f[67]*volFact*wx1_sq+0.1666666666666667*f[67]*dv1_sq*volFact; 
} 
void GkMomentCalc2x2vMax_Pperp_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx2; 
  out[2] += 2.0*f[2]*volFact*wx2; 
} 
void GkMomentCalc2x2vMax_Pperp_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact; 
  out[2] += 2.0*f[2]*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact; 
  out[3] += 2.0*f[5]*volFact*wx2; 
  out[4] += 2.0*f[11]*volFact*wx2; 
  out[5] += 2.0*f[12]*volFact*wx2; 
} 
void GkMomentCalc2x2vMax_Pperp_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact; 
  out[2] += 2.0*f[2]*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact; 
  out[3] += 2.0*f[5]*volFact*wx2+0.5773502691896258*f[16]*dv2*volFact; 
  out[4] += 2.0*f[11]*volFact*wx2+0.5773502691896257*f[25]*dv2*volFact; 
  out[5] += 2.0*f[12]*volFact*wx2+0.5773502691896257*f[26]*dv2*volFact; 
  out[6] += 2.0*f[19]*volFact*wx2; 
  out[7] += 2.0*f[20]*volFact*wx2; 
  out[8] += 2.0*f[31]*volFact*wx2; 
  out[9] += 2.0*f[32]*volFact*wx2; 
} 
void GkMomentCalc2x2vMax_Pperp_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact; 
  out[2] += 2.0*f[2]*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact; 
  out[3] += 2.0*f[5]*volFact*wx2+0.5773502691896258*f[16]*dv2*volFact; 
  out[4] += 2.0*f[11]*volFact*wx2+0.5773502691896257*f[25]*dv2*volFact; 
  out[5] += 2.0*f[12]*volFact*wx2+0.5773502691896257*f[26]*dv2*volFact; 
  out[6] += 2.0*f[19]*volFact*wx2+0.5773502691896257*f[39]*dv2*volFact; 
  out[7] += 2.0*f[20]*volFact*wx2+0.5773502691896257*f[40]*dv2*volFact; 
  out[8] += 2.0*f[31]*volFact*wx2+0.5773502691896256*f[60]*dv2*volFact; 
  out[9] += 2.0*f[32]*volFact*wx2+0.5773502691896256*f[61]*dv2*volFact; 
  out[10] += 2.0*f[48]*volFact*wx2; 
  out[11] += 2.0*f[54]*volFact*wx2; 
  out[12] += 2.0*f[55]*volFact*wx2; 
  out[13] += 2.0*f[66]*volFact*wx2; 
  out[14] += 2.0*f[67]*volFact*wx2; 
} 
void GkMomentCalc2x2vMax_Qpar_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx1_cu = wx1*wx1*wx1, dv1_cu = dv1*dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  const double wx2_cu = wx2*wx2*wx2, dv2_cu = dv2*dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1*wx1_sq+1.732050807568877*f[3]*dv1*volFact*wx1_sq+0.5*f[0]*dv1_sq*volFact*wx1+0.08660254037844387*f[3]*dv1*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx1_sq+0.5*f[1]*dv1_sq*volFact*wx1; 
  out[2] += 2.0*f[2]*volFact*wx1*wx1_sq+0.5*f[2]*dv1_sq*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Qpar_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx1_cu = wx1*wx1*wx1, dv1_cu = dv1*dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  const double wx2_cu = wx2*wx2*wx2, dv2_cu = dv2*dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1*wx1_sq+1.732050807568877*f[3]*dv1*volFact*wx1_sq+0.4472135954999579*f[13]*dv1_sq*volFact*wx1+0.5*f[0]*dv1_sq*volFact*wx1+0.08660254037844387*f[3]*dv1*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx1_sq+1.732050807568877*f[6]*dv1*volFact*wx1_sq+0.5*f[1]*dv1_sq*volFact*wx1+0.08660254037844387*f[6]*dv1*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1*wx1_sq+1.732050807568877*f[7]*dv1*volFact*wx1_sq+0.5*f[2]*dv1_sq*volFact*wx1+0.08660254037844387*f[7]*dv1*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1*wx1_sq+0.5*f[5]*dv1_sq*volFact*wx1; 
  out[4] += 2.0*f[11]*volFact*wx1*wx1_sq+0.5*f[11]*dv1_sq*volFact*wx1; 
  out[5] += 2.0*f[12]*volFact*wx1*wx1_sq+0.5*f[12]*dv1_sq*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Qpar_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx1_cu = wx1*wx1*wx1, dv1_cu = dv1*dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  const double wx2_cu = wx2*wx2*wx2, dv2_cu = dv2*dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1*wx1_sq+1.732050807568877*f[3]*dv1*volFact*wx1_sq+0.4472135954999579*f[13]*dv1_sq*volFact*wx1+0.5*f[0]*dv1_sq*volFact*wx1+0.03779644730092272*f[33]*dv1*dv1_sq*volFact+0.08660254037844387*f[3]*dv1*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx1_sq+1.732050807568877*f[6]*dv1*volFact*wx1_sq+0.447213595499958*f[23]*dv1_sq*volFact*wx1+0.5*f[1]*dv1_sq*volFact*wx1+0.08660254037844387*f[6]*dv1*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1*wx1_sq+1.732050807568877*f[7]*dv1*volFact*wx1_sq+0.447213595499958*f[24]*dv1_sq*volFact*wx1+0.5*f[2]*dv1_sq*volFact*wx1+0.08660254037844387*f[7]*dv1*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1*wx1_sq+1.732050807568877*f[15]*dv1*volFact*wx1_sq+0.5*f[5]*dv1_sq*volFact*wx1+0.08660254037844387*f[15]*dv1*dv1_sq*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1*wx1_sq+1.732050807568877*f[21]*dv1*volFact*wx1_sq+0.5*f[11]*dv1_sq*volFact*wx1+0.08660254037844385*f[21]*dv1*dv1_sq*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1*wx1_sq+1.732050807568877*f[22]*dv1*volFact*wx1_sq+0.5*f[12]*dv1_sq*volFact*wx1+0.08660254037844385*f[22]*dv1*dv1_sq*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1*wx1_sq+0.5*f[19]*dv1_sq*volFact*wx1; 
  out[7] += 2.0*f[20]*volFact*wx1*wx1_sq+0.5*f[20]*dv1_sq*volFact*wx1; 
  out[8] += 2.0*f[31]*volFact*wx1*wx1_sq+0.5*f[31]*dv1_sq*volFact*wx1; 
  out[9] += 2.0*f[32]*volFact*wx1*wx1_sq+0.5*f[32]*dv1_sq*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Qpar_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx1_sq = wx1*wx1, dv1_sq = dv1*dv1; 
  const double wx1_cu = wx1*wx1*wx1, dv1_cu = dv1*dv1*dv1; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  const double wx2_sq = wx2*wx2, dv2_sq = dv2*dv2; 
  const double wx2_cu = wx2*wx2*wx2, dv2_cu = dv2*dv2*dv2; 
  out[0] += 2.0*f[0]*volFact*wx1*wx1_sq+1.732050807568877*f[3]*dv1*volFact*wx1_sq+0.4472135954999579*f[13]*dv1_sq*volFact*wx1+0.5*f[0]*dv1_sq*volFact*wx1+0.03779644730092272*f[33]*dv1*dv1_sq*volFact+0.08660254037844387*f[3]*dv1*dv1_sq*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx1_sq+1.732050807568877*f[6]*dv1*volFact*wx1_sq+0.447213595499958*f[23]*dv1_sq*volFact*wx1+0.5*f[1]*dv1_sq*volFact*wx1+0.03779644730092273*f[58]*dv1*dv1_sq*volFact+0.08660254037844387*f[6]*dv1*dv1_sq*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1*wx1_sq+1.732050807568877*f[7]*dv1*volFact*wx1_sq+0.447213595499958*f[24]*dv1_sq*volFact*wx1+0.5*f[2]*dv1_sq*volFact*wx1+0.03779644730092273*f[59]*dv1*dv1_sq*volFact+0.08660254037844387*f[7]*dv1*dv1_sq*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1*wx1_sq+1.732050807568877*f[15]*dv1*volFact*wx1_sq+0.4472135954999579*f[38]*dv1_sq*volFact*wx1+0.5*f[5]*dv1_sq*volFact*wx1+0.08660254037844387*f[15]*dv1*dv1_sq*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1*wx1_sq+1.732050807568877*f[21]*dv1*volFact*wx1_sq+0.4472135954999579*f[49]*dv1_sq*volFact*wx1+0.5*f[11]*dv1_sq*volFact*wx1+0.08660254037844385*f[21]*dv1*dv1_sq*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1*wx1_sq+1.732050807568877*f[22]*dv1*volFact*wx1_sq+0.4472135954999579*f[50]*dv1_sq*volFact*wx1+0.5*f[12]*dv1_sq*volFact*wx1+0.08660254037844385*f[22]*dv1*dv1_sq*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1*wx1_sq+1.732050807568877*f[36]*dv1*volFact*wx1_sq+0.5*f[19]*dv1_sq*volFact*wx1+0.08660254037844385*f[36]*dv1*dv1_sq*volFact; 
  out[7] += 2.0*f[20]*volFact*wx1*wx1_sq+1.732050807568877*f[37]*dv1*volFact*wx1_sq+0.5*f[20]*dv1_sq*volFact*wx1+0.08660254037844385*f[37]*dv1*dv1_sq*volFact; 
  out[8] += 2.0*f[31]*volFact*wx1*wx1_sq+1.732050807568877*f[56]*dv1*volFact*wx1_sq+0.5*f[31]*dv1_sq*volFact*wx1+0.08660254037844385*f[56]*dv1*dv1_sq*volFact; 
  out[9] += 2.0*f[32]*volFact*wx1*wx1_sq+1.732050807568877*f[57]*dv1*volFact*wx1_sq+0.5*f[32]*dv1_sq*volFact*wx1+0.08660254037844385*f[57]*dv1*dv1_sq*volFact; 
  out[10] += 2.0*f[48]*volFact*wx1*wx1_sq+0.5*f[48]*dv1_sq*volFact*wx1; 
  out[11] += 2.0*f[54]*volFact*wx1*wx1_sq+0.5*f[54]*dv1_sq*volFact*wx1; 
  out[12] += 2.0*f[55]*volFact*wx1*wx1_sq+0.5*f[55]*dv1_sq*volFact*wx1; 
  out[13] += 2.0*f[66]*volFact*wx1*wx1_sq+0.5*f[66]*dv1_sq*volFact*wx1; 
  out[14] += 2.0*f[67]*volFact*wx1*wx1_sq+0.5*f[67]*dv1_sq*volFact*wx1; 
} 
void GkMomentCalc2x2vMax_Qperp_P1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1*wx2+0.5773502691896258*f[3]*dv1*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact*wx1; 
  out[1] += 2.0*f[1]*volFact*wx1*wx2; 
  out[2] += 2.0*f[2]*volFact*wx1*wx2; 
} 
void GkMomentCalc2x2vMax_Qperp_P2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1*wx2+0.5773502691896258*f[3]*dv1*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact*wx1+0.1666666666666667*f[10]*dv1*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx2+0.5773502691896258*f[6]*dv1*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact*wx1; 
  out[2] += 2.0*f[2]*volFact*wx1*wx2+0.5773502691896258*f[7]*dv1*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact*wx1; 
  out[3] += 2.0*f[5]*volFact*wx1*wx2; 
  out[4] += 2.0*f[11]*volFact*wx1*wx2; 
  out[5] += 2.0*f[12]*volFact*wx1*wx2; 
} 
void GkMomentCalc2x2vMax_Qperp_P3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1*wx2+0.5773502691896258*f[3]*dv1*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact*wx1+0.1666666666666667*f[10]*dv1*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx2+0.5773502691896258*f[6]*dv1*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact*wx1+0.1666666666666667*f[17]*dv1*dv2*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1*wx2+0.5773502691896258*f[7]*dv1*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact*wx1+0.1666666666666667*f[18]*dv1*dv2*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1*wx2+0.5773502691896258*f[15]*dv1*volFact*wx2+0.5773502691896258*f[16]*dv2*volFact*wx1; 
  out[4] += 2.0*f[11]*volFact*wx1*wx2+0.5773502691896257*f[21]*dv1*volFact*wx2+0.5773502691896257*f[25]*dv2*volFact*wx1; 
  out[5] += 2.0*f[12]*volFact*wx1*wx2+0.5773502691896257*f[22]*dv1*volFact*wx2+0.5773502691896257*f[26]*dv2*volFact*wx1; 
  out[6] += 2.0*f[19]*volFact*wx1*wx2; 
  out[7] += 2.0*f[20]*volFact*wx1*wx2; 
  out[8] += 2.0*f[31]*volFact*wx1*wx2; 
  out[9] += 2.0*f[32]*volFact*wx1*wx2; 
} 
void GkMomentCalc2x2vMax_Qperp_P4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  const double volFact = 2.0*M_PI*dxv[2]*dxv[3]/4; 
  const double wx1 = w[2], dv1 = dxv[2]; 
  const double wx2 = w[3], dv2 = dxv[3]; 
  out[0] += 2.0*f[0]*volFact*wx1*wx2+0.5773502691896258*f[3]*dv1*volFact*wx2+0.5773502691896258*f[4]*dv2*volFact*wx1+0.1666666666666667*f[10]*dv1*dv2*volFact; 
  out[1] += 2.0*f[1]*volFact*wx1*wx2+0.5773502691896258*f[6]*dv1*volFact*wx2+0.5773502691896258*f[8]*dv2*volFact*wx1+0.1666666666666667*f[17]*dv1*dv2*volFact; 
  out[2] += 2.0*f[2]*volFact*wx1*wx2+0.5773502691896258*f[7]*dv1*volFact*wx2+0.5773502691896258*f[9]*dv2*volFact*wx1+0.1666666666666667*f[18]*dv1*dv2*volFact; 
  out[3] += 2.0*f[5]*volFact*wx1*wx2+0.5773502691896258*f[15]*dv1*volFact*wx2+0.5773502691896258*f[16]*dv2*volFact*wx1+0.1666666666666667*f[35]*dv1*dv2*volFact; 
  out[4] += 2.0*f[11]*volFact*wx1*wx2+0.5773502691896257*f[21]*dv1*volFact*wx2+0.5773502691896257*f[25]*dv2*volFact*wx1+0.1666666666666667*f[41]*dv1*dv2*volFact; 
  out[5] += 2.0*f[12]*volFact*wx1*wx2+0.5773502691896257*f[22]*dv1*volFact*wx2+0.5773502691896257*f[26]*dv2*volFact*wx1+0.1666666666666667*f[42]*dv1*dv2*volFact; 
  out[6] += 2.0*f[19]*volFact*wx1*wx2+0.5773502691896257*f[36]*dv1*volFact*wx2+0.5773502691896257*f[39]*dv2*volFact*wx1; 
  out[7] += 2.0*f[20]*volFact*wx1*wx2+0.5773502691896257*f[37]*dv1*volFact*wx2+0.5773502691896257*f[40]*dv2*volFact*wx1; 
  out[8] += 2.0*f[31]*volFact*wx1*wx2+0.5773502691896256*f[56]*dv1*volFact*wx2+0.5773502691896256*f[60]*dv2*volFact*wx1; 
  out[9] += 2.0*f[32]*volFact*wx1*wx2+0.5773502691896256*f[57]*dv1*volFact*wx2+0.5773502691896256*f[61]*dv2*volFact*wx1; 
  out[10] += 2.0*f[48]*volFact*wx1*wx2; 
  out[11] += 2.0*f[54]*volFact*wx1*wx2; 
  out[12] += 2.0*f[55]*volFact*wx1*wx2; 
  out[13] += 2.0*f[66]*volFact*wx1*wx2; 
  out[14] += 2.0*f[67]*volFact*wx1*wx2; 
} 