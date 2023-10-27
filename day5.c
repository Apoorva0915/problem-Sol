#include<stdio.h>
#define size 10

typedef struct stack
{
    int arr[size];
    int top;
} stack;

stack stk;

int isEmpty(){
    return stk.top==-1;
}

int isFull(){
    return stk.top==size-1;
}

void push(int num){
    if(!isFull()){
        stk.top++;
        stk.arr[stk.top]=num;
    } else{
        printf("stack full");
    }
}

int pop(){
    if(!isEmpty()){
        int item;
        item=stk.arr[stk.top];
        stk.top--;
        return item;
    }
    else{
        printf("empty");
    }
}
void show(){
    if(!isEmpty()){
        for(int i=stk.top;i>=0;i--){
            printf("%d\n",stk.arr[i]);
        }
    }else{
     printf("stack empty");
    }
}


int peep(){
    if(!isEmpty()){
       return stk.arr[stk.top];
    }
  printf("stack empty");
  return -1;
}

int main(int argc, char const *argv[])
{
    int num;
    int ch,x;

    stk.top=-1;
    do
    {
        printf("\n1...push");
        printf("\n2...pop");
        printf("\n3...show");
        printf("\n4...peep");
        printf("\n5...EXIT");
        printf("\nenter choice\n");
        scanf("%d", &ch);

    switch (ch)
    {
    case 1:
         printf("enter a no.");
         scanf("%d",&num);
         push(num);
        break;
    
    case 2:
         pop();
        break;
    
    case 3:
         show();
        break;
    
    case 4:
        x= peep();
        printf("%d",x);
        break;
    
    case 5:
         printf("bye bye");
        break;
    
    default:
      printf("enter a valid choice");
    }
    } while (ch !=5);
    
    
    return 0;
}
