// https://www.youtube.com/watch?v=hErD6WGqPlA
// bazel run //:cpp_weekly_13_fib_template -- 45

#include <iostream>
#include <array>
#include <sstream>

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

template <size_t... I>
int fibImpl(std::index_sequence<I...>, int i)
{
    constexpr std::array<int, sizeof...(I)> a = {Fib<I>::val...};
    return a[i];
}

int getFibByIndex(int i)
{
    return fibImpl(std::make_index_sequence<47>(), i); // fib 46 is max int
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
