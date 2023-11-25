#include <stdio.h>
#define Size 10

typedef struct LinQueue
{
    int front;
    int rear;
    int data[Size];
} LinQueue;

LinQueue queue;

void reset()
{
    queue.front = 0;
    queue.rear = -1;
}

int IsEmpty()
{
    return queue.front > queue.rear;
}

int isFull()
{
    return queue.rear == Size - 1;
}

void enQue()
{
    if (isFull())
    {
        printf("Queue is full");
        return;
    }
    int n;
    printf("enter any no.");
    scanf("%d", &n);
    // queue.rear+=1;
    // queue.data[queue.rear]=n;
    queue.data[++queue.rear] = n;
    printf("number inserted\n");
}

void deQue()
{
    if (IsEmpty())
    {
        printf("Queue is empty");
        return;
    }
    if (queue.front == queue.rear)
    {
        reset();
    }
    else
    {
        int item = queue.data[queue.front];
        queue.front += 1;
        printf("%d is deleted", item);
        // return item;
    }
}

void show()
{
    printf("Front=%d,Rear=%d\n", queue.front, queue.rear);
    if (IsEmpty())
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue elements are \n");
    for (int i = queue.front; i <= queue.rear; i++)
    {
        printf("%d", queue.data[i]);
    }
}

int main()
{
    reset();
    int choice;
    printf("\nQUEUE USING STACKS IMPLEMENTATION\n\n");
    printf("\n1.ENQUEUE");
    printf("\n2.DEQUEUE");
    printf("\n3.DISPLAY");
    // printf("\n4.EXIT");
    printf("\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQue();
            break;
        case 2:
            deQue();
            break;
        case 3:
            show();
            break;
        // case 4:
        // exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}






















// #include <stdio.h>
// #include<stdlib.h>
// #define CAPACITY 50
 
// void insert();
// void delete();
// void display();
// int queue_array[CAPACITY];
// int rear = - 1;
// int front = - 1;
// void main()
// {
//     int choice;
//     while (1)
//     {
//         printf("1.Enter 1 to insert element to queue \n");
//         printf("2.Enter 2 to delete element from queue \n");
//         printf("3.Enter 3 to display all elements of queue \n");
//         printf("4.Enter 4 to quit \n");
//         printf("Enter your choice : ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//             case 1:
//             insert();
//             break;
//             case 2:
//             delete();
//             break;
//             case 3:
//             display();
//             break;
//             case 4:
//             exit(1);
//             default:
//             printf("Wrong choice \n");
//         } 
//     } 
// } 
 
// void insert()
// {
//     int element;
//     if (rear == CAPACITY - 1)
//     printf("Queue is full\n");
//     else
//     {
//         if (front == - 1)
        
//         front = 0;
//         printf("Enter element which is to be inserted ");
//         scanf("%d", &element);
//         rear = rear + 1;
//         queue_array[rear] = element;
//     }
// } /* End of insert() */
 
// void delete()
// {
//     if (front == - 1 || front > rear)
//     {
//         printf("Queue is empty we cannot delete an element  \n");
//         return ;
//     }
//     else
//     {
//         printf("Element deleted from queue is : %d\n", queue_array[front]);
//         front = front + 1;
//     }
// } /* End of delete() */
 
// void display()
// {
//     int i;
//     if (front==-1 || front > rear)
//         printf("Queue is empty \n");
//     else
//     {
//         printf("Elements of Queue are: \n");
//         for (i = front; i <= rear; i++)
//             printf("%d ", queue_array[i]);
//         printf("\n");
//     }
// }




