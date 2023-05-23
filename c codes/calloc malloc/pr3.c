//Sum using memory allocation
#include<stdio.h>
int main()
{
int *x,*y,sum;
x=(int*)malloc(sizeof(int));
y=(int*)malloc(sizeof(int));
printf("\nEnter two integers to add:");
scanf("%d%d",&*x,&*y);
sum=*x+*y;
printf("\n Sum of %d and %d is %d",*x,*y,sum);
}