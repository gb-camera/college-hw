// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256

// User instructions
const char *info[] = {
  "Enter a command:",
  "",
  "  ?  - print this list of commands",
  "  r  - read monster database (binary file)",
  "  w  - write monster database (binary file)",
  "  d  - display monsters",
  "  n  - sort monsters by name (ascending)",
  "  h  - sort monsters by hitpoints (descending)",
  "  q  - quit",
};
const int N_INFO = 9;


// -----------------------------------------------------------------------
// Structs

typedef struct Weapon_struct {
    char name[NAME_MAX];
    int damageModifier;
} Weapon;

typedef struct Stats_struct {
    int agility;
    int toughness;
    int hitpoints;
} Stats;

typedef struct Monster_struct {
    char name[NAME_MAX];
    Stats stats;
    Weapon weapon;
} Monster;

typedef struct MonsterList_struct {
    int size;
    Monster *list; //pointer of type Monster called list
} MonsterList;


// -----------------------------------------------------------------------
// Function prototypes

void printInfo();
void displayMonster(Monster *m);
void displayMonsters(MonsterList *monsters);
int swapNeededName(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b);
void sortMonsters(MonsterList *monsters, char sortType);
void readDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName);

// -----------------------------------------------------------------------
// Main Program

int main() {
    MonsterList monsters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];
    char cmd;

    printInfo();

    int done = 0;
    while (!done) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {
            // TODO (1): '?' command
            case '?': {
                printInfo();
                break;
            }
            // TODO (2): 'r' command
            case 'r': {
                printf("DB file name (to read): ");
                scanf("%s", fileName);
                readDb(&monsters, fileName);
                break;
            }
            // TODO (3): 'w' command
            case 'w': {
                if(monsters.list == NULL) {
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    printf("DB file name (to write): ");
                    scanf("%s", fileName);
                    writeDb(&monsters, fileName);
                    break;
                }
            }
            // TODO (4): 'd' command
            case 'd': {
                if(monsters.list == NULL) {
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    displayMonsters(&monsters);
                    break;
                }
            }
            // TODO (5): 'n' command
            case 'n': {
                if(monsters.list == NULL) {
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    sortMonsters(&monsters, 'n');
                    displayMonsters(&monsters);
                    break;
                }
            }
            // TODO (6): 'h' command
            case 'h': {
                if(monsters.list == NULL) {
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    sortMonsters(&monsters, 'h');
                    displayMonsters(&monsters);
                    break;
                }
            }
            // TODO (7): 'q' command
            case 'q': {
                done = 1;
                break;
            }

            default:
                printf("Unknown command `%c`", cmd);
                break;
        }
    }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

// TODO (8): void printInfo();
void printInfo() {
    printf("\n");
    for(int i = 0; i < N_INFO; i++) {
        printf("%s\n", info[i]);
    }
}
// TODO (9): void displayMonster(Monster *m);
void displayMonster(Monster *m) {
    printf("%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n", m->name, m->stats.agility, m->stats.toughness, m->stats.hitpoints, m->weapon.name, m->weapon.damageModifier);
}
// TODO (10): void displayMonsters(MonsterList *monsters);
void displayMonsters(MonsterList *monsters) {
    for(size_t i = 0; i < monsters->size; i++) {
        displayMonster(&monsters->list[i]);
    }
}
// TODO (11): int swapNeededName(Monster *a, Monster *b);
int swapNeededName(Monster *a, Monster *b) {
    if(strcmp(a->name, b->name) > 0) {
        return 1;
    }
    else {
        return 0;
    }
}
// TODO (12): int swapNeededHitPoints(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b) {
    if(a->stats.hitpoints < b->stats.hitpoints) {
        return 1;
    }
    else {
        return 0;
    }
}
// TODO (13): void sortMonsters(MonsterList *monsters, char sortType);
void sortMonsters(MonsterList *monsters, char sortType) {
    int i = 0, j = 0;
    Monster temp;
    for(i = 1; i < monsters->size; ++i) {
        j = i;
        if(sortType == 'n') {
            while (j > 0 && swapNeededName(&monsters->list[j], &monsters->list[j - 1]) == 0) {
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                --j;
            }
        }
        if(sortType == 'h') {
            while (j > 0 && swapNeededHitPoints(&monsters->list[j], &monsters->list[j - 1]) == 0) {
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                --j;
            }
        }
    }
    return;
}
// TODO (14): void readDb(MonsterList *monsters, char *fileName);
void readDb(MonsterList *monsters, char *fileName) {
    FILE* input = fopen(fileName, "rb");
    if(input == NULL) {
        printf("Failed to open '%s' for read\n", fileName);
        return;
    }
    if(monsters->size != 0) {
        free(monsters->list);
    }
    int numRead = fread(&monsters->size, sizeof(int), 1, input);
    printf("%d items read from '%s' (size header)\n", numRead, fileName);
    printf("Allocating heap for %d Monsters...", monsters->size);
    monsters->list = (Monster*)malloc(monsters->size * sizeof(Monster));
    if (monsters->list == NULL) {
        printf("failed to allocate memory!\n");
        return;
    }
    else {
        printf("memory allocated\n");
    }
    numRead = 0;
    for(int i = 0; i < monsters->size; i++) {
        fread(&monsters->list[i], sizeof(Monster), 1, input);
        numRead++;
    }
    printf("%d items read from '%s' (monster array)\n", numRead, fileName);
    fclose(input);
}
// TODO (15): void writeDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName) {
    FILE* output = fopen(fileName, "wb");
    if (output == NULL) {
        printf("Failed to open '%s' for write\n", fileName);
        return;
    }
    int numWrote = fwrite(&monsters->size, sizeof(int), 1, output);
    printf("%d items written to '%s' (size header)\n", numWrote, fileName);
    numWrote = 0;
    for(int i = 0; i < monsters->size; i++) {
        fwrite(&monsters->list[i], sizeof(Monster), 1, output);
        numWrote++;
    }
    printf("%d items written to '%s' (monster array)\n", numWrote, fileName);
    fclose(output);
}

// -----------------------------------------------------------------------
