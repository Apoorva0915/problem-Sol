#include<stdio.h>
// #include<math.h>

int factorial(int n){
    if(n<1){
    return 1;
    }
    return n*factorial(n-1);
}

int p(int a,int b){
    int pow=a;
    while (b>1)
    {
       pow*=a;
       b--;
    }
    return pow;
    
}

int main(int argc, char const *argv[])
{
    // int n=6;float sum=1;
    // for(int i=1;i<n;i++){
    // //    sum= sum+factorial(i)/i;
    // sum=sum+factorial(i);
    // }
    // printf("%.2f",sum);
    int n;
    scanf("%d",&n);
    float sum=0;
    for (int i = 0; i<=n; i++)
    {
        sum=sum+p(n,i)/factorial(i);
    }
      printf("%.2f",sum);
    // int n;
    // scanf("%d",&n);
    // float sum=0;
    // for (int i = 0; i<=n; i++)
    // {
    //     if(i%2==0){
    //       sum=sum+pow(n,i)/factorial(i);
    //     }
    //     else{
    //       sum=sum-pow(n,i)/factorial(i);
    //     }
    // }
    //   printf("%.2f",sum);

    return 0;
}
