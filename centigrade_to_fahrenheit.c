#include<stdio.h>
int main() {
float f,c;
printf("\nEnter the value in centigrade");
scanf("%f",&c);
f=1.8*c+32;
printf("The value in Fahrenheit is %f\n",f);
return 0;
}