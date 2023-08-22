#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array.
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        return 1;
    }

    // Read the elements of the array from the user.
    printf("Enter elements of array: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }

    // Calculate the sum of the elements of the array.
    for (i = 0; i < n; ++i)
    {
        sum += *(ptr + i);
    }

    // Print the sum of the elements of the array.
    printf("Sum = %d\n", sum);

    // Free the memory allocated for the array.
    free(ptr);

    return 0;
}
