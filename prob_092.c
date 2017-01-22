/*
 * =====================================================================================
 *
 *       Filename:  prob_092.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/02/2016 09:27:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

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
