#include <stdio.h>

#define MAX 100

int main() {
    int size, i, arr[MAX];
    int *ptr;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter %d integers into array: ", size);

    ptr = &arr[0];

    for (i = 0; i < size; i++) {
        scanf("%d", ptr);
        ptr++;
    }

    ptr = &arr[size - 1];

    printf("\nElements of array in reverse order are:\n");

    for (i = size - 1; i >= 0; i--) {
        printf("%d\t", i, *ptr);
        ptr--;
    }

    return 0;
}
