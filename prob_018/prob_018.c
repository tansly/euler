#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 15

int max_sum(int triangle[][ROWS], int row, int col)
{
    int left, right;
    if ( row == ROWS - 1 )
        return triangle[row][col];
    left = triangle[row][col] +  max_sum(triangle, row + 1, col);
    right = triangle[row][col] + max_sum(triangle, row + 1, col + 1);
    return left > right ? left : right;
}

int main()
{
    int triangle[ROWS][ROWS];
    size_t row, col;
    for ( row = 0; row < ROWS; row++ ) {
        for ( col = 0; col <= row; col++ ) {
            scanf("%d", &triangle[row][col]);
        }
    }
    printf("%d\n", max_sum(triangle, 0, 0));
    return 0;
}
