// import format;
// #include <format>
#include <iostream>

import foo;

int main()
{
    int num{3};
    auto value = foo::getNum(3);
    // std::cout << std::format("got {} -> {}", num, value);
    std::cout << "got " << num << " -> " << value << std::endl;

    return 0;
}
