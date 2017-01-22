#include <stdio.h>
#include <stdlib.h>

/* calculates 10 to the power n */
int ipow10(int n)
{
    int res = 1;
    while (n--) {
        res *= 10;
    }
    return res;
}

/* returns the dth digit from the of n
 * indexing starts from 1 */
int get_digit(int n, int d)
{
    n /= ipow10(d - 1);
    return n % 10;
}

int main(int argc, char **argv)
{
    int result = 1;
    int digit_incr = 1;
    int n, digit_ind;
    int target = 10;
    int limit = 1000000;
    if (argc > 1) {
        limit = atoi(*++argv);
    }
    for (n = 2, digit_ind = 1; digit_ind <= limit; n++) {
        if (n % ipow10(digit_incr) == 0) {
            digit_incr++;
        }
        digit_ind += digit_incr;
        if (digit_ind >= target) {
            result *= get_digit(n, digit_ind - target + 1);
            target *= 10;
        }
    }
    printf("%d\n", result);
    return 0;
}
