#include <stdio.h>

#include "implementation/dynamic_array.h"

int main()
{
    struct dynamic_array *regular = new_dyamic_array();
    struct dynamic_array *reversed = new_dyamic_array();

    append(regular, 0);
    append(regular, 3);
    append(regular, 4);
    append(regular, 4);
    append(regular, 6);
    append(regular, 30);
    append(regular, 31);

    for (int i = regular->length-1; i >= 0; i--)
    {
        append(reversed, get(regular, i));
    }

    printf("Regular:  ");
    print(regular);
    printf("Reversed: ");
    print(reversed);

    return 0;
}
