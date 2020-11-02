#include <MaxwellianOnBasisModDecl.h>

void MaxwellianOnBasisGauss1x2vMax_P2_evAtConfOrd(const double *den, const double *flowU, const double *vtSq, double *flowUOrd, double *vtSqOrd, double *fMFacOrd) {

  flowUOrd[0] = 0.7071067811865475*flowU[0]-0.7905694150420947*flowU[2]; 
  flowUOrd[1] = 0.6324555320336759*flowU[2]-0.9486832980505137*flowU[1]+0.7071067811865475*flowU[0]; 
  flowUOrd[2] = 0.6324555320336759*flowU[2]+0.9486832980505137*flowU[1]+0.7071067811865475*flowU[0]; 
  flowUOrd[3] = 0.7071067811865475*flowU[3]-0.7905694150420947*flowU[5]; 
  flowUOrd[4] = 0.6324555320336759*flowU[5]-0.9486832980505137*flowU[4]+0.7071067811865475*flowU[3]; 
  flowUOrd[5] = 0.6324555320336759*flowU[5]+0.9486832980505137*flowU[4]+0.7071067811865475*flowU[3]; 

  vtSqOrd[0] = 0.7071067811865475*vtSq[0]-0.7905694150420947*vtSq[2]; 
  vtSqOrd[1] = 0.6324555320336759*vtSq[2]-0.9486832980505137*vtSq[1]+0.7071067811865475*vtSq[0]; 
  vtSqOrd[2] = 0.6324555320336759*vtSq[2]+0.9486832980505137*vtSq[1]+0.7071067811865475*vtSq[0]; 

  fMFacOrd[0] = (0.1591549430918953*(0.7071067811865475*den[0]-0.7905694150420947*den[2]))/(0.7071067811865475*vtSq[0]-0.7905694150420947*vtSq[2]); 
  fMFacOrd[1] = (0.1591549430918953*(0.6324555320336759*den[2]-0.9486832980505137*den[1]+0.7071067811865475*den[0]))/(0.6324555320336759*vtSq[2]-0.9486832980505137*vtSq[1]+0.7071067811865475*vtSq[0]); 
  fMFacOrd[2] = (0.1591549430918953*(0.6324555320336759*den[2]+0.9486832980505137*den[1]+0.7071067811865475*den[0]))/(0.6324555320336759*vtSq[2]+0.9486832980505137*vtSq[1]+0.7071067811865475*vtSq[0]); 

}
void MaxwellianOnBasisGauss1x2vMax_P2_phaseQuad(const double *flowUOrd, const double *vtSqOrd, const double *fMFacOrd, const double *wc, const double *dxv, double *fMOut) {

  double fMquad[27];
  fMquad[0] = fMFacOrd[0]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[3],2.0)+std::pow(wc[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[1] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[2] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[3] = fMFacOrd[0]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[3],2.0)+std::pow(wc[1]-0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[4] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[5] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[6] = fMFacOrd[0]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[3],2.0)+std::pow(wc[1]+0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[7] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]+0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[8] = fMFacOrd[0]*exp(-(0.5*(std::pow((-1.0*flowUOrd[3])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]+0.3872983346207417*dxv[1]-1.0*flowUOrd[0],2.0)))/vtSqOrd[0]); 
  fMquad[9] = fMFacOrd[1]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[4],2.0)+std::pow(wc[1]-1.0*flowUOrd[1],2.0)))/vtSqOrd[1]); 
  fMquad[10] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1],2.0)))/vtSqOrd[1]); 
  fMquad[11] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1],2.0)))/vtSqOrd[1]); 
  fMquad[12] = fMFacOrd[1]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[4],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[13] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[14] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[15] = fMFacOrd[1]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[4],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[16] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[17] = fMFacOrd[1]*exp(-(0.5*(std::pow((-1.0*flowUOrd[4])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[1]); 
  fMquad[18] = fMFacOrd[2]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[5],2.0)+std::pow(wc[1]-1.0*flowUOrd[2],2.0)))/vtSqOrd[2]); 
  fMquad[19] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[2],2.0)))/vtSqOrd[2]); 
  fMquad[20] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow(wc[1]-1.0*flowUOrd[2],2.0)))/vtSqOrd[2]); 
  fMquad[21] = fMFacOrd[2]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[5],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 
  fMquad[22] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 
  fMquad[23] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]-0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 
  fMquad[24] = fMFacOrd[2]*exp(-(0.5*(std::pow(wc[2]-1.0*flowUOrd[5],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 
  fMquad[25] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]-0.3872983346207417*dxv[2],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 
  fMquad[26] = fMFacOrd[2]*exp(-(0.5*(std::pow((-1.0*flowUOrd[5])+wc[2]+0.3872983346207417*dxv[2],2.0)+std::pow((-1.0*flowUOrd[2])+wc[1]+0.3872983346207417*dxv[1],2.0)))/vtSqOrd[2]); 

  fMOut[0] = 0.1091214168497758*(fMquad[26]+fMquad[25]+fMquad[24]+fMquad[23]+fMquad[22]+fMquad[21])+0.1745942669596413*(fMquad[20]+fMquad[19]+fMquad[18])+0.1091214168497758*(fMquad[17]+fMquad[16]+fMquad[15]+fMquad[14]+fMquad[13]+fMquad[12])+0.1745942669596413*(fMquad[11]+fMquad[10]+fMquad[9]+fMquad[8]+fMquad[7]+fMquad[6]+fMquad[5]+fMquad[4]+fMquad[3])+0.2793508271354261*(fMquad[2]+fMquad[1]+fMquad[0]); 
  fMOut[1] = 0.1464017435263139*(fMquad[26]+fMquad[25]+fMquad[24]+fMquad[23]+fMquad[22]+fMquad[21])+0.2342427896421021*(fMquad[20]+fMquad[19]+fMquad[18])-0.1464017435263139*(fMquad[17]+fMquad[16]+fMquad[15]+fMquad[14]+fMquad[13]+fMquad[12])-0.2342427896421021*(fMquad[11]+fMquad[10]+fMquad[9]); 
  fMOut[2] = 0.1464017435263139*(fMquad[26]+fMquad[25]+fMquad[24])-0.1464017435263139*(fMquad[23]+fMquad[22]+fMquad[21])+0.1464017435263139*(fMquad[17]+fMquad[16]+fMquad[15])-0.1464017435263139*(fMquad[14]+fMquad[13]+fMquad[12])+0.2342427896421021*(fMquad[8]+fMquad[7]+fMquad[6])-0.2342427896421021*(fMquad[5]+fMquad[4]+fMquad[3]); 
  fMOut[3] = 0.1464017435263139*fMquad[26]-0.1464017435263139*fMquad[25]+0.1464017435263139*fMquad[23]-0.1464017435263139*fMquad[22]+0.2342427896421021*fMquad[20]-0.2342427896421021*fMquad[19]+0.1464017435263139*fMquad[17]-0.1464017435263139*fMquad[16]+0.1464017435263139*fMquad[14]-0.1464017435263139*fMquad[13]+0.2342427896421021*fMquad[11]-0.2342427896421021*fMquad[10]+0.2342427896421021*fMquad[8]-0.2342427896421021*fMquad[7]+0.2342427896421021*fMquad[5]-0.2342427896421021*fMquad[4]+0.3747884634273633*fMquad[2]-0.3747884634273633*fMquad[1]; 
  fMOut[4] = 0.1964185503295965*(fMquad[26]+fMquad[25]+fMquad[24])-0.1964185503295965*(fMquad[23]+fMquad[22]+fMquad[21]+fMquad[17]+fMquad[16]+fMquad[15])+0.1964185503295965*(fMquad[14]+fMquad[13]+fMquad[12]); 
  fMOut[5] = 0.1964185503295965*fMquad[26]-0.1964185503295965*fMquad[25]+0.1964185503295965*fMquad[23]-0.1964185503295965*fMquad[22]+0.3142696805273544*fMquad[20]-0.3142696805273544*fMquad[19]-0.1964185503295965*fMquad[17]+0.1964185503295965*fMquad[16]-0.1964185503295965*fMquad[14]+0.1964185503295965*fMquad[13]-0.3142696805273544*fMquad[11]+0.3142696805273544*fMquad[10]; 
  fMOut[6] = 0.1964185503295965*fMquad[26]-0.1964185503295965*(fMquad[25]+fMquad[23])+0.1964185503295965*(fMquad[22]+fMquad[17])-0.1964185503295965*(fMquad[16]+fMquad[14])+0.1964185503295965*fMquad[13]+0.3142696805273544*fMquad[8]-0.3142696805273544*(fMquad[7]+fMquad[5])+0.3142696805273544*fMquad[4]; 
  fMOut[7] = 0.09760116235087593*(fMquad[26]+fMquad[25]+fMquad[24]+fMquad[23]+fMquad[22]+fMquad[21])+0.1561618597614014*(fMquad[20]+fMquad[19]+fMquad[18])+0.09760116235087593*(fMquad[17]+fMquad[16]+fMquad[15]+fMquad[14]+fMquad[13]+fMquad[12])+0.1561618597614014*(fMquad[11]+fMquad[10]+fMquad[9])-0.1952023247017517*(fMquad[8]+fMquad[7]+fMquad[6]+fMquad[5]+fMquad[4]+fMquad[3])-0.3123237195228027*(fMquad[2]+fMquad[1]+fMquad[0]); 
  fMOut[8] = 0.09760116235087593*(fMquad[26]+fMquad[25]+fMquad[24]+fMquad[23]+fMquad[22]+fMquad[21])-0.1952023247017517*(fMquad[20]+fMquad[19]+fMquad[18])+0.09760116235087593*(fMquad[17]+fMquad[16]+fMquad[15]+fMquad[14]+fMquad[13]+fMquad[12])-0.1952023247017517*(fMquad[11]+fMquad[10]+fMquad[9])+0.1561618597614014*(fMquad[8]+fMquad[7]+fMquad[6]+fMquad[5]+fMquad[4]+fMquad[3])-0.3123237195228027*(fMquad[2]+fMquad[1]+fMquad[0]); 
  fMOut[9] = 0.09760116235087593*(fMquad[26]+fMquad[25])-0.1220014529385949*fMquad[24]+0.09760116235087593*(fMquad[23]+fMquad[22])-0.1220014529385949*fMquad[21]+0.1561618597614014*(fMquad[20]+fMquad[19])-0.1952023247017517*fMquad[18]+0.09760116235087593*(fMquad[17]+fMquad[16])-0.1220014529385949*fMquad[15]+0.09760116235087593*(fMquad[14]+fMquad[13])-0.1220014529385949*fMquad[12]+0.1561618597614014*(fMquad[11]+fMquad[10])-0.1952023247017517*fMquad[9]+0.1561618597614014*(fMquad[8]+fMquad[7])-0.1952023247017517*fMquad[6]+0.1561618597614014*(fMquad[5]+fMquad[4])-0.1952023247017517*fMquad[3]+0.2498589756182423*(fMquad[2]+fMquad[1])-0.3123237195228027*fMquad[0]; 

}
