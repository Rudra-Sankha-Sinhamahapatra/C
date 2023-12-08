#include <stdio.h>

void merge(int arr[], int start, int end, int low, int high) {
    int size = end - start + 1;
    int temp[size];
    int index = 0;
    int i = start, j = low;

    while (i <= high && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    while (i <= high) {
        temp[index++] = arr[i++];
    }

    while (j <= end) {
        temp[index++] = arr[j++];
    }

    for (int k = 0; k < size; ++k) {
        arr[start + k] = temp[k];
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, end, start, mid);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
