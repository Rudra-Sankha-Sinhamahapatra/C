//Factorial of a number using functions
#include<stdio.h>
int fact(int n){
    n;
    int k=1;
    while(n>0){
        k*=n;
        n--;
    }
}
int main() {
    int n;
    printf("Enter a Number:\n");
    scanf("%d",&n);
    if(n<0){
        printf("Error!Please Enter a Positive Number");
    }
    else{
    int result=fact(n);
    printf("Factorial of %d=%d\n",n,result);
    }
return 0;
}