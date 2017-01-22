#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UPPER 987654321
#define LOWER 123456789

long is_pandigital(long n)
{
    long digits[10] = {0};
    long cnt = 0;
    while (n > 0) {
        digits[n % 10]++;
        n /= 10;
        cnt++;
    }
    if (digits[0] || cnt > 9)
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

long longcat(long a, long b)
{
    long pow_10 = 1;
    while (pow_10 < b) {
        pow_10 *= 10;
    }
    return a * pow_10 + b;
}

int compare_long(const void *a, const void *b)
{
    long diff = (*(long *)a) - (*(long *)b);
    if (diff < 0)
        return -1;
    else if (diff == 0)
        return 0;
    else
        return 1;
}

long sum_tree(Treeptr tree)
{
    if (tree == NULL || tree->data == NULL)
        return 0;
    return (*(long *)(tree->data)) + sum_tree(tree->right) + sum_tree(tree->left);
}

int digit_count(long n)
{
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    Treeptr tree;
    long a, b, c, cat, tmp;
    int a_cnt, b_cnt, c_cnt;
    tree = mktree(sizeof(long), compare_long, NULL);
    for (a = 1; (a_cnt = digit_count(a)) < 5; a++) {
        for (b = a; a_cnt + (b_cnt = digit_count(b)) < 9; b++) {
            c = a * b;
            if (a_cnt + b_cnt + (c_cnt = digit_count(c)) < 9)
                continue;
            else if (a_cnt + b_cnt + c_cnt > 9)
                break;
            tmp = longcat(a, b);
            cat = longcat(tmp, c);
            if (is_pandigital(cat))
                insert(tree, &c);
        }
    }
    printf("%ld\n", sum_tree(tree));
    return 0;
}
