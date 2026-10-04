#ifndef REPORTS_H
#define REPORTS_H

float calculateSalary(float basic, float housing, float transport);

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
);

void employeeReport(
    char employeeNames[][50],
    float basicSalary[],
    float housing[],
    float transport[],
    int employeeCount
);

void budgetReport(
    char departments[][50],
    float allocatedBudget[],
    float expenditure[],
    int departmentCount
);

void supplierReport(
    char supplierNames[][100],
    char supplierEmails[][100],
    char supplierPhones[][30],
    char supplierTowns[][50],
    int supplierCount
);

void assetReport(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][50],
    float assetValues[],
    char assetDepartments[][50],
    char assetConditions[][30],
    int assetCount
);

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
);

#endif

