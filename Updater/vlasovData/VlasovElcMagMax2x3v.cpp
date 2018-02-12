#include <VlasovModDecl.h> 
void VlasovVolElcMag2x3vMaxP1(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  const double dv10 = 2/dxv[2]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[2], wv1 = w[2]; 
  const double dv11 = 2/dxv[3]; 
  const double *E1 = &EM[3]; 
  const double dv2 = dxv[3], wv2 = w[3]; 
  const double dv12 = 2/dxv[4]; 
  const double *E2 = &EM[6]; 
  const double dv3 = dxv[4], wv3 = w[4]; 

  const double *B0 = &EM[9]; 
  const double *B1 = &EM[12]; 
  const double *B2 = &EM[15]; 

  out[3] += (-0.8660254037844386*B1[2]*f[2]*dv10*wv3)-0.8660254037844386*B1[1]*f[1]*dv10*wv3-0.8660254037844386*B1[0]*f[0]*dv10*wv3+0.8660254037844386*B2[2]*f[2]*dv10*wv2+0.8660254037844386*B2[1]*f[1]*dv10*wv2+0.8660254037844386*B2[0]*f[0]*dv10*wv2-0.25*B1[0]*f[5]*dv10*dv3+0.25*B2[0]*f[4]*dv10*dv2+0.8660254037844386*E0[2]*f[2]*dv10+0.8660254037844386*E0[1]*f[1]*dv10+0.8660254037844386*E0[0]*f[0]*dv10; 
  out[4] += 0.8660254037844386*B0[2]*f[2]*dv11*wv3+0.8660254037844386*B0[1]*f[1]*dv11*wv3+0.8660254037844386*B0[0]*f[0]*dv11*wv3-0.8660254037844386*B2[2]*f[2]*dv11*wv1-0.8660254037844386*B2[1]*f[1]*dv11*wv1-0.8660254037844386*B2[0]*f[0]*dv11*wv1+0.25*B0[0]*f[5]*dv11*dv3-0.25*B2[0]*f[3]*dv1*dv11+0.8660254037844386*E1[2]*f[2]*dv11+0.8660254037844386*E1[1]*f[1]*dv11+0.8660254037844386*E1[0]*f[0]*dv11; 
  out[5] += (-0.8660254037844386*B0[2]*f[2]*dv12*wv2)-0.8660254037844386*B0[1]*f[1]*dv12*wv2-0.8660254037844386*B0[0]*f[0]*dv12*wv2+0.8660254037844386*B1[2]*f[2]*dv12*wv1+0.8660254037844386*B1[1]*f[1]*dv12*wv1+0.8660254037844386*B1[0]*f[0]*dv12*wv1-0.25*B0[0]*f[4]*dv12*dv2+0.25*B1[0]*f[3]*dv1*dv12+0.8660254037844386*E2[2]*f[2]*dv12+0.8660254037844386*E2[1]*f[1]*dv12+0.8660254037844386*E2[0]*f[0]*dv12; 
} 
void VlasovVolElcMag2x3vMaxP2(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  const double dv10 = 2/dxv[2]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[2], wv1 = w[2]; 
  const double dv11 = 2/dxv[3]; 
  const double *E1 = &EM[6]; 
  const double dv2 = dxv[3], wv2 = w[3]; 
  const double dv12 = 2/dxv[4]; 
  const double *E2 = &EM[12]; 
  const double dv3 = dxv[4], wv3 = w[4]; 

  const double *B0 = &EM[18]; 
  const double *B1 = &EM[24]; 
  const double *B2 = &EM[30]; 

  out[3] += (-0.8660254037844386*B1[5]*f[17]*dv10*wv3)-0.8660254037844386*B1[4]*f[16]*dv10*wv3-0.8660254037844386*B1[3]*f[6]*dv10*wv3-0.8660254037844386*B1[2]*f[2]*dv10*wv3-0.8660254037844386*B1[1]*f[1]*dv10*wv3-0.8660254037844386*B1[0]*f[0]*dv10*wv3+0.8660254037844386*B2[5]*f[17]*dv10*wv2+0.8660254037844386*B2[4]*f[16]*dv10*wv2+0.8660254037844386*B2[3]*f[6]*dv10*wv2+0.8660254037844386*B2[2]*f[2]*dv10*wv2+0.8660254037844386*B2[1]*f[1]*dv10*wv2+0.8660254037844386*B2[0]*f[0]*dv10*wv2-0.25*B1[2]*f[13]*dv10*dv3-0.25*B1[1]*f[12]*dv10*dv3-0.25*B1[0]*f[5]*dv10*dv3+0.25*B2[2]*f[10]*dv10*dv2+0.25*B2[1]*f[9]*dv10*dv2+0.25*B2[0]*f[4]*dv10*dv2+0.8660254037844386*E0[5]*f[17]*dv10+0.8660254037844386*E0[4]*f[16]*dv10+0.8660254037844386*E0[3]*f[6]*dv10+0.8660254037844386*E0[2]*f[2]*dv10+0.8660254037844386*E0[1]*f[1]*dv10+0.8660254037844386*E0[0]*f[0]*dv10; 
  out[4] += 0.8660254037844386*B0[5]*f[17]*dv11*wv3+0.8660254037844386*B0[4]*f[16]*dv11*wv3+0.8660254037844386*B0[3]*f[6]*dv11*wv3+0.8660254037844386*B0[2]*f[2]*dv11*wv3+0.8660254037844386*B0[1]*f[1]*dv11*wv3+0.8660254037844386*B0[0]*f[0]*dv11*wv3-0.8660254037844386*B2[5]*f[17]*dv11*wv1-0.8660254037844386*B2[4]*f[16]*dv11*wv1-0.8660254037844386*B2[3]*f[6]*dv11*wv1-0.8660254037844386*B2[2]*f[2]*dv11*wv1-0.8660254037844386*B2[1]*f[1]*dv11*wv1-0.8660254037844386*B2[0]*f[0]*dv11*wv1+0.25*B0[2]*f[13]*dv11*dv3+0.25*B0[1]*f[12]*dv11*dv3+0.25*B0[0]*f[5]*dv11*dv3-0.25*B2[2]*f[8]*dv1*dv11-0.25*B2[1]*f[7]*dv1*dv11-0.25*B2[0]*f[3]*dv1*dv11+0.8660254037844386*E1[5]*f[17]*dv11+0.8660254037844386*E1[4]*f[16]*dv11+0.8660254037844386*E1[3]*f[6]*dv11+0.8660254037844386*E1[2]*f[2]*dv11+0.8660254037844386*E1[1]*f[1]*dv11+0.8660254037844386*E1[0]*f[0]*dv11; 
  out[5] += (-0.8660254037844386*B0[5]*f[17]*dv12*wv2)-0.8660254037844386*B0[4]*f[16]*dv12*wv2-0.8660254037844386*B0[3]*f[6]*dv12*wv2-0.8660254037844386*B0[2]*f[2]*dv12*wv2-0.8660254037844386*B0[1]*f[1]*dv12*wv2-0.8660254037844386*B0[0]*f[0]*dv12*wv2+0.8660254037844386*B1[5]*f[17]*dv12*wv1+0.8660254037844386*B1[4]*f[16]*dv12*wv1+0.8660254037844386*B1[3]*f[6]*dv12*wv1+0.8660254037844386*B1[2]*f[2]*dv12*wv1+0.8660254037844386*B1[1]*f[1]*dv12*wv1+0.8660254037844386*B1[0]*f[0]*dv12*wv1-0.25*B0[2]*f[10]*dv12*dv2-0.25*B0[1]*f[9]*dv12*dv2-0.25*B0[0]*f[4]*dv12*dv2+0.25*B1[2]*f[8]*dv1*dv12+0.25*B1[1]*f[7]*dv1*dv12+0.25*B1[0]*f[3]*dv1*dv12+0.8660254037844386*E2[5]*f[17]*dv12+0.8660254037844386*E2[4]*f[16]*dv12+0.8660254037844386*E2[3]*f[6]*dv12+0.8660254037844386*E2[2]*f[2]*dv12+0.8660254037844386*E2[1]*f[1]*dv12+0.8660254037844386*E2[0]*f[0]*dv12; 
  out[7] += (-0.7745966692414833*B1[1]*f[16]*dv10*wv3)-0.8660254037844386*B1[2]*f[6]*dv10*wv3-0.7745966692414833*f[1]*B1[4]*dv10*wv3-0.8660254037844386*f[2]*B1[3]*dv10*wv3-0.8660254037844386*B1[0]*f[1]*dv10*wv3-0.8660254037844386*f[0]*B1[1]*dv10*wv3+0.7745966692414833*B2[1]*f[16]*dv10*wv2+0.8660254037844386*B2[2]*f[6]*dv10*wv2+0.7745966692414833*f[1]*B2[4]*dv10*wv2+0.8660254037844386*f[2]*B2[3]*dv10*wv2+0.8660254037844386*B2[0]*f[1]*dv10*wv2+0.8660254037844386*f[0]*B2[1]*dv10*wv2-0.25*B1[3]*f[13]*dv10*dv3-0.223606797749979*B1[4]*f[12]*dv10*dv3-0.25*B1[0]*f[12]*dv10*dv3-0.25*B1[1]*f[5]*dv10*dv3+0.25*B2[3]*f[10]*dv10*dv2+0.223606797749979*B2[4]*f[9]*dv10*dv2+0.25*B2[0]*f[9]*dv10*dv2+0.25*B2[1]*f[4]*dv10*dv2+0.7745966692414833*E0[1]*f[16]*dv10+0.8660254037844386*E0[2]*f[6]*dv10+0.7745966692414833*f[1]*E0[4]*dv10+0.8660254037844386*f[2]*E0[3]*dv10+0.8660254037844386*E0[0]*f[1]*dv10+0.8660254037844386*f[0]*E0[1]*dv10; 
  out[8] += (-0.7745966692414833*B1[2]*f[17]*dv10*wv3)-0.8660254037844386*B1[1]*f[6]*dv10*wv3-0.7745966692414833*f[2]*B1[5]*dv10*wv3-0.8660254037844386*f[1]*B1[3]*dv10*wv3-0.8660254037844386*B1[0]*f[2]*dv10*wv3-0.8660254037844386*f[0]*B1[2]*dv10*wv3+0.7745966692414833*B2[2]*f[17]*dv10*wv2+0.8660254037844386*B2[1]*f[6]*dv10*wv2+0.7745966692414833*f[2]*B2[5]*dv10*wv2+0.8660254037844386*f[1]*B2[3]*dv10*wv2+0.8660254037844386*B2[0]*f[2]*dv10*wv2+0.8660254037844386*f[0]*B2[2]*dv10*wv2-0.223606797749979*B1[5]*f[13]*dv10*dv3-0.25*B1[0]*f[13]*dv10*dv3-0.25*B1[3]*f[12]*dv10*dv3-0.25*B1[2]*f[5]*dv10*dv3+0.223606797749979*B2[5]*f[10]*dv10*dv2+0.25*B2[0]*f[10]*dv10*dv2+0.25*B2[3]*f[9]*dv10*dv2+0.25*B2[2]*f[4]*dv10*dv2+0.7745966692414833*E0[2]*f[17]*dv10+0.8660254037844386*E0[1]*f[6]*dv10+0.7745966692414833*f[2]*E0[5]*dv10+0.8660254037844386*f[1]*E0[3]*dv10+0.8660254037844386*E0[0]*f[2]*dv10+0.8660254037844386*f[0]*E0[2]*dv10; 
  out[9] += 0.7745966692414833*B0[1]*f[16]*dv11*wv3+0.8660254037844386*B0[2]*f[6]*dv11*wv3+0.7745966692414833*f[1]*B0[4]*dv11*wv3+0.8660254037844386*f[2]*B0[3]*dv11*wv3+0.8660254037844386*B0[0]*f[1]*dv11*wv3+0.8660254037844386*f[0]*B0[1]*dv11*wv3-0.7745966692414833*B2[1]*f[16]*dv11*wv1-0.8660254037844386*B2[2]*f[6]*dv11*wv1-0.7745966692414833*f[1]*B2[4]*dv11*wv1-0.8660254037844386*f[2]*B2[3]*dv11*wv1-0.8660254037844386*B2[0]*f[1]*dv11*wv1-0.8660254037844386*f[0]*B2[1]*dv11*wv1+0.25*B0[3]*f[13]*dv11*dv3+0.223606797749979*B0[4]*f[12]*dv11*dv3+0.25*B0[0]*f[12]*dv11*dv3+0.25*B0[1]*f[5]*dv11*dv3-0.25*B2[3]*f[8]*dv1*dv11-0.223606797749979*B2[4]*f[7]*dv1*dv11-0.25*B2[0]*f[7]*dv1*dv11-0.25*B2[1]*f[3]*dv1*dv11+0.7745966692414833*E1[1]*f[16]*dv11+0.8660254037844386*E1[2]*f[6]*dv11+0.7745966692414833*f[1]*E1[4]*dv11+0.8660254037844386*f[2]*E1[3]*dv11+0.8660254037844386*E1[0]*f[1]*dv11+0.8660254037844386*f[0]*E1[1]*dv11; 
  out[10] += 0.7745966692414833*B0[2]*f[17]*dv11*wv3+0.8660254037844386*B0[1]*f[6]*dv11*wv3+0.7745966692414833*f[2]*B0[5]*dv11*wv3+0.8660254037844386*f[1]*B0[3]*dv11*wv3+0.8660254037844386*B0[0]*f[2]*dv11*wv3+0.8660254037844386*f[0]*B0[2]*dv11*wv3-0.7745966692414833*B2[2]*f[17]*dv11*wv1-0.8660254037844386*B2[1]*f[6]*dv11*wv1-0.7745966692414833*f[2]*B2[5]*dv11*wv1-0.8660254037844386*f[1]*B2[3]*dv11*wv1-0.8660254037844386*B2[0]*f[2]*dv11*wv1-0.8660254037844386*f[0]*B2[2]*dv11*wv1+0.223606797749979*B0[5]*f[13]*dv11*dv3+0.25*B0[0]*f[13]*dv11*dv3+0.25*B0[3]*f[12]*dv11*dv3+0.25*B0[2]*f[5]*dv11*dv3-0.223606797749979*B2[5]*f[8]*dv1*dv11-0.25*B2[0]*f[8]*dv1*dv11-0.25*B2[3]*f[7]*dv1*dv11-0.25*B2[2]*f[3]*dv1*dv11+0.7745966692414833*E1[2]*f[17]*dv11+0.8660254037844386*E1[1]*f[6]*dv11+0.7745966692414833*f[2]*E1[5]*dv11+0.8660254037844386*f[1]*E1[3]*dv11+0.8660254037844386*E1[0]*f[2]*dv11+0.8660254037844386*f[0]*E1[2]*dv11; 
  out[11] += 0.8660254037844386*B0[2]*f[8]*dv11*wv3+0.8660254037844386*B0[1]*f[7]*dv11*wv3+0.8660254037844386*B0[0]*f[3]*dv11*wv3-0.8660254037844386*B1[2]*f[10]*dv10*wv3-0.8660254037844386*B1[1]*f[9]*dv10*wv3-0.8660254037844386*B1[0]*f[4]*dv10*wv3+0.8660254037844386*B2[2]*f[10]*dv10*wv2+0.8660254037844386*B2[1]*f[9]*dv10*wv2+0.8660254037844386*B2[0]*f[4]*dv10*wv2-0.8660254037844386*B2[2]*f[8]*dv11*wv1-0.8660254037844386*B2[1]*f[7]*dv11*wv1-0.8660254037844386*B2[0]*f[3]*dv11*wv1+0.25*B0[0]*f[14]*dv11*dv3-0.25*B1[0]*f[15]*dv10*dv3+0.223606797749979*B2[0]*f[19]*dv10*dv2+0.25*B2[5]*f[17]*dv10*dv2+0.25*B2[4]*f[16]*dv10*dv2+0.25*B2[3]*f[6]*dv10*dv2+0.25*B2[2]*f[2]*dv10*dv2+0.25*B2[1]*f[1]*dv10*dv2+0.25*B2[0]*f[0]*dv10*dv2-0.223606797749979*B2[0]*f[18]*dv1*dv11-0.25*B2[5]*f[17]*dv1*dv11-0.25*B2[4]*f[16]*dv1*dv11-0.25*B2[3]*f[6]*dv1*dv11-0.25*B2[2]*f[2]*dv1*dv11-0.25*B2[1]*f[1]*dv1*dv11-0.25*B2[0]*f[0]*dv1*dv11+0.8660254037844386*E1[2]*f[8]*dv11+0.8660254037844386*E1[1]*f[7]*dv11+0.8660254037844386*E1[0]*f[3]*dv11+0.8660254037844386*E0[2]*f[10]*dv10+0.8660254037844386*E0[1]*f[9]*dv10+0.8660254037844386*E0[0]*f[4]*dv10; 
  out[12] += (-0.7745966692414833*B0[1]*f[16]*dv12*wv2)-0.8660254037844386*B0[2]*f[6]*dv12*wv2-0.7745966692414833*f[1]*B0[4]*dv12*wv2-0.8660254037844386*f[2]*B0[3]*dv12*wv2-0.8660254037844386*B0[0]*f[1]*dv12*wv2-0.8660254037844386*f[0]*B0[1]*dv12*wv2+0.7745966692414833*B1[1]*f[16]*dv12*wv1+0.8660254037844386*B1[2]*f[6]*dv12*wv1+0.7745966692414833*f[1]*B1[4]*dv12*wv1+0.8660254037844386*f[2]*B1[3]*dv12*wv1+0.8660254037844386*B1[0]*f[1]*dv12*wv1+0.8660254037844386*f[0]*B1[1]*dv12*wv1-0.25*B0[3]*f[10]*dv12*dv2-0.223606797749979*B0[4]*f[9]*dv12*dv2-0.25*B0[0]*f[9]*dv12*dv2-0.25*B0[1]*f[4]*dv12*dv2+0.25*B1[3]*f[8]*dv1*dv12+0.223606797749979*B1[4]*f[7]*dv1*dv12+0.25*B1[0]*f[7]*dv1*dv12+0.25*B1[1]*f[3]*dv1*dv12+0.7745966692414833*E2[1]*f[16]*dv12+0.8660254037844386*E2[2]*f[6]*dv12+0.7745966692414833*f[1]*E2[4]*dv12+0.8660254037844386*f[2]*E2[3]*dv12+0.8660254037844386*E2[0]*f[1]*dv12+0.8660254037844386*f[0]*E2[1]*dv12; 
  out[13] += (-0.7745966692414833*B0[2]*f[17]*dv12*wv2)-0.8660254037844386*B0[1]*f[6]*dv12*wv2-0.7745966692414833*f[2]*B0[5]*dv12*wv2-0.8660254037844386*f[1]*B0[3]*dv12*wv2-0.8660254037844386*B0[0]*f[2]*dv12*wv2-0.8660254037844386*f[0]*B0[2]*dv12*wv2+0.7745966692414833*B1[2]*f[17]*dv12*wv1+0.8660254037844386*B1[1]*f[6]*dv12*wv1+0.7745966692414833*f[2]*B1[5]*dv12*wv1+0.8660254037844386*f[1]*B1[3]*dv12*wv1+0.8660254037844386*B1[0]*f[2]*dv12*wv1+0.8660254037844386*f[0]*B1[2]*dv12*wv1-0.223606797749979*B0[5]*f[10]*dv12*dv2-0.25*B0[0]*f[10]*dv12*dv2-0.25*B0[3]*f[9]*dv12*dv2-0.25*B0[2]*f[4]*dv12*dv2+0.223606797749979*B1[5]*f[8]*dv1*dv12+0.25*B1[0]*f[8]*dv1*dv12+0.25*B1[3]*f[7]*dv1*dv12+0.25*B1[2]*f[3]*dv1*dv12+0.7745966692414833*E2[2]*f[17]*dv12+0.8660254037844386*E2[1]*f[6]*dv12+0.7745966692414833*f[2]*E2[5]*dv12+0.8660254037844386*f[1]*E2[3]*dv12+0.8660254037844386*E2[0]*f[2]*dv12+0.8660254037844386*f[0]*E2[2]*dv12; 
  out[14] += (-0.8660254037844386*B1[2]*f[13]*dv10*wv3)-0.8660254037844386*B1[1]*f[12]*dv10*wv3-0.8660254037844386*B1[0]*f[5]*dv10*wv3-0.8660254037844386*B0[2]*f[8]*dv12*wv2-0.8660254037844386*B0[1]*f[7]*dv12*wv2-0.8660254037844386*B0[0]*f[3]*dv12*wv2+0.8660254037844386*B2[2]*f[13]*dv10*wv2+0.8660254037844386*B2[1]*f[12]*dv10*wv2+0.8660254037844386*B2[0]*f[5]*dv10*wv2+0.8660254037844386*B1[2]*f[8]*dv12*wv1+0.8660254037844386*B1[1]*f[7]*dv12*wv1+0.8660254037844386*B1[0]*f[3]*dv12*wv1-0.223606797749979*B1[0]*f[20]*dv10*dv3-0.25*B1[5]*f[17]*dv10*dv3-0.25*B1[4]*f[16]*dv10*dv3-0.25*B1[3]*f[6]*dv10*dv3-0.25*B1[2]*f[2]*dv10*dv3-0.25*B1[1]*f[1]*dv10*dv3-0.25*B1[0]*f[0]*dv10*dv3-0.25*B0[0]*f[11]*dv12*dv2+0.25*B2[0]*f[15]*dv10*dv2+0.223606797749979*B1[0]*f[18]*dv1*dv12+0.25*B1[5]*f[17]*dv1*dv12+0.25*B1[4]*f[16]*dv1*dv12+0.25*B1[3]*f[6]*dv1*dv12+0.25*B1[2]*f[2]*dv1*dv12+0.25*B1[1]*f[1]*dv1*dv12+0.25*B1[0]*f[0]*dv1*dv12+0.8660254037844386*E2[2]*f[8]*dv12+0.8660254037844386*E2[1]*f[7]*dv12+0.8660254037844386*E2[0]*f[3]*dv12+0.8660254037844386*E0[2]*f[13]*dv10+0.8660254037844386*E0[1]*f[12]*dv10+0.8660254037844386*E0[0]*f[5]*dv10; 
  out[15] += 0.8660254037844386*B0[2]*f[13]*dv11*wv3+0.8660254037844386*B0[1]*f[12]*dv11*wv3+0.8660254037844386*B0[0]*f[5]*dv11*wv3-0.8660254037844386*B0[2]*f[10]*dv12*wv2-0.8660254037844386*B0[1]*f[9]*dv12*wv2-0.8660254037844386*B0[0]*f[4]*dv12*wv2+0.8660254037844386*B1[2]*f[10]*dv12*wv1+0.8660254037844386*B1[1]*f[9]*dv12*wv1+0.8660254037844386*B1[0]*f[4]*dv12*wv1-0.8660254037844386*B2[2]*f[13]*dv11*wv1-0.8660254037844386*B2[1]*f[12]*dv11*wv1-0.8660254037844386*B2[0]*f[5]*dv11*wv1+0.223606797749979*B0[0]*f[20]*dv11*dv3+0.25*B0[5]*f[17]*dv11*dv3+0.25*B0[4]*f[16]*dv11*dv3+0.25*B0[3]*f[6]*dv11*dv3+0.25*B0[2]*f[2]*dv11*dv3+0.25*B0[1]*f[1]*dv11*dv3+0.25*B0[0]*f[0]*dv11*dv3-0.223606797749979*B0[0]*f[19]*dv12*dv2-0.25*B0[5]*f[17]*dv12*dv2-0.25*B0[4]*f[16]*dv12*dv2-0.25*B0[3]*f[6]*dv12*dv2-0.25*B0[2]*f[2]*dv12*dv2-0.25*B0[1]*f[1]*dv12*dv2-0.25*B0[0]*f[0]*dv12*dv2+0.25*B1[0]*f[11]*dv1*dv12+0.8660254037844386*E2[2]*f[10]*dv12+0.8660254037844386*E2[1]*f[9]*dv12+0.8660254037844386*E2[0]*f[4]*dv12-0.25*B2[0]*f[14]*dv1*dv11+0.8660254037844386*E1[2]*f[13]*dv11+0.8660254037844386*E1[1]*f[12]*dv11+0.8660254037844386*E1[0]*f[5]*dv11; 
  out[18] += (-1.936491673103709*B1[2]*f[8]*dv10*wv3)-1.936491673103709*B1[1]*f[7]*dv10*wv3-1.936491673103709*B1[0]*f[3]*dv10*wv3+1.936491673103709*B2[2]*f[8]*dv10*wv2+1.936491673103709*B2[1]*f[7]*dv10*wv2+1.936491673103709*B2[0]*f[3]*dv10*wv2-0.5590169943749475*B1[0]*f[14]*dv10*dv3+0.5590169943749475*B2[0]*f[11]*dv10*dv2+1.936491673103709*E0[2]*f[8]*dv10+1.936491673103709*E0[1]*f[7]*dv10+1.936491673103709*E0[0]*f[3]*dv10; 
  out[19] += 1.936491673103709*B0[2]*f[10]*dv11*wv3+1.936491673103709*B0[1]*f[9]*dv11*wv3+1.936491673103709*B0[0]*f[4]*dv11*wv3-1.936491673103709*B2[2]*f[10]*dv11*wv1-1.936491673103709*B2[1]*f[9]*dv11*wv1-1.936491673103709*B2[0]*f[4]*dv11*wv1+0.5590169943749475*B0[0]*f[15]*dv11*dv3-0.5590169943749475*B2[0]*f[11]*dv1*dv11+1.936491673103709*E1[2]*f[10]*dv11+1.936491673103709*E1[1]*f[9]*dv11+1.936491673103709*E1[0]*f[4]*dv11; 
  out[20] += (-1.936491673103709*B0[2]*f[13]*dv12*wv2)-1.936491673103709*B0[1]*f[12]*dv12*wv2-1.936491673103709*B0[0]*f[5]*dv12*wv2+1.936491673103709*B1[2]*f[13]*dv12*wv1+1.936491673103709*B1[1]*f[12]*dv12*wv1+1.936491673103709*B1[0]*f[5]*dv12*wv1-0.5590169943749475*B0[0]*f[15]*dv12*dv2+0.5590169943749475*B1[0]*f[14]*dv1*dv12+1.936491673103709*E2[2]*f[13]*dv12+1.936491673103709*E2[1]*f[12]*dv12+1.936491673103709*E2[0]*f[5]*dv12; 
} 