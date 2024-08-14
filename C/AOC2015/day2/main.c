#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
   // printf("hello world!\n");


    char *input = argv[1];
    int i = 1;
    char  result[] = "";
    
    while (argv[i])
    {
        
        printf("%c\n", *argv[i]);
        char *temp =""+ *argv[i];
        printf("%s",temp);
        strcat(result, temp);
        i++;
    }
    
    printf("you said %s lmao! \n", result);
    return 0;
}