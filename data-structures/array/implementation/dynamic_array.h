#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "struct.h"

struct dynamic_array* new_dyamic_array();

void append(struct dynamic_array *array, int data);
void insert_element(struct dynamic_array *array, int data, int index);

int pop(struct dynamic_array *array);
void remove_by_index(struct dynamic_array *array, int index);
void remove_element(struct dynamic_array *array, int element);

void* get(struct dynamic_array *array, int index);
int find(struct dynamic_array *array, int element);

void print(struct dynamic_array *array);

#endif
