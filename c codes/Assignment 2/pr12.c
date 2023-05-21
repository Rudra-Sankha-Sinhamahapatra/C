#include <stdio.h>

// Function to calculate the sum of an array using recursion
int arraySum(int arr[], int n)
{
    // Base case: If the array is empty, return 0
    if (n == 0)
        return 0;

    // Recursive case: Add the last element with the sum of the remaining elements
    return arr[n - 1] + arraySum(arr, n - 1);
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = arraySum(arr, size);
    printf("The sum of the integers in the array is %d.\n", sum);

    return 0;
}
