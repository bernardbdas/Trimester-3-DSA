#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int n, char **arr)
{
    int i;
    for (i = 0; i < n; i++)
        printf("arr[%d] = %s\n", i, *(arr + i));
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    // printf("\nsize of array = %d\n", strlen(argv[2]));
    if (n > argc - 1 || n < 0)
        printf("INDEX OUT OF BOUNDS!!!");
    else
        print(n, &argv[2]);

    return 0;
}