#include<stdio.h>
int main(){
    int a=10,b=15,c=16;
if(a>b){
    if(a>c){
printf("The largest number is %d\n",a);    
}

else{
    printf("\n The largest number is not %d",a);
} 
}  

else{
    if(b>c){
        printf("The largest number is %d\n",b);
    }
    else{
        printf("The largest number is %d\n",c);
    }
}
return 0;
}