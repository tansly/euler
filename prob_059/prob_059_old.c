#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define KEYLEN 3

void print_text(int *text, size_t len);

int *check_key(const int *text, size_t len, const int *key)
{
    size_t i;
    int *copy = malloc(len * sizeof(int));
    memcpy(copy, text, len * sizeof(int));
    for ( i = 0; i < len; i++ ) {
        copy[i] = copy[i] ^ key[i % KEYLEN];
        if ( !(copy[i] >= ' ' && copy[i] <= '~') ) {
            /*  we have a non-printable char, abort */
            free(copy);
            return NULL;
        }
    }
    return copy;
}

int sum_vals(int *text, size_t len)
{
    size_t i;
    int sum = 0;
    for ( i = 0; i < len; i++ ) {
        sum += text[i];
    }
    return sum;
}

void print_text(int *text, size_t len)
{
    size_t i;
    for ( i = 0; i < len; i++ ) {
        putchar(text[i]);
    }
    putchar('\n');
}

int calc_score(int *text, size_t len)
{
    int score;
    size_t i;
    for ( i = 0; i < len; i++ ) {
        if ( text[i] == 'e' )
            score++;
        else if ( text[i] == 't' )
            score++;
        else if ( text[i] == 'a' )
            score++;
    }
    return score;
}

int main()
{
    int *text, *result, *highest;
    int key[KEYLEN];
    int score, max_score = INT_MIN;
    size_t len;
    size_t size = 5;
    text = malloc(size * sizeof(int));
    for ( len = 0; scanf("%d,", &text[len]) != EOF; len++ ) {
        if ( len >= size - 1 ) { /* filled space, allocate more */
            size += 5;
            text = realloc(text, size * sizeof(int));
        }
    }
    highest = malloc(len * sizeof(int));
    /*  for each key */
    for ( key[0] = 'a'; key[0] <= 'z'; key[0]++ ) {
        for ( key[1] = 'a'; key[1] <= 'z'; key[1]++ ) {
            for ( key[2] = 'a'; key[2] <= 'z'; key[2]++ ) {
                /*  try to decrypt */
                result = check_key(text, len, key);
                if ( result != NULL ) { /*  result consists of printable chars */
                    score = calc_score(result, len);
                    if ( score > max_score ) {
                        max_score = score;
                        memcpy(highest, result, len * sizeof(int));
                        free(result);
                    }
                }
            }
        }
    }
    print_text(highest, len);
    printf("%d\n", sum_vals(highest, len));
    free(highest);
    return 0;
}
