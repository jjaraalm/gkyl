#include <VlasovModDecl.h> 
double VlasovSurfElcMag2x3vMax_VX_P2(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double amax, const double *EM, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w: Cell-center coordinates. dxv[NDIM]: Cell spacing. amax: amax in global lax flux. E: EM field. fl/fr: Distribution function in left/right cells 
// outl/outr: output distribution function in left/right cells 
// returns abs(amid) for use in determining amax in cfl and global lax flux 
  double dv10l = 2/dxvl[2]; 
  double dv10r = 2/dxvr[2]; 
  const double *E0 = &EM[0]; 

  const double dv1 = dxvr[2], wv1 = wr[2]; 
  const double dv2 = dxvr[3], wv2 = wr[3]; 
  const double dv3 = dxvr[4], wv3 = wr[4]; 

  const double *B0 = &EM[18]; 
  const double *B1 = &EM[24]; 
  const double *B2 = &EM[30]; 

  double Ghat[21]; 

  double alpha[21]; 

  double favg[21]; 

  favg[0] = 1*fr[0]+fl[0]; 
  favg[1] = 1*fr[1]+fl[1]; 
  favg[2] = 1*fr[2]+fl[2]; 
  favg[3] = -1*fr[3]+fl[3]; 
  favg[4] = 1*fr[4]+fl[4]; 
  favg[5] = 1*fr[5]+fl[5]; 
  favg[6] = 1*fr[6]+fl[6]; 
  favg[7] = -1*fr[7]+fl[7]; 
  favg[8] = -1*fr[8]+fl[8]; 
  favg[9] = 1*fr[9]+fl[9]; 
  favg[10] = 1*fr[10]+fl[10]; 
  favg[11] = -1*fr[11]+fl[11]; 
  favg[12] = 1*fr[12]+fl[12]; 
  favg[13] = 1*fr[13]+fl[13]; 
  favg[14] = -1*fr[14]+fl[14]; 
  favg[15] = 1*fr[15]+fl[15]; 
  favg[16] = 1*fr[16]+fl[16]; 
  favg[17] = 1*fr[17]+fl[17]; 
  favg[18] = 1*fr[18]+fl[18]; 
  favg[19] = 1*fr[19]+fl[19]; 
  favg[20] = 1*fr[20]+fl[20]; 
  double fjump[21]; 

  fjump[0] = amax*(1*fr[0]-fl[0]); 
  fjump[1] = amax*(1*fr[1]-fl[1]); 
  fjump[2] = amax*(1*fr[2]-fl[2]); 
  fjump[3] = amax*(-1*fr[3]-fl[3]); 
  fjump[4] = amax*(1*fr[4]-fl[4]); 
  fjump[5] = amax*(1*fr[5]-fl[5]); 
  fjump[6] = amax*(1*fr[6]-fl[6]); 
  fjump[7] = amax*(-1*fr[7]-fl[7]); 
  fjump[8] = amax*(-1*fr[8]-fl[8]); 
  fjump[9] = amax*(1*fr[9]-fl[9]); 
  fjump[10] = amax*(1*fr[10]-fl[10]); 
  fjump[11] = amax*(-1*fr[11]-fl[11]); 
  fjump[12] = amax*(1*fr[12]-fl[12]); 
  fjump[13] = amax*(1*fr[13]-fl[13]); 
  fjump[14] = amax*(-1*fr[14]-fl[14]); 
  fjump[15] = amax*(1*fr[15]-fl[15]); 
  fjump[16] = amax*(1*fr[16]-fl[16]); 
  fjump[17] = amax*(1*fr[17]-fl[17]); 
  fjump[18] = amax*(1*fr[18]-fl[18]); 
  fjump[19] = amax*(1*fr[19]-fl[19]); 
  fjump[20] = amax*(1*fr[20]-fl[20]); 
  alpha[0] = 2.828427124746191*(B2[0]*wv2+E0[0])-2.828427124746191*B1[0]*wv3; 
  alpha[1] = 2.828427124746191*(B2[1]*wv2+E0[1])-2.828427124746191*B1[1]*wv3; 
  alpha[2] = 2.828427124746191*(B2[2]*wv2+E0[2])-2.828427124746191*B1[2]*wv3; 
  alpha[4] = 0.8164965809277261*B2[0]*dv2; 
  alpha[5] = -0.8164965809277261*B1[0]*dv3; 
  alpha[6] = 2.828427124746191*(B2[3]*wv2+E0[3])-2.828427124746191*B1[3]*wv3; 
  alpha[9] = 0.8164965809277261*B2[1]*dv2; 
  alpha[10] = 0.8164965809277261*B2[2]*dv2; 
  alpha[12] = -0.8164965809277261*B1[1]*dv3; 
  alpha[13] = -0.8164965809277261*B1[2]*dv3; 
  alpha[16] = 2.828427124746191*(B2[4]*wv2+E0[4])-2.828427124746191*B1[4]*wv3; 
  alpha[17] = 2.828427124746191*(B2[5]*wv2+E0[5])-2.828427124746191*B1[5]*wv3; 
  const double amid = (-0.1976423537605236*alpha[17])-0.1976423537605236*alpha[16]+0.1767766952966368*alpha[0]; 
  Ghat[0] = (-1.118033988749895*fjump[18])+alpha[0]*(0.1976423537605236*favg[18]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.0883883476483184*(alpha[17]*favg[17]+alpha[16]*favg[16])+alpha[5]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[13]*favg[13]+alpha[12]*favg[12])+alpha[4]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])+0.0883883476483184*(alpha[10]*favg[10]+alpha[9]*favg[9])+alpha[2]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])+alpha[1]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])+0.0883883476483184*alpha[6]*favg[6]-0.8660254037844386*fjump[3]-0.5*fjump[0]; 
  Ghat[1] = alpha[1]*(0.1976423537605236*favg[18]+0.07905694150420944*favg[16]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[7]+0.07905694150420944*favg[1])*alpha[16]+alpha[12]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[5]*favg[12]+alpha[9]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])+0.0883883476483184*alpha[4]*favg[9]+alpha[6]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])-0.8660254037844386*fjump[7]+alpha[0]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])+0.0883883476483184*alpha[2]*favg[6]-0.5*fjump[1]; 
  Ghat[2] = alpha[2]*(0.1976423537605236*favg[18]+0.07905694150420944*favg[17]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[8]+0.07905694150420944*favg[2])*alpha[17]+alpha[13]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[5]*favg[13]+alpha[10]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])+0.0883883476483184*alpha[4]*favg[10]-0.8660254037844386*fjump[8]+alpha[0]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])+alpha[6]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])+0.0883883476483184*alpha[1]*favg[6]-0.5*fjump[2]; 
  Ghat[4] = alpha[4]*(0.07905694150420944*favg[19]+0.1976423537605236*favg[18]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.0883883476483184*alpha[5]*favg[15]-0.8660254037844386*fjump[11]+alpha[0]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])+0.0883883476483184*alpha[2]*favg[10]+(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])*alpha[10]+0.0883883476483184*alpha[1]*favg[9]+(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])*alpha[9]-0.5*fjump[4]; 
  Ghat[5] = alpha[5]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[18]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.0883883476483184*alpha[4]*favg[15]-0.8660254037844386*fjump[14]+alpha[0]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[2]*favg[13]+(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])*alpha[13]+0.0883883476483184*alpha[1]*favg[12]+(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])*alpha[12]-0.5*fjump[5]; 
  Ghat[6] = alpha[6]*(0.1976423537605236*favg[18]+0.07905694150420944*(favg[17]+favg[16])+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.07905694150420944*favg[6]*(alpha[17]+alpha[16])+0.0883883476483184*(alpha[12]*favg[13]+favg[12]*alpha[13]+alpha[9]*favg[10]+favg[9]*alpha[10])+alpha[1]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2])+alpha[2]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1])-0.5*fjump[6]+0.0883883476483184*alpha[0]*favg[6]; 
  Ghat[9] = alpha[9]*(0.07905694150420944*favg[19]+0.1976423537605236*favg[18]+0.07905694150420944*favg[16]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.07905694150420944*favg[9]*alpha[16]+0.0883883476483184*alpha[12]*favg[15]+alpha[1]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])+0.0883883476483184*(alpha[6]*favg[10]+favg[6]*alpha[10])-0.5*fjump[9]+0.0883883476483184*alpha[0]*favg[9]+alpha[4]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1]); 
  Ghat[10] = alpha[10]*(0.07905694150420944*favg[19]+0.1976423537605236*favg[18]+0.07905694150420944*favg[17]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.07905694150420944*favg[10]*alpha[17]+0.0883883476483184*alpha[13]*favg[15]+alpha[2]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4])-0.5*fjump[10]+0.0883883476483184*(alpha[0]*favg[10]+alpha[6]*favg[9]+favg[6]*alpha[9])+alpha[4]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2]); 
  Ghat[12] = alpha[12]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[18]+0.07905694150420944*favg[16]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.07905694150420944*favg[12]*alpha[16]+0.0883883476483184*alpha[9]*favg[15]+alpha[1]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[6]*favg[13]+favg[6]*alpha[13])-0.5*fjump[12]+0.0883883476483184*alpha[0]*favg[12]+alpha[5]*(0.1530931089239486*favg[7]+0.0883883476483184*favg[1]); 
  Ghat[13] = alpha[13]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[18]+0.07905694150420944*favg[17]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])+0.07905694150420944*favg[13]*alpha[17]+0.0883883476483184*alpha[10]*favg[15]+alpha[2]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])-0.5*fjump[13]+0.0883883476483184*(alpha[0]*favg[13]+alpha[6]*favg[12]+favg[6]*alpha[12])+alpha[5]*(0.1530931089239486*favg[8]+0.0883883476483184*favg[2]); 
  Ghat[15] = (-0.5*fjump[15])+0.0883883476483184*alpha[0]*favg[15]+alpha[4]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[10]*favg[13]+favg[10]*alpha[13]+alpha[9]*favg[12]+favg[9]*alpha[12])+alpha[5]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[4]); 
  Ghat[16] = alpha[16]*(0.1976423537605236*favg[18]+0.05646924393157818*favg[16]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])-0.5*fjump[16]+0.0883883476483184*alpha[0]*favg[16]+0.07905694150420944*(alpha[12]*favg[12]+alpha[9]*favg[9])+alpha[1]*(0.1369306393762915*favg[7]+0.07905694150420944*favg[1])+0.07905694150420944*alpha[6]*favg[6]; 
  Ghat[17] = alpha[17]*(0.1976423537605236*favg[18]+0.05646924393157818*favg[17]+0.1530931089239486*favg[3]+0.0883883476483184*favg[0])-0.5*fjump[17]+0.0883883476483184*alpha[0]*favg[17]+0.07905694150420944*(alpha[13]*favg[13]+alpha[10]*favg[10])+alpha[2]*(0.1369306393762915*favg[8]+0.07905694150420944*favg[2])+0.07905694150420944*alpha[6]*favg[6]; 
  Ghat[19] = (-0.5*fjump[19])+0.0883883476483184*alpha[0]*favg[19]+alpha[4]*(0.1369306393762915*favg[11]+0.07905694150420944*favg[4])+0.07905694150420944*(alpha[10]*favg[10]+alpha[9]*favg[9]); 
  Ghat[20] = (-0.5*fjump[20])+0.0883883476483184*alpha[0]*favg[20]+alpha[5]*(0.1369306393762915*favg[14]+0.07905694150420944*favg[5])+0.07905694150420944*(alpha[13]*favg[13]+alpha[12]*favg[12]); 

  outr[0] += 0.5*Ghat[0]*dv10r; 
  outr[1] += 0.5*Ghat[1]*dv10r; 
  outr[2] += 0.5*Ghat[2]*dv10r; 
  outr[3] += -0.8660254037844386*Ghat[0]*dv10r; 
  outr[4] += 0.5*Ghat[4]*dv10r; 
  outr[5] += 0.5*Ghat[5]*dv10r; 
  outr[6] += 0.5*Ghat[6]*dv10r; 
  outr[7] += -0.8660254037844386*Ghat[1]*dv10r; 
  outr[8] += -0.8660254037844386*Ghat[2]*dv10r; 
  outr[9] += 0.5*Ghat[9]*dv10r; 
  outr[10] += 0.5*Ghat[10]*dv10r; 
  outr[11] += -0.8660254037844386*Ghat[4]*dv10r; 
  outr[12] += 0.5*Ghat[12]*dv10r; 
  outr[13] += 0.5*Ghat[13]*dv10r; 
  outr[14] += -0.8660254037844386*Ghat[5]*dv10r; 
  outr[15] += 0.5*Ghat[15]*dv10r; 
  outr[16] += 0.5*Ghat[16]*dv10r; 
  outr[17] += 0.5*Ghat[17]*dv10r; 
  outr[18] += 1.118033988749895*Ghat[0]*dv10r; 
  outr[19] += 0.5*Ghat[19]*dv10r; 
  outr[20] += 0.5*Ghat[20]*dv10r; 

  outl[0] += -0.5*Ghat[0]*dv10l; 
  outl[1] += -0.5*Ghat[1]*dv10l; 
  outl[2] += -0.5*Ghat[2]*dv10l; 
  outl[3] += -0.8660254037844386*Ghat[0]*dv10l; 
  outl[4] += -0.5*Ghat[4]*dv10l; 
  outl[5] += -0.5*Ghat[5]*dv10l; 
  outl[6] += -0.5*Ghat[6]*dv10l; 
  outl[7] += -0.8660254037844386*Ghat[1]*dv10l; 
  outl[8] += -0.8660254037844386*Ghat[2]*dv10l; 
  outl[9] += -0.5*Ghat[9]*dv10l; 
  outl[10] += -0.5*Ghat[10]*dv10l; 
  outl[11] += -0.8660254037844386*Ghat[4]*dv10l; 
  outl[12] += -0.5*Ghat[12]*dv10l; 
  outl[13] += -0.5*Ghat[13]*dv10l; 
  outl[14] += -0.8660254037844386*Ghat[5]*dv10l; 
  outl[15] += -0.5*Ghat[15]*dv10l; 
  outl[16] += -0.5*Ghat[16]*dv10l; 
  outl[17] += -0.5*Ghat[17]*dv10l; 
  outl[18] += -1.118033988749895*Ghat[0]*dv10l; 
  outl[19] += -0.5*Ghat[19]*dv10l; 
  outl[20] += -0.5*Ghat[20]*dv10l; 
