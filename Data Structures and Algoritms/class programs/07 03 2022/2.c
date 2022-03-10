// WAP to print the squares of "N" different elements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int val_arr(const char *s)
{
    while (*s)
        if (isdigit(*s++) == 0)
            return 0;

    return 1;
}

void getSq(int n, char **arr)
{
    int i, j;
    float sq;
    for (i = 0; i < n; i++)
    {
        if (val_arr(*(arr + i)))
        {
            sq = (float)atoi(*(arr + i));
            sq *= sq;
            printf("arr[%d] = %.2f\n", i, sq);
        }
        else
        {
            printf("INVALID ARGUMENTS DETECTED!!!\n"); //\nPROGRAM TERMINATED.");
            continue;
        }
    }
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    // printf("\nsize of array = %d\n", strlen(argv[2]));
    if (n > argc - 1 || n < 0)
        printf("INDEX OUT OF BOUNDS!!!");
    else
        getSq(n, &argv[2]);

    return 0;
}