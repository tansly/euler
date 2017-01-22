#include <stdio.h>
#include <math.h>

int is_right(int a, int b)
{
    int c_sqr = a * a + b * b;
    int c = (int) sqrt(c_sqr);
    return (c * c == c_sqr) ? c : 0;
}

int main()
{
    int sol[1001] = {0};
    int a, b, c, max = 0, max_p, i;
    for (a = 1; a * 3 < 1000; a++) {
        for (b = a + 1; a + b * 2 < 1000; b++) {
            if ((c = is_right(a, b)) && a + b + c <= 1000)
                sol[a + b + c]++;
        }
    }
    for (i = 0; i <= 1000; i++) {
        if (sol[i] > max) {
            max = sol[i];
            max_p = i;
        }
    }
    printf("%d\n", max_p);
    return 0;
}
