#include<stdio.h>

int partition(int arr[], int l ,int h){
  int pivot=arr[l];
  int i=l+1;
  int j=h;
  while(i<=j){
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<j){
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
  }

  int temp=arr[l];
  arr[l]=arr[j];
  arr[j]=temp;

  return j;
}

void quickSort(int arr[], int l ,int h){
   if (l<h)
   {
     int j=partition(arr,l,h);
     quickSort(arr,l,j-1);
     quickSort(arr,j+1,h);
   }
} 

void show(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}


int main(){
   int arr[]={10,16,8,12,15,6,9,5};
   int size=8;
   show(arr,size);
   printf("\n");
   quickSort(arr,0,size-1);
   show(arr,size);
}