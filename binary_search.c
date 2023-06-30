#include <stdio.h>

int binarySearch(int arr[], int search, int first, int last) {
    if (first > last) {
        return -1;  // Element not found
    }

    int middle = (first + last) / 2;

    if (arr[middle] == search) {
        return middle;  // Element found
    } else if (arr[middle] < search) {
        return binarySearch(arr, search, middle + 1, last);  // Search in the right half
    } else {
        return binarySearch(arr, search, first, middle - 1);  // Search in the left half
    }
}

int main() {
    int n, i, search;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements in ascending order: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    int index = binarySearch(arr, search, 0, n - 1);

    if (index != -1) {
        printf("%d found at index %d.\n", search, index);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
