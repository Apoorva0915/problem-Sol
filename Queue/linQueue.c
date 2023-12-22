#include <stdio.h>
#define SIZE 10

typedef struct LinQueue
{
    int front;
    int rear;
    int data[SIZE];
} LinQueue;

LinQueue queue;

int isFull()
{

    return queue.rear == SIZE - 1;
}

int IsEmpty()
{

    return queue.front == -1 || queue.front > queue.rear;
}

void reset()
{
    queue.front = queue.rear = -1;
}

void enqueue()
{

    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (queue.front == -1)
            queue.front = 0;

        int n;
       printf("enter any no.");
        scanf("%d", &n);
        queue.rear += 1;
        queue.data[queue.rear] = n;
        printf("Number Inserted\n");
    }
}

void dequeue()
{

    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    if (queue.front == queue.rear)
    {
        reset();
    }
    int item = queue.data[queue.front];
    queue.front += 1;
    printf("%d is deleted", item);
}

void show()
{
    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }

    printf("Elements of Queue are: \n");
    for (int i = queue.front; i <= queue.rear; i++)
        printf("%d ", queue.data[i]);
    printf("\n");
}

int main()
{

    reset();
    int choice;

    while (1)
    {
        printf("\nQUEUE USING STACKS IMPLEMENTATION\n\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.SHOW");
        printf("\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;

        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
