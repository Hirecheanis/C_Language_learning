#include <stdio.h>

void print_array(int arr[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main()
{

    int arr[4];
    int j = 0;
    int size = sizeof(arr) / 4;
    for (int i = 0; i < size; i++)
    {
        arr[i] = j;
        j++;
    }
    print_array(arr, size);

    return 0;
}