#include <stdio.h>
#include<malloc.h>
struct Node
{
    int info;
    struct Node *next;
};

void show(struct Node *temp)
{
    if (temp == NULL)
    {
        printf("Empty List");
    }

    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

void addAfter(struct Node **s,int sinfo,int value)
{
    struct Node *temp = *s;
    if(*s == NULL){
        printf("List is empty");
        return;
    }
    while(temp->next != NULL)
    {
        if(temp->info == sinfo)
        {
            break;
        }
        temp =temp->next;
    }
    if(temp == NULL)
    {
        printf("%d not found\n",sinfo);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = value;
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node Added\n");
    }
}

void delBeg(struct Node **s)
{
    if(*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = *s;
    *s = (*s)->next;
    free(temp);
    printf("Node Deleted\n");
}

int main()
{
    struct Node *start = NULL;

    struct Node b;
    struct Node c;
    struct Node d;
    struct Node e;
    struct Node f;

    b.info = 100;
    start = &b;
    c.info = 200;
    b.next = &c;
    d.info = 300;
    c.next = &d;
    e.info = 400;
    f.info = 500;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    
    show(start);

    addAfter(&start,200,250);

    show(start);

    delBeg(&start);

    show(start);
      
    return 0;
}