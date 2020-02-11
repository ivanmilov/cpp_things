// https://www.fluentcpp.com/2020/02/11/reverse-for-loops-in-cpp/
// https://stackoverflow.com/questions/60168623/error-conflicting-declaration-using-universal-references

#include <iostream>
#include <vector>
#include <functional>

template <typename T>
class Reverse
{
    T& iterable_;  
public:
    explicit Reverse( T& iterable) : iterable_(iterable){}    
    
    auto begin() { return std::rbegin(iterable_); }
    auto end() { return std::rend(iterable_); }
};

template <typename T>
class ReverseMove
{
    T iterable_;  
public:
    explicit ReverseMove(T iterable) : iterable_(std::move(iterable)){}    
    
    auto begin() { return std::rbegin(iterable_); }
    auto end() { return std::rend(iterable_); }
};

template <typename T>
class ReverseUniversal
{
    T iterable_;  
public:
    template<typename F = T>
    explicit ReverseUniversal(F&& iterable) : iterable_(std::forward<T>(iterable)){}
    
    auto begin() { return std::rbegin(iterable_); }
    auto end() { return std::rend(iterable_); }
};

std::vector<int> CreateVector()
{
    return {0,1,2,3,4,5,6,7,8,9};
}

template<typename T>
ReverseUniversal(T) -> ReverseUniversal<T>;

int main()
{
    std::vector<int> v{1,2,3,4,5,6,7};
    
    for(const auto& i : Reverse(v))
        std::cout << i << " ";
    std::cout << std::endl;
        
    for(const auto& i : ReverseMove(CreateVector()))
        std::cout << i << " "; 
    std::cout << std::endl;
    
    for(const auto& i : ReverseUniversal(CreateVector()))
        std::cout << i << " "; 
    std::cout << std::endl;
    
    // ReverseUniversal{v};
    for(const auto& i : ReverseUniversal{v})
        std::cout << i << " "; 
    std::cout << std::endl;
        
    return 0;    
}
