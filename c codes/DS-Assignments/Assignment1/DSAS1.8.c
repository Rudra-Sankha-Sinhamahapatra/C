#include <stdio.h>
#include <math.h>
int main()
{
 int mat[10][10]={0},r,c,i,j,sum=0,res;
 printf("Enter the rows and columns of the matrix:");
 scanf("%d %d",&r,&c);
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   mat[i][j]=floor((i+1)/(j+1));
   printf("%d ",mat[i][j]);
   sum=sum+mat[i][j];
  }
  printf("\n");
 }
 printf("\nThe sum of all the matrix elements is %d",sum);
 return 0;
}   
