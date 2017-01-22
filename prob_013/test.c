#include <stdio.h>

int main()
{
    char buff[5];
    char c;
    fgets(buff, 5, stdin);
    c = getchar();
    puts(buff);
    return 0;
}
