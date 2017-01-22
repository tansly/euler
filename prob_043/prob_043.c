#include "list.h"
#include <stdio.h>

struct node *gen_list(void)
{
    int i;
    struct node *lst = NULL;
    for (i = 9; i > 1; i--)
        push(&lst, i);
    push(&lst, 0);
    push(&lst, 1);
    return lst;
}

long make_integer(struct node *lst, int start, int end)
{
    static int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    struct node *pos;
    long n;
    int i;
    pos = slicelist(lst, start);
    for (n = 0, i = end - start; i >= 0; i--) {
        n += pos->data * powers[i];
        pos = pos->next;
    }
    return n;
}

/* checks the current permutation
 * returns the number if it satisfies the description
 * returns 0 otherwise */
long check(struct node *lst)
{
    static int primes[] = {2, 3, 5, 7, 11, 13, 17};
    int i;
    long n;
    for (i = 0; i < 7; i++) {
        n = make_integer(lst, i + 1, i + 3);
        if (n % primes[i] != 0)
            return 0;
    }
    return make_integer(lst, 0, 9);
}

int main(void)
{
    int flag;
    long sum;
    struct node *lst;
    lst = gen_list();
    for (flag = 1, sum = 0; flag; flag = narayana(lst))
        sum += check(lst);
    printf("%ld\n", sum);
    rmlist(&lst);
    return 0;
}
