// #include<stdio.h>
// void pattern(int n){
//     for(int i=1;i<=n;i++){
//         for(int s=n;s>i;s--){
//             printf(" ");
//         }
//         for(int j=0;j<i;j++){
//             printf("%d",i+j);
//         }
//         printf("\n");
//     }

// }
// int main(int argc, char const *argv[])
// {
//     /* code */
//     pattern(4);
//     return 0;
// }


#include<stdio.h>
int factorial(int n){
    if(n<1){
    return 1;
    }
    return n*factorial(n-1);
}

int main(int argc, char const *argv[])
{
    int n=4,sum=0;
    for(int i=1;i<=n;i++){
       sum= sum+factorial(i);
    }
    printf("%d",sum);

    return 0;
}
