#include <stdio.h>
//reverse a string using pointers

void reverseString(char* str) {
    char* start = str;
    char* end = str;
    
    // Find the end of the string
    while (*end != '\0') {
        end++;
    }
    end--;

    // Reverse the string using pointers
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
