#include<stdio.h>

void show(int num[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",num[i]);
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
              if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
              }
        }
            //    show(arr,n);
            //    printf("\n");
    }
    show(arr,n);
}


int main(int argc, char const *argv[])
{
    int arr[]={3,2,10,5,6};
    bubbleSort(arr,5);
    return 0;
}
