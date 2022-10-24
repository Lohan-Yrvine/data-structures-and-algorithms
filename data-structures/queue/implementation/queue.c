#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct queue* new_queue(void)
{
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->first = NULL;
    q->last = NULL;
    q->length = 0;

    return q;
}

int peek(struct queue *q)
{
    return q->first->data;
}

void enqueue(struct queue *q, int data)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    if (q->length == 0)
    {
        q->first = n;
        q->last = n;
        q->length++;
    }
    else
    {
        q->last->next = n;
        q->last = n;
        q->length++;
    }
}

int dequeue(struct queue *q)
{
    int data = q->first->data;
    struct node *tmp = q->first;
    q->first = q->first->next;
    q->length--;
    free(tmp);

    if (q->length == 0)
    {
        q->last = NULL;
    }

    return data;
}

bool is_empty(struct queue *q)
{
    if (q->length == 0)
    {
        return true;
    }

    return false;
}

void display(struct queue *q)
{
    struct node *tmp = q->first;
    for (int i = 0; i < q->length; i++)
    {
        printf("V| %d\n", tmp->data);
        tmp = tmp->next;
    }
}
