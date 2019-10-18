#ifndef __LIST_H__
#define __LIST_H__

struct node{
	struct node *next;
	void *p;
};

struct list{
	struct node *head;
	struct node *tail;
	int size;
};

struct list *list_create();
void *list_destroy(struct list *l);
void *list_get(struct list *l, int index);
int list_append(struct list *l, void *p);

#endif
