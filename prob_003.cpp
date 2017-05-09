#include <iostream>

/* I guess this is not an efficient solution and
 * I do not know if most of this mess is required, but
 * it still compiles fine with -ftemplate-depth=6860
 * under a second on my machine.
 */

template <long N, long F, bool B>
struct LargestFactor {
    static const long result = LargestFactor<N, F, B>::result;
};

template <long N, long F>
struct LargestFactor<N, F, true> {
    static const long result =
        LargestFactor<N / F, F, (N / F) % F == 0>::result;
};

template <long N, long F>
struct LargestFactor<N, F, false> {
    static const long result =
        LargestFactor<N, F + 1, N % (F + 1) == 0>::result;
};

template <long F>
struct LargestFactor<1, F, true> {
    static const long result = F;
};

template <long F>
struct LargestFactor<1, F, false> {
    static const long result = F;
};

int main()
{
    const long num = 600851475143;
    std::cout << LargestFactor<num, 2, num % 2 == 0>::result << std::endl;
    return 0;
}
