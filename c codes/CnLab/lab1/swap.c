#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

int main(int argc,char* argv[]){
if(argc!=3){
printf("No of arguments should be 3\n");
return 1;
}

int a=atoi(argv[1]);
int b=atoi(argv[2]);

printf("Before swapping:---\n");
printf("A:%d\n",a);
printf("B:%d\n",b);

swap(&a,&b);

printf("After swapping:---\n");
printf("A:%d\n",a);
printf("B:%d\n",b);

return 0;
}


