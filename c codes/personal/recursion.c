#include<stdio.h>
int f(int a,int b){
    if(b==0){
        return 1;
    }
    else if (b%2==0){
        return (f(a,b/2)*f(a,b/2));
    }

    
   else{
        return (a*f(a,b/2)*f(a,b/2));
    }
}
int main() {
    int a,b;
    printf("Enter the value of a and b\n");
    scanf("%d %d",&a,&b);
    int ans=f(a,b);
    printf("f(%d,%d)=%d",a,b,ans);
return 0;
}