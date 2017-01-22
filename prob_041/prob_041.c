#include "primes.h"
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 7654321

int is_pandigital(int n)
{
    int digits[10] = {0};
    int cnt = 0;
    while (n > 0) {
        digits[n % 10]++;
        n /= 10;
        cnt++;
    }
    if (digits[0])
        return 0;
    for (n = 1; n <= cnt; n++) {
        if (digits[n] != 1)
            return 0;
    }
    for (/* n = cnt + 1 */ ; n < 10; n++) {
        if (digits[n])
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    for (n = LIMIT; n >= 2; n--) {
        if (is_pandigital(n) && is_prime(n)) {
            printf("%d\n", n);
            break;
        }
    }
    return 0;
}
