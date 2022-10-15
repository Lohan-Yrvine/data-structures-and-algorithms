#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

#define DEFAULT_CAPACITY 2

// I am not handling any errors, like popping with 0 elements or accessing an
// index that does not exist, on purpose.

struct dynamic_array* new_dyamic_array(void)
{
    struct dynamic_array *array = (struct dynamic_array*) malloc(sizeof(struct dynamic_array));
    array->arr = (int*) malloc(DEFAULT_CAPACITY * sizeof(int));
    array->capacity = DEFAULT_CAPACITY;
    array->length = 0;

    return array;
}

void increase_capacity_if_needed(struct dynamic_array *array)
{
    if (array->length == array->capacity)
    {
        array->capacity *= 2;
        array->arr = realloc(array->arr, array->capacity * sizeof(int));
    }
}

void append(struct dynamic_array *array, int data)
{
    increase_capacity_if_needed(array);
    array->arr[array->length++] = data;
}

void insert_element(struct dynamic_array *array, int data, int index)
{
    if (!(index < 0 || index > array->length))
    {
        increase_capacity_if_needed(array);
        for (int i = array->length; i > index; i--)
        {
            array->arr[array->length] = array->arr[array->length-1];
        }
        array->arr[index] = data;
        array->length++;
    }
}

void decrease_capacity_if_needed(struct dynamic_array *array)
{
    if (array->length == array->capacity / 4)
    {
        array->capacity /= 2;
        array->arr = realloc(array->arr, array->capacity * sizeof(int));
    }
}

int pop(struct dynamic_array *array)
{
    int value = array->arr[--array->length];
    decrease_capacity_if_needed(array);
    return value;
}

void remove_by_index(struct dynamic_array *array, int index)
{
    for (int i = index; i < array->length-1; i++)
    {
        array->arr[i] = array->arr[i+1];
    }

    array->length--;
    decrease_capacity_if_needed(array);
}

void remove_element(struct dynamic_array *array, int element)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] == element)
        {
            remove_by_index(array, i);
            break;
        }
    }
}

int get(struct dynamic_array *array, int index)
{
    return array->arr[index];
}

int find(struct dynamic_array *array, int element)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

void print(struct dynamic_array *array)
{
    printf("[");
    for (int i = 0; i < array->length-1; i++)
    {
        printf("%d, ", array->arr[i]);
    }
    printf("%d]\n", array->arr[array->length-1]);
}
