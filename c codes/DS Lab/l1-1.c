// 1.1 Write a program to read two numbers and compare the numbers using function call by address.
// Sample Input:
// Enter two numbers: 50  80
// Sample Output:
// 50 is smaller than 80
// Sample Input:
// Enter two numbers: 40  10
// Sample Output:
// 40 is greater than 10
// Sample Input:
// Enter two numbers: 50  50
// Sample Output:
// Both numbers are same

#include<stdio.h>
void compareNumbers(int *num1,int *num2){
    if(*num1>*num2){
        printf("%d is bigger than %d\n",*num1,*num2);
    }
    else if(*num1<*num2){
        printf("%d is smaller than %d\n",*num1,*num2);
    }
    else{
        printf("Both Numbers are equal");
    }
}
int main() {
int a,b;
printf("Enter two Numbers");
scanf("%d %d",&a,&b);
compareNumbers(&a,&b);
return 0;
}
