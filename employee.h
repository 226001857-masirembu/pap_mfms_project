#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

extern int employeeID[MAX_EMPLOYEES];
extern char name[MAX_EMPLOYEES][50];
extern char department[MAX_EMPLOYEES][50];
extern char position[MAX_EMPLOYEES][50];
extern char phone[MAX_EMPLOYEES][20];

extern float basicSalary[MAX_EMPLOYEES];
extern float housingAllowance[MAX_EMPLOYEES];
extern float transportAllowance[MAX_EMPLOYEES];

extern int employeeCount;

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void displaySalary(void);

float calculateSalary(int index);

#endif
