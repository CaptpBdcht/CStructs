#include <stdlib.h>
#include <stdio.h>

#include "array_list.h"
#include "utils.h"

void test() {
    printf("Hello from array_list!\n");
    array_list *list = malloc(sizeof *list);
    list->capacity = 100;
    list->size = 3;
    list->data = malloc(sizeof *list->data * list->size);
    list->data[0] = 42;
    list->data[1] = 43;
    list->data[2] = 44;
    printf("%d, %d\n", list->capacity, list->size);
    printInts(list->data, list->size);
    free(list->data);
    free(list);
    printf("Allocated and freed list!\n");
}