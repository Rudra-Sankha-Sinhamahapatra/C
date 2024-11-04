#include <stdio.h>
int main() {
    int num = 258;
    char c1=num;
    char c2= c1>>1;
    char c3=c2>>1;
    char c4=c3>>1;
   
    printf ("%d \n", c4);
    printf("%d \n", c3);
    printf("%d \n", c2);
    printf("%d \n", c1);
}
