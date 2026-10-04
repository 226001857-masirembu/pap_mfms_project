#ifndef SUPPLIERS_H
#define SUPPLIERS_H

typedef struct {
    char id[20];
    char name[50];
    char email[50];
    char telephone[20];
    char town[80];
} Supplier;

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

#endif
