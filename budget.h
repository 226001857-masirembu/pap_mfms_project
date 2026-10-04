#ifndef BUDGET_H
#define BUDGET_H
#define MAX_BUDGETS 50
#define MAX_DEPT_NAME 50
typedef struct
{
char department[MAX_DEPT_NAME];
double allocatedBudget;
double expenditure;
double remainingBudget;
char status[20];
} Budget;
extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;
void clearInputBuffer(void);
void getStringInput(char buffer, int size);
int getDoubleInput(double value);
double calculateRemainingBudget(int index);
int checkBudgetStatus(int index);
int searchBudgetByDepartment(const char deptName);
void displayBudgetInfo(int index);
void addBudget(void);
void displayBudgets(void);
void enterExpenditure(void);
void displayExceedingBudgets(void);
void budgetManagementMenu(void);
#endif
