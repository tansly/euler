#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bigint {
    size_t size;
    char *s;
};

/*  add two bigints, return the result with n1 */
void add(struct bigint *n1, struct bigint *n2)
{
    int i, j;
    int carry = 0;
    char d1, d2;
    if (n1->size < n2->size) {
        char *s = malloc((n1->size + 1) * sizeof(char));
        size_t size;
        strcpy(s, n1->s);
        n1->s = realloc(n1->s, n2->size + 1);
        strcpy(n1->s, n2->s);
        strcpy(n2->s, s);
        n2->s = realloc(n2->s, n1->size + 1);
        size = n1->size;
        n1->size = n2->size;
        n2->size = size;
        free(s);
    }
    for (i = n1->size - 1, j = n2->size - 1; i >= 0 && j >= 0; i--, j--) {
        d1 = n1->s[i] - '0';
        d2 = n2->s[j] - '0';
        if ((carry += d1 + d2) > 9) {
            n1->s[i] = carry - 10 + '0';
            carry = 1;
        } else {
            n1->s[i] = carry + '0';
            carry = 0;
        }
    }
    if (carry != 0) {
        if (i == 0) {
            d1 = n1->s[i] - '0';
            carry += d1;
            if (carry > 9) {
                n1->s[i] = carry - 10 + '0';
                carry = 1;
            } else {
                n1->s[i] = carry + '0';
                carry = 0;
            }
        } else if (i < 0) {
            char *s, *t;
            n1->size = n1->size + 1;
            s = malloc((n1->size + 1) * sizeof(char));
            strcpy(s + 1, n1->s);
            s[0] = carry + '0';
            t = n1->s;
            n1->s = s;
            free(t);
            carry = 0;
        } else {
            for (; i >= 0; i--) {
                d1 = n1->s[i] - '0';
                carry += d1;
                if (carry > 9) {
                    n1->s[i] = carry - 10 + '0';
                    carry = 1;
                } else {
                    n1->s[i] = carry + '0';
                    carry = 0;
                    break;
                }
            }
        }
        if (carry != 0) {
            char *s, *t;
            n1->size = n1->size + 1;
            s = malloc((n1->size + 1) * sizeof(char));
            strcpy(s + 1, n1->s);
            s[0] = carry + '0';
            t = n1->s;
            n1->s = s;
            free(t);
            carry = 0;
        }
    }
}

int head_pandigital(const struct bigint *n)
{
    int digits[10] = {0};
    int i;
    for (i = 0; i < 9; i++) {
        digits[n->s[i] - '0']++;
    }
    if (digits[0])
        return 0; // contains 0
    for (i = 1; i < 10; i++) {
        if (digits[i] != 1)
            return 0; // repeated digit
    }
    return 1;
}

int tail_pandigital(const struct bigint *n)
{
    int digits[10] = {0};
    int i;
    for (i = n->size - 1; n->size - i <= 9; i--) {
        digits[n->s[i] - '0']++;
    }
    if (digits[0])
        return 0; // contains 0
    for (i = 1; i < 10; i++) {
        if (digits[i] != 1)
            return 0; // repeated digit
    }
    return 1;
}

void cp_num(struct bigint *dest, const struct bigint *src)
{
    if (dest->size < src->size)
        dest->s = realloc(dest->s, src->size + 1);
    strcpy(dest->s, src->s);
    dest->size = src->size;
}

/*  initialize numbers to 1 */
void init_num(struct bigint *n)
{
    n->size = 1;
    n->s = malloc(2);
    strcpy(n->s, "1");
}

int check_fibs(void)
{
    int k;
    int found;
    struct bigint save, fib_p, fib;
    init_num(&save);
    init_num(&fib_p);
    init_num(&fib);
    for (k = 2, found = 0; !found; k++) {
        cp_num(&save, &fib);
        add(&fib, &fib_p);
        cp_num(&fib_p, &save);
        if (k > 2748 && head_pandigital(&fib) && tail_pandigital(&fib)) // k from problem description
            found = 1;
    }
    free(save.s);
    free(fib.s);
    free(fib_p.s);
    return k;
}

int main(void)
{
    int k;
    k = check_fibs();
    printf("%d\n", k);
    return 0;
}
