#include "widget.h"
#include <iostream>

int main()
{
    widget w("mew");

    std::cout << w.get_name() << std::endl;
    return 0;
}
