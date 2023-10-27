#include<stdio.h>
int main(int argc, char const *argv[])
{
    // int i, num;
    // scanf("%d",&num);
    // for ( i = 0; num!=0;i++,num/=10);
    // printf("%d",i);
    // return 0;

    // int i=0;
    // for ( ; i <=10; )
    // {
    //     printf("%d",++i);
    // }
    

   int n;
   scanf("%d",&n);
   int k=1;
   for (int i = 0; i < n; i++)
   {
    for (int j = 0; j <=i; j++)
    {
        printf(" %d",k);
        k++;
    }
    printf("\n ");
    
   }


   


}
