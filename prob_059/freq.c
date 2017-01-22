#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define TERM -1
#define KEYSIZE 3

/*  read the file (encrypted), put the values into an array, terminated by a TERM */
int *read_file(void)
{
    int dummy;
    int *vals;
    size_t len, i;
    FILE *fp;
    fp = fopen("p059_cipher.txt", "r");
    for ( len = 0; fscanf(fp, "%d,", &dummy) != EOF; len++ )
        ;
    vals = malloc((len  + 1) * sizeof(int));
    rewind(fp);
    for ( i = 0; i < len; i++ ) {
        fscanf(fp, "%d,", &vals[i]);
    }
    fclose(fp);
    vals[len] = TERM;
    return vals;
}

/* take the encrypted array as argument, puts frequencies into an array, terminated by a TERM */
int *calc_freqs(int *vals)
{
    size_t i;
    int *freq = calloc(CHAR_MAX - CHAR_MIN + 1, sizeof(int)); /*  allocate storage for each possible char */
    for ( i = 0; vals[i] != TERM; i++ ) {
        freq[vals[i]]++;
    }
    freq[CHAR_MAX - CHAR_MIN] = TERM;
    return freq;
}

/*  find the encrypted char with highest frequency and return its value */
int find_highest(int *freqs)
{
    int max_char, max_freq = 0;
    size_t i;
    for ( i = 0; freqs[i] != TERM; i++ ) {
        if ( freqs[i] > max_freq ) {
            max_freq = freqs[i];
            max_char = i; /*  position in the freq array will also be the value of the encrypted char */
        }
    }
    return max_char;
}

/*  try to decrypt a letter by trying all lowercase letters
 *  (we will try to find a space char from the highest occuring chars)*/
int try_keys(int enc_char)
{
    int c;
    for ( c = 'a'; c <= 'z'; c++ ) {
        if ( (enc_char ^ c) == ' ' )
            return c;
    }
    return 0; /*  FAIL */
}

int main()
{
    size_t i;
    int highest_occuring[KEYSIZE]; /*  the highest occuring chars will be held here (hopefully spaces) */
    int *encr, *freqs;
    encr = read_file();
    freqs = calc_freqs(encr);
    for ( i = 0; i < KEYSIZE; i++ ) {
        highest_occuring[i] = find_highest(freqs);
        freqs[highest_occuring[i]] = 0; /*  we want to find the second one at the next iteration */
    }
    for ( i = 0; i < KEYSIZE; i++ ) {
        putchar(try_keys(highest_occuring[i]));
    }
    putchar('\n');
    return 0;
}
