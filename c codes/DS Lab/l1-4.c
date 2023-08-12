// Sample Input/Output:
 
// Enter complex number 1: 3  4
// Enter complex number 2: 4  5
 
// MENU
// 1. addition
// 2. multiplication
// Enter your choice: 1
	
// Sum=7+9i
// Enter your choice: 2
 
// Sum=4+19i



#include <stdio.h>


struct Complex {
    double real;
    double imag;
};


struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}


void multiplyComplex(struct Complex* num1, struct Complex* num2, struct Complex* result) {
    result->real = (num1->real * num2->real) - (num1->imag * num2->imag);
    result->imag = (num1->real * num2->imag) + (num1->imag * num2->real);
}

int main() {
    struct Complex num1, num2, result;

    printf("Enter complex number 1: ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    printf("Enter complex number 2: ");
    scanf("%lf %lf", &num2.real, &num2.imag);

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addComplex(num1, num2);
                printf("Sum = %.2lf + %.2lfi\n", result.real, result.imag);
                break;
            case 2:
                multiplyComplex(&num1, &num2, &result);
                printf("Product = %.2lf + %.2lfi\n", result.real, result.imag);
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }

    } while (choice == 1 || choice == 2);

    return 0;
}
