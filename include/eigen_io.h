#ifndef _EIGEN_IO_H_
#define _EIGEN_IO_H_

#include <complex>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>

#include <Eigen/Eigen>

#include "variables.h"
class EigenIo {
 //Member types
  private:
    Eigen::MatrixXcd eig_sys_io;
    Eigen::Matrix3cd** ts_io;
    Eigen::VectorXd eig_vals_io; 
    double* configuration;

  protected:  
  //checks for right allocation (to be used in read/write functions)
    bool check_V3();
    bool check_V4();
    bool check_NB_EV();

  public:
  //Constructors
  EigenIo() {};
  EigenIo(const int NB_EV);
  EigenIo(const int v3, const int NB_EV);
  EigenIo(const int NB_EV, const int v3, const int v4);

  //Read in Eigenvectors from one Timeslice in binary format to V
  void read_eig_sys_bin(const char* prefix, const int config_i, const int t);
  void read_eig_vals_bin(const char* prefix, const int config_i, const int t);
  //void read_gauge_config();

  //Writing functions for Eigensystems
  void write_eig_sys_bin(const char* prefix, const int config_i, const int t);
  void write_eig_vals_bin(const char* prefix, const int config_i, const int t);



};
#endif//_EIGEN_IO_H
