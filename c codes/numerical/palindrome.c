//checking whether a number is palindrome or nor
#include<stdio.h>
int palindrome(int num){
    num;
    int original=num;
    int reverse=0;
    int remainder;
    while(num!=0){
        remainder=num%10;
        reverse=(reverse*10)+remainder;
        num=num/10;
    }
    
    if (original==reverse)
    {
     printf("%d Number is palindrome",original);   
    }
    else{
        printf("%d Number is not palindrome",original);
    }
}
int main() {
    int num;
    printf("Enter a number\n");
    scanf("%d",&num);
    printf("You Entered %d\n",num);
    palindrome(num);
return 0;
}