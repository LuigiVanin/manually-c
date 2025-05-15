#include <stdlib.h>
#include "lib.h"

Array NewArray(int size)
{
    Array arr = {
        .data = (int *)calloc(size, sizeof(int)),
        .capacity = size,
        .length = 0,
    };

    return arr;
}

ArrayList NewArrayList(size_t sizeType, int capacity)
{
    ArrayList d_arr = {
        .capacity = capacity,
        .sizeT = sizeType,
        .length = 0,
        .data = (void *)malloc(sizeType * capacity),
    };
    return d_arr;
}
