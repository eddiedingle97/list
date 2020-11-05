#include "list.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int works = 1;

	struct list *l = list_create();

	works = works & (l->size == 0);
	works = works & (l->head == NULL);
	works = works & (l->tail == NULL);

	int i = 20, j = 30, k = 40;

	list_append(l, &i);
	list_append(l, &j);
	list_append(l, &k);

	printf("%d %d %d\n", *(int *)(l->head->p), *(int *)(l->head->next->p), *(int *)(l->head->next->next->p));

	printf("%d %d %d\n", *(int *)(l->tail->p), *(int *)(l->tail->prev->p), *(int *)(l->tail->prev->prev->p));

	list_delete(l, 1);

	printf("%d %d \n", *(int *)(l->head->p), *(int *)(l->head->next->p));

	list_append(l, &j);

	printf("%d %d %d\n", *(int *)(l->head->p), *(int *)(l->head->next->p), *(int *)(l->head->next->next->p));

	list_delete_node(l, l->tail->prev);

	printf("%d %d \n", *(int *)(l->head->p), *(int *)(l->head->next->p));

	if(works)
		printf("It works!\n");

	else
		printf("It doesn't work!\n");

	return 0;
}
