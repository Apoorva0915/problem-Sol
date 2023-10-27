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

int precedence(char topop, char op2){
    if(topop=='$'||topop=='*'|| topop=='/'||topop=='%'){
        // if (topop=='$')
        // {
        //     return 0;
        // }else{
        //     return 1;
        // }
        return op2!='$';
    }else{
        if (op2=='+'|| op2=='-')
        
            return 1;
        
        return 0;
    
        
    }
}


int InfixToPostfix(char expr[]){
  int i=0,j=0;
  char prefix[size];
  while (i>=0)
  {
     char s=expr[i++];
    if(s>='a'&& s<='z'|| s>='A'&& s<='Z'|| s>='0'&& s<='9' ){
        prefix[j++]=s;
    }else if(isEmpty()||s=='('){
        push(s);
    }else if (s==')')
    {
        while (peep()!='(')
        {
            prefix[j++]=pop();
        }
        pop();
    }
    
    else{
        while (!isEmpty() && peep()!='(' && precedence(peep(),s))
        {
           prefix[j++]=pop();
        }
       push(s);
    }

  }

  while (!isEmpty())
  {
    prefix[j++]=pop();
  }
  prefix[j]='\0';
  printf("\n Result of expression in postfix : %s \n",prefix);
  
//   printf("\n Result of expression in postfix : %s \n", pop());
  
}


int main()
{
     stk.top = -1;
    char expr[size];
    printf("Enter any infix expression\n");
    gets(expr);
    printf("\nInfix=%s\n",expr);
    InfixToPostfix(expr);


    return 0;
}

// A+B*C/D$E$F*G

