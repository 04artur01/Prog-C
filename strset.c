#include <stdio.h>

char* strsetMy(char* str, char fillChar) {
    if (str == NULL) {
        return NULL;
    }
    char* ptr = str;
    while (*str != '\0') {
        *str = fillChar;
        ++str;
    }
    return ptr;
}

int main(void) {
    char buffer[10];
    char fillChar = '*';
    printf("Filled string: %s\n", strsetMy(buffer, fillChar));
    return 0;
}
