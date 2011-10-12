template <int n> struct solution4_Sum
{
        enum Value { N = solution4_Sum<n - 1>::N + n};
};
template <> struct solution4_Sum<1>
{
        enum Value { N = 1};
};
