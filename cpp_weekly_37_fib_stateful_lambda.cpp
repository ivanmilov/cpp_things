// https://www.youtube.com/watch?v=_1X9D8Z5huA
// bazel run //:cpp_weekly_37_fib_stateful_lambda -- 1000

// NOTE: doesn't work for the first value, for simplicity

#include <memory> // to make lambda non copyable
#include <iostream>

int main(int argc, char **argv)
{
    ///////////////////////////////////////
    auto l = [a = 0ull, b = 1ull, p = std::make_unique<int>(1)]() mutable {
        a = std::exchange(b, a + b);
        return a;
    };
    ///////////////////////////////////////

    int index = 1;
    if (argc >= 2)
    {
        index = atoi(argv[1]);
    }

    while (index-- > 2)
    {
        l();
    }

    std::cout << argv[1] << " " << l() << std::endl;

    return 0;
}
