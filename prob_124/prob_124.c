#include <stdio.h>
#include "primes.h"
#include "sort.h"
#define N 100000

struct rad_n radical(int n, int *primes, int len)
{
    int i, p;
    struct rad_n result;
    result.rad = 1;
    result.n = n;
    for (i = 0; (p = primes[i]) <= n && i < len; i++) {
        if (n % p == 0) {
            result.rad *= p;
        }
    }
    return result;
}

int main()
{
    int *primes;
    int n, len;
    struct rad_n rad_array[N];
    rad_array[0].rad = 1;
    rad_array[0].n = 1;
    len = prime_list(N + 1, &primes);
    for (n = 2; n <= N; n++) {
        inserti(radical(n, primes, len), rad_array, n - 1);
    }
    printf("%d\n", rad_array[9999].n);
    return 0;
}
