#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int grid[SIZE][SIZE];

void read_grid(void)
{
    int i, j;
    FILE *fp;
    fp = fopen("grid.txt", "r");
    if (!fp)
        exit(1);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            fscanf(fp, "%d", &grid[i][j]);
        }
    }
    fclose(fp);
}

int check_coord(int i, int j)
{
    int max = 0;
    if (i + 4 <= SIZE) {
        // check down
        int k, p;
        for (k = 0, p = 1; k < 4; k++)
            p *= grid[i + k][j];
        if (p > max)
            max = p;
    }
    if (j + 4 <= SIZE) {
        // check right
        int k, p;
        for (k = 0, p = 1; k < 4; k++)
            p *= grid[i][j + k];
        if (p > max)
            max = p;
    }
    if (i + 4 <= SIZE && j + 4 <= SIZE) {
        // check down-right
        int k, p;
        for (k = 0, p = 1; k < 4; k++)
            p *= grid[i + k][j + k];
        if (p > max)
            max = p;
    }
    if (i + 4 <= SIZE && j - 3 >= 0) {
        // check down-left
        int k, p;
        for (k = 0, p = 1; k < 4; k++)
            p *= grid[i + k][j - k];
        if (p > max)
            max = p;
    }
    return max;
}

int check_grid(void)
{
    int max = 0;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            int curr = check_coord(i, j);
            if (curr > max)
                max = curr;
        }
    }
    return max;
}

int main(void)
{
    read_grid();
    printf("%d\n", check_grid());
    return 0;
}
