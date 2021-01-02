/*
https://www.youtube.com/watch?v=ZgN1-i095QY
g++ -std=c++2a -O3 foo.cpp -pthread
*/

#include <algorithm>
#include <charconv>
#include <chrono>
#include <cstring>
#include <future>
#include <iostream>
#include <random>
#include <set>

std::string time(std::string_view s = "")
{
    static auto start = std::chrono::steady_clock::now();
    static auto point = start;

    std::chrono::duration<double> d = std::chrono::steady_clock::now() - start;
    std::chrono::duration<double> d1 = std::chrono::steady_clock::now() - point;

    point = std::chrono::steady_clock::now();

    return "[" + std::to_string(d.count()) + "s] [" + std::to_string(d1.count()) + "s]" + std::string(s);
}

auto get_size(int num)
{
    std::set<int> ret;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distribution(0, num - 1);

    std::generate_n(std::inserter(ret, ret.end()), num, [&]() { return distribution(gen); });

    return ret.size();
}

template <class T, class F>
void print(T& c, F f)
{
    for (auto& i : c)
    {
        std::cout << std::invoke(f, i) << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    int N = 2;
    constexpr int COUNT = 1000000;

    if (argc > 1)
    {
        std::from_chars(argv[1], argv[1] + strlen(argv[1]), N);
    }

    std::cout << time("\nasync start:\t") << std::flush;
    {
        std::vector<std::future<size_t>> vec(N);
        for (int i = 0; i < N; ++i)
        {
            vec[i] = std::async(std::launch::async, get_size, COUNT);
        }
        print(vec, [](std::future<size_t>& fut) { return fut.get(); });
    }
    std::cout << time(" async done\nsync start:\t") << std::flush;
    {
        std::vector<size_t> vec(N);
        for (int i = 0; i < N; ++i)
        {
            vec[i] = get_size(COUNT);
        }
        print(vec, [](size_t s) { return s; });
    }
    std::cout << time(" sync done\n");
    return 0;
}
