#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, discriminant, root1, root2, realPart, imaginaryPart;

    printf("Enter coefficients a, b and c: ");
    scanf("%f%f%f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // If the discriminant is positive, there are two real roots
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and different.\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }

    // If the discriminant is zero, there is one real root
    else if (discriminant == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("The roots are real and same.\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }

    // If the discriminant is negative, there are two complex roots
    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are complex and different.\n");
        printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }

    return 0;
}