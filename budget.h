#ifndef BUDGET_H
#define BUDGET_H

void calculateRemainingBudget(int index);
void determineBudgetStatus(int index);
int searchBudgetByDepartment(char *deptName);
void displayBudgetInfo(int index);

void addDepartmentBudget(void);
void enterExpenditure(void);
void displayAllBudgets(void);
void displayExceedingBudgets(void);
void budgetManagementMenu(void);

#endif
