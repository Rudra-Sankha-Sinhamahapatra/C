#include<stdio.h>

void quicksort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int s=low;
    int e=high;
    int m=s+(e-s)/2;
    int pivot=arr[m];
    while(s<=e){
        while(arr[s]<pivot){
            s++;
        }
        while(arr[e]>pivot){
            e--;
        }
        if(s<=e){
            int temp=arr[s];
            arr[s]=arr[e];
            arr[e]=temp;
            s++;
            e--;
        }
    }
    quicksort(arr,low,e);
    quicksort(arr,s,high);
}

int main(){
    int n;
    printf("Enter the size of the Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted Array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}