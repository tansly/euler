#include <stdio.h>
#include "include/primes.h"

int main()
{
    long int sum = 0;
    int n = 2000000;
    int i;
    int* primes;
    n = prime_list(n, &primes);
    for (i = 0; i < n; i++) {
        sum += *(primes + i);
    }
    printf("%ld\n", sum);
    return 0;
}
