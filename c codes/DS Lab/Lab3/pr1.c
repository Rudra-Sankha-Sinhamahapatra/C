#include <stdio.h>
int main()
{
int sparse[10][10],arr[10][10],transpose[10][10];
int i,j,r,r1=1,temp1,temp2,temp3,row,column,count=0;
printf("Enter the no. of rows of the sparse matrix in 3 tuple format:");
scanf("%d",&r);
printf("Enter a sparse matrix in 3 tuple format:");
for(i=0;i<r;i++)
{
 for(j=0;j<3;j++)
 {
  scanf("%d",&sparse[i][j]);
 }
} 
row=sparse[0][0];
column=sparse[0][1];
for(i=0;i<row;i++)
{
 temp1=sparse[r1][0];
 temp2=sparse[r1][1];
 temp3=sparse[r1][2];
 for(j=0;j<column;j++)
 {
  if(i==temp1 && j==temp2)
  arr[i][j]=temp3;
  else
  arr[i][j]=0;
 }
 r1++;
 }
 for(i=0;i<row;i++)
 {
  for(j=0;j<column;j++)
  {
   if(arr[i][j]!=0)
   count++;
  }
 }  
 r1=1;
 for(i=0;i<row;i++)
 {
  for(j=0;j<column;j++)
  {
   transpose[j][i]=arr[i][j];
   }
   }
    
    int sparse2[row + 1][3];
    sparse2[0][0] = column;
    sparse2[0][1] = row;
    sparse2[0][2] = count;
    
    for (i = 0; i < row+1; i++) {
        for (j = 0; j < column; j++) {
            if (transpose[i][j] != 0) {
                sparse2[r1][0] = i;
                sparse2[r1][1] = j;
                sparse2[r1][2] = transpose[i][j];
                r1++;
            }
        }
    }
    
    printf("Transpose of sparse matrix:\n");
    for (i = 0; i <row+1; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sparse2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
   
   
   
   
   
    
