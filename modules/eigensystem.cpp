
#include "eigensystem.h"
//void constructor.


Eigensystem::Eigensystem ( IO* params ) {
  //parameters from input
  int dim_vol = params -> get_int("V_TS");
  int dim_eig = params -> get_int("NEV");

  eig_vec.resize(dim_vol);
  ts = new Eigen::Matrix3cd[dim_vol];
  eig_sys.resize(dim_vol, dim_eig);
  phases.resize(dim_eig);

//Prints status of member
void Eigensystem::status () {
  std::cout << "Size of Eigensystem: " << eig_sys.rows() << " x " << eig_sys.cols() << std::endl;
  std::cout << "Colour Matrices in timeslice: " << ts.size() << " 3 x 3 matrices" << std::endl;
}

//Get timeslice in terms of eigen
void Eigensystem::map(IO* params) {

  //parameters from input file
  int LZ = params -> get_int("LZ");
  int LY = params -> get_int("LY");
  int LX = params -> get_int("LX");
  int LT = params -> get_int("LT");
  int NDIR = params -> get_int("NDIR");
  int NCOL = params -> get_int("NCOL");
  int V_TS = params -> get_int("V_TS");

  //read in elements
  int el_input = 0;
  for (int z = 0; z < params->get_int("LZ"); ++z) {//spatial loops
    for (int y = 0; y < ; ++y) {
      for (int x = 0; x < L1; ++x) {
        for (int mu = 1; mu < ; ++mu) {//direction loop
          std::complex< double > array[9];
          for (int a = 0; a < 3; ++a) {//colour loops
            for (int b = 0; b < 3; ++b) {
              //timeslice index of real part
              int ind_r = z*V_TS/LZ+y*V_TS/(LZ*LY)+x*V_TS/(V3)+
                mu*V_TS/(V3*NDIR)+a*V_TS/(V3*NDIR*NCOL)
                +b*V_TS/(V3*NDIR*NCOL*NCOL)+0;
              //timeslice index of imaginary part
              int ind_i = z*V_TS/LZ+y*V_TS/(LZ*LY)+x*V_TS/(V3)+
                mu*V_TS/(V3*NDIR)+a*V_TS/(V3*NDIR*NCOL)
                +b*V_TS/(V3*NDIR*NCOL*NCOL)+1;
              std::complex<double> pair(timeslice[ind_r], timeslice[ind_i]);
              //array to be mapped to Eigen Array
              array[3*b+a] = pair;
              ++el_input;
            }
          }
          Eigen::Map<Eigen::Matrix3cd> dummy(array);
          //spatial index
          int ind = z*L2*L1+y*L1+x;
          eigen[ind][mu-1] = dummy;
        }
      }
    }
  }

}
