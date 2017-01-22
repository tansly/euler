#include <stdio.h>
#define N_LOWER 319421985L
#define SQR_UPPER 1929394959697989990L

int check(long n)
{
    int i = 10;
    while ((n > 0) && ((n - i) % 10 == 0)) {
        n /= 100;
        i--;
    }
    return n == 0 && i == 0;
}

int main()
{
    long n;
    for (n = N_LOWER; n * n < SQR_UPPER; n++) {
        if (check(n * n)) {
            printf("%ld\n", n);
            break;
        }
    }
    return 0;
}
