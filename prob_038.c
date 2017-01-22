#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOWER 100
#define UPPER 500

/*  THIS IS INCOMPLETE
 *  SOLVED BY PEN AND PAPER */

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

char *itoa(int n)
{
    char *str = calloc(10, sizeof(*str));
    sprintf(str, "%d", n);
    return str;
}


int cat_prod(int n)
{
    char *tmp, *result;
    tmp = itoa(n);
    result = calloc(10, sizeof(*result));
    strcat(result, tmp);
    free(tmp);
    tmp = itoa(n * 2);
    strcat(result, tmp);
    free(tmp);
    tmp = itoa(n * 3);
    strcat(result, tmp);
    free(tmp);
    n = atoi(result);
    free(result);
    return n;
}

int main()
{
    int max = 0, curr, n;
    for (n = LOWER; n < UPPER; n++) {
        curr = cat_prod(n);
        if (curr > max && is_pandigital(curr)) {
            printf("%d\n", curr);
            max = curr;
        }
    }
    return 0;
}
