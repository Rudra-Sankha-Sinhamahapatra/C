//Concatenate
#include <stdio.h>
#include<string.h>

int main() 
{ 
char s1[40]; 
char s2[20]; 
printf("Give string 1:\n");
gets(s1);
printf("Give string 2:\n");
gets(s2);
int l=strlen(s1);
int i;
for(i=0;s2[i]!='\0';i++){
  s1[l+i]=s2[i];
}
s1[i+l]='\0';
printf("Concatenated String : %s\n",s1); 
return 0;
}