return std::abs(amid); 
} 
double VlasovSurfElcMag2x3vMax_VY_P2(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double amax, const double *EM, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w: Cell-center coordinates. dxv[NDIM]: Cell spacing. amax: amax in global lax flux. E: EM field. fl/fr: Distribution function in left/right cells 
// outl/outr: output distribution function in left/right cells 
// returns abs(amid) for use in determining amax in cfl and global lax flux 
  double dv11l = 2/dxvl[3]; 
  double dv11r = 2/dxvr[3]; 
  const double *E1 = &EM[6]; 

  const double dv1 = dxvr[2], wv1 = wr[2]; 
  const double dv2 = dxvr[3], wv2 = wr[3]; 
  const double dv3 = dxvr[4], wv3 = wr[4]; 

  const double *B0 = &EM[18]; 
  const double *B1 = &EM[24]; 
  const double *B2 = &EM[30]; 

  double Ghat[21]; 

  double alpha[21]; 

  double favg[21]; 

  favg[0] = 1*fr[0]+fl[0]; 
  favg[1] = 1*fr[1]+fl[1]; 
  favg[2] = 1*fr[2]+fl[2]; 
  favg[3] = 1*fr[3]+fl[3]; 
  favg[4] = -1*fr[4]+fl[4]; 
  favg[5] = 1*fr[5]+fl[5]; 
  favg[6] = 1*fr[6]+fl[6]; 
  favg[7] = 1*fr[7]+fl[7]; 
  favg[8] = 1*fr[8]+fl[8]; 
  favg[9] = -1*fr[9]+fl[9]; 
  favg[10] = -1*fr[10]+fl[10]; 
  favg[11] = -1*fr[11]+fl[11]; 
  favg[12] = 1*fr[12]+fl[12]; 
  favg[13] = 1*fr[13]+fl[13]; 
  favg[14] = 1*fr[14]+fl[14]; 
  favg[15] = -1*fr[15]+fl[15]; 
  favg[16] = 1*fr[16]+fl[16]; 
  favg[17] = 1*fr[17]+fl[17]; 
  favg[18] = 1*fr[18]+fl[18]; 
  favg[19] = 1*fr[19]+fl[19]; 
  favg[20] = 1*fr[20]+fl[20]; 
  double fjump[21]; 

  fjump[0] = amax*(1*fr[0]-fl[0]); 
  fjump[1] = amax*(1*fr[1]-fl[1]); 
  fjump[2] = amax*(1*fr[2]-fl[2]); 
  fjump[3] = amax*(1*fr[3]-fl[3]); 
  fjump[4] = amax*(-1*fr[4]-fl[4]); 
  fjump[5] = amax*(1*fr[5]-fl[5]); 
  fjump[6] = amax*(1*fr[6]-fl[6]); 
  fjump[7] = amax*(1*fr[7]-fl[7]); 
  fjump[8] = amax*(1*fr[8]-fl[8]); 
  fjump[9] = amax*(-1*fr[9]-fl[9]); 
  fjump[10] = amax*(-1*fr[10]-fl[10]); 
  fjump[11] = amax*(-1*fr[11]-fl[11]); 
  fjump[12] = amax*(1*fr[12]-fl[12]); 
  fjump[13] = amax*(1*fr[13]-fl[13]); 
  fjump[14] = amax*(1*fr[14]-fl[14]); 
  fjump[15] = amax*(-1*fr[15]-fl[15]); 
  fjump[16] = amax*(1*fr[16]-fl[16]); 
  fjump[17] = amax*(1*fr[17]-fl[17]); 
  fjump[18] = amax*(1*fr[18]-fl[18]); 
  fjump[19] = amax*(1*fr[19]-fl[19]); 
  fjump[20] = amax*(1*fr[20]-fl[20]); 
  alpha[0] = 2.828427124746191*B0[0]*wv3-2.828427124746191*B2[0]*wv1+2.828427124746191*E1[0]; 
  alpha[1] = 2.828427124746191*B0[1]*wv3-2.828427124746191*B2[1]*wv1+2.828427124746191*E1[1]; 
  alpha[2] = 2.828427124746191*B0[2]*wv3-2.828427124746191*B2[2]*wv1+2.828427124746191*E1[2]; 
  alpha[3] = -0.8164965809277261*B2[0]*dv1; 
  alpha[5] = 0.8164965809277261*B0[0]*dv3; 
  alpha[6] = 2.828427124746191*B0[3]*wv3-2.828427124746191*B2[3]*wv1+2.828427124746191*E1[3]; 
  alpha[7] = -0.8164965809277261*B2[1]*dv1; 
  alpha[8] = -0.8164965809277261*B2[2]*dv1; 
  alpha[12] = 0.8164965809277261*B0[1]*dv3; 
  alpha[13] = 0.8164965809277261*B0[2]*dv3; 
  alpha[16] = 2.828427124746191*B0[4]*wv3-2.828427124746191*B2[4]*wv1+2.828427124746191*E1[4]; 
  alpha[17] = 2.828427124746191*B0[5]*wv3-2.828427124746191*B2[5]*wv1+2.828427124746191*E1[5]; 
  const double amid = (-0.1976423537605236*alpha[17])-0.1976423537605236*alpha[16]+0.1767766952966368*alpha[0]; 
  Ghat[0] = (-1.118033988749895*fjump[19])+alpha[0]*(0.1976423537605236*favg[19]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.0883883476483184*(alpha[17]*favg[17]+alpha[16]*favg[16])+alpha[5]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[13]*favg[13]+alpha[12]*favg[12])+alpha[3]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])+alpha[2]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])+alpha[1]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[8]*favg[8]+alpha[7]*favg[7]+alpha[6]*favg[6])-0.8660254037844386*fjump[4]-0.5*fjump[0]; 
  Ghat[1] = alpha[1]*(0.1976423537605236*favg[19]+0.07905694150420944*favg[16]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[9]+0.07905694150420944*favg[1])*alpha[16]+alpha[12]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[5]*favg[12]+alpha[7]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])+alpha[6]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])-0.8660254037844386*fjump[9]+alpha[0]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[3]*favg[7]+alpha[2]*favg[6])-0.5*fjump[1]; 
  Ghat[2] = alpha[2]*(0.1976423537605236*favg[19]+0.07905694150420944*favg[17]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[10]+0.07905694150420944*favg[2])*alpha[17]+alpha[13]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[5]*favg[13]+alpha[8]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])-0.8660254037844386*fjump[10]+alpha[0]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])+alpha[6]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[3]*favg[8]+alpha[1]*favg[6])-0.5*fjump[2]; 
  Ghat[3] = alpha[3]*(0.1976423537605236*favg[19]+0.07905694150420944*favg[18]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.0883883476483184*alpha[5]*favg[14]-0.8660254037844386*fjump[11]+alpha[0]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])+alpha[8]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])+alpha[7]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[2]*favg[8]+alpha[1]*favg[7])-0.5*fjump[3]; 
  Ghat[5] = alpha[5]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[19]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])-0.8660254037844386*fjump[15]+alpha[0]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[3]*favg[14]+alpha[2]*favg[13])+(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])*alpha[13]+0.0883883476483184*alpha[1]*favg[12]+(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])*alpha[12]-0.5*fjump[5]; 
  Ghat[6] = alpha[6]*(0.1976423537605236*favg[19]+0.07905694150420944*(favg[17]+favg[16])+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.07905694150420944*favg[6]*(alpha[17]+alpha[16])+0.0883883476483184*(alpha[12]*favg[13]+favg[12]*alpha[13])+alpha[1]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])+alpha[2]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[7]*favg[8]+favg[7]*alpha[8])-0.5*fjump[6]+0.0883883476483184*alpha[0]*favg[6]; 
  Ghat[7] = alpha[7]*(0.1976423537605236*favg[19]+0.07905694150420944*(favg[18]+favg[16])+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.07905694150420944*favg[7]*alpha[16]+0.0883883476483184*alpha[12]*favg[14]+alpha[1]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])+alpha[3]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[6]*favg[8]+favg[6]*alpha[8])-0.5*fjump[7]+0.0883883476483184*alpha[0]*favg[7]; 
  Ghat[8] = alpha[8]*(0.1976423537605236*favg[19]+0.07905694150420944*(favg[18]+favg[17])+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.07905694150420944*favg[8]*alpha[17]+0.0883883476483184*alpha[13]*favg[14]+alpha[2]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3])+alpha[3]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2])-0.5*fjump[8]+0.0883883476483184*(alpha[0]*favg[8]+alpha[6]*favg[7]+favg[6]*alpha[7]); 
  Ghat[12] = alpha[12]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[19]+0.07905694150420944*favg[16]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.07905694150420944*favg[12]*alpha[16]+alpha[1]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*(alpha[7]*favg[14]+alpha[6]*favg[13]+favg[6]*alpha[13])-0.5*fjump[12]+0.0883883476483184*alpha[0]*favg[12]+alpha[5]*(0.1530931089239486*favg[9]+0.0883883476483184*favg[1]); 
  Ghat[13] = alpha[13]*(0.07905694150420944*favg[20]+0.1976423537605236*favg[19]+0.07905694150420944*favg[17]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])+0.07905694150420944*favg[13]*alpha[17]+alpha[2]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])+0.0883883476483184*alpha[8]*favg[14]-0.5*fjump[13]+0.0883883476483184*(alpha[0]*favg[13]+alpha[6]*favg[12]+favg[6]*alpha[12])+alpha[5]*(0.1530931089239486*favg[10]+0.0883883476483184*favg[2]); 
  Ghat[14] = alpha[3]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[5])-0.5*fjump[14]+0.0883883476483184*(alpha[0]*favg[14]+alpha[8]*favg[13]+favg[8]*alpha[13]+alpha[7]*favg[12]+favg[7]*alpha[12])+alpha[5]*(0.1530931089239486*favg[11]+0.0883883476483184*favg[3]); 
  Ghat[16] = alpha[16]*(0.1976423537605236*favg[19]+0.05646924393157818*favg[16]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])-0.5*fjump[16]+0.0883883476483184*alpha[0]*favg[16]+0.07905694150420944*alpha[12]*favg[12]+alpha[1]*(0.1369306393762915*favg[9]+0.07905694150420944*favg[1])+0.07905694150420944*(alpha[7]*favg[7]+alpha[6]*favg[6]); 
  Ghat[17] = alpha[17]*(0.1976423537605236*favg[19]+0.05646924393157818*favg[17]+0.1530931089239486*favg[4]+0.0883883476483184*favg[0])-0.5*fjump[17]+0.0883883476483184*alpha[0]*favg[17]+0.07905694150420944*alpha[13]*favg[13]+alpha[2]*(0.1369306393762915*favg[10]+0.07905694150420944*favg[2])+0.07905694150420944*(alpha[8]*favg[8]+alpha[6]*favg[6]); 
  Ghat[18] = (-0.5*fjump[18])+0.0883883476483184*alpha[0]*favg[18]+alpha[3]*(0.1369306393762915*favg[11]+0.07905694150420944*favg[3])+0.07905694150420944*(alpha[8]*favg[8]+alpha[7]*favg[7]); 
  Ghat[20] = (-0.5*fjump[20])+0.0883883476483184*alpha[0]*favg[20]+alpha[5]*(0.1369306393762915*favg[15]+0.07905694150420944*favg[5])+0.07905694150420944*(alpha[13]*favg[13]+alpha[12]*favg[12]); 

  outr[0] += 0.5*Ghat[0]*dv11r; 
  outr[1] += 0.5*Ghat[1]*dv11r; 
  outr[2] += 0.5*Ghat[2]*dv11r; 
  outr[3] += 0.5*Ghat[3]*dv11r; 
  outr[4] += -0.8660254037844386*Ghat[0]*dv11r; 
  outr[5] += 0.5*Ghat[5]*dv11r; 
  outr[6] += 0.5*Ghat[6]*dv11r; 
  outr[7] += 0.5*Ghat[7]*dv11r; 
  outr[8] += 0.5*Ghat[8]*dv11r; 
  outr[9] += -0.8660254037844386*Ghat[1]*dv11r; 
  outr[10] += -0.8660254037844386*Ghat[2]*dv11r; 
  outr[11] += -0.8660254037844386*Ghat[3]*dv11r; 
  outr[12] += 0.5*Ghat[12]*dv11r; 
  outr[13] += 0.5*Ghat[13]*dv11r; 
  outr[14] += 0.5*Ghat[14]*dv11r; 
  outr[15] += -0.8660254037844386*Ghat[5]*dv11r; 
  outr[16] += 0.5*Ghat[16]*dv11r; 
  outr[17] += 0.5*Ghat[17]*dv11r; 
  outr[18] += 0.5*Ghat[18]*dv11r; 
  outr[19] += 1.118033988749895*Ghat[0]*dv11r; 
  outr[20] += 0.5*Ghat[20]*dv11r; 

  outl[0] += -0.5*Ghat[0]*dv11l; 
  outl[1] += -0.5*Ghat[1]*dv11l; 
  outl[2] += -0.5*Ghat[2]*dv11l; 
  outl[3] += -0.5*Ghat[3]*dv11l; 
  outl[4] += -0.8660254037844386*Ghat[0]*dv11l; 
  outl[5] += -0.5*Ghat[5]*dv11l; 
  outl[6] += -0.5*Ghat[6]*dv11l; 
  outl[7] += -0.5*Ghat[7]*dv11l; 
  outl[8] += -0.5*Ghat[8]*dv11l; 
  outl[9] += -0.8660254037844386*Ghat[1]*dv11l; 
  outl[10] += -0.8660254037844386*Ghat[2]*dv11l; 
  outl[11] += -0.8660254037844386*Ghat[3]*dv11l; 
  outl[12] += -0.5*Ghat[12]*dv11l; 
  outl[13] += -0.5*Ghat[13]*dv11l; 
  outl[14] += -0.5*Ghat[14]*dv11l; 
  outl[15] += -0.8660254037844386*Ghat[5]*dv11l; 
  outl[16] += -0.5*Ghat[16]*dv11l; 
  outl[17] += -0.5*Ghat[17]*dv11l; 
  outl[18] += -0.5*Ghat[18]*dv11l; 
  outl[19] += -1.118033988749895*Ghat[0]*dv11l; 
  outl[20] += -0.5*Ghat[20]*dv11l; 
