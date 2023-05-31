//Set1:B1:C program to calculate a Number raised to the power of N using Recursion (a to the power b=c)

#include <stdio.h>

double power(double base, int exponent);

int main() {
    double base, result;
    int exponent;

    // Prompt the user to enter the base number
    printf("Enter the base number: ");
    scanf("%lf", &base);

    // Prompt the user to enter the exponent
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Call the power function
    result = power(base, exponent);

    // Print the result
    printf("%.2lf raised to the power of %d = %.2lf\n", base, exponent, result);

    return 0;
}

double power(double base, int exponent) {
    // Base case: If the exponent is 0, return 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive case: Multiply the base by the result of (base^(exponent-1))
    else {
        return base * power(base, exponent - 1);
    }
}


