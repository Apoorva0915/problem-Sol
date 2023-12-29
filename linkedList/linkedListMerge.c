#include <stdio.h>
#include <malloc.h>
struct Node
{
    int info;
    struct Node *next;
};

void show(struct Node *temp)
{
    if (temp == NULL)

    {
        printf("empty list");
        return;
    }
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

void addLast(struct Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = *s;
    // checkig if list is empty
    if (*s == NULL)
    {
        *s = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("node added\n");
}

void addAfter(struct Node **s, int sinfo, int value)
{
    if (*s == NULL)
    {
        printf("EMPTY LIST!!!");
        return;
    }
    struct Node *temp = *s;
    while (temp->next != NULL)
    {
        if (temp->info == sinfo)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d NOT FOUND!!!\n", sinfo);
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = value;
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Number Added\n");
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
    free(temp);
    printf("Node deleted\n");
}
void delLast(struct Node **s)
{
    if (*s == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*s)->next == NULL)
    {
        *s = NULL;
        return;
    }
    struct Node *prev, *curr;
    curr = (*s)->next;
    prev = *s;
    while (curr->next != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    free(curr);
    prev->next = NULL;
}
void delInfo(struct Node **s, int info)
{
    if (*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if ((*s)->info == info)
    {
        struct Node *temp = *s;
        *s = (*s)->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }
    struct Node *prev, *curr;
    prev = *s;
    curr = (*s)->next;
    while (curr != NULL)
    {
        if (curr->info == info)
        {
            break;
        }
        curr = curr->next;
        prev = prev->next;
    }
    if (curr == NULL)
    {
        printf("%d info not found\n", info);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
        printf("Node deleted\n");
    }
}

int searchElement(struct Node **s, int item)
{
    struct Node *current = *s; // Initialize current
    int index = 0;
    // traverse till then end of the linked list
    while (current != NULL)
    {
        if (current->info == item)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void reverseList(struct Node **s)
{
    struct Node *prevNode, *curNode;

    if(*s != NULL)
    {
        prevNode = *s;
        curNode = (*s)->next;
        *s = (*s)->next;

        prevNode->next = NULL; // Make first node as last node

        while(*s != NULL)
        {
            *s = (*s)->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = *s;
        }

        *s = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
        show(*s);
    }
}

// #include "linkedList.h"

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
        puts("3..............Insert between");
        puts("4..............Delete from begin");
        puts("5..............Delete from last");
        puts("6..............Delete on info basis");
        puts("7..............Show");
        puts("8..............search");
        puts("9..............ReverseList");
        puts("10..............Exit");
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
            addAfter(&start, sinfo, value);
            break;
        case 4:
            delBeg(&start);
            break;
        case 5:
            delLast(&start);
            break;
        case 6:
            value = takeInput();
            delInfo(&start, value);
        case 7:
            show(start);
            break;

        case 8:
            printf("Enter element to search: ");
            value = takeInput();

            int index = searchElement(&start, value);

            if (index == -1)
                printf("Item not found");
            else
                printf("Item found at position: %d", index + 1);
            break;

        case 9:
            reverseList(&start);
            break;
        case 10:
            printf("Coded by Apoorva\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 10);

    return 0;
}