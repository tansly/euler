#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_perm(int a, int b)
{
    int i;
    int digits[10] = {0};
    while (a > 0) {
        digits[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        digits[b % 10]--;
        b /= 10;
    }
    for (i = 0; i < 10; i++) {
        if (digits[i] != 0)
            return 0;
    }
    return 1;
}

int check(int n)
{
    int k;
    for (k = 1; k < 6; k++) {
        if (!is_perm(n * k, n * (k + 1)))
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    for (n = 1; ; n++) {
        if (check(n)) {
            printf("%d\n", n);
            break;
        }
    }
    return 0;
}
