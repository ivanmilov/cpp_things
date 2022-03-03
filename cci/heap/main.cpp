#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

inline namespace helper
{
int get_left_ch_index(int n)
{
    return 2 * n + 1;
}
int get_right_ch_index(int n)
{
    return 2 * n + 2;
}
int get_parent_index(int n)
{
    return round((n - 1) / 2);
}
} // namespace helper

template <class T>
struct HeapMax
{
    std::vector<T> vec;

    bool empty() const { return vec.empty(); }
    auto size() const { return vec.size(); }

    void insert(T v)
    {
        vec.push_back(v);
        const auto sz = size();
        auto new_id = sz - 1;

        auto parent_id = get_parent_index(new_id);
        while (parent_id < sz and vec[parent_id] < v)
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
            if (ch_id < sz and vec[ch_id] > vec[new_id])
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

    void print()
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

int main()
{
    HeapMax<int> h;

    h.print();
    h.insert(3);
    h.print();

    h.insert(1);
    h.print();

    h.insert(2);
    h.print();
    h.insert(4);
    h.print();

    h.insert(7);
    h.print();

    h.insert(2);
    h.print();

    for (; not h.empty(); h.pop())
    {
        h.print();
    }

    return 0;
}
