#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

struct stack* new_stack(void)
{
    struct stack *st = (struct stack*) malloc(sizeof(struct stack));
    st->length = 0;
    st->top = NULL;

    return st;
}

struct node peek(struct stack *st)
{
    return *st->top;
}

void push(struct stack *st, int data)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->next = st->top;
    st->top = n;
    st->length++;
}

int pop(struct stack *st)
{
    int data = st->top->data;
    struct node *tmp = st->top;
    st->top = st->top->next;
    st->length--;
    free(tmp);

    return data;
}

bool is_empty(struct stack *st)
{
    if (st->length == 0)
    {
        return true;
    }

    return false;
}

void display(struct stack* st)
{
    struct node *tmp = st->top;
    for (int i = 0; i < st->length; i++)
    {
        printf("[ %d\n", tmp->data);
        tmp = tmp->next;
    }
}
