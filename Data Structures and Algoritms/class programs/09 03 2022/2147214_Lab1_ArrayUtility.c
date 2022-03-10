// WAP to print the squares of "N" different elements
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
char menu();
int *create(int);
void delArr(int, int *);
void store(int, int *);
void findMin(int, int *);
void findMax(int, int *);
void gen_swap(void *, void *, int);
void sortArr(int, int, int *);
void srchByVal(int, int *, int);

// main function starts
int main(int argc, char *argv[])
{
    (void)argc;
    char ch, ch_2;
    int *arr, size, target, flag = 0;
    while (1)
    {
        system("cls");
        printf("Program Name : %s", argv[0]);
        printf("\n*********************************************\n");
        ch = menu();

        switch (ch)
        {
        case '1':
            if (1 != flag)
            {
                printf("\nEnter the size of the array to be created : ");
                scanf("%d", &size);
                arr = create(size);
                flag = 1;
            }
            else
                printf("\nDELETE the previous array first!!");
            break;

        case '2':
            if (1 == flag)
                delArr(size, &arr[0]);
            else
                printf("\nCREATE an array first!!");
            break;

        case '3':
            if (1 == flag)
                store(size, &arr[0]);
            else
                printf("\nCREATE an array first!!");
            break;

        case '4':
            if (1 == flag)
                findMin(size, &arr[0]);
            else
                printf("\nCREATE an array first!!");
            break;

        case '5':
            if (1 == flag)
                findMax(size, &arr[0]);
            else
                printf("\nCREATE an array first!!");
            break;

        case '6':
            if (1 == flag)
            {
                printf("\nSort array in ascending OR descending... (A/D)?\n");
                scanf("\n[ > ] : %c", &ch_2);
                if ('a' == ch_2 || 'A' == ch_2)
                    sortArr(1, size, &arr[0]);
                else if ('d' == ch_2 || 'D' == ch_2)
                    sortArr(0, size, &arr[0]);
                else
                    printf("\nInvalid Input.\nTRY AGAIN...\n");
            }
            else
                printf("\nCREATE an array first!!");
            break;

        case '7':
            if (1 == flag)
            {
                printf("\nSEARCH BY VALUE OR SEARCH BY INDEX... (V/I)?\n");
                scanf("\n[ > ] : %c", &ch_2);
                if ('v' == ch_2 || 'V' == ch_2)
                {
                    printf("\nEnter the value you would like to search..?");
                    scanf("%d", &target);
                    srchByVal(size, &arr[0], target);
                }
                else if ('i' == ch_2 || 'I' == ch_2)
                {
                    printf("\nEnter the index you would like to search..?");
                    scanf("%d", &target);
                    if (-1 < target < size)
                        printf("\nTarget found : arr[%d] = %d", target, arr[target]);
                    else
                        printf("\nInvalid Input.\nTRY AGAIN...\n");
                }
                else
                    printf("\nInvalid Input.\nTRY AGAIN...\n");
            }
            else
                printf("\nCREATE an array first!!");
            break;

        case '8':
            break;

        case '9':
            break;

        default:
            printf("\nInvalid Input.\nTRY AGAIN...\n");
            break;
        }
    }
    getchar();

    return 0;
}
// main function ends

// to display menu
char menu()
{
    char ch;
    printf("\n[ 1 ] : CREATE Array");
    printf("\n[ 2 ] : DELETE Array");
    printf("\n[ 3 ] : STORE DATA");
    printf("\n[ 4 ] : FIND MIN");
    printf("\n[ 5 ] : FIND MAX");
    printf("\n[ 6 ] : BUBBLE SORT ARRAY");
    printf("\n[ 7 ] : SEARCH");
    printf("\n[ 8 ] : RIGHT SHIFT");
    printf("\n[ 9 ] : LEFT SHIFT");
    scanf("\n[ > ] : %c", &ch);

    return ch;
}

// to create array
int *create(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    return arr;
}

void delete (int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = 0;
    free(arr);
    arr = NULL;
}

void store(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("\narr[%d] = ", i);
        scanf("%c", &arr[i]);
    }
    printf("\nArray Elements stored successfully!!\n");
}

void findMin(int size, int *arr)
{
    int i, min, pos;
    min = arr[0];
    for (i = 0; i < size; i++)
        if (min > arr[i])
        {
            min = arr[i];
            pos = i;
        }
    printf("\nMinimum Element : %d", min);
    printf("\nIndex position  : arr[%d]", pos);
}

void findMax(int size, int *arr)
{
    int i, max, pos;
    max = arr[0];
    for (i = 0; i < size; i++)
        if (max < arr[i])
        {
            max = arr[i];
            pos = i;
        }
    printf("\nMaximum Element : %d", max);
    printf("\nIndex position  : arr[%d]", pos);
}

void gen_swap(void *a, void *b, int size)
{
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void sortArr(int flag, int size, int *arr)
{
    int i, swaps = 1;
    if (1 == flag)
    {
        while (swaps != 0)
        {
            swaps = 0;
            for (i = 0; i < size; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    swaps = 1;
                    gen_swap(&arr[i], &arr[i + 1], sizeof(int));
                }
            }
        }
    }
    else
    {
        while (swaps != 0)
        {
            swaps = 0;
            for (i = 0; i < size; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    swaps = 1;
                    gen_swap(&arr[i], &arr[i + 1], sizeof(int));
                }
            }
        }
    }
}

void srchByVal(int size, int *arr, int target)
{
    int i;
    for(i=0;i<size && target != arr[i];i++){

    }
}