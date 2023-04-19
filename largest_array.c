#include <stdio.h>
// c program to find the largest from the array
int main() {
    int n,i;
    printf("Enter size of the array\n");
    scanf("%d",&n);
      int arr[n];
    printf("Enter elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
  
    int largest = arr[0];
    

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("The largest element in the array is %d", largest);
    return 0;
}
