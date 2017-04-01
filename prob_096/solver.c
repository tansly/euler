#include <stdio.h>

static int checkrow(int grid[][9], int guess, int row)
{
    int i;
    for (i = 0; i < 9; i++) {
        if (guess == grid[row][i]) {
            return 0;
        }
    }
    return 1;
}

static int checkcol(int grid[][9], int guess, int col)
{
    int i;
    for (i = 0; i < 9; i++) {
        if (guess == grid[i][col]) {
            return 0;
        }
    }
    return 1;
}

static int checksqr(int grid[][9], int guess, int row, int col)
{
    int i, j;
    row -= row % 3;
    col -= col % 3;
    for (i = row; i < row + 3; i++) {
        for (j = col; j < col + 3; j++) {
            if (guess == grid[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

static int checkpos(int grid[][9], int guess, int row, int col)
{
    return checkrow(grid, guess, row) &&
           checkcol(grid, guess, col) &&
           checksqr(grid, guess, row, col);
}

void printgrid(int grid[][9])
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void readgrid(int grid[][9])
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int solve(int grid[][9])
{
    int i, j, guess;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            for (guess = 1; grid[i][j] == 0 && guess <= 9; guess++) {
                if (checkpos(grid, guess, i, j)) {
                    grid[i][j] = guess;
                    if (solve(grid)) {
                        return 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}
