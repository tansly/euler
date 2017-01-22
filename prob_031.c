#include <stdio.h>
#include <limits.h>

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, INT_MAX};

int make_target(int target, int with)
{
    if (target == 0) {
        return 1;
    } else if (coins[with] > target) {
        return 0;
    } else {
        int i;
        int ways;
        for (i = 0, ways = 0; i * coins[with] <= target; i++) {
            ways += make_target(target - i * coins[with], with + 1);
        }
        return ways;
    }
}

int make200(void)
{
    return make_target(200, 0);
}

int main(void)
{
    printf("%d\n", make200());
    return 0;
}
