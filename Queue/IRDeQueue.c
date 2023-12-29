#include <stdio.h>
#define SIZE 10

int front;
int rear;
int queue[SIZE];

int isFull()
{

    return rear == SIZE - 1;
}

int IsEmpty()
{

    return front == -1 || front > rear;
}

void reset()
{
    front = rear = -1;
}

void enqueue(int n)
{

    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        // int n;
        // printf("enter any no.");
        // scanf("%d", &n);
        rear += 1;
        queue[rear] = n;
        printf("Number Inserted\n");
    }
}

void dequeue()
{

    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    if (front == rear)
    {
        reset();
    }
    printf("press 1 for front & 2 for rear \n");
    int choice;
    int item;
    scanf("%d", &choice);
    if (choice == 1)
    {
        item = queue[front];
        front += 1;
    }
    else if (choice == 2)
    {
        item = queue[rear];
        rear -= 1;
    }
    else
    {
        printf("choose from the given choice\n");
        return;
    }
    printf("%d is deleted \n", item);
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

int main()
{

    reset();
    // int choice;

    // while (1)
    // {
    //     printf("\nIR DeQUEUE USING ARRAY IMPLEMENTATION\n\n");
    //     printf("\n1.ENQUEUE");
    //     printf("\n2.DEQUEUE");
    //     printf("\n3.SHOW");
    //     printf("\n");
    //     printf("\nEnter your choice : ");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         enqueue();
    //         break;
    //     case 2:
    //         dequeue();
    //         break;
    //     case 3:
    //         show();
    //         break;

    //     default:
    //         printf("\nInvalid Choice\n");
    //     }
    // }
     for (int i = 1; i<=5; i++)
    {
       enqueue(i*10);
    }
    show();
    printf("\n");
    dequeue();
    show();
    return 0;
}
