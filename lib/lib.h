#ifndef LIB_H
#define LIB_H

#define _newArrayListOverload1(T, capacity) \
    NewArrayListInternal(sizeof(T), capacity)

#define _newArrayListOverload2(T) \
    NewArrayListInternal(sizeof(T), 8)

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
#define NewArrayList(...)       \
    _GET_NEW_ARRAY_MACRO(       \
        __VA_ARGS__,            \
        _newArrayListOverload1, \
        _newArrayListOverload2) \
    (__VA_ARGS__)

/**
 * @brief Pushes an item onto a generic array list.
 *
 * This macro appends a new item to the end of the specified array list,
 * automatically resizing the underlying storage if necessary.
 *
 * @param LIST Pointer to the array list.
 * @param VALUE The item to be added to the list.
 *
 * @note The list must have been initialized using NewArrayListT.
 */
#define PushItem(LIST, VALUE)                  \
    do                                         \
    {                                          \
        typeof(VALUE) __temp_value = (VALUE);  \
        PushItemInternal(LIST, &__temp_value); \
    } while (0)

/**
 * @brief Creates a new ArrayList instance.
 *
 * This macro initializes a new ArrayList with the specified element type.
 * It allocates memory for the list structure and sets up the initial capacity.
 *
 * @param type The data type of elements to be stored in the ArrayList.
 * @return A pointer to the newly created ArrayList.
 *
 * @note The returned ArrayList must be freed using the appropriate destroy function
 *       to avoid memory leaks.
 */
#define GetAt(T, LIST, INDEX) \
    (*(T *)GetAtInternal(LIST, INDEX));

typedef struct
{
    size_t capacity;
    size_t length;
    void *data;
    size_t element_size;
} ArrayList;

ArrayList NewArrayListInternal(size_t element_size, size_t capacity);
void PushItemInternal(ArrayList *list, const void *value);
void ResizeList(ArrayList *list);
void *GetAtInternal(ArrayList list, size_t index);

#endif