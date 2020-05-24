#include <VlasovModDecl.h> 
__host__ __device__ void VlasovSurfStream1x1vSer_X_P3(const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *outl, double *outr) 
{ 
// w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. fl/fr: Distribution function in left/right cells 
// outl/outr: Incremented distribution function in left/right cells 
  double dvxl = dxvl[1]; 
  double wxl = wl[1]; 

  double dvxr = dxvr[1]; 
  double wxr = wr[1]; 

  double dxl = 1.0/dxvl[0]; 
  double dxr = 1.0/dxvr[0]; 

  double incr[12]; 

  if (wxr>0) { 
  incr[0] = (2.645751311064591*fl[8]+2.23606797749979*fl[4]+1.732050807568877*fl[1]+fl[0])*wxl+(0.7637626158259733*fl[10]+0.6454972243679028*fl[6]+0.5*fl[3]+0.2886751345948129*fl[2])*dvxl; 
  incr[1] = ((-4.58257569495584*fl[8])-3.872983346207417*fl[4]-3.0*fl[1]-1.732050807568877*fl[0])*wxl+((-1.322875655532295*fl[10])-1.118033988749895*fl[6]-0.8660254037844386*fl[3]-0.5*fl[2])*dvxl; 
  incr[2] = (2.645751311064591*fl[10]+2.23606797749979*fl[6]+1.732050807568877*fl[3]+fl[2])*wxl+(0.7637626158259735*fl[8]+0.447213595499958*fl[7]+0.2581988897471612*fl[5]+0.6454972243679029*fl[4]+0.5*fl[1]+0.2886751345948129*fl[0])*dvxl; 
  incr[3] = ((-4.58257569495584*fl[10])-3.872983346207417*fl[6]-3.0*fl[3]-1.732050807568877*fl[2])*wxl+((-1.322875655532295*fl[8])-0.7745966692414834*fl[7]-0.4472135954999579*fl[5]-1.118033988749895*fl[4]-0.8660254037844386*fl[1]-0.5*fl[0])*dvxl; 
  incr[4] = (5.916079783099617*fl[8]+5.0*fl[4]+3.872983346207417*fl[1]+2.23606797749979*fl[0])*wxl+(1.707825127659933*fl[10]+1.443375672974065*fl[6]+1.118033988749895*fl[3]+0.6454972243679029*fl[2])*dvxl; 
  incr[5] = (1.732050807568877*fl[7]+fl[5])*wxl+(0.4391550328268399*fl[11]+0.6831300510639731*fl[10]+0.253546276418555*fl[9]+0.5773502691896257*fl[6]+0.4472135954999579*fl[3]+0.2581988897471612*fl[2])*dvxl; 
  incr[6] = (5.916079783099615*fl[10]+5.0*fl[6]+3.872983346207417*fl[3]+2.23606797749979*fl[2])*wxl+(1.707825127659933*fl[8]+fl[7]+0.5773502691896257*fl[5]+1.443375672974065*fl[4]+1.118033988749895*fl[1]+0.6454972243679028*fl[0])*dvxl; 
  incr[7] = ((-3.0*fl[7])-1.732050807568877*fl[5])*wxl+((-0.760638829255665*fl[11])-1.183215956619923*fl[10]-0.4391550328268399*fl[9]-1.0*fl[6]-0.7745966692414834*fl[3]-0.447213595499958*fl[2])*dvxl; 
  incr[8] = ((-7.0*fl[8])-5.916079783099617*fl[4]-4.58257569495584*fl[1]-2.645751311064591*fl[0])*wxl+((-2.02072594216369*fl[10])-1.707825127659933*fl[6]-1.322875655532295*fl[3]-0.7637626158259735*fl[2])*dvxl; 
  incr[9] = (1.732050807568877*fl[11]+fl[9])*wxl+(0.4391550328268399*fl[7]+0.253546276418555*fl[5])*dvxl; 
  incr[10] = ((-7.0*fl[10])-5.916079783099615*fl[6]-4.58257569495584*fl[3]-2.645751311064591*fl[2])*wxl+((-2.02072594216369*fl[8])-1.183215956619923*fl[7]-0.6831300510639731*fl[5]-1.707825127659933*fl[4]-1.322875655532295*fl[1]-0.7637626158259733*fl[0])*dvxl; 
  incr[11] = ((-3.0*fl[11])-1.732050807568877*fl[9])*wxl+((-0.760638829255665*fl[7])-0.4391550328268399*fl[5])*dvxl; 

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

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += incr[1]*dxl; 
  outl[2] += -1.0*incr[2]*dxl; 
  outl[3] += incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += -1.0*incr[6]*dxl; 
  outl[7] += incr[7]*dxl; 
  outl[8] += incr[8]*dxl; 
  outl[9] += -1.0*incr[9]*dxl; 
  outl[10] += incr[10]*dxl; 
  outl[11] += incr[11]*dxl; 
  } else { 
  incr[0] = ((-2.645751311064591*fr[8])+2.23606797749979*fr[4]-1.732050807568877*fr[1]+fr[0])*wxr+((-0.7637626158259733*fr[10])+0.6454972243679028*fr[6]-0.5*fr[3]+0.2886751345948129*fr[2])*dvxr; 
  incr[1] = (4.58257569495584*fr[8]-3.872983346207417*fr[4]+3.0*fr[1]-1.732050807568877*fr[0])*wxr+(1.322875655532295*fr[10]-1.118033988749895*fr[6]+0.8660254037844386*fr[3]-0.5*fr[2])*dvxr; 
  incr[2] = ((-2.645751311064591*fr[10])+2.23606797749979*fr[6]-1.732050807568877*fr[3]+fr[2])*wxr+((-0.7637626158259735*fr[8])-0.447213595499958*fr[7]+0.2581988897471612*fr[5]+0.6454972243679029*fr[4]-0.5*fr[1]+0.2886751345948129*fr[0])*dvxr; 
  incr[3] = (4.58257569495584*fr[10]-3.872983346207417*fr[6]+3.0*fr[3]-1.732050807568877*fr[2])*wxr+(1.322875655532295*fr[8]+0.7745966692414834*fr[7]-0.4472135954999579*fr[5]-1.118033988749895*fr[4]+0.8660254037844386*fr[1]-0.5*fr[0])*dvxr; 
  incr[4] = ((-5.916079783099617*fr[8])+5.0*fr[4]-3.872983346207417*fr[1]+2.23606797749979*fr[0])*wxr+((-1.707825127659933*fr[10])+1.443375672974065*fr[6]-1.118033988749895*fr[3]+0.6454972243679029*fr[2])*dvxr; 
  incr[5] = (fr[5]-1.732050807568877*fr[7])*wxr+((-0.4391550328268399*fr[11])-0.6831300510639731*fr[10]+0.253546276418555*fr[9]+0.5773502691896257*fr[6]-0.4472135954999579*fr[3]+0.2581988897471612*fr[2])*dvxr; 
  incr[6] = ((-5.916079783099615*fr[10])+5.0*fr[6]-3.872983346207417*fr[3]+2.23606797749979*fr[2])*wxr+((-1.707825127659933*fr[8])-1.0*fr[7]+0.5773502691896257*fr[5]+1.443375672974065*fr[4]-1.118033988749895*fr[1]+0.6454972243679028*fr[0])*dvxr; 
  incr[7] = (3.0*fr[7]-1.732050807568877*fr[5])*wxr+(0.760638829255665*fr[11]+1.183215956619923*fr[10]-0.4391550328268399*fr[9]-1.0*fr[6]+0.7745966692414834*fr[3]-0.447213595499958*fr[2])*dvxr; 
  incr[8] = (7.0*fr[8]-5.916079783099617*fr[4]+4.58257569495584*fr[1]-2.645751311064591*fr[0])*wxr+(2.02072594216369*fr[10]-1.707825127659933*fr[6]+1.322875655532295*fr[3]-0.7637626158259735*fr[2])*dvxr; 
  incr[9] = (fr[9]-1.732050807568877*fr[11])*wxr+(0.253546276418555*fr[5]-0.4391550328268399*fr[7])*dvxr; 
  incr[10] = (7.0*fr[10]-5.916079783099615*fr[6]+4.58257569495584*fr[3]-2.645751311064591*fr[2])*wxr+(2.02072594216369*fr[8]+1.183215956619923*fr[7]-0.6831300510639731*fr[5]-1.707825127659933*fr[4]+1.322875655532295*fr[1]-0.7637626158259733*fr[0])*dvxr; 
  incr[11] = (3.0*fr[11]-1.732050807568877*fr[9])*wxr+(0.760638829255665*fr[7]-0.4391550328268399*fr[5])*dvxr; 

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

  outl[0] += -1.0*incr[0]*dxl; 
  outl[1] += incr[1]*dxl; 
  outl[2] += -1.0*incr[2]*dxl; 
  outl[3] += incr[3]*dxl; 
  outl[4] += -1.0*incr[4]*dxl; 
  outl[5] += -1.0*incr[5]*dxl; 
  outl[6] += -1.0*incr[6]*dxl; 
  outl[7] += incr[7]*dxl; 
  outl[8] += incr[8]*dxl; 
  outl[9] += -1.0*incr[9]*dxl; 
  outl[10] += incr[10]*dxl; 
  outl[11] += incr[11]*dxl; 
  } 
} 
