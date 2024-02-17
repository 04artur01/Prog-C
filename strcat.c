#include <stdio.h>

char* strcatMy(char* destination, const char* source) {
    if (destination == NULL || source == NULL) {
        return NULL;
    }
    char* ptr = destination;
    while (*destination != '\0') {
        ++destination;
    }
    while ((*destination = *source) != '\0') {
        ++destination;
        ++source;
    }
    return ptr;
}

int main(void) {
    char destination[50] = "Hello, ";
    char source[] = "world!";
    strcatMy(destination, source);
    printf("%s\n", destination);
    return 0;
}
