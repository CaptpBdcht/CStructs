#include "includes.h"

void cs_assert(int expression, char *message, int *success) {
    if (!expression) printf("\n\t...%s KO", message);
    else (*success)++;
}

void printNChars(char symbol, int times, int endl) {
    while (times--) printf("%c", symbol);
    if (endl) printf("\n");
}

void printHeader(char *title) {
    if (!title)
        return;
    int len = strlen(title);
    printNChars('*', 16 + len + 16, TRUE);
    printf("\t\tSpec Suite\n");
    printf("\t\t%s\n", title);
    printNChars('*', 16 + len + 16, TRUE);
}

void printTestTitle(char *title) {
    if (!title)
        return;
    int len = strlen(title);
    printf("%s...", title);
    printNChars(' ', 30 - len, FALSE);
}