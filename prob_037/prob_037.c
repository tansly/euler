#include <stdio.h>
#include <math.h>
#include "primes.h"
#define N 1000000

int digit_count(int n);

int right_trunc(int n);

int left_trunc(int n);

int main()
{
    int *list;
    int i, len, prime, count = 0, sum = 0;
    len = prime_list(N, &list);
    for (i = 4; i < len && count < 11; i++) {
        prime = list[i];
        if (right_trunc(prime) && left_trunc(prime)) {
            sum += prime;
            count++;
        }
    }
    printf("%d\n", sum);
    return 0;
}

int digit_count(int n)
{
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int right_trunc(int n)
{
    while (n > 0) {
        n /= 10;
        if (!is_prime(n)) {
            return 0;
        }
    }
    return 1;
}

int left_trunc(int n)
{
    int d;
    d = digit_count(n);
    while (n > 0) {
        n %= (int) pow(10, d - 1);
        d--;
        if (!is_prime(n)) {
            return 0;
        }
    }
    return 1;
}
