#include <stdio.h>
#include <malloc.h>
struct Node
{
    int info;
    struct Node *prev;
    struct Node *next;
};

void show(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}

void addBeg(struct Node **start, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->prev = NULL;
    newnode->info = value;
    if (*start == NULL)
    {
        newnode->next = NULL;
    }
    else
    {
        newnode->next = *start;
        (*start)->prev = newnode;
    }
    *start = newnode;
}

void addAfter(struct Node **s, int value, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = *s;
    while (curr->info != info)
    {
        curr = curr->next;
    }
    newNode->info = value;
    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
}

void addBefore(struct Node **s, int value, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = *s;
    while (curr->info != info)
    {
        curr = curr->next;
    }
    if (curr->prev == NULL)
    {
        newNode->next = curr;
        curr->prev = newNode;
        newNode->prev = NULL;
        *s = newNode;
        return;
    }
    newNode->info = value;
    newNode->next = curr;
    newNode->prev = curr->prev;
    struct Node *back = curr->prev;
    back->next = newNode;
    curr->prev = newNode;
}

void addLast(struct Node **start, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->info = value;
    if (*start == NULL)
    {
        *start = newnode;
        newnode->prev = NULL;
    }
    else
    {
        struct Node *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void delBeg(struct Node **s)
{
    if (*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = *s;
    *s = (*s)->next;
    (*s)->prev = NULL;
    free(temp);
}

void delLast(struct Node **s)
{
    if (*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = *s;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct Node *back = temp->prev;
    back->next = NULL;
    free(temp);
}

void delNode(struct Node **s, int value){
    if(*s == NULL)
    {
        printf("Empty List, cannot delete\n");
        return;
    }
    struct Node *temp = *s;
    if((*s) -> info == value)
    {
        temp = *s;
        *s = (*s) -> next;
        free(temp);
        return;
    }
    while(temp != NULL)
    {
        if(temp -> info == value)
        {
            break;
        }
        temp = temp -> next;
    }
    if(temp == NULL)
    {
        printf("value not found\n");
        return;
    }
    else{
        struct Node *forward = temp -> next;
        temp -> next = forward -> next;
        if(forward -> next == NULL)
        {
            temp -> prev = NULL;
        }
        else
        {
            forward -> next -> prev = temp;
        }
        free(forward);
    }
}

int takeInput()
{
    int value;
    printf("Enter any value:");
    scanf("%d", &value);
    return value;
}

int main()
{
    struct Node *start = NULL;
    int choice, value, sinfo;
    do
    {
        printf("\n single linked list premptive operations\n");
        puts("1..............Insert at begin");
        puts("2..............Insert at Last");
        puts("3..............Insert before");
        puts("4..............Insert after");
        puts("5..............Delete from begin");
        puts("6..............Delete from last");
        puts("7..............Delete on info basis");
        puts("8..............Show");
        puts("9..............Exit");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            value = takeInput();
            addBeg(&start, value);
            break;
        case 2:
            value = takeInput();
            addLast(&start, value);
            break;
        case 3:
            printf("Sinfo: ");
            sinfo = takeInput();
            value = takeInput();
            addBefore(&start, sinfo, value);
            break;
        case 4:
            printf("Sinfo: ");
            sinfo = takeInput();
            value = takeInput();
            addAfter(&start, sinfo, value);
            break;
        case 5:
            delBeg(&start);
            break;
        case 6:
            delLast(&start);
            break;
        case 7:
            value = takeInput();
            delNode(&start, value);
        case 8:
            show(start);
            break;
        case 9:
            printf("Coded by Apoorva\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}