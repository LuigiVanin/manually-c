#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include <string.h>

Array NewArray(int size)
{
    Array arr = {
        .data = (int *)calloc(size, sizeof(int)),
        .capacity = size,
        .length = 0,
    };

    return arr;
}

ArrayList NewArrayList(size_t element_size, int capacity)
{
    ArrayList d_arr = {
        .capacity = capacity,
        .element_size = element_size,
        .length = 0,
        .data = (void *)malloc(element_size * capacity),
    };
    return d_arr;
}

void PushItem(ArrayList *self, const void *value)
{
    if (self->capacity <= 0)
        self->capacity = 1;

    if (self->length >= self->capacity)
        ResizeList(self);

    // Array starting point = self->data
    // Array current point = startiing point + (self->length * self->element_size)

    /**
     * NOTE: Why use char* instead of void* for address manipulation?
     *       Some compilers dont know how to properly handle void* pointer arithimatic manipulation due
     *       to void not being a proper type not having defined size depending on the compiler. To standartize
     *       the behaviour, is recommended to cast the void pointer to a char* that has a well defined bit length
     * */
    char *dest = (char *)self->data + (self->length * self->element_size);
    memcpy(dest, value, self->element_size);

    self->length++;
}

void ResizeList(ArrayList *list)
{
    fprintf(stderr, "TODO: Not Implemented yet");
}
