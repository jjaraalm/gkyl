#include <SpitzerNuModDecl.h> 
#include <math.h> 
void SpitzerNuCellAvScale2xSer_P1(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[4]:     number density of species A. 
  // vtSqA[4]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[4]:     number density of species B. 
  // vtSqB[4]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[4]:    magnetic field magnitude. 
  // nu[4]:      collisionality. 
 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = (m0B[0]*normNu*nuFrac)/sqrt(0.125*pow(vtSqB[0],3)+0.375*vtSqA[0]*pow(vtSqB[0],2)+0.375*pow(vtSqA[0],2)*vtSqB[0]+0.125*pow(vtSqA[0],3)); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
void SpitzerNuCellAvScale2xSer_P2(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[8]:     number density of species A. 
  // vtSqA[8]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[8]:     number density of species B. 
  // vtSqB[8]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[8]:    magnetic field magnitude. 
  // nu[8]:      collisionality. 
 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = (m0B[0]*normNu*nuFrac)/sqrt(0.125*pow(vtSqB[0],3)+0.375*vtSqA[0]*pow(vtSqB[0],2)+0.375*pow(vtSqA[0],2)*vtSqB[0]+0.125*pow(vtSqA[0],3)); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
void SpitzerNuCellAvScale2xSer_P3(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[12]:     number density of species A. 
  // vtSqA[12]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[12]:     number density of species B. 
  // vtSqB[12]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[12]:    magnetic field magnitude. 
  // nu[12]:      collisionality. 
 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = (m0B[0]*normNu*nuFrac)/sqrt(0.125*pow(vtSqB[0],3)+0.375*vtSqA[0]*pow(vtSqB[0],2)+0.375*pow(vtSqA[0],2)*vtSqB[0]+0.125*pow(vtSqA[0],3)); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
void SpitzerNuCellAvBuild2xSer_P1(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[4]:     number density of species A. 
  // vtSqA[4]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[4]:     number density of species B. 
  // vtSqB[4]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[4]:    magnetic field magnitude. 
  // nu[4]:      collisionality. 
 
  double nA0 = 0.5*m0A[0]; 
  double vtSqA0 = 0.5*vtSqA[0]; 
  double nB0 = 0.5*m0B[0]; 
  double vtSqB0 = 0.5*vtSqB[0]; 
  double Bmag0 = 0.5*Bmag[0]; 
  double logLambda;
  double massAB = (massA*massB)/(massB+massA); 
  double uRelSq = 3.0*vtSqB0+3.0*vtSqA0; 
  double rMaxA = 1.0/sqrt((pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0+3.0*pow(massB,2)*vtSqA0)+(nB0*pow(qB,2))/(eps0*massB*vtSqB0+3.0*eps0*massB*vtSqA0)+(0.25*nA0*pow(qA,2))/(eps0*massA*vtSqA0)+(0.25*pow(Bmag0,2)*pow(qA,2))/(pow(massA,2)*vtSqA0)); 
  double rMaxB = 1.0/sqrt((pow(Bmag0,2)*pow(qA,2))/(3.0*pow(massA,2)*vtSqB0+pow(massA,2)*vtSqA0)+(nA0*pow(qA,2))/(3.0*eps0*massA*vtSqB0+eps0*massA*vtSqA0)+(0.25*nB0*pow(qB,2))/(eps0*massB*vtSqB0)+(0.25*pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0)); 
  double rMin = std::max((0.07957747154594767*std::abs(qA*qB))/(eps0*massAB*uRelSq),(0.3032653298563167*hBar)/(massAB*sqrt(uRelSq))); 
  logLambda = 0.25*log(pow(rMaxB,2)/pow(rMin,2)+1.0)+0.25*log(pow(rMaxA,2)/pow(rMin,2)+1.0); 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = ((0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(massA*massB*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3)))+(0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(pow(massA,2)*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3))))/pow(eps0,2); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
void SpitzerNuCellAvBuild2xSer_P2(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[8]:     number density of species A. 
  // vtSqA[8]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[8]:     number density of species B. 
  // vtSqB[8]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[8]:    magnetic field magnitude. 
  // nu[8]:      collisionality. 
 
  double nA0 = 0.5*m0A[0]; 
  double vtSqA0 = 0.5*vtSqA[0]; 
  double nB0 = 0.5*m0B[0]; 
  double vtSqB0 = 0.5*vtSqB[0]; 
  double Bmag0 = 0.5*Bmag[0]; 
  double logLambda;
  double massAB = (massA*massB)/(massB+massA); 
  double uRelSq = 3.0*vtSqB0+3.0*vtSqA0; 
  double rMaxA = 1.0/sqrt((pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0+3.0*pow(massB,2)*vtSqA0)+(nB0*pow(qB,2))/(eps0*massB*vtSqB0+3.0*eps0*massB*vtSqA0)+(0.25*nA0*pow(qA,2))/(eps0*massA*vtSqA0)+(0.25*pow(Bmag0,2)*pow(qA,2))/(pow(massA,2)*vtSqA0)); 
  double rMaxB = 1.0/sqrt((pow(Bmag0,2)*pow(qA,2))/(3.0*pow(massA,2)*vtSqB0+pow(massA,2)*vtSqA0)+(nA0*pow(qA,2))/(3.0*eps0*massA*vtSqB0+eps0*massA*vtSqA0)+(0.25*nB0*pow(qB,2))/(eps0*massB*vtSqB0)+(0.25*pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0)); 
  double rMin = std::max((0.07957747154594767*std::abs(qA*qB))/(eps0*massAB*uRelSq),(0.3032653298563167*hBar)/(massAB*sqrt(uRelSq))); 
  logLambda = 0.25*log(pow(rMaxB,2)/pow(rMin,2)+1.0)+0.25*log(pow(rMaxA,2)/pow(rMin,2)+1.0); 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = ((0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(massA*massB*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3)))+(0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(pow(massA,2)*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3))))/pow(eps0,2); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
void SpitzerNuCellAvBuild2xSer_P3(const double elemCharge, const double eps0, const double hBar, const double nuFrac, const double qA, const double massA, const double *m0A, const double *vtSqA, const double qB, const double massB, const double *m0B, const double *vtSqB, const double normNu, const double *Bmag, double *nu) 
{ 
  // elemCharge: elementary charge (J - eV conversion factor). 
  // eps0:       vacuum permittivity. 
  // hBar:       Planck's constant h, divided by 2pi. 
  // nuFrac:     scaling factor. 
  // qA:         charge of species A. 
  // massA:      mass of species A. 
  // m0A[12]:     number density of species A. 
  // vtSqA[12]:   squared thermal speed, sqrt(T/m), of species A. 
  // qB:         charge of species B. 
  // massB:      mass of species B. 
  // m0B[12]:     number density of species B. 
  // vtSqB[12]:   squared thermal speed, sqrt(T/m), of species B. 
  // Bmag[12]:    magnetic field magnitude. 
  // nu[12]:      collisionality. 
 
  double nA0 = 0.5*m0A[0]; 
  double vtSqA0 = 0.5*vtSqA[0]; 
  double nB0 = 0.5*m0B[0]; 
  double vtSqB0 = 0.5*vtSqB[0]; 
  double Bmag0 = 0.5*Bmag[0]; 
  double logLambda;
  double massAB = (massA*massB)/(massB+massA); 
  double uRelSq = 3.0*vtSqB0+3.0*vtSqA0; 
  double rMaxA = 1.0/sqrt((pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0+3.0*pow(massB,2)*vtSqA0)+(nB0*pow(qB,2))/(eps0*massB*vtSqB0+3.0*eps0*massB*vtSqA0)+(0.25*nA0*pow(qA,2))/(eps0*massA*vtSqA0)+(0.25*pow(Bmag0,2)*pow(qA,2))/(pow(massA,2)*vtSqA0)); 
  double rMaxB = 1.0/sqrt((pow(Bmag0,2)*pow(qA,2))/(3.0*pow(massA,2)*vtSqB0+pow(massA,2)*vtSqA0)+(nA0*pow(qA,2))/(3.0*eps0*massA*vtSqB0+eps0*massA*vtSqA0)+(0.25*nB0*pow(qB,2))/(eps0*massB*vtSqB0)+(0.25*pow(Bmag0,2)*pow(qB,2))/(pow(massB,2)*vtSqB0)); 
  double rMin = std::max((0.07957747154594767*std::abs(qA*qB))/(eps0*massAB*uRelSq),(0.3032653298563167*hBar)/(massAB*sqrt(uRelSq))); 
  logLambda = 0.25*log(pow(rMaxB,2)/pow(rMin,2)+1.0)+0.25*log(pow(rMaxA,2)/pow(rMin,2)+1.0); 
  if ((m0B[0]>0.0) && (vtSqA[0]>0.0) && (vtSqB[0]>0.0)) {
    nu[0] = ((0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(massA*massB*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3)))+(0.04232909062282731*logLambda*nB0*nuFrac*pow(qA,2)*pow(qB,2))/(pow(massA,2)*sqrt(pow(vtSqB0,3)+3.0*vtSqA0*pow(vtSqB0,2)+3.0*pow(vtSqA0,2)*vtSqB0+pow(vtSqA0,3))))/pow(eps0,2); 
  } else {
    nu[0] = 0.0;
  }
 
} 
 
