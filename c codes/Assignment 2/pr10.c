#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int key)
{
    // Base case: If the left index becomes greater than the right index, the element is not found
    if (left > right)
        return -1;

    // Calculate the middle index
    int mid = (left + right) / 2;

    // If the key is found at the middle index, return the index
    if (arr[mid] == key)
        return mid;

    // If the key is smaller than the middle element, search in the left half
    else if (arr[mid] > key)
        return binarySearch(arr, left, mid - 1, key);

    // If the key is greater than the middle element, search in the right half
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main()
{
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, size - 1, key);

    if (index == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", index);

    return 0;
}
