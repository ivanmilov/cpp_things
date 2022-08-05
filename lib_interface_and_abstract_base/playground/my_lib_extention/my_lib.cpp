#include "my_lib.h"

MyLib::MyLib(std::string name, int v) : TestLibAbstract(name, v)
{
}

std::string MyLib::my_foo()
{
    return name + " " + std::to_string(version);
}
