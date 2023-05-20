#include <stdio.h>

struct address {
    char country[20];
    char city[30];
    char phone[14];
};

struct employee {
    char name[50];
    int age;
    float salary;
    struct address emp_address;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", emp[i].name);

        printf("Enter age: ");
        scanf("%d", &emp[i].age);

        printf("Enter salary: ");
        scanf("%f", &emp[i].salary);

        printf("Enter country: ");
        scanf("%s", emp[i].emp_address.country);

        printf("Enter city: ");
        scanf("%s", emp[i].emp_address.city);

        printf("Enter phone no: ");
        scanf("%s", emp[i].emp_address.phone);
    }

    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Age: %d\n", emp[i].age);
        printf("Salary:$%.2f\n", emp[i].salary);
        printf("Country: %s\n", emp[i].emp_address.country);
        printf("City: %s\n", emp[i].emp_address.city);
        printf("Phone no: %s\n", emp[i].emp_address.phone);
    }

    return 0;
}
