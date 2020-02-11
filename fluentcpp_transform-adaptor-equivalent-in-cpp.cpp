#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cmath>

struct Point
{
    double x;
    double y;
};

template <typename Func>
auto proj(Func func)
{
    return [func](const auto& input)
    {
        using value_type = decltype(input.front());
        using func_ret_type = std::invoke_result_t<Func, value_type>; 
        auto results = std::vector<std::decay_t<func_ret_type>>{};
        
        results.reserve(input.size());
        for(const auto& i: input)
        {
            results.push_back(std::invoke(func, i));
        }
        
        return results;
    };
}

int main()
{
    auto f = [](Point p)-> double { return sqrt(p.x*p.x + p.y*p.y);};
    
    std::vector<Point> points{{3,4}, {6,8}, {9,12}, {12,16}};    
    
    auto res = proj(f)(points);
    
    for(const auto& r: res)
    {
        std::cout << r << std::endl;
    }
    
}
