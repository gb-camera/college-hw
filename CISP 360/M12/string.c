#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str) {
    const char *comp = str;
    while(*comp != '\0') {
        comp++;
    }
    return (size_t)(comp - str);
}
int strcmp(const char* str1, const char* str2) {
    while(*str1) {
        if(*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}
int strncmp(const char* str1, const char* str2, size_t n) {
    while(n && *str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
        --n;
    }
    if(n == 0) {
        return 0;
    }
    else {
        return(*(unsigned char*)str1 - *(unsigned char*)str2);
    }
}
char* strcpy(char* dest, const char* src) {
    if(dest == NULL) {
        return NULL;
    }
    char *temp = dest;
    while(*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return temp;
}
char* strncpy(char* dest, const char* src, size_t n) {
    if(dest == NULL) {
        return NULL;
    }
    char *temp = dest;  
    while (*src != '\0' && n > 0) {
        *dest++ = *src++;
        n--;
    }
    //*dest = '\0';
    return temp;
}
char* strcat(char* dest, const char* src) {
    int i, j;
    for(i = 0; dest[i] != '\0'; i++);
    for(j = 0; src[j] != '\0'; j++) {
        dest[i+j] = src[j];
    }  
    dest[i+j] = '\0';
    return dest;
}
char* strncat(char* dest, const char* src, size_t n) {
    int i, j;
    for(i = 0; dest[i] != '\0'; i++);
    for(j = 0; src[j] != '\0' && j < n; j++) {
        dest[i+j] = src[j];
    }
    dest[i+j] = '\0';
    return dest;
}
const char* strchr(const char* str, int c) {
    for(;;str++) {
        if(*str == c) {
            return (char*)str;
        }
        if(*str == '\0') {
            return NULL;
        }
    }
}
const char* strrchr(const char* str, int c) {
    const char* temp = NULL;
    do {
        if(*str == c) {
            temp = str;
        }
    } while (*str++);
    return (char*)temp;
}

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
 /// Loop thru str1, looking for the first char of str2
 /// if(str1[i] == str2[0]) Then start inner loop, j=0
 /// loop while str1[i+j] is not null and str2[j] is not null
 /// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
 /// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
 /// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2) {
    size_t str2_len = strlen(str2);
    while(*str1) {
        if(*str1 == *str2) {
            if(!strncmp(str2, str2, str2_len)) {
                return((char*)str1);
            }
        }
        str1++;
    }
    return NULL;
}

int isalnum(int c) {
    return isalpha(c) || isdigit(c);
}

int main(void) {
    char str1[] = "Robert";
    char str2[] = "Copa";
    printf("%s", strncat(str1, str2, 3));
}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description