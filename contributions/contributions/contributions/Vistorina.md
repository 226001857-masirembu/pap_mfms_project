#include <stdio.h>
#include <string.h>

#define MAX 100

struct Supplier {
    char id[20];
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
};

struct Supplier list[MAX];
int count = 0;

void addSupplier(){
    if(count >= MAX){
        printf("Storage full!\n");
        return;
    }

    printf("\nEnter Supplier ID: ");
    scanf("%s", list[count].id);

    for(int i=0; i<count; i++){
        if(strcmp(list[i].id, list[count].id)==0){
            printf("ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", list[count].name);
    printf("Enter Email: ");
    scanf("%s", list[count].email);
    printf("Enter Telephone: ");
    scanf("%s", list[count].phone);
    printf("Enter Town: ");
    scanf(" %[^\n]", list[count].town);

    count++;
    printf("Supplier added.\n");
}

void display(){
    if(count==0){
        printf("\nNo suppliers yet.\n");
        return;
    }
    printf("\n--- Supplier List ---\n");
    for(int i=0; i<count; i++){
        printf("%s | %s | %s | %s | %s\n", list[i].id, list[i].name, list[i].email, list[i].phone, list[i].town);
    }
    printf("Total: %d\n", count);
}

void search(){
    char key[50];
    printf("\nEnter ID or Name or Town to search: ");
    scanf(" %[^\n]", key);

    int found = 0;
    for(int i=0; i<count; i++){
        if(strstr(list[i].id, key) != NULL || strstr(list[i].name, key) != NULL || strstr(list[i].town, key) != NULL){
            printf("Found: %s | %s | %s | %s | %s\n", list[i].id, list[i].name, list[i].email, list[i].phone, list[i].town);
            found = 1;
        }
    }
    if(found==0) printf("Not found.\n");
}

void compare(){
    char id1[20], id2[20];
    printf("\nEnter first Supplier ID: ");
    scanf("%s", id1);
    printf("Enter second Supplier ID: ");
    scanf("%s", id2);

    int a = -1, b = -1;
    for(int i=0; i<count; i++){
        if(strcmp(list[i].id, id1)==0) a = i;
        if(strcmp(list[i].id, id2)==0) b = i;
    }

    if(a==-1 || b==-1){
        printf("One ID not found.\n");
        return;
    }

    printf("\n--- Comparison ---\n");
    printf("ID: %s vs %s\n", list[a].id, list[b].id);
    printf("Name: %s vs %s\n", list[a].name, list[b].name);
    printf("Email: %s vs %s\n", list[a].email, list[b].email);
    printf("Phone: %s vs %s\n", list[a].phone, list[b].phone);
    printf("Town: %s vs %s\n", list[a].town, list[b].town);

    if(strcmp(list[a].town, list[b].town)==0)
        printf("Both from same town: %s\n", list[a].town);
    else
        printf("Different towns.\n");
}

int main(){
    strcpy(list[0].id, "SUP001");
    strcpy(list[0].name, "Windhoek Builders");
    strcpy(list[0].email, "info@gmail.com");
    strcpy(list[0].phone, "061123456");
    strcpy(list[0].town, "Windhoek");

    strcpy(list[1].id, "SUP002");
    strcpy(list[1].name, "Swakop Supplies");
    strcpy(list[1].email, "swakop@gmail.com");
    strcpy(list[1].phone, "064987654");
    strcpy(list[1].town, "Swakopmund");

    count = 2;

    int choice;
    while(1){
        printf("\n==== Supplier Management ====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if(choice==1) addSupplier();
        else if(choice==2) display();
        else if(choice==3) search();
        else if(choice==4) compare();
        else if(choice==5){
            printf("Exiting...\n");
            break;
        }
        else printf("Invalid choice.\n");
    }
    return 0;
}
