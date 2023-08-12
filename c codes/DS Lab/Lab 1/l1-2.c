// 1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and deallocate the memory of the array after its use.
// Sample Input:
// Enter size of the array: 5
// Enter array elements: 3  9  7  4  8
// Sample Output:
// Sum =10
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }

    printf("Sum = %d\n", sum);

    
    free(arr);

    return 0;
}
