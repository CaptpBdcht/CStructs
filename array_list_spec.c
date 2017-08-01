#include "includes.h"

void test_al_create() {
    int success = 0;
    printf("#al_create... ");
    int capacity = 3;

    array_list *list = al_create(capacity);
    cs_assert(list != NULL, "should return an allocated list", &success);
    cs_assert(list->size == 0, "should return an empty list", &success);
    cs_assert(list->capacity == capacity, "should return a list of given capacity", &success);

    if (success == 3) printf("passing");
    printf("\n");
}

void test_al_append() {
    int success = 0;
    printf("#al_append... ");
    int capacity = 2;
    array_list *list = NULL;

    al_append(list, 1);
    cs_assert(list == NULL, "shouldn't process NULL", &success);
    list = al_create(capacity);
    al_append(list, 1);
    cs_assert(list->data[0] == 1, "should work on empty lists", &success);
    al_append(list, 2);
    cs_assert(list->data[1] == 2, "should work on non-empty lists", &success);
    al_append(list, 3);
    cs_assert(list->size == 2, "should not work if list is full", &success);

    if (success == 4) printf("passing");
    printf("\n");
}

void test_al_insert_base() {
    int success = 0;
    printf("#al_insert_base... ");
    int capacity = 5;
    array_list *list = al_create(capacity);
    al_append(list, 0);
    al_append(list, 1);
    al_append(list, 2);

    al_insert_base(list, 150, 42);
    cs_assert(list->size == 3, "should not insert out of bounds", &success);
    al_insert_base(list, 0, 42);
    cs_assert(list->data[0] == 42, "should insert at begin", &success);
    al_insert_base(list, 4, 42);
    cs_assert(list->data[4] == 42, "should insert in list", &success);
    al_insert_base(list, 2, 42);
    cs_assert(list->capacity == capacity * 2, "should resize list if it was full", &success);
    cs_assert(list->data[2] == 42, "should insert in resized list", &success);

    if (success == 5) printf("passing");
    printf("\n");
}

void al_run_all() {
    printHeader("array_list");

    test_al_create();
    test_al_append();
    test_al_insert_base();
}