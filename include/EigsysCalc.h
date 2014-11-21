#ifndef EIGSYS_CALC_H_
#define EIGSYS_CALC_H_

class EigsysCalc {

  public:
    //Constructor
    //Takes as arguments the number of eigenvectors and the 3dvolume
    EigsysCalc(const size_t nev; const size_t v3);
    //Destructor
    ~EigsysCalc();
    //Copy Constructor
    //Assignement Constructor
    //Move Constructor
    //Get and set methods for eigensystem
    inline const Eigen::MatrixXcd& operator()(const size_t index_ev){
      return eigensys.col(nev);
    }
    //Vectorwise set function Arguments are index of the eigenvector, id for
    //what should be written, and pointer to the data to be mapped
    void set(const size_t index_ev, const char* id, const Eigen::Matrix* data); 
  private:
  
  Eigen::MatrixXcd eigensys;
  Eigen::VectorXd eigenvals;
  Eigen::VectorXd phases;

};



#endif //EIGSYS_CALC_H_
