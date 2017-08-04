#include "includes.h"

linked_list *ll_create(void *element, size_t size) {
    linked_list *node = malloc(sizeof *node);

    if (!node) perror("ll_create: node");

    node->data = malloc(size);
    if (!node->data) perror("ll_create: node->data");
    memcpy(node->data, element, size);

    node->next = NULL;

    return node;
}

void ll_free(linked_list **list) {
    if (!list) return;

    while (*list) {
        linked_list *tmp = (*list)->next;

        free((*list)->data);
        free(*list);
        (*list) = tmp;
    }

    (*list) = NULL;
}

void ll_append(linked_list **list, void *element, size_t size) {
    while (*list) list = &(*list)->next;
    *list = ll_create(element, size);
}

void ll_insert(linked_list **list, unsigned int index, void *element, size_t size) {
    while (*list && index) {
        list = &(*list)->next;
        index--;
    }

    if (!index) {
        linked_list *node = ll_create(element, size);
        node->next = (*list);
        (*list) = node;
    }
}

void ll_prepend(linked_list **list, void *element, size_t size) {

}

boolean ll_update(linked_list **list, unsigned int index, void *element, size_t size) {
    while (*list && index) {
        list = &(*list)->next;
        index--;
    }
    
    if (*list && !index) {
        memcpy((*list)->data, element, size);
        return TRUE;
    }

    return FALSE;
}

void ll_remove_index(linked_list **list, unsigned int index) {
    if (!index) {
        linked_list *delete = (*list);
        *list = (*list)->next;

        free(delete->data);
        free(delete);
        return;
    }
    
    --index;
    while (*list && index) {
        list = &(*list)->next;
        index--;
    }

    if (*list && (*list)->next && !index) {
        linked_list *delete = (*list)->next;
        free(delete->data);
        free(delete);

        (*list)->next = (*list)->next->next;
    }
}

void ll_remove_value(linked_list **list, void *element, int (*compare)(const void *, const void *)) {

}

void ll_remove_all(linked_list **list, void *element, int (*compare)(const void *, const void *)) {

}

int ll_index_of(linked_list **list, void *element, int (*compare)(const void *, const void *)) {
    int index = 0;
    while (*list) {
        if (compare(element, (*list)->data) == 0)
            return index;

        ++index;
        list = &(*list)->next;
    }
    return -1;
}

int ll_last_index_of(linked_list **list, void *element, int (*compare)(const void *, const void *)) {
    int index = 0, last = -1;
    while (*list) {
        if (compare(element, (*list)->data) == 0)
            last = index;

        ++index;
        list = &(*list)->next;
    }
    return last;
}

linked_list *ll_get(linked_list **list, int index) {
    if (index < 0) return NULL;

    while (*list && index) {
        list = &(*list)->next;
        index--;
    }

    if (*list && !index) return (*list);
    else return NULL;
}

linked_list *ll_find(linked_list **list, void *element, int (*compare)(const void *, const void *)) {
    int first_index = ll_index_of(list, element, compare);
    return first_index == -1 ? NULL : ll_get(list, first_index);
}

linked_list *ll_find_last(linked_list **list, void *element, int (*compare)(const void *, const void *)) {
    int last_index = ll_last_index_of(list, element, compare);
    return last_index == -1 ? NULL : ll_get(list, last_index);
}

unsigned int ll_size(linked_list *node) {
    if (node) return 1 + ll_size(node->next);
    else return 0;
}
