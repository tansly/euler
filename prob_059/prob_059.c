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
    if ( !fp ) {
        fputs("file open failed", stderr);
        exit(1);
    }
    /*  count the number of ints to be read and allocate storage */
    for ( len = 0; fscanf(fp, "%d,", &dummy) != EOF; len++ )
        ;
    vals = malloc((len  + 1) * sizeof(int));
    if ( !vals ) {
        fputs("read_file: malloc() fail", stderr);
        exit(1);
    }
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
    if ( !freq ) {
        fputs("calc_freqs: calloc() fail", stderr);
        exit(1);
    }
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

/*  try to decrypt a letter by trying all lowercase letters, return the successful key
 *  (we will try to find a space char from the highest occuring chars) */
int try_keys(int enc_char)
{
    int c;
    for ( c = 'a'; c <= 'z'; c++ ) {
        if ( (enc_char ^ c) == ' ' )
            return c;
    }
    fputs("try_keys: FAIL\n", stderr);
    return 0; /*  FAIL (should not happen) */
}

/*  decrypt the text by a given key 
 *  (we will have already found the three letters in the key) */
int print_decrypted(int *encr, int *key, size_t keysize)
{
    size_t i, decr_len = 5;
    int *decr = malloc(decr_len * sizeof(int));
    if ( !decr ) {
        fputs("print_decrypted: malloc() fail", stderr);
        exit(1);
    }
    for ( i = 0; encr[i] != TERM; i++ ) {
        if ( i >= decr_len - 1 ) {
            decr_len += 5;
            decr = realloc(decr, decr_len * sizeof(int));
            if ( !decr ) {
                fputs("print_decrypted: realloc() fail", stderr);
                exit(1);
            }
        }
        decr[i] = encr[i] ^ key[i % keysize];
        if ( !(decr[i] >= ' ' && decr[i] <= '~') ) {
            /*  not printable */
            free(decr);
            return 0;
        }
    }
    decr[i] = TERM;
    /*  all printable */
    for ( i = 0; decr[i] != TERM; i++ ) {
        putchar(decr[i]);
    }
    putchar('\n');
    free(decr);
    return 1;
}


int main(int argc, char **argv)
{
    size_t i, keysize;
    int *highest_occuring, *key; /*  the highest occuring chars will be held here (hopefully spaces) */
    int *encr, *freqs;
    if ( argc != 2 ) {
        printf("usage: %s key_size\n", argv[0]);
        return 1;
    }
    keysize = strtoul(argv[1], NULL, 0);
    encr = read_file();
    freqs = calc_freqs(encr);
    highest_occuring = malloc(keysize * sizeof(int));
    key = malloc(keysize * sizeof(int));
    if ( !key ) {
        fputs("main: malloc() fail", stderr);
        return 1;
    }
    for ( i = 0; i < keysize; i++ ) {
        highest_occuring[i] = find_highest(freqs);
        freqs[highest_occuring[i]] = 0; /*  we want to find the second one at the next iteration */
    }
    free(freqs);
    for ( i = 0; i < keysize; i++ ) {
        key[i] = try_keys(highest_occuring[i]);
    }
    for ( i = 0; i < keysize; i++ ) {
        putchar(key[i]);
    }
    putchar('\n');
    /*  TODO: permute the key and try to decrypt with each permutation
     *  do manually for now */
    puts("enter permutations of the given letters");
    do {
        for ( i = 0; i < keysize; i++ ) {
            scanf(" %c", (char *) &key[i]);
        }
    } while ( !print_decrypted(encr, key, keysize) );
    free(highest_occuring);
    free(encr);
    free(key);
    return 0;
}
