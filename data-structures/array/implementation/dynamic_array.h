#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct dynamic_array
{
    int *arr;
    int capacity;
    int length;
};

void append(struct dynamic_array *array, int data);
void insert(struct dynamic_array *array, int data, int index);

int pop(struct dynamic_array *array);
void remove_element(struct dynamic_array *array, int index);

int get(struct dynamic_array *array, int index);
int find(struct dynamic_array *array, int element);
void print(struct dynamic_array *array);

#endif
