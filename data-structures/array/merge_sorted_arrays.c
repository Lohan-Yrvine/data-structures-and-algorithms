#include <stdio.h>

#include "implementation/dynamic_array.h"

int main()
{
    struct dynamic_array *array1 = new_dyamic_array();
    struct dynamic_array *array2 = new_dyamic_array();
    struct dynamic_array *merged = new_dyamic_array();

    append(array1, 0);
    append(array1, 3);
    append(array1, 4);
    append(array1, 31);

    append(array2, 4);
    append(array2, 6);
    append(array2, 30);

    int index1 = 0;
    int index2 = 0;
    while (index1 < array1->length || index2 < array2->length)
    {
        if (index1 == array1->length)
        {
            append(merged, get(array2, index2++));
        }
        else if (index2 == array2->length)
        {
            append(merged, get(array1, index1++));
        }
        else
        {
            int element1 = get(array1, index1);
            int element2 = get(array2, index2);
            if (element1 <= element2)
            {
                append(merged, element1);
                index1++;
            }
            else
            {
                append(merged, element2);
                index2++;
            }
        }
    }

    printf("Array 1: ");
    print(array1);
    printf("Array 2: ");
    print(array2);
    printf("Merged:  ");
    print(merged);

    return 0;
}
