// wap in c to cop

#include <stdio.h>
#include<string.h>

int main() 
{ 
char s1[20]; 
char s2[20]; 
printf("Give string :\n");
gets(s1);
int l= strlen(s1);
for(int i=0;s1[i]!='\0';i++){
    s2[i]=s1[i];
}
s2[l]='\0';
printf("Copied String s2:%s",s2); 
return 0;
}