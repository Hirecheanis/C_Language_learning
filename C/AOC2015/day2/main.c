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

int *twoMinsOfThree(int a, int b, int c)
{
    int *res = malloc(sizeof(int) * 2);
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    if (max == a)
    {
        res[0] = b;
        res[1] = c;
    }
    else if (max == b)
    {
        res[0] = a;
        res[1] = c;
    }
    else if (max == c)
    {
        res[0] = a;
        res[1] = b;
    }

    return res;
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
                /*A present with dimensions 2x3x4 requires 2+2+3+3 = 10
                feet of ribbon to wrap the present plus 2*3*4 = 24 feet of ribbon for the bow,
                for a total of 34 feet.
                A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to wrap the
                present plus 1*1*10 = 10 feet of ribbon for the bow, for a total of 14 feet.*/
                int *mins = twoMinsOfThree(l, w, h);
                result = result + ((2 * mins[0]) + (2 * mins[1]) + (l * w * h));
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

    long int result = ribbon(input_file);
    printf("result = %ld \n", result);
    
    return 0;
}