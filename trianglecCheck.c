#include <stdio.h>

// void triangle(int a,int b,int c){
//     if((a==b)&&(b==c)&&(a==c)){
//         printf("Equilateral");
//     }
//     if((a==b)||(b==c)||(a==c)){
//         printf("Isosceles");
//     }
//     else {
//         printf("scalene");
//     }
// }

// void triangle(int a, int b, int c)
// {
//     if (a == b)
//     {
//         if (b == c)
//         {
//             printf("Equilateral");
//         }
//     }
//     if (a == b)
//     {
//         printf("isosceles");
//     }
//     else if (b == c)
//     {
//         printf("isosceles");
//     }
//     else if (c == a)
//     {
//         printf("isosceles");
//     }
//     else
//     {
//         printf("scalene");
//     }
// }

// int checkQ(int s){
//     if(s>0){
//         return 1;
//     }
//     return 0;
// }

// void quad(int x,int y){
//     if(checkQ(x)){
//         if(checkQ(y)){
//             printf("first");
//         }
//     }
//     if(!checkQ(x)){
//         if(checkQ(y)){
//             printf("Second");
//         }
//     }
//     if(!checkQ(x)){
//         if(!checkQ(y)){
//             printf("third");
//         }
//     }
//     if(checkQ(x)){
//         if(!checkQ(y)){
//             printf("fourth");
//         }
//     }    
// }


// void quadrant(int x, int y)
// {
//     if ((x > 0) && (y > 0))
//     {
//         printf("First");
//     }
//     if ((x < 0) && (y > 0))
//     {
//         printf("Second");
//     }
//     if ((x < 0) && (y < 0))
//     {
//         printf("Third");
//     }
//     if ((x > 0) && (y < 0))
//     {
//         printf("Fourth");
//     }
// }

void pattern(int n){
    int k;
    for(int i=0;i<n;i++){
        k=i+1;
        for(int j=0;j<=i;j++){
            printf("%d",k);
            k++;
        }
        printf("\n ");
    }
}


// int check(int s){
//     if(s>0){
//         return 1;
//     }
//     else{
//        printf("invalid angle");
//     }
//     return 0;
// }


// void tCheck(int a, int b,int c){
 
//  if(!check(a))
//      return;
  
//  if(!check(b))
//      return;
  
//  if(!check(c))
//      return;
  
//  if(a+b+c!=180){
//     printf("invalid angle");
//     return;
//  }


// }



int main()
{
    // int a, b, c;
    // triangle(4, 5, 1);
    // printf("\n ");
    // quad(5, -2);
    //  printf(" \n");
    pattern(4);
    return 0;

}
