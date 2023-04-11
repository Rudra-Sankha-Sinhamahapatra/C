#include<stdio.h>
int main() {
int hour,minute,second,Seconds;
printf("Enter the second\n");
scanf("%d",&second);
minute=second/60;
hour=minute/60;
Seconds=second%60;
printf("The hour=%d,Minute=%d,Seconds=%d",hour,minute,Seconds);
return 0;
}