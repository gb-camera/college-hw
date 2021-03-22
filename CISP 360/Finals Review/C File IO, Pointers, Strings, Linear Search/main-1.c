#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 128

typedef struct Account_ {
    char name[MAX_STRING];
    double balance;
} Account;

typedef struct Accounts_ {
    int size;
    Account* accountList;
} Accounts;

void readAccountsText(Accounts* accounts, const char* fileName) {
    FILE* inFile = fopen(fileName, "r");
    if(!inFile) {
        printf("failed to open %s", fileName);
        return;
    }
    fscanf(inFile, "%d", &accounts->size);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    for(int i = 0; i < accounts->size; i++) {
        fscanf(inFile, "%s %lf", accounts->accountList[i].name, &accounts->accountList[i].balance);
    }
    fclose(inFile);
}

void readAccountsBinary(Accounts* accounts, const char* fileName) {
    FILE* inFile = fopen(fileName, "rb");
    if(!inFile) {
        printf("failed to open %s", fileName);
        return;
    }
    fread(&accounts->size, sizeof(int), 1, inFile);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    fread(accounts->accountList, sizeof(Account), accounts->size, inFile);
    fclose(inFile);
}

void writeAccountsBinary(Accounts* accounts, const char* fileName) {
    FILE* outFile = fopen(fileName, "wb");
    if(!outFile) {
        printf("failed to open %s", fileName);
        return;
    }
    fwrite(&accounts->size, sizeof(int), 1, outFile);
    fwrite(accounts->accountList, sizeof(Account), accounts->size, outFile);
    fclose(outFile);
}

void writeAccountsText(Accounts* accounts, const char* fileName) {
    FILE* outFile = fopen(fileName, "w");
    if(!outFile) {
        printf("failed to open %s", fileName);
        return;
    }
    fprintf(outFile, "%d\n", accounts->size);
    for(int i = 0; i < accounts->size; i++) {
        fprintf(outFile, "%s %lf\n", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
    fclose(outFile);
}

void printAccounts(Accounts* accounts) {
    for(int i = 0; i < accounts->size; i++) {
        printf("%s $%.2lf\n", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
}

void printUser(Accounts* accounts, const char* name) {
    int found = 0;
    for(int i = 0; i < accounts->size; i++) {
        if(strcmp(name, accounts->accountList[i].name) == 0) {
            printf("Found!\n");
            printf("$%.2lf\n", accounts->accountList[i].balance);
            found = 1;
        }
    }
    if(!found) {
        printf("Not found\n");
    }
}

int main() {
    Accounts* accounts = (Accounts*)malloc(sizeof(Accounts));
    readAccountsText(accounts, "Accounts.txt");
    printAccounts(accounts);
    writeAccountsText(accounts, "Accounts2.txt");
    free(accounts->accountList);
    readAccountsText(accounts, "Accounts2.txt");
    printAccounts(accounts);
    writeAccountsBinary(accounts, "Accounts.bin");
    free(accounts->accountList);
    readAccountsBinary(accounts, "Accounts.bin");
    printAccounts(accounts);
    printUser(accounts, "FiftyCent");
    printUser(accounts, "NoOne");
    return 0;
}
