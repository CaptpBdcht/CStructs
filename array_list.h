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

int al_index_of(array_list *, void *, int (*compare)(const void *, const void *));
int al_last_index_of(array_list *, void *, int (*compare)(const void *, const void *));
// Todo
void al_remove(array_list *, int index);
void al_remove_all(array_list *, void *, int (*compare)(const void *, const void *));

void al_revert(array_list *);
void al_shuffle(array_list *);
array_list *al_concat(unsigned int count, ...);
// end Todo
#endif