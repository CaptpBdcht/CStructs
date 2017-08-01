#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct s_array_list {
    unsigned int size;
    unsigned int capacity;
    int *data;
} array_list;

array_list *al_create(unsigned int);
void al_append(array_list *, int);
void al_insert_base(array_list *, unsigned int index, int);
void al_insert(array_list *, unsigned int index, int);
void al_prepend(array_list *, int);

unsigned int al_index_of(array_list *, int);
unsigned int al_last_index_of(array_list *, int);

void al_remove(array_list *, unsigned int index);
void al_remove_all(array_list *, int);

void al_revert(array_list *);
void al_shuffle(array_list *);
array_list *al_concat(unsigned int count, ...);

void al_display(array_list *);

#endif