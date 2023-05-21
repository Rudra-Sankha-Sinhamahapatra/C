#include <stdio.h>

void reverseArray(int* arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        // Swap elements pointed by start and end pointers
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Move the pointers towards each other
        start++;
        end--;
    }
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    reverseArray(arr, size);
    
    printf("Reversed array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
