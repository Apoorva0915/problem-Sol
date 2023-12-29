#include<stdio.h>

void show(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int findMax(int arr[],int size){
   int max=arr[0];
   for(int i=1;i<size;i++){
    if(arr[i]>max){
        max=arr[i];
    }
    return max;
   }
}


void countingSort(int arr[],int size){
    int max=findMax(arr,size);
    int count[max+1]={0};

    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    printf("Frequency array\n");
    show(count,max+1);

    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    printf("Cumalative sum array\n");
    show(count,max+1);

    int B[size]={0};
    for(int i=size-1;i>=0;i--){
        count[arr[i]]--;
        B[count[arr[i]]]=arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=B[i];
    }
}


int main(){
    int arr[]={10,16,4,8,12,4,15,6,9,5,5};
    int size=11;
   show(arr,size);
   printf("\n");
   countingSort(arr,size);
   show(arr,size);

}

