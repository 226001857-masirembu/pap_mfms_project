#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "budget.h"
Budget budgets[MAX_BUDGETS];
int budgetCount = 0;
void clearInputBuffer(void)
{
int c;
while ((c = getchar()) != '
' && c != EOF)
{
}
}
void getStringInput(char buffer, int size)
{
if (fgets(buffer, size, stdin) != NULL)
{
buffer[strcspn(buffer, "
")] = '\0';
}
int i = 0;
int j = 0;
while (buffer[i] == ' ')
{
i++;
}
while (buffer[i] != '\0')
{
buffer[j] = buffer[i];
j++;
i++;
}
buffer[j] = '\0';
}
int getDoubleInput(double value)
{
char input[100];
char endPtr;
getStringInput(input, sizeof(input));
if (strlen(input) == 0)
{
printf("Error: Input cannot be empty.
");
return 0;
}
value = strtod(input, &endPtr);
if (endPtr != '\0' || value < 0)
{
printf("Error: Invalid or negative value not allowed.
");
return 0;
}
return 1;
}
double calculateRemainingBudget(int index)
{
budgets[index].remainingBudget =
budgets[index].allocatedBudget -
budgets[index].expenditure;
return budgets[index].remainingBudget;
}
int checkBudgetStatus(int index)
{
if (budgets[index].expenditure >
budgets[index].allocatedBudget)
{
strcpy(budgets[index].status, "EXCEEDED");
return 1;
}
strcpy(budgets[index].status, "WITHIN BUDGET");
return 0;
}
int searchBudgetByDepartment(const char deptName)
{
int i;
for (i = 0; i < budgetCount; i++)
{
if (strcmp(budgets[i].department, deptName) == 0)
{
return i;
}
}
return -1;
}
void displayBudgetInfo(int index)
{
printf("
-----------------------------
");
printf("Department: %s
",
budgets[index].department);
printf("Allocated Budget: N$%.2f
",
budgets[index].allocatedBudget);
printf("Expenditure: N$%.2f
",
budgets[index].expenditure);
printf("Remaining Budget: N$%.2f
",
budgets[index].remainingBudget);
printf("Status: %s
",
budgets[index].status);
printf("-----------------------------
");
}
void addBudget(void)
{
char tempDept[MAX_DEPT_NAME];
double tempAllocated;
if (budgetCount >= MAX_BUDGETS)
{
printf("Error: Budget limit reached.
");
return;
}
printf("
--- Enter Departmental Budget ---
");
printf("Department Name: ");
getStringInput(tempDept, sizeof(tempDept));
if (strlen(tempDept) == 0)
{
printf("Error: Department name cannot be empty.
");
return;
}
if (searchBudgetByDepartment(tempDept) != -1)
{
printf("Error: Department already exists.
");
return;
}
printf("Allocated Budget (N$): ");
if (!getDoubleInput(&tempAllocated))
{
return;
}
strcpy(budgets[budgetCount].department, tempDept);
budgets[budgetCount].allocatedBudget = tempAllocated;
budgets[budgetCount].expenditure = 0.0;
calculateRemainingBudget(budgetCount);
checkBudgetStatus(budgetCount);
budgetCount++;
printf("Budget added successfully!
");
}
void enterExpenditure(void)
{
char deptName[MAX_DEPT_NAME];
double expAmount;
int index;
if (budgetCount == 0)
{
printf("No departments yet. Add one first.
");
return;
}
printf("
--- Enter Expenditure ---
");
printf("Department Name: ");
getStringInput(deptName, sizeof(deptName));
index = searchBudgetByDepartment(deptName);
if (index == -1)
{
printf("Error: Department '%s' not found.
",
deptName);
return;
}
printf("Current Allocated: N$%.2f
",
budgets[index].allocatedBudget);
printf("Current Expenditure: N$%.2f
",
budgets[index].expenditure);
printf("Enter additional expenditure (N$): ");
if (!getDoubleInput(&expAmount))
{
return;
}
budgets[index].expenditure += expAmount;
calculateRemainingBudget(index);
checkBudgetStatus(index);
displayBudgetInfo(index);
}
void displayBudgets(void)
{
int i;
double totalAlloc = 0.0;
double totalExp = 0.0;
double totalRem = 0.0;
if (budgetCount == 0)
{
printf("
No budget information to display.
");
return;
}
printf("
===== ALL DEPARTMENTAL BUDGETS =====
");
for (i = 0; i < budgetCount; i++)
{
displayBudgetInfo(i);
totalAlloc += budgets[i].allocatedBudget;
totalExp += budgets[i].expenditure;
totalRem += budgets[i].remainingBudget;
}
printf("
===== SUMMARY =====
");
printf("Total Allocated: N$%.2f
", totalAlloc);
printf("Total Expenditure: N$%.2f
", totalExp);
printf("Total Remaining: N$%.2f
", totalRem);
}
void displayExceedingBudgets(void)
{
int i;
int found = 0;
printf("
===== DEPARTMENTS EXCEEDING BUDGET =====
");
for (i = 0; i < budgetCount; i++)
{
checkBudgetStatus(i);
if (strcmp(budgets[i].status, "EXCEEDED") == 0)
{
displayBudgetInfo(i);
found = 1;
}
}
if (!found)
{
printf("All departments are WITHIN BUDGET.
");
}
}
void budgetManagementMenu(void)
{
int choice;
char input[10];
while (1)
{
printf("
=====================================
");
printf(" MUNICIPAL BUDGET MANAGEMENT
");
printf("=====================================
");
printf("1. Enter Departmental Budget
");
printf("2. Enter Expenditure
");
printf("3. Display All Budgets
");
printf("4. Display Departments Exceeding Budget
");
printf("5. Search Budget by Department
");
printf("6. Exit Module
");
printf("Enter choice: ");
getStringInput(input, sizeof(input));
choice = atoi(input);
switch (choice)
{
case 1:
addBudget();
break;
case 2:
enterExpenditure();
break;
case 3:
displayBudgets();
break;
case 4:
displayExceedingBudgets();
break;
case 5:
{
char name[MAX_DEPT_NAME];
int index;
printf("Enter department to search: ");
getStringInput(name, sizeof(name));
index = searchBudgetByDepartment(name);
if (index != -1)
{
displayBudgetInfo(index);
}
else
{
printf("Department not found.
");
}
break;
}
case 6:
return;
default:
printf("Invalid choice. Try 1-6.
");
}
}
}
