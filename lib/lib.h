#ifndef LIB_H
#define LIB_H

#define _NewArrayListTemplate1(type, capacity) \
    NewArrayList(sizeof(type), capacity)

#define _NewArrayListTemplate2(type) \
    NewArrayList(sizeof(type), 8)

#define _GET_NEW_ARRAY_MACRO(_1, _2, NAME, ...) NAME

/**
 * @brief Macro to create a new ArrayList template with optional default capacity.
 *
 * This macro supports two overloads:
 * - NewArrayListTemplate(Type): Creates a new ArrayList for the specified Type with a default capacity of 8.
 * - NewArrayListTemplate(Type, Capacity): Creates a new ArrayList for the specified Type with the given initial Capacity.
 *
 * @param Type The type of elements to be stored in the ArrayList.
 * @param Capacity (Optional) The initial capacity of the ArrayList. If not provided, defaults to 8.
 */
#define NewArrayListT(...)      \
    _GET_NEW_ARRAY_MACRO(       \
        __VA_ARGS__,            \
        _NewArrayListTemplate1, \
        _NewArrayListTemplate2) \
    (__VA_ARGS__)

typedef struct
{
    int capacity;
    int length;
    int *data;
} Array;

Array NewArray(int capacity);

typedef struct
{
    int capacity;
    int length;
    void *data;
    size_t sizeT;
    char *tName;
} ArrayList;

ArrayList NewArrayList(size_t sizeType, int capacity);

#endif