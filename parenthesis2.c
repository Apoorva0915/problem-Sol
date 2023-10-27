#include <stdio.h>
#include<string.h>

#define size 100

typedef struct stack
{
    char arr[size];
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

int peep(){
    if (!isEmpty())
    {
        return stk.arr[stk.top];
    }
    
}

int getCode(char b){
    switch (b)
    {
    case '(':
         return 1;
        break;
    case ')':
         return -1;
        break;
    case '{':
         return 2;
        break;
    case '}':
         return -2;
        break;
    case '[':
         return 3;
        break;
    case ']':
         return -3;
        break;
    
    default:
        break;
    }
}






int validateParenthesis(char ex[]){
    stk.top=-1;
    int i=0;
    while (ex[i]!='\0')
    {
        char b= ex[i];
        if(getCode(b)>0){
            push(b);
        }
        else{
            if(!isEmpty()){
                 if(getCode(b)+getCode(peep())==0){
                    pop();
                 }else{
                    return 0;
                 }
            }else{
                return 0;
            }
        }
        i++;
    }
    return isEmpty();

}


int validateBrackets(char ex[]){
 int i=0;
    while (ex[i]!='\0')
    {
        // printf("%c\n",ex[i]);    

    char bracket=ex[i];
    if(bracket=='('){
        push(bracket);
    }
    else if(bracket==')'){
        if(!isEmpty()){
            pop();
        }else{
            return 0;
        }
    }
    i++;
 }
 return isEmpty();
}

int main(int argc, char const *argv[])
{
    /* code */
    stk.top=-1;
    char ex[100];
    printf("Enter any expression\n");
    gets(ex);
    
    if(validateParenthesis(ex)){
        printf("Valid expression");
    }
    else
    {
        printf("Invalid expression");
    }
    
    
    return 0;
}
