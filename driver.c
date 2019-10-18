#include "list.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int works = 1;

	struct list *l = list_create();

	works = works & (l->size == 0);
	works = works & (l->head == NULL);
	works = works & (l->tail == NULL);

	int no, *num;
	no = 14;
	num = &no;

	int index = list_append(l, num);

	works = works & (l->size == 1);
	works = works & (index == 0);
	works = works & (list_get(l, index) == num);

	int no2, *num2;
	no2 = 267;
	num2 = &no2;

	list_append(l, num2);
	list_append(l, num);
	list_append(l, num);
	list_append(l, num2);

	int i;
	for(i = 0; i < l->size; i++)
	{
		printf("%d\n", *(int *)list_get(l, i));
	}

	l = list_destroy(l);

	works = works & (l == NULL);

	if(works)
		printf("It works!\n");

	else
		printf("It doesn't work!\n");

	return 0;
}
