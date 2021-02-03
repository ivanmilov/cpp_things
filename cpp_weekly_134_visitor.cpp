// https://www.youtube.com/watch?v=EsUmnLgz8QY
#include <iostream>
#include <variant>

template <typename... Base>
struct Visitor : Base...
{
    using Base::operator()...;
};

template <typename... T>
Visitor(T...) -> Visitor<T...>;

int main()
{
    constexpr Visitor visitor{[](double d) -> int { return d + 1.3; }, [](int i) -> int { return i + 2; },
                              [](std::string s) -> int { return s.size(); }};

    /* constexpr */ auto v = std::variant<double, int, std::string>{1.7};

    std::cout << std::visit(visitor, v) << std::endl;

    v = 5;
    std::cout << std::visit(visitor, v) << std::endl;

    v = "Hello world";
    std::cout << std::visit(visitor, v) << std::endl;

    return 0;
}
