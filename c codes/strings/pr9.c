#include<stdio.h>
int main() {
char str[100];
int count=0;
puts("Enter a string:");
gets(str);
for (int i = 0; str[i]!='\0'; i++)
{
    count++;
}
printf("The size of the string is %d\n",count);

for (int i = 0,j=count-1;i<=j;i++,j--)
{
 char temp=str[i];
 str[i]=str[j];
 str[j]=temp;
}
puts("The Reversed string is :");
puts(str);

return 0;
}