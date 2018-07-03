#include <math.h> 
#include <PrimMomentsModDecl.h> 
 
using namespace Eigen; 
 
void SelfPrimMoments1x3vMax_P1(const double *m0, const double *m1, const double *m2, const double *cM, const double *cE, double *u, double *vtSq) 
{ 
  // m0,m1,m2: moments of the distribution function. 
  // cM, cE: vtSq*cM and vtSq*cE are corrections to u and vtSq, respectively. 
  // u:        velocity. 
  // vtSq:     squared thermal speed, sqrt(T/m). 
 
  // Declare Eigen matrix and vectors for weak division. 
  Eigen::MatrixXd BigAEM(8,8); 
  Eigen::VectorXd bEV(8); 
  Eigen::VectorXd xEV(8); 
 
  // ....... Block from weak multiply of uX and m0  .......... // 
  BigAEM(0,0) = 0.7071067811865475*m0[0]; 
  BigAEM(0,1) = 0.7071067811865475*m0[1]; 
  BigAEM(1,0) = 0.7071067811865475*m0[1]; 
  BigAEM(1,1) = 0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uX .......... // 
  BigAEM(0,6) = -0.7071067811865475*cM[0]; 
  BigAEM(0,7) = -0.7071067811865475*cM[1]; 
  BigAEM(1,6) = -0.7071067811865475*cM[1]; 
  BigAEM(1,7) = -0.7071067811865475*cM[0]; 
 
  // ....... Block from weak multiply of uX and m1X  .......... // 
  BigAEM(6,0) = 0.7071067811865475*m1[0]; 
  BigAEM(6,1) = 0.7071067811865475*m1[1]; 
  BigAEM(7,0) = 0.7071067811865475*m1[1]; 
  BigAEM(7,1) = 0.7071067811865475*m1[0]; 
 
  // ....... Block from weak multiply of uY and m0  .......... // 
  BigAEM(2,2) = 0.7071067811865475*m0[0]; 
  BigAEM(2,3) = 0.7071067811865475*m0[1]; 
  BigAEM(3,2) = 0.7071067811865475*m0[1]; 
  BigAEM(3,3) = 0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uY .......... // 
  BigAEM(2,6) = -0.7071067811865475*cM[2]; 
  BigAEM(2,7) = -0.7071067811865475*cM[3]; 
  BigAEM(3,6) = -0.7071067811865475*cM[3]; 
  BigAEM(3,7) = -0.7071067811865475*cM[2]; 
 
  // ....... Block from weak multiply of uY and m1Y  .......... // 
  BigAEM(6,2) = 0.7071067811865475*m1[2]; 
  BigAEM(6,3) = 0.7071067811865475*m1[3]; 
  BigAEM(7,2) = 0.7071067811865475*m1[3]; 
  BigAEM(7,3) = 0.7071067811865475*m1[2]; 
 
  // ....... Block from weak multiply of uZ and m0  .......... // 
  BigAEM(4,4) = 0.7071067811865475*m0[0]; 
  BigAEM(4,5) = 0.7071067811865475*m0[1]; 
  BigAEM(5,4) = 0.7071067811865475*m0[1]; 
  BigAEM(5,5) = 0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uZ .......... // 
  BigAEM(4,6) = -0.7071067811865475*cM[4]; 
  BigAEM(4,7) = -0.7071067811865475*cM[5]; 
  BigAEM(5,6) = -0.7071067811865475*cM[5]; 
  BigAEM(5,7) = -0.7071067811865475*cM[4]; 
 
  // ....... Block from weak multiply of uZ and m1Z  .......... // 
  BigAEM(6,4) = 0.7071067811865475*m1[4]; 
  BigAEM(6,5) = 0.7071067811865475*m1[5]; 
  BigAEM(7,4) = 0.7071067811865475*m1[5]; 
  BigAEM(7,5) = 0.7071067811865475*m1[4]; 
 
  // ....... Block from correction to vtSq .......... // 
  BigAEM(6,6) = 2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(6,7) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(7,6) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(7,7) = 2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
 
  // Set other entries to 0. // 
  BigAEM.block<2,4>(0,2).setZero(); 
  BigAEM.block<4,2>(2,0).setZero(); 
  BigAEM.block<2,2>(2,4).setZero(); 
  BigAEM.block<2,2>(4,2).setZero(); 
 
  // ....... RHS vector is composed of m1 and m2 .......... // 
  bEV << m1[0],m1[1],m1[2],m1[3],m1[4],m1[5],m2[0],m2[1]; 
 
  xEV = BigAEM.colPivHouseholderQr().solve(bEV); 
 
  Eigen::Map<VectorXd>(u,6,1) = xEV.segment<6>(0); 
 
  Eigen::Map<VectorXd>(vtSq,2,1) = xEV.segment<2>(6); 
 
} 
 
