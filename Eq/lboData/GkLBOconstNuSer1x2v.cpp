#include <GkLBOModDecl.h> 
double GkLBOconstNuVol1x2vSerP1(const double *w, const double *dxv, const double mufac, const double nu, const double *nuU, const double *nuVtSq, const double *f, double *out) 
{ 
  // w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. nu: diffusion coefficient (collisionality). nuU: bulk velocity times nu. nuVtSq: thermal speed squared times nu. f: Input distribution function. out: Incremented output 
  double rdv2[2]; 
  double rdvSq4[2]; 
  rdv2[0] = 2.0/dxv[1]; 
  rdvSq4[0] = 4.0/(dxv[1]*dxv[1]); 
  rdv2[1] = 2.0/dxv[2]; 
  rdvSq4[1] = 4.0/(dxv[2]*dxv[2]); 

  double drBar[4]; 
  drBar[0] = nuU[0]-1.414213562373095*w[1]*nu; 
  drBar[1] = nuU[1]; 
  drBar[2] = -1.414213562373095*w[2]*nu; 
  drBar[3] = 0.0; 

  out[2] += rdv2[0]*(1.224744871391589*f[1]*drBar[1]+1.224744871391589*f[0]*drBar[0])-1.0*f[2]*nu; 
  out[3] += rdv2[1]*(2.449489742783178*f[1]*nuVtSq[1]*mufac+2.449489742783178*f[0]*nuVtSq[0]*mufac+2.449489742783178*f[1]*drBar[3]+2.449489742783178*f[0]*drBar[2])-2.0*f[3]*nu; 
  out[4] += rdv2[0]*(1.224744871391589*f[0]*drBar[1]+1.224744871391589*drBar[0]*f[1])-1.0*f[4]*nu; 
  out[5] += rdv2[1]*(2.449489742783178*f[0]*nuVtSq[1]*mufac+2.449489742783178*nuVtSq[0]*f[1]*mufac+2.449489742783178*f[0]*drBar[3]+2.449489742783178*f[1]*drBar[2])-2.0*f[5]*nu; 
  out[6] += (-3.0*f[6]*nu)+rdv2[1]*(2.449489742783178*nuVtSq[1]*f[4]*mufac+2.449489742783178*nuVtSq[0]*f[2]*mufac+2.449489742783178*drBar[3]*f[4]+2.449489742783178*f[2]*drBar[2])+rdv2[0]*(1.224744871391589*drBar[1]*f[5]+1.224744871391589*drBar[0]*f[3]); 
  out[7] += (-3.0*f[7]*nu)+rdv2[1]*(2.449489742783178*nuVtSq[0]*f[4]*mufac+2.449489742783178*nuVtSq[1]*f[2]*mufac+2.449489742783178*drBar[2]*f[4]+2.449489742783178*f[2]*drBar[3])+rdv2[0]*(1.224744871391589*drBar[0]*f[5]+1.224744871391589*drBar[1]*f[3]); 

return nu*(rdvSq4[0]+rdvSq4[1])*0.5; 

} 
double GkLBOconstNuVol1x2vSerP2(const double *w, const double *dxv, const double mufac, const double nu, const double *nuU, const double *nuVtSq, const double *f, double *out) 
{ 
  // w[NDIM]: Cell-center coordinates. dxv[NDIM]: Cell spacing. nu: diffusion coefficient (collisionality). nuU: bulk velocity times nu. nuVtSq: thermal speed squared times nu. f: Input distribution function. out: Incremented output 
  double rdv2[2]; 
  double rdvSq4[2]; 
  rdv2[0] = 2.0/dxv[1]; 
  rdvSq4[0] = 4.0/(dxv[1]*dxv[1]); 
  rdv2[1] = 2.0/dxv[2]; 
  rdvSq4[1] = 4.0/(dxv[2]*dxv[2]); 

  double drBar[6]; 
  drBar[0] = nuU[0]-1.414213562373095*w[1]*nu; 
  drBar[1] = nuU[1]; 
  drBar[2] = nuU[2]; 
  drBar[3] = -1.414213562373095*w[2]*nu; 
  drBar[4] = 0.0; 
  drBar[5] = 0.0; 

  out[2] += rdv2[0]*(1.224744871391589*drBar[2]*f[7]+1.224744871391589*f[1]*drBar[1]+1.224744871391589*f[0]*drBar[0])-1.0*f[2]*nu; 
  out[3] += rdv2[1]*(2.449489742783178*nuVtSq[2]*f[7]*mufac+2.449489742783178*f[1]*nuVtSq[1]*mufac+2.449489742783178*f[0]*nuVtSq[0]*mufac+2.449489742783178*drBar[5]*f[7]+2.449489742783178*f[1]*drBar[4]+2.449489742783178*f[0]*drBar[3])-2.0*f[3]*nu; 
  out[4] += rdv2[0]*(1.095445115010332*drBar[1]*f[7]+1.095445115010332*f[1]*drBar[2]+1.224744871391589*f[0]*drBar[1]+1.224744871391589*drBar[0]*f[1])-1.0*f[4]*nu; 
  out[5] += rdv2[1]*(2.190890230020665*nuVtSq[1]*f[7]*mufac+2.190890230020665*f[1]*nuVtSq[2]*mufac+2.449489742783178*f[0]*nuVtSq[1]*mufac+2.449489742783178*nuVtSq[0]*f[1]*mufac+2.190890230020665*drBar[4]*f[7]+2.190890230020665*f[1]*drBar[5]+2.449489742783178*f[0]*drBar[4]+2.449489742783178*f[1]*drBar[3])-2.0*f[5]*nu; 
  out[6] += (-3.0*f[6]*nu)+rdv2[1]*(2.449489742783178*nuVtSq[2]*f[11]*mufac+2.449489742783178*nuVtSq[1]*f[4]*mufac+2.449489742783178*nuVtSq[0]*f[2]*mufac+2.449489742783178*drBar[5]*f[11]+2.449489742783178*f[4]*drBar[4]+2.449489742783178*f[2]*drBar[3])+rdv2[0]*(1.224744871391589*drBar[2]*f[13]+1.224744871391589*drBar[1]*f[5]+1.224744871391589*drBar[0]*f[3]); 
  out[8] += (-2.0*f[8]*nu)-2.23606797749979*f[0]*nu+rdv2[0]*(2.738612787525831*drBar[2]*f[11]+2.738612787525831*drBar[1]*f[4]+2.738612787525831*drBar[0]*f[2])+rdvSq4[0]*(4.743416490252569*nuVtSq[2]*f[7]+4.743416490252569*f[1]*nuVtSq[1]+4.743416490252569*f[0]*nuVtSq[0]); 
  out[9] += (-4.0*f[9]*nu)-4.47213595499958*f[0]*nu+rdvSq4[1]*((-(4.285714285714286*nuVtSq[2]*drBar[5]*f[7]*mufac)/nu)-(6.708203932499369*nuVtSq[0]*drBar[5]*f[7]*mufac)/nu-(6.0*nuVtSq[1]*drBar[4]*f[7]*mufac)/nu-(6.708203932499369*nuVtSq[2]*drBar[3]*f[7]*mufac)/nu-(6.708203932499369*f[0]*nuVtSq[2]*drBar[5]*mufac)/nu-(6.0*f[1]*nuVtSq[1]*drBar[5]*mufac)/nu-(6.0*f[1]*nuVtSq[2]*drBar[4]*mufac)/nu-(6.708203932499369*f[0]*nuVtSq[1]*drBar[4]*mufac)/nu-(6.708203932499369*nuVtSq[0]*f[1]*drBar[4]*mufac)/nu-(6.708203932499369*f[1]*nuVtSq[1]*drBar[3]*mufac)/nu-(6.708203932499369*f[0]*nuVtSq[0]*drBar[3]*mufac)/nu)+rdv2[1]*(10.95445115010333*nuVtSq[2]*f[13]*mufac+10.95445115010332*nuVtSq[1]*f[5]*mufac+10.95445115010332*nuVtSq[0]*f[3]*mufac+5.477225575051662*drBar[5]*f[13]+5.477225575051662*drBar[4]*f[5]+5.477225575051662*f[3]*drBar[3]); 
  out[10] += (-3.0*f[10]*nu)+rdv2[1]*(2.190890230020665*nuVtSq[1]*f[11]*mufac+2.190890230020665*nuVtSq[2]*f[4]*mufac+2.449489742783178*nuVtSq[0]*f[4]*mufac+2.449489742783178*nuVtSq[1]*f[2]*mufac+2.190890230020665*drBar[4]*f[11]+2.190890230020665*f[4]*drBar[5]+2.449489742783178*f[2]*drBar[4]+2.449489742783178*drBar[3]*f[4])+rdv2[0]*(1.095445115010332*drBar[1]*f[13]+1.095445115010332*drBar[2]*f[5]+1.224744871391589*drBar[0]*f[5]+1.224744871391589*drBar[1]*f[3]); 
  out[11] += rdv2[0]*(0.7824607964359517*drBar[2]*f[7]+1.224744871391589*drBar[0]*f[7]+1.224744871391589*f[0]*drBar[2]+1.095445115010332*f[1]*drBar[1])-1.0*f[11]*nu; 
  out[12] += (-2.0*f[12]*nu)-2.23606797749979*f[1]*nu+rdv2[0]*(2.449489742783178*drBar[1]*f[11]+2.449489742783178*drBar[2]*f[4]+2.738612787525831*drBar[0]*f[4]+2.738612787525831*drBar[1]*f[2])+rdvSq4[0]*(4.242640687119286*nuVtSq[1]*f[7]+4.242640687119286*f[1]*nuVtSq[2]+4.743416490252569*f[0]*nuVtSq[1]+4.743416490252569*nuVtSq[0]*f[1]); 
  out[13] += rdv2[1]*(1.564921592871904*nuVtSq[2]*f[7]*mufac+2.449489742783178*nuVtSq[0]*f[7]*mufac+2.449489742783178*f[0]*nuVtSq[2]*mufac+2.190890230020665*f[1]*nuVtSq[1]*mufac+1.564921592871904*drBar[5]*f[7]+2.449489742783178*drBar[3]*f[7]+2.449489742783178*f[0]*drBar[5]+2.190890230020665*f[1]*drBar[4])-2.0*f[13]*nu; 
  out[14] += (-4.0*f[14]*nu)-2.23606797749979*f[3]*nu+rdv2[1]*(2.449489742783178*nuVtSq[1]*f[12]*mufac+2.449489742783178*nuVtSq[0]*f[8]*mufac+2.449489742783178*drBar[4]*f[12]+2.449489742783178*drBar[3]*f[8])+rdv2[0]*(2.738612787525831*drBar[2]*f[17]+2.738612787525831*drBar[1]*f[10]+2.738612787525831*drBar[0]*f[6])+rdvSq4[0]*(4.743416490252569*nuVtSq[2]*f[13]+4.743416490252569*nuVtSq[1]*f[5]+4.743416490252569*nuVtSq[0]*f[3]); 
  out[15] += (-4.0*f[15]*nu)-4.47213595499958*f[1]*nu+rdvSq4[1]*((-(10.54146332249901*nuVtSq[1]*drBar[5]*f[7]*mufac)/nu)-(10.54146332249901*nuVtSq[2]*drBar[4]*f[7]*mufac)/nu-(6.0*nuVtSq[0]*drBar[4]*f[7]*mufac)/nu-(6.0*nuVtSq[1]*drBar[3]*f[7]*mufac)/nu-(10.54146332249901*f[1]*nuVtSq[2]*drBar[5]*mufac)/nu-(6.0*f[0]*nuVtSq[1]*drBar[5]*mufac)/nu-(6.0*nuVtSq[0]*f[1]*drBar[5]*mufac)/nu-(6.0*f[0]*nuVtSq[2]*drBar[4]*mufac)/nu-(12.07476707849886*f[1]*nuVtSq[1]*drBar[4]*mufac)/nu-(6.708203932499369*f[0]*nuVtSq[0]*drBar[4]*mufac)/nu-(6.0*f[1]*nuVtSq[2]*drBar[3]*mufac)/nu-(6.708203932499369*f[0]*nuVtSq[1]*drBar[3]*mufac)/nu-(6.708203932499369*nuVtSq[0]*f[1]*drBar[3]*mufac)/nu)+rdv2[1]*(9.797958971132715*nuVtSq[1]*f[13]*mufac+9.797958971132717*nuVtSq[2]*f[5]*mufac+10.95445115010333*nuVtSq[0]*f[5]*mufac+10.95445115010333*nuVtSq[1]*f[3]*mufac+4.898979485566357*drBar[4]*f[13]+4.898979485566358*f[5]*drBar[5]+5.477225575051662*drBar[3]*f[5]+5.477225575051662*f[3]*drBar[4]); 
  out[16] += (-5.0*f[16]*nu)-4.47213595499958*f[2]*nu+rdvSq4[1]*((-(4.285714285714286*nuVtSq[2]*drBar[5]*f[11]*mufac)/nu)-(6.708203932499369*nuVtSq[0]*drBar[5]*f[11]*mufac)/nu-(6.0*nuVtSq[1]*drBar[4]*f[11]*mufac)/nu-(6.708203932499369*nuVtSq[2]*drBar[3]*f[11]*mufac)/nu-(6.0*nuVtSq[1]*f[4]*drBar[5]*mufac)/nu-(6.708203932499369*f[2]*nuVtSq[2]*drBar[5]*mufac)/nu-(6.0*nuVtSq[2]*f[4]*drBar[4]*mufac)/nu-(6.708203932499369*nuVtSq[0]*f[4]*drBar[4]*mufac)/nu-(6.708203932499369*nuVtSq[1]*f[2]*drBar[4]*mufac)/nu-(6.708203932499369*nuVtSq[1]*drBar[3]*f[4]*mufac)/nu-(6.708203932499369*nuVtSq[0]*f[2]*drBar[3]*mufac)/nu)+rdv2[1]*(10.95445115010333*nuVtSq[2]*f[17]*mufac+10.95445115010333*nuVtSq[1]*f[10]*mufac+10.95445115010333*nuVtSq[0]*f[6]*mufac+5.477225575051662*drBar[5]*f[17]+5.477225575051662*drBar[4]*f[10]+5.477225575051662*drBar[3]*f[6])+rdv2[0]*(1.224744871391589*drBar[1]*f[15]+1.224744871391589*drBar[0]*f[9]); 
  out[17] += (-3.0*f[17]*nu)+rdv2[1]*(1.564921592871904*nuVtSq[2]*f[11]*mufac+2.449489742783178*nuVtSq[0]*f[11]*mufac+2.190890230020665*nuVtSq[1]*f[4]*mufac+2.449489742783178*f[2]*nuVtSq[2]*mufac+1.564921592871904*drBar[5]*f[11]+2.449489742783178*drBar[3]*f[11]+2.449489742783178*f[2]*drBar[5]+2.190890230020665*f[4]*drBar[4])+rdv2[0]*(0.7824607964359517*drBar[2]*f[13]+1.224744871391589*drBar[0]*f[13]+1.095445115010332*drBar[1]*f[5]+1.224744871391589*drBar[2]*f[3]); 
  out[18] += (-4.0*f[18]*nu)-2.23606797749979*f[5]*nu+rdv2[1]*(2.190890230020665*nuVtSq[2]*f[12]*mufac+2.449489742783178*nuVtSq[0]*f[12]*mufac+2.449489742783178*nuVtSq[1]*f[8]*mufac+2.190890230020665*drBar[5]*f[12]+2.449489742783178*drBar[3]*f[12]+2.449489742783178*drBar[4]*f[8])+rdv2[0]*(2.449489742783178*drBar[1]*f[17]+2.449489742783178*drBar[2]*f[10]+2.738612787525831*drBar[0]*f[10]+2.738612787525831*drBar[1]*f[6])+rdvSq4[0]*(4.242640687119286*nuVtSq[1]*f[13]+4.242640687119286*nuVtSq[2]*f[5]+4.743416490252569*nuVtSq[0]*f[5]+4.743416490252569*nuVtSq[1]*f[3]); 
  out[19] += (-5.0*f[19]*nu)-4.47213595499958*f[4]*nu+rdvSq4[1]*((-(10.54146332249901*nuVtSq[1]*drBar[5]*f[11]*mufac)/nu)-(10.54146332249901*nuVtSq[2]*drBar[4]*f[11]*mufac)/nu-(6.0*nuVtSq[0]*drBar[4]*f[11]*mufac)/nu-(6.0*nuVtSq[1]*drBar[3]*f[11]*mufac)/nu-(10.54146332249901*nuVtSq[2]*f[4]*drBar[5]*mufac)/nu-(6.0*nuVtSq[0]*f[4]*drBar[5]*mufac)/nu-(6.0*nuVtSq[1]*f[2]*drBar[5]*mufac)/nu-(12.07476707849886*nuVtSq[1]*f[4]*drBar[4]*mufac)/nu-(6.0*f[2]*nuVtSq[2]*drBar[4]*mufac)/nu-(6.708203932499369*nuVtSq[0]*f[2]*drBar[4]*mufac)/nu-(6.0*nuVtSq[2]*drBar[3]*f[4]*mufac)/nu-(6.708203932499369*nuVtSq[0]*drBar[3]*f[4]*mufac)/nu-(6.708203932499369*nuVtSq[1]*f[2]*drBar[3]*mufac)/nu)+rdv2[1]*(9.797958971132715*nuVtSq[1]*f[17]*mufac+9.797958971132715*nuVtSq[2]*f[10]*mufac+10.95445115010332*nuVtSq[0]*f[10]*mufac+10.95445115010332*nuVtSq[1]*f[6]*mufac+4.898979485566357*drBar[4]*f[17]+4.898979485566357*drBar[5]*f[10]+5.477225575051662*drBar[3]*f[10]+5.477225575051662*drBar[4]*f[6])+rdv2[0]*(1.095445115010332*drBar[2]*f[15]+1.224744871391589*drBar[0]*f[15]+1.224744871391589*drBar[1]*f[9]); 

return nu*(rdvSq4[0]+rdvSq4[1])*0.5; 

} 