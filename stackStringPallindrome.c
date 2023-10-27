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

int main(){
    stk.top=-1;
      char s[size];
      char r[size];
      gets(s);
      int i=0;
      while(s[i]!="\0"){
        push(s[i]);
        i++;
      }
      i=0;
      while (!isEmpty())
      {
         r[i]=pop();
         i++;
      }
      r[i]="\0";
      printf("Reverse= %s",r);
      

}