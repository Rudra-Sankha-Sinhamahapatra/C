#include<stdio.h>
int max(int *a,int *b){
    if(*a>*b){
        return *a;
    }
    else if(*a<*b){
        return *b;
    }
}
int main() {
int a,b;
printf("Enter two numbers\n");
scanf("%d %d",&a,&b);
if(a==b){
    printf("Both the numbers are equal\n");
}
else{
int result=max(&a,&b);
printf("Maximum is %d",result);
}
return 0;
}