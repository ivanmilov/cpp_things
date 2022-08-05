#include <iostream>
#include <map>
#include <memory>
#include <string>

class Foo
{
  public:
    explicit Foo(int index, int* r) : ref{r[index]} {}
    // Foo(Foo&& o) : ref{o.ref} {}
    // Foo(const Foo&) = delete;

    int& ref;
};

class Bar
{
  public:
    // std::map<int, std::unique_ptr<Foo>> m;
    std::map<int, Foo> m;
};

int main()
{
    Bar bar;

    int k = 42;
    int l = 24;

    int arr[2]{42, 24};

    {
        // auto foo = std::make_unique<Foo>(k);
        // bar.m.emplace(1, std::move(foo));
        // auto foo1 = std::make_unique<Foo>(l);
        // bar.m.emplace(2, std::move(foo1));
        Foo foo{0, arr};
        bar.m.emplace(1, std::move(foo));
        Foo foo1{1, arr};
        bar.m.emplace(2, std::move(foo1));
    }
    // std::cout << bar.m[1].ref << std::endl;
    // std::cout << bar.m[2].ref << std::endl;

    arr[0] = 43;
    arr[1] = 25;

    int baz = 783467856;
    int baz1 = 783467856;
    int baz2 = 783467856;
    int baz3 = 783467856;

    for (auto& m : bar.m)
    {
        std::cout << m.second.ref << std::endl;
    }

    if (auto it = bar.m.find(1); it != bar.m.end())
    {
        std::cout << it->second.ref << std::endl;
    }
    return 0;
}
