#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Using ternary operator to check if the character is an alphabet letter
    (ch >= 'A' && ch <= 'Z') ? printf("Input character is an uppercase letter") : ((ch >= 'a' && ch <= 'z') ? printf("Input character is a lowercase letter") : printf("Input character is not an alphabet letter"));

    return 0;
}