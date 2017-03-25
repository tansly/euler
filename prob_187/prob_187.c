#include <primes.h>
#include <stdlib.h>
#include <stdio.h>

#define LIMIT 100000000

int main()
{
    int *primes;
    int prime_cnt, res, i;
    prime_cnt = prime_list(LIMIT / 2, &primes);
    for (i = 0, res = 0; primes[i] * primes[i] < LIMIT; i++) {
        int j;
        for (j = i; j < prime_cnt && primes[i] * primes[j] < LIMIT; j++) {
            res++;
        }
    }
    printf("%d\n", res);
    free(primes);
    return 0;
}
