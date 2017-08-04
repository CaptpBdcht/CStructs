#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct s_linked_list {
    void *data;
    struct s_linked_list *next;
} linked_list;

linked_list *ll_create(void *, size_t);
void ll_free(linked_list **);

void ll_append(linked_list **, void *, size_t);
void ll_insert(linked_list **, unsigned int index, void *, size_t);
void ll_prepend(linked_list **, void *, size_t);
boolean ll_update(linked_list **, unsigned int index, void *, size_t);

void ll_remove_index(linked_list **, unsigned int index);
void ll_remove_value(linked_list **, void *, int (*compare)(const void *, const void *));
void ll_remove_all(linked_list **, void *, int (*compare)(const void *, const void *));

int ll_index_of(linked_list **, void *, int (*compare)(const void *, const void *));
int ll_last_index_of(linked_list **, void *, int (*compare)(const void *, const void *));

linked_list *ll_get(linked_list **, int index);
linked_list *ll_find(linked_list **, void *, int (*compare)(const void *, const void *));
linked_list *ll_find_last(linked_list **, void *, int (*compare)(const void *, const void *));

unsigned int ll_size(linked_list *);

#endif