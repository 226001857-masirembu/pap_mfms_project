#include <stdio.h>
#include "reports.h"

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void reportsMenu(
    char employeeNames[][50],
    float basicSalary[],
    float housing[],
    float transport[],
    int employeeCount,
    char departments[][50],
    float allocatedBudget[],
    float expenditure[],
    int departmentCount,
    char supplierNames[][100],
    char supplierEmails[][100],
    char supplierPhones[][30],
    char supplierTowns[][50],
    int supplierCount,
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][50],
    float assetValues[],
    char assetDepartments[][50],
    char assetConditions[][30],
    int assetCount
)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          MUNICIPAL REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Summary Report\n");
        printf("6. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                employeeReport(
                    employeeNames,
                    basicSalary,
                    housing,
                    transport,
                    employeeCount
                );
                break;

            case 2:
                budgetReport(
                    departments,
                    allocatedBudget,
                    expenditure,
                    departmentCount
                );
                break;

            case 3:
                supplierReport(
                    supplierNames,
                    supplierEmails,
                    supplierPhones,
                    supplierTowns,
                    supplierCount
                );
                break;

            case 4:
                assetReport(
                    assetIDs,
                    assetNames,
                    assetTypes,
                    assetValues,
                    assetDepartments,
                    assetConditions,
                    assetCount
                );
                break;

            case 5:
                summaryReport(
                    basicSalary,
                    housing,
                    transport,
                    employeeCount,
                    allocatedBudget,
                    expenditure,
                    departmentCount,
                    supplierCount,
                    assetValues,
                    assetCount
                );
                break;

            case 6:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1 to 6.\n");
        }

    } while(choice != 6);
}

void employeeReport(
    char employeeNames[][50],
    float basicSalary[],
    float housing[],
    float transport[],
    int employeeCount
)
{
    int i;
    int highestPosition = 0;
    int lowestPosition = 0;

    float salary;
    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    if(employeeCount == 0)
    {
        printf("\nNo employees are registered.\n");
        return;
    }

    highestSalary = calculateSalary(
        basicSalary[0],
        housing[0],
        transport[0]
    );

    lowestSalary = highestSalary;

    for(i = 0; i < employeeCount; i++)
    {
        salary = calculateSalary(
            basicSalary[i],
            housing[i],
            transport[i]
        );

        totalSalary = totalSalary + salary;

        if(salary > highestSalary)
        {
            highestSalary = salary;
            highestPosition = i;
        }

        if(salary < lowestSalary)
        {
            lowestSalary = salary;
            lowestPosition = i;
        }
    }

    averageSalary = totalSalary / employeeCount;

    printf("\n========================================\n");
    printf("            EMPLOYEE REPORT\n");
    printf("========================================\n");
    printf("Total Employees       : %d\n", employeeCount);
    printf("Total Salary Expense  : N$ %.2f\n", totalSalary);
    printf("Average Salary        : N$ %.2f\n", averageSalary);
    printf("Highest Salary        : N$ %.2f\n", highestSalary);
    printf("Lowest Salary         : N$ %.2f\n", lowestSalary);
    printf("\nHighest Paid Employee : %s\n",
           employeeNames[highestPosition]);
    printf("Lowest Paid Employee  : %s\n",
           employeeNames[lowestPosition]);
    printf("========================================\n");
}

void budgetReport(
    char departments[][50],
    float allocatedBudget[],
    float expenditure[],
    int departmentCount
)
{
    int i;
    int withinBudget = 0;
    int overBudget = 0;

    float totalBudget = 0;
    float totalExpenditure = 0;
    float remainingBudget;
    float balance;

    if(departmentCount == 0)
    {
        printf("\nNo budget information is available.\n");
        return;
    }

    for(i = 0; i < departmentCount; i++)
    {
        totalBudget = totalBudget + allocatedBudget[i];
        totalExpenditure = totalExpenditure + expenditure[i];

        if(expenditure[i] > allocatedBudget[i])
        {
            overBudget++;
        }
        else
        {
            withinBudget++;
        }
    }

    remainingBudget = totalBudget - totalExpenditure;

    printf("\n========================================\n");
    printf("             BUDGET REPORT\n");
    printf("========================================\n");
    printf("Total Departments      : %d\n", departmentCount);
    printf("Total Allocated Budget : N$ %.2f\n", totalBudget);
    printf("Total Expenditure      : N$ %.2f\n", totalExpenditure);
    printf("Remaining Budget       : N$ %.2f\n", remainingBudget);
    printf("Within Budget          : %d\n", withinBudget);
    printf("Over Budget            : %d\n", overBudget);

    printf("\n----------------------------------------\n");
    printf("DEPARTMENT BUDGET DETAILS\n");
    printf("----------------------------------------\n");

    for(i = 0; i < departmentCount; i++)
    {
        balance = allocatedBudget[i] - expenditure[i];

        printf("\nDepartment  : %s\n", departments[i]);
        printf("Allocated   : N$ %.2f\n", allocatedBudget[i]);
        printf("Expenditure : N$ %.2f\n", expenditure[i]);
        printf("Balance     : N$ %.2f\n", balance);

        if(expenditure[i] > allocatedBudget[i])
        {
            printf("Status      : OVER BUDGET\n");
            printf("Overspent   : N$ %.2f\n",
                   expenditure[i] - allocatedBudget[i]);
        }
        else if(expenditure[i] == allocatedBudget[i])
        {
            printf("Status      : BUDGET FULLY USED\n");
        }
        else
        {
            printf("Status      : WITHIN BUDGET\n");
        }
    }

    printf("\n========================================\n");
}

