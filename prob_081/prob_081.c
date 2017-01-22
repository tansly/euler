#include <stdio.h>
#define SIZE 80

long result[SIZE][SIZE];

long minimal_sum(long matrix[][SIZE], int row, int col)
{
    int right, down;
    int min;
    if ( row == SIZE - 1 && col == SIZE - 1 ) {
        result[row][col] = matrix[row][col];
        return result[row][col];
    }
    if ( row == SIZE - 1 && result[row][col] == 0) {
        result[row][col] = matrix[row][col] + minimal_sum(matrix, row, col + 1);
        return result[row][col];
    } else if ( row == SIZE - 1 && result[row][col] != 0)  {
        return result[row][col];
    }
    if ( col == SIZE - 1 && result[row][col] == 0 ) {
        result[row][col] =  matrix[row][col] + minimal_sum(matrix, row + 1, col);
        return result[row][col];
    } else if ( col == SIZE - 1 && result[row][col] != 0 ) {
        return result[row][col];
    }
    if ( result[row][col] == 0 ) {
        right = matrix[row][col] + minimal_sum(matrix, row, col + 1);
        down = matrix[row][col] + minimal_sum(matrix, row + 1, col);
        min = right < down ? right : down;
        result[row][col] = min;
        return result[row][col];
    } else {
        return result[row][col];
    }
}

int main()
{
    long matrix[SIZE][SIZE];
    int i, j;
    for ( i = 0; i < SIZE; i++ ) {
        for ( j = 0; j < SIZE; j++ ) {
            scanf("%ld,", &matrix[i][j]);
        }
    }
    printf("%ld\n", minimal_sum(matrix, 0, 0));
    return 0;
}
