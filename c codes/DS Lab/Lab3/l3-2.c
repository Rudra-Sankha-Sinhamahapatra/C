#include <stdio.h>
void sparsetonormal(int s1[10][10], int r1, int c1, int s2[10][10], int r2, int c2);
void add(int n1[10][10], int n2[10][10], int r1, int c1, int r2, int c2);
void normaltosparse(int sum[10][10], int r, int c, int count);
int main()
{
 int i,j,r,r1,c1,r2,c2,s1[10][10],s2[10][10];
 printf("Enter the no. of rows of the sparse matrix:\n");
 scanf("%d",&r);
 printf("Enter sparse matrix 1 in 3 tuple format:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   scanf("%d",&s1[i][j]);
  }
 }
 r1=s1[0][0];
 c1=s1[0][1];
 printf("The matrix you entered:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d ",s1[i][j]);
  }
  printf("\n");
 }
  
 printf("Enter sparse matrix 2 in 3 tuple format:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   scanf("%d",&s2[i][j]);
  }
 }
 r2=s2[0][0];
 c2=s2[0][1];
 printf("The matrix you entered:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d ",s2[i][j]);
  }
  printf("\n");
 }
 sparsetonormal(s1,r1,c1,s2,r2,c2);
 }
 void sparsetonormal(int s1[10][10], int r1, int c1, int s2[10][10], int r2, int c2)
 {
  int i,j,r=1,n1[10][10],n2[10][10];
  for(i=0;i<r1;i++)
  {
   for(j=0;j<c1;j++)
   {
    if(i==s1[r][0] && j==s1[r][1])
    n1[i][j]=s1[r][2];
    else
    n1[i][j]=0;
   }
   r++;
  }
  printf("The matrix after getting converted to normal:\n");
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   printf("%d ",n1[i][j]);
  }
  printf("\n");
 }
 r=1;
 for(i=0;i<r2;i++)
  {
   for(j=0;j<c2;j++)
   {
    if(i==s2[r][0] && j==s2[r][1])
    n2[i][j]=s2[r][2];
    else
    n2[i][j]=0;
   }
   r++;
  }
  printf("The matrix after getting converted to normal:\n");
 for(i=0;i<r2;i++)
 {
  for(j=0;j<c2;j++)
  {
   printf("%d ",n2[i][j]);
  }
  printf("\n");
 }
 add(n1,n2,r1,c1,r2,c2);
 }
 void add(int n1[10][10], int n2[10][10], int r1, int c1, int r2, int c2)
 {
  int i,j,sum[10][10],r,c,count=0;
  if(r1>r2)
  r=r1;
  else
  r=r2;
  
  if(c1>c2)
  c=c1;
  else
  c=c2;
  for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
   {
    sum[i][j]=n1[i][j]+n2[i][j];
    if(sum[i][j]!=0)
    count++;
   }
  }
   printf("The matrix obtained after addition is:\n");
    for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
   {
   printf("%d ",sum[i][j]);
   }
   printf("\n");
  }
  normaltosparse(sum,r,c,count);
 } 
  void normaltosparse(int sum[10][10], int r, int c, int count)
  {
   int i,j,s=0,r1=1,f[10][10];
   f[0][0]=r;
   f[0][1]=c;
   f[0][2]=count;
   for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
    {
      if(sum[i][j]!=0)
      {
        f[r1][0]=i;
        f[r1][1]=j;
        f[r1][2]=sum[i][j];
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