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

int is_in(int array[], int element, int len)
{
	int i;
	for (i = 0; i < len - 1; i++) {
		if (array[i] == element) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	int chain[60];
	int n, test, len, count = 0;
	for (n = 10; n < 1000000; n++) {
		test = n;
		len = 0;
		while (!is_in(chain, test, len)) {
			test = fac_digit_sum(test);
			chain[len] = test;
			len++;
		}
		if (len == 60) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
