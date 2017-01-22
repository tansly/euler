#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 10000
/* limit is a shot in the dark */

void reverse(char *s)
{
    size_t i, j;
    char tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}


int next_perm(char *s)
{
    int i = 0, k = -1, x;
    for (x = 0; s[x + 1] != '\0'; x++) {
        if (s[x] < s[x + 1])
            k = x;
    }
    if (k == -1)
        return 0;
    for (x = k + 1; s[x] != '\0'; x++) {
        if (s[k] < s[x])
            i = x;
    }
    char tmp;
    tmp = s[i];
    s[i] = s[k];
    s[k] = tmp;
    reverse(s + k + 1);
    return 1;
}

/*  generate an array of the cubes of the numbers up to lim 
 *  terminate the array with -1 */
unsigned long *gen_cubes(unsigned long lim)
{
    unsigned long *cubes;
    unsigned long i;
    cubes = malloc((lim + 1) * sizeof *cubes);
    for (i = 0; i < lim; i++)
        cubes[i] = i * i * i;
    cubes[lim] = -1;
    return cubes;
}

/* returns -1 if digit counts are different
 * returns 0 if digit counts match, but not permutations of each other
 * returns 1 if permutations of each other */
int is_perm(unsigned long x, unsigned long y)
{
    int digits[10] = {0};
    int cnt = 0;
    while (x > 0) {
        digits[x % 10]++;
        cnt++;
        x /= 10;
    }
    while (y > 0) {
        digits[y % 10]--;
        cnt--;
        y /= 10;
    }
    if (cnt != 0)
        return -1;
    int i;
    for (i = 0; i < 10; i++) {
        if (digits[i] != 0)
            return 0;
    }
    return 1;
}

/* returns the number of permutations of the number in the given idx 
 * puts 0 in place of permutations of the number in the given idx
 * returns 0 if the number is a permutation of a previously checked number */
int count_perms(unsigned long *cubes, int idx)
{
    if (cubes[idx] == 0)
        return 0;
    int cnt = 1;
    int i, flag;
    for (i = idx + 1; cubes[i] != -1; i++) {
        if (cubes[i] == 0)
            continue;
        flag = is_perm(cubes[idx], cubes[i]);
        if (flag == 1) {
            cnt++;
            cubes[i] = 0;
        } else if (flag == -1) {
            // digit counts do not match, no more permutations after that
            return cnt;
        }
    }
    return cnt;
}

int main(int argc, char **argv)
{
    unsigned long *cubes = gen_cubes(LIMIT);
    int i;
    for (i = 1; cubes[i] != -1; i++) {
        if (count_perms(cubes, i) == 5) {
            printf("%lu\n", cubes[i]);
            break;
        }
    }
    free(cubes);
    return 0;
}