return std::abs(amid); 
} 
double VlasovSurfElcMag2x3vMax_VZ_P2(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double amax, const double *EM, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w: Cell-center coordinates. dxv[NDIM]: Cell spacing. amax: amax in global lax flux. E: EM field. fl/fr: Distribution function in left/right cells 
// outl/outr: output distribution function in left/right cells 
// returns abs(amid) for use in determining amax in cfl and global lax flux 
  double dv12l = 2/dxvl[4]; 
  double dv12r = 2/dxvr[4]; 
  const double *E2 = &EM[12]; 

  const double dv1 = dxvr[2], wv1 = wr[2]; 
  const double dv2 = dxvr[3], wv2 = wr[3]; 
  const double dv3 = dxvr[4], wv3 = wr[4]; 

  const double *B0 = &EM[18]; 
  const double *B1 = &EM[24]; 
  const double *B2 = &EM[30]; 

  double Ghat[21]; 

  double alpha[21]; 

  double favg[21]; 

  favg[0] = 1*fr[0]+fl[0]; 
  favg[1] = 1*fr[1]+fl[1]; 
  favg[2] = 1*fr[2]+fl[2]; 
  favg[3] = 1*fr[3]+fl[3]; 
  favg[4] = 1*fr[4]+fl[4]; 
  favg[5] = -1*fr[5]+fl[5]; 
  favg[6] = 1*fr[6]+fl[6]; 
  favg[7] = 1*fr[7]+fl[7]; 
  favg[8] = 1*fr[8]+fl[8]; 
  favg[9] = 1*fr[9]+fl[9]; 
  favg[10] = 1*fr[10]+fl[10]; 
  favg[11] = 1*fr[11]+fl[11]; 
  favg[12] = -1*fr[12]+fl[12]; 
  favg[13] = -1*fr[13]+fl[13]; 
  favg[14] = -1*fr[14]+fl[14]; 
  favg[15] = -1*fr[15]+fl[15]; 
  favg[16] = 1*fr[16]+fl[16]; 
  favg[17] = 1*fr[17]+fl[17]; 
  favg[18] = 1*fr[18]+fl[18]; 
  favg[19] = 1*fr[19]+fl[19]; 
  favg[20] = 1*fr[20]+fl[20]; 
  double fjump[21]; 

  fjump[0] = amax*(1*fr[0]-fl[0]); 
  fjump[1] = amax*(1*fr[1]-fl[1]); 
  fjump[2] = amax*(1*fr[2]-fl[2]); 
  fjump[3] = amax*(1*fr[3]-fl[3]); 
  fjump[4] = amax*(1*fr[4]-fl[4]); 
  fjump[5] = amax*(-1*fr[5]-fl[5]); 
  fjump[6] = amax*(1*fr[6]-fl[6]); 
  fjump[7] = amax*(1*fr[7]-fl[7]); 
  fjump[8] = amax*(1*fr[8]-fl[8]); 
  fjump[9] = amax*(1*fr[9]-fl[9]); 
  fjump[10] = amax*(1*fr[10]-fl[10]); 
  fjump[11] = amax*(1*fr[11]-fl[11]); 
  fjump[12] = amax*(-1*fr[12]-fl[12]); 
  fjump[13] = amax*(-1*fr[13]-fl[13]); 
  fjump[14] = amax*(-1*fr[14]-fl[14]); 
  fjump[15] = amax*(-1*fr[15]-fl[15]); 
  fjump[16] = amax*(1*fr[16]-fl[16]); 
  fjump[17] = amax*(1*fr[17]-fl[17]); 
  fjump[18] = amax*(1*fr[18]-fl[18]); 
  fjump[19] = amax*(1*fr[19]-fl[19]); 
  fjump[20] = amax*(1*fr[20]-fl[20]); 
  alpha[0] = 2.828427124746191*(B1[0]*wv1+E2[0])-2.828427124746191*B0[0]*wv2; 
  alpha[1] = 2.828427124746191*(B1[1]*wv1+E2[1])-2.828427124746191*B0[1]*wv2; 
  alpha[2] = 2.828427124746191*(B1[2]*wv1+E2[2])-2.828427124746191*B0[2]*wv2; 
  alpha[3] = 0.8164965809277261*B1[0]*dv1; 
  alpha[4] = -0.8164965809277261*B0[0]*dv2; 
  alpha[6] = 2.828427124746191*(B1[3]*wv1+E2[3])-2.828427124746191*B0[3]*wv2; 
  alpha[7] = 0.8164965809277261*B1[1]*dv1; 
  alpha[8] = 0.8164965809277261*B1[2]*dv1; 
  alpha[9] = -0.8164965809277261*B0[1]*dv2; 
  alpha[10] = -0.8164965809277261*B0[2]*dv2; 
  alpha[16] = 2.828427124746191*(B1[4]*wv1+E2[4])-2.828427124746191*B0[4]*wv2; 
  alpha[17] = 2.828427124746191*(B1[5]*wv1+E2[5])-2.828427124746191*B0[5]*wv2; 
  const double amid = (-0.1976423537605236*alpha[17])-0.1976423537605236*alpha[16]+0.1767766952966368*alpha[0]; 
  Ghat[0] = (-1.118033988749895*fjump[20])+alpha[0]*(0.1976423537605236*favg[20]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.0883883476483184*(alpha[17]*favg[17]+alpha[16]*favg[16])+alpha[4]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[3]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])+alpha[2]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+alpha[1]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[10]*favg[10]+alpha[9]*favg[9]+alpha[8]*favg[8]+alpha[7]*favg[7]+alpha[6]*favg[6])-0.8660254037844386*fjump[5]-0.5*fjump[0]; 
  Ghat[1] = alpha[1]*(0.1976423537605236*favg[20]+0.07905694150420944*favg[16]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[12]+0.07905694150420944*favg[1])*alpha[16]+alpha[9]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[7]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])+alpha[6]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])-0.8660254037844386*fjump[12]+alpha[0]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[4]*favg[9]+alpha[3]*favg[7]+alpha[2]*favg[6])-0.5*fjump[1]; 
  Ghat[2] = alpha[2]*(0.1976423537605236*favg[20]+0.07905694150420944*favg[17]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+(0.1369306393762915*favg[13]+0.07905694150420944*favg[2])*alpha[17]+alpha[10]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[8]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])-0.8660254037844386*fjump[13]+alpha[0]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+alpha[6]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[4]*favg[10]+alpha[3]*favg[8]+alpha[1]*favg[6])-0.5*fjump[2]; 
  Ghat[3] = alpha[3]*(0.1976423537605236*favg[20]+0.07905694150420944*favg[18]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])-0.8660254037844386*fjump[14]+alpha[0]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])+alpha[8]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+alpha[7]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[4]*favg[11]+alpha[2]*favg[8]+alpha[1]*favg[7])-0.5*fjump[3]; 
  Ghat[4] = alpha[4]*(0.1976423537605236*favg[20]+0.07905694150420944*favg[19]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])-0.8660254037844386*fjump[15]+alpha[0]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[10]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+alpha[9]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[3]*favg[11]+alpha[2]*favg[10]+alpha[1]*favg[9])-0.5*fjump[4]; 
  Ghat[6] = alpha[6]*(0.1976423537605236*favg[20]+0.07905694150420944*(favg[17]+favg[16])+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.07905694150420944*favg[6]*(alpha[17]+alpha[16])+alpha[1]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+alpha[2]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[9]*favg[10]+favg[9]*alpha[10]+alpha[7]*favg[8]+favg[7]*alpha[8])-0.5*fjump[6]+0.0883883476483184*alpha[0]*favg[6]; 
  Ghat[7] = alpha[7]*(0.1976423537605236*favg[20]+0.07905694150420944*(favg[18]+favg[16])+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.07905694150420944*favg[7]*alpha[16]+alpha[1]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])+alpha[3]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[9]*favg[11]+alpha[6]*favg[8]+favg[6]*alpha[8])-0.5*fjump[7]+0.0883883476483184*alpha[0]*favg[7]; 
  Ghat[8] = alpha[8]*(0.1976423537605236*favg[20]+0.07905694150420944*(favg[18]+favg[17])+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.07905694150420944*favg[8]*alpha[17]+alpha[2]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])+alpha[3]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+0.0883883476483184*alpha[10]*favg[11]-0.5*fjump[8]+0.0883883476483184*(alpha[0]*favg[8]+alpha[6]*favg[7]+favg[6]*alpha[7]); 
  Ghat[9] = alpha[9]*(0.1976423537605236*favg[20]+0.07905694150420944*(favg[19]+favg[16])+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.07905694150420944*favg[9]*alpha[16]+alpha[1]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[4]*(0.1530931089239486*favg[12]+0.0883883476483184*favg[1])+0.0883883476483184*(alpha[7]*favg[11]+alpha[6]*favg[10]+favg[6]*alpha[10])-0.5*fjump[9]+0.0883883476483184*alpha[0]*favg[9]; 
  Ghat[10] = alpha[10]*(0.1976423537605236*favg[20]+0.07905694150420944*(favg[19]+favg[17])+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])+0.07905694150420944*favg[10]*alpha[17]+alpha[2]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[4]*(0.1530931089239486*favg[13]+0.0883883476483184*favg[2])+0.0883883476483184*alpha[8]*favg[11]-0.5*fjump[10]+0.0883883476483184*(alpha[0]*favg[10]+alpha[6]*favg[9]+favg[6]*alpha[9]); 
  Ghat[11] = alpha[3]*(0.1530931089239486*favg[15]+0.0883883476483184*favg[4])+alpha[4]*(0.1530931089239486*favg[14]+0.0883883476483184*favg[3])-0.5*fjump[11]+0.0883883476483184*(alpha[0]*favg[11]+alpha[8]*favg[10]+favg[8]*alpha[10]+alpha[7]*favg[9]+favg[7]*alpha[9]); 
  Ghat[16] = alpha[16]*(0.1976423537605236*favg[20]+0.05646924393157818*favg[16]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])-0.5*fjump[16]+0.0883883476483184*alpha[0]*favg[16]+alpha[1]*(0.1369306393762915*favg[12]+0.07905694150420944*favg[1])+0.07905694150420944*(alpha[9]*favg[9]+alpha[7]*favg[7]+alpha[6]*favg[6]); 
  Ghat[17] = alpha[17]*(0.1976423537605236*favg[20]+0.05646924393157818*favg[17]+0.1530931089239486*favg[5]+0.0883883476483184*favg[0])-0.5*fjump[17]+0.0883883476483184*alpha[0]*favg[17]+alpha[2]*(0.1369306393762915*favg[13]+0.07905694150420944*favg[2])+0.07905694150420944*(alpha[10]*favg[10]+alpha[8]*favg[8]+alpha[6]*favg[6]); 
  Ghat[18] = (-0.5*fjump[18])+0.0883883476483184*alpha[0]*favg[18]+alpha[3]*(0.1369306393762915*favg[14]+0.07905694150420944*favg[3])+0.07905694150420944*(alpha[8]*favg[8]+alpha[7]*favg[7]); 
  Ghat[19] = (-0.5*fjump[19])+0.0883883476483184*alpha[0]*favg[19]+alpha[4]*(0.1369306393762915*favg[15]+0.07905694150420944*favg[4])+0.07905694150420944*(alpha[10]*favg[10]+alpha[9]*favg[9]); 

  outr[0] += 0.5*Ghat[0]*dv12r; 
  outr[1] += 0.5*Ghat[1]*dv12r; 
  outr[2] += 0.5*Ghat[2]*dv12r; 
  outr[3] += 0.5*Ghat[3]*dv12r; 
  outr[4] += 0.5*Ghat[4]*dv12r; 
  outr[5] += -0.8660254037844386*Ghat[0]*dv12r; 
  outr[6] += 0.5*Ghat[6]*dv12r; 
  outr[7] += 0.5*Ghat[7]*dv12r; 
  outr[8] += 0.5*Ghat[8]*dv12r; 
  outr[9] += 0.5*Ghat[9]*dv12r; 
  outr[10] += 0.5*Ghat[10]*dv12r; 
  outr[11] += 0.5*Ghat[11]*dv12r; 
  outr[12] += -0.8660254037844386*Ghat[1]*dv12r; 
  outr[13] += -0.8660254037844386*Ghat[2]*dv12r; 
  outr[14] += -0.8660254037844386*Ghat[3]*dv12r; 
  outr[15] += -0.8660254037844386*Ghat[4]*dv12r; 
  outr[16] += 0.5*Ghat[16]*dv12r; 
  outr[17] += 0.5*Ghat[17]*dv12r; 
  outr[18] += 0.5*Ghat[18]*dv12r; 
  outr[19] += 0.5*Ghat[19]*dv12r; 
  outr[20] += 1.118033988749895*Ghat[0]*dv12r; 

  outl[0] += -0.5*Ghat[0]*dv12l; 
  outl[1] += -0.5*Ghat[1]*dv12l; 
  outl[2] += -0.5*Ghat[2]*dv12l; 
  outl[3] += -0.5*Ghat[3]*dv12l; 
  outl[4] += -0.5*Ghat[4]*dv12l; 
  outl[5] += -0.8660254037844386*Ghat[0]*dv12l; 
  outl[6] += -0.5*Ghat[6]*dv12l; 
  outl[7] += -0.5*Ghat[7]*dv12l; 
  outl[8] += -0.5*Ghat[8]*dv12l; 
  outl[9] += -0.5*Ghat[9]*dv12l; 
  outl[10] += -0.5*Ghat[10]*dv12l; 
  outl[11] += -0.5*Ghat[11]*dv12l; 
  outl[12] += -0.8660254037844386*Ghat[1]*dv12l; 
  outl[13] += -0.8660254037844386*Ghat[2]*dv12l; 
  outl[14] += -0.8660254037844386*Ghat[3]*dv12l; 
  outl[15] += -0.8660254037844386*Ghat[4]*dv12l; 
  outl[16] += -0.5*Ghat[16]*dv12l; 
  outl[17] += -0.5*Ghat[17]*dv12l; 
  outl[18] += -0.5*Ghat[18]*dv12l; 
  outl[19] += -0.5*Ghat[19]*dv12l; 
  outl[20] += -1.118033988749895*Ghat[0]*dv12l; 
return std::abs(amid); 
} 