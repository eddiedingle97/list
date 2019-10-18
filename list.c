#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct list *list_create()
{
	struct list *l = malloc(sizeof(struct list));
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;

	return l;
}

void *list_destroy(struct list *l)
{
	int i;
	struct node *temp = l->head;
	for(i = 0; i < l->size; i++)
	{
		l->head = l->head->next;
		free(temp);
		temp = l->head;
	}

	free(l);
	return NULL;
}

void *list_get(struct list *l, int index)
{
	if(l->size == 0)
		return NULL;
	if(index >= l->size)
		return NULL;
	
	struct node *temp = l->head;

	int i;
	for(i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp->p;
}

int list_append(struct list *l, void *p)
{
	if(l->size == 0)
	{
		l->head = malloc(sizeof(struct node));
		l->tail = l->head;
	}
	
	else
	{
		l->tail->next = malloc(sizeof(struct node));
		l->tail = l->tail->next;
	}

	l->tail->p = p;
	l->tail->next = NULL;
	l->size++;

	return l->size - 1;
}









