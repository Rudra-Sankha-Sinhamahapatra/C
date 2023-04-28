#include <stdio.h>

// Function to find gcd of two numbers
int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}

// Function to find hcf of two numbers
int hcf(int num1, int num2)
{
    return (num1 * num2) / gcd(num1, num2);
}

int main()
{
    int num1, num2;

    printf("Enter two numbers to find their GCD and HCF: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
    printf("HCF of %d and %d is: %d\n", num1, num2, hcf(num1, num2));

    return 0;
}