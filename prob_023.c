#include <stdio.h>
#define LIMIT 28123

/*  check if a number is abundant */
int is_abundant(int n);

/*  put abundant numbers up to the limit in array, return the length of the array   */
int generate_abundants(int* array, int limit);

/*  binary search an array of integers, return 1 if element exists, 0 if not */
int bsearch(int* array, int element, int len);

int main()
{
    int i, n, sum, len;
    int flag;
    int abundants[LIMIT];   /*  more than enough space to store all abundant numbers up to LIMIT */
    len = generate_abundants(abundants, LIMIT);
    for (n = 1, sum = 0; n < LIMIT; n++) {
        flag = 0;
        for (i = 0; i < len && n - abundants[i] > 0; i++) {
            if ((flag = bsearch(abundants, n - abundants[i], len))) /*  we can write n as a sum (flag) */
                break;
        }
        if (!flag)
            sum += n;
    }
    printf("%d\n", sum);
    return 0;
}

int is_abundant(int n)
{
    int i, sum;
    for (i = 1, sum = 0; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum > n;
}

int generate_abundants(int* array, int limit)
{
    int cnt;
    int n;
    for (n = 1, cnt = 0; n < limit; n++) {
        if (is_abundant(n))
            array[cnt++] = n;
    }
    return cnt;
}

int bsearch(int* array, int element, int len)
{
    int first = 0;
    int last = len - 1;
    int mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (element == array[mid]) {
            return 1;
        } else if (element < array[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return 0;
}
