#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 128

typedef struct Account_t {
    char* name[MAX_STRING];
    double balance;
} Account;

typedef struct Accounts_t {
    int size;
    Account* accountList;
} Accounts;

void readAccountsText(Accounts* accounts, const char* fileNameTxt) {
    FILE* in = fopen(fileNameTxt, "r");
    if(in == NULL) {
        printf("Error opening text file for input...\n");
        return;
    }
    if(accounts->accountList != NULL) {
        free(accounts->accountList);
    }
    fscanf(in, "%d", &accounts->size);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    for(size_t i = 0; i < accounts->size; i++) {
        fscanf(in, "%s %lf", accounts->accountList[i].name, &accounts->accountList[i].balance);
    }
    fclose(in);
}

void readAccountsBinary(Accounts* accounts, const char* fileNameBin) {
    FILE* in = fopen(fileNameBin, "rb");
    if(in == NULL) {
        printf("Error opening binary file for input...\n");
        return;
    }
    if(accounts->accountList != NULL) {
        free(accounts->accountList);
    }
    fread(&accounts->size, sizeof(int), 1, in);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    fread(accounts->accountList, sizeof(Account), accounts->size, in);
    fclose(in);
}

void writeAccountsText(Accounts* accounts, const char* fileNameTxt) {
    FILE* out = fopen(fileNameTxt, "w");
    if(out == NULL) {
        printf("Error opening text file for output...\n");
        return;
    }
    fprintf(out, "%d\n", accounts->size);
    for(size_t i = 0; i < accounts->size; i++) {
        fprintf(out, "%s %lf\n", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
    fclose(out);
}

void writeAccountsBinary(Accounts* accounts, const char* fileNameBin) {
    FILE* out = fopen(fileNameBin, "wb");
    if(out == NULL) {
        printf("Error opening binary file for output...\n");
        return;
    }
    fwrite(&accounts->size, sizeof(int), 1, out);
    fwrite(accounts->accountList, sizeof(Account), accounts->size, out);
    fclose(out);
}

void printAccounts(Accounts* accounts) {
    for(size_t i = 0; i < accounts->size; i++) {
        printf("%s $%.2lf\n", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
}

void printUser(Accounts* accounts, const char* name) {
    int found = 0;
    for(size_t i = 0; i < accounts->size; i++) {
        if(strcmp(name, accounts->accountList[i].name) == 0) {
            fprint("Match found!\n");
            fprint("Account balance for %s is $%.2lf\n", name, accounts->accountList[i].balance);
            found = 1;
        }
    }
    if(!found) {
        printf("User not found.\n");
    }
}

int main() {
    char* fileNameTxt[] = "Accounts.txt";
    char* fileNameBin[] = "Accounts.bin";
    Accounts* accounts = (Accounts*)malloc(sizeof(Accounts));
    accounts->accountList = NULL;
    readAccountsText(accounts, fileNameTxt);
    printAccounts(accounts);
    writeAccountsText(accounts, "Accounts2.txt");
    readAccountsText(accounts, "Accounts2.txt");
    printAccounts(accounts);
    writeAccountsBinary(accounts, fileNameBin);
    readAccountsBinary(accounts, fileNameBin);
    printAccounts(accounts);
    printUser(accounts, "FiftyCent");
    printUser(accounts, "NoOne");
}