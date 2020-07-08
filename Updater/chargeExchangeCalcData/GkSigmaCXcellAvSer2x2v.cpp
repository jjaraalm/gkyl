#include <SigmaCXModDecl.h> 
#include <math.h> 
void GkSigmaCXcellAvSer2x2v_P1(const double a, const double b, const double *uParIon, const double *uParNeut, const double *vtSqIon, const double *vtSqNeut, double *vSigmaCX) 
{ 
  // a               constant in fitting function. 
  // b               constant in fitting function. 
  // uParIon[8]:    ion fluid velocity. 
  // uParNeut[8]:   neutral fluid velocity. 
  // vtSqIon[4]:    ion squared thermal speed, sqrt(T/m). 
  // vtSqNeut[4]:   neutral squared thermal speed, sqrt(T/m). 
  // vSigmaCX:       cell ave cross section fitting eqn. 
 
  double vtSqIonAv = 0.5*vtSqIon[0]; 
  double vtSqNeutAv = 0.5*vtSqNeut[0]; 
  double vINSqAv = 0.25*pow(uParNeut[0],2)-0.5*uParIon[0]*uParNeut[0]+0.25*pow(uParIon[0],2); 
  vSigmaCX[0] = 1.128379167095513*a*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)-1.128379167095513*b*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)*log(0.5641895835477563*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)); 
 
} 
void GkSigmaCXcellAvSer2x2v_P2(const double a, const double b, const double *uParIon, const double *uParNeut, const double *vtSqIon, const double *vtSqNeut, double *vSigmaCX) 
{ 
  // a               constant in fitting function. 
  // b               constant in fitting function. 
  // uParIon[16]:    ion fluid velocity. 
  // uParNeut[16]:   neutral fluid velocity. 
  // vtSqIon[8]:    ion squared thermal speed, sqrt(T/m). 
  // vtSqNeut[8]:   neutral squared thermal speed, sqrt(T/m). 
  // vSigmaCX:       cell ave cross section fitting eqn. 
 
  double vtSqIonAv = 0.5*vtSqIon[0]; 
  double vtSqNeutAv = 0.5*vtSqNeut[0]; 
  double vINSqAv = 0.25*pow(uParNeut[0],2)-0.5*uParIon[0]*uParNeut[0]+0.25*pow(uParIon[0],2); 
  vSigmaCX[0] = 1.128379167095513*a*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)-1.128379167095513*b*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)*log(0.5641895835477563*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)); 
 
} 
void GkSigmaCXcellAvSer2x2v_P3(const double a, const double b, const double *uParIon, const double *uParNeut, const double *vtSqIon, const double *vtSqNeut, double *vSigmaCX) 
{ 
  // a               constant in fitting function. 
  // b               constant in fitting function. 
  // uParIon[24]:    ion fluid velocity. 
  // uParNeut[24]:   neutral fluid velocity. 
  // vtSqIon[12]:    ion squared thermal speed, sqrt(T/m). 
  // vtSqNeut[12]:   neutral squared thermal speed, sqrt(T/m). 
  // vSigmaCX:       cell ave cross section fitting eqn. 
 
  double vtSqIonAv = 0.5*vtSqIon[0]; 
  double vtSqNeutAv = 0.5*vtSqNeut[0]; 
  double vINSqAv = 0.25*pow(uParNeut[0],2)-0.5*uParIon[0]*uParNeut[0]+0.25*pow(uParIon[0],2); 
  vSigmaCX[0] = 1.128379167095513*a*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)-1.128379167095513*b*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)*log(0.5641895835477563*sqrt(4.0*vtSqNeutAv+4.0*vtSqIonAv+3.141592653589793*vINSqAv)); 
 
} 
