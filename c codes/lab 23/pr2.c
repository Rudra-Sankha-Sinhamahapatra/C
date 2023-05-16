#include<stdio.h>
#include<ctype.h>
int main() {
//toupper
char c;
c='m';
printf("%c-> %c",c,toupper(c));
c='D';
printf("\n %c->%c",c,toupper(c));
c='9';
printf("\n %c->%c",c,toupper(c));
return 0;
}