// https://www.youtube.com/watch?v=hErD6WGqPlA

#include <iostream>

template <int I>
struct Fib
{
    static const int val = Fib<I - 1>::val + Fib<I - 2>::val;
};

template <>
struct Fib<0>
{
    static const int val = 0;
};

template <>
struct Fib<1>
{
    static const int val = 1;
};

int main()
{
    std::cout << Fib<45>::val << "\n";
    return 0;
}
