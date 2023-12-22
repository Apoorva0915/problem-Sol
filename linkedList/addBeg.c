#include <stdio.h>
#include <malloc.h>
struct Node
{
    int info;
    struct Node *next;
};
void show(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}

void addBeg(struct Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;

    if (*s == NULL)
        newNode->next = NULL;
    else
        newNode->next = *s;

    *s = newNode;
    printf("Node is added\n");
}

int main()
{
    struct  Node *start =NULL;

    addBeg(&start,100);
    addBeg(&start,200);
    addBeg(&start,300);
    addBeg(&start,400);

    show(start);
    return 0;
}