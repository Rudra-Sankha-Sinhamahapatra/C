#include <stdio.h>
void sorta(int arr[10][10],int r,int c);
void sortd(int arr[10][10],int r, int c);
int main()
{
 int i,j,r,c,arr[10][10];
 printf("Enter the rows and columns of the matrix:");
 scanf("%d %d",&r,&c);
 printf("\nEnter all the elements of the matrix:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&arr[i][j]);
  }
  sorta(arr,i,c);
 }
 for(i=0;i<c;i++)
 {
  sortd(arr,r,i);
 } 
 printf("\nThe matrix after getting sorted:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d ",arr[i][j]);
  }
  printf("\n"); 
 }
 return 0; 
}
void sorta(int arr[10][10],int r,int c)
{
 int temp,flag=0;
 for(int i=0;i<c;i++)
 {
  flag=0;
  for(int j=0;j<c-i-1;j++)
  {
   if(arr[r][j]>arr[r][j+1])
   {
    flag=1;
    temp=arr[r][j];
    arr[r][j]=arr[r][j+1];
    arr[r][j+1]=temp;
   }
  }
  if(flag==0)
  break;
 }
}    
 void sortd(int arr[10][10],int r,int c)
 {
  int flag=0,temp;
  for(int i=0;i<r;i++)
  {
  flag=0;
   for(int j=0;j<r-i-1;j++)
   {
    if(arr[j][c]<arr[j+1][c])
    {
     flag=1;
     temp=arr[j][c];
     arr[j][c]=arr[j+1][c];
     arr[j+1][c]=temp;
    }
   } 
    if(flag==0)
    break;
  }   
  }   
     
     
  
  
  
  
  
    
    
    
   
   
   
   
     
