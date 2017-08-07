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
	printf("\n%d", al_index_of(list, &i, compareInt)); // oob

	printf("\n%d", al_last_index_of(list, &val, compareInt));
	printf("\n%d\n", al_last_index_of(list, &i, compareInt)); // oob

	al_free(&list);
}

void tests_linked_list() {
	linked_list *list = NULL;
	int i = 42, j = 11, k = 0, not = 99;
	list = ll_create(&i, sizeof i);

	ll_append(&list, &j, sizeof j);
	ll_append(&list, &i, sizeof i);
	ll_insert(&list, 1, &j, sizeof j);
	ll_insert(&list, 10, &j, sizeof j); // oob
	ll_update(&list, 2, &k, sizeof k);
	ll_update(&list, 4, &k, sizeof k);
	ll_update(&list, 10, &k, sizeof k); // oob
	ll_remove_index(&list, 0);
	ll_remove_index(&list, 10); // oob
	ll_append(&list, &k, sizeof k);
	ll_prepend(&list, &k, sizeof k);
	ll_prepend(&list, &i, sizeof i);

	printf("indexOf 0     : %d\n", ll_index_of(&list, &k, compareInt));
	printf("lastIndexOf 0 : %d\n", ll_last_index_of(&list, &k, compareInt));
	linked_list *node = ll_get(&list, 1);
	printf("node 1        : %d\n", *(int*)node->data);
	linked_list *fnode = ll_find(&list, &j, compareInt);
	printf("find first 11 : %s\n", fnode != NULL ? "OK" : "KO");
	linked_list *flnode = ll_find_last(&list, &i, compareInt);
	printf("find last 42  : %s\n", flnode != NULL ? "OK" : "KO");
	linked_list *fnotnode = ll_find(&list, &not, compareInt);
	printf("find first 99 : %s\n", fnotnode != NULL ? "OK" : "KO");

	ll_remove_value(&list, &j, compareInt);
	ll_remove_all(&list, &k, compareInt);

	printf("size: %d\n", ll_size(list));
	while (list) {	
		printf("%d ", *(int*)list->data);
		list = list->next;
	}

	ll_free(&list);
}

void tests_bst() {
	bst_node *root = NULL;
	int a = 1, b = 7, c = 42, d = 100, e = 12345;
	root = bst_insert(root, &c, sizeof c, compareInt);
	root = bst_insert(root, &a, sizeof a, compareInt);
	root = bst_insert(root, &d, sizeof d, compareInt);
	root = bst_insert(root, &b, sizeof b, compareInt);
	root = bst_insert(root, &e, sizeof e, compareInt);
	root = bst_insert(root, &a, sizeof a, compareInt);
	
	bst_display_int(root, PRE_ORDER);
	printf("\n");
	bst_display_int(root, IN_ORDER);
	printf("\n");
	bst_display_int(root, POST_ORDER);
	printf("\n");
	// bst_breadth_display_int(root);
}

int main(int argc, char **argv) {

	// tests_array_list();
	// tests_linked_list();
	tests_bst();

	return EXIT_SUCCESS;
}