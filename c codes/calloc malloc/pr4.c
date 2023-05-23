//malloc allocates memory but doesn't initialize them
#include<stdio.h>
#include<stdlib.h>
int main()
{
float *fp;
int i;
fp=(float*)malloc(10*sizeof(float));
if(fp==NULL)
{
printf("\n out of memory\n");
exit(0);
}
for(i=0;i<10;i++)
printf("%f\n",fp[i]);
}