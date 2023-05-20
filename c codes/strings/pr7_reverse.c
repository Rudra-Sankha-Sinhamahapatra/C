#include<stdio.h>
#include<string.h>
int main() {
char str1[5];
scanf("%[^\n]s",str1);
printf("Input was:%s",str1);

return 0;
}