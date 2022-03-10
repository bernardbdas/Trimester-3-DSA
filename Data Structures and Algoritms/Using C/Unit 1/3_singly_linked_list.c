// Program to implement Doubly Linked List with iterative functions
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} NODE;

//FUNCTION PROTOTYPES :-
//insert functions
NODE *insert_first(NODE *, int);
NODE *insert_last(NODE *, int);
NODE *insert_at_pos(NODE *, int, int);
//delete functions
NODE *delete_first(NODE *);
NODE *delete_last(NODE *);
NODE *delete_from_pos(NODE *, int);
//other functions
void display(NODE *);
void rev_disp(NODE *);
void search(NODE *, int);
int length_of_list(NODE *);
void clear_list(NODE *);

//FUNCTION DEFINITIONS :-
//insert functions
NODE *insert_last(NODE *head, int val)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    if (!head)
    {
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        temp = NULL;
        free(temp);
    }
    else
    {
        NODE *p = head;
        while (p->next)
            p = p->next;
        p->next = temp;
        p->next->prev = p;
        p->next->next = NULL;
        p = NULL;
        temp = NULL;
        free(p);
        free(temp);
    }

    return head;
}

NODE *insert_first(NODE *head, int val)
{
    if (!head)
        return insert_last(head, val);
    else
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = val;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        temp = NULL;
        free(temp);
        return head;
    }
}

NODE *insert_at_pos(NODE *head, int val, int pos)
{
    int i;
    if (!head)
        return insert_last(head, val);
    else if (pos < length_of_list(head))
    {
        if (pos == 0)
        {
            return insert_first(head, val);
        }
        else
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            NODE *p = head;
            temp->data = val;
            for (i = 1; i < pos - 1; i++)
                p = p->next;
            temp->next = p->next;
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            return head;
        }
    }
    else
    {
        printf("Position out of bounds!");
        getch();
        return head;
    }
}

//delete functions
NODE *delete_last(NODE *head)
{
    int del;
    if (!head)
    {
        printf("The List has no elements to delete.");
        return head;
    }
    else
    {
        NODE *p = head;
        while (p->next->next)
            p = p->next;
        del = p->next->data;
        free(p->next);
        p->next = NULL;
        return head;
    }
}

NODE *delete_first(NODE *head)
{
    int del;
    if (!head)
    {
        printf("The List has no elements to delete.");
        return head;
    }
    else
    {
        NODE *temp = head;
        head = head->next;
        temp->next = temp->prev = NULL;
        printf("\n%d has been deleted from the linked list successfully", temp->data);
        free(temp);
        return head;
    }
}

NODE *delete_from_pos(NODE *head, int pos)
{
    int i;
    if (!head)
    {
        printf("The List has no elements to delete.");
        return head;
    }
    else if (pos < length_of_list(head))
    {
        if (pos == 0)
        {
            return delete_first(head);
        }
        else
        {
            NODE *p = head, *q;
            for (i = 1; i < (pos - 1); i++)
                p = p->next;
            q = p->next;
            p->next->prev = p;
            q->prev = NULL;
            q->next = NULL;
            printf("%d at position %d has been deleted successfully.", q->data, pos);
            free(q);
            q = NULL;

            return head;
        }
    }
    else
    {
        printf("Position out of bounds!");
        getch();
        return head;
    }
}

//other functions
void display(NODE *head)
{
    if (head == NULL)
        printf("The List has no elements to print.");
    else
    {
        NODE *temp = head;
        while (temp->next)
        {
            printf("[ %d ]\t", temp->data);
            temp = temp->next;
        }
        printf("[ %d ]\t", temp->data);
        temp = NULL;
        free(temp);
    }
}

void rev_disp(NODE *head)
{

    if (!head)
        printf("The List has no elements to print.");
    else
    {
        NODE *temp = head;
        while (temp != NULL)
            temp = temp->next;

        while (temp != NULL)
        {
            printf("[ %d ]\t", temp->data);
            temp = temp->prev;
        }
        printf("[ %d ]\t", temp->data);
        temp = NULL;
        free(temp);
    }
}

