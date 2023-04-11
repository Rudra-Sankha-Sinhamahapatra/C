#include<stdio.h>
int main() {
int num;
printf("Enter a number\n");
scanf("%d",&num);
//using ternary operator
(num<0)?printf("%d is negative\n",num):(num>0)?printf("%d is positive\n",num):(num==0)?
printf("%d is zero\n",num):printf("Enter a valid number\n");
return 0;
}