#include "includes.h"

int main(int argc, char **argv) {

	array_list *list = NULL;
	list = al_create(10, sizeof(int));

	int i;
	for (i = 0; i < 10; i++) {
		al_append(list, &i);}
	for (i = 0; i < 10; i++)
		printf("%d ", ((int *)list->data)[i]);

	
	al_free(&list);

	return 0;
}