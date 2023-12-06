#include <stdio.h>
void search(int arr[],int n,int k);
void descending(int arr[],int n)
{
 int i,j,swap=0,temp,k;
 for(i=0;i<n;i++)
 {
  swap=0;
  for(j=0;j<n-i-1;j++)
  {
   if(arr[j]<arr[j+1])
   {
    swap=1;
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
  if(swap==0)
  break;
  }
  printf("\n");
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
 printf("\nEnter the value of k:");
 scanf("%d",&k);
 search(arr,n,k);
}
void search(int arr[],int n,int k)
{
  for(int i=0;i<n;i++)
  {
   if(i==k-1)
   printf("The %d-th largest sum of the contiguous subarray is %d",k,arr[i]);
  }
 }  
 int main()
 {              
 int i,j,arr[30],currentSum=0;
 int a[]={10,-5,7,-3,2};
 int n=sizeof(a)/sizeof(a[0]);
 int sumIndex=0;
 for (int i = 0; i < n; i++) {
 int currentSum = 0;
 for (int j = i; j < n; j++) {
 currentSum += a[j];
 arr[sumIndex++] = currentSum;
 }
  }
descending(arr,sumIndex);
 return 0;
 }
 
 
 
   
   
   





    
