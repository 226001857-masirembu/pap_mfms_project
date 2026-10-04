#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BUDGETS 50
#define MAX_DEPT_NAME 50
// Structure for budget - as required by spec
typedef struct {
char department[MAX_DEPT_NAME];
double allocatedBudget;
double expenditure;
double remainingBudget;
char status[20]; // WITHIN BUDGET or EXCEEDED
} Budget;
Budget budgets[MAX_BUDGETS];
int budgetCount = 0;
// ========== Helper Functions ==========
void clearInputBuffer() {
int c;
while ((c = getchar())!= '
' && c!= EOF);
}
void getStringInput(char buffer, int size) {
fgets(buffer, size, stdin);
buffer[strcspn(buffer, "
")] = '\0';
// trim leading spaces
int i = 0, j = 0;
while (buffer[i] == ' ') i++;
while (buffer[i]!= '\0') buffer[j++] = buffer[i++];
buffer[j] = '\0';
}
int getDoubleInput(double value) {
char input[100];
getStringInput(input, sizeof(input));
if (strlen(input) == 0) {
printf("Error: Input cannot be empty.
");
return 0;
}
char endPtr;
value = strtod(input, &endPtr);
if (endPtr!= '\0' || value < 0) {
printf("Error: Invalid or negative value not allowed.
");
return 0;
}
return 1;
}
// ========== Core Logic Required by PDF ==========
void calculateRemainingBudget(int index) {
budgets[index].remainingBudget = budgets[index].allocatedBudget - budgets[index].expenditure;
}
void determineBudgetStatus(int index) {
if (budgets[index].expenditure <= budgets[index].allocatedBudget) {
strcpy(budgets[index].status, "WITHIN BUDGET");
} else {
strcpy(budgets[index].status, "EXCEEDED");
}
}
int searchBudgetByDepartment(char deptName) {
for (int i = 0; i < budgetCount; i++) {
if (strcmp(budgets[i].department, deptName) == 0) {
return i;
}
}
return -1;
}
void displayBudgetInfo(int index) {
printf("
-----------------------------
");
printf("Department: %s
", budgets[index].department);
printf("Allocated Budget: N$%.2f
", budgets[index].allocatedBudget);
printf("Expenditure: N$%.2f
", budgets[index].expenditure);
printf("Remaining Budget: N$%.2f
", budgets[index].remainingBudget);
printf("Status: %s
", budgets[index].status);
printf("-----------------------------
");
}
// ========== Module Functions ==========
void addDepartmentBudget() {
if (budgetCount >= MAX_BUDGETS) {
printf("Error: Limit reached.
"); return;
}
char tempDept[MAX_DEPT_NAME];
double tempAllocated;
printf("
--- Enter Departmental Budget ---
");
printf("Department Name: ");
getStringInput(tempDept, sizeof(tempDept));
if (strlen(tempDept) == 0) {
printf("Error: Department name cannot be empty.
"); return;
}
if (searchBudgetByDepartment(tempDept)!= -1) {
printf("Error: Department already exists!
"); return;
}
printf("Allocated Budget (N$): ");
if (!getDoubleInput(&tempAllocated)) return;
strcpy(budgets[budgetCount].department, tempDept);
budgets[budgetCount].allocatedBudget = tempAllocated;
budgets[budgetCount].expenditure = 0;
calculateRemainingBudget(budgetCount);
strcpy(budgets[budgetCount].status, "WITHIN BUDGET");
budgetCount++;
printf("Budget added successfully!
");
}
void enterExpenditure() {
if (budgetCount == 0) {
printf("No departments yet. Add one first.
"); return;
}
char deptName[MAX_DEPT_NAME];
double expAmount;
printf("
--- Enter Expenditure ---
");
printf("Department Name: ");
getStringInput(deptName, sizeof(deptName));
int index = searchBudgetByDepartment(deptName);
if (index == -1) {
printf("Error: Department '%s' not found.
", deptName); return;
}
printf("Current Allocated: N$%.2f | Current Expenditure: N$%.2f
",
budgets[index].allocatedBudget, budgets[index].expenditure);
printf("Enter additional expenditure (N$): ");
if (!getDoubleInput(&expAmount)) return;
budgets[index].expenditure += expAmount;
calculateRemainingBudget(index);
determineBudgetStatus(index);
displayBudgetInfo(index);
}
void displayAllBudgets() {
if (budgetCount == 0) {
printf("
No budget information to display.
"); return;
}
printf("
===== ALL DEPARTMENTAL BUDGETS =====
");
double totalAlloc = 0, totalExp = 0, totalRem = 0;
for (int i = 0; i < budgetCount; i++) {
displayBudgetInfo(i);
totalAlloc += budgets[i].allocatedBudget;
totalExp += budgets[i].expenditure;
totalRem += budgets[i].remainingBudget;
}
printf("
SUMMARY -> Total Allocated: N$%.2f | Total Expenditure: N$%.2f | Total Remaining: N$%.2f
",
totalAlloc, totalExp, totalRem);
}
void displayExceedingBudgets() {
printf("
===== DEPARTMENTS EXCEEDING BUDGET =====
");
int found = 0;
for (int i = 0; i < budgetCount; i++) {
if (strcmp(budgets[i].status, "EXCEEDED") == 0) {
displayBudgetInfo(i);
found = 1;
}
}
if (!found) printf("All departments are WITHIN BUDGET.
");
}
// ========== MAIN MENU FOR BUDGET MODULE ==========
void budgetManagementMenu() {
int choice;
char input[10];
while (1) {
printf("
=====================================
");
printf(" MUNICIPAL BUDGET MANAGEMENT - MFMS
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
switch (choice) {
case 1: addDepartmentBudget(); break;
case 2: enterExpenditure(); break;
case 3: displayAllBudgets(); break;
case 4: displayExceedingBudgets(); break;
case 5: {
char name[MAX_DEPT_NAME];
printf("Enter department to search: ");
getStringInput(name, sizeof(name));
int idx = searchBudgetByDepartment(name);
if (idx!= -1) displayBudgetInfo(idx);
else printf("Department not found.
");
break;
}
case 6: return;
default: printf("Invalid choice. Try 1-6.
");
}
}
}
// Standalone main for testing/demo
int main() {
// Preload sample data to show your lecturer
strcpy(budgets[0].department, "Finance");
budgets[0].allocatedBudget = 500000;
budgets[0].expenditure = 420000;
calculateRemainingBudget(0);
strcpy(budgets[0].status, "WITHIN BUDGET");
strcpy(budgets[1].department, "Water");
budgets[1].allocatedBudget = 300000;
budgets[1].expenditure = 350000;
calculateRemainingBudget(1);
strcpy(budgets[1].status, "EXCEEDED");
budgetCount = 2;
printf("Municipal Financial Management System - Budget Module
");
printf("Sample data loaded for demo.
");
budgetManagementMenu();
printf("Exiting Budget Management.
");
return 0;
}
