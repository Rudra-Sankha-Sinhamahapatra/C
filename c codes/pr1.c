
include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, d, r1, r2, realPart, i;

    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f",&a, &b, &c);

    d= b*b - 4*a*c;

    if (d> 0)
    {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("The roots are real and different.\n");
        printf("Root1 = %.2f and Root2 = %.2f",r1 , r2);
    }

    else if (d== 0)
    {
        r1 = r2 = -b / (2*a);
        printf("The roots are real and same.\n");
        printf("Root1 = Root2 = %.2f;", r1);
    }

    else
    {
        realPart = -b/(2*a);
        i = sqrt(-d)/(2*a);
        printf("The roots are imaginary.\n");
        printf("Root1 = %.2f + %.2fi and Root2 = %.2f - %.2fi", realPart, i, realPart, i);
    }

    return 0;
}
