#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node
{
    int data;
    struct node *next;
};

struct linked_list
{
    struct node *head;
    struct node *tail;
    int length;
};

struct linked_list* new_linked_list(void);

void insert_element(struct linked_list *ll, int data, int index);

int remove_element(struct linked_list *ll, int index);

int get_element(struct linked_list *ll, int index);
int find_element(struct linked_list *ll, int element);

void display(struct linked_list *ll);

#endif
