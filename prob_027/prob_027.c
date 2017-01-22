#include "primes.h"
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000

int gen_cons(int a, int b)
{
    int n, r;
    for (n = 1; ; n++) {
        r = ((n * n) + (a * n) + b);
        if (r <= 0 || !is_prime(r)) 
            break;
    }
    return n;
}

int main()
{
    int a, b, max_a = -LIMIT, max_b = 2, curr_seq, max_seq = 0;
    int len_primes;
    int *primes;
    len_primes = prime_list(LIMIT, &primes);
    for (a = -LIMIT; a < LIMIT; a++) {
        for (b = 0; b < len_primes; b++) {
            curr_seq = gen_cons(a, primes[b]);
            if (curr_seq > max_seq) {
                max_seq = curr_seq;
                max_a = a;
                max_b = primes[b];
            }
        }
    }
    printf("%d\n", max_a * max_b);
    free(primes);
    return 0;
}
