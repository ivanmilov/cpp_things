// https://www.youtube.com/watch?v=hErD6WGqPlA
// bazel run //:cpp_weekly_13_fib_binet -- 45

#include <cmath>
#include <iostream>
#include <sstream>

constexpr int getFibByIndex(int i)
{
    constexpr auto sqrt_5 = std::sqrt(5);
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;

    return static_cast<int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i)) / (std::pow(2, i) * sqrt_5));
}

int main(int argc, char **argv)
{
    int index = 0;
    if (argc >= 2)
    {
        std::istringstream iss(argv[1]);
        iss >> index;
    }

    std::cout << getFibByIndex(index) << "\n";
    return 0;
}
