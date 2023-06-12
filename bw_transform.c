#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bw_transform.h"

#define DEBUG

// TODO: Write the program
// TODO: I don't think I need both start and end characters

char *bw_transform(char *s) {
    int length = strlen(s) + 2;
    // This number will be used to make sure there's extra space for the null character
    // as well as giving us an extra row for swapping strings
    int length_plus1 = length + 1;
    int table_size = length_plus1 * length;
    char *table = malloc(sizeof(char) * table_size);

    strcpy(table + 1, s);

    // Adding a special start and end character
    table[0]          = '\x02';
    table[length - 1] = '\x03';
    table[length]     = '\0';

    for (int i = 0; i < length - 1;) {
        char *prev = table + length_plus1 * i++;
        strcpy(table + length_plus1 * i + 1, prev);
        table[length_plus1 * i] = table[length_plus1 * i + length];
        table[length_plus1 * i + length] = '\0';
    }

    #ifdef DEBUG
    printf("Table:\n");
    for (int i = 0; i < table_size; i++) {
        char item = table[i];
        if (item == '\0') {
            printf("\\0\n");
            continue;
        }
        if (item < 48) {
            printf("x%i\t", item);
            continue;
        }
        printf("%c\t", item);
    }
    printf("\n");
    #endif

    // TODO: consider sorting pointers to strings instead of strings
    qsort(table, length, sizeof(char) * length_plus1, (int (* _Nonnull)(const void *, const void *))strcmp);

    #ifdef DEBUG
    printf("Sorted Table:\n");
    for (int i = 0; i < table_size; i++) {
        char item = table[i];
        if (item == '\0') {
            printf("\\0\n");
            continue;
        }
        if (item < 48) {
            printf("x%i\t", item);
            continue;
        }
        printf("%c\t", item);
    }
    printf("\n");
    #endif

}

char *bw_inverse(char *s) {
    // TODO: Consider wacky bitshift string rotation

}
