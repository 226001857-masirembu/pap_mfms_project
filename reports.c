#include <stdio.h>
#include "reports.h"
#include "employee.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"


/* =========================
   REPORT SALARY CALCULATION
   ========================= */

float calculateReportSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}


/* =========================
   EMPLOYEE REPORT
   ========================= */

void employeeReport(void)
{
    int i;

    float totalSalary = 0.0f;
    float highestSalary = 0.0f;
    float lowestSalary = 0.0f;

    int highestIndex = 0;
    int lowestIndex = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employee data available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           EMPLOYEE REPORT\n");
    printf("========================================\n");

    for (i = 0; i < employeeCount; i++)
    {
        float salary;

        salary = calculateReportSalary(
            basicSalary[i],
            housingAllowance[i],
            transportAllowance[i]
        );

        totalSalary += salary;

        if (i == 0)
        {
            highestSalary = salary;
            lowestSalary = salary;
            highestIndex = i;
            lowestIndex = i;
        }
        else
        {
            if (salary > highestSalary)
            {
                highestSalary = salary;
                highestIndex = i;
            }

            if (salary < lowestSalary)
            {
                lowestSalary = salary;
                lowestIndex = i;
            }
        }
    }

    printf("\nTotal Employees      : %d\n", employeeCount);

    printf("Total Salary Expense : N$%.2f\n",
           totalSalary);

    printf("Average Salary       : N$%.2f\n",
           totalSalary / employeeCount);

    printf("\nHighest Salary\n");
    printf("----------------------------------------\n");

    printf("Employee ID          : %d\n",
           employeeID[highestIndex]);

    printf("Employee Name        : %s\n",
           name[highestIndex]);

    printf("Department           : %s\n",
           department[highestIndex]);

    printf("Amount               : N$%.2f\n",
           highestSalary);

    printf("\nLowest Salary\n");
    printf("----------------------------------------\n");

    printf("Employee ID          : %d\n",
           employeeID[lowestIndex]);

    printf("Employee Name        : %s\n",
           name[lowestIndex]);

    printf("Department           : %s\n",
           department[lowestIndex]);

    printf("Amount               : N$%.2f\n",
           lowestSalary);

    printf("\n----------------------------------------\n");
    printf("Employee Details\n");
    printf("----------------------------------------\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID    : %d\n",
               employeeID[i]);

        printf("Name           : %s\n",
               name[i]);

        printf("Department     : %s\n",
               department[i]);

        printf("Position       : %s\n",
               position[i]);

        printf("Phone Number   : %s\n",
               phone[i]);

        printf("Basic Salary   : N$%.2f\n",
               basicSalary[i]);

        printf("Housing        : N$%.2f\n",
               housingAllowance[i]);

        printf("Transport      : N$%.2f\n",
               transportAllowance[i]);

        printf("Gross Salary   : N$%.2f\n",
               calculateReportSalary(
                   basicSalary[i],
                   housingAllowance[i],
                   transportAllowance[i]
               ));
    }
}


/* =========================
   BUDGET REPORT
   ========================= */

void budgetReport(void)
{
    int i;

    double totalBudget = 0.0;
    double totalExpenditure = 0.0;
    double totalRemaining = 0.0;

    int withinBudget = 0;
    int exceededBudget = 0;

    if (budgetCount == 0)
    {
        printf("\nNo budget data available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("            BUDGET REPORT\n");
    printf("========================================\n");

    for (i = 0; i < budgetCount; i++)
    {
        totalBudget += budgets[i].allocatedBudget;

        totalExpenditure += budgets[i].expenditure;

        budgets[i].remainingBudget =
            budgets[i].allocatedBudget -
            budgets[i].expenditure;

        totalRemaining += budgets[i].remainingBudget;

        if (budgets[i].expenditure <=
            budgets[i].allocatedBudget)
        {
            withinBudget++;
        }
        else
        {
            exceededBudget++;
        }
    }

    printf("\nTotal Departments  : %d\n",
           budgetCount);

    printf("Total Budget       : N$%.2f\n",
           totalBudget);

    printf("Total Expenditure  : N$%.2f\n",
           totalExpenditure);

    printf("Total Remaining    : N$%.2f\n",
           totalRemaining);

    printf("\nWithin Budget      : %d\n",
           withinBudget);

    printf("Exceeded Budget    : %d\n",
           exceededBudget);

    printf("\n----------------------------------------\n");
    printf("Department Details\n");
    printf("----------------------------------------\n");

    for (i = 0; i < budgetCount; i++)
    {
        printf("\nDepartment         : %s\n",
               budgets[i].department);

        printf("Allocated Budget   : N$%.2f\n",
               budgets[i].allocatedBudget);

        printf("Expenditure        : N$%.2f\n",
               budgets[i].expenditure);

        printf("Remaining Budget   : N$%.2f\n",
               budgets[i].remainingBudget);

        if (budgets[i].expenditure <=
            budgets[i].allocatedBudget)
        {
            printf("Status             : Within Budget\n");
        }
        else
        {
            printf("Status             : EXCEEDED\n");
        }
    }
}


/* =========================
   SUPPLIER REPORT
   ========================= */

void supplierReport(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo supplier data available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           SUPPLIER REPORT\n");
    printf("========================================\n");

    printf("\nTotal Suppliers: %d\n",
           supplierCount);

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n",
               i + 1);

        printf("----------------------------------------\n");

        printf("Supplier ID    : %s\n",
               suppliers[i].id);

        printf("Name           : %s\n",
               suppliers[i].name);

        printf("Email          : %s\n",
               suppliers[i].email);

        printf("Telephone      : %s\n",
               suppliers[i].telephone);

        printf("Town/Location  : %s\n",
               suppliers[i].town);
    }
}


