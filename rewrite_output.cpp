
#include <iostream>
#include <thread>

int main()
{
    std::string str = "Hello!";
    std::cout << str << std::flush;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(500ms);
    std::cout << std::string(str.length(), '\r');
    std::cout << "Hello again!\n";
    // ▓▒░

    uint N = 100;
    for (uint i = 1; i < N; ++i)
    {
        std::cout << "▓";
    }
    std::cout << '\r';

    for (uint i = 1; i < N; ++i)
    {
        // std::cout << '\r';
        // std::cout << i <<std::flush;

        // std::cout << '\r';
        // std::cout << std::string(i, '=') << '>'<< std::flush;

        std::cout << std::string(3, '\b') << std::flush;
        std::cout << "=>░▒";

        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << std::endl;
}
