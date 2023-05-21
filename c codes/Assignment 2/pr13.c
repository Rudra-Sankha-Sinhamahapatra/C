#include<stdio.h>
void swap(int *x,int *y){
   int temp=*x;
    *x=*y;
    *y=temp;
}
int main() {
int a,b,t;
printf("Enter 2 numbers\n",&a,&b);
scanf("%d %d",&a,&b);
printf("Before swapping a=%d,b=%d\n",a,b);
swap(&a,&b);
printf("After swapping a=%d,b=%d\n",a,b);
return 0;
}