/* =========================
   ASSET REPORT
   ========================= */

void assetReport(void)
{
    int i;

    double totalValue = 0.0;
    double highestValue = 0.0;
    double lowestValue = 0.0;

    int highestIndex = 0;
    int lowestIndex = 0;

    if (assetCount == 0)
    {
        printf("\nNo asset data available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ASSET REPORT\n");
    printf("========================================\n");

    for (i = 0; i < assetCount; i++)
    {
        totalValue += assets[i].purchaseValue;

        if (i == 0)
        {
            highestValue = assets[i].purchaseValue;
            lowestValue = assets[i].purchaseValue;

            highestIndex = i;
            lowestIndex = i;
        }
        else
        {
            if (assets[i].purchaseValue > highestValue)
            {
                highestValue =
                    assets[i].purchaseValue;

                highestIndex = i;
            }

            if (assets[i].purchaseValue < lowestValue)
            {
                lowestValue =
                    assets[i].purchaseValue;

                lowestIndex = i;
            }
        }
    }

    printf("\nTotal Assets        : %d\n",
           assetCount);

    printf("Total Asset Value   : N$%.2f\n",
           totalValue);

    printf("Average Asset Value : N$%.2f\n",
           totalValue / assetCount);

    printf("\nHighest Value Asset\n");
    printf("----------------------------------------\n");

    printf("Asset ID            : %d\n",
           assets[highestIndex].id);

    printf("Name                : %s\n",
           assets[highestIndex].name);

    printf("Value               : N$%.2f\n",
           highestValue);

    printf("\nLowest Value Asset\n");
    printf("----------------------------------------\n");

    printf("Asset ID            : %d\n",
           assets[lowestIndex].id);

    printf("Name                : %s\n",
           assets[lowestIndex].name);

    printf("Value               : N$%.2f\n",
           lowestValue);

    printf("\n----------------------------------------\n");
    printf("Registered Assets\n");
    printf("----------------------------------------\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID       : %d\n",
               assets[i].id);

        printf("Name           : %s\n",
               assets[i].name);

        printf("Type           : %s\n",
               assets[i].type);

        printf("Purchase Value : N$%.2f\n",
               assets[i].purchaseValue);

        printf("Department     : %s\n",
               assets[i].department);

        printf("Condition      : %s\n",
               assets[i].condition);
    }
}


/* =========================
   SUMMARY REPORT
   ========================= */

void summaryReport(void)
{
    int i;

    double totalSalaryExpense = 0.0;
    double totalBudget = 0.0;
    double totalExpenditure = 0.0;
    double totalRemaining = 0.0;
    double totalAssetValue = 0.0;

    /*
       Calculate total employee salary expense.
       IMPORTANT:
       We use calculateReportSalary() here because
       employee.c's calculateSalary() accepts an index.
    */
    for (i = 0; i < employeeCount; i++)
    {
        totalSalaryExpense +=
            calculateReportSalary(
                basicSalary[i],
                housingAllowance[i],
                transportAllowance[i]
            );
    }

    /* Calculate budget totals */
    for (i = 0; i < budgetCount; i++)
    {
        totalBudget +=
            budgets[i].allocatedBudget;

        totalExpenditure +=
            budgets[i].expenditure;

        totalRemaining +=
            budgets[i].allocatedBudget -
            budgets[i].expenditure;
    }

    /* Calculate asset totals */
    for (i = 0; i < assetCount; i++)
    {
        totalAssetValue +=
            assets[i].purchaseValue;
    }

    printf("\n========================================\n");
    printf("            SUMMARY REPORT\n");
    printf("========================================\n");

    printf("\nEMPLOYEES\n");
    printf("----------------------------------------\n");

    printf("Total Employees       : %d\n",
           employeeCount);

    printf("Total Salary Expense  : N$%.2f\n",
           totalSalaryExpense);

    printf("\nBUDGETS\n");
    printf("----------------------------------------\n");

    printf("Total Departments     : %d\n",
           budgetCount);

    printf("Total Budget          : N$%.2f\n",
           totalBudget);

    printf("Total Expenditure     : N$%.2f\n",
           totalExpenditure);

    printf("Total Remaining       : N$%.2f\n",
           totalRemaining);

    printf("\nSUPPLIERS\n");
    printf("----------------------------------------\n");

    printf("Total Suppliers       : %d\n",
           supplierCount);

    printf("\nASSETS\n");
    printf("----------------------------------------\n");

    printf("Total Assets          : %d\n",
           assetCount);

    printf("Total Asset Value     : N$%.2f\n",
           totalAssetValue);

    printf("\n========================================\n");
}


/* =========================
   REPORTS MENU
   ========================= */

void reportsMenu(void)
{
    int choice;

    while (1)
    {
        printf("\n=============================\n");
        printf("          REPORTS\n");
        printf("=============================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Summary Report\n");
        printf("6. Back to Main Menu\n");
        printf("=============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                summaryReport();
                break;

            case 6:
                return;

            default:
                printf("\nInvalid choice. Please select 1-6.\n");
        }
    }
}
