#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, j;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Find the length of str1
    for (i = 0; str1[i] != '\0'; i++);

    // Concatenate characters from str2 to str1
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i + j] = str2[j];
    }

    // Add null character at the end of the concatenated string
    str1[i + j] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}
