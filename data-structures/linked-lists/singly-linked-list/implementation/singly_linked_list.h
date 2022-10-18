#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct node
{
    int data;
    struct node *next;
};

struct singly_linked_list
{
    struct node *head;
    struct node *tail;
    int length;
};

struct singly_linked_list* new_singly_linked_list(void);

void insert_element(struct singly_linked_list *ll, int data, int index);

int remove_element(struct singly_linked_list *ll, int index);

int get_element(struct singly_linked_list *ll, int index);
int find_element(struct singly_linked_list *ll, int element);

void display(struct singly_linked_list *ll);

#endif
