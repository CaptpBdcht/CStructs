#include "includes.h"

int compareInt(const void *lhs, const void *rhs) {
	const int *x = lhs;
	const int *y = rhs;

	if (*x > *y) return 1;
	if (*x == *y) return 0;
	return -1;
}

void tests_array_list() {
	array_list *list = NULL;
	list = al_create(10, sizeof(int));

	int i;
	for (i = 0; i < 8; i++)
		al_append(list, &i);
	
	int val = 42;
	al_insert_base(list, 0, &val);
	al_insert(list, 5, &val);
	al_insert_base(list, 10, &val);
	al_insert(list, 3, &val);
	al_insert_base(list, 9, &val);

	for (i = 0; i < list->count; i++)
		printf("%d ", ((int *)list->data)[i]);

	printf("\n%d", al_index_of(list, &val, compareInt));
	printf("\n%d", al_index_of(list, &i, compareInt));

	printf("\n%d", al_last_index_of(list, &val, compareInt));
	printf("\n%d\n", al_last_index_of(list, &i, compareInt));

	al_free(&list);
}

void tests_linked_list() {
	linked_list *list = NULL;
	int i = 42, j = 11, k = 0;
	list = ll_create(&i, sizeof i);

	ll_append(&list, &j, sizeof j);
	ll_append(&list, &i, sizeof i);
	ll_insert(&list, 1, &j, sizeof j);
	ll_update(&list, 2, &k, sizeof k);
	ll_update(&list, 4, &k, sizeof k);

	printf("size: %d\n", ll_size(list));
	while (list) {	
		printf("%d ", *(int*)list->data);
		list = list->next;
	}

	ll_free(&list);
}

int main(int argc, char **argv) {

	// tests_array_list();
	tests_linked_list();

	return EXIT_SUCCESS;
}