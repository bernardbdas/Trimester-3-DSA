#include <stdio.h>
#include <stdlib.h>

void createEmpty(int[], int);
void printArray(int[], int);

int main()
{
    int size, *arr_a, *arr_c;
    printf("\nEnter the size of the array : ");
    scanf("%d", &size);
    // dynamically creating two arrays
    //int *arr_a = (int *)malloc(size * sizeof(int));
    int *arr_b = (int *)malloc(size * sizeof(int));
    printf("Base Address of arr_a : %x", arr_a);
    printf("\nBase Address of arr_b : %x\n", arr_b);
    printf("\n(calling createEmpty() function ...)");
    arr_c = createEmpty(arr_a, size);
    printf("\n(calling printArray() function ...)");
    printArray(arr_b, size);

    return 0;
}

void createEmpty(int *arr1, int size)
{
    int i;
    int *arr_1 = (int *)malloc(size * sizeof(int));
    printf("\n(inside createEmpty() function ...)");
    printf("\nBase Address of arr1 : %x", arr1);
    printf("\n(calling printArray() function ...)");
    printArray(arr1, size);
    printf("\n\nInitialized all values with 5");
    for (i = 0; i < size; i++)
        arr1[i] = 5;
    printf("\nEmpty array of size %d created!!", size);
    printf("\n(calling printArray() function ...)");
    printArray(arr1, size);
    printf("\n(exit createEmpty() function ...)\n");
}

void printArray(int *arr2, int size)
{
    int i;
    printf("\n(inside printArray() function ...)");
    printf("\nBase Address of arr2 : %x", arr2);
    for (i = 0; i < size; i++)
    {
        printf("\n\nvalue : %d", *(arr2 + i));
        printf("\naddress : %x", (arr2 + i));
    }
}
