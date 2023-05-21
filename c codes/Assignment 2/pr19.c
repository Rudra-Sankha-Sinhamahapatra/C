#include <stdio.h>
#include <ctype.h>

int countVowels(const char* str) {
    int count = 0;

    while (*str != '\0') {
        char ch = tolower(*str);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;

        str++;
    }

    return count;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int vowelCount = countVowels(str);

    printf("Number of vowels in the string: %d\n", vowelCount);

    return 0;
}
