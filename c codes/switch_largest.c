#include<stdio.h>
int main() {
int a,b,c,largest;
printf("Enter three numbers\n");
scanf("%d %d %d",&a,&b,&c);
switch(a>b && a>c){
    case 1:
    largest=a;
    break;
    case 0:
    switch(b>c){
        case 1:
        largest=b;
        break;
        case 0:
        largest=c;
    }
    break;
}
printf("%d is largest\n",largest);
return 0;
}