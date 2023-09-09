#include <stdio.h>
void sparsetonormal(int s[10][10],int r1, int c1);
void transpose(int n[10][10],int r1, int c1);
void normaltosparse(int t[10][10], int r1, int c1, int count);
int main()
{
 int i,j,r,r1,c1,s[10][10];
 printf("Enter the no. of rows:\n");
 scanf("%d",&r);
 printf("Enter a sparse matrix in 3-tuple format:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   scanf("%d",&s[i][j]);
  }
 }
 r1=s[0][0];
 c1=s[0][1];
 printf("The matrix you entered:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d ",s[i][j]);
  }
  printf("\n");
 }    
 sparsetonormal(s,r1,c1);
 }
 void sparsetonormal(int s[10][10],int r1, int c1)
 {
  int r=1,i,j,n[10][10];
  for(i=0;i<r1;i++)
  {
   for(j=0;j<c1;j++)
   {
    if(i==s[r][0]&&j==s[r][1])
    n[i][j]=s[r][2];
    else
    n[i][j]=0;
    }
   r++;
  }
  printf("The matrix after getting converted to normal is:\n");
  for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   printf("%d ",n[i][j]);
  }
  printf("\n");
 }
 transpose(n,r1,c1);     
 }   
 void transpose(int n[10][10],int r1, int c1)
 {
  int t[10][10],i,j,count=0;
  for(i=0;i<r1;i++)
  {
   for(j=0;j<c1;j++)
   {
     t[j][i]=n[i][j];
   }
  }
  printf("The transposed matrix:\n");
  for(i=0;i<c1;i++)
  {
   for(j=0;j<r1;j++)
   {
    if(t[i][j]!=0)
    count++;
    printf("%d ",t[i][j]);
   }
   printf("\n");
  }
  normaltosparse(t,c1,r1,count);
 }
 void normaltosparse(int t[10][10], int r, int c, int count)
 {
   int i,j,s=0,r1=1,f[10][10];
   f[0][0]=r;
   f[0][1]=c;
   f[0][2]=count;
   for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
    {
      if(t[i][j]!=0)
      {
        f[r1][0]=i;
        f[r1][1]=j;
        f[r1][2]=t[i][j];
       r1++;
       }
     }
    }
    printf("The resultant matrix in 3 tuple format:\n");
    for(i=0;i<r1;i++)
    {
     for(j=0;j<3;j++)
     {
      printf("%d ",f[i][j]);
     }
    printf("\n");
   }   
   }