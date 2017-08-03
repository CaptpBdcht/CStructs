#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

/*
 * -> void *
 * https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it
 ***/

typedef struct s_array_list {
    size_t capacity;
    size_t count;
    void *data;
    size_t memb_size;
} array_list;

array_list *al_create(size_t, size_t);
void al_free(array_list **);

void al_append(array_list *, void *);
void al_insert_base(array_list *, unsigned int index, void *);
void al_insert(array_list *, unsigned int index, void *);
void al_prepend(array_list *, void *);

unsigned int al_index_of(array_list *, void *, int (*compare)(const void *, const void *));
unsigned int al_last_index_of(array_list *, void *, int (*compare)(const void *, const void *));

void al_remove(array_list *, int);
void al_remove_all(array_list *, void *, int (* compare)(void *, void *));

void al_revert(array_list *);
void al_shuffle(array_list *);
array_list *al_concat(unsigned int count, ...);

/*
typedef struct s_array_list {
    unsigned int size;
    unsigned int capacity;
    int *data;
} array_list;

array_list *al_create(unsigned int);
void al_free(array_list **);

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


array_list *list;
list = al_create(10, sizeof(int));
int i;
for (i = 0; i < 10; i++)
    al_append(list, &i);
*/

#endif