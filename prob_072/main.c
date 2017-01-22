#include "/home/tansly/include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* modified sieve of Eratosthenes
 * for integers less than the parameter last
 * generates an array of linked list,
 * where each linked list stores the primes dividing the index */
struct node **sieve(int last)
{
    struct node **arr = calloc(last, sizeof *arr);
    int i, j;
    // for consistency, manually push the divisors of 0 and 1
    push(&arr[0], 0);
    push(&arr[1], 1);
    for (i = 2; i < last; i++) {
        if (arr[i] == NULL) { // this is a prime
            // start crossing multiples
            // and push the prime to the linked lists
            // note that we start from i * 2
            // that is because we need to store the prime i for all -
            // elements crossed by i
            for (j = i * 2; j < last; j += i) {
                push(&arr[j], i);
            }
        }
    }
    return arr;
}

/* take n and the list of primes dividing n
 * return the totient of n */
long totient(int n, struct node *primes)
{
    double prod;
    if (primes == NULL) { // prime number
        return n - 1;
    }
    for (prod = n; primes != NULL; primes = primes->next) {
        prod *= 1 - 1 / (double) primes->data;
    }
    return prod;
}

int main(int argc, char **argv)
{
    struct node **arr;
    int i, last;
    long sum;
    if (argc != 2) {
        return 1;
    }
    last = atoi(*++argv) + 1;
    arr = sieve(last);
    for (i = 2, sum = 0; i < last; i++) {
        sum += totient(i, arr[i]);
    }
    printf("%ld\n", sum);
    for (i = 0; i < last; i++) {
        rmlist(&arr[i]);
    }
    free(arr);
    return 0;
}
