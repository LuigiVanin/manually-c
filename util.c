#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void InsertAt(int *x, int pos, int value)
{
    x[pos] = value;

    printf("Value at %d is equal %d as asked(%d)", pos, x[pos], value);
}