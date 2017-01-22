#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int a_to_b(int number, int power, int result)
{
	if (power == 0) {
		return result;
	}
	return a_to_b(number, power - 1, result * number);
}

int is_in(int array[], int element, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (array[i] == element) {
			return 1;
		}
	}
	return 0;
}


int main()
{
	int primes[908];
	int a, b, c, count = 0;
	int results[2000000];
	int test;
	for (a = 2, b = 0; a < 7072; a++) {
		if (is_prime(a)) {
			primes[b] = a;
			b++;
		}
	}
	for (a = 0; a < 908; a++) {
		for (b = 0; b < 73; b++) {
			for (c = 0; c < 23; c++) {
				test = a_to_b(primes[a], 2, 1) + a_to_b(primes[b], 3, 1) + a_to_b(primes[c], 4, 1);
				if (test < 50000000) {
					if (!is_in(results, test, count)) {
							results[count++] = test;
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
