#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

// part 1
int min(int a, int b)
{
    int min = a;
    if (b < min)
        min = b;
    return min;
}

long int wrapper(FILE *input_file)
{
    int c;
    long long int result = 0;
    int l = 0, w = 0, h = 0;
    int temp = 0;
    if (input_file == 0)
    {
        perror("there was an error reading the file\n");
        exit(-1);
    }
    else
    {
        while ((c = fgetc(input_file)) != EOF)
        {

            if (isdigit(c))
            {

                temp = temp * 10 + (c - '0');
            }

            else if (c == 'x')
            {
                if (l == 0)
                {
                    l = temp;
                }
                else if (w == 0)
                {
                    w = temp;
                }

                temp = 0;
            }

            else if (c == '\n')
            {
                h = temp;

                temp = 0;

                printf("current result: %d\n", ((2 * l * w) + (2 * w * h) + (2 * h * l)) + min(l * w, min(w * h, h * l)));
                result = result + (((2 * l * w) + (2 * w * h) + (2 * h * l)) + min(l * w, min(w * h, h * l)));
                printf(" current variable affectations: %d x %d x %d \n", l, w, h);
                l = w = h = 0;
            }
        }
    }
    fclose(input_file);
    return result;
}

// part 2:
long int ribbon(FILE *input_file)
{
    int c;
    long long int result = 0;
    int l = 0, w = 0, h = 0;
    int temp = 0;
    if (input_file == 0)
    {
        perror("there was an error reading the file\n");
        exit(-1);
    }
    else
    {
        while ((c = fgetc(input_file)) != EOF)
        {

            if (isdigit(c))
            {

                temp = temp * 10 + (c - '0');
            }

            else if (c == 'x')
            {
                if (l == 0)
                {
                    l = temp;
                }
                else if (w == 0)
                {
                    w = temp;
                }

                temp = 0;
            }

            else if (c == '\n')
            {
                h = temp;

                temp = 0;
                //TODO: YOU WERE HERE TRYING TO MAKE THE CALC FOR THE RIBBON
                result = result + (1);
                         printf(" current variable affectations: %d x %d x %d \n", l, w, h);
                l = w = h = 0;
            }
        }
    }
    fclose(input_file);

    return result;
}

int main(int argc, char **argv)
{
    char *input = argv[1];
    FILE *input_file;
    input_file = fopen(input, "r");

    long int result = wrapper(input_file);

    printf("result = %ld \n", result);
    return 0;
}