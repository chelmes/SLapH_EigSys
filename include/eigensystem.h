#ifndef _EIGENSYSTEM_H_
#define _EIGENSYSTEM_H_

#include <complex>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <Eigen/Eigen>

#include "mash.h"
#include "variables.h"
//Class handling Eigensystems

class Eigensystem : public Element {

  public:
  void map();

  //Constructors

  //Advanced constructor for eigensystem initializing Timeslice of one
  //configuration with spatial volume dim_vol and LapH dimension dim_eig.
  Eigensystem (const int, const int);

  //Get information of instance
  void status();

  private:
   
  //Default Constructor for a 24^3 eigensystem with 120 eigenvectors
  Eigensystem () {};
  Eigensys_dat data;

};

#endif //_EIGENSYSTEM_H_
