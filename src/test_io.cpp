#include <cstdlib>
#include <iostream>

#include "eigen_io.h"

int main() {
  //initialization variables
  const int n_eig_vec = 120;
  const int v3 = 41472;


  EigenIo blub(v3,n_eig_vec);
  blub.read_eig_sys_bin("eigenvectors",500,0);
  blub.write_eig_sys_bin("eigenvectors_out",500,0);

  return 0;

}
