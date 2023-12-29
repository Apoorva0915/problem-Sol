#include<stdio.h>

void show(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void merge(int a[],int l,int mid,int h){
    int c[h-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=h){
       if(a[i]<=a[j]){
        c[k]=a[i];
        i++;
        k++;
       }
       else{
        c[k]=a[j];
        k++;
        j++;
       }
    }
    while(i<=mid){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=h){
        c[k]=a[j];
        k++;
        j++;
    }

    for(i=h;i>=l;i--){
        k--;
        a[i]=c[k];
    }

    }



void mergeSort(int arr[],int l,int h){
  if(l<h){
    int mid=l+(h-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}


int main(){
    int arr[]={10,16,8,12,15,6,9,5};
    int size=8;
       show(arr,size);
   printf("\n");
   mergeSort(arr,0,size-1);
   show(arr,size);

}