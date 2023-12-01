#include<stdio.h>

int LinearSearch(int arr[],int n,int target){
for(int i=0;i<n;i++){
    if(arr[i]==target){
        return i;
    }
}
return -1;
}

int main() {
int target,n;
printf("Enter the size of the array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the elements of the array\n");
for (int i = 0; i < n; i++)
{
scanf("%d",&arr[i]);   
}
printf("Enter the element you want to search\n");
scanf("%d",& target);

int result=LinearSearch(arr,n,target);
if(result==-1){
    printf("Element cannot exist!");
}
else{
    printf("Element Found on index %d\n",result);
}
return 0;
}