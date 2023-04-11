#include<stdio.h>
int main() {
int meter,kilometer,Meter;
printf("\n Enter the meter");
scanf("%d",&meter);
kilometer=meter/1000;
Meter=meter%1000;
printf("\n %d Kilometer %d meter",kilometer,Meter);
return 0;
}