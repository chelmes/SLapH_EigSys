//Functions to read and write from and to files. Implemented as Cheshire Cat, We
//are all mad here

#ifndef _POTTSTILL_H_
#define _POTTSTILL_H_

#include <cstdlib>
#include <memory>

class DataIO {
  public:
    DataIO();
    ~DataIO();
    // Reads in gauge configuration from lime format into array
    virtual void read_gauge_cfg();
    // writes the eigenvectors to binary format.
    // Eigenvectors are written per timeslice ordered by their eigenvalues
    // from lowest to NEVth eigenvalue
    virtual void write_evecs();
    // writes the eigenvalues to binary format
    // same storage layout as for the eigenvectors
    virtual void write_evals();
    // Same story for the eigenvalues
    virtual void write_phases();

  private:
    class read_write;
    std::unique_ptr<read_write> smile;
};
#endif //_POTTSTILL_H_
