#include <atomic>
#include <cmath>
#include <experimental/atomic>
#include <iostream>
#include <memory>
#include <sstream>
#include <thread>

int main()
{
    std::experimental::atomic_shared_ptr<int> p;
    // std::atomic_shared_ptr<int> p;

    p = 1;

    return p;
}
