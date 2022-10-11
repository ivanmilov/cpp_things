#include <iostream>
#include <map>
#include <sstream>
#include <utility>

enum class Op
{
    none,
    s1,
    s3,
    d
};

struct Stack
{
    void add(std::string_view sv)
    {
        l++;
        s += sv;
    }
    void append(const Stack& st)
    {
        l += st.l;
        s += st.s;
    }
    void final(std::string_view sv) { s += sv; }
    auto get() const { return std::make_pair(l, s); }

    int l{};
    std::string s{};
};
inline std::ostream& operator<<(std::ostream& os, const Stack& s)
{
    os << "[steps: " << s.l << "]: " << s.s;
    return os;
}

std::multimap<int, Stack> stacks;
std::map<int, Stack> solutions;

int min_stack()
{
    if (stacks.empty())
        return 100000;
    return stacks.upper_bound(0)->first;
}

inline std::ostream& operator<<(std::ostream& os, const Op op)
{
    switch (op)
    {
    case Op::none:
        os << "none; ";
        break;
    case Op::s1:
        os << "-1";
        break;
    case Op::s3:
        os << "-3";
        break;
    case Op::d:
        os << "/3";
    }
    return os;
}

inline std::string opstr(Op op)
{
    std::stringstream ss;
    ss << op;
    return ss.str();
}

void foo(int N, int cur, Op op, Stack s)
{
    if (s.l > min_stack())
        return;

    if (auto sol = solutions.find(cur); sol != solutions.end())
    {
        auto st = sol->second;
        s.append(st);
        stacks.insert(std::make_pair(s.l, s));
        return;
    }

    if (cur == 0)
    {
        s.final("0");
        stacks.insert(std::make_pair(s.l, s));
        // std::cout << "done " << s.get().first << ": " << s.get().second << "\n";
        return;
    }

    if (cur < 0)
    {
        // std::cout << "NEG: " << cur << ": " << s.get().second << "\n";
        return;
    }

    if (op != Op::none)
        s.add("(" + std::to_string(cur) + opstr(op) + ")->");

    int next = cur;
    switch (op)
    {
    case Op::none:
        foo(N, cur, Op::s1, s);
        foo(N, cur, Op::s3, s);
        foo(N, cur, Op::d, s);
        break;
    case Op::s1:
        next = cur - 1;
        foo(N, next, Op::none, s);
        break;
    case Op::s3:
        next = cur - 3;
        foo(N, next, Op::none, s);
        break;
    case Op::d:
        if (cur % 3 == 0)
        {
            next = cur / 3;
            foo(N, next, Op::none, s);
        }
        break;
    }
}

void bar(int N)
{
    for (int i{1}; i <= N; ++i)
    {
        foo(i, i, Op::none, {});
        auto f = stacks.upper_bound(0);

        if (f != stacks.end())
        {
            solutions[i] = f->second;
            stacks.clear();
        }
    }
}

int main(int argc, char** argv)
{
    int N = atoi(argv[1]);
    bar(N);

    auto sol = solutions[N];
    std::cout << "sol for " << N << ": " << sol << std::endl;

    return 0;
}
