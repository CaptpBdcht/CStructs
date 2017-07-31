#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct s_array_list {
    int size;
    int capacity;
    int *data;
} array_list;

void test();

#endif