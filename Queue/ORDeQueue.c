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

void enqueue()
{

    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        int choice;
        printf("press 1 for rear & 2 for front \n");
        scanf("%d", &choice);
        int n;
        printf("enter any no.");
        scanf("%d", &n);
        if (choice == 1)
        {
            rear += 1;
            queue[rear] = n;
        }
        else if (choice == 2)
        {
            if (front > 0)
            {
                front -= 1;
                queue[front] = n;
            }
            else
            {
                printf("insertion from front is not possible\n");
                return;
            }
        }
        else
        {
            printf("choose from the given choice\n");
            return;
        }
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
    int item = queue[front];
    front += 1;
    printf("%d is deleted", item);
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
    int choice;

    while (1)
    {
        printf("\nOR DeQUEUE USING ARRAY IMPLEMENTATION\n\n");
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
