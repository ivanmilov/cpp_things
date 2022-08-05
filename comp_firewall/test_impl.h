#pragma once

namespace test
{
int get_int()
{
    return 1;
}
const int const_get_int()
{
    return 2;
}
const int const_constexpr_get_int() // NOTE: no constexpr here
{
    return 4;
}
} // namespace test
