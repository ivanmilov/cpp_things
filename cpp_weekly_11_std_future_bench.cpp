#include <algorithm>
#include <benchmark/benchmark.h>
#include <charconv>
#include <chrono>
#include <cstring>
#include <future>
#include <iostream>
#include <random>
#include <set>

auto get_size(int num)
{
    std::set<int> ret;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distribution(0, num - 1);

    std::generate_n(std::inserter(ret, ret.end()), num, [&]() { return distribution(gen); });

    return ret.size();
}

const int N = 2;
const int COUNT = 1000;

static void BM_Async(benchmark::State& state)
{
    // Perform setup here
    for (auto _ : state)
    {
        std::vector<std::future<size_t>> vec(N);
        for (int i = 0; i < N; ++i)
            vec[i] = std::async(std::launch::async, get_size, COUNT);
        for (auto& i : vec)
            benchmark::DoNotOptimize(i.get());
    }
}

static void BM_Sync(benchmark::State& state)
{
    // Perform setup here
    for (auto _ : state)
    {
        std::vector<size_t> vec(N);
        for (int i = 0; i < N; ++i)
        {
            vec[i] = get_size(COUNT);
        }
        for (auto& i : vec)
            benchmark::DoNotOptimize(i);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_Async);
BENCHMARK(BM_Sync);

BENCHMARK_MAIN();
