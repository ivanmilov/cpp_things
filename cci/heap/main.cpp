#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

inline namespace helper
{
size_t get_left_ch_index(int n)
{
    return 2 * n + 1;
}
size_t get_right_ch_index(int n)
{
    return 2 * n + 2;
}
size_t get_parent_index(int n)
{
    return round((n - 1) / 2);
}
} // namespace helper

template <class T, class Comp = std::less<>>
class Heap
{
    std::vector<T> vec;
    Comp comp;

  public:
    bool empty() const { return vec.empty(); }
    auto size() const { return vec.size(); }

    void insert(T v)
    {
        vec.push_back(v);
        const auto sz = size();
        auto new_id = sz - 1;

        auto parent_id = get_parent_index(new_id);
        while (parent_id < sz and comp(vec[parent_id], v))
        {
            std::swap(vec[parent_id], vec[new_id]);
            new_id = parent_id;
            parent_id = get_parent_index(new_id);
        }
    }

    void pop()
    {
        if (empty())
            return;

        std::swap(vec.front(), vec.back());
        vec.pop_back();

        auto new_id{0};

        auto check_and_swap_child = [&new_id, sz = size(), this](auto ch_id) {
            if (ch_id < sz and comp(vec[new_id], vec[ch_id]))
            {
                std::swap(vec[ch_id], vec[new_id]);
                new_id = ch_id;
                return true;
            }
            return false;
        };

        while (true)
        {
            auto l_ch = get_left_ch_index(new_id);
            auto r_ch = get_right_ch_index(new_id);

            if (check_and_swap_child(l_ch))
                continue;
            if (check_and_swap_child(r_ch))
                continue;
            break;
        }
    }

    const T& top() const { return vec.front(); }

    void print() const
    {
        if (empty())
            return;

        for (auto& el : vec)
        {
            std::cout << el << " ";
        }
        std::cout << '\n';
    }
};

template <class T>
using HeapMax = Heap<T, std::less<>>;
template <class T>
using HeapMin = Heap<T, std::greater<>>;

int main()
{
    HeapMax<int> h;

    for (auto i : {3, 1, 2, 4, 7, 2})
    {
        h.print();
        h.insert(i);
    }
    h.print();

    for (; not h.empty(); h.pop())
    {
        h.print();
    }

    return 0;
}
