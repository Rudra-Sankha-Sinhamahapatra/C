#include<stdio.h>
#include<string.h>
int main()
{
char s[100], och, nch,ch;
int i, flag=0;
printf("\nEnter a string :");
gets(s);
printf("\nEnter a character to replace :");
scanf("%c", &och);
ch=getchar();
printf("\nEnter the new character :");
scanf("%c", &nch);
for(i=0; s[i]!='\0'; i++)
{
	if(s[i]==och)
	{
		s[i]=nch;
		flag=1;
	}
}//for loop ends here
if(flag==1)
printf("\nAfter the replacement by new character, the string is %s", s);
else
printf("\nThe given string does not contain the character %c", och);
return 0;
}