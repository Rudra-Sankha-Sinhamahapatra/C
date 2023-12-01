#include <stdio.h>

// Function to find the maximum number in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Using counting sort to sort the elements based on significant places (exp)
void countingSort(int arr[], int n, int exp) {
    const int BASE = 10;
    int output[n];
    int count[BASE] = {0};

    // Count the occurrences of digits at the current significant place
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }

    // Update count[i] to store the position of the next occurrence of the same digit
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in their sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);

    // Perform counting sort for every digit place (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
