#include "includes.h"

struct s_array_list *al_create(size_t capacity, size_t memb_size) {
    struct s_array_list *list = malloc(sizeof *list);

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
            for (; i > index; i--) list->data[i] = list->data[i-1];
            list->data[index] = value;
        }
        else
            al_insert(list, index, element); 
    }
    else if (index == list->count)
        al_append(list, element);
}

/*
void al_insert_base(array_list *list, unsigned int index, int value) {
    if (!list)
        return;

    if (index == list->size) {
        al_append(list, value);
    }
    else if (index < list->size) {
        if (list->size == list->capacity)
            al_insert(list, index, value);
        else {
            int i = list->size++;

            for (; i > index; i--)
                list->data[i] = list->data[i-1];
            
            list->data[index] = value;
        }
    }
}

void al_insert(array_list *list, unsigned int index, int value) {
    if (list && index <= list->size) {
        if (list->size < list->capacity) {
            al_insert_base(list, index, value);
        }
        else {
            list->capacity *= 2;
            int *data = malloc(sizeof *data * list->capacity);
            int i;

            for (i = 0; i < index; i++) data[i] = list->data[i];
            data[i] = value;
            for (; i < list->size; i++) data[i+1] = list->data[i];

            free(list->data);
            list->data = data;
            list->size++;
        }
    }
}

void al_prepend(array_list *list, int value) {
    al_insert(list, 0, value);
}

unsigned int al_index_of(array_list *list, int value) {
    if (list) {
        int i = -1;
        while (++i < list->size) {
            if (list->data[i] == value) {
                return i;
            }
        }
    }
    return -1;
}

unsigned int al_last_index_of(array_list *list, int value) {
    if (list) {
        int i = list->size;
        while (--i >= 0) {
            if (list->data[i] == value) {
                return i;
            }
        }
    }
    return -1;
}

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
