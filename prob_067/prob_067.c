#include <stdio.h>
#define SIZE 100

long triangle[SIZE][SIZE];
long result[SIZE][SIZE];

long max_sum(int row, int col)
{
    if ( row == SIZE - 1 ) {
        /*  reached the bottom (base case) */
        result[row][col] = triangle[row][col];
        return result[row][col];
    } else {
        int right, down;
        if ( result[row][col] == 0 ) {
            /*  result not already calculated */
            right = triangle[row][col] + max_sum(row + 1, col + 1);
            down = triangle[row][col] + max_sum(row + 1, col);
            result[row][col] = right > down ? right : down;
            return result[row][col];
        } else {
            /*  already calculated, return immediately */
            return result[row][col];
        }
    }
}

int main()
{
    int i, j;
    for ( i = 0; i < SIZE; i++ ) {
        for ( j = 0; j <= i; j++ ) {
            scanf("%ld", &triangle[i][j]);
        }
    }
    printf("%ld\n", max_sum(0, 0));
    return 0;
}
