#include <stdio.h>
#define size 100

typedef struct stack
{
    int arr[size];
    int top;
} stack;

stack stk;

int isEmpty()
{
    return stk.top == -1;
}

int isFull()
{
    return stk.top == size - 1;
}

void push(int num)
{
    if (!isFull())
    {
        stk.top++;
        stk.arr[stk.top] = num;
    }
    else
    {
        printf("stack full");
    }
}

int pop()
{
    if (!isEmpty())
    {
        int item;
        item = stk.arr[stk.top];
        stk.top--;
        return item;
    }
    else
    {
        printf("empty");
    }
}

int main(int argc, char const *argv[])
{
    stk.top = -1;
    int n, ch;
    char d[] = "0123456789ABCDEF";
    printf("enter a no.");
    scanf("%d", &n);

    do
    {
        printf("\n1...Binary");
        printf("\n2...Octal");
        printf("\n3...Hexadecimal");
        printf("\n4...EXIT");
        printf("\nenter choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            while (n > 0)
            {
                int r = n % 2;
                push(r);
                n /= 2;
            }

            printf("Binary representation\n");
            while (!isEmpty())
            {
                printf("%d\n", pop());
            }
            break;

        case 2:
            while (n > 0)
            {
                int r = n % 8;
                push(r);
                n /= 8;
            }

            printf("Octal representation\n");
            while (!isEmpty())
            {
                printf("%d\n", pop());
            }
            break;

        case 3:

            while (n > 0)
            {
                int r = n % 16;
                push(r);
                n /= 16;
            }

            printf("Hexadecimal representation\n");
            while (!isEmpty())
            {
                printf("%c\n", d[pop()]);
            }
            break;

        case 4:
            printf("bye");
            break;

        default:
            printf("enter a valid choice");
        }
    } while (ch != 2);

    return 0;
}
