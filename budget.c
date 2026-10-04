#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "budget.h"

Budget budgets[MAX_BUDGETS];
int budgetCount = 0;

/* Clear unwanted characters from the input buffer */
void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* Read a string safely */
void getStringInput(char *buffer, int size)
{
    int i = 0;
    int j = 0;

    if (fgets(buffer, size, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }

    /* Remove leading spaces */
    while (buffer[i] == ' ')
    {
        i++;
    }

    while (buffer[i] != '\0')
    {
        buffer[j++] = buffer[i++];
    }

    buffer[j] = '\0';
}

/* Read a non-negative double */
int getDoubleInput(double *value)
{
    char input[100];
    char *endPtr;

    getStringInput(input, sizeof(input));

    if (strlen(input) == 0)
    {
        printf("Error: Input cannot be empty.\n");
        return 0;
    }

    *value = strtod(input, &endPtr);

    if (*endPtr != '\0' || *value < 0)
    {
        printf("Error: Invalid or negative value not allowed.\n");
        return 0;
    }

    return 1;
}

/* Calculate remaining budget */
double calculateRemainingBudget(int index)
{
    budgets[index].remainingBudget =
        budgets[index].allocatedBudget -
        budgets[index].expenditure;

    return budgets[index].remainingBudget;
}

/* Check whether a budget is over budget */
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

/* Search for a department */
int searchBudgetByDepartment(const char *deptName)
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

/* Display one budget */
void displayBudgetInfo(int index)
{
    printf("\n-----------------------------\n");
    printf("Department: %s\n",
           budgets[index].department);

    printf("Allocated Budget: N$%.2f\n",
           budgets[index].allocatedBudget);

    printf("Expenditure: N$%.2f\n",
           budgets[index].expenditure);

    printf("Remaining Budget: N$%.2f\n",
           budgets[index].remainingBudget);

    printf("Status: %s\n",
           budgets[index].status);

    printf("-----------------------------\n");
}

/* Add a new department budget */
void addBudget(void)
{
    char tempDept[MAX_DEPT_NAME];
    double tempAllocated;

    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Error: Budget limit reached.\n");
        return;
    }

    printf("\n--- Enter Departmental Budget ---\n");
    printf("Department Name: ");

    getStringInput(tempDept, sizeof(tempDept));

    if (strlen(tempDept) == 0)
    {
        printf("Error: Department name cannot be empty.\n");
        return;
    }

    if (searchBudgetByDepartment(tempDept) != -1)
    {
        printf("Error: Department already exists.\n");
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

    printf("Budget added successfully!\n");
}

/* Enter expenditure for a department */
void enterExpenditure(void)
{
    char deptName[MAX_DEPT_NAME];
    double expAmount;
    int index;

    if (budgetCount == 0)
    {
        printf("No departments yet. Add one first.\n");
        return;
    }

    printf("\n--- Enter Expenditure ---\n");
    printf("Department Name: ");

    getStringInput(deptName, sizeof(deptName));

    index = searchBudgetByDepartment(deptName);

    if (index == -1)
    {
        printf("Error: Department '%s' not found.\n",
               deptName);
        return;
    }

    printf("Current Allocated: N$%.2f\n",
           budgets[index].allocatedBudget);

    printf("Current Expenditure: N$%.2f\n",
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

/* Display all budgets */
void displayBudgets(void)
{
    int i;

    double totalAlloc = 0.0;
    double totalExp = 0.0;
    double totalRem = 0.0;

    if (budgetCount == 0)
    {
        printf("\nNo budget information to display.\n");
        return;
    }

    printf("\n===== ALL DEPARTMENTAL BUDGETS =====\n");

    for (i = 0; i < budgetCount; i++)
    {
        displayBudgetInfo(i);

        totalAlloc += budgets[i].allocatedBudget;
        totalExp += budgets[i].expenditure;
        totalRem += budgets[i].remainingBudget;
    }

    printf("\n===== SUMMARY =====\n");
    printf("Total Allocated: N$%.2f\n", totalAlloc);
    printf("Total Expenditure: N$%.2f\n", totalExp);
    printf("Total Remaining: N$%.2f\n", totalRem);
}

/* Display departments that are over budget */
void displayExceedingBudgets(void)
{
    int i;
    int found = 0;

    printf("\n===== DEPARTMENTS EXCEEDING BUDGET =====\n");

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
        printf("All departments are WITHIN BUDGET.\n");
    }
}

/* Budget management menu */
void budgetManagementMenu(void)
{
    int choice;
    char input[10];

    while (1)
    {
        printf("\n=====================================\n");
        printf(" MUNICIPAL BUDGET MANAGEMENT\n");
        printf("=====================================\n");

        printf("1. Enter Departmental Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display All Budgets\n");
        printf("4. Display Departments Exceeding Budget\n");
        printf("5. Search Budget by Department\n");
        printf("6. Exit Module\n");

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
                char searchName[MAX_DEPT_NAME];
                int index;

                printf("Enter department to search: ");

                getStringInput(searchName,
                               sizeof(searchName));

                index = searchBudgetByDepartment(searchName);

                if (index != -1)
                {
                    displayBudgetInfo(index);
                }
                else
                {
                    printf("Department not found.\n");
                }

                break;
            }

            case 6:
                return;

            default:
                printf("Invalid choice. Try 1-6.\n");
        }
    }
}