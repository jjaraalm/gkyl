#include <VlasovModDecl.h> 
double VlasovVol1x1vMaxP1(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  double dv0dx0 = dxv[1]/dxv[0]; 
  double w0dx0 = w[1]/dxv[0]; 
  const double dv10 = 2/dxv[1]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[1], wv1 = w[1]; 

  const double *B0 = &EM[6]; 
  const double *B1 = &EM[8]; 
  const double *B2 = &EM[10]; 

  double abar0[2]; 


  abar0[0] = E0[0]; 
  abar0[1] = E0[1]; 

  double incr0[3]; 

  double incr1[3]; 

  for(unsigned int i=0; i<3; ++i){ 

    incr0[i]=0.0; 

    incr1[i]=0.0; 

  }; 

  incr0[1] = 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  const double amid1 = 0.7071067811865475*abar0[0]; 
  incr1[2] = 1.224744871391589*abar0[1]*f[1]+1.224744871391589*abar0[0]*f[0]; 

  out[1] += incr0[1]; 
  out[2] += incr1[2]*dv10; 
return std::abs(w0dx0)+dv0dx0/2+std::abs(amid1)/dv1; 
} 
double VlasovVol1x1vMaxP2(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  double dv0dx0 = dxv[1]/dxv[0]; 
  double w0dx0 = w[1]/dxv[0]; 
  const double dv10 = 2/dxv[1]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[1], wv1 = w[1]; 

  const double *B0 = &EM[9]; 
  const double *B1 = &EM[12]; 
  const double *B2 = &EM[15]; 

  double abar0[3]; 


  abar0[0] = E0[0]; 
  abar0[1] = E0[1]; 
  abar0[2] = E0[2]; 

  double incr0[6]; 

  double incr1[6]; 

  for(unsigned int i=0; i<6; ++i){ 

    incr0[i]=0.0; 

    incr1[i]=0.0; 

  }; 

  incr0[1] = 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  incr0[3] = 3.464101615137754*f[2]*w0dx0+(0.8944271909999159*f[5]+f[0])*dv0dx0; 
  incr0[4] = 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[3]*dv0dx0; 
  const double amid1 = 0.7071067811865475*abar0[0]-0.7905694150420947*abar0[2]; 
  incr1[2] = 1.224744871391589*abar0[2]*f[4]+1.224744871391589*abar0[1]*f[1]+1.224744871391589*abar0[0]*f[0]; 
  incr1[3] = abar0[1]*(1.095445115010332*f[4]+1.224744871391589*f[0])+1.095445115010332*f[1]*abar0[2]+1.224744871391589*abar0[0]*f[1]; 
  incr1[5] = 2.738612787525831*abar0[1]*f[3]+2.738612787525831*abar0[0]*f[2]; 

  out[1] += incr0[1]; 
  out[2] += incr1[2]*dv10; 
  out[3] += incr1[3]*dv10+incr0[3]; 
  out[4] += incr0[4]; 
  out[5] += incr1[5]*dv10; 
return std::abs(w0dx0)+dv0dx0/2+std::abs(amid1)/dv1; 
} 
double VlasovVol1x1vMaxP3(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  double dv0dx0 = dxv[1]/dxv[0]; 
  double w0dx0 = w[1]/dxv[0]; 
  const double dv10 = 2/dxv[1]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[1], wv1 = w[1]; 

  const double *B0 = &EM[12]; 
  const double *B1 = &EM[16]; 
  const double *B2 = &EM[20]; 

  double abar0[4]; 


  abar0[0] = E0[0]; 
  abar0[1] = E0[1]; 
  abar0[2] = E0[2]; 
  abar0[3] = E0[3]; 

  double incr0[10]; 

  double incr1[10]; 

  for(unsigned int i=0; i<10; ++i){ 

    incr0[i]=0.0; 

    incr1[i]=0.0; 

  }; 

  incr0[1] = 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  incr0[3] = 3.464101615137754*f[2]*w0dx0+(0.8944271909999159*f[5]+f[0])*dv0dx0; 
  incr0[4] = 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[3]*dv0dx0; 
  incr0[6] = 7.745966692414834*f[3]*w0dx0+(2.0*f[7]+2.23606797749979*f[1])*dv0dx0; 
  incr0[7] = 3.464101615137755*f[5]*w0dx0+(0.8783100656536798*f[9]+0.8944271909999161*f[2])*dv0dx0; 
  incr0[8] = (11.83215956619923*f[4]+5.291502622129181*f[0])*w0dx0+(3.415650255319866*f[6]+1.527525231651947*f[2])*dv0dx0; 
  const double amid1 = 0.7071067811865475*abar0[0]-0.7905694150420947*abar0[2]; 
  incr1[2] = 1.224744871391589*abar0[3]*f[8]+1.224744871391589*abar0[2]*f[4]+1.224744871391589*abar0[1]*f[1]+1.224744871391589*abar0[0]*f[0]; 
  incr1[3] = abar0[2]*(1.075705748400954*f[8]+1.095445115010332*f[1])+abar0[1]*(1.095445115010332*f[4]+1.224744871391589*f[0])+1.075705748400954*abar0[3]*f[4]+1.224744871391589*abar0[0]*f[1]; 
  incr1[5] = 2.738612787525831*abar0[2]*f[6]+2.738612787525831*abar0[1]*f[3]+2.738612787525831*abar0[0]*f[2]; 
  incr1[6] = abar0[1]*(1.075705748400954*f[8]+1.095445115010332*f[1])+abar0[3]*(0.7302967433402215*f[8]+1.075705748400954*f[1])+1.224744871391589*abar0[0]*f[4]+abar0[2]*(0.7824607964359517*f[4]+1.224744871391589*f[0]); 
  incr1[7] = abar0[1]*(2.449489742783178*f[6]+2.738612787525831*f[2])+2.405351177211819*abar0[3]*f[6]+2.449489742783178*abar0[2]*f[3]+2.738612787525831*abar0[0]*f[3]; 
  incr1[9] = 1.870828693386971*abar0[3]*f[8]+abar0[1]*(4.183300132670379*f[7]+1.870828693386971*f[1])+abar0[0]*(4.183300132670378*f[5]+1.870828693386971*f[0])+1.870828693386971*abar0[2]*f[4]; 

  out[1] += incr0[1]; 
  out[2] += incr1[2]*dv10; 
  out[3] += incr1[3]*dv10+incr0[3]; 
  out[4] += incr0[4]; 
  out[5] += incr1[5]*dv10; 
  out[6] += incr1[6]*dv10+incr0[6]; 
  out[7] += incr1[7]*dv10+incr0[7]; 
  out[8] += incr0[8]; 
  out[9] += incr1[9]*dv10; 
return std::abs(w0dx0)+dv0dx0/2+std::abs(amid1)/dv1; 
} 
double VlasovVol1x1vMaxP4(const double *w, const double *dxv, const double *EM, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. EM/f: Input EM-field/distribution function. out: Incremented output 
  double dv0dx0 = dxv[1]/dxv[0]; 
  double w0dx0 = w[1]/dxv[0]; 
  const double dv10 = 2/dxv[1]; 
  const double *E0 = &EM[0]; 
  const double dv1 = dxv[1], wv1 = w[1]; 

  const double *B0 = &EM[15]; 
  const double *B1 = &EM[20]; 
  const double *B2 = &EM[25]; 

  double abar0[5]; 


  abar0[0] = E0[0]; 
  abar0[1] = E0[1]; 
  abar0[2] = E0[2]; 
  abar0[3] = E0[3]; 
  abar0[4] = E0[4]; 

  double incr0[15]; 

  double incr1[15]; 

  for(unsigned int i=0; i<15; ++i){ 

    incr0[i]=0.0; 

    incr1[i]=0.0; 

  }; 

  incr0[1] = 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  incr0[3] = 3.464101615137754*f[2]*w0dx0+(0.8944271909999159*f[5]+f[0])*dv0dx0; 
  incr0[4] = 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[3]*dv0dx0; 
  incr0[6] = 7.745966692414834*f[3]*w0dx0+(2.0*f[7]+2.23606797749979*f[1])*dv0dx0; 
  incr0[7] = 3.464101615137755*f[5]*w0dx0+(0.8783100656536798*f[9]+0.8944271909999161*f[2])*dv0dx0; 
  incr0[8] = (11.83215956619923*f[4]+5.291502622129181*f[0])*w0dx0+(3.415650255319866*f[6]+1.527525231651947*f[2])*dv0dx0; 
  incr0[10] = 7.745966692414834*f[7]*w0dx0+(1.963961012123931*f[12]+2.0*f[3])*dv0dx0; 
  incr0[11] = (11.83215956619923*f[6]+5.291502622129181*f[2])*w0dx0+(3.055050463303893*f[10]+1.366260102127946*f[5]+3.415650255319866*f[4]+1.527525231651947*f[0])*dv0dx0; 
  incr0[12] = 3.464101615137754*f[9]*w0dx0+(0.8728715609439696*f[14]+0.8783100656536798*f[5])*dv0dx0; 
  incr0[13] = (15.87450786638754*f[8]+10.39230484541326*f[1])*w0dx0+(4.58257569495584*f[11]+3.0*f[3])*dv0dx0; 
  const double amid1 = 0.7954951288348656*abar0[4]-0.7905694150420947*abar0[2]+0.7071067811865475*abar0[0]; 
  incr1[2] = 1.224744871391589*abar0[4]*f[13]+1.224744871391589*abar0[3]*f[8]+1.224744871391589*abar0[2]*f[4]+1.224744871391589*abar0[1]*f[1]+1.224744871391589*abar0[0]*f[0]; 
  incr1[3] = abar0[3]*(1.069044967649698*f[13]+1.075705748400954*f[4])+abar0[2]*(1.075705748400954*f[8]+1.095445115010332*f[1])+1.069044967649698*abar0[4]*f[8]+abar0[1]*(1.095445115010332*f[4]+1.224744871391589*f[0])+1.224744871391589*abar0[0]*f[1]; 
  incr1[5] = 2.73861278752583*abar0[3]*f[11]+2.738612787525831*abar0[2]*f[6]+2.738612787525831*abar0[1]*f[3]+2.738612787525831*abar0[0]*f[2]; 
  incr1[6] = abar0[2]*(1.049781318335648*f[13]+0.7824607964359517*f[4]+1.224744871391589*f[0])+abar0[4]*(0.7113279967599562*f[13]+1.049781318335648*f[4])+abar0[1]*(1.075705748400954*f[8]+1.095445115010332*f[1])+abar0[3]*(0.7302967433402215*f[8]+1.075705748400954*f[1])+1.224744871391589*abar0[0]*f[4]; 
  incr1[7] = abar0[2]*(2.405351177211819*f[11]+2.449489742783178*f[3])+2.390457218668788*abar0[4]*f[11]+abar0[1]*(2.449489742783178*f[6]+2.738612787525831*f[2])+2.405351177211819*abar0[3]*f[6]+2.738612787525831*abar0[0]*f[3]; 
  incr1[9] = 1.870828693386971*abar0[4]*f[13]+abar0[2]*(4.183300132670378*f[10]+1.870828693386971*f[4])+1.870828693386971*abar0[3]*f[8]+abar0[1]*(4.183300132670379*f[7]+1.870828693386971*f[1])+abar0[0]*(4.183300132670378*f[5]+1.870828693386971*f[0]); 
  incr1[10] = abar0[1]*(2.405351177211819*f[11]+2.449489742783178*f[3])+abar0[3]*(1.632993161855452*f[11]+2.405351177211819*f[3])+abar0[2]*(1.749635530559413*f[6]+2.738612787525831*f[2])+2.347382389307855*abar0[4]*f[6]+2.738612787525831*abar0[0]*f[6]; 
  incr1[11] = abar0[1]*(1.069044967649698*f[13]+1.075705748400954*f[4])+abar0[3]*(0.6680426571226847*f[13]+0.7302967433402215*f[4]+1.224744871391589*f[0])+1.224744871391589*abar0[0]*f[8]+abar0[2]*(0.7302967433402215*f[8]+1.075705748400954*f[1])+abar0[4]*(0.6680426571226847*f[8]+1.069044967649698*f[1]); 
  incr1[12] = abar0[3]*(1.632993161855452*f[13]+3.674234614174766*f[10]+1.643167672515498*f[4])+abar0[1]*(3.741657386773942*f[10]+4.183300132670378*f[5]+1.673320053068151*f[4]+1.870828693386971*f[0])+abar0[2]*(1.643167672515498*f[8]+3.741657386773941*f[7]+1.673320053068151*f[1])+1.632993161855452*abar0[4]*f[8]+abar0[0]*(4.183300132670377*f[7]+1.870828693386971*f[1]); 
  incr1[14] = abar0[1]*(5.612486080160911*f[12]+3.674234614174766*f[3])+3.674234614174766*abar0[3]*f[11]+abar0[0]*(5.612486080160912*f[9]+3.674234614174766*f[2])+3.674234614174767*abar0[2]*f[6]; 

  out[1] += incr0[1]; 
  out[2] += incr1[2]*dv10; 
  out[3] += incr1[3]*dv10+incr0[3]; 
  out[4] += incr0[4]; 
  out[5] += incr1[5]*dv10; 
  out[6] += incr1[6]*dv10+incr0[6]; 
  out[7] += incr1[7]*dv10+incr0[7]; 
  out[8] += incr0[8]; 
  out[9] += incr1[9]*dv10; 
  out[10] += incr1[10]*dv10+incr0[10]; 
  out[11] += incr1[11]*dv10+incr0[11]; 
  out[12] += incr1[12]*dv10+incr0[12]; 
  out[13] += incr0[13]; 
  out[14] += incr1[14]*dv10; 
return std::abs(w0dx0)+dv0dx0/2+std::abs(amid1)/dv1; 
} 
