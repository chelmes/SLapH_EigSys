#ifndef _BARLEY_H_
#define _BARLEY_H_

#include <array>

class Gaugeconf {

  public:
    Gaugeconf();
    ~Gaugeconf();
  private:
  //Memory for one complete configuration
    std::array <double> gauge_cfg;
};
#endif //_BARLEY_H_
