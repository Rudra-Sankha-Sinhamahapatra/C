#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n)
{
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;

    // Recursive case: factorial of n is n multiplied by factorial of (n-1)
    return n * factorial(n - 1);
}

int main()
{
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    // Checking if the number is non-negative
    if (number < 0)
    {
        printf("Error: Factorial is not defined for negative numbers.\n");
    }
    else
    {
        int result = factorial(number);
        printf("The factorial of %d is %d.\n", number, result);
    }

    return 0;
}
