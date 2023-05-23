#include<stdio.h>
int main() {
int a,b,*x,*y,sum;
printf("\n Enter two integers to add");
scanf("%d %d",&a,&b);
x=&a;
y=&b;
sum=*x+*y;
printf("Sum=%d\n",sum);
return 0;
}