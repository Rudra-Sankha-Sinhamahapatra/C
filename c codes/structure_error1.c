#include<stdio.h>
struct EmpD
{
    int id,age;
    float salary;
}emp,employee;

int main() {
employee.age=22;
employee.id=1;
employee.salary=1200.00;
printf("Age=%d,Id=%d,Salary=%f\n",emp.age,emp.id,emp.salary);
return 0;
}