#include <stdio.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(long long binary)
{
    int decimal = 0, exponent = 0;

    while (binary > 0)
    {
        int digit = binary % 10;
        decimal += digit * pow(2, exponent);
        exponent++;
        binary /= 10;
    }

    return decimal;
}

// Function to convert decimal to binary
long long decimalToBinary(int decimal)
{
    long long binary = 0;
    int remainder, placeValue = 1;

    while (decimal > 0)
    {
        remainder = decimal % 2;
        binary += remainder * placeValue;
        placeValue *= 10;
        decimal /= 2;
    }

    return binary;
}

int main()
{
    int choice, decimal;
    long long binary;

    printf("Choose conversion:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter binary number: ");
        scanf("%lld", &binary);
        printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
        break;

    case 2:
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        printf("Binary equivalent: %lld\n", decimalToBinary(decimal));
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}
