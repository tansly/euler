#include <stdio.h>
#include "primes.h"
#define N 1000000

int search(int element, int *arr, int len);

int main()
{
    int i, j, len, sum = 0, max_seq = 0, max_prime = 0;
    int *list = NULL;
    len = prime_list(N, &list);
    for (i = 0; i < len; i++) {
        for (j = i, sum = 0; (j < len) && (sum + list[j] < N); j++) {
            sum += list[j];
            if ((j - i > max_seq) && search(sum, list, len)) {
                max_prime = sum;
                max_seq = j - i + 1;
            }
        }
    }
    printf("prime = %d\n", max_prime);
    printf("length = %d\n", max_seq);
    return 0;
}

int search(int element, int *arr, int len)
{
    int mid, first = 0, last = len - 1;
    while (first <= last) {
        mid = (first + last) / 2;
        if (element < arr[mid]) {
            last = mid - 1;
        } else if (element > arr[mid]) {
            first = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}