void search(NODE *head, int val) //cannot search for duplicate elements as of now
{
    int i = 0, flag = 0;
    if (!head)
        printf("The List has no elements to search from.");
    else
    {
        NODE *temp = head;
        do
        {
            if (temp->data == val)
            {
                flag = 1;
                break;
            }
            i++;
            temp = temp->next;
        } while (temp != NULL);

        if (flag)
            printf("The element %d has been found in the list at position %d.", val, i);
        else
            printf("The element %d could not be found in the list.", val, i);
        temp = NULL;
        free(temp);
    }
}

int length_of_list(NODE *head)
{
    int i = 0;
    if (!head)
        printf("The List has no elements.");
    else
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        temp = NULL;
        free(temp);
    }
    return i;
}

void clear_list(NODE *head)
{
    if (!head)
        printf("The List has no elements to clear.");
    else
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            temp->data = 0;
            temp = temp->next;
        }
        temp = NULL;
        free(temp);
    }
}

int menu()
{
    int op;
    printf("\n[ 1 ] : to INSERT a node at the end");
    printf("\n[ 2 ] : to INSERT a node at the begining");
    printf("\n[ 3 ] : to INSERT a node at a given position in the list");
    printf("\n[ 4 ] : to DELETE a node from the end");
    printf("\n[ 5 ] : to DELETE a node from the begining");
    printf("\n[ 6 ] : to DELETE a node from a given position in the list");
    printf("\n[ 7 ] : to DISPLAY the linked list");
    printf("\n[ 8 ] : to DISPLAY the linked list in reverse order");
    printf("\n[ 9 ] : to SEARCH for an element in the linked list");
    printf("\n[ 10] : to return the LENGTH of the linked list");
    printf("\n[ 11] : to CLEAR the linked list");
    printf("\n[ 12] : to TERMINATE program");
    printf("\n\n[ > ] : ");
    scanf("%d", &op);

    return op;
}

int main()
{
    int val, op, pos, len;
    system("cls");
    NODE *head = NULL;

    do
    {
        system("cls");
        op = menu();
        switch (op)
        {
        case 1: //insert an element at the end
            printf("\n[   ] : Enter a number and press enter to load in the list");
            printf("\n\n[ > ] : ");
            scanf("%d", &val);
            head = insert_last(head, val);
            break;

        case 2: //insert an element at the begining
            printf("\n[   ] : Enter a number and press enter to load in the list");
            printf("\n\n[ > ] : ");
            scanf("%d", &val);
            head = insert_first(head, val);
            break;

        case 3: //insert an element at a specific position
            printf("\n[   ] : Enter the position where you want to place this number in the list");
            printf("\n\n[ > ] : ");
            scanf("%d", &pos);
            printf("\n[   ] : Enter a number and press enter to load in the list");
            printf("\n\n[ > ] : ");
            scanf("%d", &val);
            head = insert_at_pos(head, val, pos);
            break;

        case 4: //delete an element from end
            head = delete_last(head);
            printf("\n%d has been deleted from the linked list successfully", val);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 5: //delete an element from first
            head = delete_first(head);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 6: //delete an element from a specific position
            printf("\n[   ] : Enter the position from where you want to delete the number in the list");
            printf("\n\n[ > ] : ");
            scanf("%d", &pos);
            head = delete_from_pos(head, pos);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 7: //display the linked list
            display(head);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 8: //display the linked list in reverse order
            rev_disp(head);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 9: //search for a given element in the linked list
            printf("[   ] : Enter the element you want to search for : ");
            scanf("%d", &val);
            search(head, val);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 10: //return the length of the list
            len = length_of_list(head);
            if (len)
                printf("\n[   ] : The LENGTH of the list is : %d", len);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 11: //clear the linked list
            clear_list(head);
            printf("\nPress any key to continue ...");
            getch();
            break;

        case 12: // terminate the program
            system("exit");
            break;

        default:
            printf("\nINVALID INPUT!\nTRY AGAIN...\n\n");
            getch();
            break;
        }
    } while (1);

    return 0;
}