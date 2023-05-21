#include <stdio.h>

void printString(char* str) {
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("The string is: ");
    printString(str);
    printf("\n");

    return 0;
}
