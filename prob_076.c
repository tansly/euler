#include <stdio.h>
#define TARGET 100

int main()
{
    int ways[TARGET + 1] = { 0 };
    int i, j;
    ways[0] = 1;
    for (i = 1; i < TARGET; i++) {
        for (j = i; j <= TARGET; j++) {
            ways[j] = ways[j] + ways[j - i];
        }
    }
    printf("%d\n", ways[TARGET]);
    return 0;
}
