#include "navigation.h"

//Destructor for Navigate objects
Nav::~Nav() {

  for (int i = 0; i < 3; ++i) {
    delete [] iup[i];
    delete [] idown[i];
  }

  delete up_3d;
  delete down_3d;
  
}

//Constructor including right initialization
Nav::Nav() {
  //NOT SURE HOW TO GET 3D VOLUME FROM CLASS PARAMETERS!!!
  vol =   
  **iup = new int *[vol];
  **idown = new int *[vol];

  for (int i = 0; i < vol; ++i){
    iup[i] = new int[3];
    idown[i] = new int[3];
  }
  //initialization of both lookup tables
  init();
}

Nav::init() {
  //const ints vor 3d volume, assuming L1 = L2;
  const int L1 = vol;
  const int L2 = vol;

  int* x0_h = new int[3];
  int* x1_h = new int[3];
  int* x2_h = new int[3];
  
  int L0_h = L1 * L2;

  for ( int x0 = 0; x0 < L1; ++x0 ) {//loop x0
    x0_h[2] = x0 * L0_h;
    //negative direction (index at lower boundary)
    if ((x0_h[0] = x0 - 1) < 0) x0_h[0] = L0_h * (L1 - 1);
    else x0_h[0] *= L0_h;
    //positive direction (index at upper boundary)
    if ((x0_h[1] = x0 + 1) == L1) x0_h[1] = 0;
    else x0_h[1] *= L0_h;

    for ( int x1 = 0; x1 < L1; ++x1 ) {//loop x1
      x1_h[2] = x1 * L2;
      //neg. dir.
      if ((x1_h[0] = x1 - 1) < 0) x1_h[0] = L2 * (L1 - 1);
      else x1_h[0] *= L2;
      //pos. dir.
      if ((x1_h[1] = x1 + 1) == L1) x1_h[1] = 0;
      else x1_h[1] *= L2;

      for ( int x2 = 0; x2 < L2; ++x2 ) {//loop x2
        x2_h[2] = x2;
        //neg. dir.
        if ((x2_h[0] = x2 - 1) < 0) x2_h[0] = L2 -1;
        //pos. dir.
        if ((x2_h[1] = x2 +1) == L2) x2_h[1] = 0;
        //overall volume index
        int i = x0_h[2] + x1_h[2] + x2_h[2];
        //std::cout << x0 << " " << x1 << " " << x2 << " " << i << std::endl;
        //upwards
        iup[i][0] = x0_h[1] + x1_h[2] + x2_h[2];
        iup[i][1] = x0_h[2] + x1_h[1] + x2_h[2];
        iup[i][2] = x0_h[2] + x1_h[2] + x2_h[1];
        //downwards
        idown[i][0] = x0_h[0] + x1_h[2] + x2_h[2];
        idown[i][1] = x0_h[2] + x1_h[0] + x2_h[2];
        idown[i][2] = x0_h[2] + x1_h[2] + x2_h[0];
      }//end loop x2
    }//end loop x1
  }//end loop x0
  delete x0_h;
  delete x1_h;
  delete x2_h;

}
//calculates dist steps in direction dir from original index
int Nav::dist_ind(const int org_pos, const int dir, const int dist) {

  //Error check for input arguments
  if (fabs(dir) >= 3){
    std::cout <<
    return (-1);
  }
  int tmp = 0;
  if (dir > 0) {
    for (cnt = 0; cnt < dist; ++cnt) {
      tmp = iup[org_pos][dir];
      org_pos = tmp;
    }
  }
  else {
    //get direction right
    dir *= (-1);
    for (cnt = 0; cnt < dist; ++cnt) {
      tmp = idown[org_pos][dir];
      org_pos = tmp;
    }
  }
  return tmp;
}
