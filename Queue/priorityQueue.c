// lowest value highest priority

#include <stdio.h>
#define size 10

int front;
int rear;
int queue[size];

void reset()
{
    front = rear = -1;
}

int isFull()
{
    return rear == size - 1;
}

int IsEmpty()
{
    return front == -1 || front > rear ;
}

void updateEnqueue(){
    int temp=queue[rear];
    int i=rear-1;
    while(i>=front && temp<queue[i]){
        queue[i+1]=queue[i];
        i--;
    }
    queue[i+1]=temp;
}

void enQue()
{
    if (isFull())
    {
        printf("queue is full\n");
    }
     else
    {
        if (front == -1)
            front = 0;

        int n;
       printf("enter any no.");
        scanf("%d", &n);
        rear += 1;
        queue[rear] = n;
        printf("Number Inserted\n");
        updateEnqueue();
    }
}

void show()
{
    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }

    printf("Elements of Queue are: \n");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


void updateQueue(){
    for (int i = rear; i>front; i--)
    {
        if (queue[i]<queue[i-1]){
            int t=queue[i];
            queue[i]=queue[i-1];
            queue[i-1]=t;
        }
    }
    
}

void dequeue()
{

    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    // updateQueue();
    if (front == rear)
    {
        reset();
    }
    int item =queue[front];
    front += 1;
    printf("%d is deleted \n", item);
}

int main()
{
    reset();
    for (int i = 1; i<=7; i++)
    {
       enQue();
    }
    show();
    printf("\n");
    dequeue();
    show();
    
}
