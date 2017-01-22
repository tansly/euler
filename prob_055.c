#include <stdio.h>
#include <stdint.h>

int digit_count(uintmax_t n, int count)
{
	if (n <= 9) {
		return count;
	}
	return digit_count(n / 10, count + 1);
}

uintmax_t ten_to(int power, uintmax_t result)
{
	if (power == 0) {
		return result;
	}
	return ten_to(power - 1, result * 10);
}

uintmax_t rev_num(uintmax_t n, int power)
{
	if (n <= 9) {
		return n;
	}
	return (n % 10) * ten_to(power, 1) + rev_num(n / 10, power - 1);
}

int is_pal(uintmax_t n)
{
	return n == rev_num(n, digit_count(n, 1) - 1);
}

int is_lych(uintmax_t n)
{
	int i;
	for (i = 0; i < 50; i++) {
		n += rev_num(n, digit_count(n, 1) - 1);
		if (is_pal(n)) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	uintmax_t n;
	int count = 0;
	for (n = 0; n < 10000; n++) {
		if (is_lych(n)) {
			count += 1;
		}
	}
	printf("%d\n", count);
	return 0;
}
