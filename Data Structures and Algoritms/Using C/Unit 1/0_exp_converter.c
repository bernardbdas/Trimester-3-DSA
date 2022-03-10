#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION PROTOTYPES :-
// conversion functions
char *toinfix(int, char *);
char *toprefix(int, char *);
char *topostfix(int, char *);
//

// PRECEDENCE OF OPERATORS
//  (higher to lower) :-
//  *, /, %
//  +, -
//  (, )

char *toinfix(int len, char *exp)
{
    return exp;
}

char *toprefix(int len, char *exp)
{
    return exp;
}

char *topostfix(int len, char *exp)
{
    return exp;
}

int isOperator(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// int getlen(char *exp)
//{
//     int len = 0;
//     char ch;
//     while (ch != '\0')
//     {
//         len++;
//         ch = exp[len];
//     }
//
//     return len;
// }

int chkExp(int len, char *exp)
{
    int i = 0, j;
    char first, last;
    j = len - 1;

    first = exp[i];
    last = exp[j];

    while (first == '(' || first == '{' || first == '[')
        first = exp[++i];

    while (last == ')' || last == '}' || last == ']')
        last = exp[--j];

    // fflush(stdout);
    // putchar(first);
    // fflush(stdout);
    // putchar(last);
    //  PREFIX    -> first : operator, last : operand
    //  INFIX     -> first : operand, last : operand
    //  POSTFIX   -> first : operand, last : operator

    if (isOperator(first))
    {
        if (isOperator(last))
        {
            printf(" [is an INVALID EXPRESSION!!]\nTRY AGAIN...\n");
            getchar();
            return 0;
        }
        else
            return 1; // prefix
    }
    else if (isOperator(last))
        return 3; // postfix
    else
        return 2; // infix
}

int main(int argc, char *argv[])
{
    (void)argc;
    system("cls");
    printf("Program Name : %s", argv[0]);
    printf("\n*********************************************\n");
    printf("\nGiven Expression   : %s ", argv[1]);
    // printf("\nno. of chars : %d ", strlen(argv[1]));

    if (chkExp(strlen(argv[1]), argv[1]) == 0)
        return 0;
    else if (chkExp(strlen(argv[1]), argv[1]) == 1)
    {
        printf(" [is a PREFIX Expression]\n");
        printf("\nINFIX   Expression : %s", toinfix(strlen(argv[1]), argv[1]));
        printf("\nPOSTFIX Expression : %s", topostfix(strlen(argv[1]), argv[1]));
    }
    else if (chkExp(strlen(argv[1]), argv[1]) == 2)
    {
        printf(" [is an INFIX Expression]\n");
        printf("\nPREFIX  Expression : %s", toprefix(strlen(argv[1]), argv[1]));
        printf("\nPOSTFIX Expression : %s", topostfix(strlen(argv[1]), argv[1]));
    }
    else
    {
        printf(" [is a POSTFIX Expression]\n");
        printf("\nPREFIX  Expression : %s", toprefix(strlen(argv[1]), argv[1]));
        printf("\nINFIX   Expression : %s", toprefix(strlen(argv[1]), argv[1]));
    }

    return 0;
}