#include<stdio.h>
int rev(int num){
    int remainder;
    int reverse=0;
    while(num!=0){
    remainder=num%10;
    reverse=(reverse*10)+remainder;
    num=num/10;
    }
 return reverse;
}

int main() {
int num;
printf("Enter a number:\n");
scanf("%d",&num);
int result=rev(num);
printf("Reversed Number=%d",result);
return 0;
}