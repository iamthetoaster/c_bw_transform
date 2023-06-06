#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bw_transform.h"

#define DEBUG

// TODO: Write the program

char *bw_transform(char *s) {
    int length = strlen(s) + 2;
    // This number will be used to make sure there's extra space for the null character
    // as well as giving us an extra row for swapping strings
    int length_plus1 = length + 1;
    int table_size = length_plus1 * length_plus1;
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
    #endif
}

char *bw_inverse(char *s) {
    // TODO: Consider wacky bitshift string rotation

}
