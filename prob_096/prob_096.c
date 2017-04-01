#include "solver.h"
#include <stdio.h>

int main(void)
{
    int i, sum;
    int grid[9][9];
    for (i = 0, sum = 0; i < 50; i++) {
        readgrid(grid);
        solve(grid);
        sum += 100 * grid[0][0] + 10 * grid[0][1] + grid[0][2];
    }
    printf("%d\n", sum);
    return 0;
}
