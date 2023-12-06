#include <stdio.h>
#include <malloc.h>
struct Node
{
    int info;
    struct Node *next;
};


void show(struct Node *s){
      struct Node *temp = s->next;
      while (temp!=s)
      {
         printf("%d\n",temp->info);
         temp=temp->next;
      }
      printf("%d\n",temp->info);
      
}

void addBeg(struct Node **s, int value){
       struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = value;
    if (*s==NULL)
    {
     newNode->next = newNode;
     *s = newNode;
    }else{
        newNode->next=(*s)->next;
    (*s)->next=newNode;
    }
   
}


void addLast(struct Node **s, int value){
    // printf("%d",value);
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = value;
    if (*s==NULL)
    {
     newNode->next = newNode;
     *s = newNode;
    }else{
        newNode->next=(*s)->next;
    (*s)->next=newNode;
    (*s)=newNode;   
    }
}

void addAfter(struct Node **s,int sinfo,int value){
     if (*s==NULL)
    {
      struct Node *s = (struct Node *)malloc(sizeof(struct Node));
      s->info = value;
      s->next=s;
    }

    struct Node *temp = *s;
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


void delBeg(struct Node **s){
    if (*s==NULL)
    { 
        printf("Empty List");
    }
    else if(*s==(*s)->next){
        free(*s);
    }
    else{
          struct Node *temp = (*s)->next;
          (*s)->next=temp->next;
          free(temp);
    }
    
}

void delLast(struct Node **s){
     if (*s==NULL)
    { 
        printf("Empty List");
    }
    else if(*s==(*s)->next){
        free(*s);
    }
    else{
         struct Node *temp = (*s)->next;
         while (temp!=(*s))
         {
            temp=temp->next;
         }
         temp->next=(*s)->next;
         free(*s);
         (*s)=temp;
    }
}


void delInfo(struct Node **s, int info){
     if (*s==NULL)
    { 
        printf("Empty List");
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
        puts("8..............Exit");
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
            printf("Coded by Apoorva\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}