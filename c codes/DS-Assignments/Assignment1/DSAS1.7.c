#include <stdio.h>
int main()
{
 int flag=0,mat[10][10],sumr=0,row[10][10],column[10][10],sumc=0,r,c,i,j;
 printf("Enter the rows and the columns of the matrix:");
 scanf("%d %d",&r,&c);
 printf("Enter all the elements of the matrix:");
 for(i=0;i<r;i++)
 {
  sumr=0;
  for(j=0;j<c;j++)
  {
   scanf("%d",&mat[i][j]);
   sumr=sumr+mat[i][j];
  }
  row[0][i]=sumr;
 }
 
 for(i=0;i<c;i++)
 {
  sumc=0;
  for(j=0;j<r;j++)
  {
   sumc=sumc+mat[j][i];
  }
  column[0][i]=sumc;
  if(row[0][i]==column[0][i])
  {
   flag=1;
   printf("\nThe sum of %dth row is equal to the %dth column",(i+1),(i+1));
 }
 }
 if(flag==0)
 printf("\nThis is not a row-column sum equal matrix");
 return 0;
}    
    
    
    
    
    
 
   
