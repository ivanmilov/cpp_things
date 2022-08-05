#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;
class Solution
{
  public:
    enum class State
    {
        none,
        left,
        right
    };
    struct Last
    {
        Last(size_t i, State s) : i{i}, s{s} {}
        size_t i;
        State s;
    };
    bool is_even(size_t n) { return n % 2 == 0; }
    string pushDominoes(string d)
    {
        const char l{'L'};
        const char r{'R'};
        const char u{'.'};

        State s{State::none};
        Last last{0, State::none};

        for (size_t i{0}; i < d.size(); ++i)
        {
            const auto cur = d[i];
            if (cur != u)
            {
                if (cur == l)
                {
                    // left all prev
                    if (State::none == last.s)
                    {
                        d.replace(last.i, i - last.i, i - last.i, l);
                        last = {i, State::left};
                    }
                    else if (State::left == last.s)
                    {
                        d.replace(last.i, i - last.i, i - last.i, l);
                        last = {i, State::left};
                    }
                    else if (State::right == last.s)
                    {
                        const auto diff = i - 1 - last.i;
                        const auto add_one = is_even(diff) ? 0 : 1;
                        d.replace(last.i + 1, diff / 2, diff / 2, r);
                        d.replace(last.i + 1 + add_one + diff / 2, diff / 2, diff / 2, l);

                        last = {i, State::left};
                    }
                    continue;
                }
                if (cur == r)
                {
                    if (State::right == last.s)
                    {
                        d.replace(last.i, i - last.i, i - last.i, r);
                    }

                    last = {i, State::right};
                }
            }
        }
        if (State::right == last.s)
        {
            d.replace(last.i, d.size() - last.i, d.size() - last.i, r);
        }

        return d;
    }
};
int main()
{
    auto run = [](std::string s, const std::string& exp = {}) {
        Solution sol;
        auto res = sol.pushDominoes(s);
        std::cout << s << " -> " << res /* << "\n-------" */ << std::endl;
        if (not exp.empty())
        {
            if (exp != res)
                std::cerr << "\t\tERR!: " << res << " != " << exp << std::endl;
        }
    };
    run("...L", "LLLL");
    run("L..L", "LLLL");
    run("R..L", "RRLL");
    run("R...L", "RR.LL");
    run("...R", "...R");
    run("L..R", "L..R");
    run("R..R", "RRRR");
    run("RR.L", "RR.L");
    run(".L.R...LR..L..", "LL.RR.LLRRLL..");
    run(".L.R...LR...L..", "LL.RR.LLRR.LL..");
    run(".L.R.", "LL.RR");
    return 0;
}