void SelfPrimMoments1x3vMax_P2(const double *m0, const double *m1, const double *m2, const double *cM, const double *cE, double *u, double *vtSq) 
{ 
  // m0,m1,m2: moments of the distribution function. 
  // cM, cE: vtSq*cM and vtSq*cE are corrections to u and vtSq, respectively. 
  // u:        velocity. 
  // vtSq:     squared thermal speed, sqrt(T/m). 
 
  // Declare Eigen matrix and vectors for weak division. 
  Eigen::MatrixXd BigAEM(12,12); 
  Eigen::VectorXd bEV(12); 
  Eigen::VectorXd xEV(12); 
 
  // ....... Block from weak multiply of uX and m0  .......... // 
  BigAEM(0,0) = 0.7071067811865475*m0[0]; 
  BigAEM(0,1) = 0.7071067811865475*m0[1]; 
  BigAEM(0,2) = 0.7071067811865475*m0[2]; 
  BigAEM(1,0) = 0.7071067811865475*m0[1]; 
  BigAEM(1,1) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(1,2) = 0.6324555320336759*m0[1]; 
  BigAEM(2,0) = 0.7071067811865475*m0[2]; 
  BigAEM(2,1) = 0.6324555320336759*m0[1]; 
  BigAEM(2,2) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uX .......... // 
  BigAEM(0,9) = -0.7071067811865475*cM[0]; 
  BigAEM(0,10) = -0.7071067811865475*cM[1]; 
  BigAEM(0,11) = -0.7071067811865475*cM[2]; 
  BigAEM(1,9) = -0.7071067811865475*cM[1]; 
  BigAEM(1,10) = (-0.6324555320336759*cM[2])-0.7071067811865475*cM[0]; 
  BigAEM(1,11) = -0.6324555320336759*cM[1]; 
  BigAEM(2,9) = -0.7071067811865475*cM[2]; 
  BigAEM(2,10) = -0.6324555320336759*cM[1]; 
  BigAEM(2,11) = (-0.4517539514526256*cM[2])-0.7071067811865475*cM[0]; 
 
  // ....... Block from weak multiply of uX and m1X  .......... // 
  BigAEM(9,0) = 0.7071067811865475*m1[0]; 
  BigAEM(9,1) = 0.7071067811865475*m1[1]; 
  BigAEM(9,2) = 0.7071067811865475*m1[2]; 
  BigAEM(10,0) = 0.7071067811865475*m1[1]; 
  BigAEM(10,1) = 0.6324555320336759*m1[2]+0.7071067811865475*m1[0]; 
  BigAEM(10,2) = 0.6324555320336759*m1[1]; 
  BigAEM(11,0) = 0.7071067811865475*m1[2]; 
  BigAEM(11,1) = 0.6324555320336759*m1[1]; 
  BigAEM(11,2) = 0.4517539514526256*m1[2]+0.7071067811865475*m1[0]; 
 
  // ....... Block from weak multiply of uY and m0  .......... // 
  BigAEM(3,3) = 0.7071067811865475*m0[0]; 
  BigAEM(3,4) = 0.7071067811865475*m0[1]; 
  BigAEM(3,5) = 0.7071067811865475*m0[2]; 
  BigAEM(4,3) = 0.7071067811865475*m0[1]; 
  BigAEM(4,4) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(4,5) = 0.6324555320336759*m0[1]; 
  BigAEM(5,3) = 0.7071067811865475*m0[2]; 
  BigAEM(5,4) = 0.6324555320336759*m0[1]; 
  BigAEM(5,5) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uY .......... // 
  BigAEM(3,9) = -0.7071067811865475*cM[3]; 
  BigAEM(3,10) = -0.7071067811865475*cM[4]; 
  BigAEM(3,11) = -0.7071067811865475*cM[5]; 
  BigAEM(4,9) = -0.7071067811865475*cM[4]; 
  BigAEM(4,10) = (-0.6324555320336759*cM[5])-0.7071067811865475*cM[3]; 
  BigAEM(4,11) = -0.6324555320336759*cM[4]; 
  BigAEM(5,9) = -0.7071067811865475*cM[5]; 
  BigAEM(5,10) = -0.6324555320336759*cM[4]; 
  BigAEM(5,11) = (-0.4517539514526256*cM[5])-0.7071067811865475*cM[3]; 
 
  // ....... Block from weak multiply of uY and m1Y  .......... // 
  BigAEM(9,3) = 0.7071067811865475*m1[3]; 
  BigAEM(9,4) = 0.7071067811865475*m1[4]; 
  BigAEM(9,5) = 0.7071067811865475*m1[5]; 
  BigAEM(10,3) = 0.7071067811865475*m1[4]; 
  BigAEM(10,4) = 0.6324555320336759*m1[5]+0.7071067811865475*m1[3]; 
  BigAEM(10,5) = 0.6324555320336759*m1[4]; 
  BigAEM(11,3) = 0.7071067811865475*m1[5]; 
  BigAEM(11,4) = 0.6324555320336759*m1[4]; 
  BigAEM(11,5) = 0.4517539514526256*m1[5]+0.7071067811865475*m1[3]; 
 
  // ....... Block from weak multiply of uZ and m0  .......... // 
  BigAEM(6,6) = 0.7071067811865475*m0[0]; 
  BigAEM(6,7) = 0.7071067811865475*m0[1]; 
  BigAEM(6,8) = 0.7071067811865475*m0[2]; 
  BigAEM(7,6) = 0.7071067811865475*m0[1]; 
  BigAEM(7,7) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(7,8) = 0.6324555320336759*m0[1]; 
  BigAEM(8,6) = 0.7071067811865475*m0[2]; 
  BigAEM(8,7) = 0.6324555320336759*m0[1]; 
  BigAEM(8,8) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uZ .......... // 
  BigAEM(6,9) = -0.7071067811865475*cM[6]; 
  BigAEM(6,10) = -0.7071067811865475*cM[7]; 
  BigAEM(6,11) = -0.7071067811865475*cM[8]; 
  BigAEM(7,9) = -0.7071067811865475*cM[7]; 
  BigAEM(7,10) = (-0.6324555320336759*cM[8])-0.7071067811865475*cM[6]; 
  BigAEM(7,11) = -0.6324555320336759*cM[7]; 
  BigAEM(8,9) = -0.7071067811865475*cM[8]; 
  BigAEM(8,10) = -0.6324555320336759*cM[7]; 
  BigAEM(8,11) = (-0.4517539514526256*cM[8])-0.7071067811865475*cM[6]; 
 
  // ....... Block from weak multiply of uZ and m1Z  .......... // 
  BigAEM(9,6) = 0.7071067811865475*m1[6]; 
  BigAEM(9,7) = 0.7071067811865475*m1[7]; 
  BigAEM(9,8) = 0.7071067811865475*m1[8]; 
  BigAEM(10,6) = 0.7071067811865475*m1[7]; 
  BigAEM(10,7) = 0.6324555320336759*m1[8]+0.7071067811865475*m1[6]; 
  BigAEM(10,8) = 0.6324555320336759*m1[7]; 
  BigAEM(11,6) = 0.7071067811865475*m1[8]; 
  BigAEM(11,7) = 0.6324555320336759*m1[7]; 
  BigAEM(11,8) = 0.4517539514526256*m1[8]+0.7071067811865475*m1[6]; 
 
  // ....... Block from correction to vtSq .......... // 
  BigAEM(9,9) = 2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(9,10) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(9,11) = 2.121320343559642*m0[2]-0.7071067811865475*cE[2]; 
  BigAEM(10,9) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(10,10) = 1.897366596101028*m0[2]-0.6324555320336759*cE[2]+2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(10,11) = 1.897366596101028*m0[1]-0.6324555320336759*cE[1]; 
  BigAEM(11,9) = 2.121320343559642*m0[2]-0.7071067811865475*cE[2]; 
  BigAEM(11,10) = 1.897366596101028*m0[1]-0.6324555320336759*cE[1]; 
  BigAEM(11,11) = 1.355261854357877*m0[2]-0.4517539514526256*cE[2]+2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
 
  // Set other entries to 0. // 
  BigAEM.block<3,6>(0,3).setZero(); 
  BigAEM.block<6,3>(3,0).setZero(); 
  BigAEM.block<3,3>(3,6).setZero(); 
  BigAEM.block<3,3>(6,3).setZero(); 
 
  // ....... RHS vector is composed of m1 and m2 .......... // 
  bEV << m1[0],m1[1],m1[2],m1[3],m1[4],m1[5],m1[6],m1[7],m1[8],m2[0],m2[1],m2[2]; 
 
  xEV = BigAEM.colPivHouseholderQr().solve(bEV); 
 
  Eigen::Map<VectorXd>(u,9,1) = xEV.segment<9>(0); 
 
  Eigen::Map<VectorXd>(vtSq,3,1) = xEV.segment<3>(9); 
 
} 
 
