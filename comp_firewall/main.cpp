#include "test.h"
#include <iostream>

constexpr int constexpr_foo()
{
    return test::const_constexpr_get_int();
}

int foo()
{
    return test::const_get_int() + test::const_constexpr_get_int() + test::get_int();
}

int main()
{
    std::cout << "foo():\t\t\t " << foo() << std::endl;
    std::cout << "constexpr_foo():\t " << constexpr_foo() << std::endl;

    std::cout << "get_int:\t\t " << test::get_int() << std::endl;
    std::cout << "const_get_int:\t\t " << test::const_get_int() << std::endl;
    std::cout << "const_constexpr_get_int: " << test::const_constexpr_get_int() << std::endl;
    return 0;
}
