#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "array_list.h"

int main(int argc, char **argv) {
	printf( "Hello World!\n" );
	int i = 10;
	array_list *list = al_create(i);
	while (--i >= 0) al_append(list, i);
	al_display(list);
	al_insert(list, 0, 42);
	al_display(list);
	al_insert(list, 11, 42);
	al_display(list);
	al_insert(list, 6, 42);
	al_display(list);
	al_remove_all(list, 42);
	al_display(list);
	return 0;
}