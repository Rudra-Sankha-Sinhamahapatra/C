#include<stdio.h>
#include<string.h>
int main()
{
char s[100];
int l, i;

printf("\nEnter a string : ");
gets(s);
l=strlen(s);

printf("\nThe reverse of the string is ");
for(i=l-1; i>=0; i--)
printf("%c", s[i]);
return 0;
}