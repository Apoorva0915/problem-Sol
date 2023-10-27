 #include <stdio.h>
 #include<string.h>

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
int main(){
    stk.top=-1;
    char str[size];
    printf("Enter a string\n");
    gets(str);
    for(int i=0;i<strlen(str);i++){
        push(str[i]);  
    }
    for(int i=0;i<strlen(str);i++){
        if(pop()!=str[i]){
            printf("not a pallindrome\n");
            return 0;
        }
    }
    printf("pallindrome");
    return 0;
    
}