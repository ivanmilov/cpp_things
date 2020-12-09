// https://www.youtube.com/watch?v=2kY-go52rNw
// bazel run //:cpp_weekly_189_fib_variable_template

#include <iostream>

template <int Value>
constexpr auto fib = fib<Value - 1> + fib<Value - 2>;

template <>
constexpr auto fib<1> = 1ull;

template <>
constexpr auto fib<0> = 0ull;

int main()
{
    std::cout << fib<500> << std::endl;
    return 0;
}
