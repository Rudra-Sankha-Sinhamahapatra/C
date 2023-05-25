//Reverse a string with library function
#include<stdio.h>
#include<string.h>
int main() {
char str[15];
puts("Enter a string:");
scanf("%s",str);
printf("Original string:%s\n",str);
strrev(str);
printf("The reversed string is %s\n",str);
return 0;
}