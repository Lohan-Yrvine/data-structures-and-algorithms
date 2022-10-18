#ifndef HASH_TABLE_H
#define HASH_TABLE_H

struct node
{
    int key;
    int value;
};

struct hash_table
{
    struct node **arr;
};

struct hash_table* new_hash_table(void);

int hash_function(int key);
void insert_element(struct hash_table *table, int key, int value);

void* get_value(struct hash_table *table, int key);
void remove_element(struct hash_table *table, int key);

void print(struct hash_table *table);

#endif
