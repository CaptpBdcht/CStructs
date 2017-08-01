#include "includes.h"

void linked_list_run_tests() {
    printHeader("linked_list");
    
    
    int success = 0;
    printTestTitle("#al_create");
    int capacity = 3;
    array_list *list = al_create(capacity);
    cs_assert(list != NULL, "should return an allocated list", &success);
    if (success == 1) printf("passing");
    printf("\n");

    printf("\n");
}