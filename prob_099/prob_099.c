#include <stdio.h>
#include <math.h>

int main()
{
    double base, exponent, current, max = 0;
    int line, max_line = 0;
    for (line = 1; scanf("%lf,%lf", &base, &exponent) != EOF; line++) {
        current = exponent * log10(base);
        if (current > max) {
            max = current;
            max_line = line;
        }
    }
    printf("%d\n", max_line);
    return 0;
}
