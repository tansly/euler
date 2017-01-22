#include <stdio.h>
#include <stdlib.h>
#define TARGET 2000000

int sum(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int m, n;
    int nearest_count = 0;
    int area;
    for (m = 1; ; m++) {
        int sum_m = sum(m);
        if (sum_m > TARGET) {
            break;
        }
        for (n = 1; ; n++) {
            int sum_n = sum(n);
            if ((abs(TARGET - sum_n * sum_m) < abs(TARGET - nearest_count))) {
                nearest_count = sum_n * sum_m;
                area = m * n;
            }
            if (sum_n * sum_m > TARGET) {
                break;
            }
        }
    }
    printf("%d\n", area);
    return 0;
}
