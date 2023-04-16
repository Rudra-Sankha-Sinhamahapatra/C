#include <stdio.h>

int main() {
    int n, i, search, first, last, middle;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements in ascending order: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (arr[middle] < search) {
            first = middle + 1;
        } else if (arr[middle] == search) {
            printf("%d found at index %d.\n", search, middle);
            break;
        } else {
            last = middle - 1;
        }

        middle = (first + last) / 2;
    }

    if (first > last) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
