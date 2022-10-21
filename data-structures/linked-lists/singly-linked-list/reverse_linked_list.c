#include <stddef.h>

#include "implementation/singly_linked_list.h"

void reverse_linked_list(struct singly_linked_list *ll)
{
    struct node *prev = NULL;
    struct node *actual = ll->head;
    struct node *next = ll->head;

    while (next != NULL)
    {
        next = next->next;
        actual->next = prev;
        prev = actual;
        actual = next;
    }

    ll->head = prev;
}

int main(void)
{
    struct singly_linked_list *ll = new_singly_linked_list();

    for (int i = 0; i <= 5; i++)
    {
        insert_element(ll, i, i);
    }

    display(ll);

    reverse_linked_list(ll);
    display(ll);

    return 0;
}
