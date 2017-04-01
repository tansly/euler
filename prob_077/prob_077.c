#include <primes.h>
#include <stdlib.h>
#include <stdio.h>

/* Using the non-recursive method from the overview of problem 31.
 * Upper limit was just a wild guess. My initial guess was much much
 * larger, that is why I allocated the ways array on the heap.
 * Although I managed to solve it, I still
 * have to read and think to understand it, this was kind of
 * a copy of the given solution. */
int main(void)
{
    const int limit = 100;
    int *primes, *ways;
    int prime_cnt, i, j;
    prime_cnt = prime_list(limit, &primes);
    ways = calloc(limit, sizeof *ways);
    ways[0] = 1;
    for (i = 0; i < prime_cnt; i++) {
        for (j = primes[i]; j < limit; j++) {
            ways[j] = ways[j] + ways[j - primes[i]];
        }
    }
    for (i = 0; ways[i] < 5000; i++)
        ;
    printf("val: %d, ways: %d\n", i, ways[i]);
    return 0;
}
