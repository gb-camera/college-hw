#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shiftStr(char str[], int shift);
void encipher(FILE* inFile, FILE* outFile, int key);
int validFileSuffix(char str[]);

const int BUFFER_SIZE = 2048;

int main()
{
    char inName[BUFFER_SIZE];
    
    ///TODO(0):  Declare strings for outName and outPrefix
    char outName[BUFFER_SIZE], outPrefix[BUFFER_SIZE];

    int key;

    
    ///TODO(1):  Prompt and read file name
    printf("Read file name (*.txt): ");
    scanf("%s", inName);
    
    ///TODO(2):  Validate file name
    while(validFileSuffix(inName) != 1) {
        ///Error message and prompt / read again
        printf("Error. *.txt required.\n");
        printf("Read file name (*.txt): ");
        scanf("%s", inName);
    }

    ///TODO(3):  Open read file
    FILE* inFile = fopen(inName, "r");
    ///TODO(4):  If the input file is NULL, error and exit program
    if(inFile == NULL) {
        printf("Error: Failed to open %s", inName);
        return 0;
    }
    ///TODO(5):  Prompt and read output file prefix
    printf("Output file prefix: ");
    scanf("%s", outPrefix);
    ///TODO(6):  Copy prefix to output file string, concatenate input file name
    strncpy(outName, outPrefix, strlen(outPrefix));
    strcat(outName, inName);
    ///TODO(7):  Open output file.  If it fails, exit the program.
    FILE* outFile = fopen(outName, "w");
    ///TODO(8):  Prompt and read the key.  Don't forget the & for the int on scanf!!
    printf("Key: ");
    scanf("%d", &key);
    printf("Encrypting...\n");
    encipher(inFile, outFile, key);
    printf("Complete.\n");
}

///TODO(9):  validFileSuffix
int validFileSuffix(char str[]) {
    ///From https://stackoverflow.com/questions/5309471/getting-file-extension-in-c
    if(strrchr(str, '.') == NULL) {
        return 0;
    }
    char ext[BUFFER_SIZE];
    strcpy(ext, strrchr(str, '.'));
    if(strcmp(ext, ".txt") != 0) {
        return 0;
    }
    else {
        return 1;
    }
}

///TODO(10):  encipher
///declare a string of size BUFFER_SIZE
///using fgets, read while it does not return NULL
///call shiftStr to shift the buffer
///use fprintf to output the string to the output file
void encipher(FILE* inFile, FILE* outFile, int key) {
    char string[BUFFER_SIZE];
    while(fgets(string, '\n', inFile) != NULL) {
        shiftStr(string, key);
        fprintf(outFile, "%s", string);
    }
}

///TODO(11):  shiftStr
///Mod the shift with 26
///loop through each char
///only process if isalpha is nonzero
///if lowercase and char + shift > 'z' OR uppercase and char + shift > 'Z', subtract 26 from shift
///else if lowercase and char + shift < 'a' OR uppercase and char + shift < 'A', add 26 to shift
///add shift to the char, continue loop
void shiftStr(char str[], int shift) {
    shift = shift % 26;
    for(size_t i = 0; i < strlen(str); i++) {
        if(isalpha(str[i]) != 0) {
            if(islower(str[i]) != 0) {
                if((str[i] + shift) > 'z') {
                    shift = shift - 26;
                }
                if((str[i] + shift) < 'a') {
                    shift = shift + 26;
                }
            }
            else if(isupper(str[i]) != 0) {
                if((str[i] + shift) > 'Z') {
                    shift = shift - 26;
                }
                if((str[i] + shift) < 'A') {
                    shift = shift + 26;
                }
            }
            str[i] += shift;
        }
        else {
            continue;
        }
    }
}