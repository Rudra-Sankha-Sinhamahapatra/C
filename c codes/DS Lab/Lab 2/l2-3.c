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


#include<stdio.h>
int main ()
{
    int r,c;
printf("enter number of rows and coloumns");
scanf("%d %d",&r,&c);
int arr[r][c];
printf("enter the array elements\n");
for (int i = 0; i < r; i++)
{
   for ( int j = 0; j < c; j++)
   {
    scanf("%d",&arr[i][j]);
   } 
}
printf("the sparse matrix of the following is:\n");
for (int i = 0; i < r; i++)
{
   for ( int j = 0; j < c; j++)
   {
   if(arr[i][j]!=0){
    printf("\n %d %d %d",i+1,j+1,arr[i][j]);
   }
   } 
}
return 0;
}