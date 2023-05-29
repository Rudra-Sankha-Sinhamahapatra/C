//Sorting student marks
#include<stdio.h>
struct student{
    char name[50];
    int roll;
    float marks;
};
void sortStudents(int n,struct student Students[n]){
struct student temp;
int i,j;
for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(Students[i].marks<Students[j].marks){
        temp=Students[i];
        Students[i]=Students[j];
        Students[j]=temp;
        }
    }
}
}

int main() {
 int n;
 printf("Enter the number of Students:\n");
 scanf("%d",&n);
 struct student Students[n];
 printf("Enter Student Details:\n");
 for(int i=0;i<n;i++){
    printf("Enter-Student %d name:",i+1);
    scanf("%s",&Students[i].name);
    printf("\nRoll=");
    scanf("%d",&Students[i].roll);
    printf("\nMarks:");
    scanf("%f",&Students[i].marks);
 }
    printf("Displaying Students Information:\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d details",i+1);
        printf("\nName=%s",Students[i].name);
        printf("\nRoll=%d",Students[i].roll);
        printf("\nMarks=%.2f",Students[i].marks);
    }
    
 
return 0;
}