#include <stdio.h>
int main()
{
 int n,i,a[10],b[10],c[10];
 printf("Enter the maximum degree of x:\n");
 scanf("%d",&n);
 printf("Enter the polunomial 1 from lowest degree to the highest degree:\n");
 for(i=0;i<=n;i++)
 {
  scanf("%d",&a[i]);
 } 
 printf("Enter the polunomial 2 from lowest degree to the highest degree:\n");
 for(i=0;i<=n;i++)
 {
  scanf("%d",&b[i]);
 } 
 printf("The resultant polynomial is:\n");
 for(i=n;i>=0;i--)
 {
   c[i]=a[i]+b[i];
   if(i==0)
   printf(" %dX^%d",c[i],i);
   else
   printf(" %dX^%d+",c[i],i);
 }
}