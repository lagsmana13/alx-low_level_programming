#include <stdio.h>
#include <ctype.h>
#include "main.h"

void print_buffer(char *b, int size) {
    if (size <= 0) {
        printf("\n");
        return;
    }

    int i, j;
    for (i = 0; i < size; i += 10) {
        printf("%08x ", i);

        for (j = i; j < i + 10; j += 2) {
            if (j < size) {
                printf("%02x", (unsigned char)b[j]);

                if (j + 1 < size) {
                    printf("%02x ", (unsigned char)b[j + 1]);
                } else {
                    printf("   ");
                }
            } else {
                printf("     ");
            }
        }

        for (j = i; j < i + 10; j++) {
            if (j < size) {
                printf("%c", isprint(b[j]) ? b[j] : '.');
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main(void) {
    char buffer[] = "Hello, World! This is a buffer.";
    int size = sizeof(buffer) - 1;  // Exclude null terminator

    print_buffer(buffer, size);

    return 0;
}
