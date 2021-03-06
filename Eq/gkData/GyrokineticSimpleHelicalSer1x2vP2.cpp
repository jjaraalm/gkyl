#include <GyrokineticSimpleHelicalModDecl.h> 
double GyrokineticSimpleHelicalVol1x2vSerP2_Bvars_0(const double q_, const double m_, const double *w, const double *dxv, const double *Bmag, const double *BmagInv, const double *Gradpar, const double *BdriftX, const double *BdriftY, const double *Phi, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. H/f: Input Hamiltonian/distribution function. out: Incremented output 
  double dfac_x = 2.0/dxv[0]; 
  double dfac_v = 2.0/dxv[1]; 
  double dfac_m = 2.0/dxv[2]; 
  double wx = w[0]; 
  double wv = w[1]; 
  double wm = w[2]; 
  double wv2 = wv*wv; 
  double dfac_v2 = dfac_v*dfac_v; 
  double q2 = q_*q_; 
  double m2 = m_*m_; 
  double cflFreq = 0.0; 
  double alphaL = 0.0; 
  double alphaR = 0.0; 
  double alphax[20]; 
  alphax[0] = 2.0*Gradpar[0]*dfac_x*wv; 
  alphax[2] = (1.154700538379252*Gradpar[0]*dfac_x)/dfac_v; 
#if cflType == SURFAVG 
  // evaluate surface-averaged alpha on left 
  alphaL = 0.1767766952966368*alphax[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate surface-averaged alpha on right 
  alphaR = 0.1767766952966368*alphax[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#elif cflType == QUAD 
  // evaluate alpha at left surface quadrature points 
  alphaL = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.0441941738241592*alphax[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.0441941738241592*alphax[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate alpha at right surface quadrature points 
  alphaR = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.0441941738241592*alphax[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3535533905932737*alphax[0]-0.4743416490252568*alphax[2]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.0441941738241592*alphax[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphax[2]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#endif 

  double alphav[20]; 
  alphav[0] = -(2.449489742783178*Gradpar[0]*Phi[1]*dfac_v*dfac_x*q_)/m_; 
  alphav[1] = -(5.477225575051662*Gradpar[0]*Phi[2]*dfac_v*dfac_x*q_)/m_; 
#if cflType == SURFAVG 
  // evaluate surface-averaged alpha on left 
  alphaL = 0.1767766952966368*alphav[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate surface-averaged alpha on right 
  alphaR = 0.1767766952966368*alphav[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#elif cflType == QUAD 
  // evaluate alpha at left surface quadrature points 
  alphaL = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.0441941738241592*alphav[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.0441941738241592*alphav[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate alpha at right surface quadrature points 
  alphaR = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.0441941738241592*alphav[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3535533905932737*alphav[0]-0.4743416490252568*alphav[1]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.0441941738241592*alphav[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#endif 

  out[1] += 0.6123724356957944*(alphax[2]*f[2]+alphax[0]*f[0]); 
  out[2] += 0.6123724356957944*(alphav[1]*f[1]+alphav[0]*f[0]); 
  out[4] += 0.1224744871391589*(4.47213595499958*(alphax[2]*f[8]+alphav[1]*f[7])+5.0*(alphax[0]*f[2]+f[0]*alphax[2]+alphav[0]*f[1]+f[0]*alphav[1])); 
  out[5] += 0.6123724356957944*(alphax[2]*f[6]+alphax[0]*f[3]); 
  out[6] += 0.6123724356957944*(alphav[1]*f[5]+alphav[0]*f[3]); 
  out[7] += 1.369306393762915*(alphax[2]*f[4]+alphax[0]*f[1]); 
  out[8] += 1.369306393762915*(alphav[1]*f[4]+alphav[0]*f[2]); 
  out[10] += 0.07071067811865474*(7.745966692414834*(alphax[2]*f[14]+alphav[1]*f[13])+8.660254037844386*(alphax[0]*f[6]+alphav[0]*f[5]+(alphax[2]+alphav[1])*f[3])); 
  out[11] += 0.07071067811865474*(17.32050807568877*alphax[2]*f[12]+8.660254037844387*alphav[0]*f[7]+19.36491673103708*alphax[0]*f[4]+f[1]*(19.36491673103708*alphax[2]+7.745966692414834*alphav[1])); 
  out[12] += 0.07071067811865474*(17.32050807568877*alphav[1]*f[11]+8.660254037844387*alphax[0]*f[8]+19.36491673103708*alphav[0]*f[4]+(7.745966692414834*alphax[2]+19.36491673103708*alphav[1])*f[2]); 
  out[13] += 1.369306393762915*(alphax[2]*f[10]+alphax[0]*f[5]); 
  out[14] += 1.369306393762915*(alphav[1]*f[10]+alphav[0]*f[6]); 
  out[15] += 0.07071067811865474*(8.660254037844386*alphax[2]*f[16]+8.660254037844387*alphax[0]*f[9]); 
  out[16] += 0.07071067811865474*(8.660254037844386*alphav[1]*f[15]+8.660254037844387*alphav[0]*f[9]); 
  out[17] += 0.07071067811865474*(17.32050807568877*alphax[2]*f[18]+8.660254037844387*alphav[0]*f[13]+19.36491673103709*alphax[0]*f[10]+(19.36491673103709*alphax[2]+7.745966692414834*alphav[1])*f[5]); 
  out[18] += 0.07071067811865474*(17.32050807568877*alphav[1]*f[17]+8.660254037844387*alphax[0]*f[14]+19.36491673103709*alphav[0]*f[10]+(7.745966692414834*alphax[2]+19.36491673103709*alphav[1])*f[6]); 
  out[19] += 0.07071067811865474*(8.660254037844387*(alphax[0]*f[16]+alphav[0]*f[15])+8.660254037844386*(alphax[2]+alphav[1])*f[9]); 
  return cflFreq; 
} 
double GyrokineticSimpleHelicalVol1x2vSerP2_Bvars_1(const double q_, const double m_, const double *w, const double *dxv, const double *Bmag, const double *BmagInv, const double *Gradpar, const double *BdriftX, const double *BdriftY, const double *Phi, const double *f, double *out) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. H/f: Input Hamiltonian/distribution function. out: Incremented output 
  double dfac_x = 2.0/dxv[0]; 
  double dfac_v = 2.0/dxv[1]; 
  double dfac_m = 2.0/dxv[2]; 
  double wx = w[0]; 
  double wv = w[1]; 
  double wm = w[2]; 
  double wv2 = wv*wv; 
  double dfac_v2 = dfac_v*dfac_v; 
  double q2 = q_*q_; 
  double m2 = m_*m_; 
  double cflFreq = 0.0; 
  double alphaL = 0.0; 
  double alphaR = 0.0; 
  double alphax[20]; 
  alphax[0] = 2.0*Gradpar[0]*dfac_x*wv; 
  alphax[1] = 2.0*Gradpar[1]*dfac_x*wv; 
  alphax[2] = (1.154700538379252*Gradpar[0]*dfac_x)/dfac_v; 
  alphax[4] = (1.154700538379252*Gradpar[1]*dfac_x)/dfac_v; 
  alphax[7] = 2.0*Gradpar[2]*dfac_x*wv; 
  alphax[11] = (1.154700538379251*Gradpar[2]*dfac_x)/dfac_v; 
#if cflType == SURFAVG 
  // evaluate surface-averaged alpha on left 
  alphaL = 0.125*(3.16227766016838*alphax[7]-2.449489742783178*alphax[1]+1.414213562373095*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate surface-averaged alpha on right 
  alphaR = 0.125*(3.16227766016838*alphax[7]+2.449489742783178*alphax[1]+1.414213562373095*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#elif cflType == QUAD 
  // evaluate alpha at left surface quadrature points 
  alphaL = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.7905694150420947*alphax[7]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.7905694150420947*alphax[7]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]-0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate alpha at right surface quadrature points 
  alphaR = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.7905694150420947*alphax[7]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*((-1.060660171779821*alphax[11])+0.7905694150420947*alphax[7]-0.8215838362577489*alphax[4]-0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.7905694150420947*alphax[7]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(1.060660171779821*alphax[11]+0.7905694150420947*alphax[7]+0.8215838362577489*alphax[4]+0.4743416490252568*alphax[2]+0.6123724356957944*alphax[1]+0.3535533905932737*alphax[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#endif 

  double alphav[20]; 
  alphav[0] = -(2.449489742783178*dfac_v*dfac_x*((2.23606797749979*Gradpar[1]*Bmag[2]+Gradpar[0]*Bmag[1])*wm+(2.23606797749979*Gradpar[1]*Phi[2]+Gradpar[0]*Phi[1])*q_))/m_; 
  alphav[1] = -(2.449489742783178*dfac_v*dfac_x*((Bmag[2]*(2.0*Gradpar[2]+2.23606797749979*Gradpar[0])+Bmag[1]*Gradpar[1])*wm+((2.0*Gradpar[2]+2.23606797749979*Gradpar[0])*Phi[2]+Gradpar[1]*Phi[1])*q_))/m_; 
  alphav[3] = -(1.414213562373095*(2.23606797749979*Gradpar[1]*Bmag[2]+Gradpar[0]*Bmag[1])*dfac_v*dfac_x)/(dfac_m*m_); 
  alphav[5] = -(1.414213562373095*(Bmag[2]*(2.0*Gradpar[2]+2.23606797749979*Gradpar[0])+Bmag[1]*Gradpar[1])*dfac_v*dfac_x)/(dfac_m*m_); 
  alphav[7] = -(2.449489742783178*dfac_v*dfac_x*((Bmag[1]*Gradpar[2]+2.0*Gradpar[1]*Bmag[2])*wm+(2.0*Gradpar[1]*Phi[2]+Phi[1]*Gradpar[2])*q_))/m_; 
  alphav[13] = -(1.414213562373095*(Bmag[1]*Gradpar[2]+2.0*Gradpar[1]*Bmag[2])*dfac_v*dfac_x)/(dfac_m*m_); 
#if cflType == SURFAVG 
  // evaluate surface-averaged alpha on left 
  alphaL = 0.1767766952966368*alphav[0]; 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate surface-averaged alpha on right 
  alphaR = 0.1767766952966368*alphav[0]; 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#elif cflType == QUAD 
  // evaluate alpha at left surface quadrature points 
  alphaL = 0.125*((-0.4242640687119285*alphav[13])+0.3162277660168379*alphav[7]+0.6363961030678926*alphav[5]-0.4743416490252568*(alphav[3]+alphav[1])+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.5303300858899104*alphav[13]-0.3952847075210473*alphav[7]-0.4743416490252568*alphav[3]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*((-0.4242640687119285*alphav[13])+0.3162277660168379*alphav[7]-0.6363961030678926*alphav[5]-0.4743416490252568*alphav[3]+0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3162277660168379*alphav[7]-0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.3162277660168379*alphav[7]+0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4242640687119285*alphav[13]+0.3162277660168379*alphav[7]-0.6363961030678926*alphav[5]+0.4743416490252568*alphav[3]-0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*((-0.5303300858899104*alphav[13])-0.3952847075210473*alphav[7]+0.4743416490252568*alphav[3]+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  alphaL = 0.125*(0.4242640687119285*alphav[13]+0.3162277660168379*alphav[7]+0.6363961030678926*alphav[5]+0.4743416490252568*(alphav[3]+alphav[1])+0.3535533905932737*alphav[0]); 
  cflFreq += -0.5*(alphaL-std::abs(alphaL)); 
  // evaluate alpha at right surface quadrature points 
  alphaR = 0.125*((-0.4242640687119285*alphav[13])+0.3162277660168379*alphav[7]+0.6363961030678926*alphav[5]-0.4743416490252568*(alphav[3]+alphav[1])+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.5303300858899104*alphav[13]-0.3952847075210473*alphav[7]-0.4743416490252568*alphav[3]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*((-0.4242640687119285*alphav[13])+0.3162277660168379*alphav[7]-0.6363961030678926*alphav[5]-0.4743416490252568*alphav[3]+0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3162277660168379*alphav[7]-0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.3162277660168379*alphav[7]+0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4242640687119285*alphav[13]+0.3162277660168379*alphav[7]-0.6363961030678926*alphav[5]+0.4743416490252568*alphav[3]-0.4743416490252568*alphav[1]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*((-0.5303300858899104*alphav[13])-0.3952847075210473*alphav[7]+0.4743416490252568*alphav[3]+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
  alphaR = 0.125*(0.4242640687119285*alphav[13]+0.3162277660168379*alphav[7]+0.6363961030678926*alphav[5]+0.4743416490252568*(alphav[3]+alphav[1])+0.3535533905932737*alphav[0]); 
  cflFreq += 0.5*(alphaR+std::abs(alphaR)); 
#endif 

  out[1] += 0.6123724356957944*(alphax[11]*f[11]+alphax[7]*f[7]+alphax[4]*f[4]+alphax[2]*f[2]+alphax[1]*f[1]+alphax[0]*f[0]); 
  out[2] += 0.6123724356957944*(alphav[13]*f[13]+alphav[7]*f[7]+alphav[5]*f[5]+alphav[3]*f[3]+alphav[1]*f[1]+alphav[0]*f[0]); 
  out[4] += 0.07071067811865474*(7.745966692414834*(alphav[5]*f[13]+f[5]*alphav[13]+alphax[4]*f[12])+8.660254037844387*(alphax[7]*f[11]+f[7]*alphax[11])+7.745966692414834*(alphax[2]*f[8]+alphav[1]*f[7]+f[1]*alphav[7])+8.660254037844386*(alphav[3]*f[5]+f[3]*alphav[5]+alphax[1]*f[4]+f[1]*alphax[4]+alphax[0]*f[2]+f[0]*alphax[2]+alphav[0]*f[1]+f[0]*alphav[1])); 
  out[5] += 0.07071067811865474*(8.660254037844387*(alphax[11]*f[17]+alphax[7]*f[13])+8.660254037844386*(alphax[4]*f[10]+alphax[2]*f[6]+alphax[1]*f[5]+alphax[0]*f[3])); 
  out[6] += 0.07071067811865474*(7.745966692414834*alphav[5]*f[15]+8.660254037844387*(alphav[7]*f[13]+f[7]*alphav[13])+7.745966692414834*alphav[3]*f[9]+8.660254037844386*(alphav[1]*f[5]+f[1]*alphav[5]+alphav[0]*f[3]+f[0]*alphav[3])); 
  out[7] += 0.07071067811865474*(17.32050807568877*(alphax[4]*f[11]+f[4]*alphax[11])+17.32050807568877*(alphax[1]*f[7]+f[1]*alphax[7])+19.36491673103709*(alphax[2]*f[4]+f[2]*alphax[4]+alphax[0]*f[1]+f[0]*alphax[1])); 
  out[8] += 1.369306393762915*(alphav[13]*f[17]+alphav[7]*f[11]+alphav[5]*f[10]+alphav[3]*f[6]+alphav[1]*f[4]+alphav[0]*f[2]); 
  out[10] += 0.07071067811865474*(7.745966692414834*alphax[4]*f[18]+8.660254037844386*alphax[7]*f[17]+6.928203230275509*alphav[13]*f[15]+7.745966692414834*(alphav[3]*f[15]+alphax[2]*f[14])+8.660254037844386*alphax[11]*f[13]+7.745966692414834*(alphav[1]*f[13]+f[1]*alphav[13])+8.660254037844386*alphax[1]*f[10]+7.745966692414834*(alphav[5]*(f[9]+f[7])+f[5]*alphav[7])+8.660254037844386*(alphax[0]*f[6]+(alphax[4]+alphav[0])*f[5]+f[0]*alphav[5]+(alphax[2]+alphav[1])*f[3]+f[1]*alphav[3])); 
  out[11] += 0.01010152544552211*(38.72983346207417*alphav[13]*f[13]+60.6217782649107*(alphav[3]*f[13]+f[3]*alphav[13])+108.4435336938077*alphax[11]*f[12]+121.2435565298214*(alphax[2]*f[12]+alphax[1]*f[11]+f[1]*alphax[11])+121.2435565298214*alphax[4]*f[8]+(38.72983346207417*alphav[7]+121.2435565298214*alphax[4]+60.62177826491071*alphav[0])*f[7]+121.2435565298214*f[4]*alphax[7]+60.62177826491071*f[0]*alphav[7]+54.22176684690384*alphav[5]*f[5]+135.5544171172596*(alphax[0]*f[4]+f[0]*alphax[4]+alphax[1]*f[2])+f[1]*(135.5544171172596*alphax[2]+54.22176684690384*alphav[1])); 
  out[12] += 0.07071067811865474*(17.32050807568877*alphav[5]*f[17]+17.32050807568877*f[10]*alphav[13]+8.660254037844386*alphax[1]*f[12]+(7.745966692414834*alphax[11]+17.32050807568877*alphav[1])*f[11]+19.36491673103708*alphav[3]*f[10]+8.660254037844387*alphax[0]*f[8]+17.32050807568877*f[4]*alphav[7]+19.36491673103708*alphav[5]*f[6]+(7.745966692414834*alphax[4]+19.36491673103708*alphav[0])*f[4]+(7.745966692414834*alphax[2]+19.36491673103708*alphav[1])*f[2]); 
  out[13] += 0.07071067811865474*(17.32050807568877*alphax[4]*f[17]+17.32050807568877*alphax[1]*f[13]+f[10]*(17.32050807568877*alphax[11]+19.36491673103708*alphax[2])+17.32050807568877*f[5]*alphax[7]+19.36491673103708*(alphax[4]*f[6]+alphax[0]*f[5]+alphax[1]*f[3])); 
  out[14] += 0.07071067811865474*(17.32050807568877*alphav[5]*f[19]+19.36491673103708*alphav[7]*f[17]+17.32050807568877*alphav[3]*f[16]+19.36491673103708*(f[11]*alphav[13]+alphav[1]*f[10]+alphav[0]*f[6]+f[4]*alphav[5]+f[2]*alphav[3])); 
  out[15] += 0.07071067811865474*(8.660254037844387*alphax[4]*f[19]+8.660254037844386*(alphax[2]*f[16]+alphax[1]*f[15])+8.660254037844387*alphax[0]*f[9]); 
  out[16] += 0.07071067811865474*(8.660254037844386*alphav[1]*f[15]+7.745966692414834*alphav[13]*f[13]+8.660254037844387*alphav[0]*f[9]+7.745966692414834*(alphav[5]*f[5]+alphav[3]*f[3])); 
  out[17] += 0.002020305089104421*(542.2176684690384*alphax[11]*f[18]+606.217782649107*(alphax[2]*f[18]+alphax[1]*f[17])+242.4871130596428*alphav[5]*f[15]+606.2177826491072*alphax[4]*f[14]+(193.6491673103708*alphav[7]+606.2177826491072*alphax[4]+303.1088913245536*alphav[0])*f[13]+(271.1088342345192*f[9]+193.6491673103708*f[7]+303.1088913245536*f[0])*alphav[13]+606.2177826491072*f[5]*alphax[11]+(606.217782649107*alphax[7]+677.7720855862981*alphax[0])*f[10]+303.1088913245535*(alphav[3]*f[7]+f[3]*alphav[7])+677.7720855862981*(alphax[1]*f[6]+alphax[2]*f[5])+271.1088342345192*(alphav[1]*f[5]+f[1]*alphav[5])+677.7720855862981*f[3]*alphax[4]); 
  out[18] += 0.07071067811865474*((15.49193338482967*alphav[13]+17.32050807568877*alphav[3])*f[19]+8.660254037844386*alphax[1]*f[18]+(7.745966692414834*alphax[11]+17.32050807568877*alphav[1])*f[17]+17.32050807568877*alphav[5]*f[16]+8.660254037844387*alphax[0]*f[14]+17.32050807568877*(f[4]*alphav[13]+alphav[5]*f[11])+(17.32050807568877*alphav[7]+7.745966692414834*alphax[4]+19.36491673103709*alphav[0])*f[10]+7.745966692414834*alphax[2]*f[6]+19.36491673103709*(alphav[1]*f[6]+f[2]*alphav[5]+alphav[3]*f[4])); 
  out[19] += 0.01414213562373095*(43.30127018922193*alphax[1]*f[19]+43.30127018922195*alphax[0]*f[16]+(38.72983346207417*alphav[7]+43.30127018922195*(alphax[4]+alphav[0]))*f[15]+34.64101615137755*(alphav[5]*f[13]+f[5]*alphav[13])+43.30127018922193*(alphax[2]+alphav[1])*f[9]+38.72983346207418*(alphav[3]*f[5]+f[3]*alphav[5])); 
  return cflFreq; 
} 
