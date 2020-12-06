// https://www.youtube.com/watch?v=_1X9D8Z5huA
// bazel run //:cpp_weekly_37_fib_stateful_lambda_ext -- 1000

#include <memory> // to make lambda non copyable
#include <iostream>

int main(int argc, char **argv)
{
    ///////////////////////////////////////
    auto l = [a = 0ull, b = 1ull, p = std::make_unique<int>(1)]() mutable {
        struct Result
        {
            unsigned long long &a;
            unsigned long long &b;

            Result next(int num = 1)
            {
                while (num-- > 0)
                {
                    a = std::exchange(b, a + b);
                }
                return *this;
            }

            operator unsigned long long() { return a; }
        };
        return Result{a, b};
    };
    ///////////////////////////////////////

    int index = 1;
    if (argc >= 2)
    {
        index = atoi(argv[1]);
    }

    std::cout << argv[1] << " " << l().next(index) << std::endl;

    return 0;
}
