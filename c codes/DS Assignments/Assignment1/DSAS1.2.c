#include <stdio.h>
#include <stdlib.h>
void frequency(int arr[], int n, int k);
void find(int m[],int size,int k);  
int main()
{
 int i,arr[30],n,k;
 printf("\nEnter the size of the array:");
 scanf("%d",&n);
 printf("\nEnter all the elements of the array:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
  printf("\nEnter the value of k:");
  scanf("%d",&k);
  frequency(arr,n,k);
  return 0;
 }
 void frequency(int arr[], int n, int k)
 {
  int size,gr,same,i,j,count=0;
  int m[10]={0};
  for(i=0;i<n;i++)
  {
   gr=arr[i];
   count=0;
   for(j=0;j<n;j++)
   {
    if(gr==arr[j])
    {
    count++;
   }
   }
   m[gr]=count;
  }
   size=sizeof(m)/sizeof(m[0]);
   for(i=0;i<size;i++)
   printf("%d ",m[i]);
   find(m,size,k);
  }
  void find(int m[], int size, int k)
  {
   printf("\n");
    int i,a[10],j,temp=0,s=0,gr=0;
    for(i=0;i<k;i++)
    {
     gr=0;
     for(j=0;j<size;j++)
     {
       if(m[j]>=gr)
       {
       gr=m[j];
       if(j>=temp)
       temp=j;
     }
    } 
     a[i]=temp;
     m[temp]=s;
     s--;
     temp=0;
     printf("%d ",a[i]);
    }
  }   
     
  
  
   
   
   
    
   
   
   
    
