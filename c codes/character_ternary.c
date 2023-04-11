#include <stdio.h>

int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    
    // using ternary operator to check if c is an alphabet or not
   int result= (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? printf("%c is an alphabet.\n", c) : printf("%c is not an alphabet.\n", c);
    printf("",result);
    return 0;
}