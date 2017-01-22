#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 51

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
    if ( n1 -> size < n2 -> size ) {
        char *s = malloc( (n1 -> size + 1) * sizeof(char));
        size_t size;
        strcpy(s, n1 -> s);
        n1 -> s = realloc(n1 -> s, n2 -> size + 1);
        strcpy(n1 -> s, n2 -> s);
        strcpy(n2 -> s, s);
        n2 -> s = realloc(n2 -> s, n1 -> size + 1);
        size = n1 -> size;
        n1 -> size = n2 -> size;
        n2 -> size = size;
        free(s);
    }
    for ( i = n1 -> size - 1, j = n2 -> size - 1; i >= 0 && j >= 0; i--, j-- ) {
        d1 = n1 -> s[i] - '0';
        d2 = n2 -> s[j] - '0';
        if ( (carry += d1 + d2) > 9 ) {
            n1 -> s[i] = carry - 10 + '0';
            carry = 1;
        } else {
            n1 -> s[i] = carry + '0';
            carry = 0;
        }
    }
    if ( carry != 0 ) {
        if ( i == 0 ) {
            d1 = n1 -> s[i] - '0';
            carry += d1;
            if ( carry > 9 ) {
                n1 -> s[i] = carry - 10 + '0';
                carry = 1;
            } else {
                n1 -> s[i] = carry + '0';
                carry = 0;
            }
        } else if ( i < 0 ) {
            char *s, *t;
            n1 -> size = n1 -> size + 1;
            s = malloc((n1 -> size + 1) * sizeof(char));
            strcpy(s + 1, n1 -> s);
            s[0] = carry + '0';
            t = n1 -> s;
            n1 -> s = s;
            free(t);
            carry = 0;
        } else {
            for ( ; i >= 0; i-- ) {
                d1 = n1 -> s[i] - '0';
                carry += d1;
                if ( carry > 9 ) {
                    n1 -> s[i] = carry - 10 + '0';
                    carry = 1;
                } else {
                    n1 -> s[i] = carry + '0';
                    carry = 0;
                    break;
                }
            }
        }
        if ( carry != 0 ) {
            char *s, *t;
            n1 -> size = n1 -> size + 1;
            s = malloc((n1 -> size + 1) * sizeof(char));
            strcpy(s + 1, n1 -> s);
            s[0] = carry + '0';
            t = n1 -> s;
            n1 -> s = s;
            free(t);
            carry = 0;
        }
    }
}

int main()
{
    struct bigint n1, n2;
    n1.size = SIZE - 1;
    n2.size = SIZE - 1;
    n1.s = malloc(SIZE * sizeof(char));
    n2.s = malloc(SIZE * sizeof(char));
    for ( fgets(n1.s, SIZE, stdin), getchar(); fgets(n2.s, SIZE, stdin) != NULL; getchar() ) {
        add(&n1, &n2);
    }
    puts(n1.s);
    free(n1.s);
    free(n2.s);
    return 0;
}
