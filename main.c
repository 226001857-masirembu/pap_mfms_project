#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "employee.h"
#include "budget.h"
#include "suppliers.h"

int readInt(void);
double readNonNegativeDouble(void);
void readNonEmptyString(char *text, int size);
void assetMenu(void);
void employeeMenu(void);

int readInt(void)
{
    int value;

    while (1)
    {
        if (scanf("%d", &value) == 1)
        {

            while (getchar() != '\n')
            {
                
            }

            return value;
        }

        printf("Invalid input. Please enter a number: ");

        
        while (getchar() != '\n')
        {
       
        }
    }
}

double readNonNegativeDouble(void)
{
    double value;

    while (1)
    {
        if (scanf("%lf", &value) == 1)
        {
           
            while (getchar() != '\n')
            {
                
            }

            if (value >= 0)
            {
                return value;
            }

            printf("Invalid input. Please enter a non-negative number: ");
        }
        else
        {
            printf("Invalid input. Please enter a number: ");

            while (getchar() != '\n')
            {
               
            }
        }
    }
}

void readNonEmptyString(char *text, int size)
{
    while (1)
    {
        if (fgets(text, size, stdin) != NULL)
        {
            
            text[strcspn(text, "\n")] = '\0';

            if (strlen(text) > 0)
            {
                return;
            }
        }

        printf("Input cannot be empty. Please try again: ");
    }
}

void displayMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("==========================================\n");
    printf("Enter your choice: ");
}
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n");
        printf("=============================\n");
        printf("      ASSET MANAGEMENT\n");
        printf("=============================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("=============================\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please select 1-4.\n");
        }

    } while (choice != 4);
}
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n");
        printf("=============================\n");
        printf("     EMPLOYEE MANAGEMENT\n");
        printf("=============================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Display Salary\n");
        printf("5. Return to Main Menu\n");
        printf("=============================\n");
        printf("Enter your choice: ");

        choice = readInt();

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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please select 1-5.\n");
        }

    } while (choice != 5);
}

int main(void)
{
    int choice;

    do
    {
        displayMenu();

        
        choice = readInt();

        switch (choice)
        {
           case 1:
          employeeMenu();
           break;

            case 2:
           budgetManagementMenu();
           break;

      case 3:
    while (1)
    {
        int supplierChoice;

        printf("\n=============================\n");
        printf("     SUPPLIER MANAGEMENT\n");
        printf("=============================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Return to Main Menu\n");
        printf("=============================\n");

        printf("Enter your choice: ");
        scanf("%d", &supplierChoice);

        switch (supplierChoice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice. Please select 1-4.\n");
        }

        if (supplierChoice == 4)
        {
            break;
        }
    }
    break;
            
            case 4:
                assetMenu();
                break;

            case 5:
                printf("Reports selected.\n");
                break;

            case 6:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice. Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}