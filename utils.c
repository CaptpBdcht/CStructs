#include <stdio.h>

#include "utils.h"

void printInts(int *data, int size) {
    int i = -1;
    while (++i < size)
        printf("%d ", data[i]);
    printf("\n");
}