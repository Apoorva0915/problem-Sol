#include<stdio.h>

    //    int k=1;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<i;j++){
    //         printf("%d",k);
    //         k=i+2;
    //     }
    //     k--;
    //     printf("\n ");
    // }
    // for (int i = 1; i <=n; i++)
    // {
    //         int k=i;
    //        for (int j = 0; j <=i; j++)
    //        {
              
    //        }
           
        
    // }
    

void pattern(int n){
        int k;
    for(int i=0;i<n;i++){
        k=i+1;
        for (k = i; k< n; k++)
        {
            printf(" ");
        }
        
        for(int j=0;j<=i;j++){
            printf("%d",k);
            k++;
        }
        printf("\n ");
    }
}
int main(){
    pattern(4);
return 0;
}