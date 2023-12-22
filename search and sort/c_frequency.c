#include<stdio.h>
int main(){
    int num[13]={2,1,3,5,2,3,4,4,3,2,1,4,3};
    int count[6]={0};
    for(int i=0;i<=13;i++){
        count[num[i]]++;
    }

}