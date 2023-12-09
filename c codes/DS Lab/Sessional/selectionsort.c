//selectionsort

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
   
        min= i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min= j;
        }

        if(min!=i){
        swap(&arr[min], &arr[i]);
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[8] = {64, 25, 12, 22, 11,6,8,2};
    

    printf("Current array: \n");
    print(arr, 8);

    selectionSort(arr, 8);

    printf("Sorted array: \n");
    print(arr, 8);

    return 0;
}
