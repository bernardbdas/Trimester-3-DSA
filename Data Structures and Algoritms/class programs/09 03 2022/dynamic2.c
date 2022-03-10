#include <stdio.h>
#include <stdlib.h>

void createEmpty(int **, int, int);
void printArray(int **, int, int);

int main()
{
    int i, rows, cols;
    printf("\nEnter the size of the array : ");
    printf("\nROWS : ");
    scanf("%d", &rows);
    printf("\nCOLUMNS : ");
    scanf("%d", &cols);
    // dynamically creating two array of pointers for 2-D array
    int **arr_a = (int **)malloc(rows * sizeof(int));
    for (i = 0; i < rows; i++)
        arr_a[i] = (int *)malloc(cols * sizeof(int));

    int **arr_b = (int **)malloc(rows * sizeof(int));
    for (i = 0; i < rows; i++)
        arr_b[i] = (int *)malloc(cols * sizeof(int));

    printf("Base Address of arr_a : %x", arr_a);
    printf("\nBase Address of arr_b : %x\n", arr_b);
    printf("\n(calling createEmpty() function ...)");
    createEmpty(arr_a, rows, cols);
    printf("\n(calling printArray() function ...)");
    printArray(arr_b, rows, cols);

    return 0;
}

void createEmpty(int **arr1, int rows, int cols)
{
    int i, j;
    printf("\n(inside createEmpty() function ...)");
    printf("\nBase Address of arr1 : %x", arr1);
    printf("\n(calling printArray() function ...)");
    printArray(arr1, rows, cols);
    printf("\n\nInitialized all values with 5");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            arr1[i][j] = 5;
    printf("\nEmpty array of size [ %d x %d ] created!!", rows, cols);
    printf("\n(calling printArray() function ...)");
    printArray(arr1, rows, cols);
    printf("\n(exit createEmpty() function ...)\n");
}

void printArray(int **arr2, int rows, int cols)
{
    int i, j;
    printf("\n(inside printArray() function ...)");
    printf("\n**********arr2**********\n\n");
    printf("\nBase Address of arr2 : %x\n", arr2);
    printf("\nPrinting Values in a matrix form ... \n\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("\t%d", arr2[i][j]);
        printf("\n");
    }
    printf("\nPrinting Addresses in a matrix form ... \n\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("\t%x", &arr2[i][j]);
        printf("\n");
    }
}
