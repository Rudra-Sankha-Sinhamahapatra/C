#include <stdio.h> 

#include <stdlib.h> 

struct cbits {

unsigned b1:1;

unsigned b2:1;

unsigned b3:1;

unsigned b4:1;

unsigned b5:1;

unsigned b6:1;

unsigned b7:1;

unsigned b8:1;
};
union U{
    char c;
    struct cbits cb;
};

int main()

{

union U look;

/* Assign a character to memory */

look.c='A';

/* Look at each bit */

printf("\nBIT 1 =%d\n",  look.cb.b1 );

printf("BIT 2 =%d \n" , look.cb.b2 );

printf("BIT 3 =%d\n", look.cb.b3 );

printf("BIT 4 = %d\n", look.cb.b4 );

printf("BIT 5 =%d\n",look.cb.b5 );

printf("BIT 6 = %d\n" , look.cb.b6 );

  printf("BIT 7 = %d\n", look.cb.b7 );

printf("BIT 8 =%d\n", look.cb.b8 );

return 0;

}