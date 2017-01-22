#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMLEN 105
#define HELPER_PATH "./helper.sh"

int sum_str(char *str)
{
    int sum = 0;
    size_t i;
    for (i = 0; str[i]; i++) {
        if (isdigit(str[i]))
            sum += str[i] - '0';
    }
    return sum;
}

int main(void)
{
    int sum = 0;
    char str[NUMLEN];
    FILE *fp;
    fp = popen(HELPER_PATH, "r");
    if (fp == NULL) {
        perror("popen()");
        return 1;
    }
    while (fgets(str, NUMLEN, fp) != NULL) {
        sum += sum_str(str);
    }
    pclose(fp);
    printf("%d\n", sum - 45);
    return 0;
}
