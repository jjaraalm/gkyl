#include <math.h> 
#include <CartFieldBinOpModDecl.h> 
 
using namespace Eigen; 
 
void CartFieldBinOpMultiply2xMax_P1(binOpData_t* data, const double *A, const double *B, const short int Ncomp, const short int eqNcomp, double *out) 
{ 
  // A:       scalar/vector field. 
  // B:       scalar/vector field (must be vector if A is vector). 
  // Ncomp:   number of components of B (could be 1D, 2D, 3D, vector). 
  // eqNcomp: =1 if A:numComponents=B:numComponents, =0 else. 
  // out:     output field A*B (same number of components as B). 
 
  double tmp[3]; 
 
  for (unsigned short int vd=0; vd<Ncomp; vd++) 
  { 
    unsigned short int b0 = 3*vd; 
    unsigned short int a0 = b0*eqNcomp; 
    // Component-wise (of the vectors) multiplication. 
    tmp[0] = 0.5*(A[a0+2]*B[b0+2]+A[a0+1]*B[b0+1]+A[a0]*B[b0]); 
    tmp[1] = 0.5*(A[a0]*B[b0+1]+A[a0+1]*B[b0]); 
    tmp[2] = 0.5*(A[a0]*B[b0+2]+A[a0+2]*B[b0]); 
 
    // This tmp allows for in-place multiplication. 
    for (unsigned short int i=0; i<3; i++) 
    { 
      out[b0+i] = tmp[i]; 
    } 
  } 
 
} 
 
void CartFieldBinOpDivide2xMax_P1(binOpData_t* data, const double *A, const double *B, const short int Ncomp, const short int eqNcomp, double *out) 
{ 
  // A:       denominator field (must be a scalar field). 
  // B:       numerator field (can be scalar or vector). 
  // Ncomp:   number of components of B (could be 1D, 2D, 3D, vector). 
  // eqNcomp: =1 if A:numComponents=B:numComponents, =0 else. 
  // out:     output field (same number of components as B). 
 
  // If a corner value is below zero, use cell average A.
  bool avgA = false;
  if (0.5*A[0]-0.8660254037844386*(A[2]+A[1]) < 0.0) { 
    avgA = true;
  }
  if ((-0.8660254037844386*A[2])+0.8660254037844386*A[1]+0.5*A[0] < 0.0) { 
    avgA = true;
  }
  if (0.8660254037844386*A[2]-0.8660254037844386*A[1]+0.5*A[0] < 0.0) { 
    avgA = true;
  }
  if (0.8660254037844386*(A[2]+A[1])+0.5*A[0] < 0.0) { 
    avgA = true;
  }
 
  unsigned short int b0; 
  double As[3]; 
  double Bs[3*Ncomp]; 
  if (avgA) { 
    As[0] = A[0]; 
    As[1] = 0.0; 
    As[2] = 0.0; 
    for(unsigned short int vd=0; vd<Ncomp; vd++) 
    { 
      b0 = 3*vd; 
      Bs[b0] = B[b0]; 
      Bs[b0+1] = 0.0; 
      Bs[b0+2] = 0.0; 
    } 
  } else { 
    As[0] = A[0]; 
    As[1] = A[1]; 
    As[2] = A[2]; 
    for(unsigned short int vd=0; vd<Ncomp; vd++) 
    { 
      b0 = 3*vd; 
      Bs[b0] = B[b0]; 
      Bs[b0+1] = B[b0+1]; 
      Bs[b0+2] = B[b0+2]; 
    } 
  } 
 
  // Fill AEM matrix. 
  data->AEM_S = Eigen::MatrixXd::Zero(3,3); 
  data->AEM_S(0,0) = 0.5*As[0]; 
  data->AEM_S(0,1) = 0.5*As[1]; 
  data->AEM_S(0,2) = 0.5*As[2]; 
  data->AEM_S(1,0) = 0.5*As[1]; 
  data->AEM_S(1,1) = 0.5*As[0]; 
  data->AEM_S(2,0) = 0.5*As[2]; 
  data->AEM_S(2,2) = 0.5*As[0]; 

  for(unsigned short int vd=0; vd<Ncomp; vd++) 
  { 
    b0 = 3*vd; 
    // Fill BEV. 
    data->BEV_S << Bs[b0],Bs[b0+1],Bs[b0+2]; 

    // Solve the system of equations. 
    data->u_S = data->AEM_S.colPivHouseholderQr().solve(data->BEV_S); 
 
    // Copy data from Eigen vector. 
    Eigen::Map<VectorXd>(out+vd*3,3,1) = data->u_S; 
  } 
}

void CartFieldBinOpDotProduct2xMax_P1(binOpData_t* data, const double *A, const double *B, const short int Ncomp, const short int eqNcomp, double *out) 
{ 
  // A:       scalar/vector field. 
  // B:       scalar/vector field (must be vector if A is vector). 
  // Ncomp:   number of components of B (could be 1D, 2D, 3D, vector). 
  // eqNcomp: =1 if A:numComponents=B:numComponents, =0 else (should be 1 here). 
  // out:     output field A.B (out only has one component). 
 
  // zero out. This is ok in this operator because there is no in-place dot-product. 
  for (unsigned short int vd=0; vd<3; vd++) 
  { 
    out[vd] = 0.0; 
  } 
 
  for (unsigned short int vd=0; vd<Ncomp; vd++) 
  { 
    unsigned short int a0 = 3*vd; 
    // Contribution to dot-product from weak multiplication of vd component. 
    out[0] += 0.5*A[a0+2]*B[a0+2]+0.5*A[a0+1]*B[a0+1]+0.5*A[a0]*B[a0]; 
    out[1] += 0.5*A[a0]*B[a0+1]+0.5*B[a0]*A[a0+1]; 
    out[2] += 0.5*A[a0]*B[a0+2]+0.5*B[a0]*A[a0+2]; 
  } 
 
} 
 
