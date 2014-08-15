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
