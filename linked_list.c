#include "includes.h"

linked_list *ll_create(void *element, size_t size) {
    linked_list *node = malloc(sizeof *node);

    node->data = malloc(size);
    memcpy(node->data, element, size);
    node->next = NULL;

    return node;
}

void ll_free(linked_list **list) {
    if (!list)
        return;

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

boolean ll_update(linked_list **list, unsigned int index, void *element, size_t size) {
    while (*list && index) {
        list = &((*list)->next);
        index--;
    }
    
    if (*list && !index) {
        memcpy((*list)->data, element, size);
        return TRUE;
    }

    return FALSE;
}

unsigned int ll_size(linked_list *node) {
    if (node) return 1 + ll_size(node->next);
    else return 0;
}
