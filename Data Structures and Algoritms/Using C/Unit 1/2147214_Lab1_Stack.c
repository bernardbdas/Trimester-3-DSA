#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} NODE;

// Function Declarations :-
int getLen(NODE *);
NODE *srchByVal(NODE *);
NODE *srchByPos(NODE *);
NODE *searchStack(NODE *);
void printStack(NODE *);
int isEmpty(NODE *, NODE *);
NODE *initNODE(NODE *);
NODE *pop(NODE *);
NODE *push(NODE *, NODE *);
int menu();

// main function starts :-
int main(int argc, char *argv[])
{
    (void)argc;
    NODE *temp, *top = NULL, *bottom = NULL;
    int len = 0;

    // NODE *tn;
    // NODE *temp = (NODE *)malloc(sizeof(NODE));
    // temp->data = 36;
    // temp->next = (NODE *)malloc(sizeof(NODE));
    // temp->next->data = 48;
    // temp->next->next = NULL;
    // tn = temp;
    do
    {
        system("cls");
        switch (menu())
        {

        case 0:
            /* exit program */
            printf("\nExiting Program ...");
            exit(0);
            break;

        case 1:
            /* push */
            temp = push(top, bottom);
            if (!temp)
            {
                printf("\nError in pushing the data onto the stack.");
                break;
            }
            top = temp;
            printf("\nPushed the data onto the stack successfully.");
            break;

        case 2:
            /* pop */
            if (isEmpty(top, bottom))
                printf("\nStack is Empty!!\nNo Elements popped!");
            else
            {
                top = pop(top);
                printf("\nPopped data from the top of stack successfully.");
            }
            break;

        case 3:
            /* peek */
            if (isEmpty(top, bottom))
                printf("\nStack is Empty!!\nNo Elements to print!");
            else
                printf("\nTop element of stack : %d", top->data);
            break;

        case 4:
            /* print stack */
            if (isEmpty(top, bottom))
                printf("\nStack is Empty!!\nNo Elements to print!");
            else
                printStack(bottom);
            break;

        case 5:
            /* print stack in reverse */
            if (isEmpty(top, bottom))
                printf("\nStack is Empty!!\nNo Elements to print!");
            else
                printStack(top);
            break;

        case 6:
            /* search in stack */
            if (isEmpty(top, bottom))
                printf("\nStack is Empty!!\nNo Elements to search from!");
            else
            {
                temp = searchStack(bottom);
                if (!temp)
                    printf("\nElement NOT FOUND in stack!");
                else
                    printf("\nElement FOUND in stack!");
            }
            break;

        case 7:
            /* length of stack */
            if (isEmpty(top, bottom))
                printf("Length of Stack : 0");
            else
                printf("Length of Stack : %d", getLen(bottom));
            break;

        default:
            printf("\nINVALID INPUT!\nTRY AGAIN...\n\n");
            break;
        }
        printf("\nPress any key to continue ...");
        getch();
    } while (1);
    return 0;
}

// to check whether stack is full
// int isFull(NODE *top, NODE *bottom, int len)
//{
//    int diff = (int)(top - bottom) / sizeof(NODE);
//    if (diff == len)
//        return 1;
//    return 0;
//}

// to get length of stack
int getLen(NODE *start)
{
    int len = 0;
    NODE *temp = start;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// Search by Value
NODE *srchByVal(NODE *temp)
{
    int val;
    printf("\nEnter index position to search : ");
    scanf("%d", &val);
    while (!temp && temp->data != val)
        temp = temp->next;
}

// Search by Value
NODE *srchByPos(NODE *temp)
{
    int pos;
    printf("\nEnter index position to search : ");
    scanf("%d", &pos);
    while (pos)
    {
        temp = temp->next;
        pos--;
    }
}

// to search for an element in stack
NODE *searchStack(NODE *temp)
{
    int ch, len = 0;
    printf("\n[ 0 ] : By POSITION");
    printf("\n[ 1 ] : By VALUE");
    printf("\n\n[ > ] : ");
    scanf("%d", &ch);
    if (!ch)
        return srchByPos(temp);
    else
        return srchByVal(temp);
}

void printStack(NODE *start)
{
    NODE *temp = start;
    if (temp->next)
    {
        printf("\nIn Correct Order :-\n\t[ %d ]", temp->data);
        do
        {
            temp = temp->next;
            printf(" <> [ %d ]", temp->data);
        } while (temp);
    }
    else
    {
        printf("\nIn Reverse Order :-\n\t[ %d ]", temp->data);
        do
        {
            temp = temp->prev;
            printf(" <> [ %d ]", temp->data);
        } while (temp);
    }
}

// to check whether stack is empty
int isEmpty(NODE *top, NODE *bottom)
{
    if (top == bottom)
        return 1;
    return 0;
}

// to initialize a NODE
NODE *initNODE(NODE *temp)
{
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp != NULL)
    {
        printf("\nEnter data to PUSH : ");
        scanf("%d", &temp->data);
        // fflush(stdin);
        // fgets(temp->data, BUFFER, stdin);
        temp->next = NULL;
    }

    return temp;
}

NODE *pop(NODE *top)
{
    NODE *temp = top->prev;
    temp->next = NULL;
    free(top);
    top = NULL;

    return temp;
}

NODE *push(NODE *top, NODE *bottom)
{
    NODE *temp;
    if (isEmpty(top, bottom))
    {
        temp = initNODE(bottom);
        if (!temp)
            return temp;
        temp->prev = NULL;
    }
    else
    {
        temp = initNODE(top);
        if (!temp)
            return temp;
        temp->prev = top;
    }

    return temp;
}

int menu()
{
    int op;
    printf("\nEnter your choice :\n");
    printf("\n[ 1 ] : PUSH");
    printf("\n[ 2 ] : POP");
    printf("\n[ 3 ] : PEEK");
    printf("\n[ 4 ] : PRINT STACK");
    printf("\n[ 5 ] : PRINT STACK IN REVERSE");
    printf("\n[ 6 ] : SEARCH IN STACK");
    printf("\n[ 7 ] : LENGTH OF STACK");
    printf("\n[ 0 ] : EXIT PROGRAM");
    printf("\n\n[ > ] : ");
    scanf("%d", &op);
    return op;
}