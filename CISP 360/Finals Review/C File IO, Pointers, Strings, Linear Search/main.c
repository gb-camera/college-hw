#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Initial structs
typedef struct Account_t {
    char* name[128];
    double balance;
} Account;
typedef struct Accounts_t {
    int size;
    Account* accountList;
} Accounts;
//.txt I/O functions
void readAccountsText(Accounts* accounts, const char* fileNameTxt) {
    FILE* in = fopen(fileNameTxt, "r");
    if(in == NULL) {
        printf("Error opening file for read...\n");
        return;
    }
    if(accounts->size != 0) {
        free(accounts->accountList);
    }
    fscanf(in, "%d", accounts->size);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    for(size_t i = 0; i < accounts->size; i++) {
        fscanf(in,"%s %d", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
    fclose(in);
}
void writeAccountsText(Accounts* accounts, const char* fileNameTxt) {
    FILE* out = fopen(fileNameTxt, "w");
    if(out == NULL) {
        printf("Error opening file for write...\n");
        return;
    }
    fprintf(out, "%d\n", accounts->size);
    for(size_t i = 0; i < accounts->size; i++) {
        fprintf(out, "%s %d\n", accounts->accountList[i].name, accounts->accountList[i].balance);
    }
}
//.bin I/O functions
void readAccountsBinary(Accounts* accounts, const char* fileNameBin) {
    FILE* in = fopen(fileNameBin, "rb");
    if(in == NULL) {
        printf("Error opening file for read...\n");
        return;
    }
    if(accounts->size != 0) {
        free(accounts->accountList);
    }
    fread(accounts->size, sizeof(int), 1, in);
    accounts->accountList = (Account*)malloc(sizeof(Account) * accounts->size);
    for(size_t i = 0; i < accounts->size; i++) {
        fread(accounts->accountList[i], sizeof(Account), 1, in);
    }
}

int main() {
    char* fileNameTxt[] = "Accounts.txt";
    char* fileNameBin[] = "Accounts.bin";
}