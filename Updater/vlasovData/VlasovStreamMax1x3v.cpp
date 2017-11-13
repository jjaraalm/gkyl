void VlasovVolStream1x3vMaxP1(const double *w, const double *dxv, const double *f, double *out) 
{ 
  register double dv0dx0 = dxv[1]/dxv[0]; 
  register double w0dx0 = w[1]/dxv[0]; 
  out[1] += 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
} 
void VlasovVolStream1x3vMaxP2(const double *w, const double *dxv, const double *f, double *out) 
{ 
  register double dv0dx0 = dxv[1]/dxv[0]; 
  register double w0dx0 = w[1]/dxv[0]; 
  out[1] += 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  out[5] += 3.464101615137754*f[2]*w0dx0+0.8944271909999159*f[12]*dv0dx0+f[0]*dv0dx0; 
  out[6] += 3.464101615137754*f[3]*w0dx0+f[7]*dv0dx0; 
  out[8] += 3.464101615137754*f[4]*w0dx0+f[9]*dv0dx0; 
  out[11] += 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[5]*dv0dx0; 
} 
void VlasovVolStream1x3vMaxP3(const double *w, const double *dxv, const double *f, double *out) 
{ 
  register double dv0dx0 = dxv[1]/dxv[0]; 
  register double w0dx0 = w[1]/dxv[0]; 
  out[1] += 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  out[5] += 3.464101615137754*f[2]*w0dx0+0.8944271909999159*f[12]*dv0dx0+f[0]*dv0dx0; 
  out[6] += 3.464101615137754*f[3]*w0dx0+f[7]*dv0dx0; 
  out[8] += 3.464101615137754*f[4]*w0dx0+f[9]*dv0dx0; 
  out[11] += 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[5]*dv0dx0; 
  out[15] += 3.464101615137754*f[7]*w0dx0+0.8944271909999159*f[22]*dv0dx0+f[3]*dv0dx0; 
  out[16] += 3.464101615137754*f[9]*w0dx0+0.8944271909999159*f[26]*dv0dx0+f[4]*dv0dx0; 
  out[17] += 3.464101615137754*f[10]*w0dx0+f[18]*dv0dx0; 
  out[19] += 7.745966692414834*f[5]*w0dx0+2.0*f[20]*dv0dx0+2.23606797749979*f[1]*dv0dx0; 
  out[20] += 3.464101615137754*f[12]*w0dx0+0.8783100656536796*f[32]*dv0dx0+0.8944271909999159*f[2]*dv0dx0; 
  out[21] += 7.745966692414834*f[6]*w0dx0+2.23606797749979*f[15]*dv0dx0; 
  out[23] += 3.464101615137754*f[13]*w0dx0+f[24]*dv0dx0; 
  out[25] += 7.745966692414834*f[8]*w0dx0+2.23606797749979*f[16]*dv0dx0; 
  out[28] += 3.464101615137754*f[14]*w0dx0+f[29]*dv0dx0; 
  out[31] += 11.83215956619923*f[11]*w0dx0+5.291502622129181*f[0]*w0dx0+3.415650255319867*f[19]*dv0dx0+1.527525231651947*f[2]*dv0dx0; 
} 
void VlasovVolStream1x3vMaxP4(const double *w, const double *dxv, const double *f, double *out) 
{ 
  register double dv0dx0 = dxv[1]/dxv[0]; 
  register double w0dx0 = w[1]/dxv[0]; 
  out[1] += 3.464101615137754*f[0]*w0dx0+f[2]*dv0dx0; 
  out[5] += 3.464101615137754*f[2]*w0dx0+0.8944271909999159*f[12]*dv0dx0+f[0]*dv0dx0; 
  out[6] += 3.464101615137754*f[3]*w0dx0+f[7]*dv0dx0; 
  out[8] += 3.464101615137754*f[4]*w0dx0+f[9]*dv0dx0; 
  out[11] += 7.745966692414834*f[1]*w0dx0+2.23606797749979*f[5]*dv0dx0; 
  out[15] += 3.464101615137754*f[7]*w0dx0+0.8944271909999159*f[22]*dv0dx0+f[3]*dv0dx0; 
  out[16] += 3.464101615137754*f[9]*w0dx0+0.8944271909999159*f[26]*dv0dx0+f[4]*dv0dx0; 
  out[17] += 3.464101615137754*f[10]*w0dx0+f[18]*dv0dx0; 
  out[19] += 7.745966692414834*f[5]*w0dx0+2.0*f[20]*dv0dx0+2.23606797749979*f[1]*dv0dx0; 
  out[20] += 3.464101615137754*f[12]*w0dx0+0.8783100656536796*f[32]*dv0dx0+0.8944271909999159*f[2]*dv0dx0; 
  out[21] += 7.745966692414834*f[6]*w0dx0+2.23606797749979*f[15]*dv0dx0; 
  out[23] += 3.464101615137754*f[13]*w0dx0+f[24]*dv0dx0; 
  out[25] += 7.745966692414834*f[8]*w0dx0+2.23606797749979*f[16]*dv0dx0; 
  out[28] += 3.464101615137754*f[14]*w0dx0+f[29]*dv0dx0; 
  out[31] += 11.83215956619923*f[11]*w0dx0+5.291502622129181*f[0]*w0dx0+3.415650255319867*f[19]*dv0dx0+1.527525231651947*f[2]*dv0dx0; 
  out[35] += 3.464101615137754*f[18]*w0dx0+0.8944271909999159*f[42]*dv0dx0+f[10]*dv0dx0; 
  out[36] += 7.745966692414834*f[15]*w0dx0+2.0*f[37]*dv0dx0+2.23606797749979*f[6]*dv0dx0; 
  out[37] += 3.464101615137754*f[22]*w0dx0+0.8783100656536796*f[57]*dv0dx0+0.8944271909999159*f[7]*dv0dx0; 
  out[38] += 3.464101615137754*f[24]*w0dx0+0.8944271909999159*f[50]*dv0dx0+f[13]*dv0dx0; 
  out[39] += 7.745966692414834*f[16]*w0dx0+2.0*f[40]*dv0dx0+2.23606797749979*f[8]*dv0dx0; 
  out[40] += 3.464101615137754*f[26]*w0dx0+0.8783100656536796*f[61]*dv0dx0+0.8944271909999159*f[9]*dv0dx0; 
  out[41] += 7.745966692414834*f[17]*w0dx0+2.23606797749979*f[35]*dv0dx0; 
  out[43] += 3.464101615137754*f[27]*w0dx0+f[44]*dv0dx0; 
  out[45] += 3.464101615137754*f[29]*w0dx0+0.8944271909999159*f[52]*dv0dx0+f[14]*dv0dx0; 
  out[46] += 3.464101615137754*f[30]*w0dx0+f[47]*dv0dx0; 
  out[48] += 7.745966692414834*f[20]*w0dx0+1.963961012123931*f[55]*dv0dx0+2.0*f[5]*dv0dx0; 
  out[49] += 7.745966692414834*f[23]*w0dx0+2.23606797749979*f[38]*dv0dx0; 
  out[51] += 7.745966692414834*f[28]*w0dx0+2.23606797749979*f[45]*dv0dx0; 
  out[54] += 11.83215956619923*f[19]*w0dx0+5.291502622129181*f[2]*w0dx0+3.055050463303894*f[48]*dv0dx0+1.366260102127947*f[12]*dv0dx0+3.415650255319867*f[11]*dv0dx0+1.527525231651947*f[0]*dv0dx0; 
  out[55] += 3.464101615137754*f[32]*w0dx0+0.8728715609439696*f[67]*dv0dx0+0.8783100656536796*f[12]*dv0dx0; 
  out[56] += 11.83215956619923*f[21]*w0dx0+5.291502622129181*f[3]*w0dx0+3.415650255319867*f[36]*dv0dx0+1.527525231651947*f[7]*dv0dx0; 
  out[58] += 3.464101615137754*f[33]*w0dx0+f[59]*dv0dx0; 
  out[60] += 11.83215956619923*f[25]*w0dx0+5.291502622129181*f[4]*w0dx0+3.415650255319867*f[39]*dv0dx0+1.527525231651947*f[9]*dv0dx0; 
  out[63] += 3.464101615137754*f[34]*w0dx0+f[64]*dv0dx0; 
  out[66] += 15.87450786638754*f[31]*w0dx0+10.39230484541326*f[1]*w0dx0+4.58257569495584*f[54]*dv0dx0+3.0*f[5]*dv0dx0; 
} 