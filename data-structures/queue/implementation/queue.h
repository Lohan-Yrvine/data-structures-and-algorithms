#ifndef QUEUE_H
#define QUEUE_H

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *first;
    struct node *last;
    int length;
};

struct queue* new_queue(void);

int peek(struct queue *q);
void enqueue(struct queue *q, int data);
int dequeue(struct queue *q);
bool is_empty(struct queue *q);

void display(struct queue *q);

#endif
