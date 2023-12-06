#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;

} Node;

// start will point to last node

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void show(Node **s)
{
    if (*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp;
    temp = (*s)->next;
    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != (*s)->next);
}

void addBeg(Node **start, int value)
{
    Node *newnode = createNode(value);
    if (*start == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        *start = newnode;
        return;
    }
    newnode->next = (*start)->next;
    (*start)->next = newnode;
    newnode->prev = (*start);
    Node *temp = newnode->next;
    temp->prev = newnode;
}

void addLast(Node **start, int value)
{
    Node *newnode = createNode(value);
    if (*start == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        *start = newnode;
        return;
    }
    newnode->next = (*start)->next;
    (*start)->next = newnode;
    newnode->prev = (*start);
    Node *temp = newnode->next;
    temp->prev = newnode;
    (*start) = newnode;
}

Node *search(Node *start, int info)
{
    if (start == NULL)
        return NULL;
    Node *temp = start->next;
    do
    {
        if (temp->info == info)
            return temp;
        temp = temp->next;
    } while (temp != start->next);
    return NULL;
}

void addAfter(Node **start, int info, int value)
{
    Node *temp = search(*start, info);
    if (temp == NULL)
    {
        printf("Info not found");
        return;
    }
    Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void addBefore(Node **start, int info, int value)
{
    Node *temp = search(*start, info);
    if (temp == NULL)
    {
        printf("Info not found");
        return;
    }
    Node *newNode = createNode(value);
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
}

void delBeg(Node **start)
{
    if (*start == NULL)
    {
        printf("empty list");
        return;
    }
    if ((*start)->next == *start)
    {
        *start = NULL;
    }

    Node *temp = (*start)->next;
    temp->next->prev = *start;
    (*start)->next = temp->next;
    free(temp);
}

void delLast(Node **start)
{
    if (*start == NULL)
    {
        printf("empty List");
        return;
    }

    if ((*start)->next == *start)
    {
        *start = NULL;
    }
    Node *temp = (*start)->prev;
    (*start)->next->prev = temp;
    temp->next = (*start)->next;
    *start = temp;
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
        printf("\n Doubly circular linked list premptive operations\n");
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