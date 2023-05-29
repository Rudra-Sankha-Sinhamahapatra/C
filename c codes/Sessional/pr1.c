//finding factorial of a number using recursion
#include<stdio.h>
int fact(int n){
    n;
    if(n<0){
        printf("Error!<Enter a Positive Integer\n");
    }
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
}
int main() {
    int n;
    printf("Enter a Number\n");
    scanf("%d",&n);
    int result=fact(n);
    printf("Factorial of %d=%d",n,result);

return 0;
}