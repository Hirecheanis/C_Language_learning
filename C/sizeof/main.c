#include <stdio.h>

int main()
{

    int a = 65535;
    printf("%d ",a);
    a++;
    printf("%d ,%ld", a,sizeof(a));
    return 0;
}