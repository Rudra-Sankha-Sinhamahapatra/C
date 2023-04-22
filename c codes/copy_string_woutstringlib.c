#include <stdio.h>

int main()
{
    char source_string[100], destination_string[100];
    int i = 0;
    
    printf("Enter the source string: ");
    gets(source_string);
    
    // Copying the source string to destination string
    while (source_string[i] != '\0')
    {
        destination_string[i] = source_string[i];
        i++;
    }
    destination_string[i] = '\0';
    
    printf("\nSource String: %s", source_string);
    printf("\nDestination String: %s", destination_string);
    
    return 0;
}
