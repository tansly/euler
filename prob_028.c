#include <stdio.h>
#include <stdlib.h>
#define NDEBUG

int **generate(int size)
{
    int n, i, j;
    int flag = 0;
    int **matrix;
    matrix = (int **) malloc(size * sizeof(*matrix));
    if (!matrix) {
        fputs("generate(): malloc fail\n", stderr);
        exit(1);
    }
    *matrix = (int *) calloc(size * size, sizeof(**matrix));
    if (!*matrix) {
        fputs("generate(): calloc fail\n", stderr);
        exit(1);
    }
    for (i = 0; i < size; i++) {
        matrix[i] = (*matrix) + i * size;
    }
    n = size * size;
    i = 0;
    j = size - 1;
    while (n >= 1) {
        while (j >= 0 && matrix[i][j] == 0) {
            matrix[i][j--] = n--;
            flag = 1;
        }
        if (flag) {
            j++;
            i++;
            flag = 0;
        }
        while (i < size && matrix[i][j] == 0) {
            matrix[i++][j] = n--;
            flag = 1;
        }
        if (flag) {
            i--;
            j++;
            flag = 0;
        }
        while (j < size && matrix[i][j] == 0) {
            matrix[i][j++] = n--;
            flag = 1;
        }
        if (flag) {
            j--;
            i--;
            flag = 0;
        }
        while (i >= 0 && matrix[i][j] == 0) {
            matrix[i--][j] = n--;
            flag = 1;
        }
        if (flag) {
            i++;
            j--;
            flag = 0;
        }
    }
    return matrix;
}

int sum_diag(int **matrix, int size)
{
    int i;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    for (i = size - 1; i >= 0; i--) {
        sum += matrix[i][size - i - 1];
    }
    return sum - 1; /*  counted the entry at the center (1) twice */
}

int main()
{
    int **matrix;
    int size;
    scanf("%d", &size);
    matrix = generate(size);
    printf("%d\n", sum_diag(matrix, size));
    free(*matrix);
    free(matrix);
    return 0;
}
