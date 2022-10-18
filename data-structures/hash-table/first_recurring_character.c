#include <stdio.h>
#include <stdlib.h>

#include "implementation/hash_table.h"

void* first_recurring_character(int a[], size_t length)
{
    struct hash_table *table = new_hash_table();
    for (int i = 0; i < length; i++) {
        if (get_value(table, a[i]) == NULL)
        {
            insert_element(table, a[i], 1);
        }
        else
        {
            return &a[i];
        }
    }

    return NULL;
}

int main(void)
{
    int a1[] = {2, 5, 1, 2, 3, 5, 1, 2, 3};
    int a2[] = {2, 1, 1, 2, 3, 5, 1, 2, 4};
    int a3[] = {2, 3, 4, 5};

    int *x = first_recurring_character(a1, 9);
    int *y = first_recurring_character(a2, 9);
    int *z = first_recurring_character(a3, 4);

    int *arr[3] = {x, y, z};

    for (int i = 0; i < 3; i++)
    {
        if (arr[i] != NULL)
        {
            printf("%d\n", *arr[i]);
        }
        else
        {
            printf("NULL\n");
        }
    }

    return 0;
}
