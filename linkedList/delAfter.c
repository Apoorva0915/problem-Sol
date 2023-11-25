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

void delInfo(struct Node **s,int info){
    struct Node *temp; 
    if(*s==NULL){
        printf("Empty List\n");
        return;
    }
    if((*s)->info==info){
        temp=*s;
        *s=(*s)->next;
        free(temp);
        printf("\nNode Deleted\n");
    }
    

    struct Node *prev,*curr;
    prev=*s;
    curr=(*s)->next;

    while(curr->next != NULL){
     if(curr->info==info){
        break;
     }
        curr = curr->next;
        prev = prev->next;
    }
    
    if(curr==NULL){
        printf("%d info not found\n",info);
    }
    else{
        prev->next=curr->next;
        free(curr);
        printf("\nNode deleted\n");
    }

}

int takeinput(){
    int value;
    printf("Enter any value");
    scanf("%d",&value);
    return value;
}

int main(){
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

    delInfo(&start,200);

    show(start);
    return 0;
}