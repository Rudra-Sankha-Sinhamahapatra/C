//Set1:B2: C program to store information of 5 Students[roll,name,mark and dob(dd/mm/yyyy)]Using nested structures and display

#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Date dob;
};

int main() {
    struct Student students[5];

    // Inputting information of 5 students
    printf("Enter information of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
    }

    // Displaying information of 5 students
    printf("\nInformation of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("Date of Birth: %02d/%02d/%04d\n", students[i].dob.day, students[i].dob.month, students[i].dob.year);
    }

    return 0;
}
