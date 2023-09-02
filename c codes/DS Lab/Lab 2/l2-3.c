//    WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
 
// Sample Input:
 
// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix: 0  0  33  0  0  0  17  0  0  0  0  0  0  46  0  0  0  0  0  51
 
// Sample Output:
// sparse matrix in 3-tuple format
// 4   5   4
// 0   2   33
// 1   1   17
// 2   3   46
// 3   4   51

#include <stdio.h>
void run(int, int);
int main()
{
 int i,j,r,c,count=0,r1=0,c1=0,temp,row,column,arr[10][10];
 printf("Enter the number of rows and the no. of columns:");
 scanf("%d %d",&r,&c);
 printf("Enter the sparse matrix:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&arr[i][j]);
   if(arr[i][j]!=0)
   count++;
  }
 }
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   if(arr[i][j]!=0)
   {
    temp=arr[i][j];
    arr[r1][c1]=i;
    c1++;
    arr[r1][c1]=j;
    c1++;
    arr[r1][c1]=temp;
  }
  }
  r1++;
  c1=0;
 }
 c1=0;
 printf("3 tuple format is :");
 for(i=0;i<r+1;i++)
 {
  for(j=0;j<3;j++)
  {
   if(c1==0)
   {
    
   printf(" %d",arr[i][j]);
  }
  printf("\n");  
 }  
 return 0;
 }
}