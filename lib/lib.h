#ifndef LIB_H
#define LIB_H

typedef struct
{
    int capacity;
    int length;
    int *data;
} Array;

Array NewArray(int capacity);

#endif