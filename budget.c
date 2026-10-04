#include <stdio.h>
#include <string.h>
#include "assets.h"

#define MAX_ASSETS 100

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(void)
 {

    if (assetCount >= MAX_ASSETS)
     {
        printf("Asset limit reached. Cannot add more assets.\n");
        return;
 }
printf("--- Add Asset ---\n");
printf("Enter Asset ID: ");
scanf("%d", &assets[assetCount].id);
getchar();

 printf("Enter Asset Name: ");
    fgets(assets[assetCount].name, 100, stdin);
    assets[assetCount].name[strcspn(assets[assetCount].name, "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].type, 80, stdin);
    assets[assetCount].type[strcspn(assets[assetCount].type, "\n")] = '\0';

    printf("Enter Purchase Value: ");
    scanf("%lf", &assets[assetCount].purchaseValue);
    getchar();

    if (assets[assetCount].purchaseValue < 0)
    {
        printf("Purchase value cannot be negative.\n");
        return;
    }

    printf("Enter Department: ");
    fgets(assets[assetCount].department, 100, stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assets[assetCount].condition, 50, stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';

    assetCount++;

    printf("Asset added successfully!\n");
}

void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

void searchAsset(void)
{
    int searchId;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < assetCount; i++)
    {
        if (assets[i].id == searchId)
        {
            printf("\nAsset Found!\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}
