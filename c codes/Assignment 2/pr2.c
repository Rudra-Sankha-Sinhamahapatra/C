//write a program to store student's information and display it using structures (structure array)
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int rollNumber;
};

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; ++i) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
    }

    printf("\nStudent information:\n");
    printf("-----------------------------------------\n");
    printf("Name\t\tAge\tRoll Number\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; ++i) {
        printf("%s\t\t%d\t%d\n", students[i].name, students[i].age, students[i].rollNumber);
    }

    return 0;
}
