export module foo;

namespace foo
{
constexpr int FACTOR{2};

auto applyFactor(int num)
{
    return num * FACTOR;
}

export auto getNum(int num)
{
    auto factored = applyFactor(num);
    return factored;
}

} // namespace foo
