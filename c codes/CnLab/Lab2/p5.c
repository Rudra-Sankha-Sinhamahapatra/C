#include <stdio.h>

void print_bytes(unsigned int num)
{
    unsigned char *bytePtr = (unsigned char *)&num;
    printf("Byte contents:\n");
    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Byte %d: %u (Hex: %02X)\n", i, bytePtr[i], bytePtr[i]);
    }
}
unsigned int convert_endianness(unsigned int num)
{
    return ((num >> 24) & 0x000000FF) | 
           ((num >> 8) & 0x0000FF00) | 
           ((num << 8) & 0x00FF0000) |
           ((num << 24) & 0xFF000000);
}
int main()
{
    unsigned int num;

    
    unsigned int test = 1;

    if (*(unsigned char *)&test == 1)
    {
        printf("Host machine is Little Endian.\n");
    }
    else
    {
        printf("Host machine is Big Endian.\n");
    }

    
    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    
    print_bytes(num);

    
    unsigned int converted_num = convert_endianness(num);
    printf("\nConverted number (to %s Endian): %u\n", (*(unsigned char *)&test == 1) ? "Big" : "Little", converted_num);


    print_bytes(converted_num);

    return 0;
}
