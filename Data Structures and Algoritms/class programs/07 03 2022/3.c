// WAP to print the squares of "N" different elements
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (0 == val_arg(argv[1]))
    {
        printf("INVALID ARGUMENTS DETECTED!!!\nPROGRAM TERMINATED.");
        return 0;
    }

    (void)argc;
    int i, min, max;
    int *arr = (int *)malloc(sizeof(int) * atoi(argv[1]));
    system("cls");
    printf("Program Name : %s", argv[0]);
    printf("\n*********************************************\n");
    ch = menu();

    switch (ch)
    {
    case '1':
        printf("Enter the contents of the array : ");
        for (i = 0; i < argv[0]; i++)
        {
            printf("\narr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
        break;

    case '2':
        findMinMax(arr, &min, &max);

        break;

    default:
        break;
    }

    return 0;
}

int val_arg(const char *s)
{
    while (*s)
        if (isdigit(*s++) == 0)
            return 0;

    return 1;
}