#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void input(int arr[], int size);
void display(int arr[], int size);
void all_odd(int arr[], int size);
int sum_of_elements(int arr[], int size);
bool is_prime(int n);
void all_prime(int arr[], int size);

int main()
{
    int arr[MAX_SIZE];
    int size;
    char choice;

    do
    {
        printf("\nMenu\n");
        printf("----\n");
        printf("a. Input\n");
        printf("b. Display\n");
        printf("c. All Odd Numbers\n");
        printf("d. Sum of Elements\n");
        printf("e. All Prime Numbers\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
            scanf("%d", &size);
            input(arr, size);
            break;

        case 'b':
            display(arr, size);
            break;

        case 'c':
            all_odd(arr, size);
            break;

        case 'd':
            printf("Sum of Elements: %d\n", sum_of_elements(arr, size));
            break;

        case 'e':
            all_prime(arr, size);
            break;

        case 'f':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
            break;
        }
    } while (choice != 'f');

    return 0;
}

void input(int arr[], int size)
{
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int size)
{
    printf("Elements in the array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void all_odd(int arr[], int size)
{
    printf("All Odd Numbers: ");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int sum_of_elements(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void all_prime(int arr[], int size)
{
    printf("All Prime Numbers: ");
    for (int i = 0; i < size; i++)
    {
        if (is_prime(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}