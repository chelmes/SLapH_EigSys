#ifndef _EIGENSYSTEM_H_
#define _EIGENSYSTEM_H_

#include <complex>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <Eigen/Eigen>

#include "navigation.h"
#include "variables.h"
//Class handling Eigensystems

class Eigensystem {
  private:
  std::vector <double> eig_vals;
  Eigen::VectorXcd eig_vec;
  Eigen::Matrix3cd* ts;
  Eigen::MatrixXcd eig_sys;
  std::vector <double> phases;
  //Default Constructor for a 24^3 eigensystem with 120 eigenvectors
  Eigensystem () {};

  public:


  //Constructors

  //Advanced constructor for eigensystem initializing Timeslice of one
  //configuration with spatial volume dim_vol and LapH dimension dim_eig.
  Eigensystem (const int, const int);

  //Get information of instance
  void status();
};

#endif //_EIGENSYSTEM_H_
