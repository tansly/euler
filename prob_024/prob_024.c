#include "list.h"

int main()
{
    struct node *digits = NULL;
    int cnt;
    for ( cnt = 9; cnt >= 0; cnt-- )
        push(&digits, cnt);
    for ( cnt = 2; cnt <= 1000000; cnt++ )
        narayana(digits);
    printlist(digits);
    return 0;
}