void SelfPrimMoments1x3vMax_P3(const double *m0, const double *m1, const double *m2, const double *cM, const double *cE, double *u, double *vtSq) 
{ 
  // m0,m1,m2: moments of the distribution function. 
  // cM, cE: vtSq*cM and vtSq*cE are corrections to u and vtSq, respectively. 
  // u:        velocity. 
  // vtSq:     squared thermal speed, sqrt(T/m). 
 
  // Declare Eigen matrix and vectors for weak division. 
  Eigen::MatrixXd BigAEM(16,16); 
  Eigen::VectorXd bEV(16); 
  Eigen::VectorXd xEV(16); 
 
  // ....... Block from weak multiply of uX and m0  .......... // 
  BigAEM(0,0) = 0.7071067811865475*m0[0]; 
  BigAEM(0,1) = 0.7071067811865475*m0[1]; 
  BigAEM(0,2) = 0.7071067811865475*m0[2]; 
  BigAEM(0,3) = 0.7071067811865475*m0[3]; 
  BigAEM(1,0) = 0.7071067811865475*m0[1]; 
  BigAEM(1,1) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(1,2) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(1,3) = 0.6210590034081186*m0[2]; 
  BigAEM(2,0) = 0.7071067811865475*m0[2]; 
  BigAEM(2,1) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(2,2) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(2,3) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(3,0) = 0.7071067811865475*m0[3]; 
  BigAEM(3,1) = 0.6210590034081186*m0[2]; 
  BigAEM(3,2) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(3,3) = 0.421637021355784*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uX .......... // 
  BigAEM(0,12) = -0.7071067811865475*cM[0]; 
  BigAEM(0,13) = -0.7071067811865475*cM[1]; 
  BigAEM(0,14) = -0.7071067811865475*cM[2]; 
  BigAEM(0,15) = -0.7071067811865475*cM[3]; 
  BigAEM(1,12) = -0.7071067811865475*cM[1]; 
  BigAEM(1,13) = (-0.6324555320336759*cM[2])-0.7071067811865475*cM[0]; 
  BigAEM(1,14) = (-0.6210590034081186*cM[3])-0.6324555320336759*cM[1]; 
  BigAEM(1,15) = -0.6210590034081186*cM[2]; 
  BigAEM(2,12) = -0.7071067811865475*cM[2]; 
  BigAEM(2,13) = (-0.6210590034081186*cM[3])-0.6324555320336759*cM[1]; 
  BigAEM(2,14) = (-0.4517539514526256*cM[2])-0.7071067811865475*cM[0]; 
  BigAEM(2,15) = (-0.421637021355784*cM[3])-0.6210590034081186*cM[1]; 
  BigAEM(3,12) = -0.7071067811865475*cM[3]; 
  BigAEM(3,13) = -0.6210590034081186*cM[2]; 
  BigAEM(3,14) = (-0.421637021355784*cM[3])-0.6210590034081186*cM[1]; 
  BigAEM(3,15) = (-0.421637021355784*cM[2])-0.7071067811865475*cM[0]; 
 
  // ....... Block from weak multiply of uX and m1X  .......... // 
  BigAEM(12,0) = 0.7071067811865475*m1[0]; 
  BigAEM(12,1) = 0.7071067811865475*m1[1]; 
  BigAEM(12,2) = 0.7071067811865475*m1[2]; 
  BigAEM(12,3) = 0.7071067811865475*m1[3]; 
  BigAEM(13,0) = 0.7071067811865475*m1[1]; 
  BigAEM(13,1) = 0.6324555320336759*m1[2]+0.7071067811865475*m1[0]; 
  BigAEM(13,2) = 0.6210590034081186*m1[3]+0.6324555320336759*m1[1]; 
  BigAEM(13,3) = 0.6210590034081186*m1[2]; 
  BigAEM(14,0) = 0.7071067811865475*m1[2]; 
  BigAEM(14,1) = 0.6210590034081186*m1[3]+0.6324555320336759*m1[1]; 
  BigAEM(14,2) = 0.4517539514526256*m1[2]+0.7071067811865475*m1[0]; 
  BigAEM(14,3) = 0.421637021355784*m1[3]+0.6210590034081186*m1[1]; 
  BigAEM(15,0) = 0.7071067811865475*m1[3]; 
  BigAEM(15,1) = 0.6210590034081186*m1[2]; 
  BigAEM(15,2) = 0.421637021355784*m1[3]+0.6210590034081186*m1[1]; 
  BigAEM(15,3) = 0.421637021355784*m1[2]+0.7071067811865475*m1[0]; 
 
  // ....... Block from weak multiply of uY and m0  .......... // 
  BigAEM(4,4) = 0.7071067811865475*m0[0]; 
  BigAEM(4,5) = 0.7071067811865475*m0[1]; 
  BigAEM(4,6) = 0.7071067811865475*m0[2]; 
  BigAEM(4,7) = 0.7071067811865475*m0[3]; 
  BigAEM(5,4) = 0.7071067811865475*m0[1]; 
  BigAEM(5,5) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(5,6) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(5,7) = 0.6210590034081186*m0[2]; 
  BigAEM(6,4) = 0.7071067811865475*m0[2]; 
  BigAEM(6,5) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(6,6) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(6,7) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(7,4) = 0.7071067811865475*m0[3]; 
  BigAEM(7,5) = 0.6210590034081186*m0[2]; 
  BigAEM(7,6) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(7,7) = 0.421637021355784*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uY .......... // 
  BigAEM(4,12) = -0.7071067811865475*cM[4]; 
  BigAEM(4,13) = -0.7071067811865475*cM[5]; 
  BigAEM(4,14) = -0.7071067811865475*cM[6]; 
  BigAEM(4,15) = -0.7071067811865475*cM[7]; 
  BigAEM(5,12) = -0.7071067811865475*cM[5]; 
  BigAEM(5,13) = (-0.6324555320336759*cM[6])-0.7071067811865475*cM[4]; 
  BigAEM(5,14) = (-0.6210590034081186*cM[7])-0.6324555320336759*cM[5]; 
  BigAEM(5,15) = -0.6210590034081186*cM[6]; 
  BigAEM(6,12) = -0.7071067811865475*cM[6]; 
  BigAEM(6,13) = (-0.6210590034081186*cM[7])-0.6324555320336759*cM[5]; 
  BigAEM(6,14) = (-0.4517539514526256*cM[6])-0.7071067811865475*cM[4]; 
  BigAEM(6,15) = (-0.421637021355784*cM[7])-0.6210590034081186*cM[5]; 
  BigAEM(7,12) = -0.7071067811865475*cM[7]; 
  BigAEM(7,13) = -0.6210590034081186*cM[6]; 
  BigAEM(7,14) = (-0.421637021355784*cM[7])-0.6210590034081186*cM[5]; 
  BigAEM(7,15) = (-0.421637021355784*cM[6])-0.7071067811865475*cM[4]; 
 
  // ....... Block from weak multiply of uY and m1Y  .......... // 
  BigAEM(12,4) = 0.7071067811865475*m1[4]; 
  BigAEM(12,5) = 0.7071067811865475*m1[5]; 
  BigAEM(12,6) = 0.7071067811865475*m1[6]; 
  BigAEM(12,7) = 0.7071067811865475*m1[7]; 
  BigAEM(13,4) = 0.7071067811865475*m1[5]; 
  BigAEM(13,5) = 0.6324555320336759*m1[6]+0.7071067811865475*m1[4]; 
  BigAEM(13,6) = 0.6210590034081186*m1[7]+0.6324555320336759*m1[5]; 
  BigAEM(13,7) = 0.6210590034081186*m1[6]; 
  BigAEM(14,4) = 0.7071067811865475*m1[6]; 
  BigAEM(14,5) = 0.6210590034081186*m1[7]+0.6324555320336759*m1[5]; 
  BigAEM(14,6) = 0.4517539514526256*m1[6]+0.7071067811865475*m1[4]; 
  BigAEM(14,7) = 0.421637021355784*m1[7]+0.6210590034081186*m1[5]; 
  BigAEM(15,4) = 0.7071067811865475*m1[7]; 
  BigAEM(15,5) = 0.6210590034081186*m1[6]; 
  BigAEM(15,6) = 0.421637021355784*m1[7]+0.6210590034081186*m1[5]; 
  BigAEM(15,7) = 0.421637021355784*m1[6]+0.7071067811865475*m1[4]; 
 
  // ....... Block from weak multiply of uZ and m0  .......... // 
  BigAEM(8,8) = 0.7071067811865475*m0[0]; 
  BigAEM(8,9) = 0.7071067811865475*m0[1]; 
  BigAEM(8,10) = 0.7071067811865475*m0[2]; 
  BigAEM(8,11) = 0.7071067811865475*m0[3]; 
  BigAEM(9,8) = 0.7071067811865475*m0[1]; 
  BigAEM(9,9) = 0.6324555320336759*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(9,10) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(9,11) = 0.6210590034081186*m0[2]; 
  BigAEM(10,8) = 0.7071067811865475*m0[2]; 
  BigAEM(10,9) = 0.6210590034081186*m0[3]+0.6324555320336759*m0[1]; 
  BigAEM(10,10) = 0.4517539514526256*m0[2]+0.7071067811865475*m0[0]; 
  BigAEM(10,11) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(11,8) = 0.7071067811865475*m0[3]; 
  BigAEM(11,9) = 0.6210590034081186*m0[2]; 
  BigAEM(11,10) = 0.421637021355784*m0[3]+0.6210590034081186*m0[1]; 
  BigAEM(11,11) = 0.421637021355784*m0[2]+0.7071067811865475*m0[0]; 
 
  // ....... Block from correction to uZ .......... // 
  BigAEM(8,12) = -0.7071067811865475*cM[8]; 
  BigAEM(8,13) = -0.7071067811865475*cM[9]; 
  BigAEM(8,14) = -0.7071067811865475*cM[10]; 
  BigAEM(8,15) = -0.7071067811865475*cM[11]; 
  BigAEM(9,12) = -0.7071067811865475*cM[9]; 
  BigAEM(9,13) = (-0.6324555320336759*cM[10])-0.7071067811865475*cM[8]; 
  BigAEM(9,14) = (-0.6210590034081186*cM[11])-0.6324555320336759*cM[9]; 
  BigAEM(9,15) = -0.6210590034081186*cM[10]; 
  BigAEM(10,12) = -0.7071067811865475*cM[10]; 
  BigAEM(10,13) = (-0.6210590034081186*cM[11])-0.6324555320336759*cM[9]; 
  BigAEM(10,14) = (-0.4517539514526256*cM[10])-0.7071067811865475*cM[8]; 
  BigAEM(10,15) = (-0.421637021355784*cM[11])-0.6210590034081186*cM[9]; 
  BigAEM(11,12) = -0.7071067811865475*cM[11]; 
  BigAEM(11,13) = -0.6210590034081186*cM[10]; 
  BigAEM(11,14) = (-0.421637021355784*cM[11])-0.6210590034081186*cM[9]; 
  BigAEM(11,15) = (-0.421637021355784*cM[10])-0.7071067811865475*cM[8]; 
 
  // ....... Block from weak multiply of uZ and m1Z  .......... // 
  BigAEM(12,8) = 0.7071067811865475*m1[8]; 
  BigAEM(12,9) = 0.7071067811865475*m1[9]; 
  BigAEM(12,10) = 0.7071067811865475*m1[10]; 
  BigAEM(12,11) = 0.7071067811865475*m1[11]; 
  BigAEM(13,8) = 0.7071067811865475*m1[9]; 
  BigAEM(13,9) = 0.6324555320336759*m1[10]+0.7071067811865475*m1[8]; 
  BigAEM(13,10) = 0.6210590034081186*m1[11]+0.6324555320336759*m1[9]; 
  BigAEM(13,11) = 0.6210590034081186*m1[10]; 
  BigAEM(14,8) = 0.7071067811865475*m1[10]; 
  BigAEM(14,9) = 0.6210590034081186*m1[11]+0.6324555320336759*m1[9]; 
  BigAEM(14,10) = 0.4517539514526256*m1[10]+0.7071067811865475*m1[8]; 
  BigAEM(14,11) = 0.421637021355784*m1[11]+0.6210590034081186*m1[9]; 
  BigAEM(15,8) = 0.7071067811865475*m1[11]; 
  BigAEM(15,9) = 0.6210590034081186*m1[10]; 
  BigAEM(15,10) = 0.421637021355784*m1[11]+0.6210590034081186*m1[9]; 
  BigAEM(15,11) = 0.421637021355784*m1[10]+0.7071067811865475*m1[8]; 
 
  // ....... Block from correction to vtSq .......... // 
  BigAEM(12,12) = 2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(12,13) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(12,14) = 2.121320343559642*m0[2]-0.7071067811865475*cE[2]; 
  BigAEM(12,15) = 2.121320343559642*m0[3]-0.7071067811865475*cE[3]; 
  BigAEM(13,12) = 2.121320343559642*m0[1]-0.7071067811865475*cE[1]; 
  BigAEM(13,13) = 1.897366596101028*m0[2]-0.6324555320336759*cE[2]+2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(13,14) = 1.863177010224355*m0[3]-0.6210590034081186*cE[3]+1.897366596101028*m0[1]-0.6324555320336759*cE[1]; 
  BigAEM(13,15) = 1.863177010224355*m0[2]-0.6210590034081186*cE[2]; 
  BigAEM(14,12) = 2.121320343559642*m0[2]-0.7071067811865475*cE[2]; 
  BigAEM(14,13) = 1.863177010224355*m0[3]-0.6210590034081186*cE[3]+1.897366596101028*m0[1]-0.6324555320336759*cE[1]; 
  BigAEM(14,14) = 1.355261854357877*m0[2]-0.4517539514526256*cE[2]+2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
  BigAEM(14,15) = 1.264911064067352*m0[3]-0.421637021355784*cE[3]+1.863177010224355*m0[1]-0.6210590034081186*cE[1]; 
  BigAEM(15,12) = 2.121320343559642*m0[3]-0.7071067811865475*cE[3]; 
  BigAEM(15,13) = 1.863177010224355*m0[2]-0.6210590034081186*cE[2]; 
  BigAEM(15,14) = 1.264911064067352*m0[3]-0.421637021355784*cE[3]+1.863177010224355*m0[1]-0.6210590034081186*cE[1]; 
  BigAEM(15,15) = 1.264911064067352*m0[2]-0.421637021355784*cE[2]+2.121320343559642*m0[0]-0.7071067811865475*cE[0]; 
 
  // Set other entries to 0. // 
  BigAEM.block<4,8>(0,4).setZero(); 
  BigAEM.block<8,4>(4,0).setZero(); 
  BigAEM.block<4,4>(4,8).setZero(); 
  BigAEM.block<4,4>(8,4).setZero(); 
 
  // ....... RHS vector is composed of m1 and m2 .......... // 
  bEV << m1[0],m1[1],m1[2],m1[3],m1[4],m1[5],m1[6],m1[7],m1[8],m1[9],m1[10],m1[11],m2[0],m2[1],m2[2],m2[3]; 
 
  xEV = BigAEM.colPivHouseholderQr().solve(bEV); 
 
  Eigen::Map<VectorXd>(u,12,1) = xEV.segment<12>(0); 
 
  Eigen::Map<VectorXd>(vtSq,4,1) = xEV.segment<4>(12); 
 
} 
 
