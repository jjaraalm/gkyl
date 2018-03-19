#include <VlasovModDecl.h> 
void VlasovVolElc1x1vSerP1(const double *w, const double *dxv, const double *E, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. E/f: Input electric-field/distribution function. out: Incremented output 
  double dv10 = 2/dxv[1]; 
  const double *E0 = &E[0]; 
  out[2] += 1.224744871391589*f[1]*E0[1]*dv10+1.224744871391589*f[0]*E0[0]*dv10; 
  out[3] += 1.224744871391589*f[0]*E0[1]*dv10+1.224744871391589*E0[0]*f[1]*dv10; 
} 
void VlasovVolElc1x1vSerP2(const double *w, const double *dxv, const double *E, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. E/f: Input electric-field/distribution function. out: Incremented output 
  double dv10 = 2/dxv[1]; 
  const double *E0 = &E[0]; 
  out[2] += 1.224744871391589*E0[2]*f[4]*dv10+1.224744871391589*f[1]*E0[1]*dv10+1.224744871391589*f[0]*E0[0]*dv10; 
  out[3] += 1.095445115010332*E0[1]*f[4]*dv10+1.095445115010332*f[1]*E0[2]*dv10+1.224744871391589*f[0]*E0[1]*dv10+1.224744871391589*E0[0]*f[1]*dv10; 
  out[5] += 2.738612787525831*E0[2]*f[6]*dv10+2.738612787525831*E0[1]*f[3]*dv10+2.738612787525831*E0[0]*f[2]*dv10; 
  out[6] += 0.7824607964359517*E0[2]*f[4]*dv10+1.224744871391589*E0[0]*f[4]*dv10+1.224744871391589*f[0]*E0[2]*dv10+1.095445115010332*f[1]*E0[1]*dv10; 
  out[7] += 2.449489742783178*E0[1]*f[6]*dv10+2.449489742783178*E0[2]*f[3]*dv10+2.738612787525831*E0[0]*f[3]*dv10+2.738612787525831*E0[1]*f[2]*dv10; 
} 
void VlasovVolElc1x1vSerP3(const double *w, const double *dxv, const double *E, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. E/f: Input electric-field/distribution function. out: Incremented output 
  double dv10 = 2/dxv[1]; 
  const double *E0 = &E[0]; 
  out[2] += 1.224744871391589*E0[3]*f[8]*dv10+1.224744871391589*E0[2]*f[4]*dv10+1.224744871391589*f[1]*E0[1]*dv10+1.224744871391589*f[0]*E0[0]*dv10; 
  out[3] += 1.075705748400954*E0[2]*f[8]*dv10+1.075705748400954*E0[3]*f[4]*dv10+1.095445115010332*E0[1]*f[4]*dv10+1.095445115010332*f[1]*E0[2]*dv10+1.224744871391589*f[0]*E0[1]*dv10+1.224744871391589*E0[0]*f[1]*dv10; 
  out[5] += 2.73861278752583*E0[3]*f[10]*dv10+2.738612787525831*E0[2]*f[6]*dv10+2.738612787525831*E0[1]*f[3]*dv10+2.738612787525831*E0[0]*f[2]*dv10; 
  out[6] += 0.7302967433402215*E0[3]*f[8]*dv10+1.075705748400954*E0[1]*f[8]*dv10+0.7824607964359517*E0[2]*f[4]*dv10+1.224744871391589*E0[0]*f[4]*dv10+1.075705748400954*f[1]*E0[3]*dv10+1.224744871391589*f[0]*E0[2]*dv10+1.095445115010332*f[1]*E0[1]*dv10; 
  out[7] += 2.405351177211819*E0[2]*f[10]*dv10+2.405351177211819*E0[3]*f[6]*dv10+2.449489742783178*E0[1]*f[6]*dv10+2.449489742783178*E0[2]*f[3]*dv10+2.738612787525831*E0[0]*f[3]*dv10+2.738612787525831*E0[1]*f[2]*dv10; 
  out[9] += 1.870828693386971*E0[3]*f[8]*dv10+4.183300132670379*E0[1]*f[7]*dv10+4.183300132670378*E0[0]*f[5]*dv10+1.870828693386971*E0[2]*f[4]*dv10+1.870828693386971*f[1]*E0[1]*dv10+1.870828693386971*f[0]*E0[0]*dv10; 
  out[10] += 0.7302967433402215*E0[2]*f[8]*dv10+1.224744871391589*E0[0]*f[8]*dv10+0.7302967433402215*E0[3]*f[4]*dv10+1.075705748400954*E0[1]*f[4]*dv10+1.224744871391589*f[0]*E0[3]*dv10+1.075705748400954*f[1]*E0[2]*dv10; 
  out[11] += 1.643167672515498*E0[2]*f[8]*dv10+3.741657386773941*E0[2]*f[7]*dv10+4.183300132670377*E0[0]*f[7]*dv10+4.183300132670378*E0[1]*f[5]*dv10+1.643167672515498*E0[3]*f[4]*dv10+1.673320053068151*E0[1]*f[4]*dv10+1.673320053068151*f[1]*E0[2]*dv10+1.870828693386971*f[0]*E0[1]*dv10+1.870828693386971*E0[0]*f[1]*dv10; 
} 
void VlasovVolElc1x1vSerP4(const double *w, const double *dxv, const double *E, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. E/f: Input electric-field/distribution function. out: Incremented output 
  double dv10 = 2/dxv[1]; 
  const double *E0 = &E[0]; 
  out[2] += 1.224744871391589*E0[4]*f[13]*dv10+1.224744871391589*E0[3]*f[8]*dv10+1.224744871391589*E0[2]*f[4]*dv10+1.224744871391589*f[1]*E0[1]*dv10+1.224744871391589*f[0]*E0[0]*dv10; 
  out[3] += 1.069044967649698*E0[3]*f[13]*dv10+1.069044967649698*E0[4]*f[8]*dv10+1.075705748400954*E0[2]*f[8]*dv10+1.075705748400954*E0[3]*f[4]*dv10+1.095445115010332*E0[1]*f[4]*dv10+1.095445115010332*f[1]*E0[2]*dv10+1.224744871391589*f[0]*E0[1]*dv10+1.224744871391589*E0[0]*f[1]*dv10; 
  out[5] += 2.738612787525831*E0[4]*f[15]*dv10+2.73861278752583*E0[3]*f[11]*dv10+2.738612787525831*E0[2]*f[6]*dv10+2.738612787525831*E0[1]*f[3]*dv10+2.738612787525831*E0[0]*f[2]*dv10; 
  out[6] += 0.7113279967599562*E0[4]*f[13]*dv10+1.049781318335648*E0[2]*f[13]*dv10+0.7302967433402215*E0[3]*f[8]*dv10+1.075705748400954*E0[1]*f[8]*dv10+1.049781318335648*f[4]*E0[4]*dv10+0.7824607964359517*E0[2]*f[4]*dv10+1.224744871391589*E0[0]*f[4]*dv10+1.075705748400954*f[1]*E0[3]*dv10+1.224744871391589*f[0]*E0[2]*dv10+1.095445115010332*f[1]*E0[1]*dv10; 
  out[7] += 2.390457218668788*E0[3]*f[15]*dv10+2.390457218668788*E0[4]*f[11]*dv10+2.405351177211819*E0[2]*f[11]*dv10+2.405351177211819*E0[3]*f[6]*dv10+2.449489742783178*E0[1]*f[6]*dv10+2.449489742783178*E0[2]*f[3]*dv10+2.738612787525831*E0[0]*f[3]*dv10+2.738612787525831*E0[1]*f[2]*dv10; 
  out[9] += 1.870828693386971*E0[4]*f[13]*dv10+4.183300132670378*E0[2]*f[10]*dv10+1.870828693386971*E0[3]*f[8]*dv10+4.183300132670379*E0[1]*f[7]*dv10+4.183300132670378*E0[0]*f[5]*dv10+1.870828693386971*E0[2]*f[4]*dv10+1.870828693386971*f[1]*E0[1]*dv10+1.870828693386971*f[0]*E0[0]*dv10; 
  out[10] += 1.590577755054012*E0[4]*f[15]*dv10+2.347382389307855*E0[2]*f[15]*dv10+1.632993161855452*E0[3]*f[11]*dv10+2.405351177211819*E0[1]*f[11]*dv10+2.347382389307855*E0[4]*f[6]*dv10+1.749635530559413*E0[2]*f[6]*dv10+2.738612787525831*E0[0]*f[6]*dv10+2.405351177211819*f[3]*E0[3]*dv10+2.449489742783178*E0[1]*f[3]*dv10+2.738612787525831*f[2]*E0[2]*dv10; 
  out[11] += 0.6680426571226847*E0[3]*f[13]*dv10+1.069044967649698*E0[1]*f[13]*dv10+0.6680426571226847*E0[4]*f[8]*dv10+0.7302967433402215*E0[2]*f[8]*dv10+1.224744871391589*E0[0]*f[8]*dv10+1.069044967649698*f[1]*E0[4]*dv10+0.7302967433402215*E0[3]*f[4]*dv10+1.075705748400954*E0[1]*f[4]*dv10+1.224744871391589*f[0]*E0[3]*dv10+1.075705748400954*f[1]*E0[2]*dv10; 
  out[12] += 1.632993161855452*E0[3]*f[13]*dv10+3.674234614174766*E0[3]*f[10]*dv10+3.741657386773942*E0[1]*f[10]*dv10+1.632993161855452*E0[4]*f[8]*dv10+1.643167672515498*E0[2]*f[8]*dv10+3.741657386773941*E0[2]*f[7]*dv10+4.183300132670377*E0[0]*f[7]*dv10+4.183300132670378*E0[1]*f[5]*dv10+1.643167672515498*E0[3]*f[4]*dv10+1.673320053068151*E0[1]*f[4]*dv10+1.673320053068151*f[1]*E0[2]*dv10+1.870828693386971*f[0]*E0[1]*dv10+1.870828693386971*E0[0]*f[1]*dv10; 
  out[14] += 3.674234614174766*E0[4]*f[15]*dv10+5.612486080160911*E0[1]*f[12]*dv10+3.674234614174766*E0[3]*f[11]*dv10+5.612486080160912*E0[0]*f[9]*dv10+3.674234614174767*E0[2]*f[6]*dv10+3.674234614174766*E0[1]*f[3]*dv10+3.674234614174766*E0[0]*f[2]*dv10; 
  out[15] += 0.5946313761201917*E0[4]*f[13]*dv10+0.7113279967599563*E0[2]*f[13]*dv10+1.224744871391589*E0[0]*f[13]*dv10+0.6680426571226848*E0[3]*f[8]*dv10+1.069044967649698*E0[1]*f[8]*dv10+0.7113279967599563*f[4]*E0[4]*dv10+1.224744871391589*f[0]*E0[4]*dv10+1.049781318335648*E0[2]*f[4]*dv10+1.069044967649698*f[1]*E0[3]*dv10; 
  out[16] += 3.207134902949093*E0[3]*f[15]*dv10+5.019960159204453*E0[2]*f[12]*dv10+5.612486080160911*E0[0]*f[12]*dv10+3.207134902949093*E0[4]*f[11]*dv10+3.227117245202861*E0[2]*f[11]*dv10+5.612486080160912*E0[1]*f[9]*dv10+3.227117245202861*E0[3]*f[6]*dv10+3.286335345030997*E0[1]*f[6]*dv10+3.286335345030996*E0[2]*f[3]*dv10+3.674234614174766*E0[0]*f[3]*dv10+3.674234614174766*E0[1]*f[2]*dv10; 
} 