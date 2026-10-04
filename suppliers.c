#include <stdio.h>
#include <string.h>
#include "suppliers.h"

#define MAX_SUPPLIERS 100

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;


void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    printf("Enter Supplier ID: ");
    scanf("%19s", suppliers[supplierCount].id);

    /* Check for duplicate ID */
    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].id,
                   suppliers[supplierCount].id) == 0)
        {
            printf("Supplier ID already exists.\n");
            return;
        }
    }

    /* Clear leftover newline */
    getchar();

    printf("Enter Supplier Name: ");
    fgets(suppliers[supplierCount].name,
          sizeof(suppliers[supplierCount].name),
          stdin);

    suppliers[supplierCount].name[
        strcspn(suppliers[supplierCount].name, "\n")
    ] = '\0';


    printf("Enter Supplier Email: ");
    scanf("%49s", suppliers[supplierCount].email);

    printf("Enter Telephone: ");
    scanf("%19s", suppliers[supplierCount].telephone);

    /* Clear leftover newline */
    getchar();

    printf("Enter Town/Location: ");
    fgets(suppliers[supplierCount].town,
          sizeof(suppliers[supplierCount].town),
          stdin);

    suppliers[supplierCount].town[
        strcspn(suppliers[supplierCount].town, "\n")
    ] = '\0';


    supplierCount++;

    printf("Supplier added successfully.\n");
}


void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n--- Supplier List ---\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %s\n",
               suppliers[i].id);

        printf("Name: %s\n",
               suppliers[i].name);

        printf("Email: %s\n",
               suppliers[i].email);

        printf("Telephone: %s\n",
               suppliers[i].telephone);

        printf("Town/Location: %s\n",
               suppliers[i].town);
    }

    printf("\nTotal suppliers: %d\n",
           supplierCount);
}


void searchSupplier(void)
{
    char searchKey[80];
    int found = 0;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    printf("\nEnter Supplier ID or Name to search: ");

    getchar();

    fgets(searchKey, sizeof(searchKey), stdin);

    searchKey[strcspn(searchKey, "\n")] = '\0';


    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].id, searchKey) == 0 ||
            strcmp(suppliers[i].name, searchKey) == 0)
        {
            printf("\nSupplier Found!\n");

            printf("Supplier ID: %s\n",
                   suppliers[i].id);

            printf("Name: %s\n",
                   suppliers[i].name);

            printf("Email: %s\n",
                   suppliers[i].email);

            printf("Telephone: %s\n",
                   suppliers[i].telephone);

            printf("Town/Location: %s\n",
                   suppliers[i].town);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}