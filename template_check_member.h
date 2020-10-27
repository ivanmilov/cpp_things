// check whether type has a member:

template <typename T, typename = void>
struct has_member : std::false_type
{
};

template <typename T>
struct has_member<T, decltype(std::declval<T>().some_member, void())> : std::true_type
{
};

...

template <typename InputType, typename std::enable_if_t<!has_member<InputType>::value, int> = 0>
auto GetSomething(InputType const&)
{
    return none;
}

template <typename InputType, typename std::enable_if_t<has_member<InputType>::value, int> = 0>
auto GetSomething(InputType const& data)
{
    return data.some_member;
}
