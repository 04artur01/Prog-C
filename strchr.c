#include <stdio.h>

char* strchrMy(const char* str, char target) {
    if (str == NULL) {
        return NULL;
    }
    while (*str != '\0') {
        if (*str == target) {
            return (char*)str;
        }
        ++str;
    }
    return NULL;
}

int main(void) {
    char text[] = "Hello, world!";
    char target = 'o';
    char* result = strchrMy(text, target);
    if (result != NULL) {
        printf("Found '%c' at position %ld\n", target, result - text);
    } else {
        printf("'%c' not found in the string\n", target);
    }
    return 0;
}
