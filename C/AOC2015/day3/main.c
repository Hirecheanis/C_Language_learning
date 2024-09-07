#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

long int direction(FILE *input_file)
{
    int c;
    int lenght = 0;
    long int result = 0;
    int **grid = malloc(10000 * sizeof(int *));
    for (int i = 0; i < 10000; i++)
    {
        grid[i] = malloc(10000 * sizeof(int));
        memset(grid[i], 0, 10000 * sizeof(int));
    }
    int x = 5000;
    int y = 5000;
    grid[x][y]++;

    if (input_file == 0)
    {
        perror("there was an error reading the file\n");
        exit(-1);
    }
    else
    {
        while ((c = fgetc(input_file)) != EOF)
        {

            if (c == '>' && x < 9999)
            {
                x++;
                grid[x][y]++;
            }
            else if (c == '<' && x < 9999)
            {
                x--;
                grid[x][y]++;
            }
            else if (c == '^' && y < 9999)
            {
                y--;
                grid[x][y]++;
            }
            else if (c == 'v' && y < 9999)
            {
                y++;
                grid[x][y]++;
            }
        }
    }
    fclose(input_file);
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            if (grid[i][j] > 0)
            {
                result++;
            }
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return result;
}

int main(int argc, char **argv)
{

    char *input = argv[1];
    FILE *input_file;
    input_file = fopen(input, "r");
    long int result = direction(input_file);
    printf("%ld\n", result);

    return 0;
}
