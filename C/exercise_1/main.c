#include <stdio.h>

int main(){
    int m = 0;
    int i = 1;
    do
    {
        m = m + 2;
        i++;
    } while (i > m);
    printf("m = %d \n", m);
    return 0;
}