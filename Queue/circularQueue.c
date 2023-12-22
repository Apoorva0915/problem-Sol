#include <stdio.h>
#define SIZE 10

typedef struct circularQueue
{
    int front;
    int rear;
    int data[SIZE];
} circularQueue;

circularQueue queue;

void reset()
{
    queue.front = queue.rear = -1;
}

int isFull()
{
    return (queue.rear + 1) % SIZE == queue.front;
}

int isEmpty()
{
    return queue.front == queue.rear == -1;
}

void enqueue()
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else if (isEmpty())
    {
        queue.front == queue.rear == 0;
    }
    else
    {
        queue.rear = (queue.rear + 1) % SIZE;
    }
    int n;
    printf("enter any no.");
    scanf("%d", &n);
    queue.data[queue.rear] = n;
    printf("Number Inserted\n");
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    int item = queue.data[queue.front];
    if (queue.front == queue.rear)
    {
        reset();
    }
    else
    {
        queue.front = (queue.front + 1) % SIZE;
        printf("%d is deleted", item);
    }
}

void show()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    printf("Elements of Queue are: \n");

    int i = queue.front;
    do
    {
        printf("%d ", queue.data[i]);
        i = (i + 1) % SIZE;
    } while (i != queue.rear+1);
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
