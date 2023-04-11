#include<stdio.h>
int main() {
    int paisa,rupee,Paisa;

printf("Enter the value of Paisa\n");
scanf("%d",&paisa);
rupee=paisa/100;
Paisa=paisa%100;
printf("\n The %d paisa=%d rupees and %d paisa",paisa,rupee,Paisa);
return 0;
}