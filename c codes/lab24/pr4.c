//Addition of two matrices by  user input
#include<stdio.h>
int main() {
int i,j,n,m;

printf("Enter the number of rows and columns(number of rows,colums have to be same)\n");
scanf("%d %d",&m,&n);
int arr[m][n],brr[m][n],sum[m][n];
printf("Enter the elements of the first matrix:\n");
for ( i = 0; i < m; i++)
{
    for ( j = 0; j < n; j++)
    {
        scanf("%d",&arr[i][j]);
    }
}

printf("Enter the elements for the second matrix:\n");
for ( i = 0; i < m; i++)
{
   for ( j = 0; j < n; j++)
   {
     scanf("%d",&brr[i][j]);
      }
}
for ( i = 0; i < m; i++)
{
    for(j=0;j<n;j++){
           sum[i][j]=arr[i][j]+brr[i][j];
    }
    
}
printf("Sum=\n");
for ( i = 0; i < m; i++)
{
    for(j=0;j<n;j++){
         printf("%d",sum[i][j]);  
    }printf("\n");
    
}
return 0;
}