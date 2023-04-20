#include<stdio.h>
int main() {
int arr[6]={2,3,4,5,6,7};
int max=arr[0],smax=arr[0];
for (int i = 0; i < 6; i++)
{
    if (max<arr[i])
    {
        max=arr[i];
    }
    
}
for (int i = 0; i < 6; i++)
{
    if (max!=arr[i] && smax<arr[i])
    {
        smax=arr[i];
    }
    
}
printf("%d",smax);

    return 0;
}