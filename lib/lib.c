#include <stdlib.h>
#include "lib.h"

Array NewArray(int size)
{
    Array arr = {
        .data = (int *)calloc(size, sizeof(size)),
        .capacity = size,
        .length = 0,
    };

    return arr;
}