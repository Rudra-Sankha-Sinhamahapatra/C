#include<stdio.h>
#include<ctype.h>
int main() {
char var1='M';
char var2='m';
if(isupper(var1)){
    printf("var1=|%c| is uppercase character",var1);
}
else{
    printf("var1=|%c| is not uppercase character\n",var1);
}
return 0;
}