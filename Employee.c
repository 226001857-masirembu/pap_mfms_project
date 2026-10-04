#include <stdio.h>
#include <string.h>


int employeeID[MAX_EMPLOYEES];
char name[MAX_EMPLOYEES][50];
char department[MAX_EMPLOYEES][50];
char position[MAX_EMPLOYEES][50];
char phone[MAX_EMPLOYEES][20];

float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];

int employeeCount = 0;

void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employeeID[employeeCount]);

    getchar();

    printf("Enter Name: ");
    fgets(name[employeeCount], 50, stdin);
    name[employeeCount][strcspn(name[employeeCount], "\n")] = '\0';

    printf("Enter Department: ");
    fgets(department[employeeCount], 50, stdin);
    department[employeeCount][strcspn(department[employeeCount], "\n")] = '\0';

    printf("Enter Position: ");
    fgets(position[employeeCount], 50, stdin);
    position[employeeCount][strcspn(position[employeeCount], "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(phone[employeeCount], 20, stdin);
    phone[employeeCount][strcspn(phone[employeeCount], "\n")] = '\0';

    printf("Enter Basic Salary: N$");
    scanf("%f", &basicSalary[employeeCount]);

    printf("Enter Housing Allowance: N$");
    scanf("%f", &housingAllowance[employeeCount]);

    printf("Enter Transport Allowance: N$");
    scanf("%f", &transportAllowance[employeeCount]);

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}


float calculateSalary(int index)
{
    float grossSalary;

    grossSalary = basicSalary[index] + housingAllowance[index] + transportAllowance[index];

    return grossSalary;
}


void displayEmployees()
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID       : %d\n", employeeID[i]);
        printf("Name              : %s\n", name[i]);
        printf("Department        : %s\n", department[i]);
        printf("Position          : %s\n", position[i]);
        printf("Phone Number      : %s\n", phone[i]);
        printf("Basic Salary      : N$%.2f\n", basicSalary[i]);
        printf("Housing Allowance : N$%.2f\n", housingAllowance[i]);
        printf("Transport         : N$%.2f\n", transportAllowance[i]);
        printf("Gross Salary      : N$%.2f\n", calculateSalary(i));

        printf("-----------------------------------\n");
    }
}

void searchEmployee()
{
    int searchID;
    int i;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == searchID)
        {
            printf("\n===== EMPLOYEE FOUND =====\n");
            printf("Employee ID       : %d\n", employeeID[i]);
            printf("Name              : %s\n", name[i]);
            printf("Department        : %s\n", department[i]);
            printf("Position          : %s\n", position[i]);
            printf("Phone Number      : %s\n", phone[i]);
            printf("Basic Salary      : N$%.2f\n", basicSalary[i]);
            printf("Housing Allowance : N$%.2f\n", housingAllowance[i]);
            printf("Transport         : N$%.2f\n", transportAllowance[i]);
            printf("Gross Salary      : N$%.2f\n", calculateSalary(i));

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %d was not found.\n", searchID);
    }
}


void displaySalary()
{
    int id;
    int i;
    int found = 0;
    float grossSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == id)
        {
            grossSalary = calculateSalary(i);

            printf("\n===== SALARY INFORMATION =====\n");
            printf("Employee ID       : %d\n", employeeID[i]);
            printf("Employee Name     : %s\n", name[i]);
            printf("Basic Salary      : N$%.2f\n", basicSalary[i]);
            printf("Housing Allowance : N$%.2f\n", housingAllowance[i]);
            printf("Transport         : N$%.2f\n", transportAllowance[i]);
            printf("-------------------------------\n");
            printf("Gross Salary      : N$%.2f\n", grossSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}


int main()
{
    int choice;

    do
    {
        printf("\n\n====================================\n");
        printf("       EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Display Employee Information\n");
        printf("6. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee();
            break;

        case 2:
            displayEmployees();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            displaySalary();
            break;

        case 5:
            displayEmployees();
            break;

        case 6:
            printf("\nThank you for using the Employee Management System.\n");
            break;

        default:
            printf("\nInvalid choice. Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}
