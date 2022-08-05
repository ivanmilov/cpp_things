#include "test_lib_abstract.h"

class MyLib : public TestLibAbstract
{
  public:
    MyLib(std::string name, int v);

    std::string my_foo();
};
