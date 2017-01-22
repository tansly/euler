#include <stdlib.h>
#include <math.h>


/*  generate the sieve of erastothenes with boolean values */
int* sieve(int n)
{
    int i, j, k, limit;
    int* list;
    list = calloc(n - 1, sizeof(int));
    limit = ceil(sqrt(n));
    for (i = 2; i < limit; i++) {
        if (! *(list + i - 2)) {
            for (j = (i * i) - 2, k = 1; j <= n - 2; j = (i * i) + (k * i) - 2, k++) {
                *(list + j) = 1;
            }
        }
    }
    return list;
}


/* puts the array of primes up to n to *ptr, return the number of primes (length of the array)  */
int prime_list(int n, int** ptr)
{
    int i, count = 0;
    *ptr = sieve(n);
    for (i = 0; i < n - 1; i++) {
        if (! *(*ptr + i)) {
            *(*ptr + count) = i + 2;
            count++;
        }
    }
    *ptr = realloc(*ptr, count * sizeof(int));
    return count;
}

int is_prime(long int n)
{
    if (n == 1) {
        return 0;
    } else if (n < 4) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    } else if (n < 9) {
        return 1;
    } else if (n % 3 == 0) {
        return 0;
    } else {
        long int f = 5;
        long int limit = (long int) sqrt(n);
        while (f <= limit) {
            if (n % f == 0) {
                return 0;
            } else if (n % (f + 2) == 0) {
                return 0;
            }
            f += 6;
        }
        return 1;
    }
}
