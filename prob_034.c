#include <stdio.h>

int factorial(int n)
{
	if (n == 0) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

int fac_digit_sum(int n)
{
	if (n / 10 == 0) {
		return factorial(n);
	} else {
		return factorial(n % 10) + fac_digit_sum(n / 10);
	}
}

int main()
{
	int n, total = 0;
	for (n = 3; n < 9999999; n++) {
		if (n == fac_digit_sum(n)) {
			total += n;
		}
	}
	printf("%d\n", total);
	return 0;
}
