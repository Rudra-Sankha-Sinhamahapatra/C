#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int num;
    
    printf("Enter a number: ");
    scanf("%u", &num);

    struct pkt packet;

    packet.ch1 = (num & 0xFF);       
    packet.ch2[0] = (num >> 8) & 0xFF; 
    packet.ch2[1] = (num >> 16) & 0xFF; 
    packet.ch3 = (num >> 24) & 0xFF;    

    printf("Content of each member of the structure:\n");
    printf("ch1: %u\n", (unsigned char)packet.ch1);
    printf("ch2[0]: %u\n", (unsigned char)packet.ch2[0]);
    printf("ch2[1]: %u\n", (unsigned char)packet.ch2[1]);
    printf("ch3: %u\n", (unsigned char)packet.ch3);

    unsigned int aggregated_num = (unsigned char)packet.ch1 |
                                  ((unsigned char)packet.ch2[0] << 8) |
                                  ((unsigned char)packet.ch2[1] << 16) |
                                  ((unsigned char)packet.ch3 << 24);

    printf("Aggregated number: %u\n", aggregated_num);

    return 0;
}
