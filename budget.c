#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "budget.h"

Budget budgets[MAX_BUDGETS];
int budgetCount = 0;

/* Clear leftover characters from input */
void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* discard */
    }
}

/* Read a non-empty string */
void getStringInput(char *buffer, int size)
{
    while (1)
    {
        if (fgets(buffer, size, stdin) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strlen(buffer) > 0)
            {
                return;
            }
        }

        printf("Input cannot be empty. Please try again: ");
    }
}

/* Read a non-negative double */
int getDoubleInput(double *value)
{
    char input[100];
    char *endPtr;

    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        *value = strtod(input, &endPtr);

        if (endPtr == input)
        {
            printf("Invalid input. Please enter a number: ");
            continue;
        }

        while (*endPtr == ' ' || *endPtr == '\t')
        {
            endPtr++;
        }

        if (*endPtr != '\n' && *endPtr != '\0')
        {
            printf("Invalid input. Please enter a number: ");
            continue;
        }

        if (*value < 0)
        {
            printf("Value cannot be negative. Please try again: ");
            continue;
        }

        return 1;
    }
}

/* Calculate remaining budget */
double calculateRemainingBudget(int index)
{
    if (index < 0 || index >= budgetCount)
    {
        return 0.0;
    }

    return budgets[index].allocatedBudget -
           budgets[index].expenditure;
}

/* Check budget status */
int checkBudgetStatus(int index)
{
    if (index < 0 || index >= budgetCount)
    {
        return 0;
    }

    if (budgets[index].expenditure >
        budgets[index].allocatedBudget)
    {
        strcpy(budgets[index].status, "Exceeded");
        return 0;
    }

    strcpy(budgets[index].status, "Within Budget");
    return 1;
}

/* Search budget by department */
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
    if (index < 0 || index >= budgetCount)
    {
        return;
    }

    budgets[index].remainingBudget =
        calculateRemainingBudget(index);

    checkBudgetStatus(index);

    printf("\n----------------------------------------\n");
    printf("Department        : %s\n",
           budgets[index].department);
    printf("Allocated Budget  : N$%.2f\n",
           budgets[index].allocatedBudget);
    printf("Expenditure       : N$%.2f\n",
           budgets[index].expenditure);
    printf("Remaining Budget  : N$%.2f\n",
           budgets[index].remainingBudget);
    printf("Status            : %s\n",
           budgets[index].status);
    printf("----------------------------------------\n");
}

/* Add a new budget */
void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget storage is full.\n");
        return;
    }

    printf("\n========== ADD BUDGET ==========\n");

    printf("Enter Department: ");
    getStringInput(
        budgets[budgetCount].department,
        MAX_DEPT_NAME
    );

    if (searchBudgetByDepartment(
            budgets[budgetCount].department) != -1)
    {
        printf("A budget for this department already exists.\n");
        return;
    }

    printf("Enter Allocated Budget: N$ ");

    if (!getDoubleInput(
            &budgets[budgetCount].allocatedBudget))
    {
        printf("Invalid budget amount.\n");
        return;
    }

    budgets[budgetCount].expenditure = 0.0;

    budgets[budgetCount].remainingBudget =
        budgets[budgetCount].allocatedBudget;

    strcpy(
        budgets[budgetCount].status,
        "Within Budget"
    );

    budgetCount++;

    printf("Budget added successfully.\n");
}

/* Display all budgets */
void displayBudgets(void)
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n========== BUDGET LIST ==========\n");

    for (i = 0; i < budgetCount; i++)
    {
        displayBudgetInfo(i);
    }
}

/* Enter expenditure */
void enterExpenditure(void)
{
    char department[MAX_DEPT_NAME];
    int index;
    double expenditure;

    if (budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\nEnter Department: ");
    getStringInput(department, MAX_DEPT_NAME);

    index = searchBudgetByDepartment(department);

    if (index == -1)
    {
        printf("Department budget not found.\n");
        return;
    }

    printf("Enter Expenditure: N$ ");

    if (!getDoubleInput(&expenditure))
    {
        printf("Invalid expenditure amount.\n");
        return;
    }

    budgets[index].expenditure = expenditure;

    budgets[index].remainingBudget =
        calculateRemainingBudget(index);

    checkBudgetStatus(index);

    printf("Expenditure updated successfully.\n");
}

/* Display budgets that exceeded allocation */
void displayExceedingBudgets(void)
{
    int i;
    int found = 0;

    if (budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n========== EXCEEDED BUDGETS ==========\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure >
            budgets[i].allocatedBudget)
        {
            displayBudgetInfo(i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No budgets have been exceeded.\n");
    }
}

/* Budget management menu */
void budgetManagementMenu(void)
{
    int choice;

    do
    {
        printf("\n=============================\n");
        printf("       BUDGET MANAGEMENT\n");
        printf("=============================\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Enter Expenditure\n");
        printf("4. Display Exceeded Budgets\n");
        printf("5. Return to Main Menu\n");
        printf("=============================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                enterExpenditure();
                break;

            case 4:
                displayExceedingBudgets();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please select 1-5.\n");
        }

    } while (choice != 5);
}
