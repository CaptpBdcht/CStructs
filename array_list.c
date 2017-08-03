#include "includes.h"

array_list *al_create(size_t capacity, size_t memb_size) {
    array_list *list = malloc(sizeof *list);

    if (!list) perror("al_create: list");

    list->capacity = capacity;
    list->count = 0;
    list->memb_size = memb_size;
    list->data = malloc(list->capacity * list->memb_size);
    
    if (!list->data) perror("al_create: list->data");
    
    printf("list %d %d %d\n", list->capacity, list->count, list->memb_size);

    return list;
}

void al_free(array_list **list) {
    if (list && *list) {
        if ((*list)->data)
            free((*list)->data);

        free(*list);
        (*list) = NULL;   
    }
}

void al_append(array_list *list, void *element) {
    if (list && list->count < list->capacity) {
        memcpy(list->data + (list->count * list->memb_size), element, list->memb_size);
        list->count++;
    }
}

void al_insert_base(array_list *list, unsigned int index, void *element) {
    if (!list)
        return;

    if (index < list->count) {
        if (list->count != list->capacity) {
            int i = list->count++;
            for (; i > index; i--)
                memcpy(list->data + (i * list->memb_size), list->data + ((i-1) * list->memb_size), list->memb_size);
            memcpy(list->data + (i * list->memb_size), element, list->memb_size);
        }
        else
            al_insert(list, index, element); 
    }
    else if (index == list->count)
        al_insert(list, index, element);
}

void al_insert(array_list *list, unsigned int index, void *element) {
    if (!list || index > list->count)
        return;

    if (list->count < list->capacity) {
        al_insert_base(list, index, element);
    }
    else {
        list->capacity *= 2;
        void *data = malloc(list->capacity * list->memb_size);
        int i;

        for (i = 0; i < index; i++) memcpy(data + (i * list->memb_size), list->data + (i * list->memb_size), list->memb_size);
        memcpy(data + (i * list->memb_size), element, list->memb_size);
        for (; i < list->count; i++) memcpy(data + ((i+1) * list->memb_size), list->data + (i * list->memb_size), list->memb_size);
        
        free(list->data);
        list->data = data;
        list->count++;
    }
}

void al_prepend(array_list *list, void *element) {
    al_insert(list, 0, element);
}

unsigned int al_index_of(array_list *list , void *element, int (*compare)(const void *, const void *)) {
    if (list) {
        int i = -1;
        while (++i < list->count)
            if (compare(element, list->data + (i * list->memb_size)) == 0)
                return i;
    }
    return -1;
}

unsigned int al_last_index_of(array_list *list, void *element, int (*compare)(const void *, const void *)) {
    if (list) {
        int i = list->count;
        while (--i >= 0)
            if (compare(element, list->data + (i * list->memb_size)) == 0)
                return i;
    }
    return -1;
}

/*
void al_remove(array_list *list, unsigned int index) {
    if (list && list->size && index < list->size) {
        int i = index;
        
        for (; i < list->size; i++) 
            list->data[i] = list->data[i+1];
        
        list->size--;
    }
}

void al_remove_all(array_list *list, int value) {
    int index;
    while ((index = al_last_index_of(list, value)) != -1)
        al_remove(list, index);
}

void al_revert(array_list *list) {
    if (list && list->size) {
        int i = 0;
        int half_len = (list->size % 2 == 0)
                     ? (list->size / 2) : ((list->size - 1) / 2);

        for (; i < half_len; i++)
            permuteInt(&list->data[i], &list->data[list->size - 1 - i]);
    }
}

void al_shuffle(array_list *list) {
    if (list && list->size) {
        int i = 0;
        for (; i < list->size; i++) {
            int toShuffle = (rand() % (list->size - i)) + i;
            permuteInt(&list->data[i], &list->data[toShuffle]);
        }
    }
}

array_list *al_concat(unsigned int count, ...) {
    if (count < 2)
        return NULL;

    va_list pa;
    va_start(pa, count);
    int i = 0, j = 0;
    int size = 0;

    for (; i < count; i++)
        size += va_arg(pa, array_list *)->size;
    va_end(pa);

    array_list *merged = al_create(size);
    va_start(pa, count);
    i = 0;

    for (; i < count; i++) {
        array_list *tmp = va_arg(pa, array_list *);
        for (; j < tmp->size; j++)
            al_append(merged, tmp->data[j]);
    }
    va_end(pa);

    return merged;
}

void al_display(array_list *list) {
    if (list && list->size) {
        int length = list->size - 1,
            i = 0;

        for (; i < length; i++)
            printf("%d ", list->data[i]);
        printf("%d\n", list->data[i]);
    }
}
*/
