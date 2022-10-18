#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

#define TABLE_SIZE 128

struct hash_table* new_hash_table(void)
{
    struct hash_table *table = (struct hash_table*) malloc(sizeof(struct hash_table*));
    table->arr = (struct node**) malloc(TABLE_SIZE * sizeof(struct node*));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->arr[i] = NULL;
    }

    return table;
}

int hash_function(int key)
{
    return key % TABLE_SIZE;
}

void insert_element(struct hash_table *table, int key, int value)
{
    int h = hash_function(key);

    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->key = h;
    n->value = value;

    table->arr[h] = n;
}

void* get_value(struct hash_table *table, int key)
{
    int h = hash_function(key);
    if (table->arr[h] == NULL)
    {
        return NULL;
    }

    return &table->arr[h]->value;
}

void remove_element(struct hash_table *table, int key)
{
    int h = hash_function(key);
    free(table->arr[h]);
    table->arr[h] = NULL;
}

void print(struct hash_table *table)
{
    printf("{\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table->arr[i] != NULL)
        {
            printf("\t%d: %d\n", table->arr[i]->key, table->arr[i]->value);
        }
    }
    printf("}\n");
}
