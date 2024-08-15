#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

// part 1
long wrapper(FILE *input_file)
{
    int c;
    if (input_file == 0)
    {
        perror("there was an error reading the file\n");
        exit(-1);
    }
    else
    {
        while ((c = fgetc(input_file)) != EOF)
        {

            if (isdigit(c) ){
            int i = c - '0';
            printf("%d",i);
            }
            else if (c == 'x'){
                
                
                    printf("%c", c);}
                
            else if(c == '\n'){

                printf("\n");
            
            }
        }
    }
    return 5;
}

int main(int argc, char **argv)
{
    char *input = argv[1];
    FILE *input_file;
    input_file = fopen(input, "r");

    long result = wrapper(input_file);

    printf("result = %d \n", result);

    return 0;
}