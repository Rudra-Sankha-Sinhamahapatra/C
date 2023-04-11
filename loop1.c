#include<stdio.h>
int main() {
printf("The value of a should be written below 21\n");
int a;
printf("Enter the value of a :\n");
 scanf("%d",&a);
 
 while(a<=20){
    printf("The value of a is %d\n",a);
    a++;
 }
return 0;
}