//Header File holding the Eigensystem 
#ifndef _MASH_H_
#define _MASH_H_

#include <boos/multi_array.hpp>
#include <Eigen/Eigen/unsupported>

typedef boost::multiarray<Eigen::Matrix3cd,2> timeslice;

class Eigensystem {
  public:
    //Default constructor and destructor
    Eigensystem();
    ~Eigensystem();

    //Getter and setter methods for data

  private:
    timeslice gauge_field;
    Eigen::MatrixXcd eig_vectors;
    Eigen::VectorXd eig_values;
    Eigen::VectorXd phases;
    
    void map(GaugeField* config);
    
}
#endif //_MASH_H_
