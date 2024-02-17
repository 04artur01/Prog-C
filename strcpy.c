#include <stdio.h>

char* strcpyMy(char* destination, const char* source) {
    if (destination == NULL || source == NULL) {
        return NULL;
    }
    char* ptr = destination;
    while ((*destination = *source) != '\0') {
        ++destination;
        ++source;
    }
    return ptr;
}

int main(void) {
    char source[] = "Techie Delight";
    char destination[25];
    printf("%s\n", strcpyMy(destination, source));
    return 0;
}
