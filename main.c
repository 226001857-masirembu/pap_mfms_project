#include <stdio.h>
#include <string.h>
#include "assets.h"

int readInt(void);
double readNonNegativeDouble(void);
void readNonEmptyString(char *text, int size);
void assetMenu(void);

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
                printf("Employee Management selected.\n");
                break;

            case 2:
                printf("Budget Management selected.\n");
                break;

            case 3:
                printf("Supplier Management selected.\n");
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