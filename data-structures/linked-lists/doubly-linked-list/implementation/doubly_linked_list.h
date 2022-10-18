#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct doubly_linked_list
{
    struct node *head;
    struct node *tail;
    int length;
};

struct doubly_linked_list* new_doubly_linked_list(void);

void insert_element(struct doubly_linked_list *ll, int data, int index);

int remove_element(struct doubly_linked_list *ll, int index);

int get_element(struct doubly_linked_list *ll, int index);
int find_element(struct doubly_linked_list *ll, int element);

void display(struct doubly_linked_list *ll);

#endif
