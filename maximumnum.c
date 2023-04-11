#include <stdio.h>

int main() {
    long long  int a, b, c, maximum;
    printf("Enter three numbers: ");
    scanf("%lld %lld %lld", &a, &b, &c);

    maximum = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    printf("The maximum number is %lld", maximum);
  
    return 0;
}