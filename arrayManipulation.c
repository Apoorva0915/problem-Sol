#include<stdio.h>
void show(int x[],int s){
    for (int i = 0; i < s; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
    
}
void input(int num[],int s){
    for (int i = 0; i < s; i++)
    {
        num[i]=i+1;
    }
    
}

void insert(int num[],int pos,int value, int s){
    if(pos>s){
        printf("invalid position");
    }else{
        num[pos-1]=value;
        printf("insertion successfull");
    }
    printf("\n");
}

void removeItem(int num[],int *size,int pos){
    if(pos>*size){
         printf("invalid position");
    }else{
        for (int i = pos-1; i < *size; i++)
        {
           num[i]=num[i+1];
        }
        *size=*size-1;
        printf("item removed");
        
    }
    printf("\n");
}






int main(){
    int value,pos,size;
    size=10;
    int num[10];
    input(num,size);
    show(num,size);
    printf("enter the value to insert:-");
    scanf("%d",&value);
    printf("enter the position where to insert:-");
    scanf("%d",&pos);
    insert(num,pos,value,size);
    show(num,size);
    printf("enter position to remove");
    scanf("%d",pos);
    removeItem(num,&size,pos);
    show(num,size);
}