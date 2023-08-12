// 1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use an array of structure.  
 
// Sample Input:
// Sample Output:
// Enter no.of employees: 2
// Enter employee 1 information:
// Avneesh
// Professor
// 10000
// 15%
// 45%
// Enter employee 2 information:
// Avantika
// Professor
// 20000
// 10%
// 35%
 
// Employee Information:
 
// Name: Suchismita
// Designation: Professor
// Basic Salary:10000
// HRA %: 15%
// DA %: 45%
// Gross Salary: 14500
 
// Name: Sarita
// Designation: Professor
// Basic Salary: 20000
// HRA %: 10%
// DA %: 35%
// Gross Salary: 29000
 
#include <stdio.h>


struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
    float grossSalary;
};

int main() {
    int n;

    printf("Enter no. of employees: ");
    scanf("%d", &n);

    struct Employee employees[n]; 

    
    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");  
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hraPercentage);
        printf("DA %%: ");
        scanf("%f", &employees[i].daPercentage);

    
        employees[i].grossSalary = employees[i].basicSalary +
                                  (employees[i].basicSalary * employees[i].hraPercentage / 100) +
                                  (employees[i].basicSalary * employees[i].daPercentage / 100);
    }


    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA %%: %.2f%%\n", employees[i].hraPercentage);
        printf("DA %%: %.2f%%\n", employees[i].daPercentage);
        printf("Gross Salary: %.2f\n", employees[i].grossSalary);
    }

    return 0;
}
