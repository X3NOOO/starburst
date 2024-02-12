#ifndef STARBURST_DYNAMIC_ARRAY_H
#define STARBURST_DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "macros.h"

/*
Construct a dynamic array type with a given name and type of the items.

Args:
    name: The name of the dynamic array type.
    type: The type of the items.
*/
#define sb_da_construct_type(name, type) \
    typedef struct                       \
    {                                    \
        size_t capacity;                 \
        size_t count;                    \
        type *items;                     \
    } name

/*
Insert a value into a dynamic array at a given index.

Args:
    da: The dynamic array to insert into.
    value: The value to insert.
    index: The index to insert at.
*/
#define sb_da_insert(da, value, index)                                                                                           \
    do                                                                                                                           \
    {                                                                                                                            \
        assert((da)->count >= (index));                                                                                          \
        if ((da)->capacity <= (da)->count)                                                                                       \
        {                                                                                                                        \
            (da)->capacity = (da)->capacity ? (da)->capacity * 2 : 1;                                                            \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*((da)->items)));                                         \
            assert((da)->items);                                                                                                 \
        }                                                                                                                        \
        (void)memmove((da)->items + (index) + 1, (da)->items + (index), ((da)->count - (index)) * sizeof(*((da)->items)));       \
        assert((da)->items);                                                                                                     \
        (da)->items[(index)] = (value);                                                                                          \
        (da)->count++;                                                                                                           \
    } while (0)

/*
Insert an array of items into a dynamic array at a given index.

Args:
    da: The dynamic array to insert into.
    array: The array to insert.
    size: The size of the array.
    index: The index to insert at.
*/
#define sb_da_insert_array(da, array, size, index)                                                                                  \
    do                                                                                                                              \
    {                                                                                                                               \
        static_assert(SB_M_ARE_SAME_TYPE(*(array), *((da)->items)), "Tried to add a value of a different type to a dynamic array"); \
        assert((da)->count >= (index));                                                                                             \
        if ((da)->capacity < (da)->count + (size))                                                                                  \
        {                                                                                                                           \
            while ((da)->capacity < (da)->count + (size))                                                                           \
            {                                                                                                                       \
                (da)->capacity = (da)->capacity ? (da)->capacity * 2 : 1;                                                           \
            }                                                                                                                       \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*((da)->items)));                                            \
            assert((da)->items);                                                                                                    \
        }                                                                                                                           \
        (void)memmove((da)->items + (index) + (size), (da)->items + (index), ((da)->count - (index)) * sizeof(*((da)->items)));     \
        assert((da)->items);                                                                                                        \
        (void)memcpy((da)->items + (index), (array), (size) * sizeof(*((da)->items)));                                              \
        assert((da)->items);                                                                                                        \
        (da)->count += (size);                                                                                                      \
    } while (0)

/*
Remove a value from a dynamic array.

Args:
    da: The dynamic array to remove from.
    index: The index to remove.
*/
#define sb_da_remove(da, index)                                                                                              \
    do                                                                                                                       \
    {                                                                                                                        \
        assert((da)->count > (index));                                                                                       \
        (void)memmove((da)->items + (index), (da)->items + (index) + 1, ((da)->count - (index)-1) * sizeof(*((da)->items))); \
        assert((da)->items);                                                                                                 \
        (da)->count--;                                                                                                       \
        if ((da)->count < (da)->capacity / 2)                                                                                \
        {                                                                                                                    \
            (da)->capacity /= 2;                                                                                             \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*((da)->items)));                                     \
            assert((da)->items);                                                                                             \
        }                                                                                                                    \
    } while (0)

/*
Remove a range of values from a dynamic array.

Args:
    da: The dynamic array to remove from.
    index: The index to start removing at.
    range: The number of indexes to remove.
*/
#define sb_da_remove_multiple(da, index, range)                                                                                            \
    do                                                                                                                                     \
    {                                                                                                                                      \
        assert((da)->count >= range);                                                                                                      \
        (void)memmove((da)->items + (index), (da)->items + (index) + (range), ((da)->count - (index) - (range)) * sizeof(*((da)->items))); \
        assert((da)->items);                                                                                                               \
        (da)->count -= (range);                                                                                                            \
        if ((da)->count < (da)->capacity / 2)                                                                                              \
        {                                                                                                                                  \
            (da)->capacity /= 2;                                                                                                           \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*((da)->items)));                                                   \
            assert((da)->items);                                                                                                           \
        }                                                                                                                                  \
    } while (0)

/*
Append a value to a dynamic array.

Args:
    da: The dynamic array to append to.
    value: The value to append.
*/
#define sb_da_push(da, value) sb_da_insert(da, value, (da)->count)

/*
Append an array to a dynamic array.

Args:
    da: The dynamic array to append to.
    array: The array to append.
    size: The size of the array.
*/
#define sb_da_push_array(da, array, size) sb_da_insert_array(da, array, size, (da)->count)

/*
Remove the last value from a dynamic array.

Args:
    da: The dynamic array to pop from.
*/
#define sb_da_pop(da) sb_da_remove(da, (da)->count - 1)

/*
Remove a range of values from the end of a dynamic array.

Args:
    da: The dynamic array to pop from.
    amount: The number of values to pop.
*/
#define sb_da_pop_multiple(da, amount) sb_da_remove_multiple(da, (da)->count - (amount), (amount))

/*
Free a dynamic array.

Args:
    da: The dynamic array to free.
*/
#define sb_da_free(da)      \
    do                      \
    {                       \
        free((da)->items);  \
        (da)->items = NULL; \
        (da)->capacity = 0; \
        (da)->count = 0;    \
    } while (0)

#endif // STARBURST_DYNAMIC_ARRAY_H
