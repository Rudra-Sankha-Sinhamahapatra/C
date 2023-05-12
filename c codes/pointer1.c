#include <stdio.h>
int main()
{
    int *p;
    float *q;
    double *r;
    

    printf("\nThe size of integer pointer is %ld", sizeof(p));
    printf("\nThe size of float pointer is %ld", sizeof(q));
    printf("\nThe size of double pointer is %ld", sizeof(r));
    printf("\nThe size of character pointer is %ld", sizeof(char *));
    
    return 0;
}