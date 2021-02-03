#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> f{3, 4, 5};

    auto res = std::search(v.begin(), v.end(), f.begin(), f.end());

    auto res1 = std::ranges::search(v, f);

    std::cout << std::distance(v.begin(), res) << " " << std::distance(v.begin(), res1.begin()) << std::endl;
    return std::distance(v.begin(), res);
}
