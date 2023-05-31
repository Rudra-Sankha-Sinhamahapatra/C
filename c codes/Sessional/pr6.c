//Set1:A1 Wap to find factors of a number

#include <stdio.h>

int main() {
    int number, i;

    // Prompt the user to enter a number
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    printf("Factors of %d are: ", number);

    // Find and print the factors
    for (i = 1; i <= number; i++) {
        if (number % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
