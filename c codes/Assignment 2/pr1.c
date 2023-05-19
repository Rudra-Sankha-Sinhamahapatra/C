//write a program to sort students information based on their marks using structures
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

void sortStudents(struct Student students[], int n) {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (students[i].marks < students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; ++i) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    sortStudents(students, n);

    printf("\nStudent information sorted based on marks:\n");
    printf("-----------------------------------------\n");
    printf("Name\t\tMarks\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; ++i) {
        printf("%s\t\t%d\n", students[i].name, students[i].marks);
    }

    return 0;
}
