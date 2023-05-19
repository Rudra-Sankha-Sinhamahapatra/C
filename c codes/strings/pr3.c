//input and output of a string without loop
#include<stdio.h>

#define MAX_LENGTH 100

int main() {
char str1[MAX_LENGTH];
char str2[MAX_LENGTH];
printf("\nenter the first string:");
gets(str1);
printf("\nEnter the second string:");
gets(str2);
printf("String 1 is %s\n",str1);
printf("String 2 is %s\n",str2);
return 0;
}