void BoundaryIntegral1x3vMax_F_VX_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += 2.449489742783178*fvmin[2]*dS+2.449489742783178*fvmax[2]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[1] += 1.414213562373095*fvmax[1]*dS-1.414213562373095*fvmin[1]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VX_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += (-3.16227766016838*fvmin[12]*dS)+3.16227766016838*fvmax[12]*dS+2.449489742783178*fvmin[2]*dS+2.449489742783178*fvmax[2]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[1] += 2.449489742783178*fvmin[5]*dS+2.449489742783178*fvmax[5]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[2] += 1.414213562373095*fvmax[11]*dS-1.414213562373095*fvmin[11]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VX_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += 3.741657386773942*fvmin[32]*dS+3.741657386773942*fvmax[32]*dS-3.16227766016838*fvmin[12]*dS+3.16227766016838*fvmax[12]*dS+2.449489742783178*fvmin[2]*dS+2.449489742783178*fvmax[2]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[1] += (-3.16227766016838*fvmin[20]*dS)+3.16227766016838*fvmax[20]*dS+2.449489742783178*fvmin[5]*dS+2.449489742783178*fvmax[5]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[2] += 2.449489742783178*fvmin[19]*dS+2.449489742783178*fvmax[19]*dS-1.414213562373095*fvmin[11]*dS+1.414213562373095*fvmax[11]*dS; 
  out[3] += 1.414213562373095*fvmax[31]*dS-1.414213562373095*fvmin[31]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VX_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += (-2.449489742783178*fvmin[2]*dS*vmin)+1.414213562373095*fvmin[0]*dS*vmin+2.449489742783178*fvmax[2]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 1.414213562373095*fvmin[1]*dS*vmin+1.414213562373095*fvmax[1]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VX_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += 3.16227766016838*fvmin[12]*dS*vmin-2.449489742783178*fvmin[2]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.16227766016838*fvmax[12]*dS*vmax+2.449489742783178*fvmax[2]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += (-2.449489742783178*fvmin[5]*dS*vmin)+1.414213562373095*fvmin[1]*dS*vmin+2.449489742783178*fvmax[5]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += 1.414213562373095*fvmin[11]*dS*vmin+1.414213562373095*fvmax[11]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VX_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[2]*dxv[3]; 
 
  out[0] += (-3.741657386773942*fvmin[32]*dS*vmin)+3.16227766016838*fvmin[12]*dS*vmin-2.449489742783178*fvmin[2]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.741657386773942*fvmax[32]*dS*vmax+3.16227766016838*fvmax[12]*dS*vmax+2.449489742783178*fvmax[2]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 3.16227766016838*fvmin[20]*dS*vmin-2.449489742783178*fvmin[5]*dS*vmin+1.414213562373095*fvmin[1]*dS*vmin+3.16227766016838*fvmax[20]*dS*vmax+2.449489742783178*fvmax[5]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += (-2.449489742783178*fvmin[19]*dS*vmin)+1.414213562373095*fvmin[11]*dS*vmin+2.449489742783178*fvmax[19]*dS*vmax+1.414213562373095*fvmax[11]*dS*vmax; 
  out[3] += 1.414213562373095*fvmin[31]*dS*vmin+1.414213562373095*fvmax[31]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VY_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[2] += 2.449489742783178*fvmin[3]*dS+2.449489742783178*fvmax[3]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[3] += 1.414213562373095*fvmax[1]*dS-1.414213562373095*fvmin[1]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VY_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[3] += (-3.16227766016838*fvmin[13]*dS)+3.16227766016838*fvmax[13]*dS+2.449489742783178*fvmin[3]*dS+2.449489742783178*fvmax[3]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[4] += 2.449489742783178*fvmin[6]*dS+2.449489742783178*fvmax[6]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[5] += 1.414213562373095*fvmax[11]*dS-1.414213562373095*fvmin[11]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VY_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[4] += 3.741657386773942*fvmin[33]*dS+3.741657386773942*fvmax[33]*dS-3.16227766016838*fvmin[13]*dS+3.16227766016838*fvmax[13]*dS+2.449489742783178*fvmin[3]*dS+2.449489742783178*fvmax[3]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[5] += (-3.16227766016838*fvmin[23]*dS)+3.16227766016838*fvmax[23]*dS+2.449489742783178*fvmin[6]*dS+2.449489742783178*fvmax[6]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[6] += 2.449489742783178*fvmin[21]*dS+2.449489742783178*fvmax[21]*dS-1.414213562373095*fvmin[11]*dS+1.414213562373095*fvmax[11]*dS; 
  out[7] += 1.414213562373095*fvmax[31]*dS-1.414213562373095*fvmin[31]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VY_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[0] += (-2.449489742783178*fvmin[3]*dS*vmin)+1.414213562373095*fvmin[0]*dS*vmin+2.449489742783178*fvmax[3]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 1.414213562373095*fvmin[1]*dS*vmin+1.414213562373095*fvmax[1]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VY_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[0] += 3.16227766016838*fvmin[13]*dS*vmin-2.449489742783178*fvmin[3]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.16227766016838*fvmax[13]*dS*vmax+2.449489742783178*fvmax[3]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += (-2.449489742783178*fvmin[6]*dS*vmin)+1.414213562373095*fvmin[1]*dS*vmin+2.449489742783178*fvmax[6]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += 1.414213562373095*fvmin[11]*dS*vmin+1.414213562373095*fvmax[11]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VY_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[3]; 
 
  out[0] += (-3.741657386773942*fvmin[33]*dS*vmin)+3.16227766016838*fvmin[13]*dS*vmin-2.449489742783178*fvmin[3]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.741657386773942*fvmax[33]*dS*vmax+3.16227766016838*fvmax[13]*dS*vmax+2.449489742783178*fvmax[3]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 3.16227766016838*fvmin[23]*dS*vmin-2.449489742783178*fvmin[6]*dS*vmin+1.414213562373095*fvmin[1]*dS*vmin+3.16227766016838*fvmax[23]*dS*vmax+2.449489742783178*fvmax[6]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += (-2.449489742783178*fvmin[21]*dS*vmin)+1.414213562373095*fvmin[11]*dS*vmin+2.449489742783178*fvmax[21]*dS*vmax+1.414213562373095*fvmax[11]*dS*vmax; 
  out[3] += 1.414213562373095*fvmin[31]*dS*vmin+1.414213562373095*fvmax[31]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VZ_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[4] += 2.449489742783178*fvmin[4]*dS+2.449489742783178*fvmax[4]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[5] += 1.414213562373095*fvmax[1]*dS-1.414213562373095*fvmin[1]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VZ_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[6] += (-3.16227766016838*fvmin[14]*dS)+3.16227766016838*fvmax[14]*dS+2.449489742783178*fvmin[4]*dS+2.449489742783178*fvmax[4]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[7] += 2.449489742783178*fvmin[8]*dS+2.449489742783178*fvmax[8]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[8] += 1.414213562373095*fvmax[11]*dS-1.414213562373095*fvmin[11]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_F_VZ_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[8] += 3.741657386773942*fvmin[34]*dS+3.741657386773942*fvmax[34]*dS-3.16227766016838*fvmin[14]*dS+3.16227766016838*fvmax[14]*dS+2.449489742783178*fvmin[4]*dS+2.449489742783178*fvmax[4]*dS-1.414213562373095*fvmin[0]*dS+1.414213562373095*fvmax[0]*dS; 
  out[9] += (-3.16227766016838*fvmin[28]*dS)+3.16227766016838*fvmax[28]*dS+2.449489742783178*fvmin[8]*dS+2.449489742783178*fvmax[8]*dS-1.414213562373095*fvmin[1]*dS+1.414213562373095*fvmax[1]*dS; 
  out[10] += 2.449489742783178*fvmin[25]*dS+2.449489742783178*fvmax[25]*dS-1.414213562373095*fvmin[11]*dS+1.414213562373095*fvmax[11]*dS; 
  out[11] += 1.414213562373095*fvmax[31]*dS-1.414213562373095*fvmin[31]*dS; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VZ_P1(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[5], fvmin[5]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[0] += (-2.449489742783178*fvmin[4]*dS*vmin)+1.414213562373095*fvmin[0]*dS*vmin+2.449489742783178*fvmax[4]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 1.414213562373095*fvmin[1]*dS*vmin+1.414213562373095*fvmax[1]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VZ_P2(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[15], fvmin[15]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[0] += 3.16227766016838*fvmin[14]*dS*vmin-2.449489742783178*fvmin[4]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.16227766016838*fvmax[14]*dS*vmax+2.449489742783178*fvmax[4]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += (-2.449489742783178*fvmin[8]*dS*vmin)+1.414213562373095*fvmin[1]*dS*vmin+2.449489742783178*fvmax[8]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += 1.414213562373095*fvmin[11]*dS*vmin+1.414213562373095*fvmax[11]*dS*vmax; 
 
} 
 
void BoundaryIntegral1x3vMax_vF_VZ_P3(const double vmin, const double vmax, const double *dxv, const double *fvmin, const double *fvmax, double *out) 
{ 
  // vmax, vmin:         maximum and minimum velocity of the velocity grid. 
  // dxv[4]:             cell length in each direciton. 
  // fvmax[35], fvmin[35]: distribution function at the velocity boundaries. 
  // out:                int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.25*dxv[1]*dxv[2]; 
 
  out[0] += (-3.741657386773942*fvmin[34]*dS*vmin)+3.16227766016838*fvmin[14]*dS*vmin-2.449489742783178*fvmin[4]*dS*vmin+1.414213562373095*fvmin[0]*dS*vmin+3.741657386773942*fvmax[34]*dS*vmax+3.16227766016838*fvmax[14]*dS*vmax+2.449489742783178*fvmax[4]*dS*vmax+1.414213562373095*fvmax[0]*dS*vmax; 
  out[1] += 3.16227766016838*fvmin[28]*dS*vmin-2.449489742783178*fvmin[8]*dS*vmin+1.414213562373095*fvmin[1]*dS*vmin+3.16227766016838*fvmax[28]*dS*vmax+2.449489742783178*fvmax[8]*dS*vmax+1.414213562373095*fvmax[1]*dS*vmax; 
  out[2] += (-2.449489742783178*fvmin[25]*dS*vmin)+1.414213562373095*fvmin[11]*dS*vmin+2.449489742783178*fvmax[25]*dS*vmax+1.414213562373095*fvmax[11]*dS*vmax; 
  out[3] += 1.414213562373095*fvmin[31]*dS*vmin+1.414213562373095*fvmax[31]*dS*vmax; 
 
} 
 