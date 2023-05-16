#include <stdio.h>

#define MAX_SIZE 100

void insertAtBeginning(int arr[], int *size, int element) {
    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    for (int i = *size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = element;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int element) {
    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    arr[*size] = element;
    (*size)++;
}

void insertAtLocation(int arr[], int *size, int element, int location) {
    if (location < 0 || location >= *size) {
        printf("Invalid location. Cannot insert element.\n");
        return;
    }

    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    for (int i = *size - 1; i >= location; i--) {
        arr[i + 1] = arr[i];
    }

    arr[location] = element;
    (*size)++;
}

void insertAfterKey(int arr[], int *size, int element, int key) {
    int i, location = -1;

    for (i = 0; i < *size; i++) {
        if (arr[i] == key) {
            location = i;
            break;
        }
    }

    if (location == -1) {
        printf("Key not found. Cannot insert element.\n");
        return;
    }

    insertAtLocation(arr, size, element, location + 1);
}

void deleteFromBeginning(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }

    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

void deleteFromEnd(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }

    (*size)--;
}

void deleteFromLocation(int arr[], int *size, int location) {
    if (location < 0 || location >= *size) {
        printf("Invalid location. Cannot delete element.\n");
        return;
    }

    for (int i = location; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

void deleteBeforeKey(int arr[], int *size, int key) {
    int i, location = -1;

    for (i = 0; i < *size; i++) {
        if (arr[i] == key) {
            location = i;
            break;
        }
    }

    if (location <= 0) {
        printf("Key not found or no element before the key. Cannot delete element.\n");
        return;
    }

    deleteFromLocation(arr, size, location - 1);
}

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1;
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, location, key, index;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at given location\n");
        printf("4. Insert after a key\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete from given location\n");
        printf("8. Delete before a key\n");
        printf("9. Search an element\n");
        printf("10. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtBeginning(arr, &size, element);
                printf("Element inserted at the beginning.\n");
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtEnd(arr, &size, element);
                printf("Element inserted at the end.\n");
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the location: ");
                scanf("%d", &location);
                insertAtLocation(arr, &size, element, location);
                printf("Element inserted at location %d.\n", location);
                break;
            case 4:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the key: ");
                scanf("%d", &key);
                insertAfterKey(arr, &size, element, key);
                printf("Element inserted after key %d.\n", key);
                break;
            case 5:
                deleteFromBeginning(arr, &size);
                printf("Element deleted from the beginning.\n");
                break;
            case 6:
                deleteFromEnd(arr, &size);
                printf("Element deleted from the end.\n");
                break;
            case 7:
                printf("Enter the location: ");
                scanf("%d", &location);
                deleteFromLocation(arr, &size, location);
                printf("Element deleted from location %d.\n", location);
                break;
            case 8:
                printf("Enter the key: ");
                scanf("%d", &key);
                deleteBeforeKey(arr, &size, key);
                printf("Element deleted before key %d.\n", key);
                break;
            case 9:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                index = searchElement(arr, size, element);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 10:
                displayArray(arr, size);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
                       default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}