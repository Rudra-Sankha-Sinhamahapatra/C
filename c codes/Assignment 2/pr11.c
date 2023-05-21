//Finding largest bertween 3 numbers using functions
#include<stdio.h>

int largest(int a,int b,int c){
    if(a>b && a>c){
        return a;
    }else if(b>a && b>c){
        return b;
    }
    else{
        return c;
    }

}

int main(){
int x,y,z;
printf("Enter 3 numbers\n");
scanf("%d %d %d",&x,&y,&z);
int result=largest(x,y,z);
printf("Largest number is %d\n",result);
return 0;
}