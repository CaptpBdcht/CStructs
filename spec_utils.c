#include "includes.h"

void cs_assert(int expression, char *message, int *success) {
    if (!expression) printf("\n\t...%s KO", message);
    else (*success)++;
}

void printNChars(char symbol, int times, int endl) {
    while (times--) printf("%c", symbol);
    if (endl) printf("\n");
}

void printHeader(char * title) {
    if (!title)
        return;
    int len = strlen(title);
    printNChars('*', 8 + len + 8, TRUE);
    printf("\tSpec Suite\n");
    printf("\t%s\n", title);
    printNChars('*', 8 + len + 8, TRUE);
}