#include <stdio.h>

int main()
{
    int m, i;
    m = 0;
    i = 1;
    m = 2;
    i = 1;
    do
    {
        m = m + 2;
        i = i + 1;
        printf("%d > %d\n", m, i);
    } while (i <= m);

    return 0;
}