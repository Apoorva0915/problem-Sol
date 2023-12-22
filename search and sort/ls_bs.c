#include<stdio.h>
int c=0,d=0;
int linearSearch(int arr[], int size, int key){
    for(int i=0;i<=size;i++){
        c++;
        if(arr[i]==key){
           break;
        }
    }
    return c;
}

int binarySearch(int arr[],int size,int key ){
    int l=0;
    int h=size-1;
    while (l<=h)
    {
       int mid=(l+h)/2;
       d++;
       if(arr[mid]==key){
        break;
       }
       else if(arr[mid]>key){
        h=mid-1;
       }
       else{
        l=mid+1;
       }
    }
    return d;
}

int main(){
    int arr[10]={1,3,5,7,9,11,13,15,17,19};
    
    printf("%d %d", linearSearch(arr,10,13),binarySearch(arr,10,13));

}