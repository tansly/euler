#include <iostream>

/* Compile with -ftemplate-depth=1000
 */

template <int N>
struct is_multiple {
    static const bool result = N % 3 == 0 || N % 5 == 0;
};

template <int N>
struct sum_multiples {
    static const int result = (is_multiple<N>::result ? N : 0) +
        sum_multiples<N - 1>::result;
};

template <>
struct sum_multiples<0> {
    static const int result = 0;
};

int main()
{
    std::cout << sum_multiples<999>::result << std::endl;
    return 0;
}
