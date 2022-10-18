#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct linked_list* new_linked_list(void)
{
    struct linked_list *ll = (struct linked_list*) malloc(sizeof(struct linked_list));
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;

    return ll;
}

void insert_element(struct linked_list *ll, int data, int index)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->data = data;

    if (ll->length == 0)
    {
        n->next = NULL;
        ll->head = n;
        ll->tail = n;
        ll->length++;
    }
    else if (index == 0)
    {
        n->next = ll->head;
        ll->head = n;
        ll->length++;
    }
    else if (index >= ll->length-1)
    {
        n->next = NULL;
        ll->tail->next = n;
        ll->tail = n;
        ll->length++;
    }
    else
    {
        struct node *prev = ll->head;
        for (int i = 0; i < index-1; i++)
        {
            prev = prev->next;
        }

        n->next = prev->next;
        prev->next = n;
        ll->length++;
    }
}

int remove_element(struct linked_list *ll, int index)
{
    struct node *tmp = ll->head;

    if (index == 0)
    {
        int data = tmp->data;
        ll->head = ll->head->next;
        ll->length--;
        free(tmp);

        return data;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            tmp = tmp->next;
        }

        if (index == ll->length-1)
        {
            int data = ll->tail->data;
            free(ll->tail);
            ll->tail = tmp;
            ll->tail->next = NULL;
            ll->length--;

            return data;
        }
        else
        {
            struct node *n = tmp->next;
            int data = n->data;
            tmp->next = n->next;
            ll->length--;
            free(n);

            return data;
        }

    }
}

int get_element(struct linked_list *ll, int index)
{
    if (index == 0)
    {
        return ll->head->data;
    }
    else if (index == ll->length-1)
    {
        return ll->tail->data;
    }
    else
    {
        struct node *n = ll->head;
        for (int i = 0; i < index; i++)
        {
            n = n->next;
        }

        return n->data;
    }
}

int find_element(struct linked_list *ll, int element)
{
    struct node *n = ll->head;
    for (int i = 0; i < ll->length-1; i++)
    {
        if (n->data == element)
        {
            return i;
        }

        n = n->next;
    }

    return -1;
}

void display(struct linked_list *ll)
{
    struct node *n = ll->head;
    for (int i = 0; i < ll->length-2; i++)
    {
        printf("%d --> ", n->data);
        n = n->next;
    }

    printf("%d\n", n->data);
}
