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

int list_append(struct list *l, void *p)//append to back
{
	if(l->size == 0)
	{
		l->head = malloc(sizeof(struct node));
		l->tail = l->head;
		l->head->prev = NULL;
	}
	
	else
	{
		l->tail->next = malloc(sizeof(struct node));
		struct node *temp = l->tail;
		l->tail = l->tail->next;
		l->tail->prev = temp;
	}

	l->tail->p = p;
	l->tail->next = NULL;
	l->size++;

	return l->size - 1;
}

int list_queue(struct list *l, void *p)//place in front
{
	if(l->size == 0)
	{
		l->head = malloc(sizeof(struct node));
		l->tail = l->head;
		l->head->next = NULL;
	}

	else
	{
		struct node *newhead = malloc(sizeof(struct node));
		newhead->next = l->head;
		l->head = newhead;
	}

	l->head->prev = NULL;
	l->head->p = p;
	l->size++;

	return l->size - 1;
}

void *list_dequeue(struct list *l)//remove last element
{
	if(l->size == 0)
		return NULL;

	void *p = l->tail->p;

	
	l->tail = l->tail->prev;

	if(l->size == 1)
	{
		free(l->head);
		l->head = NULL;
	}
	else
	{
		free(l->tail->next);
		l->tail->next = NULL;
	}

	l->size--;
	return p;
}

void *list_pop(struct list *l)//remove first element
{
	if(l->size == 0)
		return NULL;

	void *p = l->head->p;

	l->head = l->head->next;
	if(l->size == 1)
	{
		free(l->tail);
		l->tail = NULL;
	}
	else
	{
		free(l->head->prev);
		l->head->prev = NULL;
	}

	l->size--;
	return p;
}

void *list_delete(struct list *l, int index)
{
	if(l->size == 0)
		return NULL;
	if(index >= l->size)
		return NULL;
	
	struct node *temp = l->head, *prev = NULL;

	int i;
	for(i = 0; i < index; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	void *p = temp->p;

	if(prev == NULL)
	{
		l->head = temp->next;
		l->head->prev = NULL;
		p = temp->p;
	}
	else if(temp->next == NULL)
	{
		l->tail = prev;
		prev->next = NULL;
	}
	else
	{
		prev->next = temp->next;
		prev->next->prev = prev;
	}

	free(temp);
	l->size--;
	return p;
}

void *list_delete_node(struct list *l, struct node *node)
{
	if(node == NULL)
		return NULL;
	if(l->size == 0)
		return NULL;

	void *p = node->p;

	if(l->size == 1)
	{
		l->head = NULL;
		l->tail = NULL;
	}
	else if(l->head == node)
	{
		l->head = node->next;
		l->head->prev = NULL;
	}
	else if(l->tail == node)
	{
		l->tail = node->prev;
		l->tail->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	free(node);	

	l->size--;
	return p;
}