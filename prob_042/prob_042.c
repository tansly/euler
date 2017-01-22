#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUTSIZE 20000
#define WORDSIZE 20

int convert_and_move(char **word_ref);

int is_triangle(char **word_ref);

int main()
{
    int cnt = 0;
    char words[INPUTSIZE];
    char *current;
    fgets(words, sizeof(words), stdin);
    current = words + 1;
    while (*current != '\0') {
        if (is_triangle(&current))
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

int convert_and_move(char **word_ref)
{
    int sum = 0;
    while (**word_ref != '\"' && **word_ref != ',' && **word_ref != '\0') {
        sum += **word_ref - 'A' + 1;
        (*word_ref)++;
    }
    (*word_ref)++;
    return sum;
}

int is_triangle(char **word_ref)
{
    int tri;
    int n = 1;
    int value = convert_and_move(word_ref);
    while ((tri = n * (n + 1) / 2) <= value) {
        if (tri == value)
            return 1;
        n++;
    }
    return 0;
}
