#include <stdio.h>

size_t strlenMy(const char* str) {
    if (str == NULL) {
        return 0;
    }
    size_t length = 0;
    while (*str != '\0') {
        ++length;
        ++str;
    }
    return length;
}

int main(void) {
    char text[] = "Hello, world!";
    printf("Length of the string: %zu\n", strlenMy(text));
    return 0;
}
