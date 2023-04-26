#include <stdio.h>

void sum1();
void sum2(int num1, int num2);
int sum3();
int sum4(int num1, int num2);

int main() {
    int choice, num1, num2, sum;

    do {
        printf("\n1. Sum using function without return type without parameter\n");
        printf("2. Sum using function without return type with parameter\n");
        printf("3. Sum using function with return type without parameter\n");
        printf("4. Sum using function with return type with parameter\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                sum1();
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                sum2(num1, num2);
                break;
            case 3:
                sum = sum3();
                printf("Sum = %d\n", sum);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                sum = sum4(num1, num2);
                printf("Sum = %d\n", sum);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void sum1() {
    int num1, num2, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    printf("Sum = %d\n", sum);
}

void sum2(int num1, int num2) {
    int sum;

    sum = num1 + num2;
    printf("Sum = %d\n", sum);
}

int sum3() {
    int num1, num2, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    return sum;
}

int sum4(int num1, int num2) {
    int sum;

    sum = num1 + num2;
    return sum;
}