// https://www.youtube.com/watch?v=2kY-go52rNw
// bazel run //:cpp_weekly_189_variable_template

#include <iostream>

template <class T>
constexpr auto add = [](const T &lhs, const T &rhs) {
    return lhs + rhs;
};

int main()
{
    std::cout << add<int>(3.14, 2.71) << std::endl;
    std::cout << add<double>(3.14, 2.71) << std::endl;
    return 0;
}
