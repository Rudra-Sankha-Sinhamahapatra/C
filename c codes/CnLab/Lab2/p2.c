#include <stdio.h>
#include <string.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void studentInfo_value(struct student_info student) {
    printf("Call by value\n");
    printf("Roll no: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of birth: %d/%d/%d\n", student.age.day, student.age.month, student.age.year);
}

void studentInfo_address(struct student_info *student) {
    printf("Call by address\n");
    printf("Roll no: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of birth: %d/%d/%d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    struct student_info student;

    student.roll_no = 1;
    strcpy(student.name, "Aman Joshi");
    student.CGPA = 3.75;
    student.age.day = 15;
    student.age.month = 6;
    student.age.year = 2000;

    studentInfo_value(student);
    studentInfo_address(&student);

    return 0;
}

