// circular queue if full if (rear + 1) % size == front
#include<stdio.h>
#define size 10

typedef struct circularQueue{
    int front;
    int rear;
    int data[size];
}circularQueue;

circularQueue cirQueue;

void reset(){
    cirQueue.rear = -1;
    cirQueue.front = 0;
}

int isEmpty(){
    return cirQueue.rear == -1 || (cirQueue.front + 1) % size == cirQueue.rear;
}

int isFull(){
    return (cirQueue.rear + 1) % size == cirQueue.front;
}
void enqueue(){
    cirQueue.rear = cirQueue.rear + 1;
    cirQueue.rear = (cirQueue.rear + 1) % size;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty");
        return -1;
    }
    else{
        int num = cirQueue.data[cirQueue.front];
        cirQueue.front++;
        printf("%d removed", num);
        return num;
    }
}

int main(){



    return 0;
}