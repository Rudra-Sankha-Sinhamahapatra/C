// 2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using
// function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array
// Sample Input/Output:
// Enter size n : 5
// Enter element of array:
// Enter Array elements: 10 23 45 37 52
// ***MENU***
// 1. Insert
// 2. Delete
// 3. Linear Search
// 4. Traverse
// 5. Exit
// Enter option: 1
// Element to insert: 61 Enter Position: 2
// Element inserted
// Enter option: 4
// Array Elements: 10 23 61 45 37 52
// Note: Other menu choices are similarly needs to verify.

#include <stdio.h>


void insertElement(int arr[], int *n, int element, int position) {
    if (position < 0 || position > *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
    printf("Element inserted\n");
}


void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted\n");
}


int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i; 
        }
    }
    return -1; 
}


void traverseArray(int arr[], int n) {
    printf("Array Elements:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);

    int arr[100]; 
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, element, position, searchResult;

    do {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertElement(arr, &n, element, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &n, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchResult = linearSearch(arr, n, element);
                if (searchResult != -1) {
                    printf("Element found at position: %d\n", searchResult);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                traverseArray(arr, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
