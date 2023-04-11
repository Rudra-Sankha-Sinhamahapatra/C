//sum of first 10 natural numbers

#include<stdio.h>
int main() {
int num,sum=0,i;
printf("Enter a positive integer\n");
scanf("%d",& num);
for(i=1;i<=num;i++){
    sum+=i;
    }
    printf("Sum of first %d numbers are %d",num,sum);
return 0;
}