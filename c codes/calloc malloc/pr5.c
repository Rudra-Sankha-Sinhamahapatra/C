//malloc and initialize
#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,size;
printf("Enter the size of the Array\n");
scanf("%d",&size);
float *fa;
fa=(float*)malloc(size*sizeof(float));
if(fa==NULL)
{
printf("out of memory\n");
exit(0);
}
for(i=0;i<size;i++);
fa[i]=0.0;
printf("%f",fa);
}