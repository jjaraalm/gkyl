#include <VlasovModDecl.h> 
__host__ __device__ void VlasovSurfStream2x3vSer_X_P1(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. fl/fr: Distribution function in left/right cells 
// outl/outr: Incremented distribution function in left/right cells 
  double dvxl = dxvl[2]; 
  double wxl = wl[2]; 

  double dvxr = dxvr[2]; 
  double wxr = wr[2]; 

  double dxl = 1.0/dxvl[0]; 
  double dxr = 1.0/dxvr[0]; 

  double incr[32]; 

  if (wxr>0) { 
  incr[0] = (1.732050807568877*fl[1]+fl[0])*wxl+(0.5*fl[7]+0.2886751345948129*fl[3])*dvxl; 
  incr[1] = ((-3.0*fl[1])-1.732050807568877*fl[0])*wxl+((-0.8660254037844386*fl[7])-0.5*fl[3])*dvxl; 
  incr[2] = (1.732050807568877*fl[6]+fl[2])*wxl+(0.5*fl[16]+0.2886751345948129*fl[8])*dvxl; 
  incr[3] = (1.732050807568877*fl[7]+fl[3])*wxl+(0.5*fl[1]+0.2886751345948129*fl[0])*dvxl; 
  incr[4] = (1.732050807568877*fl[9]+fl[4])*wxl+(0.5*fl[18]+0.2886751345948129*fl[11])*dvxl; 
  incr[5] = (1.732050807568877*fl[12]+fl[5])*wxl+(0.5*fl[21]+0.2886751345948129*fl[14])*dvxl; 
  incr[6] = ((-3.0*fl[6])-1.732050807568877*fl[2])*wxl+((-0.8660254037844386*fl[16])-0.5*fl[8])*dvxl; 
  incr[7] = ((-3.0*fl[7])-1.732050807568877*fl[3])*wxl+((-0.8660254037844386*fl[1])-0.5*fl[0])*dvxl; 
  incr[8] = (1.732050807568877*fl[16]+fl[8])*wxl+(0.5*fl[6]+0.2886751345948129*fl[2])*dvxl; 
  incr[9] = ((-3.0*fl[9])-1.732050807568877*fl[4])*wxl+((-0.8660254037844386*fl[18])-0.5*fl[11])*dvxl; 
  incr[10] = (1.732050807568877*fl[17]+fl[10])*wxl+(0.5*fl[26]+0.2886751345948129*fl[19])*dvxl; 
  incr[11] = (1.732050807568877*fl[18]+fl[11])*wxl+(0.5*fl[9]+0.2886751345948129*fl[4])*dvxl; 
  incr[12] = ((-3.0*fl[12])-1.732050807568877*fl[5])*wxl+((-0.8660254037844386*fl[21])-0.5*fl[14])*dvxl; 
  incr[13] = (1.732050807568877*fl[20]+fl[13])*wxl+(0.5*fl[27]+0.2886751345948129*fl[22])*dvxl; 
  incr[14] = (1.732050807568877*fl[21]+fl[14])*wxl+(0.5*fl[12]+0.2886751345948129*fl[5])*dvxl; 
  incr[15] = (1.732050807568877*fl[23]+fl[15])*wxl+(0.5*fl[29]+0.2886751345948129*fl[25])*dvxl; 
  incr[16] = ((-3.0*fl[16])-1.732050807568877*fl[8])*wxl+((-0.8660254037844386*fl[6])-0.5*fl[2])*dvxl; 
  incr[17] = ((-3.0*fl[17])-1.732050807568877*fl[10])*wxl+((-0.8660254037844386*fl[26])-0.5*fl[19])*dvxl; 
  incr[18] = ((-3.0*fl[18])-1.732050807568877*fl[11])*wxl+((-0.8660254037844386*fl[9])-0.5*fl[4])*dvxl; 
  incr[19] = (1.732050807568877*fl[26]+fl[19])*wxl+(0.5*fl[17]+0.2886751345948129*fl[10])*dvxl; 
  incr[20] = ((-3.0*fl[20])-1.732050807568877*fl[13])*wxl+((-0.8660254037844386*fl[27])-0.5*fl[22])*dvxl; 
  incr[21] = ((-3.0*fl[21])-1.732050807568877*fl[14])*wxl+((-0.8660254037844386*fl[12])-0.5*fl[5])*dvxl; 
  incr[22] = (1.732050807568877*fl[27]+fl[22])*wxl+(0.5*fl[20]+0.2886751345948129*fl[13])*dvxl; 
  incr[23] = ((-3.0*fl[23])-1.732050807568877*fl[15])*wxl+((-0.8660254037844386*fl[29])-0.5*fl[25])*dvxl; 
  incr[24] = (1.732050807568877*fl[28]+fl[24])*wxl+(0.5*fl[31]+0.2886751345948129*fl[30])*dvxl; 
  incr[25] = (1.732050807568877*fl[29]+fl[25])*wxl+(0.5*fl[23]+0.2886751345948129*fl[15])*dvxl; 
  incr[26] = ((-3.0*fl[26])-1.732050807568877*fl[19])*wxl+((-0.8660254037844386*fl[17])-0.5*fl[10])*dvxl; 
  incr[27] = ((-3.0*fl[27])-1.732050807568877*fl[22])*wxl+((-0.8660254037844386*fl[20])-0.5*fl[13])*dvxl; 
  incr[28] = ((-3.0*fl[28])-1.732050807568877*fl[24])*wxl+((-0.8660254037844386*fl[31])-0.5*fl[30])*dvxl; 
  incr[29] = ((-3.0*fl[29])-1.732050807568877*fl[25])*wxl+((-0.8660254037844386*fl[23])-0.5*fl[15])*dvxl; 
  incr[30] = (1.732050807568877*fl[31]+fl[30])*wxl+(0.5*fl[28]+0.2886751345948129*fl[24])*dvxl; 
  incr[31] = ((-3.0*fl[31])-1.732050807568877*fl[30])*wxl+((-0.8660254037844386*fl[28])-0.5*fl[24])*dvxl; 

  outr[0] += incr[0]*dxr; 
  outr[1] += incr[1]*dxr; 
  outr[2] += incr[2]*dxr; 
  outr[3] += incr[3]*dxr; 
  outr[4] += incr[4]*dxr; 
  outr[5] += incr[5]*dxr; 
  outr[6] += incr[6]*dxr; 
  outr[7] += incr[7]*dxr; 
  outr[8] += incr[8]*dxr; 
  outr[9] += incr[9]*dxr; 
  outr[10] += incr[10]*dxr; 
  outr[11] += incr[11]*dxr; 
  outr[12] += incr[12]*dxr; 
  outr[13] += incr[13]*dxr; 
  outr[14] += incr[14]*dxr; 
  outr[15] += incr[15]*dxr; 
  outr[16] += incr[16]*dxr; 
  outr[17] += incr[17]*dxr; 
  outr[18] += incr[18]*dxr; 
  outr[19] += incr[19]*dxr; 
  outr[20] += incr[20]*dxr; 
  outr[21] += incr[21]*dxr; 
  outr[22] += incr[22]*dxr; 
  outr[23] += incr[23]*dxr; 
  outr[24] += incr[24]*dxr; 
  outr[25] += incr[25]*dxr; 
  outr[26] += incr[26]*dxr; 
  outr[27] += incr[27]*dxr; 
  outr[28] += incr[28]*dxr; 
  outr[29] += incr[29]*dxr; 
  outr[30] += incr[30]*dxr; 
  outr[31] += incr[31]*dxr; 

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += incr[1]*dxl; 
  outl[2] += -1.0*incr[2]*dxl; 
  outl[3] += -1.0*incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += incr[6]*dxl; 
  outl[7] += incr[7]*dxl; 
  outl[8] += -1.0*incr[8]*dxl; 
  outl[9] += incr[9]*dxl; 
  outl[10] += -1.0*incr[10]*dxl; 
  outl[11] += -1.0*incr[11]*dxl; 
  outl[12] += incr[12]*dxl; 
  outl[13] += -1.0*incr[13]*dxl; 
  outl[14] += -1.0*incr[14]*dxl; 
  outl[15] += -1.0*incr[15]*dxl; 
  outl[16] += incr[16]*dxl; 
  outl[17] += incr[17]*dxl; 
  outl[18] += incr[18]*dxl; 
  outl[19] += -1.0*incr[19]*dxl; 
  outl[20] += incr[20]*dxl; 
  outl[21] += incr[21]*dxl; 
  outl[22] += -1.0*incr[22]*dxl; 
  outl[23] += incr[23]*dxl; 
  outl[24] += -1.0*incr[24]*dxl; 
  outl[25] += -1.0*incr[25]*dxl; 
  outl[26] += incr[26]*dxl; 
  outl[27] += incr[27]*dxl; 
  outl[28] += incr[28]*dxl; 
  outl[29] += incr[29]*dxl; 
  outl[30] += -1.0*incr[30]*dxl; 
  outl[31] += incr[31]*dxl; 
  } else { 
  incr[0] = (fr[0]-1.732050807568877*fr[1])*wxr+(0.2886751345948129*fr[3]-0.5*fr[7])*dvxr; 
  incr[1] = (3.0*fr[1]-1.732050807568877*fr[0])*wxr+(0.8660254037844386*fr[7]-0.5*fr[3])*dvxr; 
  incr[2] = (fr[2]-1.732050807568877*fr[6])*wxr+(0.2886751345948129*fr[8]-0.5*fr[16])*dvxr; 
  incr[3] = (fr[3]-1.732050807568877*fr[7])*wxr+(0.2886751345948129*fr[0]-0.5*fr[1])*dvxr; 
  incr[4] = (fr[4]-1.732050807568877*fr[9])*wxr+(0.2886751345948129*fr[11]-0.5*fr[18])*dvxr; 
  incr[5] = (fr[5]-1.732050807568877*fr[12])*wxr+(0.2886751345948129*fr[14]-0.5*fr[21])*dvxr; 
  incr[6] = (3.0*fr[6]-1.732050807568877*fr[2])*wxr+(0.8660254037844386*fr[16]-0.5*fr[8])*dvxr; 
  incr[7] = (3.0*fr[7]-1.732050807568877*fr[3])*wxr+(0.8660254037844386*fr[1]-0.5*fr[0])*dvxr; 
  incr[8] = (fr[8]-1.732050807568877*fr[16])*wxr+(0.2886751345948129*fr[2]-0.5*fr[6])*dvxr; 
  incr[9] = (3.0*fr[9]-1.732050807568877*fr[4])*wxr+(0.8660254037844386*fr[18]-0.5*fr[11])*dvxr; 
  incr[10] = (fr[10]-1.732050807568877*fr[17])*wxr+(0.2886751345948129*fr[19]-0.5*fr[26])*dvxr; 
  incr[11] = (fr[11]-1.732050807568877*fr[18])*wxr+(0.2886751345948129*fr[4]-0.5*fr[9])*dvxr; 
  incr[12] = (3.0*fr[12]-1.732050807568877*fr[5])*wxr+(0.8660254037844386*fr[21]-0.5*fr[14])*dvxr; 
  incr[13] = (fr[13]-1.732050807568877*fr[20])*wxr+(0.2886751345948129*fr[22]-0.5*fr[27])*dvxr; 
  incr[14] = (fr[14]-1.732050807568877*fr[21])*wxr+(0.2886751345948129*fr[5]-0.5*fr[12])*dvxr; 
  incr[15] = (fr[15]-1.732050807568877*fr[23])*wxr+(0.2886751345948129*fr[25]-0.5*fr[29])*dvxr; 
  incr[16] = (3.0*fr[16]-1.732050807568877*fr[8])*wxr+(0.8660254037844386*fr[6]-0.5*fr[2])*dvxr; 
  incr[17] = (3.0*fr[17]-1.732050807568877*fr[10])*wxr+(0.8660254037844386*fr[26]-0.5*fr[19])*dvxr; 
  incr[18] = (3.0*fr[18]-1.732050807568877*fr[11])*wxr+(0.8660254037844386*fr[9]-0.5*fr[4])*dvxr; 
  incr[19] = (fr[19]-1.732050807568877*fr[26])*wxr+(0.2886751345948129*fr[10]-0.5*fr[17])*dvxr; 
  incr[20] = (3.0*fr[20]-1.732050807568877*fr[13])*wxr+(0.8660254037844386*fr[27]-0.5*fr[22])*dvxr; 
  incr[21] = (3.0*fr[21]-1.732050807568877*fr[14])*wxr+(0.8660254037844386*fr[12]-0.5*fr[5])*dvxr; 
  incr[22] = (fr[22]-1.732050807568877*fr[27])*wxr+(0.2886751345948129*fr[13]-0.5*fr[20])*dvxr; 
  incr[23] = (3.0*fr[23]-1.732050807568877*fr[15])*wxr+(0.8660254037844386*fr[29]-0.5*fr[25])*dvxr; 
  incr[24] = (fr[24]-1.732050807568877*fr[28])*wxr+(0.2886751345948129*fr[30]-0.5*fr[31])*dvxr; 
  incr[25] = (fr[25]-1.732050807568877*fr[29])*wxr+(0.2886751345948129*fr[15]-0.5*fr[23])*dvxr; 
  incr[26] = (3.0*fr[26]-1.732050807568877*fr[19])*wxr+(0.8660254037844386*fr[17]-0.5*fr[10])*dvxr; 
  incr[27] = (3.0*fr[27]-1.732050807568877*fr[22])*wxr+(0.8660254037844386*fr[20]-0.5*fr[13])*dvxr; 
  incr[28] = (3.0*fr[28]-1.732050807568877*fr[24])*wxr+(0.8660254037844386*fr[31]-0.5*fr[30])*dvxr; 
  incr[29] = (3.0*fr[29]-1.732050807568877*fr[25])*wxr+(0.8660254037844386*fr[23]-0.5*fr[15])*dvxr; 
  incr[30] = (fr[30]-1.732050807568877*fr[31])*wxr+(0.2886751345948129*fr[24]-0.5*fr[28])*dvxr; 
  incr[31] = (3.0*fr[31]-1.732050807568877*fr[30])*wxr+(0.8660254037844386*fr[28]-0.5*fr[24])*dvxr; 

  outr[0] += incr[0]*dxr; 
  outr[1] += incr[1]*dxr; 
  outr[2] += incr[2]*dxr; 
  outr[3] += incr[3]*dxr; 
  outr[4] += incr[4]*dxr; 
  outr[5] += incr[5]*dxr; 
  outr[6] += incr[6]*dxr; 
  outr[7] += incr[7]*dxr; 
  outr[8] += incr[8]*dxr; 
  outr[9] += incr[9]*dxr; 
  outr[10] += incr[10]*dxr; 
  outr[11] += incr[11]*dxr; 
  outr[12] += incr[12]*dxr; 
  outr[13] += incr[13]*dxr; 
  outr[14] += incr[14]*dxr; 
  outr[15] += incr[15]*dxr; 
  outr[16] += incr[16]*dxr; 
  outr[17] += incr[17]*dxr; 
  outr[18] += incr[18]*dxr; 
  outr[19] += incr[19]*dxr; 
  outr[20] += incr[20]*dxr; 
  outr[21] += incr[21]*dxr; 
  outr[22] += incr[22]*dxr; 
  outr[23] += incr[23]*dxr; 
  outr[24] += incr[24]*dxr; 
  outr[25] += incr[25]*dxr; 
  outr[26] += incr[26]*dxr; 
  outr[27] += incr[27]*dxr; 
  outr[28] += incr[28]*dxr; 
  outr[29] += incr[29]*dxr; 
  outr[30] += incr[30]*dxr; 
  outr[31] += incr[31]*dxr; 

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += incr[1]*dxl; 
  outl[2] += -1.0*incr[2]*dxl; 
  outl[3] += -1.0*incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += incr[6]*dxl; 
  outl[7] += incr[7]*dxl; 
  outl[8] += -1.0*incr[8]*dxl; 
  outl[9] += incr[9]*dxl; 
  outl[10] += -1.0*incr[10]*dxl; 
  outl[11] += -1.0*incr[11]*dxl; 
  outl[12] += incr[12]*dxl; 
  outl[13] += -1.0*incr[13]*dxl; 
  outl[14] += -1.0*incr[14]*dxl; 
  outl[15] += -1.0*incr[15]*dxl; 
  outl[16] += incr[16]*dxl; 
  outl[17] += incr[17]*dxl; 
  outl[18] += incr[18]*dxl; 
  outl[19] += -1.0*incr[19]*dxl; 
  outl[20] += incr[20]*dxl; 
  outl[21] += incr[21]*dxl; 
  outl[22] += -1.0*incr[22]*dxl; 
  outl[23] += incr[23]*dxl; 
  outl[24] += -1.0*incr[24]*dxl; 
  outl[25] += -1.0*incr[25]*dxl; 
  outl[26] += incr[26]*dxl; 
  outl[27] += incr[27]*dxl; 
  outl[28] += incr[28]*dxl; 
  outl[29] += incr[29]*dxl; 
  outl[30] += -1.0*incr[30]*dxl; 
  outl[31] += incr[31]*dxl; 
  } 
} 
__host__ __device__ void VlasovSurfStream2x3vSer_Y_P1(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. fl/fr: Distribution function in left/right cells 
// outl/outr: Incremented distribution function in left/right cells 
  double dvxl = dxvl[3]; 
  double wxl = wl[3]; 

  double dvxr = dxvr[3]; 
  double wxr = wr[3]; 

  double dxl = 1.0/dxvl[1]; 
  double dxr = 1.0/dxvr[1]; 

  double incr[32]; 

  if (wxr>0) { 
  incr[0] = (1.732050807568877*fl[2]+fl[0])*wxl+(0.5*fl[10]+0.2886751345948129*fl[4])*dvxl; 
  incr[1] = (1.732050807568877*fl[6]+fl[1])*wxl+(0.5*fl[17]+0.2886751345948129*fl[9])*dvxl; 
  incr[2] = ((-3.0*fl[2])-1.732050807568877*fl[0])*wxl+((-0.8660254037844386*fl[10])-0.5*fl[4])*dvxl; 
  incr[3] = (1.732050807568877*fl[8]+fl[3])*wxl+(0.5*fl[19]+0.2886751345948129*fl[11])*dvxl; 
  incr[4] = (1.732050807568877*fl[10]+fl[4])*wxl+(0.5*fl[2]+0.2886751345948129*fl[0])*dvxl; 
  incr[5] = (1.732050807568877*fl[13]+fl[5])*wxl+(0.5*fl[24]+0.2886751345948129*fl[15])*dvxl; 
  incr[6] = ((-3.0*fl[6])-1.732050807568877*fl[1])*wxl+((-0.8660254037844386*fl[17])-0.5*fl[9])*dvxl; 
  incr[7] = (1.732050807568877*fl[16]+fl[7])*wxl+(0.5*fl[26]+0.2886751345948129*fl[18])*dvxl; 
  incr[8] = ((-3.0*fl[8])-1.732050807568877*fl[3])*wxl+((-0.8660254037844386*fl[19])-0.5*fl[11])*dvxl; 
  incr[9] = (1.732050807568877*fl[17]+fl[9])*wxl+(0.5*fl[6]+0.2886751345948129*fl[1])*dvxl; 
  incr[10] = ((-3.0*fl[10])-1.732050807568877*fl[4])*wxl+((-0.8660254037844386*fl[2])-0.5*fl[0])*dvxl; 
  incr[11] = (1.732050807568877*fl[19]+fl[11])*wxl+(0.5*fl[8]+0.2886751345948129*fl[3])*dvxl; 
  incr[12] = (1.732050807568877*fl[20]+fl[12])*wxl+(0.5*fl[28]+0.2886751345948129*fl[23])*dvxl; 
  incr[13] = ((-3.0*fl[13])-1.732050807568877*fl[5])*wxl+((-0.8660254037844386*fl[24])-0.5*fl[15])*dvxl; 
  incr[14] = (1.732050807568877*fl[22]+fl[14])*wxl+(0.5*fl[30]+0.2886751345948129*fl[25])*dvxl; 
  incr[15] = (1.732050807568877*fl[24]+fl[15])*wxl+(0.5*fl[13]+0.2886751345948129*fl[5])*dvxl; 
  incr[16] = ((-3.0*fl[16])-1.732050807568877*fl[7])*wxl+((-0.8660254037844386*fl[26])-0.5*fl[18])*dvxl; 
  incr[17] = ((-3.0*fl[17])-1.732050807568877*fl[9])*wxl+((-0.8660254037844386*fl[6])-0.5*fl[1])*dvxl; 
  incr[18] = (1.732050807568877*fl[26]+fl[18])*wxl+(0.5*fl[16]+0.2886751345948129*fl[7])*dvxl; 
  incr[19] = ((-3.0*fl[19])-1.732050807568877*fl[11])*wxl+((-0.8660254037844386*fl[8])-0.5*fl[3])*dvxl; 
  incr[20] = ((-3.0*fl[20])-1.732050807568877*fl[12])*wxl+((-0.8660254037844386*fl[28])-0.5*fl[23])*dvxl; 
  incr[21] = (1.732050807568877*fl[27]+fl[21])*wxl+(0.5*fl[31]+0.2886751345948129*fl[29])*dvxl; 
  incr[22] = ((-3.0*fl[22])-1.732050807568877*fl[14])*wxl+((-0.8660254037844386*fl[30])-0.5*fl[25])*dvxl; 
  incr[23] = (1.732050807568877*fl[28]+fl[23])*wxl+(0.5*fl[20]+0.2886751345948129*fl[12])*dvxl; 
  incr[24] = ((-3.0*fl[24])-1.732050807568877*fl[15])*wxl+((-0.8660254037844386*fl[13])-0.5*fl[5])*dvxl; 
  incr[25] = (1.732050807568877*fl[30]+fl[25])*wxl+(0.5*fl[22]+0.2886751345948129*fl[14])*dvxl; 
  incr[26] = ((-3.0*fl[26])-1.732050807568877*fl[18])*wxl+((-0.8660254037844386*fl[16])-0.5*fl[7])*dvxl; 
  incr[27] = ((-3.0*fl[27])-1.732050807568877*fl[21])*wxl+((-0.8660254037844386*fl[31])-0.5*fl[29])*dvxl; 
  incr[28] = ((-3.0*fl[28])-1.732050807568877*fl[23])*wxl+((-0.8660254037844386*fl[20])-0.5*fl[12])*dvxl; 
  incr[29] = (1.732050807568877*fl[31]+fl[29])*wxl+(0.5*fl[27]+0.2886751345948129*fl[21])*dvxl; 
  incr[30] = ((-3.0*fl[30])-1.732050807568877*fl[25])*wxl+((-0.8660254037844386*fl[22])-0.5*fl[14])*dvxl; 
  incr[31] = ((-3.0*fl[31])-1.732050807568877*fl[29])*wxl+((-0.8660254037844386*fl[27])-0.5*fl[21])*dvxl; 

  outr[0] += incr[0]*dxr; 
  outr[1] += incr[1]*dxr; 
  outr[2] += incr[2]*dxr; 
  outr[3] += incr[3]*dxr; 
  outr[4] += incr[4]*dxr; 
  outr[5] += incr[5]*dxr; 
  outr[6] += incr[6]*dxr; 
  outr[7] += incr[7]*dxr; 
  outr[8] += incr[8]*dxr; 
  outr[9] += incr[9]*dxr; 
  outr[10] += incr[10]*dxr; 
  outr[11] += incr[11]*dxr; 
  outr[12] += incr[12]*dxr; 
  outr[13] += incr[13]*dxr; 
  outr[14] += incr[14]*dxr; 
  outr[15] += incr[15]*dxr; 
  outr[16] += incr[16]*dxr; 
  outr[17] += incr[17]*dxr; 
  outr[18] += incr[18]*dxr; 
  outr[19] += incr[19]*dxr; 
  outr[20] += incr[20]*dxr; 
  outr[21] += incr[21]*dxr; 
  outr[22] += incr[22]*dxr; 
  outr[23] += incr[23]*dxr; 
  outr[24] += incr[24]*dxr; 
  outr[25] += incr[25]*dxr; 
  outr[26] += incr[26]*dxr; 
  outr[27] += incr[27]*dxr; 
  outr[28] += incr[28]*dxr; 
  outr[29] += incr[29]*dxr; 
  outr[30] += incr[30]*dxr; 
  outr[31] += incr[31]*dxr; 

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += -1.0*incr[1]*dxl; 
  outl[2] += incr[2]*dxl; 
  outl[3] += -1.0*incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += incr[6]*dxl; 
  outl[7] += -1.0*incr[7]*dxl; 
  outl[8] += incr[8]*dxl; 
  outl[9] += -1.0*incr[9]*dxl; 
  outl[10] += incr[10]*dxl; 
  outl[11] += -1.0*incr[11]*dxl; 
  outl[12] += -1.0*incr[12]*dxl; 
  outl[13] += incr[13]*dxl; 
  outl[14] += -1.0*incr[14]*dxl; 
  outl[15] += -1.0*incr[15]*dxl; 
  outl[16] += incr[16]*dxl; 
  outl[17] += incr[17]*dxl; 
  outl[18] += -1.0*incr[18]*dxl; 
  outl[19] += incr[19]*dxl; 
  outl[20] += incr[20]*dxl; 
  outl[21] += -1.0*incr[21]*dxl; 
  outl[22] += incr[22]*dxl; 
  outl[23] += -1.0*incr[23]*dxl; 
  outl[24] += incr[24]*dxl; 
  outl[25] += -1.0*incr[25]*dxl; 
  outl[26] += incr[26]*dxl; 
  outl[27] += incr[27]*dxl; 
  outl[28] += incr[28]*dxl; 
  outl[29] += -1.0*incr[29]*dxl; 
  outl[30] += incr[30]*dxl; 
  outl[31] += incr[31]*dxl; 
  } else { 
  incr[0] = (fr[0]-1.732050807568877*fr[2])*wxr+(0.2886751345948129*fr[4]-0.5*fr[10])*dvxr; 
  incr[1] = (fr[1]-1.732050807568877*fr[6])*wxr+(0.2886751345948129*fr[9]-0.5*fr[17])*dvxr; 
  incr[2] = (3.0*fr[2]-1.732050807568877*fr[0])*wxr+(0.8660254037844386*fr[10]-0.5*fr[4])*dvxr; 
  incr[3] = (fr[3]-1.732050807568877*fr[8])*wxr+(0.2886751345948129*fr[11]-0.5*fr[19])*dvxr; 
  incr[4] = (fr[4]-1.732050807568877*fr[10])*wxr+(0.2886751345948129*fr[0]-0.5*fr[2])*dvxr; 
  incr[5] = (fr[5]-1.732050807568877*fr[13])*wxr+(0.2886751345948129*fr[15]-0.5*fr[24])*dvxr; 
  incr[6] = (3.0*fr[6]-1.732050807568877*fr[1])*wxr+(0.8660254037844386*fr[17]-0.5*fr[9])*dvxr; 
  incr[7] = (fr[7]-1.732050807568877*fr[16])*wxr+(0.2886751345948129*fr[18]-0.5*fr[26])*dvxr; 
  incr[8] = (3.0*fr[8]-1.732050807568877*fr[3])*wxr+(0.8660254037844386*fr[19]-0.5*fr[11])*dvxr; 
  incr[9] = (fr[9]-1.732050807568877*fr[17])*wxr+(0.2886751345948129*fr[1]-0.5*fr[6])*dvxr; 
  incr[10] = (3.0*fr[10]-1.732050807568877*fr[4])*wxr+(0.8660254037844386*fr[2]-0.5*fr[0])*dvxr; 
  incr[11] = (fr[11]-1.732050807568877*fr[19])*wxr+(0.2886751345948129*fr[3]-0.5*fr[8])*dvxr; 
  incr[12] = (fr[12]-1.732050807568877*fr[20])*wxr+(0.2886751345948129*fr[23]-0.5*fr[28])*dvxr; 
  incr[13] = (3.0*fr[13]-1.732050807568877*fr[5])*wxr+(0.8660254037844386*fr[24]-0.5*fr[15])*dvxr; 
  incr[14] = (fr[14]-1.732050807568877*fr[22])*wxr+(0.2886751345948129*fr[25]-0.5*fr[30])*dvxr; 
  incr[15] = (fr[15]-1.732050807568877*fr[24])*wxr+(0.2886751345948129*fr[5]-0.5*fr[13])*dvxr; 
  incr[16] = (3.0*fr[16]-1.732050807568877*fr[7])*wxr+(0.8660254037844386*fr[26]-0.5*fr[18])*dvxr; 
  incr[17] = (3.0*fr[17]-1.732050807568877*fr[9])*wxr+(0.8660254037844386*fr[6]-0.5*fr[1])*dvxr; 
  incr[18] = (fr[18]-1.732050807568877*fr[26])*wxr+(0.2886751345948129*fr[7]-0.5*fr[16])*dvxr; 
  incr[19] = (3.0*fr[19]-1.732050807568877*fr[11])*wxr+(0.8660254037844386*fr[8]-0.5*fr[3])*dvxr; 
  incr[20] = (3.0*fr[20]-1.732050807568877*fr[12])*wxr+(0.8660254037844386*fr[28]-0.5*fr[23])*dvxr; 
  incr[21] = (fr[21]-1.732050807568877*fr[27])*wxr+(0.2886751345948129*fr[29]-0.5*fr[31])*dvxr; 
  incr[22] = (3.0*fr[22]-1.732050807568877*fr[14])*wxr+(0.8660254037844386*fr[30]-0.5*fr[25])*dvxr; 
  incr[23] = (fr[23]-1.732050807568877*fr[28])*wxr+(0.2886751345948129*fr[12]-0.5*fr[20])*dvxr; 
  incr[24] = (3.0*fr[24]-1.732050807568877*fr[15])*wxr+(0.8660254037844386*fr[13]-0.5*fr[5])*dvxr; 
  incr[25] = (fr[25]-1.732050807568877*fr[30])*wxr+(0.2886751345948129*fr[14]-0.5*fr[22])*dvxr; 
  incr[26] = (3.0*fr[26]-1.732050807568877*fr[18])*wxr+(0.8660254037844386*fr[16]-0.5*fr[7])*dvxr; 
  incr[27] = (3.0*fr[27]-1.732050807568877*fr[21])*wxr+(0.8660254037844386*fr[31]-0.5*fr[29])*dvxr; 
  incr[28] = (3.0*fr[28]-1.732050807568877*fr[23])*wxr+(0.8660254037844386*fr[20]-0.5*fr[12])*dvxr; 
  incr[29] = (fr[29]-1.732050807568877*fr[31])*wxr+(0.2886751345948129*fr[21]-0.5*fr[27])*dvxr; 
  incr[30] = (3.0*fr[30]-1.732050807568877*fr[25])*wxr+(0.8660254037844386*fr[22]-0.5*fr[14])*dvxr; 
  incr[31] = (3.0*fr[31]-1.732050807568877*fr[29])*wxr+(0.8660254037844386*fr[27]-0.5*fr[21])*dvxr; 

  outr[0] += incr[0]*dxr; 
  outr[1] += incr[1]*dxr; 
  outr[2] += incr[2]*dxr; 
  outr[3] += incr[3]*dxr; 
  outr[4] += incr[4]*dxr; 
  outr[5] += incr[5]*dxr; 
  outr[6] += incr[6]*dxr; 
  outr[7] += incr[7]*dxr; 
  outr[8] += incr[8]*dxr; 
  outr[9] += incr[9]*dxr; 
  outr[10] += incr[10]*dxr; 
  outr[11] += incr[11]*dxr; 
  outr[12] += incr[12]*dxr; 
  outr[13] += incr[13]*dxr; 
  outr[14] += incr[14]*dxr; 
  outr[15] += incr[15]*dxr; 
  outr[16] += incr[16]*dxr; 
  outr[17] += incr[17]*dxr; 
  outr[18] += incr[18]*dxr; 
  outr[19] += incr[19]*dxr; 
  outr[20] += incr[20]*dxr; 
  outr[21] += incr[21]*dxr; 
  outr[22] += incr[22]*dxr; 
  outr[23] += incr[23]*dxr; 
  outr[24] += incr[24]*dxr; 
  outr[25] += incr[25]*dxr; 
  outr[26] += incr[26]*dxr; 
  outr[27] += incr[27]*dxr; 
  outr[28] += incr[28]*dxr; 
  outr[29] += incr[29]*dxr; 
  outr[30] += incr[30]*dxr; 
  outr[31] += incr[31]*dxr; 

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += -1.0*incr[1]*dxl; 
  outl[2] += incr[2]*dxl; 
  outl[3] += -1.0*incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += incr[6]*dxl; 
  outl[7] += -1.0*incr[7]*dxl; 
  outl[8] += incr[8]*dxl; 
  outl[9] += -1.0*incr[9]*dxl; 
  outl[10] += incr[10]*dxl; 
  outl[11] += -1.0*incr[11]*dxl; 
  outl[12] += -1.0*incr[12]*dxl; 
  outl[13] += incr[13]*dxl; 
  outl[14] += -1.0*incr[14]*dxl; 
  outl[15] += -1.0*incr[15]*dxl; 
  outl[16] += incr[16]*dxl; 
  outl[17] += incr[17]*dxl; 
  outl[18] += -1.0*incr[18]*dxl; 
  outl[19] += incr[19]*dxl; 
  outl[20] += incr[20]*dxl; 
  outl[21] += -1.0*incr[21]*dxl; 
  outl[22] += incr[22]*dxl; 
  outl[23] += -1.0*incr[23]*dxl; 
  outl[24] += incr[24]*dxl; 
  outl[25] += -1.0*incr[25]*dxl; 
  outl[26] += incr[26]*dxl; 
  outl[27] += incr[27]*dxl; 
  outl[28] += incr[28]*dxl; 
  outl[29] += -1.0*incr[29]*dxl; 
  outl[30] += incr[30]*dxl; 
  outl[31] += incr[31]*dxl; 
  } 
} 
