#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int id;
    char name[100];
    char type[80];
    double purchaseValue;
    char department[100];
    char condition[50];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void addAsset(void);
void displayAssets(void);
void searchAsset(void);

#endif