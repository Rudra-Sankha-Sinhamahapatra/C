#include<stdio.h>
#define pi 3.14
void circle(float radius,float *area,float *perimeter,float *circumference){
    *area=pi*radius*radius;
    *circumference=2*pi*radius;
    *perimeter=*circumference;
}

int main() {
    float radius,area,circumference,perimeter;
    printf("Enter the radius of the circle\n");
    scanf("%f",&radius);
    circle(radius,&area,&perimeter,&circumference);
    printf("Area of the circle is %.2f\n",area);
    printf("Circumference of the circle is %.2f\n",circumference);
    printf("Perimeter of the circle is %.2f\n",perimeter);
return 0;
}