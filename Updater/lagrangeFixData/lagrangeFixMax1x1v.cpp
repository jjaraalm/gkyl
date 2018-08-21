#include <math.h> 
#include <lagrangeFixDecl.h> 

void lagrangeFixMax1x1v1p(const double *dm0, const double *dm1, const double*dm2, double *f, const double vc, const double L, const double Nv) {
  double *dm0s = dm0 - 1;
  double *dm1s = dm1 - 1;
  double *dm2s = dm2 - 1;
  f[0] = f[0] +  -(1.0*((84.85281374238573*dm0s[1]*L^2-1018.233764908629*dm2s[1])*Nv^4*vc^2+(67.8822509939086*dm1s[1]*L^2-67.8822509939086*dm1s[1]*L^2*Nv^4)*vc+(84.85281374238573*dm2s[1]*L^2-12.72792206135786*dm0s[1]*L^4)*Nv^4+(7.071067811865476*dm0s[1]*L^4-84.85281374238573*dm2s[1]*L^2)*Nv^2+5.656854249492382*dm0s[1]*L^4))/(4.0*L^5*Nv^4-4.0*L^5);
  f[1] = f[1] +  -(1.0*((84.85281374238573*dm0s[2]*L^2-1018.233764908629*dm2s[2])*Nv^4*vc^2+(271.5290039756345*dm1s[2]*L^2*Nv^2-67.8822509939086*dm1s[2]*L^2*Nv^4)*vc+(84.85281374238573*dm2s[2]*L^2-12.72792206135786*dm0s[2]*L^4)*Nv^4+(35.35533905932738*dm0s[2]*L^4-84.85281374238573*dm2s[2]*L^2)*Nv^2-22.62741699796953*dm0s[2]*L^4))/(4.0*L^5*Nv^4-20.0*L^5*Nv^2+16.0*L^5);
  f[2] = f[2] +  -(1.0*((30.0*dm0s[1]*L^2-360.0*dm2s[1])*Nv^4*vc-12.0*dm1s[1]*L^2*Nv^4+12.0*dm1s[1]*L^2))/(2.449489742783178*L^4*Nv^5-2.449489742783178*L^4*Nv);
}
