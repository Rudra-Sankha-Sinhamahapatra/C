#include<stdio.h>
int main() {
int x=10;
int y=20;
y=(x+y)-(x=y);
printf("x=%d and y=%d",x,y);
return 0;
}