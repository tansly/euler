#include <stdio.h>

int main()
{
    long int result = 1;
    int n;
    for (n = 0; n < 7830457; n++) {
        result *= 2;
        result = result % 10000000000;
    }
    result *= 28433;
    result += 1;
    result = result % 10000000000;
    printf("%ld\n", result);
    return 0;
}
