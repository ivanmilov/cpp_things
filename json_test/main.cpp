#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

struct Foo
{
    bool happy;
    float pi;

    void print() const { std::cout << std::boolalpha << "happy:" << happy << ", pi:" << pi << std::endl; }
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Foo, happy, pi);

enum class E
{
    one = 1,
    two = 2
};
NLOHMANN_JSON_SERIALIZE_ENUM(E, {{E::one, 1}, {E::two, 2}});

struct S
{
    E e;
    std::string s;
    int i;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(S, e, s, i);

void test_enum()
{
    auto j = json::parse(R"({"e": 2, "s": "string", "i":42})", nullptr, false);

    try
    {
        S s = j;
        std::cout << "[ e: " << static_cast<int>(s.e) << ", s: " << s.s << ", i: " << s.i << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    test_enum();

    try
    {
        auto j = json::parse(R"({"happy": true, "pi": 3.141})", nullptr, false);
        auto j1 = json::parse(R"({"happy": )", nullptr, false);
        // std::cout << j << " " << std::boolalpha << j.is_object() << std::endl;
        // std::cout << j << " " << std::boolalpha << static_cast<int>(j.type()) << std::endl;
        // std::cout << j << " " << std::boolalpha << j.is_discarded() << std::endl;

        std::cout << j1 << " " << std::boolalpha << j1.is_object() << std::endl;
        std::cout << j1 << " " << std::boolalpha << static_cast<int>(j1.type()) << std::endl;
        std::cout << j1 << " " << std::boolalpha << j1.is_discarded() << std::endl;
        std::cout << j1 << " " << std::boolalpha << j1.is_null() << std::endl;

        // auto v = j.at("pi").get<float>();
        // // auto v1 = j1.at("pi").get<std::string>();

        // Foo foo = j;
        // foo.print();

        // std::cout << v << std::endl;
        // j.clear();
        // j = {};
        // std::cout << j << " " << j.is_null() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
