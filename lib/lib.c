#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include <string.h>

ArrayList NewArrayListInternal(size_t element_size, size_t capacity)
{
    if (element_size <= 0)
    {
        fprintf(stderr, "Error: `element_size` must be greater than 0.");
        element_size = 1; // default association to a char.
    }

    if (capacity <= 0)
    {
        fprintf(stderr, "Error: `capacity` must be greater than 0.");
        capacity = 8;
    }

    ArrayList arr_list = {
        .capacity = capacity,
        .element_size = element_size,
        .length = 0,
        .data = (void *)malloc(element_size * capacity),
    };

    return arr_list;
}

void PushItemInternal(ArrayList *self, const void *value)
{
    if (self->capacity <= 0)
        self->capacity = 1;

    if (self->length >= self->capacity)
        ResizeList(self);

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

void *GetAtInternal(ArrayList self, size_t index)
{
    if (index >= self.length)
    {
        fprintf(stderr, "Error: Index %zu out of bounds for ArrayList with length %d.\n", index, (int)self.length);
        // Decide on error handling: return NULL, exit, assert, etc.
        return NULL;
    }

    return (char *)self.data + (index * self.element_size);
}
