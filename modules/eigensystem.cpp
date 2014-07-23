
#include "eigensystem.h"
//void constructor.


Eigensystem::Eigensystem (const int dim_vol, const int dim_eig) {
  eig_vec.resize(dim_vol);
  ts = new Eigen::Matrix3cd[dim_vol];
  eig_sys.resize(dim_vol, dim_eig);
}

//Prints status of member
void Eigensystem::status (void) {
  std::cout << "Size of Eigensystem: " << eig_sys.rows() << " x " << eig_sys.cols() << std::endl;
}

