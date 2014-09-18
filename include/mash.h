//Class holding the eigensystem data. Maintained are one timeslice
#ifndef _MASH_H_
#define _MASH_H_

#include <boos/multi_array.hpp>
#include <Eigen/Eigen/unsupported>

typedef boost::multiarray<Eigen::Matrix3cd,2> timeslice;

class Eigensys_dat {
  public:
    //Default constructor and destructor
    Eigensys_dat();
    ~Eigensys_dat();

    //Getter and setter methods for data

  private:
    timeslice gauge_field;
    Eigen::MatrixXcd eig_vectors;
    Eigen::VectorXd eig_values;
    Eigen::VectorXd phases;

}
#endif //_MASH_H_
