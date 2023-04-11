#include<stdio.h>
int main() {
float length,breadth,perimeter,area;
printf("\nEnter the length");
scanf("%f",&length);
printf("\n Enter the breadth");
scanf("%f",&breadth);
perimeter=2*(length+breadth);
area=length*breadth;
printf("\n The perimeter is %f",perimeter);
printf("\n The area is %f",area);
if(perimeter>area){
    printf("\n The perimeter is greater than the area");

}
else if(area>perimeter){
    printf("\n The area is greater than the perimeter");

}
else if(perimeter=area){
    printf("The area is equal to the perimeter\n");
}

return 0;
}