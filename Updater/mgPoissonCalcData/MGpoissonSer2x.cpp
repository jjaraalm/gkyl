#include <MGpoissonModDecl.h> 
 
void MGpoissonProlong2xSer_P1(const double *fldC, double **fldF) 
{ 
  // fldC: coarse-grid field.
  // fldF: fine-grid field in cells pointed to by the stencil.

  double *fldF1 = fldF[0];
  double *fldF2 = fldF[1];
  double *fldF3 = fldF[2];
  double *fldF4 = fldF[3];

  fldF1[0] = 0.75*fldC[3]-0.8660254037844386*fldC[2]-0.8660254037844386*fldC[1]+fldC[0]; 
  fldF1[1] = 0.5*fldC[1]-0.4330127018922193*fldC[3]; 
  fldF1[2] = 0.5*fldC[2]-0.4330127018922193*fldC[3]; 
  fldF1[3] = 0.25*fldC[3]; 

  fldF2[0] = (-0.75*fldC[3])-0.8660254037844386*fldC[2]+0.8660254037844386*fldC[1]+fldC[0]; 
  fldF2[1] = 0.5*fldC[1]-0.4330127018922193*fldC[3]; 
  fldF2[2] = 0.4330127018922193*fldC[3]+0.5*fldC[2]; 
  fldF2[3] = 0.25*fldC[3]; 

  fldF3[0] = (-0.75*fldC[3])+0.8660254037844386*fldC[2]-0.8660254037844386*fldC[1]+fldC[0]; 
  fldF3[1] = 0.4330127018922193*fldC[3]+0.5*fldC[1]; 
  fldF3[2] = 0.5*fldC[2]-0.4330127018922193*fldC[3]; 
  fldF3[3] = 0.25*fldC[3]; 

  fldF4[0] = 0.75*fldC[3]+0.8660254037844386*fldC[2]+0.8660254037844386*fldC[1]+fldC[0]; 
  fldF4[1] = 0.4330127018922193*fldC[3]+0.5*fldC[1]; 
  fldF4[2] = 0.4330127018922193*fldC[3]+0.5*fldC[2]; 
  fldF4[3] = 0.25*fldC[3]; 

}

void MGpoissonRestrict2xSer_P1(double **fldF, double *fldC) 
{ 
  // fldF: fine-grid field in stencils pointed to by the stencil.
  // fldC: coarse-grid field.

  double *fldF1 = fldF[0];
  double *fldF2 = fldF[1];
  double *fldF3 = fldF[2];
  double *fldF4 = fldF[3];

  fldC[0] = 0.25*fldF4[0]+0.25*fldF3[0]+0.25*fldF2[0]+0.25*fldF1[0]; 
  fldC[1] = 0.125*fldF4[1]+0.125*fldF3[1]+0.125*fldF2[1]+0.125*fldF1[1]+0.2165063509461096*fldF4[0]-0.2165063509461096*fldF3[0]+0.2165063509461096*fldF2[0]-0.2165063509461096*fldF1[0]; 
  fldC[2] = 0.125*fldF4[2]+0.125*fldF3[2]+0.125*fldF2[2]+0.125*fldF1[2]+0.2165063509461096*fldF4[0]+0.2165063509461096*fldF3[0]-0.2165063509461096*fldF2[0]-0.2165063509461096*fldF1[0]; 
  fldC[3] = 0.0625*fldF4[3]+0.0625*fldF3[3]+0.0625*fldF2[3]+0.0625*fldF1[3]+0.1082531754730548*fldF4[2]-0.1082531754730548*fldF3[2]+0.1082531754730548*fldF2[2]-0.1082531754730548*fldF1[2]+0.1082531754730548*fldF4[1]+0.1082531754730548*fldF3[1]-0.1082531754730548*fldF2[1]-0.1082531754730548*fldF1[1]+0.1875*fldF4[0]-0.1875*fldF3[0]-0.1875*fldF2[0]+0.1875*fldF1[0]; 

}

void MGpoissonGaussSeidel2xSer_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double *dxUx = dx[1]; 
  double *dxLx = dx[2]; 
  double *dxUy = dx[3]; 
  double *dxLy = dx[4]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxLx[2]; 
  double rdxUx[2]; 
  double rdxLxSq[2]; 
  double rdxUxSq[2]; 
  double rdxLxCu[2]; 
  double rdxUxCu[2]; 
  double rdxLxR4[2]; 
  double rdxUxR4[2]; 
  double rdxLy[2]; 
  double rdxUy[2]; 
  double rdxLySq[2]; 
  double rdxUySq[2]; 
  double rdxLyCu[2]; 
  double rdxUyCu[2]; 
  double rdxLyR4[2]; 
  double rdxUyR4[2]; 
  rdxCp2[0]  = volFac*4.0/(dxC[0]*dxC[0]); 
  rdxLx[0]   = 1.0/dxLx[0]; 
  rdxUx[0]   = 1.0/dxUx[0]; 
  rdxLxSq[0] = rdxLx[0]*rdxLx[0]; 
  rdxUxSq[0] = rdxUx[0]*rdxUx[0]; 
  rdxLxCu[0] = rdxLxSq[0]*rdxLx[0]; 
  rdxUxCu[0] = rdxUxSq[0]*rdxUx[0]; 
  rdxLxR4[0] = rdxLxCu[0]*rdxLx[0]; 
  rdxUxR4[0] = rdxUxCu[0]*rdxUx[0]; 
  rdxLx[1]   = 1.0/dxLx[1]; 
  rdxUx[1]   = 1.0/dxUx[1]; 
  rdxLxSq[1] = rdxLx[1]*rdxLx[1]; 
  rdxUxSq[1] = rdxUx[1]*rdxUx[1]; 
  rdxLxCu[1] = rdxLxSq[1]*rdxLx[1]; 
  rdxUxCu[1] = rdxUxSq[1]*rdxUx[1]; 
  rdxLxR4[1] = rdxLxCu[1]*rdxLx[1]; 
  rdxUxR4[1] = rdxUxCu[1]*rdxUx[1]; 
  rdxCp2[1]  = volFac*4.0/(dxC[1]*dxC[1]); 
  rdxLy[0]   = 1.0/dxLy[0]; 
  rdxUy[0]   = 1.0/dxUy[0]; 
  rdxLySq[0] = rdxLy[0]*rdxLy[0]; 
  rdxUySq[0] = rdxUy[0]*rdxUy[0]; 
  rdxLyCu[0] = rdxLySq[0]*rdxLy[0]; 
  rdxUyCu[0] = rdxUySq[0]*rdxUy[0]; 
  rdxLyR4[0] = rdxLyCu[0]*rdxLy[0]; 
  rdxUyR4[0] = rdxUyCu[0]*rdxUy[0]; 
  rdxLy[1]   = 1.0/dxLy[1]; 
  rdxUy[1]   = 1.0/dxUy[1]; 
  rdxLySq[1] = rdxLy[1]*rdxLy[1]; 
  rdxUySq[1] = rdxUy[1]*rdxUy[1]; 
  rdxLyCu[1] = rdxLySq[1]*rdxLy[1]; 
  rdxUyCu[1] = rdxUySq[1]*rdxUy[1]; 
  rdxLyR4[1] = rdxLyCu[1]*rdxLy[1]; 
  rdxUyR4[1] = rdxUyCu[1]*rdxUy[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((((12300.0*rdxUx[0]-12300.0*rdxLx[0])*rdxUySq[1]+(12300.0*rdxUxSq[0]-12300.0*rdxLxSq[0])*rdxUy[1]+(12300.0*rdxLx[0]-12300.0*rdxUx[0])*rdxLySq[1]+(12300.0*rdxLxSq[0]-12300.0*rdxUxSq[0])*rdxLy[1])*rho[3]+((-831.384387633061*rdxUyCu[1])+((-54871.36958378201*rdxLy[1])-32666.47823074902*rdxUx[0]-32666.47823074902*rdxLx[0])*rdxUySq[1]+(54871.36958378201*rdxLySq[1]-31835.09384311596*rdxUxSq[0]-9630.202490082957*rdxLx[0]*rdxUx[0]-31835.09384311596*rdxLxSq[0])*rdxUy[1]+831.384387633061*rdxLyCu[1]+(32666.47823074902*rdxUx[0]+32666.47823074902*rdxLx[0])*rdxLySq[1]+(31835.09384311596*rdxUxSq[0]+9630.202490082957*rdxLx[0]*rdxUx[0]+31835.09384311596*rdxLxSq[0])*rdxLy[1])*rho[2]+((31835.09384311596*rdxLx[0]-31835.09384311596*rdxUx[0])*rdxUySq[1]+((9630.202490082957*rdxLx[0]-9630.202490082957*rdxUx[0])*rdxLy[1]-32666.47823074902*rdxUxSq[0]+32666.47823074902*rdxLxSq[0])*rdxUy[1]+(31835.09384311596*rdxLx[0]-31835.09384311596*rdxUx[0])*rdxLySq[1]+(32666.47823074902*rdxLxSq[0]-32666.47823074902*rdxUxSq[0])*rdxLy[1]-831.384387633061*rdxUxCu[0]-54871.36958378201*rdxLx[0]*rdxUxSq[0]+54871.36958378201*rdxLxSq[0]*rdxUx[0]+831.384387633061*rdxLxCu[0])*rho[1]+2208.0*rho[0]*rdxUyCu[1]+(150144.0*rho[0]*rdxLy[1]+(88484.0*rdxUx[0]+88484.0*rdxLx[0])*rho[0])*rdxUySq[1]+(150144.0*rho[0]*rdxLySq[1]+(289288.0*rdxUx[0]+289288.0*rdxLx[0])*rho[0]*rdxLy[1]+(88484.0*rdxUxSq[0]+289288.0*rdxLx[0]*rdxUx[0]+88484.0*rdxLxSq[0])*rho[0])*rdxUy[1]+2208.0*rho[0]*rdxLyCu[1]+(88484.0*rdxUx[0]+88484.0*rdxLx[0])*rho[0]*rdxLySq[1]+(88484.0*rdxUxSq[0]+289288.0*rdxLx[0]*rdxUx[0]+88484.0*rdxLxSq[0])*rho[0]*rdxLy[1]+(2208.0*rdxUxCu[0]+150144.0*rdxLx[0]*rdxUxSq[0]+150144.0*rdxLxSq[0]*rdxUx[0]+2208.0*rdxLxCu[0])*rho[0])*volFac+((47400.0*rdxUx[0]-47400.0*rdxLx[0])*rdxUyCu[1]+((20850.0*rdxUx[0]-20850.0*rdxLx[0])*rdxLy[1]+49200.0*rdxUxSq[0]-49200.0*rdxLxSq[0])*rdxUySq[1]+((90450.0*rdxUx[0]-90450.0*rdxLx[0])*rdxLySq[1]+(92250.0*rdxUxSq[0]-92250.0*rdxLxSq[0])*rdxLy[1]+1800.0*rdxUxCu[0]+118800.0*rdxLx[0]*rdxUxSq[0]-118800.0*rdxLxSq[0]*rdxUx[0]-1800.0*rdxLxCu[0])*rdxUy[1])*phiUy[3]+(1800.0*rdxUx[0]*rdxUyCu[1]+(118800.0*rdxUx[0]*rdxLy[1]+49200.0*rdxUxSq[0]+92250.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-118800.0*rdxUx[0]*rdxLySq[1])+47400.0*rdxUxCu[0]+20850.0*rdxLx[0]*rdxUxSq[0]+90450.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-1800.0*rdxUx[0]*rdxLyCu[1]+((-49200.0*rdxUxSq[0])-92250.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-47400.0*rdxUxCu[0])-20850.0*rdxLx[0]*rdxUxSq[0]-90450.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[3]+((90450.0*rdxLx[0]-90450.0*rdxUx[0])*rdxLy[1]*rdxUySq[1]+((20850.0*rdxLx[0]-20850.0*rdxUx[0])*rdxLySq[1]+(92250.0*rdxLxSq[0]-92250.0*rdxUxSq[0])*rdxLy[1])*rdxUy[1]+(47400.0*rdxLx[0]-47400.0*rdxUx[0])*rdxLyCu[1]+(49200.0*rdxLxSq[0]-49200.0*rdxUxSq[0])*rdxLySq[1]+((-1800.0*rdxUxCu[0])-118800.0*rdxLx[0]*rdxUxSq[0]+118800.0*rdxLxSq[0]*rdxUx[0]+1800.0*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-1800.0*rdxLx[0]*rdxUyCu[1])+((-118800.0*rdxLx[0]*rdxLy[1])-92250.0*rdxLx[0]*rdxUx[0]-49200.0*rdxLxSq[0])*rdxUySq[1]+(118800.0*rdxLx[0]*rdxLySq[1]-90450.0*rdxLx[0]*rdxUxSq[0]-20850.0*rdxLxSq[0]*rdxUx[0]-47400.0*rdxLxCu[0])*rdxUy[1]+1800.0*rdxLx[0]*rdxLyCu[1]+(92250.0*rdxLx[0]*rdxUx[0]+49200.0*rdxLxSq[0])*rdxLySq[1]+(90450.0*rdxLx[0]*rdxUxSq[0]+20850.0*rdxLxSq[0]*rdxUx[0]+47400.0*rdxLxCu[0])*rdxLy[1])*phiLx[3]+((-1662.768775266122*rdxUyR4[1])+((-114523.1993964541*rdxLy[1])-67203.57133367243*rdxUx[0]-67203.57133367243*rdxLx[0])*rdxUyCu[1]+((-210548.0961680727*rdxLySq[1])+((-313163.4462624908*rdxUx[0])-313163.4462624908*rdxLx[0])*rdxLy[1]-67931.03267285136*rdxUxSq[0]-304737.0190836682*rdxLx[0]*rdxUx[0]-67931.03267285136*rdxLxSq[0])*rdxUySq[1]+((-3117.691453623978*rdxLyCu[1])+((-124369.9082374832*rdxUx[0])-124369.9082374832*rdxLx[0])*rdxLySq[1]+((-123642.4468983043*rdxUxSq[0])-321589.8734413133*rdxLx[0]*rdxUx[0]-123642.4468983043*rdxLxSq[0])*rdxLy[1]-2390.23011444505*rdxUxCu[0]-162535.6477822634*rdxLx[0]*rdxUxSq[0]-162535.6477822634*rdxLxSq[0]*rdxUx[0]-2390.23011444505*rdxLxCu[0])*rdxUy[1])*phiUy[2]+((-1870.614872174387*rdxUx[0]*rdxUyCu[1])+((-123460.5815635095*rdxUx[0]*rdxLy[1])-46869.29485281381*rdxUxSq[0]-100129.8571855568*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(123460.5815635095*rdxUx[0]*rdxLySq[1]-44998.67998063943*rdxUxCu[0]-21667.95560268665*rdxLx[0]*rdxUxSq[0]-98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+1870.614872174387*rdxUx[0]*rdxLyCu[1]+(46869.29485281381*rdxUxSq[0]+100129.8571855568*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(44998.67998063943*rdxUxCu[0]+21667.95560268665*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[2]+(3117.691453623978*rdxLy[1]*rdxUyCu[1]+(210548.0961680727*rdxLySq[1]+(124369.9082374832*rdxUx[0]+124369.9082374832*rdxLx[0])*rdxLy[1])*rdxUySq[1]+(114523.1993964541*rdxLyCu[1]+(313163.4462624908*rdxUx[0]+313163.4462624908*rdxLx[0])*rdxLySq[1]+(123642.4468983043*rdxUxSq[0]+321589.8734413133*rdxLx[0]*rdxUx[0]+123642.4468983043*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+1662.768775266122*rdxLyR4[1]+(67203.57133367243*rdxUx[0]+67203.57133367243*rdxLx[0])*rdxLyCu[1]+(67931.03267285136*rdxUxSq[0]+304737.0190836682*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*rdxLySq[1]+(2390.23011444505*rdxUxCu[0]+162535.6477822634*rdxLx[0]*rdxUxSq[0]+162535.6477822634*rdxLxSq[0]*rdxUx[0]+2390.23011444505*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-1870.614872174387*rdxLx[0]*rdxUyCu[1])+((-123460.5815635095*rdxLx[0]*rdxLy[1])-100129.8571855568*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxLxSq[0])*rdxUySq[1]+(123460.5815635095*rdxLx[0]*rdxLySq[1]-98259.24231338239*rdxLx[0]*rdxUxSq[0]-21667.95560268665*rdxLxSq[0]*rdxUx[0]-44998.67998063943*rdxLxCu[0])*rdxUy[1]+1870.614872174387*rdxLx[0]*rdxLyCu[1]+(100129.8571855568*rdxLx[0]*rdxUx[0]+46869.29485281381*rdxLxSq[0])*rdxLySq[1]+(98259.24231338239*rdxLx[0]*rdxUxSq[0]+21667.95560268665*rdxLxSq[0]*rdxUx[0]+44998.67998063943*rdxLxCu[0])*rdxLy[1])*phiLx[2]+1584.0*phiUy[0]*rdxUyR4[1]+((109512.0*phiUy[0]+3384.0*phiLy[0])*rdxLy[1]+(44998.67998063943*rdxLx[0]-44998.67998063943*rdxUx[0])*phiUy[1]-2390.23011444505*rdxUx[0]*phiUx[1]+2390.23011444505*rdxLx[0]*phiLx[1]+(64182.0*phiUy[0]+2484.0*phiUx[0])*rdxUx[0]+(64182.0*phiUy[0]+2484.0*phiLx[0])*rdxLx[0])*rdxUyCu[1]+((228312.0*phiUy[0]+228312.0*phiLy[0])*rdxLySq[1]+((21667.95560268665*rdxLx[0]-21667.95560268665*rdxUx[0])*phiUy[1]-162535.6477822634*rdxUx[0]*phiUx[1]+(98259.24231338239*rdxLx[0]-98259.24231338239*rdxUx[0])*phiLy[1]+162535.6477822634*rdxLx[0]*phiLx[1]+(325449.0*phiUy[0]+168912.0*phiUx[0]+134907.0*phiLy[0])*rdxUx[0]+(325449.0*phiUy[0]+134907.0*phiLy[0]+168912.0*phiLx[0])*rdxLx[0])*rdxLy[1]+(46869.29485281381*rdxLxSq[0]-46869.29485281381*rdxUxSq[0])*phiUy[1]+((-67931.03267285136*rdxUxSq[0])-123642.4468983043*rdxLx[0]*rdxUx[0])*phiUx[1]+(123642.4468983043*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*phiLx[1]+(65082.0*phiUy[0]+65082.0*phiUx[0])*rdxUxSq[0]+(315024.0*phiUy[0]+134007.0*phiUx[0]+134007.0*phiLx[0])*rdxLx[0]*rdxUx[0]+(65082.0*phiUy[0]+65082.0*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+((3384.0*phiUy[0]+109512.0*phiLy[0])*rdxLyCu[1]+((98259.24231338239*rdxLx[0]-98259.24231338239*rdxUx[0])*phiUy[1]-162535.6477822634*rdxUx[0]*phiUx[1]+(21667.95560268665*rdxLx[0]-21667.95560268665*rdxUx[0])*phiLy[1]+162535.6477822634*rdxLx[0]*phiLx[1]+(134907.0*phiUy[0]+168912.0*phiUx[0]+325449.0*phiLy[0])*rdxUx[0]+(134907.0*phiUy[0]+325449.0*phiLy[0]+168912.0*phiLx[0])*rdxLx[0])*rdxLySq[1]+((100129.8571855568*rdxLxSq[0]-100129.8571855568*rdxUxSq[0])*phiUy[1]+((-304737.0190836682*rdxUxSq[0])-321589.8734413133*rdxLx[0]*rdxUx[0])*phiUx[1]+(100129.8571855568*rdxLxSq[0]-100129.8571855568*rdxUxSq[0])*phiLy[1]+(321589.8734413133*rdxLx[0]*rdxUx[0]+304737.0190836682*rdxLxSq[0])*phiLx[1]+(134007.0*phiUy[0]+315024.0*phiUx[0]+134007.0*phiLy[0])*rdxUxSq[0]+(335874.0*phiUy[0]+335874.0*phiUx[0]+335874.0*phiLy[0]+335874.0*phiLx[0])*rdxLx[0]*rdxUx[0]+(134007.0*phiUy[0]+134007.0*phiLy[0]+315024.0*phiLx[0])*rdxLxSq[0])*rdxLy[1]+((-1870.614872174387*rdxUxCu[0])-123460.5815635095*rdxLx[0]*rdxUxSq[0]+123460.5815635095*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*phiUy[1]+((-67203.57133367243*rdxUxCu[0])-313163.4462624908*rdxLx[0]*rdxUxSq[0]-124369.9082374832*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(124369.9082374832*rdxLx[0]*rdxUxSq[0]+313163.4462624908*rdxLxSq[0]*rdxUx[0]+67203.57133367243*rdxLxCu[0])*phiLx[1]+(2484.0*phiUy[0]+64182.0*phiUx[0])*rdxUxCu[0]+(168912.0*phiUy[0]+325449.0*phiUx[0]+134907.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(168912.0*phiUy[0]+134907.0*phiUx[0]+325449.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(2484.0*phiUy[0]+64182.0*phiLx[0])*rdxLxCu[0])*rdxUy[1]+1584.0*phiLy[0]*rdxLyR4[1]+((-2390.23011444505*rdxUx[0]*phiUx[1])+(44998.67998063943*rdxLx[0]-44998.67998063943*rdxUx[0])*phiLy[1]+2390.23011444505*rdxLx[0]*phiLx[1]+(2484.0*phiUx[0]+64182.0*phiLy[0])*rdxUx[0]+(64182.0*phiLy[0]+2484.0*phiLx[0])*rdxLx[0])*rdxLyCu[1]+(((-67931.03267285136*rdxUxSq[0])-123642.4468983043*rdxLx[0]*rdxUx[0])*phiUx[1]+(46869.29485281381*rdxLxSq[0]-46869.29485281381*rdxUxSq[0])*phiLy[1]+(123642.4468983043*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*phiLx[1]+(65082.0*phiUx[0]+65082.0*phiLy[0])*rdxUxSq[0]+(134007.0*phiUx[0]+315024.0*phiLy[0]+134007.0*phiLx[0])*rdxLx[0]*rdxUx[0]+(65082.0*phiLy[0]+65082.0*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+(((-67203.57133367243*rdxUxCu[0])-313163.4462624908*rdxLx[0]*rdxUxSq[0]-124369.9082374832*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-1870.614872174387*rdxUxCu[0])-123460.5815635095*rdxLx[0]*rdxUxSq[0]+123460.5815635095*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*phiLy[1]+(124369.9082374832*rdxLx[0]*rdxUxSq[0]+313163.4462624908*rdxLxSq[0]*rdxUx[0]+67203.57133367243*rdxLxCu[0])*phiLx[1]+(64182.0*phiUx[0]+2484.0*phiLy[0])*rdxUxCu[0]+(325449.0*phiUx[0]+168912.0*phiLy[0]+134907.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(134907.0*phiUx[0]+168912.0*phiLy[0]+325449.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(2484.0*phiLy[0]+64182.0*phiLx[0])*rdxLxCu[0])*rdxLy[1]+((-1662.768775266122*rdxUxR4[0])-114523.1993964541*rdxLx[0]*rdxUxCu[0]-210548.0961680727*rdxLxSq[0]*rdxUxSq[0]-3117.691453623978*rdxLxCu[0]*rdxUx[0])*phiUx[1]+(3117.691453623978*rdxLx[0]*rdxUxCu[0]+210548.0961680727*rdxLxSq[0]*rdxUxSq[0]+114523.1993964541*rdxLxCu[0]*rdxUx[0]+1662.768775266122*rdxLxR4[0])*phiLx[1]+1584.0*phiUx[0]*rdxUxR4[0]+(109512.0*phiUx[0]+3384.0*phiLx[0])*rdxLx[0]*rdxUxCu[0]+(228312.0*phiUx[0]+228312.0*phiLx[0])*rdxLxSq[0]*rdxUxSq[0]+(3384.0*phiUx[0]+109512.0*phiLx[0])*rdxLxCu[0]*rdxUx[0]+1584.0*phiLx[0]*rdxLxR4[0])/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[1] = -(1.0*(((415.6921938165305*rdxUyCu[1]+(27435.68479189101*rdxLy[1]+12782.53495985831*rdxUx[0]+12782.53495985831*rdxLx[0])*rdxUySq[1]+((-27435.68479189101*rdxLySq[1])+12366.84276604178*rdxUxSq[0]-2286.307065990918*rdxLx[0]*rdxUx[0]+12366.84276604178*rdxLxSq[0])*rdxUy[1]-415.6921938165305*rdxLyCu[1]+((-12782.53495985831*rdxUx[0])-12782.53495985831*rdxLx[0])*rdxLySq[1]+((-12366.84276604178*rdxUxSq[0])+2286.307065990918*rdxLx[0]*rdxUx[0]-12366.84276604178*rdxLxSq[0])*rdxLy[1])*rho[3]+((31980.0*rdxLx[0]-31980.0*rdxUx[0])*rdxUySq[1]+(31980.0*rdxLxSq[0]-31980.0*rdxUxSq[0])*rdxUy[1]+(31980.0*rdxUx[0]-31980.0*rdxLx[0])*rdxLySq[1]+(31980.0*rdxUxSq[0]-31980.0*rdxLxSq[0])*rdxLy[1])*rho[2]+((-1104.0*rdxUyCu[1])+((-75072.0*rdxLy[1])-35052.0*rdxUx[0]-35052.0*rdxLx[0])*rdxUySq[1]+((-75072.0*rdxLySq[1])+((-141864.0*rdxUx[0])-141864.0*rdxLx[0])*rdxLy[1]-34812.0*rdxUxSq[0]-125784.0*rdxLx[0]*rdxUx[0]-34812.0*rdxLxSq[0])*rdxUy[1]-1104.0*rdxLyCu[1]+((-35052.0*rdxUx[0])-35052.0*rdxLx[0])*rdxLySq[1]+((-34812.0*rdxUxSq[0])-125784.0*rdxLx[0]*rdxUx[0]-34812.0*rdxLxSq[0])*rdxLy[1]-864.0*rdxUxCu[0]-58752.0*rdxLx[0]*rdxUxSq[0]-58752.0*rdxLxSq[0]*rdxUx[0]-864.0*rdxLxCu[0])*rho[1]+(82771.2439921015*rdxUx[0]-82771.2439921015*rdxLx[0])*rho[0]*rdxUySq[1]+((25038.52647421569*rdxUx[0]-25038.52647421569*rdxLx[0])*rho[0]*rdxLy[1]+(84932.84339994747*rdxUxSq[0]-84932.84339994747*rdxLxSq[0])*rho[0])*rdxUy[1]+(82771.2439921015*rdxUx[0]-82771.2439921015*rdxLx[0])*rho[0]*rdxLySq[1]+(84932.84339994747*rdxUxSq[0]-84932.84339994747*rdxLxSq[0])*rho[0]*rdxLy[1]+(2161.599407845958*rdxUxCu[0]+142665.5609178332*rdxLx[0]*rdxUxSq[0]-142665.5609178332*rdxLxSq[0]*rdxUx[0]-2161.599407845958*rdxLxCu[0])*rho[0])*volFac+(1662.768775266122*rdxUyR4[1]+(114523.1993964541*rdxLy[1]+53520.3699538783*rdxUx[0]+53520.3699538783*rdxLx[0])*rdxUyCu[1]+(210548.0961680727*rdxLySq[1]+(307144.569706189*rdxUx[0]+307144.569706189*rdxLx[0])*rdxLy[1]+53728.21605078656*rdxUxSq[0]+276331.3858395386*rdxLx[0]*rdxUx[0]+53728.21605078656*rdxLxSq[0])*rdxUySq[1]+(3117.691453623978*rdxLyCu[1]+(98259.24231338239*rdxUx[0]+98259.24231338239*rdxLx[0])*rdxLySq[1]+(97012.16573193281*rdxUxSq[0]+268329.3111085704*rdxLx[0]*rdxUx[0]+97012.16573193281*rdxLxSq[0])*rdxLy[1]+1870.614872174387*rdxUxCu[0]+127201.8113078583*rdxLx[0]*rdxUxSq[0]+127201.8113078583*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*rdxUy[1])*phiUy[3]+((-727.4613391789284*rdxUx[0]*rdxUyCu[1])+((-48012.44838580926*rdxUx[0]*rdxLy[1])+46869.29485281381*rdxUxSq[0]-91608.1672123179*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(48012.44838580926*rdxUx[0]*rdxLySq[1]+47596.75619199274*rdxUxCu[0]+4001.037365484106*rdxLx[0]*rdxUxSq[0]-90880.70587313897*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+727.4613391789284*rdxUx[0]*rdxLyCu[1]+(91608.1672123179*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxUxSq[0])*rdxLySq[1]+((-47596.75619199274*rdxUxCu[0])-4001.037365484106*rdxLx[0]*rdxUxSq[0]+90880.70587313897*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[3]+((-3117.691453623978*rdxLy[1]*rdxUyCu[1])+(((-98259.24231338239*rdxUx[0])-98259.24231338239*rdxLx[0])*rdxLy[1]-210548.0961680727*rdxLySq[1])*rdxUySq[1]+((-114523.1993964541*rdxLyCu[1])+((-307144.569706189*rdxUx[0])-307144.569706189*rdxLx[0])*rdxLySq[1]+((-97012.16573193281*rdxUxSq[0])-268329.3111085704*rdxLx[0]*rdxUx[0]-97012.16573193281*rdxLxSq[0])*rdxLy[1])*rdxUy[1]-1662.768775266122*rdxLyR4[1]+((-53520.3699538783*rdxUx[0])-53520.3699538783*rdxLx[0])*rdxLyCu[1]+((-53728.21605078656*rdxUxSq[0])-276331.3858395386*rdxLx[0]*rdxUx[0]-53728.21605078656*rdxLxSq[0])*rdxLySq[1]+((-1870.614872174387*rdxUxCu[0])-127201.8113078583*rdxLx[0]*rdxUxSq[0]-127201.8113078583*rdxLxSq[0]*rdxUx[0]-1870.614872174387*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-727.4613391789284*rdxLx[0]*rdxUyCu[1])+((-48012.44838580926*rdxLx[0]*rdxLy[1])-91608.1672123179*rdxLx[0]*rdxUx[0]+46869.29485281381*rdxLxSq[0])*rdxUySq[1]+(48012.44838580926*rdxLx[0]*rdxLySq[1]-90880.70587313897*rdxLx[0]*rdxUxSq[0]+4001.037365484106*rdxLxSq[0]*rdxUx[0]+47596.75619199274*rdxLxCu[0])*rdxUy[1]+727.4613391789284*rdxLx[0]*rdxLyCu[1]+(91608.1672123179*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxLxSq[0])*rdxLySq[1]+(90880.70587313897*rdxLx[0]*rdxUxSq[0]-4001.037365484106*rdxLxSq[0]*rdxUx[0]-47596.75619199274*rdxLxCu[0])*rdxLy[1])*phiLx[3]+((61620.0*rdxLx[0]-61620.0*rdxUx[0])*rdxUyCu[1]+((27105.0*rdxLx[0]-27105.0*rdxUx[0])*rdxLy[1]-63960.0*rdxUxSq[0]+63960.0*rdxLxSq[0])*rdxUySq[1]+((117585.0*rdxLx[0]-117585.0*rdxUx[0])*rdxLySq[1]+(119925.0*rdxLxSq[0]-119925.0*rdxUxSq[0])*rdxLy[1]-2340.0*rdxUxCu[0]-154440.0*rdxLx[0]*rdxUxSq[0]+154440.0*rdxLxSq[0]*rdxUx[0]+2340.0*rdxLxCu[0])*rdxUy[1])*phiUy[2]+(900.0*rdxUx[0]*rdxUyCu[1]+(59400.0*rdxUx[0]*rdxLy[1]-44280.0*rdxUxSq[0]+99630.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-59400.0*rdxUx[0]*rdxLySq[1])-45180.0*rdxUxCu[0]-4950.0*rdxLx[0]*rdxUxSq[0]+98730.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-900.0*rdxUx[0]*rdxLyCu[1]+(44280.0*rdxUxSq[0]-99630.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(45180.0*rdxUxCu[0]+4950.0*rdxLx[0]*rdxUxSq[0]-98730.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[2]+((117585.0*rdxUx[0]-117585.0*rdxLx[0])*rdxLy[1]*rdxUySq[1]+((27105.0*rdxUx[0]-27105.0*rdxLx[0])*rdxLySq[1]+(119925.0*rdxUxSq[0]-119925.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+(61620.0*rdxUx[0]-61620.0*rdxLx[0])*rdxLyCu[1]+(63960.0*rdxUxSq[0]-63960.0*rdxLxSq[0])*rdxLySq[1]+(2340.0*rdxUxCu[0]+154440.0*rdxLx[0]*rdxUxSq[0]-154440.0*rdxLxSq[0]*rdxUx[0]-2340.0*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-900.0*rdxLx[0]*rdxUyCu[1])+((-59400.0*rdxLx[0]*rdxLy[1])-99630.0*rdxLx[0]*rdxUx[0]+44280.0*rdxLxSq[0])*rdxUySq[1]+(59400.0*rdxLx[0]*rdxLySq[1]-98730.0*rdxLx[0]*rdxUxSq[0]+4950.0*rdxLxSq[0]*rdxUx[0]+45180.0*rdxLxCu[0])*rdxUy[1]+900.0*rdxLx[0]*rdxLyCu[1]+(99630.0*rdxLx[0]*rdxUx[0]-44280.0*rdxLxSq[0])*rdxLySq[1]+(98730.0*rdxLx[0]*rdxUxSq[0]-4950.0*rdxLxSq[0]*rdxUx[0]-45180.0*rdxLxCu[0])*rdxLy[1])*phiLx[2]-1584.0*phiUy[1]*rdxUyR4[1]+(((-109512.0*phiUy[1])-3384.0*phiLy[1])*rdxLy[1]+((-51192.0*rdxUx[0])-51192.0*rdxLx[0])*phiUy[1]+966.0*rdxUx[0]*phiUx[1]+966.0*rdxLx[0]*phiLx[1]+(58498.28397483125*phiUy[0]-1195.115057222525*phiUx[0])*rdxUx[0]+(1195.115057222525*phiLx[0]-58498.28397483125*phiUy[0])*rdxLx[0])*rdxUyCu[1]+(((-228312.0*phiUy[1])-228312.0*phiLy[1])*rdxLySq[1]+(((-319194.0*rdxUx[0])-319194.0*rdxLx[0])*phiUy[1]+65688.0*rdxUx[0]*phiUx[1]+((-106542.0*rdxUx[0])-106542.0*rdxLx[0])*phiLy[1]+65688.0*rdxLx[0]*phiLx[1]+(28168.34228349264*phiUy[0]-81267.82389113172*phiUx[0]+127737.0150073971*phiLy[0])*rdxUx[0]+((-28168.34228349264*phiUy[0])-127737.0150073971*phiLy[0]+81267.82389113172*phiLx[0])*rdxLx[0])*rdxLy[1]+((-51552.0*rdxUxSq[0])-287964.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*phiUy[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxUxSq[0])*phiUx[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*phiLx[1]+(60930.08330865796*phiUy[0]+55172.74642429901*phiUx[0])*rdxUxSq[0]+(131062.5525579294*phiLx[0]-131062.5525579294*phiUx[0])*rdxLx[0]*rdxUx[0]+((-60930.08330865796*phiUy[0])-55172.74642429901*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+(((-3384.0*phiUy[1])-109512.0*phiLy[1])*rdxLyCu[1]+(((-106542.0*rdxUx[0])-106542.0*rdxLx[0])*phiUy[1]+65688.0*rdxUx[0]*phiUx[1]+((-319194.0*rdxUx[0])-319194.0*rdxLx[0])*phiLy[1]+65688.0*rdxLx[0]*phiLx[1]+(127737.0150073971*phiUy[0]-81267.82389113172*phiUx[0]+28168.34228349264*phiLy[0])*rdxUx[0]+((-127737.0150073971*phiUy[0])-28168.34228349264*phiLy[0]+81267.82389113172*phiLx[0])*rdxLx[0])*rdxLySq[1]+(((-105102.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0]-105102.0*rdxLxSq[0])*phiUy[1]+(97026.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0])*phiUx[1]+((-105102.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0]-105102.0*rdxLxSq[0])*phiLy[1]+(151236.0*rdxLx[0]*rdxUx[0]+97026.0*rdxLxSq[0])*phiLx[1]+(130168.8143412238*phiUy[0]-125403.9425696018*phiUx[0]+130168.8143412238*phiLy[0])*rdxUxSq[0]+(181740.6271365871*phiLx[0]-181740.6271365871*phiUx[0])*rdxLx[0]*rdxUx[0]+((-130168.8143412238*phiUy[0])-130168.8143412238*phiLy[0]+125403.9425696018*phiLx[0])*rdxLxSq[0])*rdxLy[1]+((-1944.0*rdxUxCu[0])-132192.0*rdxLx[0]*rdxUxSq[0]-132192.0*rdxLxSq[0]*rdxUx[0]-1944.0*rdxLxCu[0])*phiUy[1]+((-61482.0*rdxUxCu[0])+110061.0*rdxLx[0]*rdxUxSq[0]+122403.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(122403.0*rdxLx[0]*rdxUxSq[0]+110061.0*rdxLxSq[0]*rdxUx[0]-61482.0*rdxLxCu[0])*phiLx[1]+(2431.799333826703*phiUy[0]+57864.35337926103*phiUx[0])*rdxUxCu[0]+(160498.7560325623*phiUy[0]-136165.1742370272*phiUx[0]+133234.5442706207*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-160498.7560325623*phiUy[0])-133234.5442706207*phiUx[0]+136165.1742370272*phiLx[0])*rdxLxSq[0]*rdxUx[0]+((-2431.799333826703*phiUy[0])-57864.35337926103*phiLx[0])*rdxLxCu[0])*rdxUy[1]-1584.0*phiLy[1]*rdxLyR4[1]+(966.0*rdxUx[0]*phiUx[1]+((-51192.0*rdxUx[0])-51192.0*rdxLx[0])*phiLy[1]+966.0*rdxLx[0]*phiLx[1]+(58498.28397483125*phiLy[0]-1195.115057222525*phiUx[0])*rdxUx[0]+(1195.115057222525*phiLx[0]-58498.28397483125*phiLy[0])*rdxLx[0])*rdxLyCu[1]+((120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxUxSq[0])*phiUx[1]+((-51552.0*rdxUxSq[0])-287964.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*phiLy[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*phiLx[1]+(55172.74642429901*phiUx[0]+60930.08330865796*phiLy[0])*rdxUxSq[0]+(131062.5525579294*phiLx[0]-131062.5525579294*phiUx[0])*rdxLx[0]*rdxUx[0]+((-60930.08330865796*phiLy[0])-55172.74642429901*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+(((-61482.0*rdxUxCu[0])+110061.0*rdxLx[0]*rdxUxSq[0]+122403.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-1944.0*rdxUxCu[0])-132192.0*rdxLx[0]*rdxUxSq[0]-132192.0*rdxLxSq[0]*rdxUx[0]-1944.0*rdxLxCu[0])*phiLy[1]+(122403.0*rdxLx[0]*rdxUxSq[0]+110061.0*rdxLxSq[0]*rdxUx[0]-61482.0*rdxLxCu[0])*phiLx[1]+(57864.35337926103*phiUx[0]+2431.799333826703*phiLy[0])*rdxUxCu[0]+((-136165.1742370272*phiUx[0])+160498.7560325623*phiLy[0]+133234.5442706207*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-133234.5442706207*phiUx[0])-160498.7560325623*phiLy[0]+136165.1742370272*phiLx[0])*rdxLxSq[0]*rdxUx[0]+((-2431.799333826703*phiLy[0])-57864.35337926103*phiLx[0])*rdxLxCu[0])*rdxLy[1]+((-1584.0*rdxUxR4[0])-103032.0*rdxLx[0]*rdxUxCu[0]+205848.0*rdxLxSq[0]*rdxUxSq[0]+3096.0*rdxLxCu[0]*rdxUx[0])*phiUx[1]+(3096.0*rdxLx[0]*rdxUxCu[0]+205848.0*rdxLxSq[0]*rdxUxSq[0]-103032.0*rdxLxCu[0]*rdxUx[0]-1584.0*rdxLxR4[0])*phiLx[1]+1496.491897739509*phiUx[0]*rdxUxR4[0]+(96897.85037863323*phiUx[0]+3367.106769913895*phiLx[0])*rdxLx[0]*rdxUxCu[0]+(224099.6616864915*phiLx[0]-224099.6616864915*phiUx[0])*rdxLxSq[0]*rdxUxSq[0]+((-3367.106769913895*phiUx[0])-96897.85037863323*phiLx[0])*rdxLxCu[0]*rdxUx[0]-1496.491897739509*phiLx[0]*rdxLxR4[0]))/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[2] = -(1.0*((((12366.84276604178*rdxUx[0]-12366.84276604178*rdxLx[0])*rdxUySq[1]+((2286.307065990918*rdxLx[0]-2286.307065990918*rdxUx[0])*rdxLy[1]+12782.53495985831*rdxUxSq[0]-12782.53495985831*rdxLxSq[0])*rdxUy[1]+(12366.84276604178*rdxUx[0]-12366.84276604178*rdxLx[0])*rdxLySq[1]+(12782.53495985831*rdxUxSq[0]-12782.53495985831*rdxLxSq[0])*rdxLy[1]+415.6921938165305*rdxUxCu[0]+27435.68479189101*rdxLx[0]*rdxUxSq[0]-27435.68479189101*rdxLxSq[0]*rdxUx[0]-415.6921938165305*rdxLxCu[0])*rho[3]+((-864.0*rdxUyCu[1])+((-58752.0*rdxLy[1])-34812.0*rdxUx[0]-34812.0*rdxLx[0])*rdxUySq[1]+((-58752.0*rdxLySq[1])+((-125784.0*rdxUx[0])-125784.0*rdxLx[0])*rdxLy[1]-35052.0*rdxUxSq[0]-141864.0*rdxLx[0]*rdxUx[0]-35052.0*rdxLxSq[0])*rdxUy[1]-864.0*rdxLyCu[1]+((-34812.0*rdxUx[0])-34812.0*rdxLx[0])*rdxLySq[1]+((-35052.0*rdxUxSq[0])-141864.0*rdxLx[0]*rdxUx[0]-35052.0*rdxLxSq[0])*rdxLy[1]-1104.0*rdxUxCu[0]-75072.0*rdxLx[0]*rdxUxSq[0]-75072.0*rdxLxSq[0]*rdxUx[0]-1104.0*rdxLxCu[0])*rho[2]+((31980.0*rdxLx[0]-31980.0*rdxUx[0])*rdxUySq[1]+(31980.0*rdxLxSq[0]-31980.0*rdxUxSq[0])*rdxUy[1]+(31980.0*rdxUx[0]-31980.0*rdxLx[0])*rdxLySq[1]+(31980.0*rdxUxSq[0]-31980.0*rdxLxSq[0])*rdxLy[1])*rho[1]+2161.599407845958*rho[0]*rdxUyCu[1]+(142665.5609178332*rho[0]*rdxLy[1]+(84932.84339994747*rdxUx[0]+84932.84339994747*rdxLx[0])*rho[0])*rdxUySq[1]+((82771.2439921015*rdxUxSq[0]+25038.52647421569*rdxLx[0]*rdxUx[0]+82771.2439921015*rdxLxSq[0])*rho[0]-142665.5609178332*rho[0]*rdxLySq[1])*rdxUy[1]-2161.599407845958*rho[0]*rdxLyCu[1]+((-84932.84339994747*rdxUx[0])-84932.84339994747*rdxLx[0])*rho[0]*rdxLySq[1]+((-82771.2439921015*rdxUxSq[0])-25038.52647421569*rdxLx[0]*rdxUx[0]-82771.2439921015*rdxLxSq[0])*rho[0]*rdxLy[1])*volFac+((47596.75619199274*rdxUx[0]-47596.75619199274*rdxLx[0])*rdxUyCu[1]+((4001.037365484106*rdxUx[0]-4001.037365484106*rdxLx[0])*rdxLy[1]+46869.29485281381*rdxUxSq[0]-46869.29485281381*rdxLxSq[0])*rdxUySq[1]+((90880.70587313897*rdxLx[0]-90880.70587313897*rdxUx[0])*rdxLySq[1]+(91608.1672123179*rdxLxSq[0]-91608.1672123179*rdxUxSq[0])*rdxLy[1]-727.4613391789284*rdxUxCu[0]-48012.44838580926*rdxLx[0]*rdxUxSq[0]+48012.44838580926*rdxLxSq[0]*rdxUx[0]+727.4613391789284*rdxLxCu[0])*rdxUy[1])*phiUy[3]+(1870.614872174387*rdxUx[0]*rdxUyCu[1]+(127201.8113078583*rdxUx[0]*rdxLy[1]+53728.21605078656*rdxUxSq[0]+97012.16573193281*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(127201.8113078583*rdxUx[0]*rdxLySq[1]+(276331.3858395386*rdxUxSq[0]+268329.3111085704*rdxLx[0]*rdxUx[0])*rdxLy[1]+53520.3699538783*rdxUxCu[0]+307144.569706189*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+1870.614872174387*rdxUx[0]*rdxLyCu[1]+(53728.21605078656*rdxUxSq[0]+97012.16573193281*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(53520.3699538783*rdxUxCu[0]+307144.569706189*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxLy[1]+1662.768775266122*rdxUxR4[0]+114523.1993964541*rdxLx[0]*rdxUxCu[0]+210548.0961680727*rdxLxSq[0]*rdxUxSq[0]+3117.691453623978*rdxLxCu[0]*rdxUx[0])*phiUx[3]+((90880.70587313897*rdxLx[0]-90880.70587313897*rdxUx[0])*rdxLy[1]*rdxUySq[1]+((4001.037365484106*rdxUx[0]-4001.037365484106*rdxLx[0])*rdxLySq[1]+(91608.1672123179*rdxLxSq[0]-91608.1672123179*rdxUxSq[0])*rdxLy[1])*rdxUy[1]+(47596.75619199274*rdxUx[0]-47596.75619199274*rdxLx[0])*rdxLyCu[1]+(46869.29485281381*rdxUxSq[0]-46869.29485281381*rdxLxSq[0])*rdxLySq[1]+((-727.4613391789284*rdxUxCu[0])-48012.44838580926*rdxLx[0]*rdxUxSq[0]+48012.44838580926*rdxLxSq[0]*rdxUx[0]+727.4613391789284*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-1870.614872174387*rdxLx[0]*rdxUyCu[1])+((-127201.8113078583*rdxLx[0]*rdxLy[1])-97012.16573193281*rdxLx[0]*rdxUx[0]-53728.21605078656*rdxLxSq[0])*rdxUySq[1]+((-127201.8113078583*rdxLx[0]*rdxLySq[1])+((-268329.3111085704*rdxLx[0]*rdxUx[0])-276331.3858395386*rdxLxSq[0])*rdxLy[1]-98259.24231338239*rdxLx[0]*rdxUxSq[0]-307144.569706189*rdxLxSq[0]*rdxUx[0]-53520.3699538783*rdxLxCu[0])*rdxUy[1]-1870.614872174387*rdxLx[0]*rdxLyCu[1]+((-97012.16573193281*rdxLx[0]*rdxUx[0])-53728.21605078656*rdxLxSq[0])*rdxLySq[1]+((-98259.24231338239*rdxLx[0]*rdxUxSq[0])-307144.569706189*rdxLxSq[0]*rdxUx[0]-53520.3699538783*rdxLxCu[0])*rdxLy[1]-3117.691453623978*rdxLx[0]*rdxUxCu[0]-210548.0961680727*rdxLxSq[0]*rdxUxSq[0]-114523.1993964541*rdxLxCu[0]*rdxUx[0]-1662.768775266122*rdxLxR4[0])*phiLx[3]+((-1584.0*rdxUyR4[1])+((-103032.0*rdxLy[1])-61482.0*rdxUx[0]-61482.0*rdxLx[0])*rdxUyCu[1]+(205848.0*rdxLySq[1]+(110061.0*rdxUx[0]+110061.0*rdxLx[0])*rdxLy[1]-58932.0*rdxUxSq[0]+97026.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*rdxUySq[1]+(3096.0*rdxLyCu[1]+(122403.0*rdxUx[0]+122403.0*rdxLx[0])*rdxLySq[1]+(120273.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0]+120273.0*rdxLxSq[0])*rdxLy[1]+966.0*rdxUxCu[0]+65688.0*rdxLx[0]*rdxUxSq[0]+65688.0*rdxLxSq[0]*rdxUx[0]+966.0*rdxLxCu[0])*rdxUy[1])*phiUy[2]+((-1944.0*rdxUx[0]*rdxUyCu[1])+((-132192.0*rdxUx[0]*rdxLy[1])-51552.0*rdxUxSq[0]-105102.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-132192.0*rdxUx[0]*rdxLySq[1])+((-287964.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0])*rdxLy[1]-51192.0*rdxUxCu[0]-319194.0*rdxLx[0]*rdxUxSq[0]-106542.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-1944.0*rdxUx[0]*rdxLyCu[1]+((-51552.0*rdxUxSq[0])-105102.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-51192.0*rdxUxCu[0])-319194.0*rdxLx[0]*rdxUxSq[0]-106542.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1]-1584.0*rdxUxR4[0]-109512.0*rdxLx[0]*rdxUxCu[0]-228312.0*rdxLxSq[0]*rdxUxSq[0]-3384.0*rdxLxCu[0]*rdxUx[0])*phiUx[2]+(3096.0*rdxLy[1]*rdxUyCu[1]+(205848.0*rdxLySq[1]+(122403.0*rdxUx[0]+122403.0*rdxLx[0])*rdxLy[1])*rdxUySq[1]+((-103032.0*rdxLyCu[1])+(110061.0*rdxUx[0]+110061.0*rdxLx[0])*rdxLySq[1]+(120273.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0]+120273.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]-1584.0*rdxLyR4[1]+((-61482.0*rdxUx[0])-61482.0*rdxLx[0])*rdxLyCu[1]+((-58932.0*rdxUxSq[0])+97026.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*rdxLySq[1]+(966.0*rdxUxCu[0]+65688.0*rdxLx[0]*rdxUxSq[0]+65688.0*rdxLxSq[0]*rdxUx[0]+966.0*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-1944.0*rdxLx[0]*rdxUyCu[1])+((-132192.0*rdxLx[0]*rdxLy[1])-105102.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*rdxUySq[1]+((-132192.0*rdxLx[0]*rdxLySq[1])+((-278064.0*rdxLx[0]*rdxUx[0])-287964.0*rdxLxSq[0])*rdxLy[1]-106542.0*rdxLx[0]*rdxUxSq[0]-319194.0*rdxLxSq[0]*rdxUx[0]-51192.0*rdxLxCu[0])*rdxUy[1]-1944.0*rdxLx[0]*rdxLyCu[1]+((-105102.0*rdxLx[0]*rdxUx[0])-51552.0*rdxLxSq[0])*rdxLySq[1]+((-106542.0*rdxLx[0]*rdxUxSq[0])-319194.0*rdxLxSq[0]*rdxUx[0]-51192.0*rdxLxCu[0])*rdxLy[1]-3384.0*rdxLx[0]*rdxUxCu[0]-228312.0*rdxLxSq[0]*rdxUxSq[0]-109512.0*rdxLxCu[0]*rdxUx[0]-1584.0*rdxLxR4[0])*phiLx[2]+1496.491897739509*phiUy[0]*rdxUyR4[1]+((96897.85037863323*phiUy[0]+3367.106769913895*phiLy[0])*rdxLy[1]+(45180.0*rdxLx[0]-45180.0*rdxUx[0])*phiUy[1]-2340.0*rdxUx[0]*phiUx[1]+2340.0*rdxLx[0]*phiLx[1]+(57864.35337926103*phiUy[0]+2431.799333826703*phiUx[0])*rdxUx[0]+(57864.35337926103*phiUy[0]+2431.799333826703*phiLx[0])*rdxLx[0])*rdxUyCu[1]+((224099.6616864915*phiLy[0]-224099.6616864915*phiUy[0])*rdxLySq[1]+((4950.0*rdxLx[0]-4950.0*rdxUx[0])*phiUy[1]-154440.0*rdxUx[0]*phiUx[1]+(98730.0*rdxLx[0]-98730.0*rdxUx[0])*phiLy[1]+154440.0*rdxLx[0]*phiLx[1]+((-136165.1742370272*phiUy[0])+160498.7560325623*phiUx[0]+133234.5442706207*phiLy[0])*rdxUx[0]+((-136165.1742370272*phiUy[0])+133234.5442706207*phiLy[0]+160498.7560325623*phiLx[0])*rdxLx[0])*rdxLy[1]+(44280.0*rdxLxSq[0]-44280.0*rdxUxSq[0])*phiUy[1]+((-63960.0*rdxUxSq[0])-119925.0*rdxLx[0]*rdxUx[0])*phiUx[1]+(119925.0*rdxLx[0]*rdxUx[0]+63960.0*rdxLxSq[0])*phiLx[1]+(55172.74642429901*phiUy[0]+60930.08330865796*phiUx[0])*rdxUxSq[0]+((-125403.9425696018*phiUy[0])+130168.8143412238*phiUx[0]+130168.8143412238*phiLx[0])*rdxLx[0]*rdxUx[0]+(55172.74642429901*phiUy[0]+60930.08330865796*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+(((-3367.106769913895*phiUy[0])-96897.85037863323*phiLy[0])*rdxLyCu[1]+((98730.0*rdxUx[0]-98730.0*rdxLx[0])*phiUy[1]+154440.0*rdxUx[0]*phiUx[1]+(4950.0*rdxUx[0]-4950.0*rdxLx[0])*phiLy[1]-154440.0*rdxLx[0]*phiLx[1]+((-133234.5442706207*phiUy[0])-160498.7560325623*phiUx[0]+136165.1742370272*phiLy[0])*rdxUx[0]+((-133234.5442706207*phiUy[0])+136165.1742370272*phiLy[0]-160498.7560325623*phiLx[0])*rdxLx[0])*rdxLySq[1]+((99630.0*rdxUxSq[0]-99630.0*rdxLxSq[0])*phiUy[1]+(99630.0*rdxLxSq[0]-99630.0*rdxUxSq[0])*phiLy[1]+(131062.5525579294*phiLy[0]-131062.5525579294*phiUy[0])*rdxUxSq[0]+(181740.6271365871*phiLy[0]-181740.6271365871*phiUy[0])*rdxLx[0]*rdxUx[0]+(131062.5525579294*phiLy[0]-131062.5525579294*phiUy[0])*rdxLxSq[0])*rdxLy[1]+(900.0*rdxUxCu[0]+59400.0*rdxLx[0]*rdxUxSq[0]-59400.0*rdxLxSq[0]*rdxUx[0]-900.0*rdxLxCu[0])*phiUy[1]+((-61620.0*rdxUxCu[0])-27105.0*rdxLx[0]*rdxUxSq[0]-117585.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(117585.0*rdxLx[0]*rdxUxSq[0]+27105.0*rdxLxSq[0]*rdxUx[0]+61620.0*rdxLxCu[0])*phiLx[1]+(58498.28397483125*phiUx[0]-1195.115057222525*phiUy[0])*rdxUxCu[0]+((-81267.82389113172*phiUy[0])+28168.34228349264*phiUx[0]+127737.0150073971*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-81267.82389113172*phiUy[0])+127737.0150073971*phiUx[0]+28168.34228349264*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(58498.28397483125*phiLx[0]-1195.115057222525*phiUy[0])*rdxLxCu[0])*rdxUy[1]-1496.491897739509*phiLy[0]*rdxLyR4[1]+(2340.0*rdxUx[0]*phiUx[1]+(45180.0*rdxUx[0]-45180.0*rdxLx[0])*phiLy[1]-2340.0*rdxLx[0]*phiLx[1]+((-2431.799333826703*phiUx[0])-57864.35337926103*phiLy[0])*rdxUx[0]+((-57864.35337926103*phiLy[0])-2431.799333826703*phiLx[0])*rdxLx[0])*rdxLyCu[1]+((63960.0*rdxUxSq[0]+119925.0*rdxLx[0]*rdxUx[0])*phiUx[1]+(44280.0*rdxUxSq[0]-44280.0*rdxLxSq[0])*phiLy[1]+((-119925.0*rdxLx[0]*rdxUx[0])-63960.0*rdxLxSq[0])*phiLx[1]+((-60930.08330865796*phiUx[0])-55172.74642429901*phiLy[0])*rdxUxSq[0]+((-130168.8143412238*phiUx[0])+125403.9425696018*phiLy[0]-130168.8143412238*phiLx[0])*rdxLx[0]*rdxUx[0]+((-55172.74642429901*phiLy[0])-60930.08330865796*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+((61620.0*rdxUxCu[0]+27105.0*rdxLx[0]*rdxUxSq[0]+117585.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-900.0*rdxUxCu[0])-59400.0*rdxLx[0]*rdxUxSq[0]+59400.0*rdxLxSq[0]*rdxUx[0]+900.0*rdxLxCu[0])*phiLy[1]+((-117585.0*rdxLx[0]*rdxUxSq[0])-27105.0*rdxLxSq[0]*rdxUx[0]-61620.0*rdxLxCu[0])*phiLx[1]+(1195.115057222525*phiLy[0]-58498.28397483125*phiUx[0])*rdxUxCu[0]+((-28168.34228349264*phiUx[0])+81267.82389113172*phiLy[0]-127737.0150073971*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-127737.0150073971*phiUx[0])+81267.82389113172*phiLy[0]-28168.34228349264*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(1195.115057222525*phiLy[0]-58498.28397483125*phiLx[0])*rdxLxCu[0])*rdxLy[1]))/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[3] = (((144.0*rdxUyCu[1]+(9792.0*rdxLy[1]+4612.0*rdxUx[0]+4612.0*rdxLx[0])*rdxUySq[1]+(9792.0*rdxLySq[1]+(21184.0*rdxUx[0]+21184.0*rdxLx[0])*rdxLy[1]+4612.0*rdxUxSq[0]+21184.0*rdxLx[0]*rdxUx[0]+4612.0*rdxLxSq[0])*rdxUy[1]+144.0*rdxLyCu[1]+(4612.0*rdxUx[0]+4612.0*rdxLx[0])*rdxLySq[1]+(4612.0*rdxUxSq[0]+21184.0*rdxLx[0]*rdxUx[0]+4612.0*rdxLxSq[0])*rdxLy[1]+144.0*rdxUxCu[0]+9792.0*rdxLx[0]*rdxUxSq[0]+9792.0*rdxLxSq[0]*rdxUx[0]+144.0*rdxLxCu[0])*rho[3]+((10717.93039723621*rdxLx[0]-10717.93039723621*rdxUx[0])*rdxUySq[1]+((1981.466123858796*rdxUx[0]-1981.466123858796*rdxLx[0])*rdxLy[1]-11078.19696521054*rdxUxSq[0]+11078.19696521054*rdxLxSq[0])*rdxUy[1]+(10717.93039723621*rdxLx[0]-10717.93039723621*rdxUx[0])*rdxLySq[1]+(11078.19696521054*rdxLxSq[0]-11078.19696521054*rdxUxSq[0])*rdxLy[1]-360.2665679743264*rdxUxCu[0]-23777.59348630554*rdxLx[0]*rdxUxSq[0]+23777.59348630554*rdxLxSq[0]*rdxUx[0]+360.2665679743264*rdxLxCu[0])*rho[2]+((-360.2665679743264*rdxUyCu[1])+((-23777.59348630554*rdxLy[1])-11078.19696521054*rdxUx[0]-11078.19696521054*rdxLx[0])*rdxUySq[1]+(23777.59348630554*rdxLySq[1]-10717.93039723621*rdxUxSq[0]+1981.466123858796*rdxLx[0]*rdxUx[0]-10717.93039723621*rdxLxSq[0])*rdxUy[1]+360.2665679743264*rdxLyCu[1]+(11078.19696521054*rdxUx[0]+11078.19696521054*rdxLx[0])*rdxLySq[1]+(10717.93039723621*rdxUxSq[0]-1981.466123858796*rdxLx[0]*rdxUx[0]+10717.93039723621*rdxLxSq[0])*rdxLy[1])*rho[1]+(27716.0*rdxUx[0]-27716.0*rdxLx[0])*rho[0]*rdxUySq[1]+(27716.0*rdxUxSq[0]-27716.0*rdxLxSq[0])*rho[0]*rdxUy[1]+(27716.0*rdxLx[0]-27716.0*rdxUx[0])*rho[0]*rdxLySq[1]+(27716.0*rdxLxSq[0]-27716.0*rdxUxSq[0])*rho[0]*rdxLy[1])*volFac+(528.0*rdxUyR4[1]+(34344.0*rdxLy[1]+15914.0*rdxUx[0]+15914.0*rdxLx[0])*rdxUyCu[1]+((-68616.0*rdxLySq[1])+((-37072.0*rdxUx[0])-37072.0*rdxLx[0])*rdxLy[1]+15134.0*rdxUxSq[0]-41362.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxUySq[1]+((-1032.0*rdxLyCu[1])+((-32056.0*rdxUx[0])-32056.0*rdxLx[0])*rdxLySq[1]+((-31276.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0]-31276.0*rdxLxSq[0])*rdxLy[1]-252.0*rdxUxCu[0]-17136.0*rdxLx[0]*rdxUxSq[0]-17136.0*rdxLxSq[0]*rdxUx[0]-252.0*rdxLxCu[0])*rdxUy[1])*phiUy[3]+((-252.0*rdxUx[0]*rdxUyCu[1])+((-17136.0*rdxUx[0]*rdxLy[1])+15134.0*rdxUxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-17136.0*rdxUx[0]*rdxLySq[1])+((-41362.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0])*rdxLy[1]+15914.0*rdxUxCu[0]-37072.0*rdxLx[0]*rdxUxSq[0]-32056.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-252.0*rdxUx[0]*rdxLyCu[1]+(15134.0*rdxUxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(15914.0*rdxUxCu[0]-37072.0*rdxLx[0]*rdxUxSq[0]-32056.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1]+528.0*rdxUxR4[0]+34344.0*rdxLx[0]*rdxUxCu[0]-68616.0*rdxLxSq[0]*rdxUxSq[0]-1032.0*rdxLxCu[0]*rdxUx[0])*phiUx[3]+((-1032.0*rdxLy[1]*rdxUyCu[1])+(((-32056.0*rdxUx[0])-32056.0*rdxLx[0])*rdxLy[1]-68616.0*rdxLySq[1])*rdxUySq[1]+(34344.0*rdxLyCu[1]+((-37072.0*rdxUx[0])-37072.0*rdxLx[0])*rdxLySq[1]+((-31276.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0]-31276.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+528.0*rdxLyR4[1]+(15914.0*rdxUx[0]+15914.0*rdxLx[0])*rdxLyCu[1]+(15134.0*rdxUxSq[0]-41362.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxLySq[1]+((-252.0*rdxUxCu[0])-17136.0*rdxLx[0]*rdxUxSq[0]-17136.0*rdxLxSq[0]*rdxUx[0]-252.0*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-252.0*rdxLx[0]*rdxUyCu[1])+((-17136.0*rdxLx[0]*rdxLy[1])-31276.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxUySq[1]+((-17136.0*rdxLx[0]*rdxLySq[1])+((-32782.0*rdxLx[0]*rdxUx[0])-41362.0*rdxLxSq[0])*rdxLy[1]-32056.0*rdxLx[0]*rdxUxSq[0]-37072.0*rdxLxSq[0]*rdxUx[0]+15914.0*rdxLxCu[0])*rdxUy[1]-252.0*rdxLx[0]*rdxLyCu[1]+(15134.0*rdxLxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-32056.0*rdxLx[0]*rdxUxSq[0])-37072.0*rdxLxSq[0]*rdxUx[0]+15914.0*rdxLxCu[0])*rdxLy[1]-1032.0*rdxLx[0]*rdxUxCu[0]-68616.0*rdxLxSq[0]*rdxUxSq[0]+34344.0*rdxLxCu[0]*rdxUx[0]+528.0*rdxLxR4[0])*phiLx[3]+((20625.26101653019*rdxLx[0]-20625.26101653019*rdxUx[0])*rdxUyCu[1]+((1733.782858376446*rdxLx[0]-1733.782858376446*rdxUx[0])*rdxLy[1]-20310.02776955265*rdxUxSq[0]+20310.02776955265*rdxLxSq[0])*rdxUySq[1]+((39381.63921169356*rdxUx[0]-39381.63921169356*rdxLx[0])*rdxLySq[1]+(39696.8724586711*rdxUxSq[0]-39696.8724586711*rdxLxSq[0])*rdxLy[1]+315.2332469775357*rdxUxCu[0]+20805.39430051735*rdxLx[0]*rdxUxSq[0]-20805.39430051735*rdxLxSq[0]*rdxUx[0]-315.2332469775357*rdxLxCu[0])*rdxUy[1])*phiUy[2]+(311.7691453623978*rdxUx[0]*rdxUyCu[1]+(21200.30188464305*rdxUx[0]*rdxLy[1]-14130.0704881469*rdxUxSq[0]+34100.61629941605*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(21200.30188464305*rdxUx[0]*rdxLySq[1]+(50323.00416310616*rdxUxSq[0]+41406.40660574158*rdxLx[0]*rdxUx[0])*rdxLy[1]-14940.67026608914*rdxUxCu[0]+45864.70538442387*rdxLx[0]*rdxUxSq[0]+34911.21607735829*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+311.7691453623978*rdxUx[0]*rdxLyCu[1]+(34100.61629941605*rdxLx[0]*rdxUx[0]-14130.0704881469*rdxUxSq[0])*rdxLySq[1]+((-14940.67026608914*rdxUxCu[0])+45864.70538442387*rdxLx[0]*rdxUxSq[0]+34911.21607735829*rdxLxSq[0]*rdxUx[0])*rdxLy[1]-498.8306325798365*rdxUxR4[0]-32299.28345954441*rdxLx[0]*rdxUxCu[0]+74699.88722883051*rdxLxSq[0]*rdxUxSq[0]+1122.368923304632*rdxLxCu[0]*rdxUx[0])*phiUx[2]+((39381.63921169356*rdxUx[0]-39381.63921169356*rdxLx[0])*rdxLy[1]*rdxUySq[1]+((1733.782858376446*rdxLx[0]-1733.782858376446*rdxUx[0])*rdxLySq[1]+(39696.8724586711*rdxUxSq[0]-39696.8724586711*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+(20625.26101653019*rdxLx[0]-20625.26101653019*rdxUx[0])*rdxLyCu[1]+(20310.02776955265*rdxLxSq[0]-20310.02776955265*rdxUxSq[0])*rdxLySq[1]+(315.2332469775357*rdxUxCu[0]+20805.39430051735*rdxLx[0]*rdxUxSq[0]-20805.39430051735*rdxLxSq[0]*rdxUx[0]-315.2332469775357*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-311.7691453623978*rdxLx[0]*rdxUyCu[1])+((-21200.30188464305*rdxLx[0]*rdxLy[1])-34100.61629941605*rdxLx[0]*rdxUx[0]+14130.0704881469*rdxLxSq[0])*rdxUySq[1]+((-21200.30188464305*rdxLx[0]*rdxLySq[1])+((-41406.40660574158*rdxLx[0]*rdxUx[0])-50323.00416310616*rdxLxSq[0])*rdxLy[1]-34911.21607735829*rdxLx[0]*rdxUxSq[0]-45864.70538442387*rdxLxSq[0]*rdxUx[0]+14940.67026608914*rdxLxCu[0])*rdxUy[1]-311.7691453623978*rdxLx[0]*rdxLyCu[1]+(14130.0704881469*rdxLxSq[0]-34100.61629941605*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-34911.21607735829*rdxLx[0]*rdxUxSq[0])-45864.70538442387*rdxLxSq[0]*rdxUx[0]+14940.67026608914*rdxLxCu[0])*rdxLy[1]-1122.368923304632*rdxLx[0]*rdxUxCu[0]-74699.88722883051*rdxLxSq[0]*rdxUxSq[0]+32299.28345954441*rdxLxCu[0]*rdxUx[0]+498.8306325798365*rdxLxR4[0])*phiLx[2]-498.8306325798365*phiUy[1]*rdxUyR4[1]+(((-32299.28345954441*phiUy[1])-1122.368923304632*phiLy[1])*rdxLy[1]+((-14940.67026608914*rdxUx[0])-14940.67026608914*rdxLx[0])*phiUy[1]+315.2332469775357*rdxUx[0]*phiUx[1]+315.2332469775357*rdxLx[0]*phiLx[1]+(19578.0*phiUy[0]-390.0*phiUx[0])*rdxUx[0]+(390.0*phiLx[0]-19578.0*phiUy[0])*rdxLx[0])*rdxUyCu[1]+((74699.88722883051*phiUy[1]-74699.88722883051*phiLy[1])*rdxLySq[1]+((45864.70538442387*rdxUx[0]+45864.70538442387*rdxLx[0])*phiUy[1]+20805.39430051735*rdxUx[0]*phiUx[1]+((-34911.21607735829*rdxUx[0])-34911.21607735829*rdxLx[0])*phiLy[1]+20805.39430051735*rdxLx[0]*phiLx[1]+(2145.0*phiUy[0]-25740.0*phiUx[0]+42783.0*phiLy[0])*rdxUx[0]+((-2145.0*phiUy[0])-42783.0*phiLy[0]+25740.0*phiLx[0])*rdxLx[0])*rdxLy[1]+((-14130.0704881469*rdxUxSq[0])+50323.00416310616*rdxLx[0]*rdxUx[0]-14130.0704881469*rdxLxSq[0])*phiUy[1]+(39696.8724586711*rdxLx[0]*rdxUx[0]-20310.02776955265*rdxUxSq[0])*phiUx[1]+(39696.8724586711*rdxLx[0]*rdxUx[0]-20310.02776955265*rdxLxSq[0])*phiLx[1]+(19188.0*phiUy[0]+19188.0*phiUx[0])*rdxUxSq[0]+(43173.0*phiLx[0]-43173.0*phiUx[0])*rdxLx[0]*rdxUx[0]+((-19188.0*phiUy[0])-19188.0*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+((1122.368923304632*phiUy[1]+32299.28345954441*phiLy[1])*rdxLyCu[1]+((34911.21607735829*rdxUx[0]+34911.21607735829*rdxLx[0])*phiUy[1]-20805.39430051735*rdxUx[0]*phiUx[1]+((-45864.70538442387*rdxUx[0])-45864.70538442387*rdxLx[0])*phiLy[1]-20805.39430051735*rdxLx[0]*phiLx[1]+((-42783.0*phiUy[0])+25740.0*phiUx[0]-2145.0*phiLy[0])*rdxUx[0]+(42783.0*phiUy[0]+2145.0*phiLy[0]-25740.0*phiLx[0])*rdxLx[0])*rdxLySq[1]+((34100.61629941605*rdxUxSq[0]+41406.40660574158*rdxLx[0]*rdxUx[0]+34100.61629941605*rdxLxSq[0])*phiUy[1]+((-34100.61629941605*rdxUxSq[0])-41406.40660574158*rdxLx[0]*rdxUx[0]-34100.61629941605*rdxLxSq[0])*phiLy[1]+(43173.0*phiLy[0]-43173.0*phiUy[0])*rdxUxSq[0]+(43173.0*phiUy[0]-43173.0*phiLy[0])*rdxLxSq[0])*rdxLy[1]+(311.7691453623978*rdxUxCu[0]+21200.30188464305*rdxLx[0]*rdxUxSq[0]+21200.30188464305*rdxLxSq[0]*rdxUx[0]+311.7691453623978*rdxLxCu[0])*phiUy[1]+((-20625.26101653019*rdxUxCu[0])-1733.782858376446*rdxLx[0]*rdxUxSq[0]+39381.63921169356*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(39381.63921169356*rdxLx[0]*rdxUxSq[0]-1733.782858376446*rdxLxSq[0]*rdxUx[0]-20625.26101653019*rdxLxCu[0])*phiLx[1]+(19578.0*phiUx[0]-390.0*phiUy[0])*rdxUxCu[0]+((-25740.0*phiUy[0])+2145.0*phiUx[0]+42783.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(25740.0*phiUy[0]-42783.0*phiUx[0]-2145.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(390.0*phiUy[0]-19578.0*phiLx[0])*rdxLxCu[0])*rdxUy[1]+498.8306325798365*phiLy[1]*rdxLyR4[1]+((-315.2332469775357*rdxUx[0]*phiUx[1])+(14940.67026608914*rdxUx[0]+14940.67026608914*rdxLx[0])*phiLy[1]-315.2332469775357*rdxLx[0]*phiLx[1]+(390.0*phiUx[0]-19578.0*phiLy[0])*rdxUx[0]+(19578.0*phiLy[0]-390.0*phiLx[0])*rdxLx[0])*rdxLyCu[1]+((20310.02776955265*rdxUxSq[0]-39696.8724586711*rdxLx[0]*rdxUx[0])*phiUx[1]+(14130.0704881469*rdxUxSq[0]-50323.00416310616*rdxLx[0]*rdxUx[0]+14130.0704881469*rdxLxSq[0])*phiLy[1]+(20310.02776955265*rdxLxSq[0]-39696.8724586711*rdxLx[0]*rdxUx[0])*phiLx[1]+((-19188.0*phiUx[0])-19188.0*phiLy[0])*rdxUxSq[0]+(43173.0*phiUx[0]-43173.0*phiLx[0])*rdxLx[0]*rdxUx[0]+(19188.0*phiLy[0]+19188.0*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+((20625.26101653019*rdxUxCu[0]+1733.782858376446*rdxLx[0]*rdxUxSq[0]-39381.63921169356*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-311.7691453623978*rdxUxCu[0])-21200.30188464305*rdxLx[0]*rdxUxSq[0]-21200.30188464305*rdxLxSq[0]*rdxUx[0]-311.7691453623978*rdxLxCu[0])*phiLy[1]+((-39381.63921169356*rdxLx[0]*rdxUxSq[0])+1733.782858376446*rdxLxSq[0]*rdxUx[0]+20625.26101653019*rdxLxCu[0])*phiLx[1]+(390.0*phiLy[0]-19578.0*phiUx[0])*rdxUxCu[0]+((-2145.0*phiUx[0])+25740.0*phiLy[0]-42783.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(42783.0*phiUx[0]-25740.0*phiLy[0]+2145.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(19578.0*phiLx[0]-390.0*phiLy[0])*rdxLxCu[0])*rdxLy[1])/(48.0*rdxUyR4[1]+(6432.0*rdxLy[1]+3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxUyCu[1]+(215568.0*rdxLySq[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLy[1]+6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxUySq[1]+(6432.0*rdxLyCu[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLySq[1]+(225546.0*rdxUxSq[0]+470072.0*rdxLx[0]*rdxUx[0]+225546.0*rdxLxSq[0])*rdxLy[1]+3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxUy[1]+48.0*rdxLyR4[1]+(3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxLyCu[1]+(6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxLySq[1]+(3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxLy[1]+48.0*rdxUxR4[0]+6432.0*rdxLx[0]*rdxUxCu[0]+215568.0*rdxLxSq[0]*rdxUxSq[0]+6432.0*rdxLxCu[0]*rdxUx[0]+48.0*rdxLxR4[0]); 

}

void MGpoissonGaussSeidel2xSer_LxDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((1.732050807568877*rdxCp2Sq[0]*rho[1]+6.0*rho[0]*rdxCp2Sq[1]+50.0*rdxCp2Sq[0]*rho[0])*volFac-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-20.78460969082652*rdxCp2R4[1])-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(20.78460969082652*rdxCp2R4[1]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(18.0*phiUy[0]+18.0*phiLy[0])*rdxCp2R4[1]+(10.39230484541326*rdxCp2Sq[0]*phiUy[1]-20.78460969082652*rdxCp2Sq[0]*phiUx[1]+10.39230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiUy[0]+18.0*phiUx[0]+150.0*phiLy[0]+144.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-207.8460969082653*rdxCp2R4[0]*phiUx[1]+(180.0*phiUx[0]+960.0*bcVals[0])*rdxCp2R4[0])/(36.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+420.0*rdxCp2R4[0]); 
  phiC[1] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[1]+17.32050807568877*rdxCp2Sq[0]*rho[0])*volFac+((-41.56921938165305*rdxCp2R4[1])-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(41.56921938165305*rdxCp2R4[1]+62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*phiUy[1]+36.0*phiLy[1])*rdxCp2R4[1]+(54.0*rdxCp2Sq[0]*phiUy[1]-120.0*rdxCp2Sq[0]*phiUx[1]+54.0*rdxCp2Sq[0]*phiLy[1]+(51.96152422706631*phiUy[0]+103.9230484541326*phiUx[0]+51.96152422706631*phiLy[0]-831.384387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-240.0*rdxCp2R4[0]*phiUx[1]+(207.8460969082653*phiUx[0]-831.384387633061*bcVals[0])*rdxCp2R4[0])/(72.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[2] = ((1.732050807568877*rdxCp2Sq[0]*rho[3]+(40.0*rdxCp2Sq[1]+50.0*rdxCp2Sq[0])*rho[2])*volFac-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+((-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiUx[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-800.0*rdxCp2R4[1])-1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(240.0*rdxCp2Sq[0]*rdxCp2Sq[1]+360.0*rdxCp2R4[0])*phiUx[2]+((-800.0*rdxCp2R4[1])-1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(692.8203230275509*phiUy[0]-692.8203230275509*phiLy[0])*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUy[1]-60.0*rdxCp2Sq[0]*phiLy[1]+(866.0254037844386*phiUy[0]-866.0254037844386*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[3] = (((40.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[3]+17.32050807568877*rdxCp2Sq[0]*rho[2])*volFac+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])-480.0*rdxCp2R4[0])*phiUx[3]+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+(1385.640646055102*rdxCp2Sq[0]*rdxCp2Sq[1]+415.6921938165305*rdxCp2R4[0])*phiUx[2]-346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(1385.640646055102*phiUy[1]-1385.640646055102*phiLy[1])*rdxCp2R4[1]+(311.7691453623978*rdxCp2Sq[0]*phiUy[1]-311.7691453623978*rdxCp2Sq[0]*phiLy[1]+(300.0*phiUy[0]-300.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_LxNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((5.196152422706631*rdxCp2Sq[0]*rho[1]-9.0*rho[0]*rdxCp2Sq[1]-30.0*rdxCp2Sq[0]*rho[0])*volFac-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(31.17691453623978*rdxCp2R4[1]+103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-31.17691453623978*rdxCp2R4[1])-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-27.0*phiUy[0])-27.0*phiLy[0])*rdxCp2R4[1]+(31.17691453623978*rdxCp2Sq[0]*phiUy[1]+41.56921938165305*rdxCp2Sq[0]*phiUx[1]+31.17691453623978*rdxCp2Sq[0]*phiLy[1]+((-90.0*phiUy[0])-36.0*phiUx[0]-90.0*phiLy[0]+24.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+69.28203230275508*rdxCp2R4[0]*phiUx[1]+(160.0*bcVals[0]-60.0*phiUx[0])*rdxCp2R4[0]))/(54.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+60.0*rdxCp2R4[0]); 
  phiC[1] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[1]-17.32050807568877*rdxCp2Sq[0]*rho[0])*volFac+((-62.35382907247956*rdxCp2R4[1])-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(62.35382907247956*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(54.0*phiUy[1]+54.0*phiLy[1])*rdxCp2R4[1]+(36.0*rdxCp2Sq[0]*phiUy[1]-120.0*rdxCp2Sq[0]*phiUx[1]+36.0*rdxCp2Sq[0]*phiLy[1]+((-51.96152422706631*phiUy[0])+103.9230484541326*phiUx[0]-51.96152422706631*phiLy[0]+138.5640646055102*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+138.5640646055102*bcVals[0]*rdxCp2R4[0])/(108.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[2] = -(1.0*((5.196152422706631*rdxCp2Sq[0]*rho[3]+((-60.0*rdxCp2Sq[1])-30.0*rdxCp2Sq[0])*rho[2])*volFac-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+(554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1]+138.5640646055102*rdxCp2R4[0])*phiUx[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(1200.0*rdxCp2R4[1]+600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-480.0*rdxCp2Sq[0]*rdxCp2Sq[1])-120.0*rdxCp2R4[0])*phiUx[2]+(1200.0*rdxCp2R4[1]+600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(1039.230484541326*phiLy[0]-1039.230484541326*phiUy[0])*rdxCp2R4[1]+(180.0*rdxCp2Sq[0]*phiUy[1]-180.0*rdxCp2Sq[0]*phiLy[1]+(519.6152422706631*phiLy[0]-519.6152422706631*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1]))/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[3] = (((30.0*rdxCp2Sq[1]+3.0*rdxCp2Sq[0])*rho[3]-8.660254037844386*rdxCp2Sq[0]*rho[2])*volFac+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+692.8203230275509*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(1039.230484541326*phiUy[1]-1039.230484541326*phiLy[1])*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUy[1]-103.9230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiLy[0]-150.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_UxDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((1.732050807568877*rdxCp2Sq[0]*rho[1]-6.0*rho[0]*rdxCp2Sq[1]-50.0*rdxCp2Sq[0]*rho[0])*volFac-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(20.78460969082652*rdxCp2R4[1]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-20.78460969082652*rdxCp2R4[1])-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-18.0*phiUy[0])-18.0*phiLy[0])*rdxCp2R4[1]+(10.39230484541326*rdxCp2Sq[0]*phiUy[1]+10.39230484541326*rdxCp2Sq[0]*phiLy[1]-20.78460969082652*rdxCp2Sq[0]*phiLx[1]-144.0*rdxCp2Sq[0]*bcVals[1]+((-150.0*phiUy[0])-150.0*phiLy[0]-18.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-207.8460969082653*rdxCp2R4[0]*phiLx[1]-960.0*rdxCp2R4[0]*bcVals[1]-180.0*phiLx[0]*rdxCp2R4[0]))/(36.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+420.0*rdxCp2R4[0]); 
  phiC[1] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[1]-17.32050807568877*rdxCp2Sq[0]*rho[0])*volFac+((-41.56921938165305*rdxCp2R4[1])-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(41.56921938165305*rdxCp2R4[1]+62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*phiUy[1]+36.0*phiLy[1])*rdxCp2R4[1]+(54.0*rdxCp2Sq[0]*phiUy[1]+54.0*rdxCp2Sq[0]*phiLy[1]-120.0*rdxCp2Sq[0]*phiLx[1]+831.384387633061*rdxCp2Sq[0]*bcVals[1]+((-51.96152422706631*phiUy[0])-51.96152422706631*phiLy[0]-103.9230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-240.0*rdxCp2R4[0]*phiLx[1]+831.384387633061*rdxCp2R4[0]*bcVals[1]-207.8460969082653*phiLx[0]*rdxCp2R4[0])/(72.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[2] = -(1.0*((1.732050807568877*rdxCp2Sq[0]*rho[3]+((-40.0*rdxCp2Sq[1])-50.0*rdxCp2Sq[0])*rho[2])*volFac-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiLx[3]+(800.0*rdxCp2R4[1]+1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(800.0*rdxCp2R4[1]+1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-240.0*rdxCp2Sq[0]*rdxCp2Sq[1])-360.0*rdxCp2R4[0])*phiLx[2]+(692.8203230275509*phiLy[0]-692.8203230275509*phiUy[0])*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUy[1]-60.0*rdxCp2Sq[0]*phiLy[1]+(866.0254037844386*phiLy[0]-866.0254037844386*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1]))/(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[3] = (((40.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[3]-17.32050807568877*rdxCp2Sq[0]*rho[2])*volFac+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])-480.0*rdxCp2R4[0])*phiLx[3]+346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+((-1385.640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiLx[2]+(1385.640646055102*phiUy[1]-1385.640646055102*phiLy[1])*rdxCp2R4[1]+(311.7691453623978*rdxCp2Sq[0]*phiUy[1]-311.7691453623978*rdxCp2Sq[0]*phiLy[1]+(300.0*phiLy[0]-300.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_UxNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((5.196152422706631*rdxCp2Sq[0]*rho[1]+9.0*rho[0]*rdxCp2Sq[1]+30.0*rdxCp2Sq[0]*rho[0])*volFac-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-31.17691453623978*rdxCp2R4[1])-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(31.17691453623978*rdxCp2R4[1]+103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(27.0*phiUy[0]+27.0*phiLy[0])*rdxCp2R4[1]+(31.17691453623978*rdxCp2Sq[0]*phiUy[1]+31.17691453623978*rdxCp2Sq[0]*phiLy[1]+41.56921938165305*rdxCp2Sq[0]*phiLx[1]+24.0*rdxCp2Sq[0]*bcVals[1]+(90.0*phiUy[0]+90.0*phiLy[0]+36.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+69.28203230275508*rdxCp2R4[0]*phiLx[1]+160.0*rdxCp2R4[0]*bcVals[1]+60.0*phiLx[0]*rdxCp2R4[0])/(54.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+60.0*rdxCp2R4[0]); 
  phiC[1] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[1]+17.32050807568877*rdxCp2Sq[0]*rho[0])*volFac+((-62.35382907247956*rdxCp2R4[1])-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(62.35382907247956*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(54.0*phiUy[1]+54.0*phiLy[1])*rdxCp2R4[1]+(36.0*rdxCp2Sq[0]*phiUy[1]+36.0*rdxCp2Sq[0]*phiLy[1]-120.0*rdxCp2Sq[0]*phiLx[1]+138.5640646055102*rdxCp2Sq[0]*bcVals[1]+(51.96152422706631*phiUy[0]+51.96152422706631*phiLy[0]-103.9230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+138.5640646055102*rdxCp2R4[0]*bcVals[1])/(108.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[2] = ((5.196152422706631*rdxCp2Sq[0]*rho[3]+(60.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[2])*volFac-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1]+138.5640646055102*rdxCp2R4[0])*phiLx[3]+((-1200.0*rdxCp2R4[1])-600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-1200.0*rdxCp2R4[1])-600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(480.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiLx[2]+(1039.230484541326*phiUy[0]-1039.230484541326*phiLy[0])*rdxCp2R4[1]+(180.0*rdxCp2Sq[0]*phiUy[1]-180.0*rdxCp2Sq[0]*phiLy[1]+(519.6152422706631*phiUy[0]-519.6152422706631*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[3] = (((30.0*rdxCp2Sq[1]+3.0*rdxCp2Sq[0])*rho[3]+8.660254037844386*rdxCp2Sq[0]*rho[2])*volFac+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]-692.8203230275509*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(1039.230484541326*phiUy[1]-1039.230484541326*phiLy[1])*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUy[1]-103.9230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiUy[0]-150.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_LyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((1.732050807568877*rdxCp2Sq[1]*rho[2]+50.0*rho[0]*rdxCp2Sq[1]+6.0*rdxCp2Sq[0]*rho[0])*volFac-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+((-207.8460969082653*rdxCp2R4[1])-20.78460969082652*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(960.0*rdxCp2R4[1]+144.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+180.0*phiUy[0]*rdxCp2R4[1]+((-173.2050807568877*rdxCp2Sq[0]*phiUx[1])+173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(18.0*phiUy[0]+150.0*phiUx[0]+150.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-20.78460969082652*rdxCp2R4[0]*phiUx[1]+20.78460969082652*rdxCp2R4[0]*phiLx[1]+(18.0*phiUx[0]+18.0*phiLx[0])*rdxCp2R4[0])/(420.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0]); 
  phiC[1] = ((1.732050807568877*rdxCp2Sq[1]*rho[3]+(50.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[1])*volFac+((-415.6921938165305*rdxCp2R4[1])-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+360.0*phiUy[1]*rdxCp2R4[1]+(240.0*rdxCp2Sq[0]*phiUy[1]-1000.0*rdxCp2Sq[0]*phiUx[1]-1000.0*rdxCp2Sq[0]*phiLx[1]+(866.0254037844386*phiUx[0]-866.0254037844386*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-800.0*rdxCp2R4[0]*phiUx[1]-800.0*rdxCp2R4[0]*phiLx[1]+(692.8203230275509*phiUx[0]-692.8203230275509*phiLx[0])*rdxCp2R4[0])/(840.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3200.0*rdxCp2R4[0]); 
  phiC[2] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[2]+17.32050807568877*rho[0]*rdxCp2Sq[1])*volFac+((-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])-41.56921938165305*rdxCp2R4[0])*phiUx[3]+(62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1]+41.56921938165305*rdxCp2R4[0])*phiLx[3]+((-240.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiUx[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiLx[2]+((-831.384387633061*rdxCp2R4[1])-831.384387633061*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+207.8460969082653*phiUy[0]*rdxCp2R4[1]+((-60.0*rdxCp2Sq[0]*phiUx[1])+60.0*rdxCp2Sq[0]*phiLx[1]+(103.9230484541326*phiUy[0]+51.96152422706631*phiUx[0]+51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0]); 
  phiC[3] = (((9.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[3]+17.32050807568877*rdxCp2Sq[1]*rho[1])*volFac+((-480.0*rdxCp2R4[1])-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiUx[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiLx[3]+(311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]+1385.640646055102*rdxCp2R4[0])*phiUx[2]+((-311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1])-1385.640646055102*rdxCp2R4[0])*phiLx[2]+415.6921938165305*phiUy[1]*rdxCp2R4[1]+(1385.640646055102*rdxCp2Sq[0]*phiUy[1]-346.4101615137754*rdxCp2Sq[0]*phiUx[1]-346.4101615137754*rdxCp2Sq[0]*phiLx[1]+(300.0*phiUx[0]-300.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_LyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((5.196152422706631*rdxCp2Sq[1]*rho[2]-30.0*rho[0]*rdxCp2Sq[1]-9.0*rdxCp2Sq[0]*rho[0])*volFac-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+(69.28203230275508*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(160.0*rdxCp2R4[1]+24.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]-60.0*phiUy[0]*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUx[1]-103.9230484541326*rdxCp2Sq[0]*phiLx[1]+((-36.0*phiUy[0])-90.0*phiUx[0]-90.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+31.17691453623978*rdxCp2R4[0]*phiUx[1]-31.17691453623978*rdxCp2R4[0]*phiLx[1]+((-27.0*phiUx[0])-27.0*phiLx[0])*rdxCp2R4[0]))/(60.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0]); 
  phiC[1] = -(1.0*((5.196152422706631*rdxCp2Sq[1]*rho[3]+((-30.0*rdxCp2Sq[1])-60.0*rdxCp2Sq[0])*rho[1])*volFac+(138.5640646055102*rdxCp2R4[1]+554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]-120.0*phiUy[1]*rdxCp2R4[1]+((-480.0*rdxCp2Sq[0]*phiUy[1])+600.0*rdxCp2Sq[0]*phiUx[1]+600.0*rdxCp2Sq[0]*phiLx[1]+(519.6152422706631*phiLx[0]-519.6152422706631*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+1200.0*rdxCp2R4[0]*phiUx[1]+1200.0*rdxCp2R4[0]*phiLx[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiUx[0])*rdxCp2R4[0]))/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 
  phiC[2] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[2]-17.32050807568877*rho[0]*rdxCp2Sq[1])*volFac+((-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])-62.35382907247956*rdxCp2R4[0])*phiUx[3]+(41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1]+62.35382907247956*rdxCp2R4[0])*phiLx[3]-120.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiUx[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiLx[2]+(138.5640646055102*rdxCp2R4[1]+138.5640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+(60.0*rdxCp2Sq[0]*phiUx[1]-60.0*rdxCp2Sq[0]*phiLx[1]+(103.9230484541326*phiUy[0]-51.96152422706631*phiUx[0]-51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0]); 
  phiC[3] = (((3.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[3]-8.660254037844386*rdxCp2Sq[1]*rho[1])*volFac-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3]+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiUx[3]+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiLx[3]+(103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]+1039.230484541326*rdxCp2R4[0])*phiUx[2]+((-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])-1039.230484541326*rdxCp2R4[0])*phiLx[2]+(692.8203230275509*rdxCp2Sq[0]*phiUy[1]+173.2050807568877*rdxCp2Sq[0]*phiUx[1]+173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(150.0*phiLx[0]-150.0*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_UyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((1.732050807568877*rdxCp2Sq[1]*rho[2]-50.0*rho[0]*rdxCp2Sq[1]-6.0*rdxCp2Sq[0]*rho[0])*volFac-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+((-960.0*rdxCp2R4[1])-144.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+((-207.8460969082653*rdxCp2R4[1])-20.78460969082652*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]-180.0*phiLy[0]*rdxCp2R4[1]+(173.2050807568877*rdxCp2Sq[0]*phiUx[1]-173.2050807568877*rdxCp2Sq[0]*phiLx[1]+((-150.0*phiUx[0])-18.0*phiLy[0]-150.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+20.78460969082652*rdxCp2R4[0]*phiUx[1]-20.78460969082652*rdxCp2R4[0]*phiLx[1]+((-18.0*phiUx[0])-18.0*phiLx[0])*rdxCp2R4[0]))/(420.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0]); 
  phiC[1] = -(1.0*((1.732050807568877*rdxCp2Sq[1]*rho[3]+((-50.0*rdxCp2Sq[1])-40.0*rdxCp2Sq[0])*rho[1])*volFac-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+((-415.6921938165305*rdxCp2R4[1])-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]-360.0*phiLy[1]*rdxCp2R4[1]+(1000.0*rdxCp2Sq[0]*phiUx[1]-240.0*rdxCp2Sq[0]*phiLy[1]+1000.0*rdxCp2Sq[0]*phiLx[1]+(866.0254037844386*phiLx[0]-866.0254037844386*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+800.0*rdxCp2R4[0]*phiUx[1]+800.0*rdxCp2R4[0]*phiLx[1]+(692.8203230275509*phiLx[0]-692.8203230275509*phiUx[0])*rdxCp2R4[0]))/(840.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3200.0*rdxCp2R4[0]); 
  phiC[2] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[2]-17.32050807568877*rho[0]*rdxCp2Sq[1])*volFac+((-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])-41.56921938165305*rdxCp2R4[0])*phiUx[3]+(62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1]+41.56921938165305*rdxCp2R4[0])*phiLx[3]+(831.384387633061*rdxCp2R4[1]+831.384387633061*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiUx[2]+((-240.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiLx[2]-207.8460969082653*phiLy[0]*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUx[1]-60.0*rdxCp2Sq[0]*phiLx[1]+((-51.96152422706631*phiUx[0])-103.9230484541326*phiLy[0]-51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0]); 
  phiC[3] = (((9.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[3]-17.32050807568877*rdxCp2Sq[1]*rho[1])*volFac+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiUx[3]+((-480.0*rdxCp2R4[1])-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiLx[3]+(311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]+1385.640646055102*rdxCp2R4[0])*phiUx[2]+((-311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1])-1385.640646055102*rdxCp2R4[0])*phiLx[2]-415.6921938165305*phiLy[1]*rdxCp2R4[1]+(346.4101615137754*rdxCp2Sq[0]*phiUx[1]-1385.640646055102*rdxCp2Sq[0]*phiLy[1]+346.4101615137754*rdxCp2Sq[0]*phiLx[1]+(300.0*phiLx[0]-300.0*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_UyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((5.196152422706631*rdxCp2Sq[1]*rho[2]+30.0*rho[0]*rdxCp2Sq[1]+9.0*rdxCp2Sq[0]*rho[0])*volFac-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+(160.0*rdxCp2R4[1]+24.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+(69.28203230275508*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+60.0*phiLy[0]*rdxCp2R4[1]+((-103.9230484541326*rdxCp2Sq[0]*phiUx[1])+103.9230484541326*rdxCp2Sq[0]*phiLx[1]+(90.0*phiUx[0]+36.0*phiLy[0]+90.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-31.17691453623978*rdxCp2R4[0]*phiUx[1]+31.17691453623978*rdxCp2R4[0]*phiLx[1]+(27.0*phiUx[0]+27.0*phiLx[0])*rdxCp2R4[0])/(60.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0]); 
  phiC[1] = ((5.196152422706631*rdxCp2Sq[1]*rho[3]+(30.0*rdxCp2Sq[1]+60.0*rdxCp2Sq[0])*rho[1])*volFac-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+(138.5640646055102*rdxCp2R4[1]+554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+120.0*phiLy[1]*rdxCp2R4[1]+((-600.0*rdxCp2Sq[0]*phiUx[1])+480.0*rdxCp2Sq[0]*phiLy[1]-600.0*rdxCp2Sq[0]*phiLx[1]+(519.6152422706631*phiUx[0]-519.6152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-1200.0*rdxCp2R4[0]*phiUx[1]-1200.0*rdxCp2R4[0]*phiLx[1]+(1039.230484541326*phiUx[0]-1039.230484541326*phiLx[0])*rdxCp2R4[0])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 
  phiC[2] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[2]+17.32050807568877*rho[0]*rdxCp2Sq[1])*volFac+((-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])-62.35382907247956*rdxCp2R4[0])*phiUx[3]+(41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1]+62.35382907247956*rdxCp2R4[0])*phiLx[3]+(138.5640646055102*rdxCp2R4[1]+138.5640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiUx[2]-120.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiLx[2]+((-60.0*rdxCp2Sq[0]*phiUx[1])+60.0*rdxCp2Sq[0]*phiLx[1]+(51.96152422706631*phiUx[0]-103.9230484541326*phiLy[0]+51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0]); 
  phiC[3] = (((3.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[3]+8.660254037844386*rdxCp2Sq[1]*rho[1])*volFac+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiUx[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiLx[3]+(103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]+1039.230484541326*rdxCp2R4[0])*phiUx[2]+((-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])-1039.230484541326*rdxCp2R4[0])*phiLx[2]+((-173.2050807568877*rdxCp2Sq[0]*phiUx[1])-692.8203230275509*rdxCp2Sq[0]*phiLy[1]-173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(150.0*phiUx[0]-150.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 

}

void MGpoissonGaussSeidel2xSer_LxDirichletLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(727.4613391789284*rdxCp2R4[1]+4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[1]+21000.0*rho[0]*rdxCp2R4[1]+130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0]*rho[0])*volFac+((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-87295.36070147139*rdxCp2R6[1])-538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]-72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1]+32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(403200.0*rdxCp2R6[1]+2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]+504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+75600.0*phiUy[0]*rdxCp2R6[1]+(32423.99111768937*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiUx[1]+(466740.0*phiUy[0]+63000.0*phiUx[0]+504000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(4364.768035073569*rdxCp2R4[0]*phiUy[1]-538944.9292831317*rdxCp2R4[0]*phiUx[1]+(63000.0*phiUy[0]+466740.0*phiUx[0]+2519520.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-87295.36070147139*rdxCp2R6[0]*phiUx[1]+(75600.0*phiUx[0]+403200.0*bcVals[0])*rdxCp2R6[0])/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = (((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(21000.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3780.0*rdxCp2R4[0])*rho[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+7274.613391789284*rdxCp2R4[0]*rho[0])*volFac+((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-187200.0*rdxCp2Sq[0]*rdxCp2R4[1])-25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(25200.0*rdxCp2Sq[0]*rdxCp2R4[1]+17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+151200.0*phiUy[1]*rdxCp2R6[1]+(165960.0*rdxCp2Sq[0]*phiUy[1]-420000.0*rdxCp2Sq[0]*phiUx[1]+(162119.9555884469*phiUy[0]+363730.6695894642*phiUx[0]-2909845.356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(22680.0*rdxCp2R4[0]*phiUy[1]-682800.0*rdxCp2R4[0]*phiUx[1]+(21823.84017536785*phiUy[0]+591322.1457040146*phiUx[0]-2627174.664920473*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-100800.0*rdxCp2R6[0]*phiUx[1]+(87295.36070147139*phiUx[0]-349181.4428058856*bcVals[0])*rdxCp2R6[0])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = (((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+(3780.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0])*rho[2]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+7274.613391789284*rho[0]*rdxCp2R4[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiUx[3]+((-100800.0*rdxCp2R6[1])-682800.0*rdxCp2Sq[0]*rdxCp2R4[1]-420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(22680.0*rdxCp2Sq[0]*rdxCp2R4[1]+165960.0*rdxCp2R4[0]*rdxCp2Sq[1]+151200.0*rdxCp2R6[0])*phiUx[2]+((-349181.4428058856*rdxCp2R6[1])-2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]-2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+87295.36070147139*phiUy[0]*rdxCp2R6[1]+(17280.0*rdxCp2Sq[0]*phiUy[1]-25200.0*rdxCp2Sq[0]*phiUx[1]+(591322.1457040146*phiUy[0]+21823.84017536785*phiUx[0]+174590.7214029428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(25200.0*rdxCp2R4[0]*phiUy[1]-187200.0*rdxCp2R4[0]*phiUx[1]+(363730.6695894642*phiUy[0]+162119.9555884469*phiUx[0]+806442.8560040692*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+(640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1]+2424.871130596428*rdxCp2R4[0])*rho[2]+(2424.871130596428*rdxCp2R4[1]+640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiUx[3]+((-33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1])-48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1]+257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]+58196.90713431427*rdxCp2R6[0])*phiUx[2]+(52800.0*rdxCp2Sq[0]*rdxCp2R4[1]-336000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+58196.90713431427*phiUy[1]*rdxCp2R6[1]+(257867.7242308544*rdxCp2Sq[0]*phiUy[1]-48497.42261192856*rdxCp2Sq[0]*phiUx[1]+(28800.0*phiUy[0]+42000.0*phiUx[0]-336000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(43647.6803507357*rdxCp2R4[0]*phiUy[1]-33255.37550532244*rdxCp2R4[0]*phiUx[1]+(42000.0*phiUy[0]+28800.0*phiUx[0]+52800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_LxDirichletLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(207.8460969082653*rdxCp2R6[1]+6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]+13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-1091.192008768392*rdxCp2R6[0])*rho[1]-1200.0*rho[0]*rdxCp2R6[1]-36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-31500.0*rdxCp2R6[0]*rho[0])*volFac+(4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(2771.281292110204*rdxCp2R8[1]+85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]+245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]+145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1]+44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]+97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(6400.0*rdxCp2R8[1]+193440.0*rdxCp2Sq[0]*rdxCp2R6[1]+445120.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-2400.0*phiUy[0]*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUy[1])+4156.921938165305*rdxCp2Sq[0]*phiUx[1]+((-74160.0*phiUy[0])-3600.0*phiUx[0]-28800.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-12262.91971758765*rdxCp2R4[0]*phiUy[1])+149441.3436770427*rdxCp2R4[0]*phiUx[1]+((-212280.0*phiUy[0])-129420.0*phiUx[0]-718560.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-8729.536070147138*rdxCp2R6[0]*phiUy[1])+376617.1275977765*rdxCp2R6[0]*phiUx[1]+((-126000.0*phiUy[0])-326160.0*phiUx[0]-1759680.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0]*phiUx[1]+((-113400.0*phiUx[0])-604800.0*bcVals[0])*rdxCp2R8[0]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(2160.0*rdxCp2Sq[0]*rdxCp2R4[1]+5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1200.0*rdxCp2R6[1])-9480.0*rdxCp2Sq[0]*rdxCp2R4[1]-18450.0*rdxCp2R4[0]*rdxCp2Sq[1]-5670.0*rdxCp2R6[0])*rho[1]-11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-10911.92008768392*rdxCp2R6[0]*rho[0])*volFac+(5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(24000.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(7200.0*rdxCp2Sq[0]*rdxCp2R6[1]+51840.0*rdxCp2R4[0]*rdxCp2R4[1]+51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1]+163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]+29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-4800.0*phiUy[1]*rdxCp2R8[1]+((-49920.0*rdxCp2Sq[0]*phiUy[1])+24000.0*rdxCp2Sq[0]*phiUx[1]+((-20784.60969082652*phiUy[0])-20784.60969082652*phiUx[0]+166276.8775266122*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-134280.0*rdxCp2R4[0]*phiUy[1])+229200.0*rdxCp2R4[0]*phiUx[1]+((-61314.59858793825*phiUy[0])-198493.0225473933*phiUx[0]+1039230.484541326*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-45360.0*rdxCp2R6[0]*phiUy[1])+475200.0*rdxCp2R6[0]*phiUx[1]+((-43647.6803507357*phiUy[0])-411535.2718783651*phiUx[0]+1820731.808916403*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+151200.0*rdxCp2R8[0]*phiUx[1]+(523772.1642088283*bcVals[0]-130943.0410522071*phiUx[0])*rdxCp2R8[0]))/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = (((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+(120.0*rdxCp2R6[1]+3870.0*rdxCp2Sq[0]*rdxCp2R4[1]+15150.0*rdxCp2R4[0]*rdxCp2Sq[1]+15750.0*rdxCp2R6[0])*rho[2]+((-360.0*rdxCp2Sq[0]*rdxCp2R4[1])-885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-346.4101615137754*rho[0]*rdxCp2R6[1]-10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+(1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiUx[3]+((-3600.0*rdxCp2Sq[0]*rdxCp2R6[1])-100800.0*rdxCp2R4[0]*rdxCp2R4[1]-210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R6[1]+25740.0*rdxCp2R4[0]*rdxCp2R4[1]+101520.0*rdxCp2R6[0]*rdxCp2Sq[1]+113400.0*rdxCp2R8[0])*phiUx[2]+(2771.281292110204*rdxCp2R8[1]+87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]+291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]+242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+((-1200.0*rdxCp2Sq[0]*phiUy[1])+1200.0*rdxCp2Sq[0]*phiUx[1]+(3117.691453623978*phiUy[0]-1039.230484541326*phiUx[0]-8313.84387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(43200.0*rdxCp2R4[0]*phiUx[1]+(87295.36070147139*phiUy[0]-37412.29744348773*phiUx[0]-199532.2530319346*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(12600.0*rdxCp2R6[0]*phiUy[1]+93600.0*rdxCp2R6[0]*phiUx[1]+(181865.3347947321*phiUy[0]-81059.97779422344*phiUx[0]-403221.4280020346*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+(727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+5455.960043841962*rdxCp2R6[0])*rho[2]+((-346.4101615137754*rdxCp2R6[1])-1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]-961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiUx[3]+(6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1]-72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1]+78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]+291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0])*phiUx[2]+(20800.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(34641.01615137755*rdxCp2Sq[0]*phiUy[1]+6928.203230275509*rdxCp2Sq[0]*phiUx[1]+((-6000.0*phiUy[0])-6000.0*phiUx[0]+48000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(174590.7214029428*rdxCp2R4[0]*phiUy[1]+49883.06325798365*rdxCp2R4[0]*phiUx[1]+(172800.0*bcVals[0]-43200.0*phiUx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(65471.52052610354*rdxCp2R6[0]*phiUy[1]+49883.06325798365*rdxCp2R6[0]*phiUx[1]+(63000.0*phiUy[0]-43200.0*phiUx[0]-79200.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_LxNeumannLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-1091.192008768392*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1]+6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[1]-31500.0*rho[0]*rdxCp2R6[1]-91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0]*rho[0])*volFac+((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(130943.0410522071*rdxCp2R8[1]+376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]+149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1])-12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-604800.0*rdxCp2R8[1])-1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]-718560.0*rdxCp2R4[0]*rdxCp2R4[1]-28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-113400.0*phiUy[0]*rdxCp2R8[1]+(97271.97335306811*rdxCp2Sq[0]*phiUy[1]+145492.2678357857*rdxCp2Sq[0]*phiUx[1]+((-326160.0*phiUy[0])-126000.0*phiUx[0]+84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(44894.75693218527*rdxCp2R4[0]*phiUy[1]+245119.8302871475*rdxCp2R4[0]*phiUx[1]+((-129420.0*phiUy[0])-212280.0*phiUx[0]+445120.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(1247.076581449591*rdxCp2R6[0]*phiUy[1]+85632.59192620528*rdxCp2R6[0]*phiUx[1]+((-3600.0*phiUy[0])-74160.0*phiUx[0]+193440.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*rdxCp2R8[0]*phiUx[1]+(6400.0*bcVals[0]-2400.0*phiUx[0])*rdxCp2R8[0]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = (((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-885.0*rdxCp2Sq[0]*rdxCp2R4[1])-360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(15750.0*rdxCp2R6[1]+15150.0*rdxCp2Sq[0]*rdxCp2R4[1]+3870.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[1]-21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*rho[0])*volFac+((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiUx[3]+(93600.0*rdxCp2Sq[0]*rdxCp2R6[1]+43200.0*rdxCp2R4[0]*rdxCp2R4[1]+1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(12600.0*rdxCp2Sq[0]*rdxCp2R6[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1])-199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+113400.0*phiUy[1]*rdxCp2R8[1]+(101520.0*rdxCp2Sq[0]*phiUy[1]-210000.0*rdxCp2Sq[0]*phiUx[1]+((-81059.97779422344*phiUy[0])+181865.3347947321*phiUx[0]+242487.1130596428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(25740.0*rdxCp2R4[0]*phiUy[1]-100800.0*rdxCp2R4[0]*phiUx[1]+((-37412.29744348773*phiUy[0])+87295.36070147139*phiUx[0]+291677.3559945989*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(720.0*rdxCp2R6[0]*phiUy[1]-3600.0*rdxCp2R6[0]*phiUx[1]+((-1039.230484541326*phiUy[0])+3117.691453623978*phiUx[0]+87295.36070147139*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*bcVals[0]*rdxCp2R8[0])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+((-5670.0*rdxCp2R6[1])-18450.0*rdxCp2Sq[0]*rdxCp2R4[1]-9480.0*rdxCp2R4[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0])*rho[2]+(5310.0*rdxCp2Sq[0]*rdxCp2R4[1]+2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-10911.92008768392*rho[0]*rdxCp2R6[1]-30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiUx[3]+(151200.0*rdxCp2R8[1]+475200.0*rdxCp2Sq[0]*rdxCp2R6[1]+229200.0*rdxCp2R4[0]*rdxCp2R4[1]+24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-45360.0*rdxCp2Sq[0]*rdxCp2R6[1])-134280.0*rdxCp2R4[0]*rdxCp2R4[1]-49920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiUx[2]+(523772.1642088283*rdxCp2R8[1]+1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]+1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]+166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-130943.0410522071*phiUy[0]*rdxCp2R8[1]+(51840.0*rdxCp2Sq[0]*phiUy[1]+50400.0*rdxCp2Sq[0]*phiUx[1]+((-411535.2718783651*phiUy[0])-43647.6803507357*phiUx[0]+29098.45356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(51840.0*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*phiUx[1]+((-198493.0225473933*phiUy[0])-61314.59858793825*phiUx[0]+163505.596234502*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(7200.0*rdxCp2R6[0]*phiUy[1]+24000.0*rdxCp2R6[0]*phiUx[1]+((-20784.60969082652*phiUy[0])-20784.60969082652*phiUx[0]+63739.46971853468*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]))/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+((-961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1])-1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0])*rho[2]+(5455.960043841962*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1]+49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]+34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-79200.0*rdxCp2Sq[0]*rdxCp2R6[1])+172800.0*rdxCp2R4[0]*rdxCp2R4[1]+48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[1]*rdxCp2R8[1]+(291815.9200592043*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiUx[1]+((-43200.0*phiUy[0])+63000.0*phiUx[0]+84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(78773.67072823252*rdxCp2R4[0]*phiUy[1]+(70800.0*bcVals[0]-43200.0*phiUy[0])*rdxCp2R4[0])*rdxCp2R4[1]+(4156.921938165305*rdxCp2R6[0]*phiUy[1]+6928.203230275509*rdxCp2R6[0]*phiUx[1]+((-6000.0*phiUy[0])-6000.0*phiUx[0]+20800.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_LxNeumannLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-25.98076211353316*rdxCp2R4[1])-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])-25.98076211353316*rdxCp2R4[0])*rho[1]+150.0*rho[0]*rdxCp2R4[1]+1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+150.0*rdxCp2R4[0]*rho[0])*volFac+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-346.4101615137754*rdxCp2R6[1])-3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1])-1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-800.0*rdxCp2R6[1])-8880.0*rdxCp2Sq[0]*rdxCp2R4[1]-400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+300.0*phiUy[0]*rdxCp2R6[1]+((-1039.230484541326*rdxCp2Sq[0]*phiUy[1])-692.8203230275509*rdxCp2Sq[0]*phiUx[1]+(3420.0*phiUy[0]+600.0*phiUx[0]-400.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-207.8460969082653*rdxCp2R4[0]*phiUy[1])-3949.07584125704*rdxCp2R4[0]*phiUx[1]+(600.0*phiUy[0]+3420.0*phiUx[0]-8880.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*phiUx[1]+(300.0*phiUx[0]-800.0*bcVals[0])*rdxCp2R6[0])/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-450.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-90.0*rdxCp2R4[0])*rho[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+259.8076211353315*rdxCp2R4[0]*rho[0])*volFac+(2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiUx[3]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(1800.0*rdxCp2Sq[0]*rdxCp2R4[1]-1800.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1])-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-1800.0*phiUy[1]*rdxCp2R6[1]+((-6120.0*rdxCp2Sq[0]*phiUy[1])+6000.0*rdxCp2Sq[0]*phiUx[1]+(5196.152422706631*phiUy[0]-5196.152422706631*phiUx[0]-6928.203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-720.0*rdxCp2R4[0]*phiUy[1])+1200.0*rdxCp2R4[0]*phiUx[1]+(1039.230484541326*phiUy[0]-1039.230484541326*phiUx[0]-24248.71130596428*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-2078.460969082652*bcVals[0]*rdxCp2R6[0]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+((-90.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-450.0*rdxCp2R4[0])*rho[2]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+259.8076211353315*rho[0]*rdxCp2R4[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+(2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiUx[3]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R4[1])-6120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiUx[2]+((-2078.460969082652*rdxCp2R6[1])-24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+((-1800.0*rdxCp2Sq[0]*phiUy[1])-1200.0*rdxCp2Sq[0]*phiUx[1]+((-1039.230484541326*phiUy[0])+1039.230484541326*phiUx[0]-692.8203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1800.0*rdxCp2R4[0]*phiUy[1]-6000.0*rdxCp2R4[0]*phiUx[1]+((-5196.152422706631*phiUy[0])+5196.152422706631*phiUx[0]-15934.86742963367*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+((-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])-129.9038105676658*rdxCp2R4[0])*rho[2]+((-129.9038105676658*rdxCp2R4[1])-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+(1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1]-1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1])*phiUy[2]+(1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1]+5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-5200.0*rdxCp2Sq[0]*rdxCp2R4[1])-2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(5196.152422706631*rdxCp2Sq[0]*phiUy[1]+1732.050807568877*rdxCp2Sq[0]*phiUx[1]+(1500.0*phiUy[0]-1500.0*phiUx[0]-2000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1039.230484541326*rdxCp2R4[0]*phiUy[1]-1732.050807568877*rdxCp2R4[0]*phiUx[1]+((-1500.0*phiUy[0])+1500.0*phiUx[0]-5200.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_LxDirichletUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(727.4613391789284*rdxCp2R4[1]+4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])-727.4613391789284*rdxCp2R4[0])*rho[1]-21000.0*rho[0]*rdxCp2R4[1]-130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0]*rho[0])*volFac+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-403200.0*rdxCp2R6[1])-2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]-504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1]+32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-87295.36070147139*rdxCp2R6[1])-538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]-72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-75600.0*phiLy[0]*rdxCp2R6[1]+(72746.13391789283*rdxCp2Sq[0]*phiUx[1]-32423.99111768937*rdxCp2Sq[0]*phiLy[1]+((-63000.0*phiUx[0])-466740.0*phiLy[0]-504000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(538944.9292831317*rdxCp2R4[0]*phiUx[1]-4364.768035073569*rdxCp2R4[0]*phiLy[1]+((-466740.0*phiUx[0])-63000.0*phiLy[0]-2519520.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+87295.36070147139*rdxCp2R6[0]*phiUx[1]+((-75600.0*phiUx[0])-403200.0*bcVals[0])*rdxCp2R6[0]))/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-21000.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-3780.0*rdxCp2R4[0])*rho[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-7274.613391789284*rdxCp2R4[0]*rho[0])*volFac+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(25200.0*rdxCp2Sq[0]*rdxCp2R4[1]+17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-187200.0*rdxCp2Sq[0]*rdxCp2R4[1])-25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-151200.0*phiLy[1]*rdxCp2R6[1]+(420000.0*rdxCp2Sq[0]*phiUx[1]-165960.0*rdxCp2Sq[0]*phiLy[1]+((-363730.6695894642*phiUx[0])-162119.9555884469*phiLy[0]+2909845.356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(682800.0*rdxCp2R4[0]*phiUx[1]-22680.0*rdxCp2R4[0]*phiLy[1]+((-591322.1457040146*phiUx[0])-21823.84017536785*phiLy[0]+2627174.664920473*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+100800.0*rdxCp2R6[0]*phiUx[1]+(349181.4428058856*bcVals[0]-87295.36070147139*phiUx[0])*rdxCp2R6[0]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = (((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+(3780.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0])*rho[2]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-7274.613391789284*rho[0]*rdxCp2R4[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiUx[3]+((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(349181.4428058856*rdxCp2R6[1]+2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]+2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(22680.0*rdxCp2Sq[0]*rdxCp2R4[1]+165960.0*rdxCp2R4[0]*rdxCp2Sq[1]+151200.0*rdxCp2R6[0])*phiUx[2]+((-100800.0*rdxCp2R6[1])-682800.0*rdxCp2Sq[0]*rdxCp2R4[1]-420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-87295.36070147139*phiLy[0]*rdxCp2R6[1]+(25200.0*rdxCp2Sq[0]*phiUx[1]-17280.0*rdxCp2Sq[0]*phiLy[1]+((-21823.84017536785*phiUx[0])-591322.1457040146*phiLy[0]-174590.7214029428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(187200.0*rdxCp2R4[0]*phiUx[1]-25200.0*rdxCp2R4[0]*phiLy[1]+((-162119.9555884469*phiUx[0])-363730.6695894642*phiLy[0]-806442.8560040692*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+(640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1]+2424.871130596428*rdxCp2R4[0])*rho[2]+((-2424.871130596428*rdxCp2R4[1])-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiUx[3]+((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(336000.0*rdxCp2R4[0]*rdxCp2Sq[1]-52800.0*rdxCp2Sq[0]*rdxCp2R4[1])*bcVals[3]+(43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1]+257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]+58196.90713431427*rdxCp2R6[0])*phiUx[2]+((-33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1])-48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-58196.90713431427*phiLy[1]*rdxCp2R6[1]+(48497.42261192856*rdxCp2Sq[0]*phiUx[1]-257867.7242308544*rdxCp2Sq[0]*phiLy[1]+((-42000.0*phiUx[0])-28800.0*phiLy[0]+336000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(33255.37550532244*rdxCp2R4[0]*phiUx[1]-43647.6803507357*rdxCp2R4[0]*phiLy[1]+((-28800.0*phiUx[0])-42000.0*phiLy[0]-52800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_LxDirichletUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(207.8460969082653*rdxCp2R6[1]+6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]+13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+1091.192008768392*rdxCp2R6[0])*rho[1]+1200.0*rho[0]*rdxCp2R6[1]+36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+31500.0*rdxCp2R6[0]*rho[0])*volFac+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(6400.0*rdxCp2R8[1]+193440.0*rdxCp2Sq[0]*rdxCp2R6[1]+445120.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1]+44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]+97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(2771.281292110204*rdxCp2R8[1]+85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]+245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]+145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+2400.0*phiLy[0]*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUx[1])+4156.921938165305*rdxCp2Sq[0]*phiLy[1]+(3600.0*phiUx[0]+74160.0*phiLy[0]+28800.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-149441.3436770427*rdxCp2R4[0]*phiUx[1])+12262.91971758765*rdxCp2R4[0]*phiLy[1]+(129420.0*phiUx[0]+212280.0*phiLy[0]+718560.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-376617.1275977765*rdxCp2R6[0]*phiUx[1])+8729.536070147138*rdxCp2R6[0]*phiLy[1]+(326160.0*phiUx[0]+126000.0*phiLy[0]+1759680.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0]*phiUx[1]+(113400.0*phiUx[0]+604800.0*bcVals[0])*rdxCp2R8[0])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = (((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(2160.0*rdxCp2Sq[0]*rdxCp2R4[1]+5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1200.0*rdxCp2R6[1]+9480.0*rdxCp2Sq[0]*rdxCp2R4[1]+18450.0*rdxCp2R4[0]*rdxCp2Sq[1]+5670.0*rdxCp2R6[0])*rho[1]+11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+10911.92008768392*rdxCp2R6[0]*rho[0])*volFac+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1]+163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]+29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(7200.0*rdxCp2Sq[0]*rdxCp2R6[1]+51840.0*rdxCp2R4[0]*rdxCp2R4[1]+51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(24000.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+4800.0*phiLy[1]*rdxCp2R8[1]+((-24000.0*rdxCp2Sq[0]*phiUx[1])+49920.0*rdxCp2Sq[0]*phiLy[1]+(20784.60969082652*phiUx[0]+20784.60969082652*phiLy[0]-166276.8775266122*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-229200.0*rdxCp2R4[0]*phiUx[1])+134280.0*rdxCp2R4[0]*phiLy[1]+(198493.0225473933*phiUx[0]+61314.59858793825*phiLy[0]-1039230.484541326*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-475200.0*rdxCp2R6[0]*phiUx[1])+45360.0*rdxCp2R6[0]*phiLy[1]+(411535.2718783651*phiUx[0]+43647.6803507357*phiLy[0]-1820731.808916403*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-151200.0*rdxCp2R8[0]*phiUx[1]+(130943.0410522071*phiUx[0]-523772.1642088283*bcVals[0])*rdxCp2R8[0])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = (((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+(120.0*rdxCp2R6[1]+3870.0*rdxCp2Sq[0]*rdxCp2R4[1]+15150.0*rdxCp2R4[0]*rdxCp2Sq[1]+15750.0*rdxCp2R6[0])*rho[2]+(360.0*rdxCp2Sq[0]*rdxCp2R4[1]+885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+346.4101615137754*rho[0]*rdxCp2R6[1]+10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiUx[3]+(1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(2771.281292110204*rdxCp2R8[1]+87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]+291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]+242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(720.0*rdxCp2Sq[0]*rdxCp2R6[1]+25740.0*rdxCp2R4[0]*rdxCp2R4[1]+101520.0*rdxCp2R6[0]*rdxCp2Sq[1]+113400.0*rdxCp2R8[0])*phiUx[2]+((-3600.0*rdxCp2Sq[0]*rdxCp2R6[1])-100800.0*rdxCp2R4[0]*rdxCp2R4[1]-210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-1200.0*rdxCp2Sq[0]*phiUx[1])+1200.0*rdxCp2Sq[0]*phiLy[1]+(1039.230484541326*phiUx[0]-3117.691453623978*phiLy[0]+8313.84387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((37412.29744348773*phiUx[0]-87295.36070147139*phiLy[0]+199532.2530319346*bcVals[0])*rdxCp2R4[0]-43200.0*rdxCp2R4[0]*phiUx[1])*rdxCp2R4[1]+((-93600.0*rdxCp2R6[0]*phiUx[1])-12600.0*rdxCp2R6[0]*phiLy[1]+(81059.97779422344*phiUx[0]-181865.3347947321*phiLy[0]+403221.4280020346*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+(727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+5455.960043841962*rdxCp2R6[0])*rho[2]+(346.4101615137754*rdxCp2R6[1]+1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]+961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiUx[3]+((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(20800.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1]+78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]+291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0])*phiUx[2]+(6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1]-72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-6928.203230275509*rdxCp2Sq[0]*phiUx[1])-34641.01615137755*rdxCp2Sq[0]*phiLy[1]+(6000.0*phiUx[0]+6000.0*phiLy[0]-48000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-49883.06325798365*rdxCp2R4[0]*phiUx[1])-174590.7214029428*rdxCp2R4[0]*phiLy[1]+(43200.0*phiUx[0]-172800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-49883.06325798365*rdxCp2R6[0]*phiUx[1])-65471.52052610354*rdxCp2R6[0]*phiLy[1]+(43200.0*phiUx[0]-63000.0*phiLy[0]+79200.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_LxNeumannUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-1091.192008768392*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1])-6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]-207.8460969082653*rdxCp2R6[0])*rho[1]+31500.0*rho[0]*rdxCp2R6[1]+91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0]*rho[0])*volFac+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(604800.0*rdxCp2R8[1]+1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]+718560.0*rdxCp2R4[0]*rdxCp2R4[1]+28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1])-12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(130943.0410522071*rdxCp2R8[1]+376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]+149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+113400.0*phiLy[0]*rdxCp2R8[1]+((-145492.2678357857*rdxCp2Sq[0]*phiUx[1])-97271.97335306811*rdxCp2Sq[0]*phiLy[1]+(126000.0*phiUx[0]+326160.0*phiLy[0]-84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-245119.8302871475*rdxCp2R4[0]*phiUx[1])-44894.75693218527*rdxCp2R4[0]*phiLy[1]+(212280.0*phiUx[0]+129420.0*phiLy[0]-445120.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-85632.59192620528*rdxCp2R6[0]*phiUx[1])-1247.076581449591*rdxCp2R6[0]*phiLy[1]+(74160.0*phiUx[0]+3600.0*phiLy[0]-193440.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*rdxCp2R8[0]*phiUx[1]+(2400.0*phiUx[0]-6400.0*bcVals[0])*rdxCp2R8[0])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-885.0*rdxCp2Sq[0]*rdxCp2R4[1])-360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-15750.0*rdxCp2R6[1])-15150.0*rdxCp2Sq[0]*rdxCp2R4[1]-3870.0*rdxCp2R4[0]*rdxCp2Sq[1]-120.0*rdxCp2R6[0])*rho[1]+21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*rho[0])*volFac+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiUx[3]+((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1]+199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]+8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(12600.0*rdxCp2Sq[0]*rdxCp2R6[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(93600.0*rdxCp2Sq[0]*rdxCp2R6[1]+43200.0*rdxCp2R4[0]*rdxCp2R4[1]+1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]-113400.0*phiLy[1]*rdxCp2R8[1]+(210000.0*rdxCp2Sq[0]*phiUx[1]-101520.0*rdxCp2Sq[0]*phiLy[1]+((-181865.3347947321*phiUx[0])+81059.97779422344*phiLy[0]-242487.1130596428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(100800.0*rdxCp2R4[0]*phiUx[1]-25740.0*rdxCp2R4[0]*phiLy[1]+((-87295.36070147139*phiUx[0])+37412.29744348773*phiLy[0]-291677.3559945989*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(3600.0*rdxCp2R6[0]*phiUx[1]-720.0*rdxCp2R6[0]*phiLy[1]+((-3117.691453623978*phiUx[0])+1039.230484541326*phiLy[0]-87295.36070147139*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*bcVals[0]*rdxCp2R8[0]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+((-5670.0*rdxCp2R6[1])-18450.0*rdxCp2Sq[0]*rdxCp2R4[1]-9480.0*rdxCp2R4[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0])*rho[2]+((-5310.0*rdxCp2Sq[0]*rdxCp2R4[1])-2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+10911.92008768392*rho[0]*rdxCp2R6[1]+30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiUx[3]+((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-523772.1642088283*rdxCp2R8[1])-1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]-1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]-166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-45360.0*rdxCp2Sq[0]*rdxCp2R6[1])-134280.0*rdxCp2R4[0]*rdxCp2R4[1]-49920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiUx[2]+(151200.0*rdxCp2R8[1]+475200.0*rdxCp2Sq[0]*rdxCp2R6[1]+229200.0*rdxCp2R4[0]*rdxCp2R4[1]+24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+130943.0410522071*phiLy[0]*rdxCp2R8[1]+((-50400.0*rdxCp2Sq[0]*phiUx[1])-51840.0*rdxCp2Sq[0]*phiLy[1]+(43647.6803507357*phiUx[0]+411535.2718783651*phiLy[0]-29098.45356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-70800.0*rdxCp2R4[0]*phiUx[1])-51840.0*rdxCp2R4[0]*phiLy[1]+(61314.59858793825*phiUx[0]+198493.0225473933*phiLy[0]-163505.596234502*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-24000.0*rdxCp2R6[0]*phiUx[1])-7200.0*rdxCp2R6[0]*phiLy[1]+(20784.60969082652*phiUx[0]+20784.60969082652*phiLy[0]-63739.46971853468*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]))/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+((-961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1])-1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0])*rho[2]+((-5455.960043841962*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(79200.0*rdxCp2Sq[0]*rdxCp2R6[1]-172800.0*rdxCp2R4[0]*rdxCp2R4[1]-48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]+34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1]+49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]-130943.0410522071*phiLy[1]*rdxCp2R8[1]+(72746.13391789283*rdxCp2Sq[0]*phiUx[1]-291815.9200592043*rdxCp2Sq[0]*phiLy[1]+((-63000.0*phiUx[0])+43200.0*phiLy[0]-84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((43200.0*phiLy[0]-70800.0*bcVals[0])*rdxCp2R4[0]-78773.67072823252*rdxCp2R4[0]*phiLy[1])*rdxCp2R4[1]+((-6928.203230275509*rdxCp2R6[0]*phiUx[1])-4156.921938165305*rdxCp2R6[0]*phiLy[1]+(6000.0*phiUx[0]+6000.0*phiLy[0]-20800.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_LxNeumannUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-25.98076211353316*rdxCp2R4[1])-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1]+25.98076211353316*rdxCp2R4[0])*rho[1]-150.0*rho[0]*rdxCp2R4[1]-1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-150.0*rdxCp2R4[0]*rho[0])*volFac+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-800.0*rdxCp2R6[1])-8880.0*rdxCp2Sq[0]*rdxCp2R4[1]-400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1])-1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-346.4101615137754*rdxCp2R6[1])-3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-300.0*phiLy[0]*rdxCp2R6[1]+(692.8203230275509*rdxCp2Sq[0]*phiUx[1]+1039.230484541326*rdxCp2Sq[0]*phiLy[1]+((-600.0*phiUx[0])-3420.0*phiLy[0]+400.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(3949.07584125704*rdxCp2R4[0]*phiUx[1]+207.8460969082653*rdxCp2R4[0]*phiLy[1]+((-3420.0*phiUx[0])-600.0*phiLy[0]+8880.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*phiUx[1]+(800.0*bcVals[0]-300.0*phiUx[0])*rdxCp2R6[0]))/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = (((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(450.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+90.0*rdxCp2R4[0])*rho[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-259.8076211353315*rdxCp2R4[0]*rho[0])*volFac+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiUx[3]+(2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1])-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1800.0*rdxCp2Sq[0]*rdxCp2R4[1]-1800.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+1800.0*phiLy[1]*rdxCp2R6[1]+((-6000.0*rdxCp2Sq[0]*phiUx[1])+6120.0*rdxCp2Sq[0]*phiLy[1]+(5196.152422706631*phiUx[0]-5196.152422706631*phiLy[0]+6928.203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1200.0*rdxCp2R4[0]*phiUx[1])+720.0*rdxCp2R4[0]*phiLy[1]+(1039.230484541326*phiUx[0]-1039.230484541326*phiLy[0]+24248.71130596428*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+2078.460969082652*bcVals[0]*rdxCp2R6[0])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+((-90.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-450.0*rdxCp2R4[0])*rho[2]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-259.8076211353315*rho[0]*rdxCp2R4[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiUx[3]+(2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-2078.460969082652*rdxCp2R6[1])-24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-720.0*rdxCp2Sq[0]*rdxCp2R4[1])-6120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiUx[2]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(1200.0*rdxCp2Sq[0]*phiUx[1]+1800.0*rdxCp2Sq[0]*phiLy[1]+((-1039.230484541326*phiUx[0])+1039.230484541326*phiLy[0]+692.8203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(6000.0*rdxCp2R4[0]*phiUx[1]-1800.0*rdxCp2R4[0]*phiLy[1]+((-5196.152422706631*phiUx[0])+5196.152422706631*phiLy[0]+15934.86742963367*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+((-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])-129.9038105676658*rdxCp2R4[0])*rho[2]+(129.9038105676658*rdxCp2R4[1]+181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-5200.0*rdxCp2Sq[0]*rdxCp2R4[1])-2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1]+5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1]-1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1])*phiLy[2]+((-1732.050807568877*rdxCp2Sq[0]*phiUx[1])-5196.152422706631*rdxCp2Sq[0]*phiLy[1]+(1500.0*phiUx[0]-1500.0*phiLy[0]+2000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1732.050807568877*rdxCp2R4[0]*phiUx[1]-1039.230484541326*rdxCp2R4[0]*phiLy[1]+((-1500.0*phiUx[0])+1500.0*phiLy[0]+5200.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_UxDirichletLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-727.4613391789284*rdxCp2R4[1])-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[1]-21000.0*rho[0]*rdxCp2R4[1]-130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0]*rho[0])*volFac+((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(87295.36070147139*rdxCp2R6[1]+538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]+72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1])-32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-403200.0*rdxCp2R6[1])-2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]-504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-75600.0*phiUy[0]*rdxCp2R6[1]+(32423.99111768937*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiLx[1]-504000.0*rdxCp2Sq[0]*bcVals[1]+((-466740.0*phiUy[0])-63000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(4364.768035073569*rdxCp2R4[0]*phiUy[1]-538944.9292831317*rdxCp2R4[0]*phiLx[1]-2519520.0*rdxCp2R4[0]*bcVals[1]+((-63000.0*phiUy[0])-466740.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]-87295.36070147139*rdxCp2R6[0]*phiLx[1]-403200.0*rdxCp2R6[0]*bcVals[1]-75600.0*phiLx[0]*rdxCp2R6[0]))/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = (((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(21000.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3780.0*rdxCp2R4[0])*rho[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-7274.613391789284*rdxCp2R4[0]*rho[0])*volFac+((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(187200.0*rdxCp2Sq[0]*rdxCp2R4[1]+25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-25200.0*rdxCp2Sq[0]*rdxCp2R4[1])-17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+151200.0*phiUy[1]*rdxCp2R6[1]+(165960.0*rdxCp2Sq[0]*phiUy[1]-420000.0*rdxCp2Sq[0]*phiLx[1]+2909845.356715714*rdxCp2Sq[0]*bcVals[1]+((-162119.9555884469*phiUy[0])-363730.6695894642*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(22680.0*rdxCp2R4[0]*phiUy[1]-682800.0*rdxCp2R4[0]*phiLx[1]+2627174.664920473*rdxCp2R4[0]*bcVals[1]+((-21823.84017536785*phiUy[0])-591322.1457040146*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]-100800.0*rdxCp2R6[0]*phiLx[1]+349181.4428058856*rdxCp2R6[0]*bcVals[1]-87295.36070147139*phiLx[0]*rdxCp2R6[0])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+((-3780.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0])*rho[2]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-7274.613391789284*rho[0]*rdxCp2R4[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiLx[3]+(100800.0*rdxCp2R6[1]+682800.0*rdxCp2Sq[0]*rdxCp2R4[1]+420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-22680.0*rdxCp2Sq[0]*rdxCp2R4[1])-165960.0*rdxCp2R4[0]*rdxCp2Sq[1]-151200.0*rdxCp2R6[0])*phiLx[2]+(349181.4428058856*rdxCp2R6[1]+2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]+2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-87295.36070147139*phiUy[0]*rdxCp2R6[1]+(17280.0*rdxCp2Sq[0]*phiUy[1]-25200.0*rdxCp2Sq[0]*phiLx[1]-174590.7214029428*rdxCp2Sq[0]*bcVals[1]+((-591322.1457040146*phiUy[0])-21823.84017536785*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(25200.0*rdxCp2R4[0]*phiUy[1]-187200.0*rdxCp2R4[0]*phiLx[1]-806442.8560040692*rdxCp2R4[0]*bcVals[1]+((-363730.6695894642*phiUy[0])-162119.9555884469*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+((-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])-2424.871130596428*rdxCp2R4[0])*rho[2]+(2424.871130596428*rdxCp2R4[1]+640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiLx[3]+(33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1]+48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1])-257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]-58196.90713431427*rdxCp2R6[0])*phiLx[2]+(336000.0*rdxCp2R4[0]*rdxCp2Sq[1]-52800.0*rdxCp2Sq[0]*rdxCp2R4[1])*bcVals[2]+58196.90713431427*phiUy[1]*rdxCp2R6[1]+(257867.7242308544*rdxCp2Sq[0]*phiUy[1]-48497.42261192856*rdxCp2Sq[0]*phiLx[1]+336000.0*rdxCp2Sq[0]*bcVals[1]+((-28800.0*phiUy[0])-42000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(43647.6803507357*rdxCp2R4[0]*phiUy[1]-33255.37550532244*rdxCp2R4[0]*phiLx[1]-52800.0*rdxCp2R4[0]*bcVals[1]+((-42000.0*phiUy[0])-28800.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_UxDirichletLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-207.8460969082653*rdxCp2R6[1])-6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]-13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-1091.192008768392*rdxCp2R6[0])*rho[1]+1200.0*rho[0]*rdxCp2R6[1]+36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+31500.0*rdxCp2R6[0]*rho[0])*volFac+(4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-2771.281292110204*rdxCp2R8[1])-85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]-245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]-145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1])-44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]-97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+((-6400.0*rdxCp2R8[1])-193440.0*rdxCp2Sq[0]*rdxCp2R6[1]-445120.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+2400.0*phiUy[0]*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUy[1])+4156.921938165305*rdxCp2Sq[0]*phiLx[1]+28800.0*rdxCp2Sq[0]*bcVals[1]+(74160.0*phiUy[0]+3600.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-12262.91971758765*rdxCp2R4[0]*phiUy[1])+149441.3436770427*rdxCp2R4[0]*phiLx[1]+718560.0*rdxCp2R4[0]*bcVals[1]+(212280.0*phiUy[0]+129420.0*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-8729.536070147138*rdxCp2R6[0]*phiUy[1])+376617.1275977765*rdxCp2R6[0]*phiLx[1]+1759680.0*rdxCp2R6[0]*bcVals[1]+(126000.0*phiUy[0]+326160.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0]*phiLx[1]+604800.0*rdxCp2R8[0]*bcVals[1]+113400.0*phiLx[0]*rdxCp2R8[0])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-2160.0*rdxCp2Sq[0]*rdxCp2R4[1])-5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1200.0*rdxCp2R6[1])-9480.0*rdxCp2Sq[0]*rdxCp2R4[1]-18450.0*rdxCp2R4[0]*rdxCp2Sq[1]-5670.0*rdxCp2R6[0])*rho[1]+11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+10911.92008768392*rdxCp2R6[0]*rho[0])*volFac+(5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-24000.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-7200.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+((-63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1])-163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]-29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-4800.0*phiUy[1]*rdxCp2R8[1]+((-49920.0*rdxCp2Sq[0]*phiUy[1])+24000.0*rdxCp2Sq[0]*phiLx[1]-166276.8775266122*rdxCp2Sq[0]*bcVals[1]+(20784.60969082652*phiUy[0]+20784.60969082652*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-134280.0*rdxCp2R4[0]*phiUy[1])+229200.0*rdxCp2R4[0]*phiLx[1]-1039230.484541326*rdxCp2R4[0]*bcVals[1]+(61314.59858793825*phiUy[0]+198493.0225473933*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-45360.0*rdxCp2R6[0]*phiUy[1])+475200.0*rdxCp2R6[0]*phiLx[1]-1820731.808916403*rdxCp2R6[0]*bcVals[1]+(43647.6803507357*phiUy[0]+411535.2718783651*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]+151200.0*rdxCp2R8[0]*phiLx[1]-523772.1642088283*rdxCp2R8[0]*bcVals[1]+130943.0410522071*phiLx[0]*rdxCp2R8[0]))/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+((-120.0*rdxCp2R6[1])-3870.0*rdxCp2Sq[0]*rdxCp2R4[1]-15150.0*rdxCp2R4[0]*rdxCp2Sq[1]-15750.0*rdxCp2R6[0])*rho[2]+((-360.0*rdxCp2Sq[0]*rdxCp2R4[1])-885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+346.4101615137754*rho[0]*rdxCp2R6[1]+10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+(1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[3]+(3600.0*rdxCp2Sq[0]*rdxCp2R6[1]+100800.0*rdxCp2R4[0]*rdxCp2R4[1]+210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R6[1])-25740.0*rdxCp2R4[0]*rdxCp2R4[1]-101520.0*rdxCp2R6[0]*rdxCp2Sq[1]-113400.0*rdxCp2R8[0])*phiLx[2]+((-2771.281292110204*rdxCp2R8[1])-87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]-291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]-242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+((-1200.0*rdxCp2Sq[0]*phiUy[1])+1200.0*rdxCp2Sq[0]*phiLx[1]+8313.84387633061*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiLx[0]-3117.691453623978*phiUy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(43200.0*rdxCp2R4[0]*phiLx[1]+199532.2530319346*rdxCp2R4[0]*bcVals[1]+(37412.29744348773*phiLx[0]-87295.36070147139*phiUy[0])*rdxCp2R4[0])*rdxCp2R4[1]+(12600.0*rdxCp2R6[0]*phiUy[1]+93600.0*rdxCp2R6[0]*phiLx[1]+403221.4280020346*rdxCp2R6[0]*bcVals[1]+(81059.97779422344*phiLx[0]-181865.3347947321*phiUy[0])*rdxCp2R6[0])*rdxCp2Sq[1]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+((-727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-5455.960043841962*rdxCp2R6[0])*rho[2]+((-346.4101615137754*rdxCp2R6[1])-1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]-961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiLx[3]+(72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1]-6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1])*phiUy[2]+((-4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1])-78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]-291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[2]+((-20800.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(34641.01615137755*rdxCp2Sq[0]*phiUy[1]+6928.203230275509*rdxCp2Sq[0]*phiLx[1]-48000.0*rdxCp2Sq[0]*bcVals[1]+(6000.0*phiUy[0]+6000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(174590.7214029428*rdxCp2R4[0]*phiUy[1]+49883.06325798365*rdxCp2R4[0]*phiLx[1]-172800.0*rdxCp2R4[0]*bcVals[1]+43200.0*phiLx[0]*rdxCp2R4[0])*rdxCp2R4[1]+(65471.52052610354*rdxCp2R6[0]*phiUy[1]+49883.06325798365*rdxCp2R6[0]*phiLx[1]+79200.0*rdxCp2R6[0]*bcVals[1]+(43200.0*phiLx[0]-63000.0*phiUy[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_UxNeumannLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(1091.192008768392*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1]+6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[1]+31500.0*rho[0]*rdxCp2R6[1]+91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0]*rho[0])*volFac+((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-130943.0410522071*rdxCp2R8[1])-376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]-149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1]+12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(604800.0*rdxCp2R8[1]+1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]+718560.0*rdxCp2R4[0]*rdxCp2R4[1]+28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+113400.0*phiUy[0]*rdxCp2R8[1]+(97271.97335306811*rdxCp2Sq[0]*phiUy[1]+145492.2678357857*rdxCp2Sq[0]*phiLx[1]+84000.0*rdxCp2Sq[0]*bcVals[1]+(326160.0*phiUy[0]+126000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(44894.75693218527*rdxCp2R4[0]*phiUy[1]+245119.8302871475*rdxCp2R4[0]*phiLx[1]+445120.0*rdxCp2R4[0]*bcVals[1]+(129420.0*phiUy[0]+212280.0*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(1247.076581449591*rdxCp2R6[0]*phiUy[1]+85632.59192620528*rdxCp2R6[0]*phiLx[1]+193440.0*rdxCp2R6[0]*bcVals[1]+(3600.0*phiUy[0]+74160.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*rdxCp2R8[0]*phiLx[1]+6400.0*rdxCp2R8[0]*bcVals[1]+2400.0*phiLx[0]*rdxCp2R8[0])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = (((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(885.0*rdxCp2Sq[0]*rdxCp2R4[1]+360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(15750.0*rdxCp2R6[1]+15150.0*rdxCp2Sq[0]*rdxCp2R4[1]+3870.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[1]+21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*rho[0])*volFac+((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[3]+((-93600.0*rdxCp2Sq[0]*rdxCp2R6[1])-43200.0*rdxCp2R4[0]*rdxCp2R4[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(1200.0*rdxCp2R6[0]*rdxCp2Sq[1]-12600.0*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[2]+(403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1]+199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]+8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+113400.0*phiUy[1]*rdxCp2R8[1]+(101520.0*rdxCp2Sq[0]*phiUy[1]-210000.0*rdxCp2Sq[0]*phiLx[1]+242487.1130596428*rdxCp2Sq[0]*bcVals[1]+(81059.97779422344*phiUy[0]-181865.3347947321*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(25740.0*rdxCp2R4[0]*phiUy[1]-100800.0*rdxCp2R4[0]*phiLx[1]+291677.3559945989*rdxCp2R4[0]*bcVals[1]+(37412.29744348773*phiUy[0]-87295.36070147139*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(720.0*rdxCp2R6[0]*phiUy[1]-3600.0*rdxCp2R6[0]*phiLx[1]+87295.36070147139*rdxCp2R6[0]*bcVals[1]+(1039.230484541326*phiUy[0]-3117.691453623978*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*rdxCp2R8[0]*bcVals[1])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = (((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+(5670.0*rdxCp2R6[1]+18450.0*rdxCp2Sq[0]*rdxCp2R4[1]+9480.0*rdxCp2R4[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0])*rho[2]+(5310.0*rdxCp2Sq[0]*rdxCp2R4[1]+2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+10911.92008768392*rho[0]*rdxCp2R6[1]+30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiLx[3]+((-151200.0*rdxCp2R8[1])-475200.0*rdxCp2Sq[0]*rdxCp2R6[1]-229200.0*rdxCp2R4[0]*rdxCp2R4[1]-24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(45360.0*rdxCp2Sq[0]*rdxCp2R6[1]+134280.0*rdxCp2R4[0]*rdxCp2R4[1]+49920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiLx[2]+((-523772.1642088283*rdxCp2R8[1])-1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]-1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]-166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[0]*rdxCp2R8[1]+(51840.0*rdxCp2Sq[0]*phiUy[1]+50400.0*rdxCp2Sq[0]*phiLx[1]+29098.45356715714*rdxCp2Sq[0]*bcVals[1]+(411535.2718783651*phiUy[0]+43647.6803507357*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(51840.0*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*phiLx[1]+163505.596234502*rdxCp2R4[0]*bcVals[1]+(198493.0225473933*phiUy[0]+61314.59858793825*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(7200.0*rdxCp2R6[0]*phiUy[1]+24000.0*rdxCp2R6[0]*phiLx[1]+63739.46971853468*rdxCp2R6[0]*bcVals[1]+(20784.60969082652*phiUy[0]+20784.60969082652*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+(961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1]+1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0])*rho[2]+(5455.960043841962*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1])-49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]-34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(79200.0*rdxCp2Sq[0]*rdxCp2R6[1]-172800.0*rdxCp2R4[0]*rdxCp2R4[1]-48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[1]*rdxCp2R8[1]+(291815.9200592043*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiLx[1]+84000.0*rdxCp2Sq[0]*bcVals[1]+(43200.0*phiUy[0]-63000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(78773.67072823252*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*bcVals[1]+43200.0*phiUy[0]*rdxCp2R4[0])*rdxCp2R4[1]+(4156.921938165305*rdxCp2R6[0]*phiUy[1]+6928.203230275509*rdxCp2R6[0]*phiLx[1]+20800.0*rdxCp2R6[0]*bcVals[1]+(6000.0*phiUy[0]+6000.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_UxNeumannLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(25.98076211353316*rdxCp2R4[1]+285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])-25.98076211353316*rdxCp2R4[0])*rho[1]-150.0*rho[0]*rdxCp2R4[1]-1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-150.0*rdxCp2R4[0]*rho[0])*volFac+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(346.4101615137754*rdxCp2R6[1]+3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1]+1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(800.0*rdxCp2R6[1]+8880.0*rdxCp2Sq[0]*rdxCp2R4[1]+400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-300.0*phiUy[0]*rdxCp2R6[1]+((-1039.230484541326*rdxCp2Sq[0]*phiUy[1])-692.8203230275509*rdxCp2Sq[0]*phiLx[1]-400.0*rdxCp2Sq[0]*bcVals[1]+((-3420.0*phiUy[0])-600.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-207.8460969082653*rdxCp2R4[0]*phiUy[1])-3949.07584125704*rdxCp2R4[0]*phiLx[1]-8880.0*rdxCp2R4[0]*bcVals[1]+((-600.0*phiUy[0])-3420.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*phiLx[1]-800.0*rdxCp2R6[0]*bcVals[1]-300.0*phiLx[0]*rdxCp2R6[0]))/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-450.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-90.0*rdxCp2R4[0])*rho[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-259.8076211353315*rdxCp2R4[0]*rho[0])*volFac+(2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[3]+(6000.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(1800.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[2]+(15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-1800.0*phiUy[1]*rdxCp2R6[1]+((-6120.0*rdxCp2Sq[0]*phiUy[1])+6000.0*rdxCp2Sq[0]*phiLx[1]-6928.203230275509*rdxCp2Sq[0]*bcVals[1]+(5196.152422706631*phiLx[0]-5196.152422706631*phiUy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-720.0*rdxCp2R4[0]*phiUy[1])+1200.0*rdxCp2R4[0]*phiLx[1]-24248.71130596428*rdxCp2R4[0]*bcVals[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiUy[0])*rdxCp2R4[0])*rdxCp2Sq[1]-2078.460969082652*rdxCp2R6[0]*bcVals[1]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = (((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+(90.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+450.0*rdxCp2R4[0])*rho[2]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-259.8076211353315*rho[0]*rdxCp2R4[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+(2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiLx[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R4[1]+6120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiLx[2]+(2078.460969082652*rdxCp2R6[1]+24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+((-1800.0*rdxCp2Sq[0]*phiUy[1])-1200.0*rdxCp2Sq[0]*phiLx[1]-692.8203230275509*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiUy[0]-1039.230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1800.0*rdxCp2R4[0]*phiUy[1]-6000.0*rdxCp2R4[0]*phiLx[1]-15934.86742963367*rdxCp2R4[0]*bcVals[1]+(5196.152422706631*phiUy[0]-5196.152422706631*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+(181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1]+129.9038105676658*rdxCp2R4[0])*rho[2]+((-129.9038105676658*rdxCp2R4[1])-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1]-1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1])-5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(5200.0*rdxCp2Sq[0]*rdxCp2R4[1]+2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(5196.152422706631*rdxCp2Sq[0]*phiUy[1]+1732.050807568877*rdxCp2Sq[0]*phiLx[1]-2000.0*rdxCp2Sq[0]*bcVals[1]+(1500.0*phiLx[0]-1500.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1039.230484541326*rdxCp2R4[0]*phiUy[1]-1732.050807568877*rdxCp2R4[0]*phiLx[1]-5200.0*rdxCp2R4[0]*bcVals[1]+(1500.0*phiUy[0]-1500.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_UxDirichletUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-727.4613391789284*rdxCp2R4[1])-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])-727.4613391789284*rdxCp2R4[0])*rho[1]+21000.0*rho[0]*rdxCp2R4[1]+130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0]*rho[0])*volFac+((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(403200.0*rdxCp2R6[1]+2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]+504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(87295.36070147139*rdxCp2R6[1]+538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]+72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1])-32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+75600.0*phiLy[0]*rdxCp2R6[1]+((-32423.99111768937*rdxCp2Sq[0]*phiLy[1])+72746.13391789283*rdxCp2Sq[0]*phiLx[1]+504000.0*rdxCp2Sq[0]*bcVals[1]+(466740.0*phiLy[0]+63000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-4364.768035073569*rdxCp2R4[0]*phiLy[1])+538944.9292831317*rdxCp2R4[0]*phiLx[1]+2519520.0*rdxCp2R4[0]*bcVals[1]+(63000.0*phiLy[0]+466740.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]+87295.36070147139*rdxCp2R6[0]*phiLx[1]+403200.0*rdxCp2R6[0]*bcVals[1]+75600.0*phiLx[0]*rdxCp2R6[0])/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-21000.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-3780.0*rdxCp2R4[0])*rho[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+7274.613391789284*rdxCp2R4[0]*rho[0])*volFac+((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(187200.0*rdxCp2Sq[0]*rdxCp2R4[1]+25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-25200.0*rdxCp2Sq[0]*rdxCp2R4[1])-17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]-151200.0*phiLy[1]*rdxCp2R6[1]+((-165960.0*rdxCp2Sq[0]*phiLy[1])+420000.0*rdxCp2Sq[0]*phiLx[1]-2909845.356715714*rdxCp2Sq[0]*bcVals[1]+(162119.9555884469*phiLy[0]+363730.6695894642*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-22680.0*rdxCp2R4[0]*phiLy[1])+682800.0*rdxCp2R4[0]*phiLx[1]-2627174.664920473*rdxCp2R4[0]*bcVals[1]+(21823.84017536785*phiLy[0]+591322.1457040146*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]+100800.0*rdxCp2R6[0]*phiLx[1]-349181.4428058856*rdxCp2R6[0]*bcVals[1]+87295.36070147139*phiLx[0]*rdxCp2R6[0]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+((-3780.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0])*rho[2]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+7274.613391789284*rho[0]*rdxCp2R4[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiLx[3]+((-349181.4428058856*rdxCp2R6[1])-2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]-2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(100800.0*rdxCp2R6[1]+682800.0*rdxCp2Sq[0]*rdxCp2R4[1]+420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-22680.0*rdxCp2Sq[0]*rdxCp2R4[1])-165960.0*rdxCp2R4[0]*rdxCp2Sq[1]-151200.0*rdxCp2R6[0])*phiLx[2]+87295.36070147139*phiLy[0]*rdxCp2R6[1]+((-17280.0*rdxCp2Sq[0]*phiLy[1])+25200.0*rdxCp2Sq[0]*phiLx[1]+174590.7214029428*rdxCp2Sq[0]*bcVals[1]+(591322.1457040146*phiLy[0]+21823.84017536785*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-25200.0*rdxCp2R4[0]*phiLy[1])+187200.0*rdxCp2R4[0]*phiLx[1]+806442.8560040692*rdxCp2R4[0]*bcVals[1]+(363730.6695894642*phiLy[0]+162119.9555884469*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+((-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])-2424.871130596428*rdxCp2R4[0])*rho[2]+((-2424.871130596428*rdxCp2R4[1])-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiLx[3]+(52800.0*rdxCp2Sq[0]*rdxCp2R4[1]-336000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1]+48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1])-257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]-58196.90713431427*rdxCp2R6[0])*phiLx[2]-58196.90713431427*phiLy[1]*rdxCp2R6[1]+((-257867.7242308544*rdxCp2Sq[0]*phiLy[1])+48497.42261192856*rdxCp2Sq[0]*phiLx[1]-336000.0*rdxCp2Sq[0]*bcVals[1]+(28800.0*phiLy[0]+42000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-43647.6803507357*rdxCp2R4[0]*phiLy[1])+33255.37550532244*rdxCp2R4[0]*phiLx[1]+52800.0*rdxCp2R4[0]*bcVals[1]+(42000.0*phiLy[0]+28800.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonGaussSeidel2xSer_UxDirichletUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-207.8460969082653*rdxCp2R6[1])-6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]-13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+1091.192008768392*rdxCp2R6[0])*rho[1]-1200.0*rho[0]*rdxCp2R6[1]-36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-31500.0*rdxCp2R6[0]*rho[0])*volFac+(4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-6400.0*rdxCp2R8[1])-193440.0*rdxCp2Sq[0]*rdxCp2R6[1]-445120.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-2771.281292110204*rdxCp2R8[1])-85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]-245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]-145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1])-44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]-97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]-2400.0*phiLy[0]*rdxCp2R8[1]+(4156.921938165305*rdxCp2Sq[0]*phiLy[1]-4156.921938165305*rdxCp2Sq[0]*phiLx[1]-28800.0*rdxCp2Sq[0]*bcVals[1]+((-74160.0*phiLy[0])-3600.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(12262.91971758765*rdxCp2R4[0]*phiLy[1]-149441.3436770427*rdxCp2R4[0]*phiLx[1]-718560.0*rdxCp2R4[0]*bcVals[1]+((-212280.0*phiLy[0])-129420.0*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(8729.536070147138*rdxCp2R6[0]*phiLy[1]-376617.1275977765*rdxCp2R6[0]*phiLx[1]-1759680.0*rdxCp2R6[0]*bcVals[1]+((-126000.0*phiLy[0])-326160.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0]*phiLx[1]-604800.0*rdxCp2R8[0]*bcVals[1]-113400.0*phiLx[0]*rdxCp2R8[0]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = (((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-2160.0*rdxCp2Sq[0]*rdxCp2R4[1])-5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1200.0*rdxCp2R6[1]+9480.0*rdxCp2Sq[0]*rdxCp2R4[1]+18450.0*rdxCp2R4[0]*rdxCp2Sq[1]+5670.0*rdxCp2R6[0])*rho[1]-11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-10911.92008768392*rdxCp2R6[0]*rho[0])*volFac+(5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1])-163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]-29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-24000.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-7200.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+4800.0*phiLy[1]*rdxCp2R8[1]+(49920.0*rdxCp2Sq[0]*phiLy[1]-24000.0*rdxCp2Sq[0]*phiLx[1]+166276.8775266122*rdxCp2Sq[0]*bcVals[1]+((-20784.60969082652*phiLy[0])-20784.60969082652*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(134280.0*rdxCp2R4[0]*phiLy[1]-229200.0*rdxCp2R4[0]*phiLx[1]+1039230.484541326*rdxCp2R4[0]*bcVals[1]+((-61314.59858793825*phiLy[0])-198493.0225473933*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(45360.0*rdxCp2R6[0]*phiLy[1]-475200.0*rdxCp2R6[0]*phiLx[1]+1820731.808916403*rdxCp2R6[0]*bcVals[1]+((-43647.6803507357*phiLy[0])-411535.2718783651*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]-151200.0*rdxCp2R8[0]*phiLx[1]+523772.1642088283*rdxCp2R8[0]*bcVals[1]-130943.0410522071*phiLx[0]*rdxCp2R8[0])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+((-120.0*rdxCp2R6[1])-3870.0*rdxCp2Sq[0]*rdxCp2R4[1]-15150.0*rdxCp2R4[0]*rdxCp2Sq[1]-15750.0*rdxCp2R6[0])*rho[2]+(360.0*rdxCp2Sq[0]*rdxCp2R4[1]+885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-346.4101615137754*rho[0]*rdxCp2R6[1]-10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+(1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[3]+((-2771.281292110204*rdxCp2R8[1])-87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]-291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]-242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(3600.0*rdxCp2Sq[0]*rdxCp2R6[1]+100800.0*rdxCp2R4[0]*rdxCp2R4[1]+210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R6[1])-25740.0*rdxCp2R4[0]*rdxCp2R4[1]-101520.0*rdxCp2R6[0]*rdxCp2Sq[1]-113400.0*rdxCp2R8[0])*phiLx[2]+(1200.0*rdxCp2Sq[0]*phiLy[1]-1200.0*rdxCp2Sq[0]*phiLx[1]-8313.84387633061*rdxCp2Sq[0]*bcVals[1]+(3117.691453623978*phiLy[0]-1039.230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-43200.0*rdxCp2R4[0]*phiLx[1])-199532.2530319346*rdxCp2R4[0]*bcVals[1]+(87295.36070147139*phiLy[0]-37412.29744348773*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-12600.0*rdxCp2R6[0]*phiLy[1])-93600.0*rdxCp2R6[0]*phiLx[1]-403221.4280020346*rdxCp2R6[0]*bcVals[1]+(181865.3347947321*phiLy[0]-81059.97779422344*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+((-727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-5455.960043841962*rdxCp2R6[0])*rho[2]+(346.4101615137754*rdxCp2R6[1]+1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]+961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiLx[3]+((-20800.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1]-6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1])*phiLy[2]+((-4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1])-78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]-291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[2]+((-34641.01615137755*rdxCp2Sq[0]*phiLy[1])-6928.203230275509*rdxCp2Sq[0]*phiLx[1]+48000.0*rdxCp2Sq[0]*bcVals[1]+((-6000.0*phiLy[0])-6000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-174590.7214029428*rdxCp2R4[0]*phiLy[1])-49883.06325798365*rdxCp2R4[0]*phiLx[1]+172800.0*rdxCp2R4[0]*bcVals[1]-43200.0*phiLx[0]*rdxCp2R4[0])*rdxCp2R4[1]+((-65471.52052610354*rdxCp2R6[0]*phiLy[1])-49883.06325798365*rdxCp2R6[0]*phiLx[1]-79200.0*rdxCp2R6[0]*bcVals[1]+(63000.0*phiLy[0]-43200.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_UxNeumannUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(1091.192008768392*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1])-6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]-207.8460969082653*rdxCp2R6[0])*rho[1]-31500.0*rho[0]*rdxCp2R6[1]-91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0]*rho[0])*volFac+((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-604800.0*rdxCp2R8[1])-1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]-718560.0*rdxCp2R4[0]*rdxCp2R4[1]-28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-130943.0410522071*rdxCp2R8[1])-376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]-149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1]+12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]-113400.0*phiLy[0]*rdxCp2R8[1]+((-97271.97335306811*rdxCp2Sq[0]*phiLy[1])-145492.2678357857*rdxCp2Sq[0]*phiLx[1]-84000.0*rdxCp2Sq[0]*bcVals[1]+((-326160.0*phiLy[0])-126000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-44894.75693218527*rdxCp2R4[0]*phiLy[1])-245119.8302871475*rdxCp2R4[0]*phiLx[1]-445120.0*rdxCp2R4[0]*bcVals[1]+((-129420.0*phiLy[0])-212280.0*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-1247.076581449591*rdxCp2R6[0]*phiLy[1])-85632.59192620528*rdxCp2R6[0]*phiLx[1]-193440.0*rdxCp2R6[0]*bcVals[1]+((-3600.0*phiLy[0])-74160.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*rdxCp2R8[0]*phiLx[1]-6400.0*rdxCp2R8[0]*bcVals[1]-2400.0*phiLx[0]*rdxCp2R8[0]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(885.0*rdxCp2Sq[0]*rdxCp2R4[1]+360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-15750.0*rdxCp2R6[1])-15150.0*rdxCp2Sq[0]*rdxCp2R4[1]-3870.0*rdxCp2R4[0]*rdxCp2Sq[1]-120.0*rdxCp2R6[0])*rho[1]-21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*rho[0])*volFac+((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[3]+((-403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1])-199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-93600.0*rdxCp2Sq[0]*rdxCp2R6[1])-43200.0*rdxCp2R4[0]*rdxCp2R4[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(1200.0*rdxCp2R6[0]*rdxCp2Sq[1]-12600.0*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[2]-113400.0*phiLy[1]*rdxCp2R8[1]+((-101520.0*rdxCp2Sq[0]*phiLy[1])+210000.0*rdxCp2Sq[0]*phiLx[1]-242487.1130596428*rdxCp2Sq[0]*bcVals[1]+(181865.3347947321*phiLx[0]-81059.97779422344*phiLy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-25740.0*rdxCp2R4[0]*phiLy[1])+100800.0*rdxCp2R4[0]*phiLx[1]-291677.3559945989*rdxCp2R4[0]*bcVals[1]+(87295.36070147139*phiLx[0]-37412.29744348773*phiLy[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-720.0*rdxCp2R6[0]*phiLy[1])+3600.0*rdxCp2R6[0]*phiLx[1]-87295.36070147139*rdxCp2R6[0]*bcVals[1]+(3117.691453623978*phiLx[0]-1039.230484541326*phiLy[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*rdxCp2R8[0]*bcVals[1]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = (((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+(5670.0*rdxCp2R6[1]+18450.0*rdxCp2Sq[0]*rdxCp2R4[1]+9480.0*rdxCp2R4[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0])*rho[2]+((-5310.0*rdxCp2Sq[0]*rdxCp2R4[1])-2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-10911.92008768392*rho[0]*rdxCp2R6[1]-30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiLx[3]+(523772.1642088283*rdxCp2R8[1]+1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]+1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]+166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-151200.0*rdxCp2R8[1])-475200.0*rdxCp2Sq[0]*rdxCp2R6[1]-229200.0*rdxCp2R4[0]*rdxCp2R4[1]-24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(45360.0*rdxCp2Sq[0]*rdxCp2R6[1]+134280.0*rdxCp2R4[0]*rdxCp2R4[1]+49920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiLx[2]-130943.0410522071*phiLy[0]*rdxCp2R8[1]+((-51840.0*rdxCp2Sq[0]*phiLy[1])-50400.0*rdxCp2Sq[0]*phiLx[1]-29098.45356715714*rdxCp2Sq[0]*bcVals[1]+((-411535.2718783651*phiLy[0])-43647.6803507357*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-51840.0*rdxCp2R4[0]*phiLy[1])-70800.0*rdxCp2R4[0]*phiLx[1]-163505.596234502*rdxCp2R4[0]*bcVals[1]+((-198493.0225473933*phiLy[0])-61314.59858793825*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-7200.0*rdxCp2R6[0]*phiLy[1])-24000.0*rdxCp2R6[0]*phiLx[1]-63739.46971853468*rdxCp2R6[0]*bcVals[1]+((-20784.60969082652*phiLy[0])-20784.60969082652*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+(961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1]+1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0])*rho[2]+((-5455.960043841962*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*volFac+((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-79200.0*rdxCp2Sq[0]*rdxCp2R6[1])+172800.0*rdxCp2R4[0]*rdxCp2R4[1]+48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1])-49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]-34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]-130943.0410522071*phiLy[1]*rdxCp2R8[1]+((-291815.9200592043*rdxCp2Sq[0]*phiLy[1])+72746.13391789283*rdxCp2Sq[0]*phiLx[1]-84000.0*rdxCp2Sq[0]*bcVals[1]+(63000.0*phiLx[0]-43200.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-78773.67072823252*rdxCp2R4[0]*phiLy[1])-70800.0*rdxCp2R4[0]*bcVals[1]-43200.0*phiLy[0]*rdxCp2R4[0])*rdxCp2R4[1]+((-4156.921938165305*rdxCp2R6[0]*phiLy[1])-6928.203230275509*rdxCp2R6[0]*phiLx[1]-20800.0*rdxCp2R6[0]*bcVals[1]+((-6000.0*phiLy[0])-6000.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonGaussSeidel2xSer_UxNeumannUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(25.98076211353316*rdxCp2R4[1]+285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1]+25.98076211353316*rdxCp2R4[0])*rho[1]+150.0*rho[0]*rdxCp2R4[1]+1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+150.0*rdxCp2R4[0]*rho[0])*volFac+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(800.0*rdxCp2R6[1]+8880.0*rdxCp2Sq[0]*rdxCp2R4[1]+400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(346.4101615137754*rdxCp2R6[1]+3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1]+1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+300.0*phiLy[0]*rdxCp2R6[1]+(1039.230484541326*rdxCp2Sq[0]*phiLy[1]+692.8203230275509*rdxCp2Sq[0]*phiLx[1]+400.0*rdxCp2Sq[0]*bcVals[1]+(3420.0*phiLy[0]+600.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(207.8460969082653*rdxCp2R4[0]*phiLy[1]+3949.07584125704*rdxCp2R4[0]*phiLx[1]+8880.0*rdxCp2R4[0]*bcVals[1]+(600.0*phiLy[0]+3420.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*phiLx[1]+800.0*rdxCp2R6[0]*bcVals[1]+300.0*phiLx[0]*rdxCp2R6[0])/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = (((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(450.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+90.0*rdxCp2R4[0])*rho[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+259.8076211353315*rdxCp2R4[0]*rho[0])*volFac+(2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[3]+(15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(6000.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(1800.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[2]+1800.0*phiLy[1]*rdxCp2R6[1]+(6120.0*rdxCp2Sq[0]*phiLy[1]-6000.0*rdxCp2Sq[0]*phiLx[1]+6928.203230275509*rdxCp2Sq[0]*bcVals[1]+(5196.152422706631*phiLy[0]-5196.152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(720.0*rdxCp2R4[0]*phiLy[1]-1200.0*rdxCp2R4[0]*phiLx[1]+24248.71130596428*rdxCp2R4[0]*bcVals[1]+(1039.230484541326*phiLy[0]-1039.230484541326*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0]*bcVals[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = (((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+(90.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+450.0*rdxCp2R4[0])*rho[2]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+259.8076211353315*rho[0]*rdxCp2R4[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+(2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiLx[3]+(2078.460969082652*rdxCp2R6[1]+24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R4[1]+6120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiLx[2]+(1800.0*rdxCp2Sq[0]*phiLy[1]+1200.0*rdxCp2Sq[0]*phiLx[1]+692.8203230275509*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiLy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1800.0*rdxCp2R4[0]*phiLy[1])+6000.0*rdxCp2R4[0]*phiLx[1]+15934.86742963367*rdxCp2R4[0]*bcVals[1]+(5196.152422706631*phiLx[0]-5196.152422706631*phiLy[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+(181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1]+129.9038105676658*rdxCp2R4[0])*rho[2]+(129.9038105676658*rdxCp2R4[1]+181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*volFac+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(5200.0*rdxCp2Sq[0]*rdxCp2R4[1]+2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1]-1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1])-5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-5196.152422706631*rdxCp2Sq[0]*phiLy[1])-1732.050807568877*rdxCp2Sq[0]*phiLx[1]+2000.0*rdxCp2Sq[0]*bcVals[1]+(1500.0*phiLy[0]-1500.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1039.230484541326*rdxCp2R4[0]*phiLy[1])+1732.050807568877*rdxCp2R4[0]*phiLx[1]+5200.0*rdxCp2R4[0]*bcVals[1]+(1500.0*phiLx[0]-1500.0*phiLy[0])*rdxCp2R4[0])*rdxCp2Sq[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double *dxUx = dx[1]; 
  double *dxLx = dx[2]; 
  double *dxUy = dx[3]; 
  double *dxLy = dx[4]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxLx[2]; 
  double rdxUx[2]; 
  double rdxLxSq[2]; 
  double rdxUxSq[2]; 
  double rdxLxCu[2]; 
  double rdxUxCu[2]; 
  double rdxLxR4[2]; 
  double rdxUxR4[2]; 
  double rdxLy[2]; 
  double rdxUy[2]; 
  double rdxLySq[2]; 
  double rdxUySq[2]; 
  double rdxLyCu[2]; 
  double rdxUyCu[2]; 
  double rdxLyR4[2]; 
  double rdxUyR4[2]; 
  rdxCp2[0]  = volFac*4.0/(dxC[0]*dxC[0]); 
  rdxLx[0]   = 1.0/dxLx[0]; 
  rdxUx[0]   = 1.0/dxUx[0]; 
  rdxLxSq[0] = rdxLx[0]*rdxLx[0]; 
  rdxUxSq[0] = rdxUx[0]*rdxUx[0]; 
  rdxLxCu[0] = rdxLxSq[0]*rdxLx[0]; 
  rdxUxCu[0] = rdxUxSq[0]*rdxUx[0]; 
  rdxLxR4[0] = rdxLxCu[0]*rdxLx[0]; 
  rdxUxR4[0] = rdxUxCu[0]*rdxUx[0]; 
  rdxLx[1]   = 1.0/dxLx[1]; 
  rdxUx[1]   = 1.0/dxUx[1]; 
  rdxLxSq[1] = rdxLx[1]*rdxLx[1]; 
  rdxUxSq[1] = rdxUx[1]*rdxUx[1]; 
  rdxLxCu[1] = rdxLxSq[1]*rdxLx[1]; 
  rdxUxCu[1] = rdxUxSq[1]*rdxUx[1]; 
  rdxLxR4[1] = rdxLxCu[1]*rdxLx[1]; 
  rdxUxR4[1] = rdxUxCu[1]*rdxUx[1]; 
  rdxCp2[1]  = volFac*4.0/(dxC[1]*dxC[1]); 
  rdxLy[0]   = 1.0/dxLy[0]; 
  rdxUy[0]   = 1.0/dxUy[0]; 
  rdxLySq[0] = rdxLy[0]*rdxLy[0]; 
  rdxUySq[0] = rdxUy[0]*rdxUy[0]; 
  rdxLyCu[0] = rdxLySq[0]*rdxLy[0]; 
  rdxUyCu[0] = rdxUySq[0]*rdxUy[0]; 
  rdxLyR4[0] = rdxLyCu[0]*rdxLy[0]; 
  rdxUyR4[0] = rdxUyCu[0]*rdxUy[0]; 
  rdxLy[1]   = 1.0/dxLy[1]; 
  rdxUy[1]   = 1.0/dxUy[1]; 
  rdxLySq[1] = rdxLy[1]*rdxLy[1]; 
  rdxUySq[1] = rdxUy[1]*rdxUy[1]; 
  rdxLyCu[1] = rdxLySq[1]*rdxLy[1]; 
  rdxUyCu[1] = rdxUySq[1]*rdxUy[1]; 
  rdxLyR4[1] = rdxLyCu[1]*rdxLy[1]; 
  rdxUyR4[1] = rdxUyCu[1]*rdxUy[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((((12300.0*rdxUx[0]-12300.0*rdxLx[0])*rdxUySq[1]+(12300.0*rdxUxSq[0]-12300.0*rdxLxSq[0])*rdxUy[1]+(12300.0*rdxLx[0]-12300.0*rdxUx[0])*rdxLySq[1]+(12300.0*rdxLxSq[0]-12300.0*rdxUxSq[0])*rdxLy[1])*rho[3]+((-831.384387633061*rdxUyCu[1])+((-54871.36958378201*rdxLy[1])-32666.47823074902*rdxUx[0]-32666.47823074902*rdxLx[0])*rdxUySq[1]+(54871.36958378201*rdxLySq[1]-31835.09384311596*rdxUxSq[0]-9630.202490082957*rdxLx[0]*rdxUx[0]-31835.09384311596*rdxLxSq[0])*rdxUy[1]+831.384387633061*rdxLyCu[1]+(32666.47823074902*rdxUx[0]+32666.47823074902*rdxLx[0])*rdxLySq[1]+(31835.09384311596*rdxUxSq[0]+9630.202490082957*rdxLx[0]*rdxUx[0]+31835.09384311596*rdxLxSq[0])*rdxLy[1])*rho[2]+((31835.09384311596*rdxLx[0]-31835.09384311596*rdxUx[0])*rdxUySq[1]+((9630.202490082957*rdxLx[0]-9630.202490082957*rdxUx[0])*rdxLy[1]-32666.47823074902*rdxUxSq[0]+32666.47823074902*rdxLxSq[0])*rdxUy[1]+(31835.09384311596*rdxLx[0]-31835.09384311596*rdxUx[0])*rdxLySq[1]+(32666.47823074902*rdxLxSq[0]-32666.47823074902*rdxUxSq[0])*rdxLy[1]-831.384387633061*rdxUxCu[0]-54871.36958378201*rdxLx[0]*rdxUxSq[0]+54871.36958378201*rdxLxSq[0]*rdxUx[0]+831.384387633061*rdxLxCu[0])*rho[1]+2208.0*rho[0]*rdxUyCu[1]+(150144.0*rho[0]*rdxLy[1]+(88484.0*rdxUx[0]+88484.0*rdxLx[0])*rho[0])*rdxUySq[1]+(150144.0*rho[0]*rdxLySq[1]+(289288.0*rdxUx[0]+289288.0*rdxLx[0])*rho[0]*rdxLy[1]+(88484.0*rdxUxSq[0]+289288.0*rdxLx[0]*rdxUx[0]+88484.0*rdxLxSq[0])*rho[0])*rdxUy[1]+2208.0*rho[0]*rdxLyCu[1]+(88484.0*rdxUx[0]+88484.0*rdxLx[0])*rho[0]*rdxLySq[1]+(88484.0*rdxUxSq[0]+289288.0*rdxLx[0]*rdxUx[0]+88484.0*rdxLxSq[0])*rho[0]*rdxLy[1]+(2208.0*rdxUxCu[0]+150144.0*rdxLx[0]*rdxUxSq[0]+150144.0*rdxLxSq[0]*rdxUx[0]+2208.0*rdxLxCu[0])*rho[0])*omega*volFac+(((47400.0*rdxUx[0]-47400.0*rdxLx[0])*rdxUyCu[1]+((20850.0*rdxUx[0]-20850.0*rdxLx[0])*rdxLy[1]+49200.0*rdxUxSq[0]-49200.0*rdxLxSq[0])*rdxUySq[1]+((90450.0*rdxUx[0]-90450.0*rdxLx[0])*rdxLySq[1]+(92250.0*rdxUxSq[0]-92250.0*rdxLxSq[0])*rdxLy[1]+1800.0*rdxUxCu[0]+118800.0*rdxLx[0]*rdxUxSq[0]-118800.0*rdxLxSq[0]*rdxUx[0]-1800.0*rdxLxCu[0])*rdxUy[1])*phiUy[3]+(1800.0*rdxUx[0]*rdxUyCu[1]+(118800.0*rdxUx[0]*rdxLy[1]+49200.0*rdxUxSq[0]+92250.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-118800.0*rdxUx[0]*rdxLySq[1])+47400.0*rdxUxCu[0]+20850.0*rdxLx[0]*rdxUxSq[0]+90450.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-1800.0*rdxUx[0]*rdxLyCu[1]+((-49200.0*rdxUxSq[0])-92250.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-47400.0*rdxUxCu[0])-20850.0*rdxLx[0]*rdxUxSq[0]-90450.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[3]+((90450.0*rdxLx[0]-90450.0*rdxUx[0])*rdxLy[1]*rdxUySq[1]+((20850.0*rdxLx[0]-20850.0*rdxUx[0])*rdxLySq[1]+(92250.0*rdxLxSq[0]-92250.0*rdxUxSq[0])*rdxLy[1])*rdxUy[1]+(47400.0*rdxLx[0]-47400.0*rdxUx[0])*rdxLyCu[1]+(49200.0*rdxLxSq[0]-49200.0*rdxUxSq[0])*rdxLySq[1]+((-1800.0*rdxUxCu[0])-118800.0*rdxLx[0]*rdxUxSq[0]+118800.0*rdxLxSq[0]*rdxUx[0]+1800.0*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-1800.0*rdxLx[0]*rdxUyCu[1])+((-118800.0*rdxLx[0]*rdxLy[1])-92250.0*rdxLx[0]*rdxUx[0]-49200.0*rdxLxSq[0])*rdxUySq[1]+(118800.0*rdxLx[0]*rdxLySq[1]-90450.0*rdxLx[0]*rdxUxSq[0]-20850.0*rdxLxSq[0]*rdxUx[0]-47400.0*rdxLxCu[0])*rdxUy[1]+1800.0*rdxLx[0]*rdxLyCu[1]+(92250.0*rdxLx[0]*rdxUx[0]+49200.0*rdxLxSq[0])*rdxLySq[1]+(90450.0*rdxLx[0]*rdxUxSq[0]+20850.0*rdxLxSq[0]*rdxUx[0]+47400.0*rdxLxCu[0])*rdxLy[1])*phiLx[3]+((-1662.768775266122*rdxUyR4[1])+((-114523.1993964541*rdxLy[1])-67203.57133367243*rdxUx[0]-67203.57133367243*rdxLx[0])*rdxUyCu[1]+((-210548.0961680727*rdxLySq[1])+((-313163.4462624908*rdxUx[0])-313163.4462624908*rdxLx[0])*rdxLy[1]-67931.03267285136*rdxUxSq[0]-304737.0190836682*rdxLx[0]*rdxUx[0]-67931.03267285136*rdxLxSq[0])*rdxUySq[1]+((-3117.691453623978*rdxLyCu[1])+((-124369.9082374832*rdxUx[0])-124369.9082374832*rdxLx[0])*rdxLySq[1]+((-123642.4468983043*rdxUxSq[0])-321589.8734413133*rdxLx[0]*rdxUx[0]-123642.4468983043*rdxLxSq[0])*rdxLy[1]-2390.23011444505*rdxUxCu[0]-162535.6477822634*rdxLx[0]*rdxUxSq[0]-162535.6477822634*rdxLxSq[0]*rdxUx[0]-2390.23011444505*rdxLxCu[0])*rdxUy[1])*phiUy[2]+((-1870.614872174387*rdxUx[0]*rdxUyCu[1])+((-123460.5815635095*rdxUx[0]*rdxLy[1])-46869.29485281381*rdxUxSq[0]-100129.8571855568*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(123460.5815635095*rdxUx[0]*rdxLySq[1]-44998.67998063943*rdxUxCu[0]-21667.95560268665*rdxLx[0]*rdxUxSq[0]-98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+1870.614872174387*rdxUx[0]*rdxLyCu[1]+(46869.29485281381*rdxUxSq[0]+100129.8571855568*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(44998.67998063943*rdxUxCu[0]+21667.95560268665*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[2]+(3117.691453623978*rdxLy[1]*rdxUyCu[1]+(210548.0961680727*rdxLySq[1]+(124369.9082374832*rdxUx[0]+124369.9082374832*rdxLx[0])*rdxLy[1])*rdxUySq[1]+(114523.1993964541*rdxLyCu[1]+(313163.4462624908*rdxUx[0]+313163.4462624908*rdxLx[0])*rdxLySq[1]+(123642.4468983043*rdxUxSq[0]+321589.8734413133*rdxLx[0]*rdxUx[0]+123642.4468983043*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+1662.768775266122*rdxLyR4[1]+(67203.57133367243*rdxUx[0]+67203.57133367243*rdxLx[0])*rdxLyCu[1]+(67931.03267285136*rdxUxSq[0]+304737.0190836682*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*rdxLySq[1]+(2390.23011444505*rdxUxCu[0]+162535.6477822634*rdxLx[0]*rdxUxSq[0]+162535.6477822634*rdxLxSq[0]*rdxUx[0]+2390.23011444505*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-1870.614872174387*rdxLx[0]*rdxUyCu[1])+((-123460.5815635095*rdxLx[0]*rdxLy[1])-100129.8571855568*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxLxSq[0])*rdxUySq[1]+(123460.5815635095*rdxLx[0]*rdxLySq[1]-98259.24231338239*rdxLx[0]*rdxUxSq[0]-21667.95560268665*rdxLxSq[0]*rdxUx[0]-44998.67998063943*rdxLxCu[0])*rdxUy[1]+1870.614872174387*rdxLx[0]*rdxLyCu[1]+(100129.8571855568*rdxLx[0]*rdxUx[0]+46869.29485281381*rdxLxSq[0])*rdxLySq[1]+(98259.24231338239*rdxLx[0]*rdxUxSq[0]+21667.95560268665*rdxLxSq[0]*rdxUx[0]+44998.67998063943*rdxLxCu[0])*rdxLy[1])*phiLx[2]+(1584.0*phiUy[0]-144.0*phiC[0])*rdxUyR4[1]+((109512.0*phiUy[0]+3384.0*phiLy[0]-19296.0*phiC[0])*rdxLy[1]+(44998.67998063943*rdxLx[0]-44998.67998063943*rdxUx[0])*phiUy[1]-2390.23011444505*rdxUx[0]*phiUx[1]+2390.23011444505*rdxLx[0]*phiLx[1]+(64182.0*phiUy[0]+2484.0*phiUx[0]-10086.0*phiC[0])*rdxUx[0]+(64182.0*phiUy[0]+2484.0*phiLx[0]-10086.0*phiC[0])*rdxLx[0])*rdxUyCu[1]+((228312.0*phiUy[0]+228312.0*phiLy[0]-646704.0*phiC[0])*rdxLySq[1]+((21667.95560268665*rdxLx[0]-21667.95560268665*rdxUx[0])*phiUy[1]-162535.6477822634*rdxUx[0]*phiUx[1]+(98259.24231338239*rdxLx[0]-98259.24231338239*rdxUx[0])*phiLy[1]+162535.6477822634*rdxLx[0]*phiLx[1]+(325449.0*phiUy[0]+168912.0*phiUx[0]+134907.0*phiLy[0]-685848.0*phiC[0])*rdxUx[0]+(325449.0*phiUy[0]+134907.0*phiLy[0]+168912.0*phiLx[0]-685848.0*phiC[0])*rdxLx[0])*rdxLy[1]+(46869.29485281381*rdxLxSq[0]-46869.29485281381*rdxUxSq[0])*phiUy[1]+((-67931.03267285136*rdxUxSq[0])-123642.4468983043*rdxLx[0]*rdxUx[0])*phiUx[1]+(123642.4468983043*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*phiLx[1]+(65082.0*phiUy[0]+65082.0*phiUx[0]-19884.0*phiC[0])*rdxUxSq[0]+(315024.0*phiUy[0]+134007.0*phiUx[0]+134007.0*phiLx[0]-676638.0*phiC[0])*rdxLx[0]*rdxUx[0]+(65082.0*phiUy[0]+65082.0*phiLx[0]-19884.0*phiC[0])*rdxLxSq[0])*rdxUySq[1]+((3384.0*phiUy[0]+109512.0*phiLy[0]-19296.0*phiC[0])*rdxLyCu[1]+((98259.24231338239*rdxLx[0]-98259.24231338239*rdxUx[0])*phiUy[1]-162535.6477822634*rdxUx[0]*phiUx[1]+(21667.95560268665*rdxLx[0]-21667.95560268665*rdxUx[0])*phiLy[1]+162535.6477822634*rdxLx[0]*phiLx[1]+(134907.0*phiUy[0]+168912.0*phiUx[0]+325449.0*phiLy[0]-685848.0*phiC[0])*rdxUx[0]+(134907.0*phiUy[0]+325449.0*phiLy[0]+168912.0*phiLx[0]-685848.0*phiC[0])*rdxLx[0])*rdxLySq[1]+((100129.8571855568*rdxLxSq[0]-100129.8571855568*rdxUxSq[0])*phiUy[1]+((-304737.0190836682*rdxUxSq[0])-321589.8734413133*rdxLx[0]*rdxUx[0])*phiUx[1]+(100129.8571855568*rdxLxSq[0]-100129.8571855568*rdxUxSq[0])*phiLy[1]+(321589.8734413133*rdxLx[0]*rdxUx[0]+304737.0190836682*rdxLxSq[0])*phiLx[1]+(134007.0*phiUy[0]+315024.0*phiUx[0]+134007.0*phiLy[0]-676638.0*phiC[0])*rdxUxSq[0]+(335874.0*phiUy[0]+335874.0*phiUx[0]+335874.0*phiLy[0]+335874.0*phiLx[0]-1410216.0*phiC[0])*rdxLx[0]*rdxUx[0]+(134007.0*phiUy[0]+134007.0*phiLy[0]+315024.0*phiLx[0]-676638.0*phiC[0])*rdxLxSq[0])*rdxLy[1]+((-1870.614872174387*rdxUxCu[0])-123460.5815635095*rdxLx[0]*rdxUxSq[0]+123460.5815635095*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*phiUy[1]+((-67203.57133367243*rdxUxCu[0])-313163.4462624908*rdxLx[0]*rdxUxSq[0]-124369.9082374832*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(124369.9082374832*rdxLx[0]*rdxUxSq[0]+313163.4462624908*rdxLxSq[0]*rdxUx[0]+67203.57133367243*rdxLxCu[0])*phiLx[1]+(2484.0*phiUy[0]+64182.0*phiUx[0]-10086.0*phiC[0])*rdxUxCu[0]+(168912.0*phiUy[0]+325449.0*phiUx[0]+134907.0*phiLx[0]-685848.0*phiC[0])*rdxLx[0]*rdxUxSq[0]+(168912.0*phiUy[0]+134907.0*phiUx[0]+325449.0*phiLx[0]-685848.0*phiC[0])*rdxLxSq[0]*rdxUx[0]+(2484.0*phiUy[0]+64182.0*phiLx[0]-10086.0*phiC[0])*rdxLxCu[0])*rdxUy[1]+(1584.0*phiLy[0]-144.0*phiC[0])*rdxLyR4[1]+((-2390.23011444505*rdxUx[0]*phiUx[1])+(44998.67998063943*rdxLx[0]-44998.67998063943*rdxUx[0])*phiLy[1]+2390.23011444505*rdxLx[0]*phiLx[1]+(2484.0*phiUx[0]+64182.0*phiLy[0]-10086.0*phiC[0])*rdxUx[0]+(64182.0*phiLy[0]+2484.0*phiLx[0]-10086.0*phiC[0])*rdxLx[0])*rdxLyCu[1]+(((-67931.03267285136*rdxUxSq[0])-123642.4468983043*rdxLx[0]*rdxUx[0])*phiUx[1]+(46869.29485281381*rdxLxSq[0]-46869.29485281381*rdxUxSq[0])*phiLy[1]+(123642.4468983043*rdxLx[0]*rdxUx[0]+67931.03267285136*rdxLxSq[0])*phiLx[1]+(65082.0*phiUx[0]+65082.0*phiLy[0]-19884.0*phiC[0])*rdxUxSq[0]+(134007.0*phiUx[0]+315024.0*phiLy[0]+134007.0*phiLx[0]-676638.0*phiC[0])*rdxLx[0]*rdxUx[0]+(65082.0*phiLy[0]+65082.0*phiLx[0]-19884.0*phiC[0])*rdxLxSq[0])*rdxLySq[1]+(((-67203.57133367243*rdxUxCu[0])-313163.4462624908*rdxLx[0]*rdxUxSq[0]-124369.9082374832*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-1870.614872174387*rdxUxCu[0])-123460.5815635095*rdxLx[0]*rdxUxSq[0]+123460.5815635095*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*phiLy[1]+(124369.9082374832*rdxLx[0]*rdxUxSq[0]+313163.4462624908*rdxLxSq[0]*rdxUx[0]+67203.57133367243*rdxLxCu[0])*phiLx[1]+(64182.0*phiUx[0]+2484.0*phiLy[0]-10086.0*phiC[0])*rdxUxCu[0]+(325449.0*phiUx[0]+168912.0*phiLy[0]+134907.0*phiLx[0]-685848.0*phiC[0])*rdxLx[0]*rdxUxSq[0]+(134907.0*phiUx[0]+168912.0*phiLy[0]+325449.0*phiLx[0]-685848.0*phiC[0])*rdxLxSq[0]*rdxUx[0]+(2484.0*phiLy[0]+64182.0*phiLx[0]-10086.0*phiC[0])*rdxLxCu[0])*rdxLy[1]+((-1662.768775266122*rdxUxR4[0])-114523.1993964541*rdxLx[0]*rdxUxCu[0]-210548.0961680727*rdxLxSq[0]*rdxUxSq[0]-3117.691453623978*rdxLxCu[0]*rdxUx[0])*phiUx[1]+(3117.691453623978*rdxLx[0]*rdxUxCu[0]+210548.0961680727*rdxLxSq[0]*rdxUxSq[0]+114523.1993964541*rdxLxCu[0]*rdxUx[0]+1662.768775266122*rdxLxR4[0])*phiLx[1]+(1584.0*phiUx[0]-144.0*phiC[0])*rdxUxR4[0]+(109512.0*phiUx[0]+3384.0*phiLx[0]-19296.0*phiC[0])*rdxLx[0]*rdxUxCu[0]+(228312.0*phiUx[0]+228312.0*phiLx[0]-646704.0*phiC[0])*rdxLxSq[0]*rdxUxSq[0]+(3384.0*phiUx[0]+109512.0*phiLx[0]-19296.0*phiC[0])*rdxLxCu[0]*rdxUx[0]+(1584.0*phiLx[0]-144.0*phiC[0])*rdxLxR4[0])*omega+144.0*phiC[0]*rdxUyR4[1]+(19296.0*phiC[0]*rdxLy[1]+10086.0*phiC[0]*rdxUx[0]+10086.0*phiC[0]*rdxLx[0])*rdxUyCu[1]+(646704.0*phiC[0]*rdxLySq[1]+(685848.0*phiC[0]*rdxUx[0]+685848.0*phiC[0]*rdxLx[0])*rdxLy[1]+19884.0*phiC[0]*rdxUxSq[0]+676638.0*phiC[0]*rdxLx[0]*rdxUx[0]+19884.0*phiC[0]*rdxLxSq[0])*rdxUySq[1]+(19296.0*phiC[0]*rdxLyCu[1]+(685848.0*phiC[0]*rdxUx[0]+685848.0*phiC[0]*rdxLx[0])*rdxLySq[1]+(676638.0*phiC[0]*rdxUxSq[0]+1410216.0*phiC[0]*rdxLx[0]*rdxUx[0]+676638.0*phiC[0]*rdxLxSq[0])*rdxLy[1]+10086.0*phiC[0]*rdxUxCu[0]+685848.0*phiC[0]*rdxLx[0]*rdxUxSq[0]+685848.0*phiC[0]*rdxLxSq[0]*rdxUx[0]+10086.0*phiC[0]*rdxLxCu[0])*rdxUy[1]+144.0*phiC[0]*rdxLyR4[1]+(10086.0*phiC[0]*rdxUx[0]+10086.0*phiC[0]*rdxLx[0])*rdxLyCu[1]+(19884.0*phiC[0]*rdxUxSq[0]+676638.0*phiC[0]*rdxLx[0]*rdxUx[0]+19884.0*phiC[0]*rdxLxSq[0])*rdxLySq[1]+(10086.0*phiC[0]*rdxUxCu[0]+685848.0*phiC[0]*rdxLx[0]*rdxUxSq[0]+685848.0*phiC[0]*rdxLxSq[0]*rdxUx[0]+10086.0*phiC[0]*rdxLxCu[0])*rdxLy[1]+144.0*phiC[0]*rdxUxR4[0]+19296.0*phiC[0]*rdxLx[0]*rdxUxCu[0]+646704.0*phiC[0]*rdxLxSq[0]*rdxUxSq[0]+19296.0*phiC[0]*rdxLxCu[0]*rdxUx[0]+144.0*phiC[0]*rdxLxR4[0])/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[1] = -(1.0*(((415.6921938165305*rdxUyCu[1]+(27435.68479189101*rdxLy[1]+12782.53495985831*rdxUx[0]+12782.53495985831*rdxLx[0])*rdxUySq[1]+((-27435.68479189101*rdxLySq[1])+12366.84276604178*rdxUxSq[0]-2286.307065990918*rdxLx[0]*rdxUx[0]+12366.84276604178*rdxLxSq[0])*rdxUy[1]-415.6921938165305*rdxLyCu[1]+((-12782.53495985831*rdxUx[0])-12782.53495985831*rdxLx[0])*rdxLySq[1]+((-12366.84276604178*rdxUxSq[0])+2286.307065990918*rdxLx[0]*rdxUx[0]-12366.84276604178*rdxLxSq[0])*rdxLy[1])*rho[3]+((31980.0*rdxLx[0]-31980.0*rdxUx[0])*rdxUySq[1]+(31980.0*rdxLxSq[0]-31980.0*rdxUxSq[0])*rdxUy[1]+(31980.0*rdxUx[0]-31980.0*rdxLx[0])*rdxLySq[1]+(31980.0*rdxUxSq[0]-31980.0*rdxLxSq[0])*rdxLy[1])*rho[2]+((-1104.0*rdxUyCu[1])+((-75072.0*rdxLy[1])-35052.0*rdxUx[0]-35052.0*rdxLx[0])*rdxUySq[1]+((-75072.0*rdxLySq[1])+((-141864.0*rdxUx[0])-141864.0*rdxLx[0])*rdxLy[1]-34812.0*rdxUxSq[0]-125784.0*rdxLx[0]*rdxUx[0]-34812.0*rdxLxSq[0])*rdxUy[1]-1104.0*rdxLyCu[1]+((-35052.0*rdxUx[0])-35052.0*rdxLx[0])*rdxLySq[1]+((-34812.0*rdxUxSq[0])-125784.0*rdxLx[0]*rdxUx[0]-34812.0*rdxLxSq[0])*rdxLy[1]-864.0*rdxUxCu[0]-58752.0*rdxLx[0]*rdxUxSq[0]-58752.0*rdxLxSq[0]*rdxUx[0]-864.0*rdxLxCu[0])*rho[1]+(82771.2439921015*rdxUx[0]-82771.2439921015*rdxLx[0])*rho[0]*rdxUySq[1]+((25038.52647421569*rdxUx[0]-25038.52647421569*rdxLx[0])*rho[0]*rdxLy[1]+(84932.84339994747*rdxUxSq[0]-84932.84339994747*rdxLxSq[0])*rho[0])*rdxUy[1]+(82771.2439921015*rdxUx[0]-82771.2439921015*rdxLx[0])*rho[0]*rdxLySq[1]+(84932.84339994747*rdxUxSq[0]-84932.84339994747*rdxLxSq[0])*rho[0]*rdxLy[1]+(2161.599407845958*rdxUxCu[0]+142665.5609178332*rdxLx[0]*rdxUxSq[0]-142665.5609178332*rdxLxSq[0]*rdxUx[0]-2161.599407845958*rdxLxCu[0])*rho[0])*omega*volFac+((1662.768775266122*rdxUyR4[1]+(114523.1993964541*rdxLy[1]+53520.3699538783*rdxUx[0]+53520.3699538783*rdxLx[0])*rdxUyCu[1]+(210548.0961680727*rdxLySq[1]+(307144.569706189*rdxUx[0]+307144.569706189*rdxLx[0])*rdxLy[1]+53728.21605078656*rdxUxSq[0]+276331.3858395386*rdxLx[0]*rdxUx[0]+53728.21605078656*rdxLxSq[0])*rdxUySq[1]+(3117.691453623978*rdxLyCu[1]+(98259.24231338239*rdxUx[0]+98259.24231338239*rdxLx[0])*rdxLySq[1]+(97012.16573193281*rdxUxSq[0]+268329.3111085704*rdxLx[0]*rdxUx[0]+97012.16573193281*rdxLxSq[0])*rdxLy[1]+1870.614872174387*rdxUxCu[0]+127201.8113078583*rdxLx[0]*rdxUxSq[0]+127201.8113078583*rdxLxSq[0]*rdxUx[0]+1870.614872174387*rdxLxCu[0])*rdxUy[1])*phiUy[3]+((-727.4613391789284*rdxUx[0]*rdxUyCu[1])+((-48012.44838580926*rdxUx[0]*rdxLy[1])+46869.29485281381*rdxUxSq[0]-91608.1672123179*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(48012.44838580926*rdxUx[0]*rdxLySq[1]+47596.75619199274*rdxUxCu[0]+4001.037365484106*rdxLx[0]*rdxUxSq[0]-90880.70587313897*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+727.4613391789284*rdxUx[0]*rdxLyCu[1]+(91608.1672123179*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxUxSq[0])*rdxLySq[1]+((-47596.75619199274*rdxUxCu[0])-4001.037365484106*rdxLx[0]*rdxUxSq[0]+90880.70587313897*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[3]+((-3117.691453623978*rdxLy[1]*rdxUyCu[1])+(((-98259.24231338239*rdxUx[0])-98259.24231338239*rdxLx[0])*rdxLy[1]-210548.0961680727*rdxLySq[1])*rdxUySq[1]+((-114523.1993964541*rdxLyCu[1])+((-307144.569706189*rdxUx[0])-307144.569706189*rdxLx[0])*rdxLySq[1]+((-97012.16573193281*rdxUxSq[0])-268329.3111085704*rdxLx[0]*rdxUx[0]-97012.16573193281*rdxLxSq[0])*rdxLy[1])*rdxUy[1]-1662.768775266122*rdxLyR4[1]+((-53520.3699538783*rdxUx[0])-53520.3699538783*rdxLx[0])*rdxLyCu[1]+((-53728.21605078656*rdxUxSq[0])-276331.3858395386*rdxLx[0]*rdxUx[0]-53728.21605078656*rdxLxSq[0])*rdxLySq[1]+((-1870.614872174387*rdxUxCu[0])-127201.8113078583*rdxLx[0]*rdxUxSq[0]-127201.8113078583*rdxLxSq[0]*rdxUx[0]-1870.614872174387*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-727.4613391789284*rdxLx[0]*rdxUyCu[1])+((-48012.44838580926*rdxLx[0]*rdxLy[1])-91608.1672123179*rdxLx[0]*rdxUx[0]+46869.29485281381*rdxLxSq[0])*rdxUySq[1]+(48012.44838580926*rdxLx[0]*rdxLySq[1]-90880.70587313897*rdxLx[0]*rdxUxSq[0]+4001.037365484106*rdxLxSq[0]*rdxUx[0]+47596.75619199274*rdxLxCu[0])*rdxUy[1]+727.4613391789284*rdxLx[0]*rdxLyCu[1]+(91608.1672123179*rdxLx[0]*rdxUx[0]-46869.29485281381*rdxLxSq[0])*rdxLySq[1]+(90880.70587313897*rdxLx[0]*rdxUxSq[0]-4001.037365484106*rdxLxSq[0]*rdxUx[0]-47596.75619199274*rdxLxCu[0])*rdxLy[1])*phiLx[3]+((61620.0*rdxLx[0]-61620.0*rdxUx[0])*rdxUyCu[1]+((27105.0*rdxLx[0]-27105.0*rdxUx[0])*rdxLy[1]-63960.0*rdxUxSq[0]+63960.0*rdxLxSq[0])*rdxUySq[1]+((117585.0*rdxLx[0]-117585.0*rdxUx[0])*rdxLySq[1]+(119925.0*rdxLxSq[0]-119925.0*rdxUxSq[0])*rdxLy[1]-2340.0*rdxUxCu[0]-154440.0*rdxLx[0]*rdxUxSq[0]+154440.0*rdxLxSq[0]*rdxUx[0]+2340.0*rdxLxCu[0])*rdxUy[1])*phiUy[2]+(900.0*rdxUx[0]*rdxUyCu[1]+(59400.0*rdxUx[0]*rdxLy[1]-44280.0*rdxUxSq[0]+99630.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-59400.0*rdxUx[0]*rdxLySq[1])-45180.0*rdxUxCu[0]-4950.0*rdxLx[0]*rdxUxSq[0]+98730.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-900.0*rdxUx[0]*rdxLyCu[1]+(44280.0*rdxUxSq[0]-99630.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(45180.0*rdxUxCu[0]+4950.0*rdxLx[0]*rdxUxSq[0]-98730.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1])*phiUx[2]+((117585.0*rdxUx[0]-117585.0*rdxLx[0])*rdxLy[1]*rdxUySq[1]+((27105.0*rdxUx[0]-27105.0*rdxLx[0])*rdxLySq[1]+(119925.0*rdxUxSq[0]-119925.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+(61620.0*rdxUx[0]-61620.0*rdxLx[0])*rdxLyCu[1]+(63960.0*rdxUxSq[0]-63960.0*rdxLxSq[0])*rdxLySq[1]+(2340.0*rdxUxCu[0]+154440.0*rdxLx[0]*rdxUxSq[0]-154440.0*rdxLxSq[0]*rdxUx[0]-2340.0*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-900.0*rdxLx[0]*rdxUyCu[1])+((-59400.0*rdxLx[0]*rdxLy[1])-99630.0*rdxLx[0]*rdxUx[0]+44280.0*rdxLxSq[0])*rdxUySq[1]+(59400.0*rdxLx[0]*rdxLySq[1]-98730.0*rdxLx[0]*rdxUxSq[0]+4950.0*rdxLxSq[0]*rdxUx[0]+45180.0*rdxLxCu[0])*rdxUy[1]+900.0*rdxLx[0]*rdxLyCu[1]+(99630.0*rdxLx[0]*rdxUx[0]-44280.0*rdxLxSq[0])*rdxLySq[1]+(98730.0*rdxLx[0]*rdxUxSq[0]-4950.0*rdxLxSq[0]*rdxUx[0]-45180.0*rdxLxCu[0])*rdxLy[1])*phiLx[2]+(144.0*phiC[1]-1584.0*phiUy[1])*rdxUyR4[1]+(((-109512.0*phiUy[1])-3384.0*phiLy[1]+19296.0*phiC[1])*rdxLy[1]+((-51192.0*rdxUx[0])-51192.0*rdxLx[0])*phiUy[1]+966.0*rdxUx[0]*phiUx[1]+966.0*rdxLx[0]*phiLx[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*phiC[1]+(58498.28397483125*phiUy[0]-1195.115057222525*phiUx[0])*rdxUx[0]+(1195.115057222525*phiLx[0]-58498.28397483125*phiUy[0])*rdxLx[0])*rdxUyCu[1]+(((-228312.0*phiUy[1])-228312.0*phiLy[1]+646704.0*phiC[1])*rdxLySq[1]+(((-319194.0*rdxUx[0])-319194.0*rdxLx[0])*phiUy[1]+65688.0*rdxUx[0]*phiUx[1]+((-106542.0*rdxUx[0])-106542.0*rdxLx[0])*phiLy[1]+65688.0*rdxLx[0]*phiLx[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*phiC[1]+(28168.34228349264*phiUy[0]-81267.82389113172*phiUx[0]+127737.0150073971*phiLy[0])*rdxUx[0]+((-28168.34228349264*phiUy[0])-127737.0150073971*phiLy[0]+81267.82389113172*phiLx[0])*rdxLx[0])*rdxLy[1]+((-51552.0*rdxUxSq[0])-287964.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*phiUy[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxUxSq[0])*phiUx[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*phiLx[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*phiC[1]+(60930.08330865796*phiUy[0]+55172.74642429901*phiUx[0])*rdxUxSq[0]+(131062.5525579294*phiLx[0]-131062.5525579294*phiUx[0])*rdxLx[0]*rdxUx[0]+((-60930.08330865796*phiUy[0])-55172.74642429901*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+(((-3384.0*phiUy[1])-109512.0*phiLy[1]+19296.0*phiC[1])*rdxLyCu[1]+(((-106542.0*rdxUx[0])-106542.0*rdxLx[0])*phiUy[1]+65688.0*rdxUx[0]*phiUx[1]+((-319194.0*rdxUx[0])-319194.0*rdxLx[0])*phiLy[1]+65688.0*rdxLx[0]*phiLx[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*phiC[1]+(127737.0150073971*phiUy[0]-81267.82389113172*phiUx[0]+28168.34228349264*phiLy[0])*rdxUx[0]+((-127737.0150073971*phiUy[0])-28168.34228349264*phiLy[0]+81267.82389113172*phiLx[0])*rdxLx[0])*rdxLySq[1]+(((-105102.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0]-105102.0*rdxLxSq[0])*phiUy[1]+(97026.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0])*phiUx[1]+((-105102.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0]-105102.0*rdxLxSq[0])*phiLy[1]+(151236.0*rdxLx[0]*rdxUx[0]+97026.0*rdxLxSq[0])*phiLx[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*phiC[1]+(130168.8143412238*phiUy[0]-125403.9425696018*phiUx[0]+130168.8143412238*phiLy[0])*rdxUxSq[0]+(181740.6271365871*phiLx[0]-181740.6271365871*phiUx[0])*rdxLx[0]*rdxUx[0]+((-130168.8143412238*phiUy[0])-130168.8143412238*phiLy[0]+125403.9425696018*phiLx[0])*rdxLxSq[0])*rdxLy[1]+((-1944.0*rdxUxCu[0])-132192.0*rdxLx[0]*rdxUxSq[0]-132192.0*rdxLxSq[0]*rdxUx[0]-1944.0*rdxLxCu[0])*phiUy[1]+((-61482.0*rdxUxCu[0])+110061.0*rdxLx[0]*rdxUxSq[0]+122403.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(122403.0*rdxLx[0]*rdxUxSq[0]+110061.0*rdxLxSq[0]*rdxUx[0]-61482.0*rdxLxCu[0])*phiLx[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*phiC[1]+(2431.799333826703*phiUy[0]+57864.35337926103*phiUx[0])*rdxUxCu[0]+(160498.7560325623*phiUy[0]-136165.1742370272*phiUx[0]+133234.5442706207*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-160498.7560325623*phiUy[0])-133234.5442706207*phiUx[0]+136165.1742370272*phiLx[0])*rdxLxSq[0]*rdxUx[0]+((-2431.799333826703*phiUy[0])-57864.35337926103*phiLx[0])*rdxLxCu[0])*rdxUy[1]+(144.0*phiC[1]-1584.0*phiLy[1])*rdxLyR4[1]+(966.0*rdxUx[0]*phiUx[1]+((-51192.0*rdxUx[0])-51192.0*rdxLx[0])*phiLy[1]+966.0*rdxLx[0]*phiLx[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*phiC[1]+(58498.28397483125*phiLy[0]-1195.115057222525*phiUx[0])*rdxUx[0]+(1195.115057222525*phiLx[0]-58498.28397483125*phiLy[0])*rdxLx[0])*rdxLyCu[1]+((120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxUxSq[0])*phiUx[1]+((-51552.0*rdxUxSq[0])-287964.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*phiLy[1]+(120273.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*phiLx[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*phiC[1]+(55172.74642429901*phiUx[0]+60930.08330865796*phiLy[0])*rdxUxSq[0]+(131062.5525579294*phiLx[0]-131062.5525579294*phiUx[0])*rdxLx[0]*rdxUx[0]+((-60930.08330865796*phiLy[0])-55172.74642429901*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+(((-61482.0*rdxUxCu[0])+110061.0*rdxLx[0]*rdxUxSq[0]+122403.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-1944.0*rdxUxCu[0])-132192.0*rdxLx[0]*rdxUxSq[0]-132192.0*rdxLxSq[0]*rdxUx[0]-1944.0*rdxLxCu[0])*phiLy[1]+(122403.0*rdxLx[0]*rdxUxSq[0]+110061.0*rdxLxSq[0]*rdxUx[0]-61482.0*rdxLxCu[0])*phiLx[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*phiC[1]+(57864.35337926103*phiUx[0]+2431.799333826703*phiLy[0])*rdxUxCu[0]+((-136165.1742370272*phiUx[0])+160498.7560325623*phiLy[0]+133234.5442706207*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-133234.5442706207*phiUx[0])-160498.7560325623*phiLy[0]+136165.1742370272*phiLx[0])*rdxLxSq[0]*rdxUx[0]+((-2431.799333826703*phiLy[0])-57864.35337926103*phiLx[0])*rdxLxCu[0])*rdxLy[1]+((-1584.0*rdxUxR4[0])-103032.0*rdxLx[0]*rdxUxCu[0]+205848.0*rdxLxSq[0]*rdxUxSq[0]+3096.0*rdxLxCu[0]*rdxUx[0])*phiUx[1]+(3096.0*rdxLx[0]*rdxUxCu[0]+205848.0*rdxLxSq[0]*rdxUxSq[0]-103032.0*rdxLxCu[0]*rdxUx[0]-1584.0*rdxLxR4[0])*phiLx[1]+(144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0])*phiC[1]+1496.491897739509*phiUx[0]*rdxUxR4[0]+(96897.85037863323*phiUx[0]+3367.106769913895*phiLx[0])*rdxLx[0]*rdxUxCu[0]+(224099.6616864915*phiLx[0]-224099.6616864915*phiUx[0])*rdxLxSq[0]*rdxUxSq[0]+((-3367.106769913895*phiUx[0])-96897.85037863323*phiLx[0])*rdxLxCu[0]*rdxUx[0]-1496.491897739509*phiLx[0]*rdxLxR4[0])*omega-144.0*phiC[1]*rdxUyR4[1]+(((-10086.0*rdxUx[0])-10086.0*rdxLx[0])*phiC[1]-19296.0*phiC[1]*rdxLy[1])*rdxUyCu[1]+((-646704.0*phiC[1]*rdxLySq[1])+((-685848.0*rdxUx[0])-685848.0*rdxLx[0])*phiC[1]*rdxLy[1]+((-19884.0*rdxUxSq[0])-676638.0*rdxLx[0]*rdxUx[0]-19884.0*rdxLxSq[0])*phiC[1])*rdxUySq[1]+((-19296.0*phiC[1]*rdxLyCu[1])+((-685848.0*rdxUx[0])-685848.0*rdxLx[0])*phiC[1]*rdxLySq[1]+((-676638.0*rdxUxSq[0])-1410216.0*rdxLx[0]*rdxUx[0]-676638.0*rdxLxSq[0])*phiC[1]*rdxLy[1]+((-10086.0*rdxUxCu[0])-685848.0*rdxLx[0]*rdxUxSq[0]-685848.0*rdxLxSq[0]*rdxUx[0]-10086.0*rdxLxCu[0])*phiC[1])*rdxUy[1]-144.0*phiC[1]*rdxLyR4[1]+((-10086.0*rdxUx[0])-10086.0*rdxLx[0])*phiC[1]*rdxLyCu[1]+((-19884.0*rdxUxSq[0])-676638.0*rdxLx[0]*rdxUx[0]-19884.0*rdxLxSq[0])*phiC[1]*rdxLySq[1]+((-10086.0*rdxUxCu[0])-685848.0*rdxLx[0]*rdxUxSq[0]-685848.0*rdxLxSq[0]*rdxUx[0]-10086.0*rdxLxCu[0])*phiC[1]*rdxLy[1]+((-144.0*rdxUxR4[0])-19296.0*rdxLx[0]*rdxUxCu[0]-646704.0*rdxLxSq[0]*rdxUxSq[0]-19296.0*rdxLxCu[0]*rdxUx[0]-144.0*rdxLxR4[0])*phiC[1]))/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[2] = -(1.0*((((12366.84276604178*rdxUx[0]-12366.84276604178*rdxLx[0])*rdxUySq[1]+((2286.307065990918*rdxLx[0]-2286.307065990918*rdxUx[0])*rdxLy[1]+12782.53495985831*rdxUxSq[0]-12782.53495985831*rdxLxSq[0])*rdxUy[1]+(12366.84276604178*rdxUx[0]-12366.84276604178*rdxLx[0])*rdxLySq[1]+(12782.53495985831*rdxUxSq[0]-12782.53495985831*rdxLxSq[0])*rdxLy[1]+415.6921938165305*rdxUxCu[0]+27435.68479189101*rdxLx[0]*rdxUxSq[0]-27435.68479189101*rdxLxSq[0]*rdxUx[0]-415.6921938165305*rdxLxCu[0])*rho[3]+((-864.0*rdxUyCu[1])+((-58752.0*rdxLy[1])-34812.0*rdxUx[0]-34812.0*rdxLx[0])*rdxUySq[1]+((-58752.0*rdxLySq[1])+((-125784.0*rdxUx[0])-125784.0*rdxLx[0])*rdxLy[1]-35052.0*rdxUxSq[0]-141864.0*rdxLx[0]*rdxUx[0]-35052.0*rdxLxSq[0])*rdxUy[1]-864.0*rdxLyCu[1]+((-34812.0*rdxUx[0])-34812.0*rdxLx[0])*rdxLySq[1]+((-35052.0*rdxUxSq[0])-141864.0*rdxLx[0]*rdxUx[0]-35052.0*rdxLxSq[0])*rdxLy[1]-1104.0*rdxUxCu[0]-75072.0*rdxLx[0]*rdxUxSq[0]-75072.0*rdxLxSq[0]*rdxUx[0]-1104.0*rdxLxCu[0])*rho[2]+((31980.0*rdxLx[0]-31980.0*rdxUx[0])*rdxUySq[1]+(31980.0*rdxLxSq[0]-31980.0*rdxUxSq[0])*rdxUy[1]+(31980.0*rdxUx[0]-31980.0*rdxLx[0])*rdxLySq[1]+(31980.0*rdxUxSq[0]-31980.0*rdxLxSq[0])*rdxLy[1])*rho[1]+2161.599407845958*rho[0]*rdxUyCu[1]+(142665.5609178332*rho[0]*rdxLy[1]+(84932.84339994747*rdxUx[0]+84932.84339994747*rdxLx[0])*rho[0])*rdxUySq[1]+((82771.2439921015*rdxUxSq[0]+25038.52647421569*rdxLx[0]*rdxUx[0]+82771.2439921015*rdxLxSq[0])*rho[0]-142665.5609178332*rho[0]*rdxLySq[1])*rdxUy[1]-2161.599407845958*rho[0]*rdxLyCu[1]+((-84932.84339994747*rdxUx[0])-84932.84339994747*rdxLx[0])*rho[0]*rdxLySq[1]+((-82771.2439921015*rdxUxSq[0])-25038.52647421569*rdxLx[0]*rdxUx[0]-82771.2439921015*rdxLxSq[0])*rho[0]*rdxLy[1])*omega*volFac+(((47596.75619199274*rdxUx[0]-47596.75619199274*rdxLx[0])*rdxUyCu[1]+((4001.037365484106*rdxUx[0]-4001.037365484106*rdxLx[0])*rdxLy[1]+46869.29485281381*rdxUxSq[0]-46869.29485281381*rdxLxSq[0])*rdxUySq[1]+((90880.70587313897*rdxLx[0]-90880.70587313897*rdxUx[0])*rdxLySq[1]+(91608.1672123179*rdxLxSq[0]-91608.1672123179*rdxUxSq[0])*rdxLy[1]-727.4613391789284*rdxUxCu[0]-48012.44838580926*rdxLx[0]*rdxUxSq[0]+48012.44838580926*rdxLxSq[0]*rdxUx[0]+727.4613391789284*rdxLxCu[0])*rdxUy[1])*phiUy[3]+(1870.614872174387*rdxUx[0]*rdxUyCu[1]+(127201.8113078583*rdxUx[0]*rdxLy[1]+53728.21605078656*rdxUxSq[0]+97012.16573193281*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(127201.8113078583*rdxUx[0]*rdxLySq[1]+(276331.3858395386*rdxUxSq[0]+268329.3111085704*rdxLx[0]*rdxUx[0])*rdxLy[1]+53520.3699538783*rdxUxCu[0]+307144.569706189*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+1870.614872174387*rdxUx[0]*rdxLyCu[1]+(53728.21605078656*rdxUxSq[0]+97012.16573193281*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(53520.3699538783*rdxUxCu[0]+307144.569706189*rdxLx[0]*rdxUxSq[0]+98259.24231338239*rdxLxSq[0]*rdxUx[0])*rdxLy[1]+1662.768775266122*rdxUxR4[0]+114523.1993964541*rdxLx[0]*rdxUxCu[0]+210548.0961680727*rdxLxSq[0]*rdxUxSq[0]+3117.691453623978*rdxLxCu[0]*rdxUx[0])*phiUx[3]+((90880.70587313897*rdxLx[0]-90880.70587313897*rdxUx[0])*rdxLy[1]*rdxUySq[1]+((4001.037365484106*rdxUx[0]-4001.037365484106*rdxLx[0])*rdxLySq[1]+(91608.1672123179*rdxLxSq[0]-91608.1672123179*rdxUxSq[0])*rdxLy[1])*rdxUy[1]+(47596.75619199274*rdxUx[0]-47596.75619199274*rdxLx[0])*rdxLyCu[1]+(46869.29485281381*rdxUxSq[0]-46869.29485281381*rdxLxSq[0])*rdxLySq[1]+((-727.4613391789284*rdxUxCu[0])-48012.44838580926*rdxLx[0]*rdxUxSq[0]+48012.44838580926*rdxLxSq[0]*rdxUx[0]+727.4613391789284*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-1870.614872174387*rdxLx[0]*rdxUyCu[1])+((-127201.8113078583*rdxLx[0]*rdxLy[1])-97012.16573193281*rdxLx[0]*rdxUx[0]-53728.21605078656*rdxLxSq[0])*rdxUySq[1]+((-127201.8113078583*rdxLx[0]*rdxLySq[1])+((-268329.3111085704*rdxLx[0]*rdxUx[0])-276331.3858395386*rdxLxSq[0])*rdxLy[1]-98259.24231338239*rdxLx[0]*rdxUxSq[0]-307144.569706189*rdxLxSq[0]*rdxUx[0]-53520.3699538783*rdxLxCu[0])*rdxUy[1]-1870.614872174387*rdxLx[0]*rdxLyCu[1]+((-97012.16573193281*rdxLx[0]*rdxUx[0])-53728.21605078656*rdxLxSq[0])*rdxLySq[1]+((-98259.24231338239*rdxLx[0]*rdxUxSq[0])-307144.569706189*rdxLxSq[0]*rdxUx[0]-53520.3699538783*rdxLxCu[0])*rdxLy[1]-3117.691453623978*rdxLx[0]*rdxUxCu[0]-210548.0961680727*rdxLxSq[0]*rdxUxSq[0]-114523.1993964541*rdxLxCu[0]*rdxUx[0]-1662.768775266122*rdxLxR4[0])*phiLx[3]+((-1584.0*rdxUyR4[1])+((-103032.0*rdxLy[1])-61482.0*rdxUx[0]-61482.0*rdxLx[0])*rdxUyCu[1]+(205848.0*rdxLySq[1]+(110061.0*rdxUx[0]+110061.0*rdxLx[0])*rdxLy[1]-58932.0*rdxUxSq[0]+97026.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*rdxUySq[1]+(3096.0*rdxLyCu[1]+(122403.0*rdxUx[0]+122403.0*rdxLx[0])*rdxLySq[1]+(120273.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0]+120273.0*rdxLxSq[0])*rdxLy[1]+966.0*rdxUxCu[0]+65688.0*rdxLx[0]*rdxUxSq[0]+65688.0*rdxLxSq[0]*rdxUx[0]+966.0*rdxLxCu[0])*rdxUy[1])*phiUy[2]+((-1944.0*rdxUx[0]*rdxUyCu[1])+((-132192.0*rdxUx[0]*rdxLy[1])-51552.0*rdxUxSq[0]-105102.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-132192.0*rdxUx[0]*rdxLySq[1])+((-287964.0*rdxUxSq[0])-278064.0*rdxLx[0]*rdxUx[0])*rdxLy[1]-51192.0*rdxUxCu[0]-319194.0*rdxLx[0]*rdxUxSq[0]-106542.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-1944.0*rdxUx[0]*rdxLyCu[1]+((-51552.0*rdxUxSq[0])-105102.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-51192.0*rdxUxCu[0])-319194.0*rdxLx[0]*rdxUxSq[0]-106542.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1]-1584.0*rdxUxR4[0]-109512.0*rdxLx[0]*rdxUxCu[0]-228312.0*rdxLxSq[0]*rdxUxSq[0]-3384.0*rdxLxCu[0]*rdxUx[0])*phiUx[2]+(3096.0*rdxLy[1]*rdxUyCu[1]+(205848.0*rdxLySq[1]+(122403.0*rdxUx[0]+122403.0*rdxLx[0])*rdxLy[1])*rdxUySq[1]+((-103032.0*rdxLyCu[1])+(110061.0*rdxUx[0]+110061.0*rdxLx[0])*rdxLySq[1]+(120273.0*rdxUxSq[0]+151236.0*rdxLx[0]*rdxUx[0]+120273.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]-1584.0*rdxLyR4[1]+((-61482.0*rdxUx[0])-61482.0*rdxLx[0])*rdxLyCu[1]+((-58932.0*rdxUxSq[0])+97026.0*rdxLx[0]*rdxUx[0]-58932.0*rdxLxSq[0])*rdxLySq[1]+(966.0*rdxUxCu[0]+65688.0*rdxLx[0]*rdxUxSq[0]+65688.0*rdxLxSq[0]*rdxUx[0]+966.0*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-1944.0*rdxLx[0]*rdxUyCu[1])+((-132192.0*rdxLx[0]*rdxLy[1])-105102.0*rdxLx[0]*rdxUx[0]-51552.0*rdxLxSq[0])*rdxUySq[1]+((-132192.0*rdxLx[0]*rdxLySq[1])+((-278064.0*rdxLx[0]*rdxUx[0])-287964.0*rdxLxSq[0])*rdxLy[1]-106542.0*rdxLx[0]*rdxUxSq[0]-319194.0*rdxLxSq[0]*rdxUx[0]-51192.0*rdxLxCu[0])*rdxUy[1]-1944.0*rdxLx[0]*rdxLyCu[1]+((-105102.0*rdxLx[0]*rdxUx[0])-51552.0*rdxLxSq[0])*rdxLySq[1]+((-106542.0*rdxLx[0]*rdxUxSq[0])-319194.0*rdxLxSq[0]*rdxUx[0]-51192.0*rdxLxCu[0])*rdxLy[1]-3384.0*rdxLx[0]*rdxUxCu[0]-228312.0*rdxLxSq[0]*rdxUxSq[0]-109512.0*rdxLxCu[0]*rdxUx[0]-1584.0*rdxLxR4[0])*phiLx[2]+(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0])*phiC[2]+1496.491897739509*phiUy[0]*rdxUyR4[1]+((96897.85037863323*phiUy[0]+3367.106769913895*phiLy[0])*rdxLy[1]+(45180.0*rdxLx[0]-45180.0*rdxUx[0])*phiUy[1]-2340.0*rdxUx[0]*phiUx[1]+2340.0*rdxLx[0]*phiLx[1]+(57864.35337926103*phiUy[0]+2431.799333826703*phiUx[0])*rdxUx[0]+(57864.35337926103*phiUy[0]+2431.799333826703*phiLx[0])*rdxLx[0])*rdxUyCu[1]+((224099.6616864915*phiLy[0]-224099.6616864915*phiUy[0])*rdxLySq[1]+((4950.0*rdxLx[0]-4950.0*rdxUx[0])*phiUy[1]-154440.0*rdxUx[0]*phiUx[1]+(98730.0*rdxLx[0]-98730.0*rdxUx[0])*phiLy[1]+154440.0*rdxLx[0]*phiLx[1]+((-136165.1742370272*phiUy[0])+160498.7560325623*phiUx[0]+133234.5442706207*phiLy[0])*rdxUx[0]+((-136165.1742370272*phiUy[0])+133234.5442706207*phiLy[0]+160498.7560325623*phiLx[0])*rdxLx[0])*rdxLy[1]+(44280.0*rdxLxSq[0]-44280.0*rdxUxSq[0])*phiUy[1]+((-63960.0*rdxUxSq[0])-119925.0*rdxLx[0]*rdxUx[0])*phiUx[1]+(119925.0*rdxLx[0]*rdxUx[0]+63960.0*rdxLxSq[0])*phiLx[1]+(55172.74642429901*phiUy[0]+60930.08330865796*phiUx[0])*rdxUxSq[0]+((-125403.9425696018*phiUy[0])+130168.8143412238*phiUx[0]+130168.8143412238*phiLx[0])*rdxLx[0]*rdxUx[0]+(55172.74642429901*phiUy[0]+60930.08330865796*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+(((-3367.106769913895*phiUy[0])-96897.85037863323*phiLy[0])*rdxLyCu[1]+((98730.0*rdxUx[0]-98730.0*rdxLx[0])*phiUy[1]+154440.0*rdxUx[0]*phiUx[1]+(4950.0*rdxUx[0]-4950.0*rdxLx[0])*phiLy[1]-154440.0*rdxLx[0]*phiLx[1]+((-133234.5442706207*phiUy[0])-160498.7560325623*phiUx[0]+136165.1742370272*phiLy[0])*rdxUx[0]+((-133234.5442706207*phiUy[0])+136165.1742370272*phiLy[0]-160498.7560325623*phiLx[0])*rdxLx[0])*rdxLySq[1]+((99630.0*rdxUxSq[0]-99630.0*rdxLxSq[0])*phiUy[1]+(99630.0*rdxLxSq[0]-99630.0*rdxUxSq[0])*phiLy[1]+(131062.5525579294*phiLy[0]-131062.5525579294*phiUy[0])*rdxUxSq[0]+(181740.6271365871*phiLy[0]-181740.6271365871*phiUy[0])*rdxLx[0]*rdxUx[0]+(131062.5525579294*phiLy[0]-131062.5525579294*phiUy[0])*rdxLxSq[0])*rdxLy[1]+(900.0*rdxUxCu[0]+59400.0*rdxLx[0]*rdxUxSq[0]-59400.0*rdxLxSq[0]*rdxUx[0]-900.0*rdxLxCu[0])*phiUy[1]+((-61620.0*rdxUxCu[0])-27105.0*rdxLx[0]*rdxUxSq[0]-117585.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(117585.0*rdxLx[0]*rdxUxSq[0]+27105.0*rdxLxSq[0]*rdxUx[0]+61620.0*rdxLxCu[0])*phiLx[1]+(58498.28397483125*phiUx[0]-1195.115057222525*phiUy[0])*rdxUxCu[0]+((-81267.82389113172*phiUy[0])+28168.34228349264*phiUx[0]+127737.0150073971*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-81267.82389113172*phiUy[0])+127737.0150073971*phiUx[0]+28168.34228349264*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(58498.28397483125*phiLx[0]-1195.115057222525*phiUy[0])*rdxLxCu[0])*rdxUy[1]-1496.491897739509*phiLy[0]*rdxLyR4[1]+(2340.0*rdxUx[0]*phiUx[1]+(45180.0*rdxUx[0]-45180.0*rdxLx[0])*phiLy[1]-2340.0*rdxLx[0]*phiLx[1]+((-2431.799333826703*phiUx[0])-57864.35337926103*phiLy[0])*rdxUx[0]+((-57864.35337926103*phiLy[0])-2431.799333826703*phiLx[0])*rdxLx[0])*rdxLyCu[1]+((63960.0*rdxUxSq[0]+119925.0*rdxLx[0]*rdxUx[0])*phiUx[1]+(44280.0*rdxUxSq[0]-44280.0*rdxLxSq[0])*phiLy[1]+((-119925.0*rdxLx[0]*rdxUx[0])-63960.0*rdxLxSq[0])*phiLx[1]+((-60930.08330865796*phiUx[0])-55172.74642429901*phiLy[0])*rdxUxSq[0]+((-130168.8143412238*phiUx[0])+125403.9425696018*phiLy[0]-130168.8143412238*phiLx[0])*rdxLx[0]*rdxUx[0]+((-55172.74642429901*phiLy[0])-60930.08330865796*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+((61620.0*rdxUxCu[0]+27105.0*rdxLx[0]*rdxUxSq[0]+117585.0*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-900.0*rdxUxCu[0])-59400.0*rdxLx[0]*rdxUxSq[0]+59400.0*rdxLxSq[0]*rdxUx[0]+900.0*rdxLxCu[0])*phiLy[1]+((-117585.0*rdxLx[0]*rdxUxSq[0])-27105.0*rdxLxSq[0]*rdxUx[0]-61620.0*rdxLxCu[0])*phiLx[1]+(1195.115057222525*phiLy[0]-58498.28397483125*phiUx[0])*rdxUxCu[0]+((-28168.34228349264*phiUx[0])+81267.82389113172*phiLy[0]-127737.0150073971*phiLx[0])*rdxLx[0]*rdxUxSq[0]+((-127737.0150073971*phiUx[0])+81267.82389113172*phiLy[0]-28168.34228349264*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(1195.115057222525*phiLy[0]-58498.28397483125*phiLx[0])*rdxLxCu[0])*rdxLy[1])*omega+((-144.0*rdxUyR4[1])+((-19296.0*rdxLy[1])-10086.0*rdxUx[0]-10086.0*rdxLx[0])*rdxUyCu[1]+((-646704.0*rdxLySq[1])+((-685848.0*rdxUx[0])-685848.0*rdxLx[0])*rdxLy[1]-19884.0*rdxUxSq[0]-676638.0*rdxLx[0]*rdxUx[0]-19884.0*rdxLxSq[0])*rdxUySq[1]+((-19296.0*rdxLyCu[1])+((-685848.0*rdxUx[0])-685848.0*rdxLx[0])*rdxLySq[1]+((-676638.0*rdxUxSq[0])-1410216.0*rdxLx[0]*rdxUx[0]-676638.0*rdxLxSq[0])*rdxLy[1]-10086.0*rdxUxCu[0]-685848.0*rdxLx[0]*rdxUxSq[0]-685848.0*rdxLxSq[0]*rdxUx[0]-10086.0*rdxLxCu[0])*rdxUy[1]-144.0*rdxLyR4[1]+((-10086.0*rdxUx[0])-10086.0*rdxLx[0])*rdxLyCu[1]+((-19884.0*rdxUxSq[0])-676638.0*rdxLx[0]*rdxUx[0]-19884.0*rdxLxSq[0])*rdxLySq[1]+((-10086.0*rdxUxCu[0])-685848.0*rdxLx[0]*rdxUxSq[0]-685848.0*rdxLxSq[0]*rdxUx[0]-10086.0*rdxLxCu[0])*rdxLy[1]-144.0*rdxUxR4[0]-19296.0*rdxLx[0]*rdxUxCu[0]-646704.0*rdxLxSq[0]*rdxUxSq[0]-19296.0*rdxLxCu[0]*rdxUx[0]-144.0*rdxLxR4[0])*phiC[2]))/(144.0*rdxUyR4[1]+(19296.0*rdxLy[1]+10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxUyCu[1]+(646704.0*rdxLySq[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLy[1]+19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxUySq[1]+(19296.0*rdxLyCu[1]+(685848.0*rdxUx[0]+685848.0*rdxLx[0])*rdxLySq[1]+(676638.0*rdxUxSq[0]+1410216.0*rdxLx[0]*rdxUx[0]+676638.0*rdxLxSq[0])*rdxLy[1]+10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxUy[1]+144.0*rdxLyR4[1]+(10086.0*rdxUx[0]+10086.0*rdxLx[0])*rdxLyCu[1]+(19884.0*rdxUxSq[0]+676638.0*rdxLx[0]*rdxUx[0]+19884.0*rdxLxSq[0])*rdxLySq[1]+(10086.0*rdxUxCu[0]+685848.0*rdxLx[0]*rdxUxSq[0]+685848.0*rdxLxSq[0]*rdxUx[0]+10086.0*rdxLxCu[0])*rdxLy[1]+144.0*rdxUxR4[0]+19296.0*rdxLx[0]*rdxUxCu[0]+646704.0*rdxLxSq[0]*rdxUxSq[0]+19296.0*rdxLxCu[0]*rdxUx[0]+144.0*rdxLxR4[0]); 
  phiC[3] = (((144.0*rdxUyCu[1]+(9792.0*rdxLy[1]+4612.0*rdxUx[0]+4612.0*rdxLx[0])*rdxUySq[1]+(9792.0*rdxLySq[1]+(21184.0*rdxUx[0]+21184.0*rdxLx[0])*rdxLy[1]+4612.0*rdxUxSq[0]+21184.0*rdxLx[0]*rdxUx[0]+4612.0*rdxLxSq[0])*rdxUy[1]+144.0*rdxLyCu[1]+(4612.0*rdxUx[0]+4612.0*rdxLx[0])*rdxLySq[1]+(4612.0*rdxUxSq[0]+21184.0*rdxLx[0]*rdxUx[0]+4612.0*rdxLxSq[0])*rdxLy[1]+144.0*rdxUxCu[0]+9792.0*rdxLx[0]*rdxUxSq[0]+9792.0*rdxLxSq[0]*rdxUx[0]+144.0*rdxLxCu[0])*rho[3]+((10717.93039723621*rdxLx[0]-10717.93039723621*rdxUx[0])*rdxUySq[1]+((1981.466123858796*rdxUx[0]-1981.466123858796*rdxLx[0])*rdxLy[1]-11078.19696521054*rdxUxSq[0]+11078.19696521054*rdxLxSq[0])*rdxUy[1]+(10717.93039723621*rdxLx[0]-10717.93039723621*rdxUx[0])*rdxLySq[1]+(11078.19696521054*rdxLxSq[0]-11078.19696521054*rdxUxSq[0])*rdxLy[1]-360.2665679743264*rdxUxCu[0]-23777.59348630554*rdxLx[0]*rdxUxSq[0]+23777.59348630554*rdxLxSq[0]*rdxUx[0]+360.2665679743264*rdxLxCu[0])*rho[2]+((-360.2665679743264*rdxUyCu[1])+((-23777.59348630554*rdxLy[1])-11078.19696521054*rdxUx[0]-11078.19696521054*rdxLx[0])*rdxUySq[1]+(23777.59348630554*rdxLySq[1]-10717.93039723621*rdxUxSq[0]+1981.466123858796*rdxLx[0]*rdxUx[0]-10717.93039723621*rdxLxSq[0])*rdxUy[1]+360.2665679743264*rdxLyCu[1]+(11078.19696521054*rdxUx[0]+11078.19696521054*rdxLx[0])*rdxLySq[1]+(10717.93039723621*rdxUxSq[0]-1981.466123858796*rdxLx[0]*rdxUx[0]+10717.93039723621*rdxLxSq[0])*rdxLy[1])*rho[1]+(27716.0*rdxUx[0]-27716.0*rdxLx[0])*rho[0]*rdxUySq[1]+(27716.0*rdxUxSq[0]-27716.0*rdxLxSq[0])*rho[0]*rdxUy[1]+(27716.0*rdxLx[0]-27716.0*rdxUx[0])*rho[0]*rdxLySq[1]+(27716.0*rdxLxSq[0]-27716.0*rdxUxSq[0])*rho[0]*rdxLy[1])*omega*volFac+((528.0*rdxUyR4[1]+(34344.0*rdxLy[1]+15914.0*rdxUx[0]+15914.0*rdxLx[0])*rdxUyCu[1]+((-68616.0*rdxLySq[1])+((-37072.0*rdxUx[0])-37072.0*rdxLx[0])*rdxLy[1]+15134.0*rdxUxSq[0]-41362.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxUySq[1]+((-1032.0*rdxLyCu[1])+((-32056.0*rdxUx[0])-32056.0*rdxLx[0])*rdxLySq[1]+((-31276.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0]-31276.0*rdxLxSq[0])*rdxLy[1]-252.0*rdxUxCu[0]-17136.0*rdxLx[0]*rdxUxSq[0]-17136.0*rdxLxSq[0]*rdxUx[0]-252.0*rdxLxCu[0])*rdxUy[1])*phiUy[3]+((-252.0*rdxUx[0]*rdxUyCu[1])+((-17136.0*rdxUx[0]*rdxLy[1])+15134.0*rdxUxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxUySq[1]+((-17136.0*rdxUx[0]*rdxLySq[1])+((-41362.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0])*rdxLy[1]+15914.0*rdxUxCu[0]-37072.0*rdxLx[0]*rdxUxSq[0]-32056.0*rdxLxSq[0]*rdxUx[0])*rdxUy[1]-252.0*rdxUx[0]*rdxLyCu[1]+(15134.0*rdxUxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+(15914.0*rdxUxCu[0]-37072.0*rdxLx[0]*rdxUxSq[0]-32056.0*rdxLxSq[0]*rdxUx[0])*rdxLy[1]+528.0*rdxUxR4[0]+34344.0*rdxLx[0]*rdxUxCu[0]-68616.0*rdxLxSq[0]*rdxUxSq[0]-1032.0*rdxLxCu[0]*rdxUx[0])*phiUx[3]+((-1032.0*rdxLy[1]*rdxUyCu[1])+(((-32056.0*rdxUx[0])-32056.0*rdxLx[0])*rdxLy[1]-68616.0*rdxLySq[1])*rdxUySq[1]+(34344.0*rdxLyCu[1]+((-37072.0*rdxUx[0])-37072.0*rdxLx[0])*rdxLySq[1]+((-31276.0*rdxUxSq[0])-32782.0*rdxLx[0]*rdxUx[0]-31276.0*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+528.0*rdxLyR4[1]+(15914.0*rdxUx[0]+15914.0*rdxLx[0])*rdxLyCu[1]+(15134.0*rdxUxSq[0]-41362.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxLySq[1]+((-252.0*rdxUxCu[0])-17136.0*rdxLx[0]*rdxUxSq[0]-17136.0*rdxLxSq[0]*rdxUx[0]-252.0*rdxLxCu[0])*rdxLy[1])*phiLy[3]+((-252.0*rdxLx[0]*rdxUyCu[1])+((-17136.0*rdxLx[0]*rdxLy[1])-31276.0*rdxLx[0]*rdxUx[0]+15134.0*rdxLxSq[0])*rdxUySq[1]+((-17136.0*rdxLx[0]*rdxLySq[1])+((-32782.0*rdxLx[0]*rdxUx[0])-41362.0*rdxLxSq[0])*rdxLy[1]-32056.0*rdxLx[0]*rdxUxSq[0]-37072.0*rdxLxSq[0]*rdxUx[0]+15914.0*rdxLxCu[0])*rdxUy[1]-252.0*rdxLx[0]*rdxLyCu[1]+(15134.0*rdxLxSq[0]-31276.0*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-32056.0*rdxLx[0]*rdxUxSq[0])-37072.0*rdxLxSq[0]*rdxUx[0]+15914.0*rdxLxCu[0])*rdxLy[1]-1032.0*rdxLx[0]*rdxUxCu[0]-68616.0*rdxLxSq[0]*rdxUxSq[0]+34344.0*rdxLxCu[0]*rdxUx[0]+528.0*rdxLxR4[0])*phiLx[3]+((-48.0*rdxUyR4[1])+((-6432.0*rdxLy[1])-3362.0*rdxUx[0]-3362.0*rdxLx[0])*rdxUyCu[1]+((-215568.0*rdxLySq[1])+((-228616.0*rdxUx[0])-228616.0*rdxLx[0])*rdxLy[1]-6628.0*rdxUxSq[0]-225546.0*rdxLx[0]*rdxUx[0]-6628.0*rdxLxSq[0])*rdxUySq[1]+((-6432.0*rdxLyCu[1])+((-228616.0*rdxUx[0])-228616.0*rdxLx[0])*rdxLySq[1]+((-225546.0*rdxUxSq[0])-470072.0*rdxLx[0]*rdxUx[0]-225546.0*rdxLxSq[0])*rdxLy[1]-3362.0*rdxUxCu[0]-228616.0*rdxLx[0]*rdxUxSq[0]-228616.0*rdxLxSq[0]*rdxUx[0]-3362.0*rdxLxCu[0])*rdxUy[1]-48.0*rdxLyR4[1]+((-3362.0*rdxUx[0])-3362.0*rdxLx[0])*rdxLyCu[1]+((-6628.0*rdxUxSq[0])-225546.0*rdxLx[0]*rdxUx[0]-6628.0*rdxLxSq[0])*rdxLySq[1]+((-3362.0*rdxUxCu[0])-228616.0*rdxLx[0]*rdxUxSq[0]-228616.0*rdxLxSq[0]*rdxUx[0]-3362.0*rdxLxCu[0])*rdxLy[1]-48.0*rdxUxR4[0]-6432.0*rdxLx[0]*rdxUxCu[0]-215568.0*rdxLxSq[0]*rdxUxSq[0]-6432.0*rdxLxCu[0]*rdxUx[0]-48.0*rdxLxR4[0])*phiC[3]+((20625.26101653019*rdxLx[0]-20625.26101653019*rdxUx[0])*rdxUyCu[1]+((1733.782858376446*rdxLx[0]-1733.782858376446*rdxUx[0])*rdxLy[1]-20310.02776955265*rdxUxSq[0]+20310.02776955265*rdxLxSq[0])*rdxUySq[1]+((39381.63921169356*rdxUx[0]-39381.63921169356*rdxLx[0])*rdxLySq[1]+(39696.8724586711*rdxUxSq[0]-39696.8724586711*rdxLxSq[0])*rdxLy[1]+315.2332469775357*rdxUxCu[0]+20805.39430051735*rdxLx[0]*rdxUxSq[0]-20805.39430051735*rdxLxSq[0]*rdxUx[0]-315.2332469775357*rdxLxCu[0])*rdxUy[1])*phiUy[2]+(311.7691453623978*rdxUx[0]*rdxUyCu[1]+(21200.30188464305*rdxUx[0]*rdxLy[1]-14130.0704881469*rdxUxSq[0]+34100.61629941605*rdxLx[0]*rdxUx[0])*rdxUySq[1]+(21200.30188464305*rdxUx[0]*rdxLySq[1]+(50323.00416310616*rdxUxSq[0]+41406.40660574158*rdxLx[0]*rdxUx[0])*rdxLy[1]-14940.67026608914*rdxUxCu[0]+45864.70538442387*rdxLx[0]*rdxUxSq[0]+34911.21607735829*rdxLxSq[0]*rdxUx[0])*rdxUy[1]+311.7691453623978*rdxUx[0]*rdxLyCu[1]+(34100.61629941605*rdxLx[0]*rdxUx[0]-14130.0704881469*rdxUxSq[0])*rdxLySq[1]+((-14940.67026608914*rdxUxCu[0])+45864.70538442387*rdxLx[0]*rdxUxSq[0]+34911.21607735829*rdxLxSq[0]*rdxUx[0])*rdxLy[1]-498.8306325798365*rdxUxR4[0]-32299.28345954441*rdxLx[0]*rdxUxCu[0]+74699.88722883051*rdxLxSq[0]*rdxUxSq[0]+1122.368923304632*rdxLxCu[0]*rdxUx[0])*phiUx[2]+((39381.63921169356*rdxUx[0]-39381.63921169356*rdxLx[0])*rdxLy[1]*rdxUySq[1]+((1733.782858376446*rdxLx[0]-1733.782858376446*rdxUx[0])*rdxLySq[1]+(39696.8724586711*rdxUxSq[0]-39696.8724586711*rdxLxSq[0])*rdxLy[1])*rdxUy[1]+(20625.26101653019*rdxLx[0]-20625.26101653019*rdxUx[0])*rdxLyCu[1]+(20310.02776955265*rdxLxSq[0]-20310.02776955265*rdxUxSq[0])*rdxLySq[1]+(315.2332469775357*rdxUxCu[0]+20805.39430051735*rdxLx[0]*rdxUxSq[0]-20805.39430051735*rdxLxSq[0]*rdxUx[0]-315.2332469775357*rdxLxCu[0])*rdxLy[1])*phiLy[2]+((-311.7691453623978*rdxLx[0]*rdxUyCu[1])+((-21200.30188464305*rdxLx[0]*rdxLy[1])-34100.61629941605*rdxLx[0]*rdxUx[0]+14130.0704881469*rdxLxSq[0])*rdxUySq[1]+((-21200.30188464305*rdxLx[0]*rdxLySq[1])+((-41406.40660574158*rdxLx[0]*rdxUx[0])-50323.00416310616*rdxLxSq[0])*rdxLy[1]-34911.21607735829*rdxLx[0]*rdxUxSq[0]-45864.70538442387*rdxLxSq[0]*rdxUx[0]+14940.67026608914*rdxLxCu[0])*rdxUy[1]-311.7691453623978*rdxLx[0]*rdxLyCu[1]+(14130.0704881469*rdxLxSq[0]-34100.61629941605*rdxLx[0]*rdxUx[0])*rdxLySq[1]+((-34911.21607735829*rdxLx[0]*rdxUxSq[0])-45864.70538442387*rdxLxSq[0]*rdxUx[0]+14940.67026608914*rdxLxCu[0])*rdxLy[1]-1122.368923304632*rdxLx[0]*rdxUxCu[0]-74699.88722883051*rdxLxSq[0]*rdxUxSq[0]+32299.28345954441*rdxLxCu[0]*rdxUx[0]+498.8306325798365*rdxLxR4[0])*phiLx[2]-498.8306325798365*phiUy[1]*rdxUyR4[1]+(((-32299.28345954441*phiUy[1])-1122.368923304632*phiLy[1])*rdxLy[1]+((-14940.67026608914*rdxUx[0])-14940.67026608914*rdxLx[0])*phiUy[1]+315.2332469775357*rdxUx[0]*phiUx[1]+315.2332469775357*rdxLx[0]*phiLx[1]+(19578.0*phiUy[0]-390.0*phiUx[0])*rdxUx[0]+(390.0*phiLx[0]-19578.0*phiUy[0])*rdxLx[0])*rdxUyCu[1]+((74699.88722883051*phiUy[1]-74699.88722883051*phiLy[1])*rdxLySq[1]+((45864.70538442387*rdxUx[0]+45864.70538442387*rdxLx[0])*phiUy[1]+20805.39430051735*rdxUx[0]*phiUx[1]+((-34911.21607735829*rdxUx[0])-34911.21607735829*rdxLx[0])*phiLy[1]+20805.39430051735*rdxLx[0]*phiLx[1]+(2145.0*phiUy[0]-25740.0*phiUx[0]+42783.0*phiLy[0])*rdxUx[0]+((-2145.0*phiUy[0])-42783.0*phiLy[0]+25740.0*phiLx[0])*rdxLx[0])*rdxLy[1]+((-14130.0704881469*rdxUxSq[0])+50323.00416310616*rdxLx[0]*rdxUx[0]-14130.0704881469*rdxLxSq[0])*phiUy[1]+(39696.8724586711*rdxLx[0]*rdxUx[0]-20310.02776955265*rdxUxSq[0])*phiUx[1]+(39696.8724586711*rdxLx[0]*rdxUx[0]-20310.02776955265*rdxLxSq[0])*phiLx[1]+(19188.0*phiUy[0]+19188.0*phiUx[0])*rdxUxSq[0]+(43173.0*phiLx[0]-43173.0*phiUx[0])*rdxLx[0]*rdxUx[0]+((-19188.0*phiUy[0])-19188.0*phiLx[0])*rdxLxSq[0])*rdxUySq[1]+((1122.368923304632*phiUy[1]+32299.28345954441*phiLy[1])*rdxLyCu[1]+((34911.21607735829*rdxUx[0]+34911.21607735829*rdxLx[0])*phiUy[1]-20805.39430051735*rdxUx[0]*phiUx[1]+((-45864.70538442387*rdxUx[0])-45864.70538442387*rdxLx[0])*phiLy[1]-20805.39430051735*rdxLx[0]*phiLx[1]+((-42783.0*phiUy[0])+25740.0*phiUx[0]-2145.0*phiLy[0])*rdxUx[0]+(42783.0*phiUy[0]+2145.0*phiLy[0]-25740.0*phiLx[0])*rdxLx[0])*rdxLySq[1]+((34100.61629941605*rdxUxSq[0]+41406.40660574158*rdxLx[0]*rdxUx[0]+34100.61629941605*rdxLxSq[0])*phiUy[1]+((-34100.61629941605*rdxUxSq[0])-41406.40660574158*rdxLx[0]*rdxUx[0]-34100.61629941605*rdxLxSq[0])*phiLy[1]+(43173.0*phiLy[0]-43173.0*phiUy[0])*rdxUxSq[0]+(43173.0*phiUy[0]-43173.0*phiLy[0])*rdxLxSq[0])*rdxLy[1]+(311.7691453623978*rdxUxCu[0]+21200.30188464305*rdxLx[0]*rdxUxSq[0]+21200.30188464305*rdxLxSq[0]*rdxUx[0]+311.7691453623978*rdxLxCu[0])*phiUy[1]+((-20625.26101653019*rdxUxCu[0])-1733.782858376446*rdxLx[0]*rdxUxSq[0]+39381.63921169356*rdxLxSq[0]*rdxUx[0])*phiUx[1]+(39381.63921169356*rdxLx[0]*rdxUxSq[0]-1733.782858376446*rdxLxSq[0]*rdxUx[0]-20625.26101653019*rdxLxCu[0])*phiLx[1]+(19578.0*phiUx[0]-390.0*phiUy[0])*rdxUxCu[0]+((-25740.0*phiUy[0])+2145.0*phiUx[0]+42783.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(25740.0*phiUy[0]-42783.0*phiUx[0]-2145.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(390.0*phiUy[0]-19578.0*phiLx[0])*rdxLxCu[0])*rdxUy[1]+498.8306325798365*phiLy[1]*rdxLyR4[1]+((-315.2332469775357*rdxUx[0]*phiUx[1])+(14940.67026608914*rdxUx[0]+14940.67026608914*rdxLx[0])*phiLy[1]-315.2332469775357*rdxLx[0]*phiLx[1]+(390.0*phiUx[0]-19578.0*phiLy[0])*rdxUx[0]+(19578.0*phiLy[0]-390.0*phiLx[0])*rdxLx[0])*rdxLyCu[1]+((20310.02776955265*rdxUxSq[0]-39696.8724586711*rdxLx[0]*rdxUx[0])*phiUx[1]+(14130.0704881469*rdxUxSq[0]-50323.00416310616*rdxLx[0]*rdxUx[0]+14130.0704881469*rdxLxSq[0])*phiLy[1]+(20310.02776955265*rdxLxSq[0]-39696.8724586711*rdxLx[0]*rdxUx[0])*phiLx[1]+((-19188.0*phiUx[0])-19188.0*phiLy[0])*rdxUxSq[0]+(43173.0*phiUx[0]-43173.0*phiLx[0])*rdxLx[0]*rdxUx[0]+(19188.0*phiLy[0]+19188.0*phiLx[0])*rdxLxSq[0])*rdxLySq[1]+((20625.26101653019*rdxUxCu[0]+1733.782858376446*rdxLx[0]*rdxUxSq[0]-39381.63921169356*rdxLxSq[0]*rdxUx[0])*phiUx[1]+((-311.7691453623978*rdxUxCu[0])-21200.30188464305*rdxLx[0]*rdxUxSq[0]-21200.30188464305*rdxLxSq[0]*rdxUx[0]-311.7691453623978*rdxLxCu[0])*phiLy[1]+((-39381.63921169356*rdxLx[0]*rdxUxSq[0])+1733.782858376446*rdxLxSq[0]*rdxUx[0]+20625.26101653019*rdxLxCu[0])*phiLx[1]+(390.0*phiLy[0]-19578.0*phiUx[0])*rdxUxCu[0]+((-2145.0*phiUx[0])+25740.0*phiLy[0]-42783.0*phiLx[0])*rdxLx[0]*rdxUxSq[0]+(42783.0*phiUx[0]-25740.0*phiLy[0]+2145.0*phiLx[0])*rdxLxSq[0]*rdxUx[0]+(19578.0*phiLx[0]-390.0*phiLy[0])*rdxLxCu[0])*rdxLy[1])*omega+(48.0*rdxUyR4[1]+(6432.0*rdxLy[1]+3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxUyCu[1]+(215568.0*rdxLySq[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLy[1]+6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxUySq[1]+(6432.0*rdxLyCu[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLySq[1]+(225546.0*rdxUxSq[0]+470072.0*rdxLx[0]*rdxUx[0]+225546.0*rdxLxSq[0])*rdxLy[1]+3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxUy[1]+48.0*rdxLyR4[1]+(3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxLyCu[1]+(6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxLySq[1]+(3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxLy[1]+48.0*rdxUxR4[0]+6432.0*rdxLx[0]*rdxUxCu[0]+215568.0*rdxLxSq[0]*rdxUxSq[0]+6432.0*rdxLxCu[0]*rdxUx[0]+48.0*rdxLxR4[0])*phiC[3])/(48.0*rdxUyR4[1]+(6432.0*rdxLy[1]+3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxUyCu[1]+(215568.0*rdxLySq[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLy[1]+6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxUySq[1]+(6432.0*rdxLyCu[1]+(228616.0*rdxUx[0]+228616.0*rdxLx[0])*rdxLySq[1]+(225546.0*rdxUxSq[0]+470072.0*rdxLx[0]*rdxUx[0]+225546.0*rdxLxSq[0])*rdxLy[1]+3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxUy[1]+48.0*rdxLyR4[1]+(3362.0*rdxUx[0]+3362.0*rdxLx[0])*rdxLyCu[1]+(6628.0*rdxUxSq[0]+225546.0*rdxLx[0]*rdxUx[0]+6628.0*rdxLxSq[0])*rdxLySq[1]+(3362.0*rdxUxCu[0]+228616.0*rdxLx[0]*rdxUxSq[0]+228616.0*rdxLxSq[0]*rdxUx[0]+3362.0*rdxLxCu[0])*rdxLy[1]+48.0*rdxUxR4[0]+6432.0*rdxLx[0]*rdxUxCu[0]+215568.0*rdxLxSq[0]*rdxUxSq[0]+6432.0*rdxLxCu[0]*rdxUx[0]+48.0*rdxLxR4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((1.732050807568877*rdxCp2Sq[0]*rho[1]+6.0*rho[0]*rdxCp2Sq[1]+50.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-20.78460969082652*rdxCp2R4[1])-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(20.78460969082652*rdxCp2R4[1]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(18.0*phiUy[0]+18.0*phiLy[0]-36.0*phiC[0])*rdxCp2R4[1]+(10.39230484541326*rdxCp2Sq[0]*phiUy[1]-20.78460969082652*rdxCp2Sq[0]*phiUx[1]+10.39230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiUy[0]+18.0*phiUx[0]+150.0*phiLy[0]-354.0*phiC[0]+144.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-207.8460969082653*rdxCp2R4[0]*phiUx[1]+(180.0*phiUx[0]-420.0*phiC[0]+960.0*bcVals[0])*rdxCp2R4[0])*omega+36.0*phiC[0]*rdxCp2R4[1]+354.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]+420.0*phiC[0]*rdxCp2R4[0])/(36.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+420.0*rdxCp2R4[0]); 
  phiC[1] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[1]+17.32050807568877*rdxCp2Sq[0]*rho[0])*omega*volFac+(((-41.56921938165305*rdxCp2R4[1])-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(41.56921938165305*rdxCp2R4[1]+62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*phiUy[1]+36.0*phiLy[1]-72.0*phiC[1])*rdxCp2R4[1]+(54.0*rdxCp2Sq[0]*phiUy[1]-120.0*rdxCp2Sq[0]*phiUx[1]+54.0*rdxCp2Sq[0]*phiLy[1]-708.0*rdxCp2Sq[0]*phiC[1]+(51.96152422706631*phiUy[0]+103.9230484541326*phiUx[0]+51.96152422706631*phiLy[0]-831.384387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-240.0*rdxCp2R4[0]*phiUx[1]-840.0*rdxCp2R4[0]*phiC[1]+(207.8460969082653*phiUx[0]-831.384387633061*bcVals[0])*rdxCp2R4[0])*omega+72.0*phiC[1]*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]*phiC[1])/(72.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[2] = ((1.732050807568877*rdxCp2Sq[0]*rho[3]+(40.0*rdxCp2Sq[1]+50.0*rdxCp2Sq[0])*rho[2])*omega*volFac+((-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+((-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiUx[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-800.0*rdxCp2R4[1])-1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(240.0*rdxCp2Sq[0]*rdxCp2Sq[1]+360.0*rdxCp2R4[0])*phiUx[2]+((-800.0*rdxCp2R4[1])-1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-3200.0*rdxCp2R4[1])-4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]-840.0*rdxCp2R4[0])*phiC[2]+(692.8203230275509*phiUy[0]-692.8203230275509*phiLy[0])*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUy[1]-60.0*rdxCp2Sq[0]*phiLy[1]+(866.0254037844386*phiUy[0]-866.0254037844386*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0])*phiC[2])/(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[3] = (((40.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[3]+17.32050807568877*rdxCp2Sq[0]*rho[2])*omega*volFac+(((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])-480.0*rdxCp2R4[0])*phiUx[3]+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-6400.0*rdxCp2R4[1])-9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]-1680.0*rdxCp2R4[0])*phiC[3]-346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+(1385.640646055102*rdxCp2Sq[0]*rdxCp2Sq[1]+415.6921938165305*rdxCp2R4[0])*phiUx[2]-346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(1385.640646055102*phiUy[1]-1385.640646055102*phiLy[1])*rdxCp2R4[1]+(311.7691453623978*rdxCp2Sq[0]*phiUy[1]-311.7691453623978*rdxCp2Sq[0]*phiLy[1]+(300.0*phiUy[0]-300.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0])*phiC[3])/(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((5.196152422706631*rdxCp2Sq[0]*rho[1]-9.0*rho[0]*rdxCp2Sq[1]-30.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(31.17691453623978*rdxCp2R4[1]+103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-31.17691453623978*rdxCp2R4[1])-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-27.0*phiUy[0])-27.0*phiLy[0]+54.0*phiC[0])*rdxCp2R4[1]+(31.17691453623978*rdxCp2Sq[0]*phiUy[1]+41.56921938165305*rdxCp2Sq[0]*phiUx[1]+31.17691453623978*rdxCp2Sq[0]*phiLy[1]+((-90.0*phiUy[0])-36.0*phiUx[0]-90.0*phiLy[0]+216.0*phiC[0]+24.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+69.28203230275508*rdxCp2R4[0]*phiUx[1]+((-60.0*phiUx[0])+60.0*phiC[0]+160.0*bcVals[0])*rdxCp2R4[0])*omega-54.0*phiC[0]*rdxCp2R4[1]-216.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]-60.0*phiC[0]*rdxCp2R4[0]))/(54.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+60.0*rdxCp2R4[0]); 
  phiC[1] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[1]-17.32050807568877*rdxCp2Sq[0]*rho[0])*omega*volFac+(((-62.35382907247956*rdxCp2R4[1])-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(62.35382907247956*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(54.0*phiUy[1]+54.0*phiLy[1]-108.0*phiC[1])*rdxCp2R4[1]+(36.0*rdxCp2Sq[0]*phiUy[1]-120.0*rdxCp2Sq[0]*phiUx[1]+36.0*rdxCp2Sq[0]*phiLy[1]-432.0*rdxCp2Sq[0]*phiC[1]+((-51.96152422706631*phiUy[0])+103.9230484541326*phiUx[0]-51.96152422706631*phiLy[0]+138.5640646055102*bcVals[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-120.0*rdxCp2R4[0]*phiC[1]+138.5640646055102*bcVals[0]*rdxCp2R4[0])*omega+108.0*phiC[1]*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]*phiC[1])/(108.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[2] = -(1.0*((5.196152422706631*rdxCp2Sq[0]*rho[3]+((-60.0*rdxCp2Sq[1])-30.0*rdxCp2Sq[0])*rho[2])*omega*volFac+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+(554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1]+138.5640646055102*rdxCp2R4[0])*phiUx[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(1200.0*rdxCp2R4[1]+600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-480.0*rdxCp2Sq[0]*rdxCp2Sq[1])-120.0*rdxCp2R4[0])*phiUx[2]+(1200.0*rdxCp2R4[1]+600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiC[2]+(1039.230484541326*phiLy[0]-1039.230484541326*phiUy[0])*rdxCp2R4[1]+(180.0*rdxCp2Sq[0]*phiUy[1]-180.0*rdxCp2Sq[0]*phiLy[1]+(519.6152422706631*phiLy[0]-519.6152422706631*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+((-4800.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-120.0*rdxCp2R4[0])*phiC[2]))/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[3] = (((30.0*rdxCp2Sq[1]+3.0*rdxCp2Sq[0])*rho[3]-8.660254037844386*rdxCp2Sq[0]*rho[2])*omega*volFac+(((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-4800.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-120.0*rdxCp2R4[0])*phiC[3]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+692.8203230275509*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(1039.230484541326*phiUy[1]-1039.230484541326*phiLy[1])*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUy[1]-103.9230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiLy[0]-150.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiC[3])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((1.732050807568877*rdxCp2Sq[0]*rho[1]-6.0*rho[0]*rdxCp2Sq[1]-50.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(20.78460969082652*rdxCp2R4[1]+173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-20.78460969082652*rdxCp2R4[1])-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-18.0*phiUy[0])-18.0*phiLy[0]+36.0*phiC[0])*rdxCp2R4[1]+(10.39230484541326*rdxCp2Sq[0]*phiUy[1]+10.39230484541326*rdxCp2Sq[0]*phiLy[1]-20.78460969082652*rdxCp2Sq[0]*phiLx[1]-144.0*rdxCp2Sq[0]*bcVals[1]+((-150.0*phiUy[0])-150.0*phiLy[0]-18.0*phiLx[0]+354.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-207.8460969082653*rdxCp2R4[0]*phiLx[1]-960.0*rdxCp2R4[0]*bcVals[1]+(420.0*phiC[0]-180.0*phiLx[0])*rdxCp2R4[0])*omega-36.0*phiC[0]*rdxCp2R4[1]-354.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]-420.0*phiC[0]*rdxCp2R4[0]))/(36.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+420.0*rdxCp2R4[0]); 
  phiC[1] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[1]-17.32050807568877*rdxCp2Sq[0]*rho[0])*omega*volFac+(((-41.56921938165305*rdxCp2R4[1])-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(41.56921938165305*rdxCp2R4[1]+62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*phiUy[1]+36.0*phiLy[1]-72.0*phiC[1])*rdxCp2R4[1]+(54.0*rdxCp2Sq[0]*phiUy[1]+54.0*rdxCp2Sq[0]*phiLy[1]-120.0*rdxCp2Sq[0]*phiLx[1]-708.0*rdxCp2Sq[0]*phiC[1]+831.384387633061*rdxCp2Sq[0]*bcVals[1]+((-51.96152422706631*phiUy[0])-51.96152422706631*phiLy[0]-103.9230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-240.0*rdxCp2R4[0]*phiLx[1]-840.0*rdxCp2R4[0]*phiC[1]+831.384387633061*rdxCp2R4[0]*bcVals[1]-207.8460969082653*phiLx[0]*rdxCp2R4[0])*omega+72.0*phiC[1]*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]*phiC[1])/(72.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[2] = -(1.0*((1.732050807568877*rdxCp2Sq[0]*rho[3]+((-40.0*rdxCp2Sq[1])-50.0*rdxCp2Sq[0])*rho[2])*omega*volFac+((-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiLx[3]+(800.0*rdxCp2R4[1]+1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(800.0*rdxCp2R4[1]+1000.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+((-240.0*rdxCp2Sq[0]*rdxCp2Sq[1])-360.0*rdxCp2R4[0])*phiLx[2]+(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0])*phiC[2]+(692.8203230275509*phiLy[0]-692.8203230275509*phiUy[0])*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUy[1]-60.0*rdxCp2Sq[0]*phiLy[1]+(866.0254037844386*phiLy[0]-866.0254037844386*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+((-3200.0*rdxCp2R4[1])-4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]-840.0*rdxCp2R4[0])*phiC[2]))/(3200.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+840.0*rdxCp2R4[0]); 
  phiC[3] = (((40.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[3]-17.32050807568877*rdxCp2Sq[0]*rho[2])*omega*volFac+(((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1600.0*rdxCp2R4[1])-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])-480.0*rdxCp2R4[0])*phiLx[3]+((-6400.0*rdxCp2R4[1])-9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]-1680.0*rdxCp2R4[0])*phiC[3]+346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+346.4101615137754*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+((-1385.640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])-415.6921938165305*rdxCp2R4[0])*phiLx[2]+(1385.640646055102*phiUy[1]-1385.640646055102*phiLy[1])*rdxCp2R4[1]+(311.7691453623978*rdxCp2Sq[0]*phiUy[1]-311.7691453623978*rdxCp2Sq[0]*phiLy[1]+(300.0*phiLy[0]-300.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0])*phiC[3])/(6400.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1680.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((5.196152422706631*rdxCp2Sq[0]*rho[1]+9.0*rho[0]*rdxCp2Sq[1]+30.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-31.17691453623978*rdxCp2R4[1])-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(31.17691453623978*rdxCp2R4[1]+103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(27.0*phiUy[0]+27.0*phiLy[0]-54.0*phiC[0])*rdxCp2R4[1]+(31.17691453623978*rdxCp2Sq[0]*phiUy[1]+31.17691453623978*rdxCp2Sq[0]*phiLy[1]+41.56921938165305*rdxCp2Sq[0]*phiLx[1]+24.0*rdxCp2Sq[0]*bcVals[1]+(90.0*phiUy[0]+90.0*phiLy[0]+36.0*phiLx[0]-216.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+69.28203230275508*rdxCp2R4[0]*phiLx[1]+160.0*rdxCp2R4[0]*bcVals[1]+(60.0*phiLx[0]-60.0*phiC[0])*rdxCp2R4[0])*omega+54.0*phiC[0]*rdxCp2R4[1]+216.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]+60.0*phiC[0]*rdxCp2R4[0])/(54.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+60.0*rdxCp2R4[0]); 
  phiC[1] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[1]+17.32050807568877*rdxCp2Sq[0]*rho[0])*omega*volFac+(((-62.35382907247956*rdxCp2R4[1])-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+(62.35382907247956*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(54.0*phiUy[1]+54.0*phiLy[1]-108.0*phiC[1])*rdxCp2R4[1]+(36.0*rdxCp2Sq[0]*phiUy[1]+36.0*rdxCp2Sq[0]*phiLy[1]-120.0*rdxCp2Sq[0]*phiLx[1]-432.0*rdxCp2Sq[0]*phiC[1]+138.5640646055102*rdxCp2Sq[0]*bcVals[1]+(51.96152422706631*phiUy[0]+51.96152422706631*phiLy[0]-103.9230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-120.0*rdxCp2R4[0]*phiC[1]+138.5640646055102*rdxCp2R4[0]*bcVals[1])*omega+108.0*phiC[1]*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]*phiC[1])/(108.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[2] = ((5.196152422706631*rdxCp2Sq[0]*rho[3]+(60.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[2])*omega*volFac+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+(554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1]+138.5640646055102*rdxCp2R4[0])*phiLx[3]+((-1200.0*rdxCp2R4[1])-600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+((-1200.0*rdxCp2R4[1])-600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(480.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiLx[2]+((-4800.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-120.0*rdxCp2R4[0])*phiC[2]+(1039.230484541326*phiUy[0]-1039.230484541326*phiLy[0])*rdxCp2R4[1]+(180.0*rdxCp2Sq[0]*phiUy[1]-180.0*rdxCp2Sq[0]*phiLy[1]+(519.6152422706631*phiUy[0]-519.6152422706631*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiC[2])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 
  phiC[3] = (((30.0*rdxCp2Sq[1]+3.0*rdxCp2Sq[0])*rho[3]+8.660254037844386*rdxCp2Sq[0]*rho[2])*omega*volFac+(((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+((-4800.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-120.0*rdxCp2R4[0])*phiC[3]-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]-173.2050807568877*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]-692.8203230275509*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(1039.230484541326*phiUy[1]-1039.230484541326*phiLy[1])*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUy[1]-103.9230484541326*rdxCp2Sq[0]*phiLy[1]+(150.0*phiUy[0]-150.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0])*phiC[3])/(4800.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+120.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((1.732050807568877*rdxCp2Sq[1]*rho[2]+50.0*rho[0]*rdxCp2Sq[1]+6.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+((-207.8460969082653*rdxCp2R4[1])-20.78460969082652*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(960.0*rdxCp2R4[1]+144.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+(180.0*phiUy[0]-420.0*phiC[0])*rdxCp2R4[1]+((-173.2050807568877*rdxCp2Sq[0]*phiUx[1])+173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(18.0*phiUy[0]+150.0*phiUx[0]+150.0*phiLx[0]-354.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-20.78460969082652*rdxCp2R4[0]*phiUx[1]+20.78460969082652*rdxCp2R4[0]*phiLx[1]+(18.0*phiUx[0]+18.0*phiLx[0]-36.0*phiC[0])*rdxCp2R4[0])*omega+420.0*phiC[0]*rdxCp2R4[1]+354.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*phiC[0]*rdxCp2R4[0])/(420.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0]); 
  phiC[1] = ((1.732050807568877*rdxCp2Sq[1]*rho[3]+(50.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[1])*omega*volFac+(((-415.6921938165305*rdxCp2R4[1])-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(360.0*phiUy[1]-840.0*phiC[1])*rdxCp2R4[1]+(240.0*rdxCp2Sq[0]*phiUy[1]-1000.0*rdxCp2Sq[0]*phiUx[1]-1000.0*rdxCp2Sq[0]*phiLx[1]-4720.0*rdxCp2Sq[0]*phiC[1]+(866.0254037844386*phiUx[0]-866.0254037844386*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-800.0*rdxCp2R4[0]*phiUx[1]-800.0*rdxCp2R4[0]*phiLx[1]-3200.0*rdxCp2R4[0]*phiC[1]+(692.8203230275509*phiUx[0]-692.8203230275509*phiLx[0])*rdxCp2R4[0])*omega+840.0*phiC[1]*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+3200.0*rdxCp2R4[0]*phiC[1])/(840.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3200.0*rdxCp2R4[0]); 
  phiC[2] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[2]+17.32050807568877*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])-41.56921938165305*rdxCp2R4[0])*phiUx[3]+(62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1]+41.56921938165305*rdxCp2R4[0])*phiLx[3]+((-240.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiUx[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiLx[2]+((-840.0*rdxCp2R4[1])-708.0*rdxCp2Sq[0]*rdxCp2Sq[1]-72.0*rdxCp2R4[0])*phiC[2]+((-831.384387633061*rdxCp2R4[1])-831.384387633061*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+207.8460969082653*phiUy[0]*rdxCp2R4[1]+((-60.0*rdxCp2Sq[0]*phiUx[1])+60.0*rdxCp2Sq[0]*phiLx[1]+(103.9230484541326*phiUy[0]+51.96152422706631*phiUx[0]+51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0])*phiC[2])/(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0]); 
  phiC[3] = (((9.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[3]+17.32050807568877*rdxCp2Sq[1]*rho[1])*omega*volFac+(((-480.0*rdxCp2R4[1])-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiUx[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiLx[3]+((-1680.0*rdxCp2R4[1])-9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]-6400.0*rdxCp2R4[0])*phiC[3]+(311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]+1385.640646055102*rdxCp2R4[0])*phiUx[2]+((-311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1])-1385.640646055102*rdxCp2R4[0])*phiLx[2]+415.6921938165305*phiUy[1]*rdxCp2R4[1]+(1385.640646055102*rdxCp2Sq[0]*phiUy[1]-346.4101615137754*rdxCp2Sq[0]*phiUx[1]-346.4101615137754*rdxCp2Sq[0]*phiLx[1]+(300.0*phiUx[0]-300.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0])*phiC[3])/(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((5.196152422706631*rdxCp2Sq[1]*rho[2]-30.0*rho[0]*rdxCp2Sq[1]-9.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+(69.28203230275508*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(160.0*rdxCp2R4[1]+24.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+(60.0*phiC[0]-60.0*phiUy[0])*rdxCp2R4[1]+(103.9230484541326*rdxCp2Sq[0]*phiUx[1]-103.9230484541326*rdxCp2Sq[0]*phiLx[1]+((-36.0*phiUy[0])-90.0*phiUx[0]-90.0*phiLx[0]+216.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+31.17691453623978*rdxCp2R4[0]*phiUx[1]-31.17691453623978*rdxCp2R4[0]*phiLx[1]+((-27.0*phiUx[0])-27.0*phiLx[0]+54.0*phiC[0])*rdxCp2R4[0])*omega-60.0*phiC[0]*rdxCp2R4[1]-216.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]-54.0*phiC[0]*rdxCp2R4[0]))/(60.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0]); 
  phiC[1] = -(1.0*((5.196152422706631*rdxCp2Sq[1]*rho[3]+((-30.0*rdxCp2Sq[1])-60.0*rdxCp2Sq[0])*rho[1])*omega*volFac+((138.5640646055102*rdxCp2R4[1]+554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1])*phiUy[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(120.0*phiC[1]-120.0*phiUy[1])*rdxCp2R4[1]+((-480.0*rdxCp2Sq[0]*phiUy[1])+600.0*rdxCp2Sq[0]*phiUx[1]+600.0*rdxCp2Sq[0]*phiLx[1]+2880.0*rdxCp2Sq[0]*phiC[1]+(519.6152422706631*phiLx[0]-519.6152422706631*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+1200.0*rdxCp2R4[0]*phiUx[1]+1200.0*rdxCp2R4[0]*phiLx[1]+4800.0*rdxCp2R4[0]*phiC[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiUx[0])*rdxCp2R4[0])*omega-120.0*phiC[1]*rdxCp2R4[1]-2880.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]-4800.0*rdxCp2R4[0]*phiC[1]))/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 
  phiC[2] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[2]-17.32050807568877*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])-62.35382907247956*rdxCp2R4[0])*phiUx[3]+(41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1]+62.35382907247956*rdxCp2R4[0])*phiLx[3]-120.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiUx[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiLx[2]+((-120.0*rdxCp2R4[1])-432.0*rdxCp2Sq[0]*rdxCp2Sq[1]-108.0*rdxCp2R4[0])*phiC[2]+(138.5640646055102*rdxCp2R4[1]+138.5640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[2]+(60.0*rdxCp2Sq[0]*phiUx[1]-60.0*rdxCp2Sq[0]*phiLx[1]+(103.9230484541326*phiUy[0]-51.96152422706631*phiUx[0]-51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0])*phiC[2])/(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0]); 
  phiC[3] = (((3.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[3]-8.660254037844386*rdxCp2Sq[1]*rho[1])*omega*volFac+((-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUy[3])+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiUx[3]+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiLx[3]+((-120.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-4800.0*rdxCp2R4[0])*phiC[3]+(103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]+1039.230484541326*rdxCp2R4[0])*phiUx[2]+((-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])-1039.230484541326*rdxCp2R4[0])*phiLx[2]+(692.8203230275509*rdxCp2Sq[0]*phiUy[1]+173.2050807568877*rdxCp2Sq[0]*phiUx[1]+173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(150.0*phiLx[0]-150.0*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0])*phiC[3])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((1.732050807568877*rdxCp2Sq[1]*rho[2]-50.0*rho[0]*rdxCp2Sq[1]-6.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+12.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+((-960.0*rdxCp2R4[1])-144.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+((-207.8460969082653*rdxCp2R4[1])-20.78460969082652*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+10.39230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(420.0*phiC[0]-180.0*phiLy[0])*rdxCp2R4[1]+(173.2050807568877*rdxCp2Sq[0]*phiUx[1]-173.2050807568877*rdxCp2Sq[0]*phiLx[1]+((-150.0*phiUx[0])-18.0*phiLy[0]-150.0*phiLx[0]+354.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+20.78460969082652*rdxCp2R4[0]*phiUx[1]-20.78460969082652*rdxCp2R4[0]*phiLx[1]+((-18.0*phiUx[0])-18.0*phiLx[0]+36.0*phiC[0])*rdxCp2R4[0])*omega-420.0*phiC[0]*rdxCp2R4[1]-354.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]-36.0*phiC[0]*rdxCp2R4[0]))/(420.0*rdxCp2R4[1]+354.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0]); 
  phiC[1] = -(1.0*((1.732050807568877*rdxCp2Sq[1]*rho[3]+((-50.0*rdxCp2Sq[1])-40.0*rdxCp2Sq[0])*rho[1])*omega*volFac+((-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+((-415.6921938165305*rdxCp2R4[1])-277.1281292110203*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-69.28203230275508*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-60.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(840.0*phiC[1]-360.0*phiLy[1])*rdxCp2R4[1]+(1000.0*rdxCp2Sq[0]*phiUx[1]-240.0*rdxCp2Sq[0]*phiLy[1]+1000.0*rdxCp2Sq[0]*phiLx[1]+4720.0*rdxCp2Sq[0]*phiC[1]+(866.0254037844386*phiLx[0]-866.0254037844386*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]+800.0*rdxCp2R4[0]*phiUx[1]+800.0*rdxCp2R4[0]*phiLx[1]+3200.0*rdxCp2R4[0]*phiC[1]+(692.8203230275509*phiLx[0]-692.8203230275509*phiUx[0])*rdxCp2R4[0])*omega-840.0*phiC[1]*rdxCp2R4[1]-4720.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]-3200.0*rdxCp2R4[0]*phiC[1]))/(840.0*rdxCp2R4[1]+4720.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3200.0*rdxCp2R4[0]); 
  phiC[2] = (((9.0*rdxCp2Sq[1]+6.0*rdxCp2Sq[0])*rho[2]-17.32050807568877*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1])-41.56921938165305*rdxCp2R4[0])*phiUx[3]+(62.35382907247956*rdxCp2Sq[0]*rdxCp2Sq[1]+41.56921938165305*rdxCp2R4[0])*phiLx[3]+(831.384387633061*rdxCp2R4[1]+831.384387633061*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiUx[2]+((-240.0*rdxCp2R4[1])-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+(54.0*rdxCp2Sq[0]*rdxCp2Sq[1]+36.0*rdxCp2R4[0])*phiLx[2]+((-840.0*rdxCp2R4[1])-708.0*rdxCp2Sq[0]*rdxCp2Sq[1]-72.0*rdxCp2R4[0])*phiC[2]-207.8460969082653*phiLy[0]*rdxCp2R4[1]+(60.0*rdxCp2Sq[0]*phiUx[1]-60.0*rdxCp2Sq[0]*phiLx[1]+((-51.96152422706631*phiUx[0])-103.9230484541326*phiLy[0]-51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0])*phiC[2])/(840.0*rdxCp2R4[1]+708.0*rdxCp2Sq[0]*rdxCp2Sq[1]+72.0*rdxCp2R4[0]); 
  phiC[3] = (((9.0*rdxCp2Sq[1]+40.0*rdxCp2Sq[0])*rho[3]-17.32050807568877*rdxCp2Sq[1]*rho[1])*omega*volFac+(((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiUx[3]+((-480.0*rdxCp2R4[1])-1600.0*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]+((-360.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1600.0*rdxCp2R4[0])*phiLx[3]+((-1680.0*rdxCp2R4[1])-9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]-6400.0*rdxCp2R4[0])*phiC[3]+(311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]+1385.640646055102*rdxCp2R4[0])*phiUx[2]+((-311.7691453623978*rdxCp2Sq[0]*rdxCp2Sq[1])-1385.640646055102*rdxCp2R4[0])*phiLx[2]-415.6921938165305*phiLy[1]*rdxCp2R4[1]+(346.4101615137754*rdxCp2Sq[0]*phiUx[1]-1385.640646055102*rdxCp2Sq[0]*phiLy[1]+346.4101615137754*rdxCp2Sq[0]*phiLx[1]+(300.0*phiLx[0]-300.0*phiUx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0])*phiC[3])/(1680.0*rdxCp2R4[1]+9440.0*rdxCp2Sq[0]*rdxCp2Sq[1]+6400.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((5.196152422706631*rdxCp2Sq[1]*rho[2]+30.0*rho[0]*rdxCp2Sq[1]+9.0*rdxCp2Sq[0]*rho[0])*omega*volFac+((-36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+36.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+(160.0*rdxCp2R4[1]+24.0*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]+(69.28203230275508*rdxCp2R4[1]+41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[2]+31.17691453623978*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(60.0*phiLy[0]-60.0*phiC[0])*rdxCp2R4[1]+((-103.9230484541326*rdxCp2Sq[0]*phiUx[1])+103.9230484541326*rdxCp2Sq[0]*phiLx[1]+(90.0*phiUx[0]+36.0*phiLy[0]+90.0*phiLx[0]-216.0*phiC[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-31.17691453623978*rdxCp2R4[0]*phiUx[1]+31.17691453623978*rdxCp2R4[0]*phiLx[1]+(27.0*phiUx[0]+27.0*phiLx[0]-54.0*phiC[0])*rdxCp2R4[0])*omega+60.0*phiC[0]*rdxCp2R4[1]+216.0*phiC[0]*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*phiC[0]*rdxCp2R4[0])/(60.0*rdxCp2R4[1]+216.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0]); 
  phiC[1] = ((5.196152422706631*rdxCp2Sq[1]*rho[3]+(30.0*rdxCp2Sq[1]+60.0*rdxCp2Sq[0])*rho[1])*omega*volFac+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[3])+(138.5640646055102*rdxCp2R4[1]+554.2562584220407*rdxCp2Sq[0]*rdxCp2Sq[1])*phiLy[3]-207.8460969082653*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[3]+180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiUx[2]-180.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLx[2]+(120.0*phiLy[1]-120.0*phiC[1])*rdxCp2R4[1]+((-600.0*rdxCp2Sq[0]*phiUx[1])+480.0*rdxCp2Sq[0]*phiLy[1]-600.0*rdxCp2Sq[0]*phiLx[1]-2880.0*rdxCp2Sq[0]*phiC[1]+(519.6152422706631*phiUx[0]-519.6152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1]-1200.0*rdxCp2R4[0]*phiUx[1]-1200.0*rdxCp2R4[0]*phiLx[1]-4800.0*rdxCp2R4[0]*phiC[1]+(1039.230484541326*phiUx[0]-1039.230484541326*phiLx[0])*rdxCp2R4[0])*omega+120.0*phiC[1]*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*phiC[1]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]*phiC[1])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 
  phiC[2] = (((6.0*rdxCp2Sq[1]+9.0*rdxCp2Sq[0])*rho[2]+17.32050807568877*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1])-62.35382907247956*rdxCp2R4[0])*phiUx[3]+(41.56921938165305*rdxCp2Sq[0]*rdxCp2Sq[1]+62.35382907247956*rdxCp2R4[0])*phiLx[3]+(138.5640646055102*rdxCp2R4[1]+138.5640646055102*rdxCp2Sq[0]*rdxCp2Sq[1])*bcVals[3]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiUx[2]-120.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[2]+(36.0*rdxCp2Sq[0]*rdxCp2Sq[1]+54.0*rdxCp2R4[0])*phiLx[2]+((-120.0*rdxCp2R4[1])-432.0*rdxCp2Sq[0]*rdxCp2Sq[1]-108.0*rdxCp2R4[0])*phiC[2]+((-60.0*rdxCp2Sq[0]*phiUx[1])+60.0*rdxCp2Sq[0]*phiLx[1]+(51.96152422706631*phiUx[0]-103.9230484541326*phiLy[0]+51.96152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0])*phiC[2])/(120.0*rdxCp2R4[1]+432.0*rdxCp2Sq[0]*rdxCp2Sq[1]+108.0*rdxCp2R4[0]); 
  phiC[3] = (((3.0*rdxCp2Sq[1]+30.0*rdxCp2Sq[0])*rho[3]+8.660254037844386*rdxCp2Sq[1]*rho[1])*omega*volFac+(((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiUx[3]-800.0*rdxCp2Sq[0]*rdxCp2Sq[1]*phiLy[3]+((-120.0*rdxCp2Sq[0]*rdxCp2Sq[1])-1200.0*rdxCp2R4[0])*phiLx[3]+((-120.0*rdxCp2R4[1])-2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]-4800.0*rdxCp2R4[0])*phiC[3]+(103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1]+1039.230484541326*rdxCp2R4[0])*phiUx[2]+((-103.9230484541326*rdxCp2Sq[0]*rdxCp2Sq[1])-1039.230484541326*rdxCp2R4[0])*phiLx[2]+((-173.2050807568877*rdxCp2Sq[0]*phiUx[1])-692.8203230275509*rdxCp2Sq[0]*phiLy[1]-173.2050807568877*rdxCp2Sq[0]*phiLx[1]+(150.0*phiUx[0]-150.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2Sq[1])*omega+(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0])*phiC[3])/(120.0*rdxCp2R4[1]+2880.0*rdxCp2Sq[0]*rdxCp2Sq[1]+4800.0*rdxCp2R4[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxDirichletLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(727.4613391789284*rdxCp2R4[1]+4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[1]+21000.0*rho[0]*rdxCp2R4[1]+130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0]*rho[0])*omega*volFac+(((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-87295.36070147139*rdxCp2R6[1])-538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]-72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1]+32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(403200.0*rdxCp2R6[1]+2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]+504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(75600.0*phiUy[0]-176400.0*phiC[0])*rdxCp2R6[1]+(32423.99111768937*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiUx[1]+(466740.0*phiUy[0]+63000.0*phiUx[0]-1285620.0*phiC[0]+504000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(4364.768035073569*rdxCp2R4[0]*phiUy[1]-538944.9292831317*rdxCp2R4[0]*phiUx[1]+(63000.0*phiUy[0]+466740.0*phiUx[0]-1285620.0*phiC[0]+2519520.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-87295.36070147139*rdxCp2R6[0]*phiUx[1]+(75600.0*phiUx[0]-176400.0*phiC[0]+403200.0*bcVals[0])*rdxCp2R6[0])*omega+176400.0*phiC[0]*rdxCp2R6[1]+1285620.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*phiC[0]*rdxCp2R6[0])/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = (((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(21000.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3780.0*rdxCp2R4[0])*rho[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+7274.613391789284*rdxCp2R4[0]*rho[0])*omega*volFac+(((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-187200.0*rdxCp2Sq[0]*rdxCp2R4[1])-25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(25200.0*rdxCp2Sq[0]*rdxCp2R4[1]+17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(151200.0*phiUy[1]-352800.0*phiC[1])*rdxCp2R6[1]+(165960.0*rdxCp2Sq[0]*phiUy[1]-420000.0*rdxCp2Sq[0]*phiUx[1]-2571240.0*rdxCp2Sq[0]*phiC[1]+(162119.9555884469*phiUy[0]+363730.6695894642*phiUx[0]-2909845.356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(22680.0*rdxCp2R4[0]*phiUy[1]-682800.0*rdxCp2R4[0]*phiUx[1]-2571240.0*rdxCp2R4[0]*phiC[1]+(21823.84017536785*phiUy[0]+591322.1457040146*phiUx[0]-2627174.664920473*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-100800.0*rdxCp2R6[0]*phiUx[1]-352800.0*rdxCp2R6[0]*phiC[1]+(87295.36070147139*phiUx[0]-349181.4428058856*bcVals[0])*rdxCp2R6[0])*omega+352800.0*phiC[1]*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]*phiC[1])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = (((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+(3780.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0])*rho[2]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+7274.613391789284*rho[0]*rdxCp2R4[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiUx[3]+((-100800.0*rdxCp2R6[1])-682800.0*rdxCp2Sq[0]*rdxCp2R4[1]-420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(22680.0*rdxCp2Sq[0]*rdxCp2R4[1]+165960.0*rdxCp2R4[0]*rdxCp2Sq[1]+151200.0*rdxCp2R6[0])*phiUx[2]+((-352800.0*rdxCp2R6[1])-2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0])*phiC[2]+((-349181.4428058856*rdxCp2R6[1])-2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]-2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+87295.36070147139*phiUy[0]*rdxCp2R6[1]+(17280.0*rdxCp2Sq[0]*phiUy[1]-25200.0*rdxCp2Sq[0]*phiUx[1]+(591322.1457040146*phiUy[0]+21823.84017536785*phiUx[0]+174590.7214029428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(25200.0*rdxCp2R4[0]*phiUy[1]-187200.0*rdxCp2R4[0]*phiUx[1]+(363730.6695894642*phiUy[0]+162119.9555884469*phiUx[0]+806442.8560040692*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0])*phiC[2])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+(640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1]+2424.871130596428*rdxCp2R4[0])*rho[2]+(2424.871130596428*rdxCp2R4[1]+640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiUx[3]+((-235200.0*rdxCp2R6[1])-1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]-1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]-235200.0*rdxCp2R6[0])*phiC[3]+((-33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1])-48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1]+257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]+58196.90713431427*rdxCp2R6[0])*phiUx[2]+(52800.0*rdxCp2Sq[0]*rdxCp2R4[1]-336000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+58196.90713431427*phiUy[1]*rdxCp2R6[1]+(257867.7242308544*rdxCp2Sq[0]*phiUy[1]-48497.42261192856*rdxCp2Sq[0]*phiUx[1]+(28800.0*phiUy[0]+42000.0*phiUx[0]-336000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(43647.6803507357*rdxCp2R4[0]*phiUy[1]-33255.37550532244*rdxCp2R4[0]*phiUx[1]+(42000.0*phiUy[0]+28800.0*phiUx[0]+52800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0])*phiC[3])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxDirichletLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(207.8460969082653*rdxCp2R6[1]+6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]+13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-1091.192008768392*rdxCp2R6[0])*rho[1]-1200.0*rho[0]*rdxCp2R6[1]-36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-31500.0*rdxCp2R6[0]*rho[0])*omega*volFac+((4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(2771.281292110204*rdxCp2R8[1]+85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]+245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]+145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1]+44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]+97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(6400.0*rdxCp2R8[1]+193440.0*rdxCp2Sq[0]*rdxCp2R6[1]+445120.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(2400.0*phiC[0]-2400.0*phiUy[0])*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUy[1])+4156.921938165305*rdxCp2Sq[0]*phiUx[1]+((-74160.0*phiUy[0])-3600.0*phiUx[0]+84960.0*phiC[0]-28800.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-12262.91971758765*rdxCp2R4[0]*phiUy[1])+149441.3436770427*rdxCp2R4[0]*phiUx[1]+((-212280.0*phiUy[0])-129420.0*phiUx[0]+521340.0*phiC[0]-718560.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-8729.536070147138*rdxCp2R6[0]*phiUy[1])+376617.1275977765*rdxCp2R6[0]*phiUx[1]+((-126000.0*phiUy[0])-326160.0*phiUx[0]+892080.0*phiC[0]-1759680.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0]*phiUx[1]+((-113400.0*phiUx[0])+264600.0*phiC[0]-604800.0*bcVals[0])*rdxCp2R8[0])*omega-2400.0*phiC[0]*rdxCp2R8[1]-84960.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*phiC[0]*rdxCp2R8[0]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(2160.0*rdxCp2Sq[0]*rdxCp2R4[1]+5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1200.0*rdxCp2R6[1])-9480.0*rdxCp2Sq[0]*rdxCp2R4[1]-18450.0*rdxCp2R4[0]*rdxCp2Sq[1]-5670.0*rdxCp2R6[0])*rho[1]-11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-10911.92008768392*rdxCp2R6[0]*rho[0])*omega*volFac+((5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(24000.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(7200.0*rdxCp2Sq[0]*rdxCp2R6[1]+51840.0*rdxCp2R4[0]*rdxCp2R4[1]+51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1]+163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]+29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(4800.0*phiC[1]-4800.0*phiUy[1])*rdxCp2R8[1]+((-49920.0*rdxCp2Sq[0]*phiUy[1])+24000.0*rdxCp2Sq[0]*phiUx[1]+169920.0*rdxCp2Sq[0]*phiC[1]+((-20784.60969082652*phiUy[0])-20784.60969082652*phiUx[0]+166276.8775266122*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-134280.0*rdxCp2R4[0]*phiUy[1])+229200.0*rdxCp2R4[0]*phiUx[1]+1042680.0*rdxCp2R4[0]*phiC[1]+((-61314.59858793825*phiUy[0])-198493.0225473933*phiUx[0]+1039230.484541326*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-45360.0*rdxCp2R6[0]*phiUy[1])+475200.0*rdxCp2R6[0]*phiUx[1]+1784160.0*rdxCp2R6[0]*phiC[1]+((-43647.6803507357*phiUy[0])-411535.2718783651*phiUx[0]+1820731.808916403*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+151200.0*rdxCp2R8[0]*phiUx[1]+529200.0*rdxCp2R8[0]*phiC[1]+(523772.1642088283*bcVals[0]-130943.0410522071*phiUx[0])*rdxCp2R8[0])*omega-4800.0*phiC[1]*rdxCp2R8[1]-169920.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0]*phiC[1]))/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = (((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+(120.0*rdxCp2R6[1]+3870.0*rdxCp2Sq[0]*rdxCp2R4[1]+15150.0*rdxCp2R4[0]*rdxCp2Sq[1]+15750.0*rdxCp2R6[0])*rho[2]+((-360.0*rdxCp2Sq[0]*rdxCp2R4[1])-885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-346.4101615137754*rho[0]*rdxCp2R6[1]-10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiUx[3]+((-3600.0*rdxCp2Sq[0]*rdxCp2R6[1])-100800.0*rdxCp2R4[0]*rdxCp2R4[1]-210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R6[1]+25740.0*rdxCp2R4[0]*rdxCp2R4[1]+101520.0*rdxCp2R6[0]*rdxCp2Sq[1]+113400.0*rdxCp2R8[0])*phiUx[2]+((-2400.0*rdxCp2R8[1])-84960.0*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*rdxCp2R8[0])*phiC[2]+(2771.281292110204*rdxCp2R8[1]+87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]+291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]+242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+((-1200.0*rdxCp2Sq[0]*phiUy[1])+1200.0*rdxCp2Sq[0]*phiUx[1]+(3117.691453623978*phiUy[0]-1039.230484541326*phiUx[0]-8313.84387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(43200.0*rdxCp2R4[0]*phiUx[1]+(87295.36070147139*phiUy[0]-37412.29744348773*phiUx[0]-199532.2530319346*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(12600.0*rdxCp2R6[0]*phiUy[1]+93600.0*rdxCp2R6[0]*phiUx[1]+(181865.3347947321*phiUy[0]-81059.97779422344*phiUx[0]-403221.4280020346*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0])*phiC[2])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+(727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+5455.960043841962*rdxCp2R6[0])*rho[2]+((-346.4101615137754*rdxCp2R6[1])-1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]-961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiUx[3]+((-4800.0*rdxCp2R8[1])-169920.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0])*phiC[3]+(6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1]-72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1]+78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]+291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0])*phiUx[2]+(20800.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(34641.01615137755*rdxCp2Sq[0]*phiUy[1]+6928.203230275509*rdxCp2Sq[0]*phiUx[1]+((-6000.0*phiUy[0])-6000.0*phiUx[0]+48000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(174590.7214029428*rdxCp2R4[0]*phiUy[1]+49883.06325798365*rdxCp2R4[0]*phiUx[1]+(172800.0*bcVals[0]-43200.0*phiUx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(65471.52052610354*rdxCp2R6[0]*phiUy[1]+49883.06325798365*rdxCp2R6[0]*phiUx[1]+(63000.0*phiUy[0]-43200.0*phiUx[0]-79200.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0])*phiC[3])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxNeumannLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-1091.192008768392*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1]+6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[1]-31500.0*rho[0]*rdxCp2R6[1]-91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0]*rho[0])*omega*volFac+(((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(130943.0410522071*rdxCp2R8[1]+376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]+149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1])-12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-604800.0*rdxCp2R8[1])-1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]-718560.0*rdxCp2R4[0]*rdxCp2R4[1]-28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(264600.0*phiC[0]-113400.0*phiUy[0])*rdxCp2R8[1]+(97271.97335306811*rdxCp2Sq[0]*phiUy[1]+145492.2678357857*rdxCp2Sq[0]*phiUx[1]+((-326160.0*phiUy[0])-126000.0*phiUx[0]+892080.0*phiC[0]+84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(44894.75693218527*rdxCp2R4[0]*phiUy[1]+245119.8302871475*rdxCp2R4[0]*phiUx[1]+((-129420.0*phiUy[0])-212280.0*phiUx[0]+521340.0*phiC[0]+445120.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(1247.076581449591*rdxCp2R6[0]*phiUy[1]+85632.59192620528*rdxCp2R6[0]*phiUx[1]+((-3600.0*phiUy[0])-74160.0*phiUx[0]+84960.0*phiC[0]+193440.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*rdxCp2R8[0]*phiUx[1]+((-2400.0*phiUx[0])+2400.0*phiC[0]+6400.0*bcVals[0])*rdxCp2R8[0])*omega-264600.0*phiC[0]*rdxCp2R8[1]-892080.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]-84960.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]-2400.0*phiC[0]*rdxCp2R8[0]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = (((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-885.0*rdxCp2Sq[0]*rdxCp2R4[1])-360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(15750.0*rdxCp2R6[1]+15150.0*rdxCp2Sq[0]*rdxCp2R4[1]+3870.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[1]-21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*rho[0])*omega*volFac+(((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiUx[3]+(93600.0*rdxCp2Sq[0]*rdxCp2R6[1]+43200.0*rdxCp2R4[0]*rdxCp2R4[1]+1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(12600.0*rdxCp2Sq[0]*rdxCp2R6[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1])-199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(113400.0*phiUy[1]-264600.0*phiC[1])*rdxCp2R8[1]+(101520.0*rdxCp2Sq[0]*phiUy[1]-210000.0*rdxCp2Sq[0]*phiUx[1]-892080.0*rdxCp2Sq[0]*phiC[1]+((-81059.97779422344*phiUy[0])+181865.3347947321*phiUx[0]+242487.1130596428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(25740.0*rdxCp2R4[0]*phiUy[1]-100800.0*rdxCp2R4[0]*phiUx[1]-521340.0*rdxCp2R4[0]*phiC[1]+((-37412.29744348773*phiUy[0])+87295.36070147139*phiUx[0]+291677.3559945989*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(720.0*rdxCp2R6[0]*phiUy[1]-3600.0*rdxCp2R6[0]*phiUx[1]-84960.0*rdxCp2R6[0]*phiC[1]+((-1039.230484541326*phiUy[0])+3117.691453623978*phiUx[0]+87295.36070147139*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2400.0*rdxCp2R8[0]*phiC[1]+2771.281292110204*bcVals[0]*rdxCp2R8[0])*omega+264600.0*phiC[1]*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]*phiC[1])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+((-5670.0*rdxCp2R6[1])-18450.0*rdxCp2Sq[0]*rdxCp2R4[1]-9480.0*rdxCp2R4[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0])*rho[2]+(5310.0*rdxCp2Sq[0]*rdxCp2R4[1]+2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-10911.92008768392*rho[0]*rdxCp2R6[1]-30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiUx[3]+(151200.0*rdxCp2R8[1]+475200.0*rdxCp2Sq[0]*rdxCp2R6[1]+229200.0*rdxCp2R4[0]*rdxCp2R4[1]+24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-45360.0*rdxCp2Sq[0]*rdxCp2R6[1])-134280.0*rdxCp2R4[0]*rdxCp2R4[1]-49920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiUx[2]+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[2]+(523772.1642088283*rdxCp2R8[1]+1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]+1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]+166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]-130943.0410522071*phiUy[0]*rdxCp2R8[1]+(51840.0*rdxCp2Sq[0]*phiUy[1]+50400.0*rdxCp2Sq[0]*phiUx[1]+((-411535.2718783651*phiUy[0])-43647.6803507357*phiUx[0]+29098.45356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(51840.0*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*phiUx[1]+((-198493.0225473933*phiUy[0])-61314.59858793825*phiUx[0]+163505.596234502*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(7200.0*rdxCp2R6[0]*phiUy[1]+24000.0*rdxCp2R6[0]*phiUx[1]+((-20784.60969082652*phiUy[0])-20784.60969082652*phiUx[0]+63739.46971853468*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[2]))/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+((-961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1])-1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0])*rho[2]+(5455.960043841962*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[3]+(49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1]+49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]+34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+((-79200.0*rdxCp2Sq[0]*rdxCp2R6[1])+172800.0*rdxCp2R4[0]*rdxCp2R4[1]+48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[1]*rdxCp2R8[1]+(291815.9200592043*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiUx[1]+((-43200.0*phiUy[0])+63000.0*phiUx[0]+84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(78773.67072823252*rdxCp2R4[0]*phiUy[1]+(70800.0*bcVals[0]-43200.0*phiUy[0])*rdxCp2R4[0])*rdxCp2R4[1]+(4156.921938165305*rdxCp2R6[0]*phiUy[1]+6928.203230275509*rdxCp2R6[0]*phiUx[1]+((-6000.0*phiUy[0])-6000.0*phiUx[0]+20800.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[3])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxNeumannLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-25.98076211353316*rdxCp2R4[1])-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])-25.98076211353316*rdxCp2R4[0])*rho[1]+150.0*rho[0]*rdxCp2R4[1]+1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+150.0*rdxCp2R4[0]*rho[0])*omega*volFac+((1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-346.4101615137754*rdxCp2R6[1])-3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1])-1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-800.0*rdxCp2R6[1])-8880.0*rdxCp2Sq[0]*rdxCp2R4[1]-400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(300.0*phiUy[0]-300.0*phiC[0])*rdxCp2R6[1]+((-1039.230484541326*rdxCp2Sq[0]*phiUy[1])-692.8203230275509*rdxCp2Sq[0]*phiUx[1]+(3420.0*phiUy[0]+600.0*phiUx[0]-4020.0*phiC[0]-400.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-207.8460969082653*rdxCp2R4[0]*phiUy[1])-3949.07584125704*rdxCp2R4[0]*phiUx[1]+(600.0*phiUy[0]+3420.0*phiUx[0]-4020.0*phiC[0]-8880.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*phiUx[1]+(300.0*phiUx[0]-300.0*phiC[0]-800.0*bcVals[0])*rdxCp2R6[0])*omega+300.0*phiC[0]*rdxCp2R6[1]+4020.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*phiC[0]*rdxCp2R6[0])/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-450.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-90.0*rdxCp2R4[0])*rho[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+259.8076211353315*rdxCp2R4[0]*rho[0])*omega*volFac+((2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiUx[3]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(1800.0*rdxCp2Sq[0]*rdxCp2R4[1]-1800.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1])-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(1800.0*phiC[1]-1800.0*phiUy[1])*rdxCp2R6[1]+((-6120.0*rdxCp2Sq[0]*phiUy[1])+6000.0*rdxCp2Sq[0]*phiUx[1]+24120.0*rdxCp2Sq[0]*phiC[1]+(5196.152422706631*phiUy[0]-5196.152422706631*phiUx[0]-6928.203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-720.0*rdxCp2R4[0]*phiUy[1])+1200.0*rdxCp2R4[0]*phiUx[1]+24120.0*rdxCp2R4[0]*phiC[1]+(1039.230484541326*phiUy[0]-1039.230484541326*phiUx[0]-24248.71130596428*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]*phiC[1]-2078.460969082652*bcVals[0]*rdxCp2R6[0])*omega-1800.0*phiC[1]*rdxCp2R6[1]-24120.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0]*phiC[1]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+((-90.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-450.0*rdxCp2R4[0])*rho[2]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+259.8076211353315*rho[0]*rdxCp2R4[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiUx[3]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R4[1])-6120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiUx[2]+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[2]+((-2078.460969082652*rdxCp2R6[1])-24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+((-1800.0*rdxCp2Sq[0]*phiUy[1])-1200.0*rdxCp2Sq[0]*phiUx[1]+((-1039.230484541326*phiUy[0])+1039.230484541326*phiUx[0]-692.8203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1800.0*rdxCp2R4[0]*phiUy[1]-6000.0*rdxCp2R4[0]*phiUx[1]+((-5196.152422706631*phiUy[0])+5196.152422706631*phiUx[0]-15934.86742963367*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[2]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+((-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])-129.9038105676658*rdxCp2R4[0])*rho[2]+((-129.9038105676658*rdxCp2R4[1])-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[3]+(1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1]-1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1])*phiUy[2]+(1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1]+5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-5200.0*rdxCp2Sq[0]*rdxCp2R4[1])-2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(5196.152422706631*rdxCp2Sq[0]*phiUy[1]+1732.050807568877*rdxCp2Sq[0]*phiUx[1]+(1500.0*phiUy[0]-1500.0*phiUx[0]-2000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1039.230484541326*rdxCp2R4[0]*phiUy[1]-1732.050807568877*rdxCp2R4[0]*phiUx[1]+((-1500.0*phiUy[0])+1500.0*phiUx[0]-5200.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[3])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxDirichletUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(727.4613391789284*rdxCp2R4[1]+4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])-727.4613391789284*rdxCp2R4[0])*rho[1]-21000.0*rho[0]*rdxCp2R4[1]-130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0]*rho[0])*omega*volFac+(((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-403200.0*rdxCp2R6[1])-2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]-504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1]+32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-87295.36070147139*rdxCp2R6[1])-538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]-72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(176400.0*phiC[0]-75600.0*phiLy[0])*rdxCp2R6[1]+(72746.13391789283*rdxCp2Sq[0]*phiUx[1]-32423.99111768937*rdxCp2Sq[0]*phiLy[1]+((-63000.0*phiUx[0])-466740.0*phiLy[0]+1285620.0*phiC[0]-504000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(538944.9292831317*rdxCp2R4[0]*phiUx[1]-4364.768035073569*rdxCp2R4[0]*phiLy[1]+((-466740.0*phiUx[0])-63000.0*phiLy[0]+1285620.0*phiC[0]-2519520.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+87295.36070147139*rdxCp2R6[0]*phiUx[1]+((-75600.0*phiUx[0])+176400.0*phiC[0]-403200.0*bcVals[0])*rdxCp2R6[0])*omega-176400.0*phiC[0]*rdxCp2R6[1]-1285620.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]-1285620.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]-176400.0*phiC[0]*rdxCp2R6[0]))/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-21000.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-3780.0*rdxCp2R4[0])*rho[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-7274.613391789284*rdxCp2R4[0]*rho[0])*omega*volFac+(((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(25200.0*rdxCp2Sq[0]*rdxCp2R4[1]+17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-187200.0*rdxCp2Sq[0]*rdxCp2R4[1])-25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(352800.0*phiC[1]-151200.0*phiLy[1])*rdxCp2R6[1]+(420000.0*rdxCp2Sq[0]*phiUx[1]-165960.0*rdxCp2Sq[0]*phiLy[1]+2571240.0*rdxCp2Sq[0]*phiC[1]+((-363730.6695894642*phiUx[0])-162119.9555884469*phiLy[0]+2909845.356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(682800.0*rdxCp2R4[0]*phiUx[1]-22680.0*rdxCp2R4[0]*phiLy[1]+2571240.0*rdxCp2R4[0]*phiC[1]+((-591322.1457040146*phiUx[0])-21823.84017536785*phiLy[0]+2627174.664920473*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+100800.0*rdxCp2R6[0]*phiUx[1]+352800.0*rdxCp2R6[0]*phiC[1]+(349181.4428058856*bcVals[0]-87295.36070147139*phiUx[0])*rdxCp2R6[0])*omega-352800.0*phiC[1]*rdxCp2R6[1]-2571240.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0]*phiC[1]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = (((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+(3780.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0])*rho[2]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-7274.613391789284*rho[0]*rdxCp2R4[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiUx[3]+((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(349181.4428058856*rdxCp2R6[1]+2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]+2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(22680.0*rdxCp2Sq[0]*rdxCp2R4[1]+165960.0*rdxCp2R4[0]*rdxCp2Sq[1]+151200.0*rdxCp2R6[0])*phiUx[2]+((-100800.0*rdxCp2R6[1])-682800.0*rdxCp2Sq[0]*rdxCp2R4[1]-420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-352800.0*rdxCp2R6[1])-2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0])*phiC[2]-87295.36070147139*phiLy[0]*rdxCp2R6[1]+(25200.0*rdxCp2Sq[0]*phiUx[1]-17280.0*rdxCp2Sq[0]*phiLy[1]+((-21823.84017536785*phiUx[0])-591322.1457040146*phiLy[0]-174590.7214029428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(187200.0*rdxCp2R4[0]*phiUx[1]-25200.0*rdxCp2R4[0]*phiLy[1]+((-162119.9555884469*phiUx[0])-363730.6695894642*phiLy[0]-806442.8560040692*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0])*phiC[2])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+(640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1]+2424.871130596428*rdxCp2R4[0])*rho[2]+((-2424.871130596428*rdxCp2R4[1])-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiUx[3]+((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-235200.0*rdxCp2R6[1])-1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]-1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]-235200.0*rdxCp2R6[0])*phiC[3]+(336000.0*rdxCp2R4[0]*rdxCp2Sq[1]-52800.0*rdxCp2Sq[0]*rdxCp2R4[1])*bcVals[3]+(43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1]+257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]+58196.90713431427*rdxCp2R6[0])*phiUx[2]+((-33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1])-48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]-58196.90713431427*phiLy[1]*rdxCp2R6[1]+(48497.42261192856*rdxCp2Sq[0]*phiUx[1]-257867.7242308544*rdxCp2Sq[0]*phiLy[1]+((-42000.0*phiUx[0])-28800.0*phiLy[0]+336000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(33255.37550532244*rdxCp2R4[0]*phiUx[1]-43647.6803507357*rdxCp2R4[0]*phiLy[1]+((-28800.0*phiUx[0])-42000.0*phiLy[0]-52800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0])*phiC[3])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxDirichletUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(207.8460969082653*rdxCp2R6[1]+6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]+13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+1091.192008768392*rdxCp2R6[0])*rho[1]+1200.0*rho[0]*rdxCp2R6[1]+36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+31500.0*rdxCp2R6[0]*rho[0])*omega*volFac+(((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(6400.0*rdxCp2R8[1]+193440.0*rdxCp2Sq[0]*rdxCp2R6[1]+445120.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1]+44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]+97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(2771.281292110204*rdxCp2R8[1]+85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]+245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]+145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(2400.0*phiLy[0]-2400.0*phiC[0])*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUx[1])+4156.921938165305*rdxCp2Sq[0]*phiLy[1]+(3600.0*phiUx[0]+74160.0*phiLy[0]-84960.0*phiC[0]+28800.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-149441.3436770427*rdxCp2R4[0]*phiUx[1])+12262.91971758765*rdxCp2R4[0]*phiLy[1]+(129420.0*phiUx[0]+212280.0*phiLy[0]-521340.0*phiC[0]+718560.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-376617.1275977765*rdxCp2R6[0]*phiUx[1])+8729.536070147138*rdxCp2R6[0]*phiLy[1]+(326160.0*phiUx[0]+126000.0*phiLy[0]-892080.0*phiC[0]+1759680.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0]*phiUx[1]+(113400.0*phiUx[0]-264600.0*phiC[0]+604800.0*bcVals[0])*rdxCp2R8[0])*omega+2400.0*phiC[0]*rdxCp2R8[1]+84960.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*phiC[0]*rdxCp2R8[0])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = (((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(2160.0*rdxCp2Sq[0]*rdxCp2R4[1]+5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1200.0*rdxCp2R6[1]+9480.0*rdxCp2Sq[0]*rdxCp2R4[1]+18450.0*rdxCp2R4[0]*rdxCp2Sq[1]+5670.0*rdxCp2R6[0])*rho[1]+11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+10911.92008768392*rdxCp2R6[0]*rho[0])*omega*volFac+(((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+(5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1]+163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]+29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(7200.0*rdxCp2Sq[0]*rdxCp2R6[1]+51840.0*rdxCp2R4[0]*rdxCp2R4[1]+51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(24000.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(4800.0*phiLy[1]-4800.0*phiC[1])*rdxCp2R8[1]+((-24000.0*rdxCp2Sq[0]*phiUx[1])+49920.0*rdxCp2Sq[0]*phiLy[1]-169920.0*rdxCp2Sq[0]*phiC[1]+(20784.60969082652*phiUx[0]+20784.60969082652*phiLy[0]-166276.8775266122*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-229200.0*rdxCp2R4[0]*phiUx[1])+134280.0*rdxCp2R4[0]*phiLy[1]-1042680.0*rdxCp2R4[0]*phiC[1]+(198493.0225473933*phiUx[0]+61314.59858793825*phiLy[0]-1039230.484541326*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-475200.0*rdxCp2R6[0]*phiUx[1])+45360.0*rdxCp2R6[0]*phiLy[1]-1784160.0*rdxCp2R6[0]*phiC[1]+(411535.2718783651*phiUx[0]+43647.6803507357*phiLy[0]-1820731.808916403*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-151200.0*rdxCp2R8[0]*phiUx[1]-529200.0*rdxCp2R8[0]*phiC[1]+(130943.0410522071*phiUx[0]-523772.1642088283*bcVals[0])*rdxCp2R8[0])*omega+4800.0*phiC[1]*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]*phiC[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = (((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+(120.0*rdxCp2R6[1]+3870.0*rdxCp2Sq[0]*rdxCp2R4[1]+15150.0*rdxCp2R4[0]*rdxCp2Sq[1]+15750.0*rdxCp2R6[0])*rho[2]+(360.0*rdxCp2Sq[0]*rdxCp2R4[1]+885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+346.4101615137754*rho[0]*rdxCp2R6[1]+10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiUx[3]+(1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(2771.281292110204*rdxCp2R8[1]+87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]+291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]+242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(720.0*rdxCp2Sq[0]*rdxCp2R6[1]+25740.0*rdxCp2R4[0]*rdxCp2R4[1]+101520.0*rdxCp2R6[0]*rdxCp2Sq[1]+113400.0*rdxCp2R8[0])*phiUx[2]+((-3600.0*rdxCp2Sq[0]*rdxCp2R6[1])-100800.0*rdxCp2R4[0]*rdxCp2R4[1]-210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-2400.0*rdxCp2R8[1])-84960.0*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*rdxCp2R8[0])*phiC[2]+((-1200.0*rdxCp2Sq[0]*phiUx[1])+1200.0*rdxCp2Sq[0]*phiLy[1]+(1039.230484541326*phiUx[0]-3117.691453623978*phiLy[0]+8313.84387633061*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((37412.29744348773*phiUx[0]-87295.36070147139*phiLy[0]+199532.2530319346*bcVals[0])*rdxCp2R4[0]-43200.0*rdxCp2R4[0]*phiUx[1])*rdxCp2R4[1]+((-93600.0*rdxCp2R6[0]*phiUx[1])-12600.0*rdxCp2R6[0]*phiLy[1]+(81059.97779422344*phiUx[0]-181865.3347947321*phiLy[0]+403221.4280020346*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0])*phiC[2])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+(727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+5455.960043841962*rdxCp2R6[0])*rho[2]+(346.4101615137754*rdxCp2R6[1]+1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]+961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiUx[3]+((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-4800.0*rdxCp2R8[1])-169920.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0])*phiC[3]+(20800.0*rdxCp2Sq[0]*rdxCp2R6[1]+70800.0*rdxCp2R4[0]*rdxCp2R4[1]+84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1]+78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]+291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0])*phiUx[2]+(6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1]-72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-6928.203230275509*rdxCp2Sq[0]*phiUx[1])-34641.01615137755*rdxCp2Sq[0]*phiLy[1]+(6000.0*phiUx[0]+6000.0*phiLy[0]-48000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-49883.06325798365*rdxCp2R4[0]*phiUx[1])-174590.7214029428*rdxCp2R4[0]*phiLy[1]+(43200.0*phiUx[0]-172800.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-49883.06325798365*rdxCp2R6[0]*phiUx[1])-65471.52052610354*rdxCp2R6[0]*phiLy[1]+(43200.0*phiUx[0]-63000.0*phiLy[0]+79200.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0])*phiC[3])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxNeumannUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-1091.192008768392*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1])-6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]-207.8460969082653*rdxCp2R6[0])*rho[1]+31500.0*rho[0]*rdxCp2R6[1]+91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0]*rho[0])*omega*volFac+((10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(604800.0*rdxCp2R8[1]+1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]+718560.0*rdxCp2R4[0]*rdxCp2R4[1]+28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1])-12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(130943.0410522071*rdxCp2R8[1]+376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]+149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(113400.0*phiLy[0]-264600.0*phiC[0])*rdxCp2R8[1]+((-145492.2678357857*rdxCp2Sq[0]*phiUx[1])-97271.97335306811*rdxCp2Sq[0]*phiLy[1]+(126000.0*phiUx[0]+326160.0*phiLy[0]-892080.0*phiC[0]-84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-245119.8302871475*rdxCp2R4[0]*phiUx[1])-44894.75693218527*rdxCp2R4[0]*phiLy[1]+(212280.0*phiUx[0]+129420.0*phiLy[0]-521340.0*phiC[0]-445120.0*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-85632.59192620528*rdxCp2R6[0]*phiUx[1])-1247.076581449591*rdxCp2R6[0]*phiLy[1]+(74160.0*phiUx[0]+3600.0*phiLy[0]-84960.0*phiC[0]-193440.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*rdxCp2R8[0]*phiUx[1]+(2400.0*phiUx[0]-2400.0*phiC[0]-6400.0*bcVals[0])*rdxCp2R8[0])*omega+264600.0*phiC[0]*rdxCp2R8[1]+892080.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*phiC[0]*rdxCp2R8[0])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-885.0*rdxCp2Sq[0]*rdxCp2R4[1])-360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-15750.0*rdxCp2R6[1])-15150.0*rdxCp2Sq[0]*rdxCp2R4[1]-3870.0*rdxCp2R4[0]*rdxCp2Sq[1]-120.0*rdxCp2R6[0])*rho[1]+21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*rho[0])*omega*volFac+((1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiUx[3]+((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1]+199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]+8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(12600.0*rdxCp2Sq[0]*rdxCp2R6[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(93600.0*rdxCp2Sq[0]*rdxCp2R6[1]+43200.0*rdxCp2R4[0]*rdxCp2R4[1]+1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(264600.0*phiC[1]-113400.0*phiLy[1])*rdxCp2R8[1]+(210000.0*rdxCp2Sq[0]*phiUx[1]-101520.0*rdxCp2Sq[0]*phiLy[1]+892080.0*rdxCp2Sq[0]*phiC[1]+((-181865.3347947321*phiUx[0])+81059.97779422344*phiLy[0]-242487.1130596428*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(100800.0*rdxCp2R4[0]*phiUx[1]-25740.0*rdxCp2R4[0]*phiLy[1]+521340.0*rdxCp2R4[0]*phiC[1]+((-87295.36070147139*phiUx[0])+37412.29744348773*phiLy[0]-291677.3559945989*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+(3600.0*rdxCp2R6[0]*phiUx[1]-720.0*rdxCp2R6[0]*phiLy[1]+84960.0*rdxCp2R6[0]*phiC[1]+((-3117.691453623978*phiUx[0])+1039.230484541326*phiLy[0]-87295.36070147139*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]*phiC[1]-2771.281292110204*bcVals[0]*rdxCp2R8[0])*omega-264600.0*phiC[1]*rdxCp2R8[1]-892080.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]-84960.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]-2400.0*rdxCp2R8[0]*phiC[1]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+((-5670.0*rdxCp2R6[1])-18450.0*rdxCp2Sq[0]*rdxCp2R4[1]-9480.0*rdxCp2R4[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0])*rho[2]+((-5310.0*rdxCp2Sq[0]*rdxCp2R4[1])-2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+10911.92008768392*rho[0]*rdxCp2R6[1]+30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiUx[3]+((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-523772.1642088283*rdxCp2R8[1])-1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]-1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]-166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-45360.0*rdxCp2Sq[0]*rdxCp2R6[1])-134280.0*rdxCp2R4[0]*rdxCp2R4[1]-49920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiUx[2]+(151200.0*rdxCp2R8[1]+475200.0*rdxCp2Sq[0]*rdxCp2R6[1]+229200.0*rdxCp2R4[0]*rdxCp2R4[1]+24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[2]+130943.0410522071*phiLy[0]*rdxCp2R8[1]+((-50400.0*rdxCp2Sq[0]*phiUx[1])-51840.0*rdxCp2Sq[0]*phiLy[1]+(43647.6803507357*phiUx[0]+411535.2718783651*phiLy[0]-29098.45356715714*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-70800.0*rdxCp2R4[0]*phiUx[1])-51840.0*rdxCp2R4[0]*phiLy[1]+(61314.59858793825*phiUx[0]+198493.0225473933*phiLy[0]-163505.596234502*bcVals[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-24000.0*rdxCp2R6[0]*phiUx[1])-7200.0*rdxCp2R6[0]*phiLy[1]+(20784.60969082652*phiUx[0]+20784.60969082652*phiLy[0]-63739.46971853468*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[2]))/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+((-961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1])-1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0])*rho[2]+((-5455.960043841962*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[3]+((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[3]+(79200.0*rdxCp2Sq[0]*rdxCp2R6[1]-172800.0*rdxCp2R4[0]*rdxCp2R4[1]-48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]+34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiUx[2]+(49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1]+49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]-130943.0410522071*phiLy[1]*rdxCp2R8[1]+(72746.13391789283*rdxCp2Sq[0]*phiUx[1]-291815.9200592043*rdxCp2Sq[0]*phiLy[1]+((-63000.0*phiUx[0])+43200.0*phiLy[0]-84000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((43200.0*phiLy[0]-70800.0*bcVals[0])*rdxCp2R4[0]-78773.67072823252*rdxCp2R4[0]*phiLy[1])*rdxCp2R4[1]+((-6928.203230275509*rdxCp2R6[0]*phiUx[1])-4156.921938165305*rdxCp2R6[0]*phiLy[1]+(6000.0*phiUx[0]+6000.0*phiLy[0]-20800.0*bcVals[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[3])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_LxNeumannUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-25.98076211353316*rdxCp2R4[1])-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1]+25.98076211353316*rdxCp2R4[0])*rho[1]-150.0*rho[0]*rdxCp2R4[1]-1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-150.0*rdxCp2R4[0]*rho[0])*omega*volFac+((240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-800.0*rdxCp2R6[1])-8880.0*rdxCp2Sq[0]*rdxCp2R4[1]-400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1])-1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-346.4101615137754*rdxCp2R6[1])-3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(300.0*phiC[0]-300.0*phiLy[0])*rdxCp2R6[1]+(692.8203230275509*rdxCp2Sq[0]*phiUx[1]+1039.230484541326*rdxCp2Sq[0]*phiLy[1]+((-600.0*phiUx[0])-3420.0*phiLy[0]+4020.0*phiC[0]+400.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(3949.07584125704*rdxCp2R4[0]*phiUx[1]+207.8460969082653*rdxCp2R4[0]*phiLy[1]+((-3420.0*phiUx[0])-600.0*phiLy[0]+4020.0*phiC[0]+8880.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*phiUx[1]+((-300.0*phiUx[0])+300.0*phiC[0]+800.0*bcVals[0])*rdxCp2R6[0])*omega-300.0*phiC[0]*rdxCp2R6[1]-4020.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]-4020.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]-300.0*phiC[0]*rdxCp2R6[0]))/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = (((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(450.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+90.0*rdxCp2R4[0])*rho[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-259.8076211353315*rdxCp2R4[0]*rho[0])*omega*volFac+((2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiUx[3]+(2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1])-692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1800.0*rdxCp2Sq[0]*rdxCp2R4[1]-1800.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(1800.0*phiLy[1]-1800.0*phiC[1])*rdxCp2R6[1]+((-6000.0*rdxCp2Sq[0]*phiUx[1])+6120.0*rdxCp2Sq[0]*phiLy[1]-24120.0*rdxCp2Sq[0]*phiC[1]+(5196.152422706631*phiUx[0]-5196.152422706631*phiLy[0]+6928.203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1200.0*rdxCp2R4[0]*phiUx[1])+720.0*rdxCp2R4[0]*phiLy[1]-24120.0*rdxCp2R4[0]*phiC[1]+(1039.230484541326*phiUx[0]-1039.230484541326*phiLy[0]+24248.71130596428*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1]-1800.0*rdxCp2R6[0]*phiC[1]+2078.460969082652*bcVals[0]*rdxCp2R6[0])*omega+1800.0*phiC[1]*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]*phiC[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+((-90.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-450.0*rdxCp2R4[0])*rho[2]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-259.8076211353315*rho[0]*rdxCp2R4[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiUx[3]+(2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-2078.460969082652*rdxCp2R6[1])-24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-720.0*rdxCp2Sq[0]*rdxCp2R4[1])-6120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiUx[2]+(1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[2]+(1200.0*rdxCp2Sq[0]*phiUx[1]+1800.0*rdxCp2Sq[0]*phiLy[1]+((-1039.230484541326*phiUx[0])+1039.230484541326*phiLy[0]+692.8203230275509*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(6000.0*rdxCp2R4[0]*phiUx[1]-1800.0*rdxCp2R4[0]*phiLy[1]+((-5196.152422706631*phiUx[0])+5196.152422706631*phiLy[0]+15934.86742963367*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[2]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+((-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])-129.9038105676658*rdxCp2R4[0])*rho[2]+(129.9038105676658*rdxCp2R4[1]+181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[3]+((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[3]+((-5200.0*rdxCp2Sq[0]*rdxCp2R4[1])-2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1]+5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiUx[2]+(1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1]-1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1])*phiLy[2]+((-1732.050807568877*rdxCp2Sq[0]*phiUx[1])-5196.152422706631*rdxCp2Sq[0]*phiLy[1]+(1500.0*phiUx[0]-1500.0*phiLy[0]+2000.0*bcVals[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1732.050807568877*rdxCp2R4[0]*phiUx[1]-1039.230484541326*rdxCp2R4[0]*phiLy[1]+((-1500.0*phiUx[0])+1500.0*phiLy[0]+5200.0*bcVals[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[3])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxDirichletLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-727.4613391789284*rdxCp2R4[1])-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[1]-21000.0*rho[0]*rdxCp2R4[1]-130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0]*rho[0])*omega*volFac+(((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(87295.36070147139*rdxCp2R6[1]+538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]+72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1])-32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-403200.0*rdxCp2R6[1])-2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]-504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(176400.0*phiC[0]-75600.0*phiUy[0])*rdxCp2R6[1]+(32423.99111768937*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiLx[1]-504000.0*rdxCp2Sq[0]*bcVals[1]+((-466740.0*phiUy[0])-63000.0*phiLx[0]+1285620.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(4364.768035073569*rdxCp2R4[0]*phiUy[1]-538944.9292831317*rdxCp2R4[0]*phiLx[1]-2519520.0*rdxCp2R4[0]*bcVals[1]+((-63000.0*phiUy[0])-466740.0*phiLx[0]+1285620.0*phiC[0])*rdxCp2R4[0])*rdxCp2Sq[1]-87295.36070147139*rdxCp2R6[0]*phiLx[1]-403200.0*rdxCp2R6[0]*bcVals[1]+(176400.0*phiC[0]-75600.0*phiLx[0])*rdxCp2R6[0])*omega-176400.0*phiC[0]*rdxCp2R6[1]-1285620.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]-1285620.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]-176400.0*phiC[0]*rdxCp2R6[0]))/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = (((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(21000.0*rdxCp2R4[1]+26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]+3780.0*rdxCp2R4[0])*rho[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-7274.613391789284*rdxCp2R4[0]*rho[0])*omega*volFac+(((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(187200.0*rdxCp2Sq[0]*rdxCp2R4[1]+25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-25200.0*rdxCp2Sq[0]*rdxCp2R4[1])-17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(151200.0*phiUy[1]-352800.0*phiC[1])*rdxCp2R6[1]+(165960.0*rdxCp2Sq[0]*phiUy[1]-420000.0*rdxCp2Sq[0]*phiLx[1]-2571240.0*rdxCp2Sq[0]*phiC[1]+2909845.356715714*rdxCp2Sq[0]*bcVals[1]+((-162119.9555884469*phiUy[0])-363730.6695894642*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(22680.0*rdxCp2R4[0]*phiUy[1]-682800.0*rdxCp2R4[0]*phiLx[1]-2571240.0*rdxCp2R4[0]*phiC[1]+2627174.664920473*rdxCp2R4[0]*bcVals[1]+((-21823.84017536785*phiUy[0])-591322.1457040146*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]-100800.0*rdxCp2R6[0]*phiLx[1]-352800.0*rdxCp2R6[0]*phiC[1]+349181.4428058856*rdxCp2R6[0]*bcVals[1]-87295.36070147139*phiLx[0]*rdxCp2R6[0])*omega+352800.0*phiC[1]*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]*phiC[1])/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+((-3780.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0])*rho[2]+1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-7274.613391789284*rho[0]*rdxCp2R4[1]-43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiLx[3]+(100800.0*rdxCp2R6[1]+682800.0*rdxCp2Sq[0]*rdxCp2R4[1]+420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-22680.0*rdxCp2Sq[0]*rdxCp2R4[1])-165960.0*rdxCp2R4[0]*rdxCp2Sq[1]-151200.0*rdxCp2R6[0])*phiLx[2]+(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0])*phiC[2]+(349181.4428058856*rdxCp2R6[1]+2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]+2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]-87295.36070147139*phiUy[0]*rdxCp2R6[1]+(17280.0*rdxCp2Sq[0]*phiUy[1]-25200.0*rdxCp2Sq[0]*phiLx[1]-174590.7214029428*rdxCp2Sq[0]*bcVals[1]+((-591322.1457040146*phiUy[0])-21823.84017536785*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(25200.0*rdxCp2R4[0]*phiUy[1]-187200.0*rdxCp2R4[0]*phiLx[1]-806442.8560040692*rdxCp2R4[0]*bcVals[1]+((-363730.6695894642*phiUy[0])-162119.9555884469*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+((-352800.0*rdxCp2R6[1])-2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0])*phiC[2]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+((-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])-2424.871130596428*rdxCp2R4[0])*rho[2]+(2424.871130596428*rdxCp2R4[1]+640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiLx[3]+((-235200.0*rdxCp2R6[1])-1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]-1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]-235200.0*rdxCp2R6[0])*phiC[3]+(33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1]+48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1])-257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]-58196.90713431427*rdxCp2R6[0])*phiLx[2]+(336000.0*rdxCp2R4[0]*rdxCp2Sq[1]-52800.0*rdxCp2Sq[0]*rdxCp2R4[1])*bcVals[2]+58196.90713431427*phiUy[1]*rdxCp2R6[1]+(257867.7242308544*rdxCp2Sq[0]*phiUy[1]-48497.42261192856*rdxCp2Sq[0]*phiLx[1]+336000.0*rdxCp2Sq[0]*bcVals[1]+((-28800.0*phiUy[0])-42000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(43647.6803507357*rdxCp2R4[0]*phiUy[1]-33255.37550532244*rdxCp2R4[0]*phiLx[1]-52800.0*rdxCp2R4[0]*bcVals[1]+((-42000.0*phiUy[0])-28800.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0])*phiC[3])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxDirichletLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-207.8460969082653*rdxCp2R6[1])-6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]-13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-1091.192008768392*rdxCp2R6[0])*rho[1]+1200.0*rho[0]*rdxCp2R6[1]+36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+31500.0*rdxCp2R6[0]*rho[0])*omega*volFac+((4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-2771.281292110204*rdxCp2R8[1])-85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]-245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]-145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1])-44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]-97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+((-6400.0*rdxCp2R8[1])-193440.0*rdxCp2Sq[0]*rdxCp2R6[1]-445120.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(2400.0*phiUy[0]-2400.0*phiC[0])*rdxCp2R8[1]+((-4156.921938165305*rdxCp2Sq[0]*phiUy[1])+4156.921938165305*rdxCp2Sq[0]*phiLx[1]+28800.0*rdxCp2Sq[0]*bcVals[1]+(74160.0*phiUy[0]+3600.0*phiLx[0]-84960.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-12262.91971758765*rdxCp2R4[0]*phiUy[1])+149441.3436770427*rdxCp2R4[0]*phiLx[1]+718560.0*rdxCp2R4[0]*bcVals[1]+(212280.0*phiUy[0]+129420.0*phiLx[0]-521340.0*phiC[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-8729.536070147138*rdxCp2R6[0]*phiUy[1])+376617.1275977765*rdxCp2R6[0]*phiLx[1]+1759680.0*rdxCp2R6[0]*bcVals[1]+(126000.0*phiUy[0]+326160.0*phiLx[0]-892080.0*phiC[0])*rdxCp2R6[0])*rdxCp2Sq[1]+130943.0410522071*rdxCp2R8[0]*phiLx[1]+604800.0*rdxCp2R8[0]*bcVals[1]+(113400.0*phiLx[0]-264600.0*phiC[0])*rdxCp2R8[0])*omega+2400.0*phiC[0]*rdxCp2R8[1]+84960.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*phiC[0]*rdxCp2R8[0])/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-2160.0*rdxCp2Sq[0]*rdxCp2R4[1])-5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-1200.0*rdxCp2R6[1])-9480.0*rdxCp2Sq[0]*rdxCp2R4[1]-18450.0*rdxCp2R4[0]*rdxCp2Sq[1]-5670.0*rdxCp2R6[0])*rho[1]+11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+10911.92008768392*rdxCp2R6[0]*rho[0])*omega*volFac+((5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-24000.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-7200.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+((-63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1])-163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]-29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(4800.0*phiC[1]-4800.0*phiUy[1])*rdxCp2R8[1]+((-49920.0*rdxCp2Sq[0]*phiUy[1])+24000.0*rdxCp2Sq[0]*phiLx[1]+169920.0*rdxCp2Sq[0]*phiC[1]-166276.8775266122*rdxCp2Sq[0]*bcVals[1]+(20784.60969082652*phiUy[0]+20784.60969082652*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-134280.0*rdxCp2R4[0]*phiUy[1])+229200.0*rdxCp2R4[0]*phiLx[1]+1042680.0*rdxCp2R4[0]*phiC[1]-1039230.484541326*rdxCp2R4[0]*bcVals[1]+(61314.59858793825*phiUy[0]+198493.0225473933*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-45360.0*rdxCp2R6[0]*phiUy[1])+475200.0*rdxCp2R6[0]*phiLx[1]+1784160.0*rdxCp2R6[0]*phiC[1]-1820731.808916403*rdxCp2R6[0]*bcVals[1]+(43647.6803507357*phiUy[0]+411535.2718783651*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]+151200.0*rdxCp2R8[0]*phiLx[1]+529200.0*rdxCp2R8[0]*phiC[1]-523772.1642088283*rdxCp2R8[0]*bcVals[1]+130943.0410522071*phiLx[0]*rdxCp2R8[0])*omega-4800.0*phiC[1]*rdxCp2R8[1]-169920.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0]*phiC[1]))/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+((-120.0*rdxCp2R6[1])-3870.0*rdxCp2Sq[0]*rdxCp2R4[1]-15150.0*rdxCp2R4[0]*rdxCp2Sq[1]-15750.0*rdxCp2R6[0])*rho[2]+((-360.0*rdxCp2Sq[0]*rdxCp2R4[1])-885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+346.4101615137754*rho[0]*rdxCp2R6[1]+10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[3]+(3600.0*rdxCp2Sq[0]*rdxCp2R6[1]+100800.0*rdxCp2R4[0]*rdxCp2R4[1]+210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R6[1])-25740.0*rdxCp2R4[0]*rdxCp2R4[1]-101520.0*rdxCp2R6[0]*rdxCp2Sq[1]-113400.0*rdxCp2R8[0])*phiLx[2]+(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0])*phiC[2]+((-2771.281292110204*rdxCp2R8[1])-87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]-291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]-242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+((-1200.0*rdxCp2Sq[0]*phiUy[1])+1200.0*rdxCp2Sq[0]*phiLx[1]+8313.84387633061*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiLx[0]-3117.691453623978*phiUy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(43200.0*rdxCp2R4[0]*phiLx[1]+199532.2530319346*rdxCp2R4[0]*bcVals[1]+(37412.29744348773*phiLx[0]-87295.36070147139*phiUy[0])*rdxCp2R4[0])*rdxCp2R4[1]+(12600.0*rdxCp2R6[0]*phiUy[1]+93600.0*rdxCp2R6[0]*phiLx[1]+403221.4280020346*rdxCp2R6[0]*bcVals[1]+(81059.97779422344*phiLx[0]-181865.3347947321*phiUy[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+((-2400.0*rdxCp2R8[1])-84960.0*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*rdxCp2R8[0])*phiC[2]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+((-727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-5455.960043841962*rdxCp2R6[0])*rho[2]+((-346.4101615137754*rdxCp2R6[1])-1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]-961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiLx[3]+((-4800.0*rdxCp2R8[1])-169920.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0])*phiC[3]+(72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1]-6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1])*phiUy[2]+((-4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1])-78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]-291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[2]+((-20800.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(34641.01615137755*rdxCp2Sq[0]*phiUy[1]+6928.203230275509*rdxCp2Sq[0]*phiLx[1]-48000.0*rdxCp2Sq[0]*bcVals[1]+(6000.0*phiUy[0]+6000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(174590.7214029428*rdxCp2R4[0]*phiUy[1]+49883.06325798365*rdxCp2R4[0]*phiLx[1]-172800.0*rdxCp2R4[0]*bcVals[1]+43200.0*phiLx[0]*rdxCp2R4[0])*rdxCp2R4[1]+(65471.52052610354*rdxCp2R6[0]*phiUy[1]+49883.06325798365*rdxCp2R6[0]*phiLx[1]+79200.0*rdxCp2R6[0]*bcVals[1]+(43200.0*phiLx[0]-63000.0*phiUy[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0])*phiC[3])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxNeumannLyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = (((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(1091.192008768392*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1]+6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[1]+31500.0*rho[0]*rdxCp2R6[1]+91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0]*rho[0])*omega*volFac+(((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-130943.0410522071*rdxCp2R8[1])-376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]-149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1]+12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(604800.0*rdxCp2R8[1]+1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]+718560.0*rdxCp2R4[0]*rdxCp2R4[1]+28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(113400.0*phiUy[0]-264600.0*phiC[0])*rdxCp2R8[1]+(97271.97335306811*rdxCp2Sq[0]*phiUy[1]+145492.2678357857*rdxCp2Sq[0]*phiLx[1]+84000.0*rdxCp2Sq[0]*bcVals[1]+(326160.0*phiUy[0]+126000.0*phiLx[0]-892080.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(44894.75693218527*rdxCp2R4[0]*phiUy[1]+245119.8302871475*rdxCp2R4[0]*phiLx[1]+445120.0*rdxCp2R4[0]*bcVals[1]+(129420.0*phiUy[0]+212280.0*phiLx[0]-521340.0*phiC[0])*rdxCp2R4[0])*rdxCp2R4[1]+(1247.076581449591*rdxCp2R6[0]*phiUy[1]+85632.59192620528*rdxCp2R6[0]*phiLx[1]+193440.0*rdxCp2R6[0]*bcVals[1]+(3600.0*phiUy[0]+74160.0*phiLx[0]-84960.0*phiC[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2771.281292110204*rdxCp2R8[0]*phiLx[1]+6400.0*rdxCp2R8[0]*bcVals[1]+(2400.0*phiLx[0]-2400.0*phiC[0])*rdxCp2R8[0])*omega+264600.0*phiC[0]*rdxCp2R8[1]+892080.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*phiC[0]*rdxCp2R8[0])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = (((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(885.0*rdxCp2Sq[0]*rdxCp2R4[1]+360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(15750.0*rdxCp2R6[1]+15150.0*rdxCp2Sq[0]*rdxCp2R4[1]+3870.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[1]+21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*rho[0])*omega*volFac+(((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[3]+((-93600.0*rdxCp2Sq[0]*rdxCp2R6[1])-43200.0*rdxCp2R4[0]*rdxCp2R4[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(1200.0*rdxCp2R6[0]*rdxCp2Sq[1]-12600.0*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[2]+(403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1]+199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]+8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+(113400.0*phiUy[1]-264600.0*phiC[1])*rdxCp2R8[1]+(101520.0*rdxCp2Sq[0]*phiUy[1]-210000.0*rdxCp2Sq[0]*phiLx[1]-892080.0*rdxCp2Sq[0]*phiC[1]+242487.1130596428*rdxCp2Sq[0]*bcVals[1]+(81059.97779422344*phiUy[0]-181865.3347947321*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(25740.0*rdxCp2R4[0]*phiUy[1]-100800.0*rdxCp2R4[0]*phiLx[1]-521340.0*rdxCp2R4[0]*phiC[1]+291677.3559945989*rdxCp2R4[0]*bcVals[1]+(37412.29744348773*phiUy[0]-87295.36070147139*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(720.0*rdxCp2R6[0]*phiUy[1]-3600.0*rdxCp2R6[0]*phiLx[1]-84960.0*rdxCp2R6[0]*phiC[1]+87295.36070147139*rdxCp2R6[0]*bcVals[1]+(1039.230484541326*phiUy[0]-3117.691453623978*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2400.0*rdxCp2R8[0]*phiC[1]+2771.281292110204*rdxCp2R8[0]*bcVals[1])*omega+264600.0*phiC[1]*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]*phiC[1])/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = (((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+(5670.0*rdxCp2R6[1]+18450.0*rdxCp2Sq[0]*rdxCp2R4[1]+9480.0*rdxCp2R4[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0])*rho[2]+(5310.0*rdxCp2Sq[0]*rdxCp2R4[1]+2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+10911.92008768392*rho[0]*rdxCp2R6[1]+30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiLx[3]+((-151200.0*rdxCp2R8[1])-475200.0*rdxCp2Sq[0]*rdxCp2R6[1]-229200.0*rdxCp2R4[0]*rdxCp2R4[1]-24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+(45360.0*rdxCp2Sq[0]*rdxCp2R6[1]+134280.0*rdxCp2R4[0]*rdxCp2R4[1]+49920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiLx[2]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[2]+((-523772.1642088283*rdxCp2R8[1])-1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]-1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]-166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[0]*rdxCp2R8[1]+(51840.0*rdxCp2Sq[0]*phiUy[1]+50400.0*rdxCp2Sq[0]*phiLx[1]+29098.45356715714*rdxCp2Sq[0]*bcVals[1]+(411535.2718783651*phiUy[0]+43647.6803507357*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(51840.0*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*phiLx[1]+163505.596234502*rdxCp2R4[0]*bcVals[1]+(198493.0225473933*phiUy[0]+61314.59858793825*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(7200.0*rdxCp2R6[0]*phiUy[1]+24000.0*rdxCp2R6[0]*phiLx[1]+63739.46971853468*rdxCp2R6[0]*bcVals[1]+(20784.60969082652*phiUy[0]+20784.60969082652*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[2])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+(961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1]+1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0])*rho[2]+(5455.960043841962*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]+8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]+3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[3]+((-49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1])-49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiUy[2]+((-65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]-34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(79200.0*rdxCp2Sq[0]*rdxCp2R6[1]-172800.0*rdxCp2R4[0]*rdxCp2R4[1]-48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[2]+130943.0410522071*phiUy[1]*rdxCp2R8[1]+(291815.9200592043*rdxCp2Sq[0]*phiUy[1]-72746.13391789283*rdxCp2Sq[0]*phiLx[1]+84000.0*rdxCp2Sq[0]*bcVals[1]+(43200.0*phiUy[0]-63000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(78773.67072823252*rdxCp2R4[0]*phiUy[1]+70800.0*rdxCp2R4[0]*bcVals[1]+43200.0*phiUy[0]*rdxCp2R4[0])*rdxCp2R4[1]+(4156.921938165305*rdxCp2R6[0]*phiUy[1]+6928.203230275509*rdxCp2R6[0]*phiLx[1]+20800.0*rdxCp2R6[0]*bcVals[1]+(6000.0*phiUy[0]+6000.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[3])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxNeumannLyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(25.98076211353316*rdxCp2R4[1]+285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])-25.98076211353316*rdxCp2R4[0])*rho[1]-150.0*rho[0]*rdxCp2R4[1]-1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-150.0*rdxCp2R4[0]*rho[0])*omega*volFac+((1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(346.4101615137754*rdxCp2R6[1]+3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1]+1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(800.0*rdxCp2R6[1]+8880.0*rdxCp2Sq[0]*rdxCp2R4[1]+400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(300.0*phiC[0]-300.0*phiUy[0])*rdxCp2R6[1]+((-1039.230484541326*rdxCp2Sq[0]*phiUy[1])-692.8203230275509*rdxCp2Sq[0]*phiLx[1]-400.0*rdxCp2Sq[0]*bcVals[1]+((-3420.0*phiUy[0])-600.0*phiLx[0]+4020.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-207.8460969082653*rdxCp2R4[0]*phiUy[1])-3949.07584125704*rdxCp2R4[0]*phiLx[1]-8880.0*rdxCp2R4[0]*bcVals[1]+((-600.0*phiUy[0])-3420.0*phiLx[0]+4020.0*phiC[0])*rdxCp2R4[0])*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*phiLx[1]-800.0*rdxCp2R6[0]*bcVals[1]+(300.0*phiC[0]-300.0*phiLx[0])*rdxCp2R6[0])*omega-300.0*phiC[0]*rdxCp2R6[1]-4020.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]-4020.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]-300.0*phiC[0]*rdxCp2R6[0]))/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-450.0*rdxCp2R4[1])-1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]-90.0*rdxCp2R4[0])*rho[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]-259.8076211353315*rdxCp2R4[0]*rho[0])*omega*volFac+((2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[3]+(6000.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(1800.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[2]+(15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(1800.0*phiC[1]-1800.0*phiUy[1])*rdxCp2R6[1]+((-6120.0*rdxCp2Sq[0]*phiUy[1])+6000.0*rdxCp2Sq[0]*phiLx[1]+24120.0*rdxCp2Sq[0]*phiC[1]-6928.203230275509*rdxCp2Sq[0]*bcVals[1]+(5196.152422706631*phiLx[0]-5196.152422706631*phiUy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-720.0*rdxCp2R4[0]*phiUy[1])+1200.0*rdxCp2R4[0]*phiLx[1]+24120.0*rdxCp2R4[0]*phiC[1]-24248.71130596428*rdxCp2R4[0]*bcVals[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiUy[0])*rdxCp2R4[0])*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]*phiC[1]-2078.460969082652*rdxCp2R6[0]*bcVals[1])*omega-1800.0*phiC[1]*rdxCp2R6[1]-24120.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0]*phiC[1]))/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = (((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+(90.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+450.0*rdxCp2R4[0])*rho[2]-540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]-259.8076211353315*rho[0]*rdxCp2R4[1]-2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiLx[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R4[1]+6120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiLx[2]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[2]+(2078.460969082652*rdxCp2R6[1]+24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+((-1800.0*rdxCp2Sq[0]*phiUy[1])-1200.0*rdxCp2Sq[0]*phiLx[1]-692.8203230275509*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiUy[0]-1039.230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1800.0*rdxCp2R4[0]*phiUy[1]-6000.0*rdxCp2R4[0]*phiLx[1]-15934.86742963367*rdxCp2R4[0]*bcVals[1]+(5196.152422706631*phiUy[0]-5196.152422706631*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[2])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+(181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1]+129.9038105676658*rdxCp2R4[0])*rho[2]+((-129.9038105676658*rdxCp2R4[1])-181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]-900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[3]+(1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1]-1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1])*phiUy[2]+((-1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1])-5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(5200.0*rdxCp2Sq[0]*rdxCp2R4[1]+2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[2]+(5196.152422706631*rdxCp2Sq[0]*phiUy[1]+1732.050807568877*rdxCp2Sq[0]*phiLx[1]-2000.0*rdxCp2Sq[0]*bcVals[1]+(1500.0*phiLx[0]-1500.0*phiUy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(1039.230484541326*rdxCp2R4[0]*phiUy[1]-1732.050807568877*rdxCp2R4[0]*phiLx[1]-5200.0*rdxCp2R4[0]*bcVals[1]+(1500.0*phiUy[0]-1500.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[3])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxDirichletUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((177.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+((-727.4613391789284*rdxCp2R4[1])-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+((-4382.08854314926*rdxCp2Sq[0]*rdxCp2Sq[1])-727.4613391789284*rdxCp2R4[0])*rho[1]+21000.0*rho[0]*rdxCp2R4[1]+130280.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+21000.0*rdxCp2R4[0]*rho[0])*omega*volFac+(((-37440.0*rdxCp2Sq[0]*rdxCp2R4[1])-5040.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-5040.0*rdxCp2Sq[0]*rdxCp2R4[1])-37440.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(403200.0*rdxCp2R6[1]+2519520.0*rdxCp2Sq[0]*rdxCp2R4[1]+504000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(87295.36070147139*rdxCp2R6[1]+538944.9292831317*rdxCp2Sq[0]*rdxCp2R4[1]+72746.13391789283*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-4364.768035073569*rdxCp2Sq[0]*rdxCp2R4[1])-32423.99111768937*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(75600.0*phiLy[0]-176400.0*phiC[0])*rdxCp2R6[1]+((-32423.99111768937*rdxCp2Sq[0]*phiLy[1])+72746.13391789283*rdxCp2Sq[0]*phiLx[1]+504000.0*rdxCp2Sq[0]*bcVals[1]+(466740.0*phiLy[0]+63000.0*phiLx[0]-1285620.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-4364.768035073569*rdxCp2R4[0]*phiLy[1])+538944.9292831317*rdxCp2R4[0]*phiLx[1]+2519520.0*rdxCp2R4[0]*bcVals[1]+(63000.0*phiLy[0]+466740.0*phiLx[0]-1285620.0*phiC[0])*rdxCp2R4[0])*rdxCp2Sq[1]+87295.36070147139*rdxCp2R6[0]*phiLx[1]+403200.0*rdxCp2R6[0]*bcVals[1]+(75600.0*phiLx[0]-176400.0*phiC[0])*rdxCp2R6[0])*omega+176400.0*phiC[0]*rdxCp2R6[1]+1285620.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*phiC[0]*rdxCp2R6[0])/(176400.0*rdxCp2R6[1]+1285620.0*rdxCp2Sq[0]*rdxCp2R4[1]+1285620.0*rdxCp2R4[0]*rdxCp2Sq[1]+176400.0*rdxCp2R6[0]); 
  phiC[1] = -(1.0*(((727.4613391789284*rdxCp2R4[1]+192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+((-21000.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-3780.0*rdxCp2R4[0])*rho[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+7274.613391789284*rdxCp2R4[0]*rho[0])*omega*volFac+(((-174590.7214029428*rdxCp2R6[1])-191634.1013494206*rdxCp2Sq[0]*rdxCp2R4[1]-26188.60821044141*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-29098.45356715714*rdxCp2Sq[0]*rdxCp2R4[1])-19953.22530319346*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(806442.8560040692*rdxCp2Sq[0]*rdxCp2R4[1]+174590.7214029428*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(187200.0*rdxCp2Sq[0]*rdxCp2R4[1]+25200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-25200.0*rdxCp2Sq[0]*rdxCp2R4[1])-17280.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(352800.0*phiC[1]-151200.0*phiLy[1])*rdxCp2R6[1]+((-165960.0*rdxCp2Sq[0]*phiLy[1])+420000.0*rdxCp2Sq[0]*phiLx[1]+2571240.0*rdxCp2Sq[0]*phiC[1]-2909845.356715714*rdxCp2Sq[0]*bcVals[1]+(162119.9555884469*phiLy[0]+363730.6695894642*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-22680.0*rdxCp2R4[0]*phiLy[1])+682800.0*rdxCp2R4[0]*phiLx[1]+2571240.0*rdxCp2R4[0]*phiC[1]-2627174.664920473*rdxCp2R4[0]*bcVals[1]+(21823.84017536785*phiLy[0]+591322.1457040146*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]+100800.0*rdxCp2R6[0]*phiLx[1]+352800.0*rdxCp2R6[0]*phiC[1]-349181.4428058856*rdxCp2R6[0]*bcVals[1]+87295.36070147139*phiLx[0]*rdxCp2R6[0])*omega-352800.0*phiC[1]*rdxCp2R6[1]-2571240.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0]*phiC[1]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[2] = -(1.0*(((192.2576396401454*rdxCp2Sq[0]*rdxCp2Sq[1]+727.4613391789284*rdxCp2R4[0])*rho[3]+((-3780.0*rdxCp2R4[1])-26550.0*rdxCp2Sq[0]*rdxCp2Sq[1]-21000.0*rdxCp2R4[0])*rho[2]-1770.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+7274.613391789284*rho[0]*rdxCp2R4[1]+43820.88543149259*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-19953.22530319346*rdxCp2Sq[0]*rdxCp2R4[1])-29098.45356715714*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-26188.60821044141*rdxCp2Sq[0]*rdxCp2R4[1])-191634.1013494206*rdxCp2R4[0]*rdxCp2Sq[1]-174590.7214029428*rdxCp2R6[0])*phiLx[3]+((-349181.4428058856*rdxCp2R6[1])-2627174.664920473*rdxCp2Sq[0]*rdxCp2R4[1]-2909845.356715714*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(100800.0*rdxCp2R6[1]+682800.0*rdxCp2Sq[0]*rdxCp2R4[1]+420000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-22680.0*rdxCp2Sq[0]*rdxCp2R4[1])-165960.0*rdxCp2R4[0]*rdxCp2Sq[1]-151200.0*rdxCp2R6[0])*phiLx[2]+(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0])*phiC[2]+87295.36070147139*phiLy[0]*rdxCp2R6[1]+((-17280.0*rdxCp2Sq[0]*phiLy[1])+25200.0*rdxCp2Sq[0]*phiLx[1]+174590.7214029428*rdxCp2Sq[0]*bcVals[1]+(591322.1457040146*phiLy[0]+21823.84017536785*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-25200.0*rdxCp2R4[0]*phiLy[1])+187200.0*rdxCp2R4[0]*phiLx[1]+806442.8560040692*rdxCp2R4[0]*bcVals[1]+(363730.6695894642*phiLy[0]+162119.9555884469*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+((-352800.0*rdxCp2R6[1])-2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]-2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]-352800.0*rdxCp2R6[0])*phiC[2]))/(352800.0*rdxCp2R6[1]+2571240.0*rdxCp2Sq[0]*rdxCp2R4[1]+2571240.0*rdxCp2R4[0]*rdxCp2Sq[1]+352800.0*rdxCp2R6[0]); 
  phiC[3] = (((1260.0*rdxCp2R4[1]+7333.0*rdxCp2Sq[0]*rdxCp2Sq[1]+1260.0*rdxCp2R4[0])*rho[3]+((-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])-2424.871130596428*rdxCp2R4[0])*rho[2]+((-2424.871130596428*rdxCp2R4[1])-640.8587988004846*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+5900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-67200.0*rdxCp2R6[1])-297760.0*rdxCp2Sq[0]*rdxCp2R4[1]-50400.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-50400.0*rdxCp2Sq[0]*rdxCp2R4[1])-297760.0*rdxCp2R4[0]*rdxCp2Sq[1]-67200.0*rdxCp2R6[0])*phiLx[3]+((-235200.0*rdxCp2R6[1])-1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]-1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]-235200.0*rdxCp2R6[0])*phiC[3]+(52800.0*rdxCp2Sq[0]*rdxCp2R4[1]-336000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(33255.37550532244*rdxCp2Sq[0]*rdxCp2R4[1]+48497.42261192856*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-43647.6803507357*rdxCp2Sq[0]*rdxCp2R4[1])-257867.7242308544*rdxCp2R4[0]*rdxCp2Sq[1]-58196.90713431427*rdxCp2R6[0])*phiLx[2]-58196.90713431427*phiLy[1]*rdxCp2R6[1]+((-257867.7242308544*rdxCp2Sq[0]*phiLy[1])+48497.42261192856*rdxCp2Sq[0]*phiLx[1]-336000.0*rdxCp2Sq[0]*bcVals[1]+(28800.0*phiLy[0]+42000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-43647.6803507357*rdxCp2R4[0]*phiLy[1])+33255.37550532244*rdxCp2R4[0]*phiLx[1]+52800.0*rdxCp2R4[0]*bcVals[1]+(42000.0*phiLy[0]+28800.0*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0])*phiC[3])/(235200.0*rdxCp2R6[1]+1714160.0*rdxCp2Sq[0]*rdxCp2R4[1]+1714160.0*rdxCp2R4[0]*rdxCp2Sq[1]+235200.0*rdxCp2R6[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxDirichletUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((216.0*rdxCp2Sq[0]*rdxCp2R4[1]+531.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-207.8460969082653*rdxCp2R6[1])-6235.382907247957*rdxCp2Sq[0]*rdxCp2R4[1]-13146.26562944778*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1143.153532995459*rdxCp2Sq[0]*rdxCp2R4[1]+3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+1091.192008768392*rdxCp2R6[0])*rho[1]-1200.0*rho[0]*rdxCp2R6[1]-36540.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-91020.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-31500.0*rdxCp2R6[0]*rho[0])*omega*volFac+((4800.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+10080.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-1440.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-112320.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-6400.0*rdxCp2R8[1])-193440.0*rdxCp2Sq[0]*rdxCp2R6[1]-445120.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-2771.281292110204*rdxCp2R8[1])-85632.59192620528*rdxCp2Sq[0]*rdxCp2R6[1]-245119.8302871475*rdxCp2R4[0]*rdxCp2R4[1]-145492.2678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-1247.076581449591*rdxCp2Sq[0]*rdxCp2R6[1])-44894.75693218527*rdxCp2R4[0]*rdxCp2R4[1]-97271.97335306811*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(2400.0*phiC[0]-2400.0*phiLy[0])*rdxCp2R8[1]+(4156.921938165305*rdxCp2Sq[0]*phiLy[1]-4156.921938165305*rdxCp2Sq[0]*phiLx[1]-28800.0*rdxCp2Sq[0]*bcVals[1]+((-74160.0*phiLy[0])-3600.0*phiLx[0]+84960.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(12262.91971758765*rdxCp2R4[0]*phiLy[1]-149441.3436770427*rdxCp2R4[0]*phiLx[1]-718560.0*rdxCp2R4[0]*bcVals[1]+((-212280.0*phiLy[0])-129420.0*phiLx[0]+521340.0*phiC[0])*rdxCp2R4[0])*rdxCp2R4[1]+(8729.536070147138*rdxCp2R6[0]*phiLy[1]-376617.1275977765*rdxCp2R6[0]*phiLx[1]-1759680.0*rdxCp2R6[0]*bcVals[1]+((-126000.0*phiLy[0])-326160.0*phiLx[0]+892080.0*phiC[0])*rdxCp2R6[0])*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0]*phiLx[1]-604800.0*rdxCp2R8[0]*bcVals[1]+(264600.0*phiC[0]-113400.0*phiLx[0])*rdxCp2R8[0])*omega-2400.0*phiC[0]*rdxCp2R8[1]-84960.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*phiC[0]*rdxCp2R8[0]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[1] = (((207.8460969082653*rdxCp2R6[1]+1122.368923304632*rdxCp2Sq[0]*rdxCp2R4[1]+576.7729189204359*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+((-2160.0*rdxCp2Sq[0]*rdxCp2R4[1])-5310.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+(1200.0*rdxCp2R6[1]+9480.0*rdxCp2Sq[0]*rdxCp2R4[1]+18450.0*rdxCp2R4[0]*rdxCp2Sq[1]+5670.0*rdxCp2R6[0])*rho[1]-11431.53532995459*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-30657.29929396912*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-10911.92008768392*rdxCp2R6[0]*rho[0])*omega*volFac+((5542.562584220407*rdxCp2R8[1]+57642.65087589224*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+52377.21642088283*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-8313.84387633061*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-59859.67590958037*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-63739.46971853468*rdxCp2Sq[0]*rdxCp2R6[1])-163505.596234502*rdxCp2R4[0]*rdxCp2R4[1]-29098.45356715714*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-24000.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-50400.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-7200.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-51840.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(4800.0*phiLy[1]-4800.0*phiC[1])*rdxCp2R8[1]+(49920.0*rdxCp2Sq[0]*phiLy[1]-24000.0*rdxCp2Sq[0]*phiLx[1]-169920.0*rdxCp2Sq[0]*phiC[1]+166276.8775266122*rdxCp2Sq[0]*bcVals[1]+((-20784.60969082652*phiLy[0])-20784.60969082652*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+(134280.0*rdxCp2R4[0]*phiLy[1]-229200.0*rdxCp2R4[0]*phiLx[1]-1042680.0*rdxCp2R4[0]*phiC[1]+1039230.484541326*rdxCp2R4[0]*bcVals[1]+((-61314.59858793825*phiLy[0])-198493.0225473933*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+(45360.0*rdxCp2R6[0]*phiLy[1]-475200.0*rdxCp2R6[0]*phiLx[1]-1784160.0*rdxCp2R6[0]*phiC[1]+1820731.808916403*rdxCp2R6[0]*bcVals[1]+((-43647.6803507357*phiLy[0])-411535.2718783651*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1]-151200.0*rdxCp2R8[0]*phiLx[1]-529200.0*rdxCp2R8[0]*phiC[1]+523772.1642088283*rdxCp2R8[0]*bcVals[1]-130943.0410522071*phiLx[0]*rdxCp2R8[0])*omega+4800.0*phiC[1]*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]*phiC[1])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 
  phiC[2] = -(1.0*(((72.74613391789283*rdxCp2Sq[0]*rdxCp2R4[1]+306.5729929396912*rdxCp2R4[0]*rdxCp2Sq[1]+545.5960043841961*rdxCp2R6[0])*rho[3]+((-120.0*rdxCp2R6[1])-3870.0*rdxCp2Sq[0]*rdxCp2R4[1]-15150.0*rdxCp2R4[0]*rdxCp2Sq[1]-15750.0*rdxCp2R6[0])*rho[2]+(360.0*rdxCp2Sq[0]*rdxCp2R4[1]+885.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-346.4101615137754*rho[0]*rdxCp2R6[1]-10392.30484541326*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-21910.4427157463*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((1385.640646055102*rdxCp2Sq[0]*rdxCp2R6[1]-14549.22678357857*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-831.384387633061*rdxCp2Sq[0]*rdxCp2R6[1])-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-117225.1986562616*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[3]+((-2771.281292110204*rdxCp2R8[1])-87295.36070147139*rdxCp2Sq[0]*rdxCp2R6[1]-291677.3559945989*rdxCp2R4[0]*rdxCp2R4[1]-242487.1130596428*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(3600.0*rdxCp2Sq[0]*rdxCp2R6[1]+100800.0*rdxCp2R4[0]*rdxCp2R4[1]+210000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-720.0*rdxCp2Sq[0]*rdxCp2R6[1])-25740.0*rdxCp2R4[0]*rdxCp2R4[1]-101520.0*rdxCp2R6[0]*rdxCp2Sq[1]-113400.0*rdxCp2R8[0])*phiLx[2]+(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0])*phiC[2]+(1200.0*rdxCp2Sq[0]*phiLy[1]-1200.0*rdxCp2Sq[0]*phiLx[1]-8313.84387633061*rdxCp2Sq[0]*bcVals[1]+(3117.691453623978*phiLy[0]-1039.230484541326*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-43200.0*rdxCp2R4[0]*phiLx[1])-199532.2530319346*rdxCp2R4[0]*bcVals[1]+(87295.36070147139*phiLy[0]-37412.29744348773*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-12600.0*rdxCp2R6[0]*phiLy[1])-93600.0*rdxCp2R6[0]*phiLx[1]-403221.4280020346*rdxCp2R6[0]*bcVals[1]+(181865.3347947321*phiLy[0]-81059.97779422344*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+((-2400.0*rdxCp2R8[1])-84960.0*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*rdxCp2R4[1]-892080.0*rdxCp2R6[0]*rdxCp2Sq[1]-264600.0*rdxCp2R8[0])*phiC[2]))/(2400.0*rdxCp2R8[1]+84960.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+892080.0*rdxCp2R6[0]*rdxCp2Sq[1]+264600.0*rdxCp2R8[0]); 
  phiC[3] = (((120.0*rdxCp2R6[1]+2148.0*rdxCp2Sq[0]*rdxCp2R4[1]+7893.0*rdxCp2R4[0]*rdxCp2Sq[1]+2835.0*rdxCp2R6[0])*rho[3]+((-727.4613391789284*rdxCp2Sq[0]*rdxCp2R4[1])-3065.729929396912*rdxCp2R4[0]*rdxCp2Sq[1]-5455.960043841962*rdxCp2R6[0])*rho[2]+(346.4101615137754*rdxCp2R6[1]+1870.614872174387*rdxCp2Sq[0]*rdxCp2R4[1]+961.2881982007268*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-3600.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-8850.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-40000.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-75600.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-4800.0*rdxCp2Sq[0]*rdxCp2R6[1])-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-336960.0*rdxCp2R6[0]*rdxCp2Sq[1]-151200.0*rdxCp2R8[0])*phiLx[3]+((-4800.0*rdxCp2R8[1])-169920.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]-529200.0*rdxCp2R8[0])*phiC[3]+((-20800.0*rdxCp2Sq[0]*rdxCp2R6[1])-70800.0*rdxCp2R4[0]*rdxCp2R4[1]-84000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+(72746.13391789283*rdxCp2R6[0]*rdxCp2Sq[1]-6928.203230275509*rdxCp2Sq[0]*rdxCp2R6[1])*phiLy[2]+((-4156.921938165305*rdxCp2Sq[0]*rdxCp2R6[1])-78773.67072823252*rdxCp2R4[0]*rdxCp2R4[1]-291815.9200592043*rdxCp2R6[0]*rdxCp2Sq[1]-130943.0410522071*rdxCp2R8[0])*phiLx[2]+((-34641.01615137755*rdxCp2Sq[0]*phiLy[1])-6928.203230275509*rdxCp2Sq[0]*phiLx[1]+48000.0*rdxCp2Sq[0]*bcVals[1]+((-6000.0*phiLy[0])-6000.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-174590.7214029428*rdxCp2R4[0]*phiLy[1])-49883.06325798365*rdxCp2R4[0]*phiLx[1]+172800.0*rdxCp2R4[0]*bcVals[1]-43200.0*phiLx[0]*rdxCp2R4[0])*rdxCp2R4[1]+((-65471.52052610354*rdxCp2R6[0]*phiLy[1])-49883.06325798365*rdxCp2R6[0]*phiLx[1]-79200.0*rdxCp2R6[0]*bcVals[1]+(63000.0*phiLy[0]-43200.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0])*phiC[3])/(4800.0*rdxCp2R8[1]+169920.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+1784160.0*rdxCp2R6[0]*rdxCp2Sq[1]+529200.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxNeumannUyDirichlet_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = -(1.0*(((531.0*rdxCp2Sq[0]*rdxCp2R4[1]+216.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(1091.192008768392*rdxCp2R6[1]+3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+1143.153532995459*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-13146.26562944778*rdxCp2Sq[0]*rdxCp2R4[1])-6235.382907247957*rdxCp2R4[0]*rdxCp2Sq[1]-207.8460969082653*rdxCp2R6[0])*rho[1]-31500.0*rho[0]*rdxCp2R6[1]-91020.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-36540.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-1200.0*rdxCp2R6[0]*rho[0])*omega*volFac+(((-112320.0*rdxCp2Sq[0]*rdxCp2R6[1])-51840.0*rdxCp2R4[0]*rdxCp2R4[1]-1440.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(10080.0*rdxCp2Sq[0]*rdxCp2R6[1]+14160.0*rdxCp2R4[0]*rdxCp2R4[1]+4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-604800.0*rdxCp2R8[1])-1759680.0*rdxCp2Sq[0]*rdxCp2R6[1]-718560.0*rdxCp2R4[0]*rdxCp2R4[1]-28800.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-130943.0410522071*rdxCp2R8[1])-376617.1275977765*rdxCp2Sq[0]*rdxCp2R6[1]-149441.3436770427*rdxCp2R4[0]*rdxCp2R4[1]-4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(8729.536070147138*rdxCp2Sq[0]*rdxCp2R6[1]+12262.91971758765*rdxCp2R4[0]*rdxCp2R4[1]+4156.921938165305*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]+(264600.0*phiC[0]-113400.0*phiLy[0])*rdxCp2R8[1]+((-97271.97335306811*rdxCp2Sq[0]*phiLy[1])-145492.2678357857*rdxCp2Sq[0]*phiLx[1]-84000.0*rdxCp2Sq[0]*bcVals[1]+((-326160.0*phiLy[0])-126000.0*phiLx[0]+892080.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-44894.75693218527*rdxCp2R4[0]*phiLy[1])-245119.8302871475*rdxCp2R4[0]*phiLx[1]-445120.0*rdxCp2R4[0]*bcVals[1]+((-129420.0*phiLy[0])-212280.0*phiLx[0]+521340.0*phiC[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-1247.076581449591*rdxCp2R6[0]*phiLy[1])-85632.59192620528*rdxCp2R6[0]*phiLx[1]-193440.0*rdxCp2R6[0]*bcVals[1]+((-3600.0*phiLy[0])-74160.0*phiLx[0]+84960.0*phiC[0])*rdxCp2R6[0])*rdxCp2Sq[1]-2771.281292110204*rdxCp2R8[0]*phiLx[1]-6400.0*rdxCp2R8[0]*bcVals[1]+(2400.0*phiC[0]-2400.0*phiLx[0])*rdxCp2R8[0])*omega-264600.0*phiC[0]*rdxCp2R8[1]-892080.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R6[1]-521340.0*phiC[0]*rdxCp2R4[0]*rdxCp2R4[1]-84960.0*phiC[0]*rdxCp2R6[0]*rdxCp2Sq[1]-2400.0*phiC[0]*rdxCp2R8[0]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[1] = -(1.0*(((545.5960043841961*rdxCp2R6[1]+306.5729929396912*rdxCp2Sq[0]*rdxCp2R4[1]+72.74613391789283*rdxCp2R4[0]*rdxCp2Sq[1])*rho[3]+(885.0*rdxCp2Sq[0]*rdxCp2R4[1]+360.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[2]+((-15750.0*rdxCp2R6[1])-15150.0*rdxCp2Sq[0]*rdxCp2R4[1]-3870.0*rdxCp2R4[0]*rdxCp2Sq[1]-120.0*rdxCp2R6[0])*rho[1]-21910.4427157463*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-10392.30484541326*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1]-346.4101615137754*rdxCp2R6[0]*rho[0])*omega*volFac+(((-130943.0410522071*rdxCp2R8[1])-117225.1986562616*rdxCp2Sq[0]*rdxCp2R6[1]-29721.99185788193*rdxCp2R4[0]*rdxCp2R4[1]-831.384387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(1385.640646055102*rdxCp2R6[0]*rdxCp2Sq[1]-14549.22678357857*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[3]+((-403221.4280020346*rdxCp2Sq[0]*rdxCp2R6[1])-199532.2530319346*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-93600.0*rdxCp2Sq[0]*rdxCp2R6[1])-43200.0*rdxCp2R4[0]*rdxCp2R4[1]-1200.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(1200.0*rdxCp2R6[0]*rdxCp2Sq[1]-12600.0*rdxCp2Sq[0]*rdxCp2R6[1])*phiLx[2]+(264600.0*phiC[1]-113400.0*phiLy[1])*rdxCp2R8[1]+((-101520.0*rdxCp2Sq[0]*phiLy[1])+210000.0*rdxCp2Sq[0]*phiLx[1]+892080.0*rdxCp2Sq[0]*phiC[1]-242487.1130596428*rdxCp2Sq[0]*bcVals[1]+(181865.3347947321*phiLx[0]-81059.97779422344*phiLy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-25740.0*rdxCp2R4[0]*phiLy[1])+100800.0*rdxCp2R4[0]*phiLx[1]+521340.0*rdxCp2R4[0]*phiC[1]-291677.3559945989*rdxCp2R4[0]*bcVals[1]+(87295.36070147139*phiLx[0]-37412.29744348773*phiLy[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-720.0*rdxCp2R6[0]*phiLy[1])+3600.0*rdxCp2R6[0]*phiLx[1]+84960.0*rdxCp2R6[0]*phiC[1]-87295.36070147139*rdxCp2R6[0]*bcVals[1]+(3117.691453623978*phiLx[0]-1039.230484541326*phiLy[0])*rdxCp2R6[0])*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]*phiC[1]-2771.281292110204*rdxCp2R8[0]*bcVals[1])*omega-264600.0*phiC[1]*rdxCp2R8[1]-892080.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R6[1]-521340.0*rdxCp2R4[0]*phiC[1]*rdxCp2R4[1]-84960.0*rdxCp2R6[0]*phiC[1]*rdxCp2Sq[1]-2400.0*rdxCp2R8[0]*phiC[1]))/(264600.0*rdxCp2R8[1]+892080.0*rdxCp2Sq[0]*rdxCp2R6[1]+521340.0*rdxCp2R4[0]*rdxCp2R4[1]+84960.0*rdxCp2R6[0]*rdxCp2Sq[1]+2400.0*rdxCp2R8[0]); 
  phiC[2] = (((576.7729189204359*rdxCp2Sq[0]*rdxCp2R4[1]+1122.368923304632*rdxCp2R4[0]*rdxCp2Sq[1]+207.8460969082653*rdxCp2R6[0])*rho[3]+(5670.0*rdxCp2R6[1]+18450.0*rdxCp2Sq[0]*rdxCp2R4[1]+9480.0*rdxCp2R4[0]*rdxCp2Sq[1]+1200.0*rdxCp2R6[0])*rho[2]+((-5310.0*rdxCp2Sq[0]*rdxCp2R4[1])-2160.0*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-10911.92008768392*rho[0]*rdxCp2R6[1]-30657.29929396912*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-11431.53532995459*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-59859.67590958037*rdxCp2Sq[0]*rdxCp2R6[1])-59859.67590958037*rdxCp2R4[0]*rdxCp2R4[1]-8313.84387633061*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+(52377.21642088283*rdxCp2Sq[0]*rdxCp2R6[1]+155053.1882935659*rdxCp2R4[0]*rdxCp2R4[1]+57642.65087589224*rdxCp2R6[0]*rdxCp2Sq[1]+5542.562584220407*rdxCp2R8[0])*phiLx[3]+(523772.1642088283*rdxCp2R8[1]+1820731.808916403*rdxCp2Sq[0]*rdxCp2R6[1]+1039230.484541326*rdxCp2R4[0]*rdxCp2R4[1]+166276.8775266122*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-151200.0*rdxCp2R8[1])-475200.0*rdxCp2Sq[0]*rdxCp2R6[1]-229200.0*rdxCp2R4[0]*rdxCp2R4[1]-24000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+(45360.0*rdxCp2Sq[0]*rdxCp2R6[1]+134280.0*rdxCp2R4[0]*rdxCp2R4[1]+49920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiLx[2]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[2]-130943.0410522071*phiLy[0]*rdxCp2R8[1]+((-51840.0*rdxCp2Sq[0]*phiLy[1])-50400.0*rdxCp2Sq[0]*phiLx[1]-29098.45356715714*rdxCp2Sq[0]*bcVals[1]+((-411535.2718783651*phiLy[0])-43647.6803507357*phiLx[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-51840.0*rdxCp2R4[0]*phiLy[1])-70800.0*rdxCp2R4[0]*phiLx[1]-163505.596234502*rdxCp2R4[0]*bcVals[1]+((-198493.0225473933*phiLy[0])-61314.59858793825*phiLx[0])*rdxCp2R4[0])*rdxCp2R4[1]+((-7200.0*rdxCp2R6[0]*phiLy[1])-24000.0*rdxCp2R6[0]*phiLx[1]-63739.46971853468*rdxCp2R6[0]*bcVals[1]+((-20784.60969082652*phiLy[0])-20784.60969082652*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[2])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 
  phiC[3] = (((2835.0*rdxCp2R6[1]+7893.0*rdxCp2Sq[0]*rdxCp2R4[1]+2148.0*rdxCp2R4[0]*rdxCp2Sq[1]+120.0*rdxCp2R6[0])*rho[3]+(961.2881982007268*rdxCp2Sq[0]*rdxCp2R4[1]+1870.614872174387*rdxCp2R4[0]*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0])*rho[2]+((-5455.960043841962*rdxCp2R6[1])-3065.729929396912*rdxCp2Sq[0]*rdxCp2R4[1]-727.4613391789284*rdxCp2R4[0]*rdxCp2Sq[1])*rho[1]-8850.0*rdxCp2Sq[0]*rho[0]*rdxCp2R4[1]-3600.0*rdxCp2R4[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-151200.0*rdxCp2R8[1])-336960.0*rdxCp2Sq[0]*rdxCp2R6[1]-90960.0*rdxCp2R4[0]*rdxCp2R4[1]-4800.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[3]+((-75600.0*rdxCp2Sq[0]*rdxCp2R6[1])-201600.0*rdxCp2R4[0]*rdxCp2R4[1]-40000.0*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[3]+((-529200.0*rdxCp2R8[1])-1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]-1042680.0*rdxCp2R4[0]*rdxCp2R4[1]-169920.0*rdxCp2R6[0]*rdxCp2Sq[1]-4800.0*rdxCp2R8[0])*phiC[3]+((-79200.0*rdxCp2Sq[0]*rdxCp2R6[1])+172800.0*rdxCp2R4[0]*rdxCp2R4[1]+48000.0*rdxCp2R6[0]*rdxCp2Sq[1])*bcVals[3]+((-49883.06325798365*rdxCp2Sq[0]*rdxCp2R6[1])-49883.06325798365*rdxCp2R4[0]*rdxCp2R4[1]-6928.203230275509*rdxCp2R6[0]*rdxCp2Sq[1])*phiLy[2]+((-65471.52052610354*rdxCp2Sq[0]*rdxCp2R6[1])-174590.7214029428*rdxCp2R4[0]*rdxCp2R4[1]-34641.01615137755*rdxCp2R6[0]*rdxCp2Sq[1])*phiLx[2]-130943.0410522071*phiLy[1]*rdxCp2R8[1]+((-291815.9200592043*rdxCp2Sq[0]*phiLy[1])+72746.13391789283*rdxCp2Sq[0]*phiLx[1]-84000.0*rdxCp2Sq[0]*bcVals[1]+(63000.0*phiLx[0]-43200.0*phiLy[0])*rdxCp2Sq[0])*rdxCp2R6[1]+((-78773.67072823252*rdxCp2R4[0]*phiLy[1])-70800.0*rdxCp2R4[0]*bcVals[1]-43200.0*phiLy[0]*rdxCp2R4[0])*rdxCp2R4[1]+((-4156.921938165305*rdxCp2R6[0]*phiLy[1])-6928.203230275509*rdxCp2R6[0]*phiLx[1]-20800.0*rdxCp2R6[0]*bcVals[1]+((-6000.0*phiLy[0])-6000.0*phiLx[0])*rdxCp2R6[0])*rdxCp2Sq[1])*omega+(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0])*phiC[3])/(529200.0*rdxCp2R8[1]+1784160.0*rdxCp2Sq[0]*rdxCp2R6[1]+1042680.0*rdxCp2R4[0]*rdxCp2R4[1]+169920.0*rdxCp2R6[0]*rdxCp2Sq[1]+4800.0*rdxCp2R8[0]); 

}

void MGpoissonDampedGaussSeidel2xSer_UxNeumannUyNeumann_P1(const double omega, double **dx, const double *bcVals, const double *rho, double **phi) 
{ 
  // omega:  relaxation parameter.
  // dx:     cell lengths of cells pointed to by the stencil.
  // bcVals: values to impose as BCs.
  // rho:    right-side source in the current cell.
  // phi:    iterate cells pointed to by the stencil.

  double *dxC  = dx[0]; 
  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  phiC[0] = ((54.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[3]+(25.98076211353316*rdxCp2R4[1]+285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[2]+(285.7883832488647*rdxCp2Sq[0]*rdxCp2Sq[1]+25.98076211353316*rdxCp2R4[0])*rho[1]+150.0*rho[0]*rdxCp2R4[1]+1680.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+150.0*rdxCp2R4[0]*rho[0])*omega*volFac+((1200.0*rdxCp2Sq[0]*rdxCp2R4[1]+240.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(240.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+(800.0*rdxCp2R6[1]+8880.0*rdxCp2Sq[0]*rdxCp2R4[1]+400.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(346.4101615137754*rdxCp2R6[1]+3949.07584125704*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(207.8460969082653*rdxCp2Sq[0]*rdxCp2R4[1]+1039.230484541326*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+(300.0*phiLy[0]-300.0*phiC[0])*rdxCp2R6[1]+(1039.230484541326*rdxCp2Sq[0]*phiLy[1]+692.8203230275509*rdxCp2Sq[0]*phiLx[1]+400.0*rdxCp2Sq[0]*bcVals[1]+(3420.0*phiLy[0]+600.0*phiLx[0]-4020.0*phiC[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(207.8460969082653*rdxCp2R4[0]*phiLy[1]+3949.07584125704*rdxCp2R4[0]*phiLx[1]+8880.0*rdxCp2R4[0]*bcVals[1]+(600.0*phiLy[0]+3420.0*phiLx[0]-4020.0*phiC[0])*rdxCp2R4[0])*rdxCp2Sq[1]+346.4101615137754*rdxCp2R6[0]*phiLx[1]+800.0*rdxCp2R6[0]*bcVals[1]+(300.0*phiLx[0]-300.0*phiC[0])*rdxCp2R6[0])*omega+300.0*phiC[0]*rdxCp2R6[1]+4020.0*phiC[0]*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*phiC[0]*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*phiC[0]*rdxCp2R6[0])/(300.0*rdxCp2R6[1]+4020.0*rdxCp2Sq[0]*rdxCp2R4[1]+4020.0*rdxCp2R4[0]*rdxCp2Sq[1]+300.0*rdxCp2R6[0]); 
  phiC[1] = (((77.94228634059945*rdxCp2R4[1]+109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[3]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[2]+(450.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+90.0*rdxCp2R4[0])*rho[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1]+259.8076211353315*rdxCp2R4[0]*rho[0])*omega*volFac+((2078.460969082652*rdxCp2R6[1]+7066.767294881019*rdxCp2Sq[0]*rdxCp2R4[1]+831.384387633061*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1]-2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[3]+(15934.86742963367*rdxCp2Sq[0]*rdxCp2R4[1]+692.8203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(6000.0*rdxCp2Sq[0]*rdxCp2R4[1]+1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(1800.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2Sq[0]*rdxCp2R4[1])*phiLx[2]+(1800.0*phiLy[1]-1800.0*phiC[1])*rdxCp2R6[1]+(6120.0*rdxCp2Sq[0]*phiLy[1]-6000.0*rdxCp2Sq[0]*phiLx[1]-24120.0*rdxCp2Sq[0]*phiC[1]+6928.203230275509*rdxCp2Sq[0]*bcVals[1]+(5196.152422706631*phiLy[0]-5196.152422706631*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+(720.0*rdxCp2R4[0]*phiLy[1]-1200.0*rdxCp2R4[0]*phiLx[1]-24120.0*rdxCp2R4[0]*phiC[1]+24248.71130596428*rdxCp2R4[0]*bcVals[1]+(1039.230484541326*phiLy[0]-1039.230484541326*phiLx[0])*rdxCp2R4[0])*rdxCp2Sq[1]-1800.0*rdxCp2R6[0]*phiC[1]+2078.460969082652*rdxCp2R6[0]*bcVals[1])*omega+1800.0*phiC[1]*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*phiC[1]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*phiC[1]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]*phiC[1])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[2] = (((109.1192008768392*rdxCp2Sq[0]*rdxCp2Sq[1]+77.94228634059945*rdxCp2R4[0])*rho[3]+(90.0*rdxCp2R4[1]+1080.0*rdxCp2Sq[0]*rdxCp2Sq[1]+450.0*rdxCp2R4[0])*rho[2]+540.0*rdxCp2Sq[0]*rdxCp2Sq[1]*rho[1]+259.8076211353315*rho[0]*rdxCp2R4[1]+2857.883832488647*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+((2078.460969082652*rdxCp2Sq[0]*rdxCp2R4[1]-2078.460969082652*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+(831.384387633061*rdxCp2Sq[0]*rdxCp2R4[1]+7066.767294881019*rdxCp2R4[0]*rdxCp2Sq[1]+2078.460969082652*rdxCp2R6[0])*phiLx[3]+(2078.460969082652*rdxCp2R6[1]+24248.71130596428*rdxCp2Sq[0]*rdxCp2R4[1]+6928.203230275509*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+(720.0*rdxCp2Sq[0]*rdxCp2R4[1]+6120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiLx[2]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[2]+(1800.0*rdxCp2Sq[0]*phiLy[1]+1200.0*rdxCp2Sq[0]*phiLx[1]+692.8203230275509*rdxCp2Sq[0]*bcVals[1]+(1039.230484541326*phiLx[0]-1039.230484541326*phiLy[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1800.0*rdxCp2R4[0]*phiLy[1])+6000.0*rdxCp2R4[0]*phiLx[1]+15934.86742963367*rdxCp2R4[0]*bcVals[1]+(5196.152422706631*phiLx[0]-5196.152422706631*phiLy[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[2])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 
  phiC[3] = (((45.0*rdxCp2R4[1]+288.0*rdxCp2Sq[0]*rdxCp2Sq[1]+45.0*rdxCp2R4[0])*rho[3]+(181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1]+129.9038105676658*rdxCp2R4[0])*rho[2]+(129.9038105676658*rdxCp2R4[1]+181.8653347947321*rdxCp2Sq[0]*rdxCp2Sq[1])*rho[1]+900.0*rdxCp2Sq[0]*rho[0]*rdxCp2Sq[1])*omega*volFac+(((-6000.0*rdxCp2Sq[0]*rdxCp2R4[1])-1200.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[3]+((-1200.0*rdxCp2Sq[0]*rdxCp2R4[1])-6000.0*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[3]+((-1800.0*rdxCp2R6[1])-24120.0*rdxCp2Sq[0]*rdxCp2R4[1]-24120.0*rdxCp2R4[0]*rdxCp2Sq[1]-1800.0*rdxCp2R6[0])*phiC[3]+(5200.0*rdxCp2Sq[0]*rdxCp2R4[1]+2000.0*rdxCp2R4[0]*rdxCp2Sq[1])*bcVals[3]+(1732.050807568877*rdxCp2Sq[0]*rdxCp2R4[1]-1732.050807568877*rdxCp2R4[0]*rdxCp2Sq[1])*phiLy[2]+((-1039.230484541326*rdxCp2Sq[0]*rdxCp2R4[1])-5196.152422706631*rdxCp2R4[0]*rdxCp2Sq[1])*phiLx[2]+((-5196.152422706631*rdxCp2Sq[0]*phiLy[1])-1732.050807568877*rdxCp2Sq[0]*phiLx[1]+2000.0*rdxCp2Sq[0]*bcVals[1]+(1500.0*phiLy[0]-1500.0*phiLx[0])*rdxCp2Sq[0])*rdxCp2R4[1]+((-1039.230484541326*rdxCp2R4[0]*phiLy[1])+1732.050807568877*rdxCp2R4[0]*phiLx[1]+5200.0*rdxCp2R4[0]*bcVals[1]+(1500.0*phiLx[0]-1500.0*phiLy[0])*rdxCp2R4[0])*rdxCp2Sq[1])*omega+(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0])*phiC[3])/(1800.0*rdxCp2R6[1]+24120.0*rdxCp2Sq[0]*rdxCp2R4[1]+24120.0*rdxCp2R4[0]*rdxCp2Sq[1]+1800.0*rdxCp2R6[0]); 

}

void MGpoissonResidue2xSer_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 
  double *dxUx = dx[1]; 
  double *dxLx = dx[2]; 
  double *dxUy = dx[3]; 
  double *dxLy = dx[4]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxLx[2]; 
  double rdxUx[2]; 
  double rdxLxSq[2]; 
  double rdxUxSq[2]; 
  double rdxLxCu[2]; 
  double rdxUxCu[2]; 
  double rdxLxR4[2]; 
  double rdxUxR4[2]; 
  double rdxLy[2]; 
  double rdxUy[2]; 
  double rdxLySq[2]; 
  double rdxUySq[2]; 
  double rdxLyCu[2]; 
  double rdxUyCu[2]; 
  double rdxLyR4[2]; 
  double rdxUyR4[2]; 
  rdxCp2[0]  = volFac*4.0/(dxC[0]*dxC[0]); 
  rdxLx[0]   = 1.0/dxLx[0]; 
  rdxUx[0]   = 1.0/dxUx[0]; 
  rdxLxSq[0] = rdxLx[0]*rdxLx[0]; 
  rdxUxSq[0] = rdxUx[0]*rdxUx[0]; 
  rdxLxCu[0] = rdxLxSq[0]*rdxLx[0]; 
  rdxUxCu[0] = rdxUxSq[0]*rdxUx[0]; 
  rdxLxR4[0] = rdxLxCu[0]*rdxLx[0]; 
  rdxUxR4[0] = rdxUxCu[0]*rdxUx[0]; 
  rdxLx[1]   = 1.0/dxLx[1]; 
  rdxUx[1]   = 1.0/dxUx[1]; 
  rdxLxSq[1] = rdxLx[1]*rdxLx[1]; 
  rdxUxSq[1] = rdxUx[1]*rdxUx[1]; 
  rdxLxCu[1] = rdxLxSq[1]*rdxLx[1]; 
  rdxUxCu[1] = rdxUxSq[1]*rdxUx[1]; 
  rdxLxR4[1] = rdxLxCu[1]*rdxLx[1]; 
  rdxUxR4[1] = rdxUxCu[1]*rdxUx[1]; 
  rdxCp2[1]  = volFac*4.0/(dxC[1]*dxC[1]); 
  rdxLy[0]   = 1.0/dxLy[0]; 
  rdxUy[0]   = 1.0/dxUy[0]; 
  rdxLySq[0] = rdxLy[0]*rdxLy[0]; 
  rdxUySq[0] = rdxUy[0]*rdxUy[0]; 
  rdxLyCu[0] = rdxLySq[0]*rdxLy[0]; 
  rdxUyCu[0] = rdxUySq[0]*rdxUy[0]; 
  rdxLyR4[0] = rdxLyCu[0]*rdxLy[0]; 
  rdxUyR4[0] = rdxUyCu[0]*rdxUy[0]; 
  rdxLy[1]   = 1.0/dxLy[1]; 
  rdxUy[1]   = 1.0/dxUy[1]; 
  rdxLySq[1] = rdxLy[1]*rdxLy[1]; 
  rdxUySq[1] = rdxUy[1]*rdxUy[1]; 
  rdxLyCu[1] = rdxLySq[1]*rdxLy[1]; 
  rdxUyCu[1] = rdxUySq[1]*rdxUy[1]; 
  rdxLyR4[1] = rdxLyCu[1]*rdxLy[1]; 
  rdxUyR4[1] = rdxUyCu[1]*rdxUy[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.0625*(8.0*rho[0]*volFac-8.660254037844386*rdxUy[1]*phiUy[2]+8.660254037844386*rdxLy[1]*phiLy[2]+(8.660254037844386*rdxLy[1]-8.660254037844386*rdxUy[1])*phiC[2]+(9.0*phiUy[0]-9.0*phiC[0])*rdxUy[1]+(9.0*phiLy[0]-9.0*phiC[0])*rdxLy[1]-8.660254037844386*rdxUx[0]*phiUx[1]+8.660254037844386*rdxLx[0]*phiLx[1]+(8.660254037844386*rdxLx[0]-8.660254037844386*rdxUx[0])*phiC[1]+(9.0*phiUx[0]-9.0*phiC[0])*rdxUx[0]+(9.0*phiLx[0]-9.0*phiC[0])*rdxLx[0]); 
  resOut[1] = 0.0625*(8.0*rho[1]*volFac-17.32050807568877*rdxUy[1]*phiUy[3]+17.32050807568877*rdxLy[1]*phiLy[3]+(17.32050807568877*rdxLy[1]-17.32050807568877*rdxUy[1])*phiC[3]+(18.0*phiUy[1]-18.0*phiC[1])*rdxUy[1]+(18.0*phiLy[1]-18.0*phiC[1])*rdxLy[1]-7.0*rdxUx[0]*phiUx[1]-7.0*rdxLx[0]*phiLx[1]+((-23.0*rdxUx[0])-23.0*rdxLx[0])*phiC[1]+(8.660254037844386*phiUx[0]-22.5166604983954*phiC[0])*rdxUx[0]+(22.5166604983954*phiC[0]-8.660254037844386*phiLx[0])*rdxLx[0]); 
  resOut[2] = 0.0625*(8.0*rho[2]*volFac-17.32050807568877*rdxUx[0]*phiUx[3]+17.32050807568877*rdxLx[0]*phiLx[3]+(17.32050807568877*rdxLx[0]-17.32050807568877*rdxUx[0])*phiC[3]-7.0*rdxUy[1]*phiUy[2]+18.0*rdxUx[0]*phiUx[2]-7.0*rdxLy[1]*phiLy[2]+18.0*rdxLx[0]*phiLx[2]+((-23.0*rdxUy[1])-23.0*rdxLy[1]-18.0*rdxUx[0]-18.0*rdxLx[0])*phiC[2]+(8.660254037844386*phiUy[0]-22.5166604983954*phiC[0])*rdxUy[1]+(22.5166604983954*phiC[0]-8.660254037844386*phiLy[0])*rdxLy[1]); 
  resOut[3] = 0.125*(4.0*rho[3]*volFac-7.0*rdxUy[1]*phiUy[3]-7.0*rdxUx[0]*phiUx[3]-7.0*rdxLy[1]*phiLy[3]-7.0*rdxLx[0]*phiLx[3]+((-23.0*rdxUy[1])-23.0*rdxLy[1]-23.0*rdxUx[0]-23.0*rdxLx[0])*phiC[3]+8.660254037844386*rdxUx[0]*phiUx[2]-8.660254037844386*rdxLx[0]*phiLx[2]+(22.5166604983954*rdxLx[0]-22.5166604983954*rdxUx[0])*phiC[2]+(8.660254037844386*phiUy[1]-22.5166604983954*phiC[1])*rdxUy[1]+(22.5166604983954*phiC[1]-8.660254037844386*phiLy[1])*rdxLy[1]); 

}

void MGpoissonResidue2xSer_LxDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac-3.464101615137754*rdxCp2[1]*phiUy[2]+3.464101615137754*rdxCp2[1]*phiLy[2]+(3.0*phiUy[0]+3.0*phiLy[0]-6.0*phiC[0])*rdxCp2[1]-3.464101615137754*rdxCp2[0]*phiUx[1]+3.464101615137754*rdxCp2[0]*phiC[1]+(3.0*phiUx[0]-9.0*phiC[0]+24.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac-6.928203230275509*rdxCp2[1]*phiUy[3]+6.928203230275509*rdxCp2[1]*phiLy[3]+(6.0*phiUy[1]+6.0*phiLy[1]-12.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiUx[1]-100.0*rdxCp2[0]*phiC[1]+(17.32050807568877*phiUx[0]+17.32050807568877*phiC[0]-138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac-6.928203230275509*rdxCp2[0]*phiUx[3]+6.928203230275509*rdxCp2[0]*phiC[3]-20.0*rdxCp2[1]*phiUy[2]+6.0*rdxCp2[0]*phiUx[2]-20.0*rdxCp2[1]*phiLy[2]+((-80.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]+(17.32050807568877*phiUy[0]-17.32050807568877*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiUy[3]-40.0*rdxCp2[0]*phiUx[3]-40.0*rdxCp2[1]*phiLy[3]+((-160.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]+34.64101615137754*rdxCp2[0]*phiUx[2]+34.64101615137754*rdxCp2[0]*phiC[2]+(34.64101615137754*phiUy[1]-34.64101615137754*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-10.39230484541326*rdxCp2[1]*phiUy[2]+10.39230484541326*rdxCp2[1]*phiLy[2]+(9.0*phiUy[0]+9.0*phiLy[0]-18.0*phiC[0])*rdxCp2[1]-13.85640646055102*rdxCp2[0]*phiUx[1]-20.78460969082652*rdxCp2[0]*phiC[1]+(12.0*phiUx[0]-12.0*phiC[0]-8.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-62.35382907247956*rdxCp2[1]*phiUy[3]+62.35382907247956*rdxCp2[1]*phiLy[3]+(54.0*phiUy[1]+54.0*phiLy[1]-108.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiUx[1]-360.0*rdxCp2[0]*phiC[1]+(103.9230484541326*phiUx[0]-103.9230484541326*phiC[0]+138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac-27.71281292110204*rdxCp2[0]*phiUx[3]-41.56921938165305*rdxCp2[0]*phiC[3]-60.0*rdxCp2[1]*phiUy[2]+24.0*rdxCp2[0]*phiUx[2]-60.0*rdxCp2[1]*phiLy[2]+((-240.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]+(51.96152422706631*phiUy[0]-51.96152422706631*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[1]*phiUy[3]-80.0*rdxCp2[0]*phiUx[3]-120.0*rdxCp2[1]*phiLy[3]+((-480.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]+69.28203230275508*rdxCp2[0]*phiUx[2]-69.28203230275508*rdxCp2[0]*phiC[2]+(103.9230484541326*phiUy[1]-103.9230484541326*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac-3.464101615137754*rdxCp2[1]*phiUy[2]+3.464101615137754*rdxCp2[1]*phiLy[2]+(3.0*phiUy[0]+3.0*phiLy[0]-6.0*phiC[0])*rdxCp2[1]+3.464101615137754*rdxCp2[0]*phiLx[1]-3.464101615137754*rdxCp2[0]*phiC[1]+24.0*rdxCp2[0]*bcVals[1]+(3.0*phiLx[0]-9.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac-6.928203230275509*rdxCp2[1]*phiUy[3]+6.928203230275509*rdxCp2[1]*phiLy[3]+(6.0*phiUy[1]+6.0*phiLy[1]-12.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiLx[1]-100.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+((-17.32050807568877*phiLx[0])-17.32050807568877*phiC[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac+6.928203230275509*rdxCp2[0]*phiLx[3]-6.928203230275509*rdxCp2[0]*phiC[3]-20.0*rdxCp2[1]*phiUy[2]-20.0*rdxCp2[1]*phiLy[2]+6.0*rdxCp2[0]*phiLx[2]+((-80.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]+(17.32050807568877*phiUy[0]-17.32050807568877*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiUy[3]-40.0*rdxCp2[1]*phiLy[3]-40.0*rdxCp2[0]*phiLx[3]+((-160.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]-34.64101615137754*rdxCp2[0]*phiLx[2]-34.64101615137754*rdxCp2[0]*phiC[2]+(34.64101615137754*phiUy[1]-34.64101615137754*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-10.39230484541326*rdxCp2[1]*phiUy[2]+10.39230484541326*rdxCp2[1]*phiLy[2]+(9.0*phiUy[0]+9.0*phiLy[0]-18.0*phiC[0])*rdxCp2[1]+13.85640646055102*rdxCp2[0]*phiLx[1]+20.78460969082652*rdxCp2[0]*phiC[1]+8.0*rdxCp2[0]*bcVals[1]+(12.0*phiLx[0]-12.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-62.35382907247956*rdxCp2[1]*phiUy[3]+62.35382907247956*rdxCp2[1]*phiLy[3]+(54.0*phiUy[1]+54.0*phiLy[1]-108.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiLx[1]-360.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+(103.9230484541326*phiC[0]-103.9230484541326*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac+27.71281292110204*rdxCp2[0]*phiLx[3]+41.56921938165305*rdxCp2[0]*phiC[3]-60.0*rdxCp2[1]*phiUy[2]-60.0*rdxCp2[1]*phiLy[2]+24.0*rdxCp2[0]*phiLx[2]+((-240.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]+(51.96152422706631*phiUy[0]-51.96152422706631*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[1]*phiUy[3]-120.0*rdxCp2[1]*phiLy[3]-80.0*rdxCp2[0]*phiLx[3]+((-480.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]-69.28203230275508*rdxCp2[0]*phiLx[2]+69.28203230275508*rdxCp2[0]*phiC[2]+(103.9230484541326*phiUy[1]-103.9230484541326*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac-3.464101615137754*rdxCp2[1]*phiUy[2]+3.464101615137754*rdxCp2[1]*phiC[2]+24.0*rdxCp2[1]*bcVals[2]+(3.0*phiUy[0]-9.0*phiC[0])*rdxCp2[1]-3.464101615137754*rdxCp2[0]*phiUx[1]+3.464101615137754*rdxCp2[0]*phiLx[1]+(3.0*phiUx[0]+3.0*phiLx[0]-6.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac-6.928203230275509*rdxCp2[1]*phiUy[3]+6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiUy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiUx[1]-20.0*rdxCp2[0]*phiLx[1]-80.0*rdxCp2[0]*phiC[1]+(17.32050807568877*phiUx[0]-17.32050807568877*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac-6.928203230275509*rdxCp2[0]*phiUx[3]+6.928203230275509*rdxCp2[0]*phiLx[3]-20.0*rdxCp2[1]*phiUy[2]+6.0*rdxCp2[0]*phiUx[2]+6.0*rdxCp2[0]*phiLx[2]+((-100.0*rdxCp2[1])-12.0*rdxCp2[0])*phiC[2]-138.5640646055102*rdxCp2[1]*bcVals[2]+(17.32050807568877*phiUy[0]+17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiUy[3]-40.0*rdxCp2[0]*phiUx[3]-40.0*rdxCp2[0]*phiLx[3]+((-200.0*rdxCp2[1])-160.0*rdxCp2[0])*phiC[3]+34.64101615137754*rdxCp2[0]*phiUx[2]-34.64101615137754*rdxCp2[0]*phiLx[2]+(34.64101615137754*phiUy[1]+34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-13.85640646055102*rdxCp2[1]*phiUy[2]-20.78460969082652*rdxCp2[1]*phiC[2]-8.0*rdxCp2[1]*bcVals[2]+(12.0*phiUy[0]-12.0*phiC[0])*rdxCp2[1]-10.39230484541326*rdxCp2[0]*phiUx[1]+10.39230484541326*rdxCp2[0]*phiLx[1]+(9.0*phiUx[0]+9.0*phiLx[0]-18.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac-27.71281292110204*rdxCp2[1]*phiUy[3]-41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiUy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiUx[1]-60.0*rdxCp2[0]*phiLx[1]-240.0*rdxCp2[0]*phiC[1]+(51.96152422706631*phiUx[0]-51.96152422706631*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-62.35382907247956*rdxCp2[0]*phiUx[3]+62.35382907247956*rdxCp2[0]*phiLx[3]-120.0*rdxCp2[1]*phiUy[2]+54.0*rdxCp2[0]*phiUx[2]+54.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-108.0*rdxCp2[0])*phiC[2]+138.5640646055102*rdxCp2[1]*bcVals[2]+(103.9230484541326*phiUy[0]-103.9230484541326*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiUy[3]-120.0*rdxCp2[0]*phiUx[3]-120.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-480.0*rdxCp2[0])*phiC[3]+103.9230484541326*rdxCp2[0]*phiUx[2]-103.9230484541326*rdxCp2[0]*phiLx[2]+(69.28203230275508*phiUy[1]-69.28203230275508*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac+24.0*rdxCp2[1]*bcVals[3]+3.464101615137754*rdxCp2[1]*phiLy[2]-3.464101615137754*rdxCp2[1]*phiC[2]+(3.0*phiLy[0]-9.0*phiC[0])*rdxCp2[1]-3.464101615137754*rdxCp2[0]*phiUx[1]+3.464101615137754*rdxCp2[0]*phiLx[1]+(3.0*phiUx[0]+3.0*phiLx[0]-6.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac+6.928203230275509*rdxCp2[1]*phiLy[3]-6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiLy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiUx[1]-20.0*rdxCp2[0]*phiLx[1]-80.0*rdxCp2[0]*phiC[1]+(17.32050807568877*phiUx[0]-17.32050807568877*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac-6.928203230275509*rdxCp2[0]*phiUx[3]+6.928203230275509*rdxCp2[0]*phiLx[3]+138.5640646055102*rdxCp2[1]*bcVals[3]+6.0*rdxCp2[0]*phiUx[2]-20.0*rdxCp2[1]*phiLy[2]+6.0*rdxCp2[0]*phiLx[2]+((-100.0*rdxCp2[1])-12.0*rdxCp2[0])*phiC[2]+((-17.32050807568877*phiLy[0])-17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[0]*phiUx[3]-40.0*rdxCp2[1]*phiLy[3]-40.0*rdxCp2[0]*phiLx[3]+((-200.0*rdxCp2[1])-160.0*rdxCp2[0])*phiC[3]+34.64101615137754*rdxCp2[0]*phiUx[2]-34.64101615137754*rdxCp2[0]*phiLx[2]+((-34.64101615137754*phiLy[1])-34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+8.0*rdxCp2[1]*bcVals[3]+13.85640646055102*rdxCp2[1]*phiLy[2]+20.78460969082652*rdxCp2[1]*phiC[2]+(12.0*phiLy[0]-12.0*phiC[0])*rdxCp2[1]-10.39230484541326*rdxCp2[0]*phiUx[1]+10.39230484541326*rdxCp2[0]*phiLx[1]+(9.0*phiUx[0]+9.0*phiLx[0]-18.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac+27.71281292110204*rdxCp2[1]*phiLy[3]+41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiLy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiUx[1]-60.0*rdxCp2[0]*phiLx[1]-240.0*rdxCp2[0]*phiC[1]+(51.96152422706631*phiUx[0]-51.96152422706631*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-62.35382907247956*rdxCp2[0]*phiUx[3]+62.35382907247956*rdxCp2[0]*phiLx[3]+138.5640646055102*rdxCp2[1]*bcVals[3]+54.0*rdxCp2[0]*phiUx[2]-120.0*rdxCp2[1]*phiLy[2]+54.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-108.0*rdxCp2[0])*phiC[2]+(103.9230484541326*phiC[0]-103.9230484541326*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[0]*phiUx[3]-80.0*rdxCp2[1]*phiLy[3]-120.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-480.0*rdxCp2[0])*phiC[3]+103.9230484541326*rdxCp2[0]*phiUx[2]-103.9230484541326*rdxCp2[0]*phiLx[2]+(69.28203230275508*phiC[1]-69.28203230275508*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxDirichletLyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac-3.464101615137754*rdxCp2[1]*phiUy[2]+3.464101615137754*rdxCp2[1]*phiC[2]+24.0*rdxCp2[1]*bcVals[2]+(3.0*phiUy[0]-9.0*phiC[0])*rdxCp2[1]-3.464101615137754*rdxCp2[0]*phiUx[1]+3.464101615137754*rdxCp2[0]*phiC[1]+(3.0*phiUx[0]-9.0*phiC[0]+24.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac-6.928203230275509*rdxCp2[1]*phiUy[3]+6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiUy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiUx[1]-100.0*rdxCp2[0]*phiC[1]+(17.32050807568877*phiUx[0]+17.32050807568877*phiC[0]-138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac-6.928203230275509*rdxCp2[0]*phiUx[3]+6.928203230275509*rdxCp2[0]*phiC[3]-20.0*rdxCp2[1]*phiUy[2]+6.0*rdxCp2[0]*phiUx[2]+((-100.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]-138.5640646055102*rdxCp2[1]*bcVals[2]+(17.32050807568877*phiUy[0]+17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiUy[3]-40.0*rdxCp2[0]*phiUx[3]+((-200.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]+34.64101615137754*rdxCp2[0]*phiUx[2]+34.64101615137754*rdxCp2[0]*phiC[2]+(34.64101615137754*phiUy[1]+34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxDirichletLyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-13.85640646055102*rdxCp2[1]*phiUy[2]-20.78460969082652*rdxCp2[1]*phiC[2]-8.0*rdxCp2[1]*bcVals[2]+(12.0*phiUy[0]-12.0*phiC[0])*rdxCp2[1]-10.39230484541326*rdxCp2[0]*phiUx[1]+10.39230484541326*rdxCp2[0]*phiC[1]+(9.0*phiUx[0]-27.0*phiC[0]+72.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac-27.71281292110204*rdxCp2[1]*phiUy[3]-41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiUy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiUx[1]-300.0*rdxCp2[0]*phiC[1]+(51.96152422706631*phiUx[0]+51.96152422706631*phiC[0]-415.6921938165305*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-62.35382907247956*rdxCp2[0]*phiUx[3]+62.35382907247956*rdxCp2[0]*phiC[3]-120.0*rdxCp2[1]*phiUy[2]+54.0*rdxCp2[0]*phiUx[2]+((-360.0*rdxCp2[1])-162.0*rdxCp2[0])*phiC[2]+138.5640646055102*rdxCp2[1]*bcVals[2]+(103.9230484541326*phiUy[0]-103.9230484541326*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiUy[3]-120.0*rdxCp2[0]*phiUx[3]+((-240.0*rdxCp2[1])-600.0*rdxCp2[0])*phiC[3]+103.9230484541326*rdxCp2[0]*phiUx[2]+103.9230484541326*rdxCp2[0]*phiC[2]+(69.28203230275508*phiUy[1]-69.28203230275508*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxNeumannLyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-10.39230484541326*rdxCp2[1]*phiUy[2]+10.39230484541326*rdxCp2[1]*phiC[2]+72.0*rdxCp2[1]*bcVals[2]+(9.0*phiUy[0]-27.0*phiC[0])*rdxCp2[1]-13.85640646055102*rdxCp2[0]*phiUx[1]-20.78460969082652*rdxCp2[0]*phiC[1]+(12.0*phiUx[0]-12.0*phiC[0]-8.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-62.35382907247956*rdxCp2[1]*phiUy[3]+62.35382907247956*rdxCp2[1]*phiC[3]+(54.0*phiUy[1]-162.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiUx[1]-360.0*rdxCp2[0]*phiC[1]+(103.9230484541326*phiUx[0]-103.9230484541326*phiC[0]+138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac-27.71281292110204*rdxCp2[0]*phiUx[3]-41.56921938165305*rdxCp2[0]*phiC[3]-60.0*rdxCp2[1]*phiUy[2]+24.0*rdxCp2[0]*phiUx[2]+((-300.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]-415.6921938165305*rdxCp2[1]*bcVals[2]+(51.96152422706631*phiUy[0]+51.96152422706631*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[1]*phiUy[3]-80.0*rdxCp2[0]*phiUx[3]+((-600.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]+69.28203230275508*rdxCp2[0]*phiUx[2]-69.28203230275508*rdxCp2[0]*phiC[2]+(103.9230484541326*phiUy[1]+103.9230484541326*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxNeumannLyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-13.85640646055102*rdxCp2[1]*phiUy[2]-20.78460969082652*rdxCp2[1]*phiC[2]-8.0*rdxCp2[1]*bcVals[2]+(12.0*phiUy[0]-12.0*phiC[0])*rdxCp2[1]-13.85640646055102*rdxCp2[0]*phiUx[1]-20.78460969082652*rdxCp2[0]*phiC[1]+(12.0*phiUx[0]-12.0*phiC[0]-8.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-83.1384387633061*rdxCp2[1]*phiUy[3]-124.7076581449591*rdxCp2[1]*phiC[3]+(72.0*phiUy[1]-72.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiUx[1]-360.0*rdxCp2[0]*phiC[1]+(103.9230484541326*phiUx[0]-103.9230484541326*phiC[0]+138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-83.1384387633061*rdxCp2[0]*phiUx[3]-124.7076581449591*rdxCp2[0]*phiC[3]-120.0*rdxCp2[1]*phiUy[2]+72.0*rdxCp2[0]*phiUx[2]+((-360.0*rdxCp2[1])-72.0*rdxCp2[0])*phiC[2]+138.5640646055102*rdxCp2[1]*bcVals[2]+(103.9230484541326*phiUy[0]-103.9230484541326*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiUy[3]-80.0*rdxCp2[0]*phiUx[3]+((-240.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]+69.28203230275508*rdxCp2[0]*phiUx[2]-69.28203230275508*rdxCp2[0]*phiC[2]+(69.28203230275508*phiUy[1]-69.28203230275508*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxDirichletUyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac+24.0*rdxCp2[1]*bcVals[3]+3.464101615137754*rdxCp2[1]*phiLy[2]-3.464101615137754*rdxCp2[1]*phiC[2]+(3.0*phiLy[0]-9.0*phiC[0])*rdxCp2[1]-3.464101615137754*rdxCp2[0]*phiUx[1]+3.464101615137754*rdxCp2[0]*phiC[1]+(3.0*phiUx[0]-9.0*phiC[0]+24.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac+6.928203230275509*rdxCp2[1]*phiLy[3]-6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiLy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiUx[1]-100.0*rdxCp2[0]*phiC[1]+(17.32050807568877*phiUx[0]+17.32050807568877*phiC[0]-138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac-6.928203230275509*rdxCp2[0]*phiUx[3]+6.928203230275509*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]+6.0*rdxCp2[0]*phiUx[2]-20.0*rdxCp2[1]*phiLy[2]+((-100.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]+((-17.32050807568877*phiLy[0])-17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[0]*phiUx[3]-40.0*rdxCp2[1]*phiLy[3]+((-200.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]+34.64101615137754*rdxCp2[0]*phiUx[2]+34.64101615137754*rdxCp2[0]*phiC[2]+((-34.64101615137754*phiLy[1])-34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxDirichletUyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+8.0*rdxCp2[1]*bcVals[3]+13.85640646055102*rdxCp2[1]*phiLy[2]+20.78460969082652*rdxCp2[1]*phiC[2]+(12.0*phiLy[0]-12.0*phiC[0])*rdxCp2[1]-10.39230484541326*rdxCp2[0]*phiUx[1]+10.39230484541326*rdxCp2[0]*phiC[1]+(9.0*phiUx[0]-27.0*phiC[0]+72.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac+27.71281292110204*rdxCp2[1]*phiLy[3]+41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiLy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiUx[1]-300.0*rdxCp2[0]*phiC[1]+(51.96152422706631*phiUx[0]+51.96152422706631*phiC[0]-415.6921938165305*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-62.35382907247956*rdxCp2[0]*phiUx[3]+62.35382907247956*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]+54.0*rdxCp2[0]*phiUx[2]-120.0*rdxCp2[1]*phiLy[2]+((-360.0*rdxCp2[1])-162.0*rdxCp2[0])*phiC[2]+(103.9230484541326*phiC[0]-103.9230484541326*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[0]*phiUx[3]-80.0*rdxCp2[1]*phiLy[3]+((-240.0*rdxCp2[1])-600.0*rdxCp2[0])*phiC[3]+103.9230484541326*rdxCp2[0]*phiUx[2]+103.9230484541326*rdxCp2[0]*phiC[2]+(69.28203230275508*phiC[1]-69.28203230275508*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxNeumannUyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+72.0*rdxCp2[1]*bcVals[3]+10.39230484541326*rdxCp2[1]*phiLy[2]-10.39230484541326*rdxCp2[1]*phiC[2]+(9.0*phiLy[0]-27.0*phiC[0])*rdxCp2[1]-13.85640646055102*rdxCp2[0]*phiUx[1]-20.78460969082652*rdxCp2[0]*phiC[1]+(12.0*phiUx[0]-12.0*phiC[0]-8.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac+62.35382907247956*rdxCp2[1]*phiLy[3]-62.35382907247956*rdxCp2[1]*phiC[3]+(54.0*phiLy[1]-162.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiUx[1]-360.0*rdxCp2[0]*phiC[1]+(103.9230484541326*phiUx[0]-103.9230484541326*phiC[0]+138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac-27.71281292110204*rdxCp2[0]*phiUx[3]-41.56921938165305*rdxCp2[0]*phiC[3]+415.6921938165305*rdxCp2[1]*bcVals[3]+24.0*rdxCp2[0]*phiUx[2]-60.0*rdxCp2[1]*phiLy[2]+((-300.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]+((-51.96152422706631*phiLy[0])-51.96152422706631*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[0]*phiUx[3]-120.0*rdxCp2[1]*phiLy[3]+((-600.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]+69.28203230275508*rdxCp2[0]*phiUx[2]-69.28203230275508*rdxCp2[0]*phiC[2]+((-103.9230484541326*phiLy[1])-103.9230484541326*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_LxNeumannUyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+8.0*rdxCp2[1]*bcVals[3]+13.85640646055102*rdxCp2[1]*phiLy[2]+20.78460969082652*rdxCp2[1]*phiC[2]+(12.0*phiLy[0]-12.0*phiC[0])*rdxCp2[1]-13.85640646055102*rdxCp2[0]*phiUx[1]-20.78460969082652*rdxCp2[0]*phiC[1]+(12.0*phiUx[0]-12.0*phiC[0]-8.0*bcVals[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac+83.1384387633061*rdxCp2[1]*phiLy[3]+124.7076581449591*rdxCp2[1]*phiC[3]+(72.0*phiLy[1]-72.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiUx[1]-360.0*rdxCp2[0]*phiC[1]+(103.9230484541326*phiUx[0]-103.9230484541326*phiC[0]+138.5640646055102*bcVals[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac-83.1384387633061*rdxCp2[0]*phiUx[3]-124.7076581449591*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]+72.0*rdxCp2[0]*phiUx[2]-120.0*rdxCp2[1]*phiLy[2]+((-360.0*rdxCp2[1])-72.0*rdxCp2[0])*phiC[2]+(103.9230484541326*phiC[0]-103.9230484541326*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[0]*phiUx[3]-80.0*rdxCp2[1]*phiLy[3]+((-240.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]+69.28203230275508*rdxCp2[0]*phiUx[2]-69.28203230275508*rdxCp2[0]*phiC[2]+(69.28203230275508*phiC[1]-69.28203230275508*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxDirichletLyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac-3.464101615137754*rdxCp2[1]*phiUy[2]+3.464101615137754*rdxCp2[1]*phiC[2]+24.0*rdxCp2[1]*bcVals[2]+(3.0*phiUy[0]-9.0*phiC[0])*rdxCp2[1]+3.464101615137754*rdxCp2[0]*phiLx[1]-3.464101615137754*rdxCp2[0]*phiC[1]+24.0*rdxCp2[0]*bcVals[1]+(3.0*phiLx[0]-9.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac-6.928203230275509*rdxCp2[1]*phiUy[3]+6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiUy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiLx[1]-100.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+((-17.32050807568877*phiLx[0])-17.32050807568877*phiC[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac+6.928203230275509*rdxCp2[0]*phiLx[3]-6.928203230275509*rdxCp2[0]*phiC[3]-20.0*rdxCp2[1]*phiUy[2]+6.0*rdxCp2[0]*phiLx[2]+((-100.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]-138.5640646055102*rdxCp2[1]*bcVals[2]+(17.32050807568877*phiUy[0]+17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiUy[3]-40.0*rdxCp2[0]*phiLx[3]+((-200.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]-34.64101615137754*rdxCp2[0]*phiLx[2]-34.64101615137754*rdxCp2[0]*phiC[2]+(34.64101615137754*phiUy[1]+34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxDirichletLyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-13.85640646055102*rdxCp2[1]*phiUy[2]-20.78460969082652*rdxCp2[1]*phiC[2]-8.0*rdxCp2[1]*bcVals[2]+(12.0*phiUy[0]-12.0*phiC[0])*rdxCp2[1]+10.39230484541326*rdxCp2[0]*phiLx[1]-10.39230484541326*rdxCp2[0]*phiC[1]+72.0*rdxCp2[0]*bcVals[1]+(9.0*phiLx[0]-27.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac-27.71281292110204*rdxCp2[1]*phiUy[3]-41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiUy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiLx[1]-300.0*rdxCp2[0]*phiC[1]+415.6921938165305*rdxCp2[0]*bcVals[1]+((-51.96152422706631*phiLx[0])-51.96152422706631*phiC[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac+62.35382907247956*rdxCp2[0]*phiLx[3]-62.35382907247956*rdxCp2[0]*phiC[3]-120.0*rdxCp2[1]*phiUy[2]+54.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-162.0*rdxCp2[0])*phiC[2]+138.5640646055102*rdxCp2[1]*bcVals[2]+(103.9230484541326*phiUy[0]-103.9230484541326*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiUy[3]-120.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-600.0*rdxCp2[0])*phiC[3]-103.9230484541326*rdxCp2[0]*phiLx[2]-103.9230484541326*rdxCp2[0]*phiC[2]+(69.28203230275508*phiUy[1]-69.28203230275508*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxNeumannLyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-10.39230484541326*rdxCp2[1]*phiUy[2]+10.39230484541326*rdxCp2[1]*phiC[2]+72.0*rdxCp2[1]*bcVals[2]+(9.0*phiUy[0]-27.0*phiC[0])*rdxCp2[1]+13.85640646055102*rdxCp2[0]*phiLx[1]+20.78460969082652*rdxCp2[0]*phiC[1]+8.0*rdxCp2[0]*bcVals[1]+(12.0*phiLx[0]-12.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-62.35382907247956*rdxCp2[1]*phiUy[3]+62.35382907247956*rdxCp2[1]*phiC[3]+(54.0*phiUy[1]-162.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiLx[1]-360.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+(103.9230484541326*phiC[0]-103.9230484541326*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac+27.71281292110204*rdxCp2[0]*phiLx[3]+41.56921938165305*rdxCp2[0]*phiC[3]-60.0*rdxCp2[1]*phiUy[2]+24.0*rdxCp2[0]*phiLx[2]+((-300.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]-415.6921938165305*rdxCp2[1]*bcVals[2]+(51.96152422706631*phiUy[0]+51.96152422706631*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[1]*phiUy[3]-80.0*rdxCp2[0]*phiLx[3]+((-600.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]-69.28203230275508*rdxCp2[0]*phiLx[2]+69.28203230275508*rdxCp2[0]*phiC[2]+(103.9230484541326*phiUy[1]+103.9230484541326*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxNeumannLyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac-13.85640646055102*rdxCp2[1]*phiUy[2]-20.78460969082652*rdxCp2[1]*phiC[2]-8.0*rdxCp2[1]*bcVals[2]+(12.0*phiUy[0]-12.0*phiC[0])*rdxCp2[1]+13.85640646055102*rdxCp2[0]*phiLx[1]+20.78460969082652*rdxCp2[0]*phiC[1]+8.0*rdxCp2[0]*bcVals[1]+(12.0*phiLx[0]-12.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac-83.1384387633061*rdxCp2[1]*phiUy[3]-124.7076581449591*rdxCp2[1]*phiC[3]+(72.0*phiUy[1]-72.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiLx[1]-360.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+(103.9230484541326*phiC[0]-103.9230484541326*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac+83.1384387633061*rdxCp2[0]*phiLx[3]+124.7076581449591*rdxCp2[0]*phiC[3]-120.0*rdxCp2[1]*phiUy[2]+72.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-72.0*rdxCp2[0])*phiC[2]+138.5640646055102*rdxCp2[1]*bcVals[2]+(103.9230484541326*phiUy[0]-103.9230484541326*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiUy[3]-80.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]-69.28203230275508*rdxCp2[0]*phiLx[2]+69.28203230275508*rdxCp2[0]*phiC[2]+(69.28203230275508*phiUy[1]-69.28203230275508*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxDirichletUyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.5*(rho[0]*volFac+24.0*rdxCp2[1]*bcVals[3]+3.464101615137754*rdxCp2[1]*phiLy[2]-3.464101615137754*rdxCp2[1]*phiC[2]+(3.0*phiLy[0]-9.0*phiC[0])*rdxCp2[1]+3.464101615137754*rdxCp2[0]*phiLx[1]-3.464101615137754*rdxCp2[0]*phiC[1]+24.0*rdxCp2[0]*bcVals[1]+(3.0*phiLx[0]-9.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.5*(rho[1]*volFac+6.928203230275509*rdxCp2[1]*phiLy[3]-6.928203230275509*rdxCp2[1]*phiC[3]+(6.0*phiLy[1]-18.0*phiC[1])*rdxCp2[1]-20.0*rdxCp2[0]*phiLx[1]-100.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+((-17.32050807568877*phiLx[0])-17.32050807568877*phiC[0])*rdxCp2[0]); 
  resOut[2] = 0.5*(rho[2]*volFac+6.928203230275509*rdxCp2[0]*phiLx[3]-6.928203230275509*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]-20.0*rdxCp2[1]*phiLy[2]+6.0*rdxCp2[0]*phiLx[2]+((-100.0*rdxCp2[1])-18.0*rdxCp2[0])*phiC[2]+((-17.32050807568877*phiLy[0])-17.32050807568877*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.5*(rho[3]*volFac-40.0*rdxCp2[1]*phiLy[3]-40.0*rdxCp2[0]*phiLx[3]+((-200.0*rdxCp2[1])-200.0*rdxCp2[0])*phiC[3]-34.64101615137754*rdxCp2[0]*phiLx[2]-34.64101615137754*rdxCp2[0]*phiC[2]+((-34.64101615137754*phiLy[1])-34.64101615137754*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxDirichletUyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+8.0*rdxCp2[1]*bcVals[3]+13.85640646055102*rdxCp2[1]*phiLy[2]+20.78460969082652*rdxCp2[1]*phiC[2]+(12.0*phiLy[0]-12.0*phiC[0])*rdxCp2[1]+10.39230484541326*rdxCp2[0]*phiLx[1]-10.39230484541326*rdxCp2[0]*phiC[1]+72.0*rdxCp2[0]*bcVals[1]+(9.0*phiLx[0]-27.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.1666666666666667*(3.0*rho[1]*volFac+27.71281292110204*rdxCp2[1]*phiLy[3]+41.56921938165305*rdxCp2[1]*phiC[3]+(24.0*phiLy[1]-24.0*phiC[1])*rdxCp2[1]-60.0*rdxCp2[0]*phiLx[1]-300.0*rdxCp2[0]*phiC[1]+415.6921938165305*rdxCp2[0]*bcVals[1]+((-51.96152422706631*phiLx[0])-51.96152422706631*phiC[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac+62.35382907247956*rdxCp2[0]*phiLx[3]-62.35382907247956*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]-120.0*rdxCp2[1]*phiLy[2]+54.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-162.0*rdxCp2[0])*phiC[2]+(103.9230484541326*phiC[0]-103.9230484541326*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiLy[3]-120.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-600.0*rdxCp2[0])*phiC[3]-103.9230484541326*rdxCp2[0]*phiLx[2]-103.9230484541326*rdxCp2[0]*phiC[2]+(69.28203230275508*phiC[1]-69.28203230275508*phiLy[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxNeumannUyDirichlet_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+72.0*rdxCp2[1]*bcVals[3]+10.39230484541326*rdxCp2[1]*phiLy[2]-10.39230484541326*rdxCp2[1]*phiC[2]+(9.0*phiLy[0]-27.0*phiC[0])*rdxCp2[1]+13.85640646055102*rdxCp2[0]*phiLx[1]+20.78460969082652*rdxCp2[0]*phiC[1]+8.0*rdxCp2[0]*bcVals[1]+(12.0*phiLx[0]-12.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac+62.35382907247956*rdxCp2[1]*phiLy[3]-62.35382907247956*rdxCp2[1]*phiC[3]+(54.0*phiLy[1]-162.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiLx[1]-360.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+(103.9230484541326*phiC[0]-103.9230484541326*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.1666666666666667*(3.0*rho[2]*volFac+27.71281292110204*rdxCp2[0]*phiLx[3]+41.56921938165305*rdxCp2[0]*phiC[3]+415.6921938165305*rdxCp2[1]*bcVals[3]-60.0*rdxCp2[1]*phiLy[2]+24.0*rdxCp2[0]*phiLx[2]+((-300.0*rdxCp2[1])-24.0*rdxCp2[0])*phiC[2]+((-51.96152422706631*phiLy[0])-51.96152422706631*phiC[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-120.0*rdxCp2[1]*phiLy[3]-80.0*rdxCp2[0]*phiLx[3]+((-600.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]-69.28203230275508*rdxCp2[0]*phiLx[2]+69.28203230275508*rdxCp2[0]*phiC[2]+((-103.9230484541326*phiLy[1])-103.9230484541326*phiC[1])*rdxCp2[1]); 

}

void MGpoissonResidue2xSer_UxNeumannUyNeumann_P1(double **dx, const double *bcVals, const double *rho, double **phi, double *resOut) 
{ 
  // dx:     cell lengths of cells pointed to by the stencil.
  // rho:    right-side source in the current cell.
  // bcVals: values to impose as BCs.
  // phi:    iterate cells pointed to by the stencil.
  // resOut: residue in current cell.

  double *dxC  = dx[0]; 

  double volFac = 0.25*dxC[0]*dxC[1]; 

  double rdxCp2[2]; 
  double rdxCp2Sq[2]; 
  double rdxCp2R3[2]; 
  double rdxCp2R4[2]; 
  double rdxCp2R6[2]; 
  double rdxCp2R8[2]; 
  rdxCp2[0]  = volFac/(dxC[0]*dxC[0]); 
  rdxCp2Sq[0]  = rdxCp2[0]*rdxCp2[0]; 
  rdxCp2R3[0]  = rdxCp2[0]*rdxCp2Sq[0]; 
  rdxCp2R4[0]  = rdxCp2Sq[0]*rdxCp2Sq[0]; 
  rdxCp2R6[0]  = rdxCp2Sq[0]*rdxCp2R4[0]; 
  rdxCp2R8[0]  = rdxCp2R4[0]*rdxCp2R4[0]; 
  rdxCp2[1]  = volFac/(dxC[1]*dxC[1]); 
  rdxCp2Sq[1]  = rdxCp2[1]*rdxCp2[1]; 
  rdxCp2R3[1]  = rdxCp2[1]*rdxCp2Sq[1]; 
  rdxCp2R4[1]  = rdxCp2Sq[1]*rdxCp2Sq[1]; 
  rdxCp2R6[1]  = rdxCp2Sq[1]*rdxCp2R4[1]; 
  rdxCp2R8[1]  = rdxCp2R4[1]*rdxCp2R4[1]; 

  double *phiC = phi[0]; 
  double *phiUx = phi[1]; 
  double *phiLx = phi[2]; 
  double *phiUy = phi[3]; 
  double *phiLy = phi[4]; 

  resOut[0] = 0.1666666666666667*(3.0*rho[0]*volFac+8.0*rdxCp2[1]*bcVals[3]+13.85640646055102*rdxCp2[1]*phiLy[2]+20.78460969082652*rdxCp2[1]*phiC[2]+(12.0*phiLy[0]-12.0*phiC[0])*rdxCp2[1]+13.85640646055102*rdxCp2[0]*phiLx[1]+20.78460969082652*rdxCp2[0]*phiC[1]+8.0*rdxCp2[0]*bcVals[1]+(12.0*phiLx[0]-12.0*phiC[0])*rdxCp2[0]); 
  resOut[1] = 0.05555555555555555*(9.0*rho[1]*volFac+83.1384387633061*rdxCp2[1]*phiLy[3]+124.7076581449591*rdxCp2[1]*phiC[3]+(72.0*phiLy[1]-72.0*phiC[1])*rdxCp2[1]-120.0*rdxCp2[0]*phiLx[1]-360.0*rdxCp2[0]*phiC[1]+138.5640646055102*rdxCp2[0]*bcVals[1]+(103.9230484541326*phiC[0]-103.9230484541326*phiLx[0])*rdxCp2[0]); 
  resOut[2] = 0.05555555555555555*(9.0*rho[2]*volFac+83.1384387633061*rdxCp2[0]*phiLx[3]+124.7076581449591*rdxCp2[0]*phiC[3]+138.5640646055102*rdxCp2[1]*bcVals[3]-120.0*rdxCp2[1]*phiLy[2]+72.0*rdxCp2[0]*phiLx[2]+((-360.0*rdxCp2[1])-72.0*rdxCp2[0])*phiC[2]+(103.9230484541326*phiC[0]-103.9230484541326*phiLy[0])*rdxCp2[1]); 
  resOut[3] = 0.1666666666666667*(3.0*rho[3]*volFac-80.0*rdxCp2[1]*phiLy[3]-80.0*rdxCp2[0]*phiLx[3]+((-240.0*rdxCp2[1])-240.0*rdxCp2[0])*phiC[3]-69.28203230275508*rdxCp2[0]*phiLx[2]+69.28203230275508*rdxCp2[0]*phiC[2]+(69.28203230275508*phiC[1]-69.28203230275508*phiLy[1])*rdxCp2[1]); 

}

