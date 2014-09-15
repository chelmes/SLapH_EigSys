#include <cstdio>
#include <fstream>
#include <ostream>#include <ostream>#include <ostream>
#include "navigation.h"
#include "pottstill.h"

static IO* const paras = IO::getInstance();

class DataIO::read_write{
  public:
  private:

    Eigen::MatrixXcd read_evectors_ts( const int config_i, const int t) {
      Eigen::MatrixXcd V; 
      const int dim_row = paras -> get_int("MAT_ENTRIES");
      const int nb_ev = paras -> get_int("NEV");

      //buffer one eigenvector for read in
      std::complex<double>* eigen_vec = new std::complex<double>[dim_row];
      //setting up filename
      char filename[200];
      sprintf(filename, "%s.%04d.%03d", "eigenvectors", config_i, t);
      std::cout << "Reading file: " << filename << std::endl;
      std::ifstream infile(filename, std::ifstream::binary);
      for (int nev = 0; nev < nb_ev; ++nev) {
        infile.read( reinterpret_cast<char*> (eigen_vec), 2*dim_row*sizeof(double));
        Eigen::Map<Eigen::VectorXcd> vec(eigen_vec,dim_row);
        V.col(nev) = vec;
        //std::cout << eigen_vec[5] << std::endl;
      }
      //clean up
      delete[] eigen_vec;
      infile.close();
      return V;
    }
};
