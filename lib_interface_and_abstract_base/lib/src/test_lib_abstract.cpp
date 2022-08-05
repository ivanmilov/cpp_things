#include "test_lib_abstract.h"

TestLibAbstract::TestLibAbstract(std::string name, int version) : name{name}, version{version}
{
}

std::string TestLibAbstract::get_name() const
{
    return name;
}
int TestLibAbstract::get_version() const
{
    return version;
}
