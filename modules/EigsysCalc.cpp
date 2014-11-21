#include "malt.h"
#include "EigsysCalc.h"


void EigsysCalc::set(const size_t index_ev, const char* id, const Eigen::Matrix* data) {
  if(id=="vec"){
    eigensys.col(index_ev) = data;
  }
  else if (id =="val"){
    eigenvals=data;
  }
  else if(id=="pha"){
    phases=data;
  }
  else{std::cout <<"id not known, please check arguments..."}
}

void EigsysCalc::init() {

}

void EigsysCalc::setup() {
}

void EigsysCalc::calc() {
}

void EigsysCalc::save() {
}
