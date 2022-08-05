#include <assert.h>
#include <atomic>
#include <iostream>
#include <thread>
std::atomic<bool> x, y;
void func_1()
{
    x.store(true, std::memory_order_relaxed);
}
void func_2()
{
    y.store(true, std::memory_order_relaxed);
}
void func_3()
{
    while (!x.load(std::memory_order_relaxed))
        ;
    if (y.load(std::memory_order_relaxed))
    {
        std::cout << "x == true then also y == true \n";
    }
    else
        std::cout << "HUY 1\n";
}
void func_4()
{
    while (!y.load(std::memory_order_relaxed))
        ;
    if (x.load(std::memory_order_relaxed))
    {
        std::cout << "y == true then also x == true \n";
    }
    else
        std::cout << "HUY 2\n";
}
// It is possible that neither func_3 or func_4 executes print out.
int main()
{
    // for (int i{0}; i < 100; ++i)
    // {
    std::cout << "------------------\n";
    x = false;
    y = false;
    std::thread thread_1(func_1);
    std::thread thread_2(func_2);
    std::thread thread_3(func_3);
    std::thread thread_4(func_4);
    thread_1.join();
    thread_2.join();
    thread_3.join();
    thread_4.join();
    // }
}
