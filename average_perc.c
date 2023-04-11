#include<stdio.h>
int main() {
float eng,math,phy,chem,comp;
float total,avg,percentage;
printf("Enter the marks for 5 subjects\n");
scanf("%f %f %f %f %f",&eng,&math,&phy,&chem,&comp);
total=eng+math+phy+chem+comp;

avg=(eng+math+phy+chem+comp)/5;
percentage=(total/500)*100;
printf("\nThe average is %f",avg);
printf("\n The percentage is %f",percentage);
return 0;
}