#include "my_lib.h"
#include <iostream>

int main()
{
    MyLib l("my_name", 2);

    std::cout << l.my_foo() << std::endl;
    std::cout << l.get_name() << std::endl;
    std::cout << l.get_version() << std::endl;

    return 0;
}