void supplierReport(
    char supplierNames[][100],
    char supplierEmails[][100],
    char supplierPhones[][30],
    char supplierTowns[][50],
    int supplierCount
)
{
    int i;

    printf("\n========================================\n");
    printf("            SUPPLIER REPORT\n");
    printf("========================================\n");

    if(supplierCount == 0)
    {
        printf("No suppliers are registered.\n");
        printf("========================================\n");
        return;
    }

    printf("Total Suppliers: %d\n", supplierCount);

    for(i = 0; i < supplierCount; i++)
    {
        printf("\n----------------------------------------\n");
        printf("Supplier %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Name  : %s\n", supplierNames[i]);
        printf("Email : %s\n", supplierEmails[i]);
        printf("Phone : %s\n", supplierPhones[i]);
        printf("Town  : %s\n", supplierTowns[i]);
    }

    printf("\n========================================\n");
}

void assetReport(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][50],
    float assetValues[],
    char assetDepartments[][50],
    char assetConditions[][30],
    int assetCount
)
{
    int i;
    int highestPosition = 0;
    int lowestPosition = 0;

    float totalValue = 0;
    float averageValue;
    float highestValue;
    float lowestValue;

    if(assetCount == 0)
    {
        printf("\nNo assets are registered.\n");
        return;
    }

    highestValue = assetValues[0];
    lowestValue = assetValues[0];

    for(i = 0; i < assetCount; i++)
    {
        totalValue = totalValue + assetValues[i];

        if(assetValues[i] > highestValue)
        {
            highestValue = assetValues[i];
            highestPosition = i;
        }

        if(assetValues[i] < lowestValue)
        {
            lowestValue = assetValues[i];
            lowestPosition = i;
        }
    }

    averageValue = totalValue / assetCount;

    printf("\n========================================\n");
    printf("              ASSET REPORT\n");
    printf("========================================\n");
    printf("Total Assets        : %d\n", assetCount);
    printf("Total Asset Value   : N$ %.2f\n", totalValue);
    printf("Average Asset Value : N$ %.2f\n", averageValue);

    printf("\nMost Expensive Asset: %s\n",
           assetNames[highestPosition]);

    printf("Value               : N$ %.2f\n",
           highestValue);

    printf("\nCheapest Asset      : %s\n",
           assetNames[lowestPosition]);

    printf("Value               : N$ %.2f\n",
           lowestValue);

    printf("\n----------------------------------------\n");
    printf("REGISTERED ASSETS\n");
    printf("----------------------------------------\n");

    for(i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID       : %d\n", assetIDs[i]);
        printf("Asset Name     : %s\n", assetNames[i]);
        printf("Asset Type     : %s\n", assetTypes[i]);
        printf("Purchase Value : N$ %.2f\n", assetValues[i]);
        printf("Department     : %s\n", assetDepartments[i]);
        printf("Condition      : %s\n", assetConditions[i]);
    }

    printf("\n========================================\n");
}

void summaryReport(
    float basicSalary[],
    float housing[],
    float transport[],
    int employeeCount,
    float allocatedBudget[],
    float expenditure[],
    int departmentCount,
    int supplierCount,
    float assetValues[],
    int assetCount
)
{
    int i;

    float salary;
    float totalSalary = 0;
    float totalBudget = 0;
    float totalExpenditure = 0;
    float totalAssetValue = 0;

    for(i = 0; i < employeeCount; i++)
    {
        salary = calculateSalary(
            basicSalary[i],
            housing[i],
            transport[i]
        );

        totalSalary = totalSalary + salary;
    }

    for(i = 0; i < departmentCount; i++)
    {
        totalBudget = totalBudget + allocatedBudget[i];
        totalExpenditure = totalExpenditure + expenditure[i];
    }

    for(i = 0; i < assetCount; i++)
    {
        totalAssetValue = totalAssetValue + assetValues[i];
    }

    printf("\n========================================\n");
    printf("       MUNICIPAL SUMMARY REPORT\n");
    printf("========================================\n");

    printf("\nEMPLOYEES\n");
    printf("----------------------------------------\n");
    printf("Total Employees      : %d\n", employeeCount);
    printf("Total Salary Expense : N$ %.2f\n", totalSalary);

    printf("\nBUDGET\n");
    printf("----------------------------------------\n");
    printf("Total Budget         : N$ %.2f\n", totalBudget);
    printf("Total Expenditure    : N$ %.2f\n", totalExpenditure);
    printf("Remaining Budget     : N$ %.2f\n",
           totalBudget - totalExpenditure);

    printf("\nSUPPLIERS\n");
    printf("----------------------------------------\n");
    printf("Total Suppliers      : %d\n", supplierCount);

    printf("\nASSETS\n");
    printf("----------------------------------------\n");
    printf("Total Assets         : %d\n", assetCount);
    printf("Total Asset Value    : N$ %.2f\n", totalAssetValue);

    printf("\n========================================\n");
}

