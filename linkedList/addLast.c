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

void addlast(struct Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;
    struct Node *temp = *s;
    // checkig if list is empty
    if (*s == NULL)
    {
        *s = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("node addded\n");
}

void delLast(struct Node **s)
{
    if(*s == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*s)->next == NULL)
    {
        *s = NULL;
        return;
    }
    struct Node *prev, *curr;
    curr = (*s)->next;
    prev = *s;
    while(curr->next != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    free(curr);
    prev->next = NULL;
}

int main()
{
    struct node *start = NULL;
    addlast(&start, 100);
    addlast(&start, 200);
    addlast(&start, 300);
    show(start);
    return 0;
}
