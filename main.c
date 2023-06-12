#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bw_transform.h"

int main(int argc, char *argv[]) {
    char *word = "test";
    char *transformed = bw_transform(word);
    char *inv_transformed = bw_inverse(transformed);
    printf("Original:            %s\n", word);
    printf("Transformed:         %s\n", transformed);
    printf("Inverse Transformed: %s\n", inv_transformed);

    return 0;
}
