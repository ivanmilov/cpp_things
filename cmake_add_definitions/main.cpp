#include <iostream>

void foo()
{
#ifdef MY_DEF
    std::cout << "MY_DEF defined!" << std::endl;
#else
    std::cout << "MY_DEF NOT defined!" << std::endl;
#endif
}

int main()
{
    foo();
    return 0;
}
