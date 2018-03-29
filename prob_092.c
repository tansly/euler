#include <stdio.h>

int digit_square(int n)
{
	int d;
	if (n == 0) {
		return 0;
	}
	d = n % 10;
	return d * d + digit_square(n / 10);
}

int main()
{
	int n, test, count = 0;
	for (n = 1; n < 10000000; n++) {
		test = n;
		while (1) {
			test = digit_square(test);
			if (test == 89) {
				count++;
				break;
			} else if (test == 1) {
				break;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
