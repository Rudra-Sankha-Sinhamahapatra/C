#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;
    char choice;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Enter 'A' for addition, 'S' for subtraction, 'M' for multiplication, 'D' for division: ");
    scanf(" %c", &choice); // add a space before %c to consume the newline character in the input buffer

    switch (choice) {
        case 'A':
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
            break;
        case 'S':
            result = a - b;
            printf("%d - %d = %d\n", a, b, result);
            break;
        case 'M':
            result = a * b;
            printf("%d * %d = %d\n", a, b, result);
            break;
        case 'D':
            if (b == 0) {
                printf("Error: division by zero\n");
            } else {
                result = a / b;
                printf("%d / %d = %d\n", a, b, result);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
