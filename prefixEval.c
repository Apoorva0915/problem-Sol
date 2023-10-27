// #include <stdio.h>
// #include <string.h>

// #define size 100

// typedef struct stack
// {
//     char arr[size];
//     int top;
// } stack;

// stack stk;

// int isEmpty()
// {
//     return stk.top == -1;
// }

// int isFull()
// {
//     return stk.top == size - 1;
// }

// void push(int num)
// {
//     if (!isFull())
//     {
//         stk.top++;
//         stk.arr[stk.top] = num;
//     }
//     else
//     {
//         printf("stack full");
//     }
// }
// int pop()
// {
//     if(!isEmpty())
//     {
//         return stk.arr[stk.top--];
//     }
// }

// int peep()
// {
//     if (!isEmpty())
//     {
//         return stk.arr[stk.top];
//     }
// }

// int getCode(char b)
// {
//     switch (b)
//     {
//     case '(':
//         return 1;
//         break;
//     case ')':
//         return -1;
//         break;
//     case '{':
//         return 2;
//         break;
//     case '}':
//         return -2;
//         break;
//     case '[':
//         return 3;
//         break;
//     case ']':
//         return -3;
//         break;

//     default:
//         break;
//     }
// }

// int calc(int a, int b, char op)
// {
//     switch (op)
//     {
//     case '+':
//         return a + b;
//         break;
//     case '-':
//         return a - b;
//         break;
//     case '*':
//         return a * b;
//         break;
//     case '/':
//         return a / b;
//         break;
//     case '%':
//         return a % b;
//         break;

//     default:
//         break;
//     }
// }

// int preFix(char expr[])
// {

//     int i = 0;

//     while (expr[i] != '\0')
//     {
//         i++;
//     }
//     i--;
//     while (i >= 0)
//     {
//         char s = expr[i];
//         if (s >= '0' && s <= '9')
//             push(s);
//         else
//         {
//             char a = pop();
//             char b = pop();
//             char c = calc(a, b, s);
//             push(c);
//         }
//         i--;
//     }
//     return stk.top;
// }

// int validateParenthesis(char ex[])
// {
//     stk.top = -1;
//     int i = 0;
//     while (ex[i] != '\0')
//     {
//         char b = ex[i];
//         if (getCode(b) > 0)
//         {
//             push(b);
//         }
//         else
//         {
//             if (!isEmpty())
//             {
//                 if (getCode(b) + getCode(peep()) == 0)
//                 {
//                     pop();
//                 }
//                 else
//                 {
//                     return 0;
//                 }
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         i++;
//     }
//     return isEmpty();
// }

// int validateBrackets(char ex[])
// {
//     int i = 0;
//     while (ex[i] != '\0')
//     {
//         // printf("%c\n",ex[i]);

//         char bracket = ex[i];
//         if (bracket == '(')
//         {
//             push(bracket);
//         }
//         else if (bracket == ')')
//         {
//             if (!isEmpty())
//             {
//                 pop();
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         i++;
//     }
//     return isEmpty();
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     stk.top = -1;
//     char ex[100];
//     printf("Enter any expression\n");
//     gets(ex);

//     preFix(ex);

//     // if(preFix(ex)){
//     //     printf("Valid expression");
//     // }
//     // else
//     // {
//     //     printf("Invalid expression");
//     // }

//     return 0;
// }






#include <stdio.h>

#define SIZE 100
typedef struct stack
{
    int top;
    int data[SIZE];
}stack;

stack stk;
void push(int item)
{

    if (stk.top >= SIZE - 1) {
        printf("stack over flow");
        return;
    }
    else {
        stk.top++;
        stk.data[stk.top] = item;
    }
}

int pop()
{
    int item;
    if (stk.top < 0) {
        printf("stack under flow");
    }
    else {
        item = stk.data[stk.top];
        stk.top--;
        return item;
    }
}

void EvalPrefix(char prefix[])
{

    // int i;
    char ch;
    int val;
    int A, B;

    int i = 0;

    while (prefix[i] != '\0')
    {
        i++;
    }
    i--;
    while(i>=0){
        ch = prefix[i];
        if (ch>='0' && ch<='9') {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = A * B;
                break;

            case '/':
                val = A / B;
                break;

            case '+':
                val = A + B;
                break;

            case '-':
                val = A - B;
                break;
            }

            /* push the value obtained above onto the stack */
            push(val);
        }
    i--;
    }
    printf("\n Result of expression evaluation : %d \n", pop());
}

int main()
{
     stk.top = -1;
    char expr[100];
    printf("Enter any expression\n");
    gets(expr);

    /* call function to evaluate postfix expression */

    EvalPrefix(expr);

    return 0;
}