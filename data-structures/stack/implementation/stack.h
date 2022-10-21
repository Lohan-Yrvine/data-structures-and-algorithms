#ifndef STACK_H
#define STACK_H

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
    int length;
};

struct stack* new_stack(void);

struct node peek(struct stack *st);
void push(struct stack *st, int data);
int pop(struct stack *st);
bool is_empty(struct stack *st);

void display(struct stack* st);

#endif
