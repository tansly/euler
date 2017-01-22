#include <stdio.h>
#define SIZE 20

long result[SIZE][SIZE];

long paths(int row, int col)
{
    if (row == 0 && col == 0) {
        result[row][col] = 0;
        return 0;
    } else if (row == 0) {
        result[row][col] = 1;
        return 1;
    } else if (col == 0) {
        result[row][col] = 1;
        return 1;
    } else if (result[row][col] == 0) {
        result[row][col] = paths(row - 1, col) + paths(row, col - 1);
        return result[row][col];
    } else {
        return result[row][col];
    }
}

int main()
{
    printf("%ld\n", paths(SIZE, SIZE));
    return 0;
}
