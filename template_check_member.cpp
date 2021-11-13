#include <iostream>
#include <type_traits>

// check whether type has a member:

template <typename T, typename = void>
struct has_member : std::false_type
{
};

template <typename T>
struct has_member<T, decltype(std::declval<T>().some_member, void())> : std::true_type
{
};

// ...

template <typename InputType, typename std::enable_if_t<!has_member<InputType>::value, int> = 0>
auto GetSomething(InputType const&)
{
    return;
}

template <typename InputType, typename std::enable_if_t<has_member<InputType>::value, int> = 0>
auto GetSomething(InputType const& data)
{
    return data.some_member;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// check whether type has a member function:

class WithMemFunc
{
  public:
    void call_me() { std::cout << "from class member\n"; }
};

class WithNOMemFunc
{
};

/////  via param
// template <class T>
// void do_smth(
//     T& t, typename std::enable_if_t<std::is_member_function_pointer_v<decltype(&T::call_me)>>* = 0)
// {
//     t.call_me();
// }

///// via non-type template param
// template <class T, typename std::enable_if_t<std::is_member_function_pointer_v<decltype(&T::call_me)>, bool> = true>
// void do_smth(T& t)
// {
//     t.call_me();
// }

/////  via type template param
template <class T, typename = std::enable_if_t<std::is_member_function_pointer_v<decltype(&T::call_me)>>>
void do_smth(T& t)
{
    t.call_me();
}

void do_smth(...)
{
    std::cout << "NOK\n";
}

int main()
{
    WithMemFunc a;
    WithNOMemFunc b;
    do_smth(a);
    do_smth(b);
}
