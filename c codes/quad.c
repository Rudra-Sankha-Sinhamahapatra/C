#include <stdio.h>
#include<math.h>

 
 
int main()
{
    double a, b, c, root1, root2,imaginaryPart,realPart;
    printf("Enter the coefficient of x^2: ");
    scanf("%lf", &a);
    printf("Enter the coefficient of x: ");
    scanf("%lf",&b);
    printf("Enter the constant: ");
    scanf("%lf", &c);
    double determinant = b*b - 4*a*c;
 
    // condition for real and different roots
    if (determinant > 0)
    {
        // sqrt() function returns square root
        root1 = (-b+sqrt(determinant))/(2*a);
        root2 = (-b-sqrt(determinant))/(2*a);
 
        printf("Root1 = %.2lf and Root2 = %.2lf",root1 , root2);
    }
 
    //condition for real and equal roots
    else if (determinant == 0)
    {
        root1 = root2 = -b/(2*a);
 
        printf("Root1 = Root2 = %.2lf;", root1);
    }
 
    // if roots are not real
    else
    {
        realPart = -b/(2*a);
        imaginaryPart = sqrt(-determinant)/(2*a);
        printf("Root1 = %.2lf+%.2lfi and Root2 = %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
    }
 
    return 0;
}