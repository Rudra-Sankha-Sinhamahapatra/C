#include <stdio.h>

int main() {
int f,n,f1;
printf("Enter a number\n");
scanf("%d",&n); 
f=n;
while(f>=10){
    f1=f/10;
}
printf("First digit of %d is %d\n",n,f1);
return 0;
}