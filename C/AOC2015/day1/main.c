#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

// Advent of Code 2015

// day 1 part one
int floors(FILE *input_file)
{
    long int counter = 0;
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

            if (c == '(')
            {
                counter++;
            }
            else if (c == ')')
            {
                counter--;
            }
        }
    }

    fclose(input_file);
    return counter;
}

// day 1 part 2
int position(FILE *input_file)
{
    long int floor = 0;
    
    long int position = 1;
    long int result;
    bool found = false;
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

            if (c == '(')
            {
                floor++;
            }
            else if (c == ')')
            {
                floor--;
            }
            position++;
            printf("position %d and floor %d \n",position, floor);
            
            if (floor < 0 && !found)
            {
                result = position;
                found = true;
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

    long int result = position(input_file);
    
    printf("result = %d \n", result);
    return 0;
}