#include <boos/multi_array.hpp>

typedef boost::multiarray<Eigen::Matrix3cd,2> timeslice;

class Eigensystem {
  public:
    //Default constructor and destructor
    Eigensystem();
    ~Eigensystem();

    //Getter and setter methods for data

  private:
    timeslice;
    Eigen::MatrixXcd eig_vectors;
    Eigen::VectorXd eig_values;
    Eigen::VectorXd phases;
    
    void map(GaugeField* config);
    
}
