#include<stdio.h>
int sum(int a,int b);

int main() {
 int c;
 int x;
 int y;
 printf("\n Enter the value of First Number");
 scanf("%d",&x);
 printf("\n Enter the value of Second Number");
 scanf("%d",&y);
 c=sum(x,y);
 printf("The value of c is %d\n",c);
return 0;
}
int sum(int a,int b){
    int result;
    result=a+b;
    return result;
}