#ifndef __LIST_H__
#define __LIST_H__

struct node{
	struct node *next;
	struct node *prev;
	void *p;
};

struct list{
	struct node *head;
	struct node *tail;
	int size;
};

struct list *list_create();
void *list_destroy(struct list *l);
void *list_destroy_with_function(struct list *l, void (*destroyfunc)(void *));
void *list_get(struct list *l, int index);
struct node *list_get_node(struct list *l, int index);
int list_append(struct list *l, void *p);
int list_queue(struct list *l, void *p);
int list_push(struct list *l, void *p);
void *list_dequeue(struct list *l);
void *list_pop(struct list *l);
void list_swap_node(struct list *l, struct node *one, struct node *two);
void *list_delete(struct list *l, int index);
void *list_delete_node(struct list *l, struct node *node);

#endif