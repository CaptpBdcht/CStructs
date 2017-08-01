#include "includes.h"

void test_al_create() {
    int success = 0;
    printTestTitle("#al_create");
    int capacity = 3;

    array_list *list = al_create(capacity);
    cs_assert(list != NULL, "should return an allocated list", &success);
    cs_assert(list->size == 0, "should return an empty list", &success);
    cs_assert(list->capacity == capacity, "should return a list of given capacity", &success);
    al_free(&list);

    if (success == 3) printf("passing");
    printf("\n");
}

void test_al_free() {
    int success = 0;
    printTestTitle("#al_free");
    int capacity = 42;
    array_list *list = al_create(capacity);

    al_free(&list);
    cs_assert(list == NULL, "should free the list correctly", &success);

    if (success == 1) printf("passing");
    printf("\n");
}

void test_al_append() {
    int success = 0;
    printTestTitle("#al_append");
    int capacity = 2;
    array_list *list = NULL;

    al_append(list, 1);
    cs_assert(list == NULL, "shouldn't process NULL", &success);
    list = al_create(capacity);
    al_append(list, 1);
    cs_assert(list->data[0] == 1 && list->size == 1, "should work on empty lists", &success);
    al_append(list, 2);
    cs_assert(list->data[1] == 2 && list->size == 2, "should work on non-empty lists", &success);
    al_append(list, 3);
    cs_assert(list->size == 2, "should not work if list is full", &success);
    al_free(&list);

    if (success == 4) printf("passing");
    printf("\n");
}

void test_al_insert_base() {
    int success = 0;
    printTestTitle("#al_insert_base");
    int capacity = 5;
    array_list *list = al_create(capacity);
    al_append(list, 0);
    al_append(list, 1);
    al_append(list, 2);

    al_insert_base(list, 150, 42);
    cs_assert(list->size == 3, "should not insert out of bounds", &success);
    al_insert_base(list, 0, 42);
    cs_assert(list->data[0] == 42 && list->size == 4, "should insert at begin", &success);
    al_insert_base(list, 4, 42);
    cs_assert(list->data[4] == 42 && list->size == 5, "should insert in list", &success);
    al_insert_base(list, 2, 42);
    cs_assert(list->capacity == capacity * 2, "should resize list if it was full", &success);
    cs_assert(list->data[2] == 42 && list->size == 6, "should insert in resized list", &success);
    al_free(&list);

    if (success == 5) printf("passing");
    printf("\n");
}

void test_al_insert() {
    int success = 0;
    printTestTitle("#al_insert");
    int capacity = 5;
    array_list *list = al_create(capacity);
    al_append(list, 0);
    al_append(list, 1);
    al_append(list, 2);

    al_insert(list, 150, 42);
    cs_assert(list->size == 3, "should not insert out of bounds", &success);
    al_insert(list, 0, 42);
    cs_assert(list->data[0] == 42 && list->size == 4, "should insert at begin", &success);
    al_insert(list, 4, 42);
    cs_assert(list->data[4] == 42 && list->size == 5, "should insert in list", &success);
    al_insert(list, 2, 42);
    cs_assert(list->capacity == capacity * 2, "should resize list if it was full", &success);
    cs_assert(list->data[2] == 42 && list->size == 6, "should insert in resized list", &success);
    al_free(&list);

    if (success == 5) printf("passing");
    printf("\n");
}

void test_al_prepend() {
    int success = 0;
    printTestTitle("#al_prepend");
    int capacity = 2;
    array_list *list = NULL;

    al_prepend(list, 1);
    cs_assert(list == NULL, "shouldn't process NULL", &success);
    list = al_create(capacity);
    al_prepend(list, 1);
    cs_assert(list->data[0] == 1 && list->size == 1, "should work on empty lists", &success);
    al_prepend(list, 2);
    cs_assert(list->data[0] == 2 && list->size == 2, "should work on non-empty lists", &success);
    al_prepend(list, 3);
    cs_assert(list->size == 3 && list->capacity == 2 * capacity,
            "should resize list if it is full", &success);
    al_free(&list);

    if (success == 4) printf("passing");
    printf("\n");
}

void test_al_index_of() {
    int success = 0;
    printTestTitle("#al_index_of");
    int capacity = 3;
    array_list *list = NULL;

    cs_assert(al_index_of(list, 1) == -1, "should return -1 if list is null", &success);
    list = al_create(capacity);
    al_append(list, 1);
    al_append(list, 10);
    al_append(list, 10);
    cs_assert(al_index_of(list, 1) == 0, "should return index if list contains value", &success);
    cs_assert(al_index_of(list, 10) == 1, "should return index of the first occurence", &success);
    cs_assert(al_index_of(list, 42) == -1, "should return -1 if value not found", &success);
    al_free(&list);

    if (success == 4) printf("passing");
    printf("\n");
}

void test_al_last_index_of() {
    int success = 0;
    printTestTitle("#al_last_index_of");
    int capacity = 3;
    array_list *list = NULL;

    cs_assert(al_last_index_of(list, 1) == -1, "should return -1 if list is null", &success);
    list = al_create(capacity);
    al_append(list, 10);
    al_append(list, 1);
    al_append(list, 10);
    cs_assert(al_last_index_of(list, 1) == 1, "should return index if list contains value", &success);
    cs_assert(al_last_index_of(list, 10) == 2, "should return index of the last occurence", &success);
    cs_assert(al_last_index_of(list, 42) == -1, "should return -1 if value not found", &success);
    al_free(&list);

    if (success == 4) printf("passing");
    printf("\n");
}

void array_list_run_tests() {
    printHeader("array_list");

    test_al_create();
    test_al_free();

    test_al_append();
    test_al_insert_base();
    test_al_insert();
    test_al_prepend();

    test_al_index_of();
    test_al_last_index_of();

    printf("\n");
}