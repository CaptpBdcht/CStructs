#include "includes.h"

int maxInt(int a, int b) {
    return a > b ? a : b;
}

void permuteInt(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}