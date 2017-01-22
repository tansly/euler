#include "primes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 1000000

int is_circular(int n)
{
    int i, len, digit_cnt;
    char digits[13];
    char rot[7];
    if (n < 10) {
        return 1;
    }
    len = sprintf(digits, "%d%d", n, n);
    if (strchr(digits, '2') || strchr(digits, '4') || strchr(digits, '5') || \
            strchr(digits, '6') || strchr(digits, '8')) {
        return 0;
    }
    digit_cnt = len / 2;
    for (i = 1; i < digit_cnt; i++) {
        strncpy(rot, digits + i, digit_cnt);
        rot[digit_cnt] = '\0';
        n = atoi(rot);
        if (!is_prime(n)) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int len, i, cnt;
    int *primes;
    len = prime_list(LIMIT, &primes);
    for (i = 0, cnt = 0; i < len; i++) {
        if (is_circular(primes[i]))
            cnt++;
    }
    printf("%d\n", cnt);
    free(primes);
    return 0;
}
