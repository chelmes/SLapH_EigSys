#include "eigen_io.h"

/*********************************** Constructors *****************************************/
EigenIo::EigenIo(const int v3, const int nev) {
  eig_sys_io.resize(v3,nev);
}

/*********************************** Read and Write ***************************************/

//Get timeslice from configuration


//construct filename
void name (const char* prefix, const int config, const int time) {
}

//Reads in Eigenvectors from one Timeslice in binary format to V
void EigenIo::read_eig_sys_bin(const char* prefix, const int config_i, const int t) {

  if (check_V3()) {
    std::cout << "Read-in aborted" << std::endl; 
  }

  else {

    const int nb_ev = eig_sys_io.cols();
    //buffer for read in
    std::complex<double>* eigen_vec = new std::complex<double>[MAT_ENTRIES];
    //setting up ile
    char file [200];
    sprintf(file, "%s.%04d.%03d", prefix, config_i, t);
    std::cout << "Reading from file: " << file << std::endl;
    std::ifstream infile(file, std::ifstream::binary);
    for (int nev = 0; nev < nb_ev; ++nev) {
      infile.read( reinterpret_cast<char*> (eigen_vec), 2*MAT_ENTRIES*sizeof(double));
      eig_sys_io.col(nev) = Eigen::Map<Eigen::Matrix<std::complex<double>, MAT_ENTRIES, 1> >(eigen_vec);
      //std::cout << eigen_vec[5] << std::endl;
    }
    //clean up
    delete[] eigen_vec;
    infile.close();

  }

}

//Writes eigenvectors from one Timeslice to file in binary format

void EigenIo::write_eig_sys_bin(const char* prefix, const int config_i, const int t) {
  if (check_V3()) {
    std::cout << "Write-out aborted" << std::endl;
  }
  else {
    //set up filename
    char file [200];
    sprintf(file, "%s.%04d.%03d", prefix, config_i, t);
    std::cout << "Writing to file:" << file << std::endl;
    std::ofstream outfile(file, std::ofstream::binary);
    outfile.write(reinterpret_cast<char*> (eig_sys_io.data()), 2*3*V3*NEV*sizeof(double));
    outfile.close();
  }
}

//Reads in eigenvalues from binary to std::vector
void EigenIo::read_eig_vals_bin( const char* prefix, const int config_i, const int t) {
  /* 
  //Build filename
  char filename[200];
  sprintf(filename, "%s.%04d.%03d", prefix, config_i, t);
  std::ifstream infile(filename, std::ifstream::binary);
  if (infile) {
  eig_vals.resize(nb_ev);
  infile.read (reinterpret_cast<char*>(&ev[0]), ev.size()*sizeof(double));
  //if(infile) std::cout << filename << " read successfully" << std::endl;
  //else std::cout << "error: only" << infile.gcount() << "could be read" << std::endl;
  infile.close();
  }  
  */
}

bool EigenIo::check_V3() { 

  std::string error("Object not allocated properly, please use appropriate constructor");
  bool code = false;

  if (eig_sys_io.rows() == 0) {
    std::cout << error << std::endl;
    code = true;
  }

  else if (eig_sys_io.cols() == 0) {
    std::cout << error << std::endl;
    code = true;
  }
  return code;

}

bool EigenIo::check_NB_EV() {

}
