#include<stdio.h>
#include<math.h>
int main() {
int a,b;
printf("Enter a and b \n");
scanf("%d %d",&a,&b);
float c;
printf("Enter c \n");
scanf("%f",&c);

printf("Bokachoda dekh pow a %d\n",pow(a,3));
printf("Bokachoda dekh pow  b %d\n",(int)pow(b,3));
printf("Bokachoda dekh pow c %f\n",pow(c,3));
return 0;
}