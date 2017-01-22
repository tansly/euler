#include <stdio.h>
#define UL unsigned long int

int digit_count(UL n, int count)
{
	if (n <= 9) {
		return count;
	}
	return digit_count(n / 10, count + 1);
}

UL ten_to(int power, UL result)
{
	if (power == 0) {
		return result;
	}
	return ten_to(power - 1, result * 10);
}

UL rev_num(UL n, int power)
{
	if (n <= 9) {
		return n;
	}
	return (n % 10) * ten_to(power, 1) + rev_num(n / 10, power - 1);
}

int is_reversible(UL n)
{
	UL test;
	test = n + rev_num(n, digit_count(n, 1) - 1);
	while (test > 0) {
		if ((test % 10) % 2 == 0) {
			return 0;
		} else {
			test /= 10;
		}
	}
	return 1;
}

int main()
{
	int count = 0;
	UL n = 11;
	while (n < 100000000) {
		if (n % 10 != 0) {
			if (is_reversible(n)) {
				count++;
				n++;
			} else {
				n++;
			}
		} else {
			n++;
		}
	}
	printf("%d\n", count);
	return 0;
}
