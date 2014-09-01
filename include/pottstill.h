#ifndef _POTTSTILL_H_
#define _POTTSTILL_H_

#include <cstdlib>
#include <memory>

class DataIO {
  public:
    DataIO();
    ~DataIO();
    void read();
  private:
    class read_write;
    std::unique_ptr<read_write> pimpl;
};
#endif //_POTTSTILL_H_
