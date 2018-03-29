/* int gcd(int a, int b)
 * {
 * 	int temp;
 * 	while (b != 0) {
 * 		temp = b;
 * 		b = a % b;
 * 		a = temp;
 * 	}
 * 	return a;
 * }
 * 
 * int totient(int n)
 * {
 * 	int i, count = 0;
 * 	for (i = 1; i < n; i++) {
 * 		if (gcd(n, i) == 1) {
 * 			count++;
 * 		}
 * 	}
 * 	return count;
 * }
 * 
 * int main()
 * {
 * 	int n, max_n;
 * 	double test, max = 0.0;
 * 	for (n = 2; n <= 10000; n++) {
 * 		test = (double) n / totient(n);
 * 		if (test > max) {
 * 			max = test;
 * 			max_n = n;
 * 		}
 * 	}
 * 	printf("%d\n", max_n);
 * 	return 0;
 * }
 */

/*  GAVE UP BRUTE FORCE APPROACH */

#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, p = 2;
	for (n = 3; p * n < 1000000; n += 2) {
		if (is_prime(n)) {
			p *= n;
		}
	}
	printf("%d\n", p);
	return 0;
}
