#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Calculates the index destination pointer in the vector data memory block
char* calculate_index_dest_ptr(vector* vec, size_t index) {
    return (char*)vec->data + (index * vec->data_size);
}

/// Creates a new vector
vector* new_vec(size_t dataSize) {
    vector* newVec = (vector*) malloc(sizeof(vector));
    newVec->data = NULL;
    newVec->data_size = dataSize;
    newVec->length = 0;

    return newVec;
}

/// Insert the item into the vector at the last index
void vec_push(vector* vec, const void* item) {
    vec->length++;

    // Reallocates enough space for the new item
    vec->data = realloc(vec->data, vec->length * vec->data_size);

    // Destination pointer for the last element in the array
    char* dest = calculate_index_dest_ptr(vec, vec->length - 1); 
    memcpy(dest, item, vec->data_size);
}

/// Inserts an item into the vector at the index
void vec_insert(vector* vec, const void* item, size_t index) {
    if (index > vec->length){
        vec_push(vec, item);
        return;
    };

    vec->length++;

    // Reallocates enough space for the entire array
    vec->data = realloc(vec->data, vec->length * vec->data_size);

    // Destination pointer to the index
    char* insertDest = calculate_index_dest_ptr(vec, index);

    // The amount of elements that we need to move in the vector
    char* src =  calculate_index_dest_ptr(vec, index + 1);

    // The amount of elements needed to be moved in the vector
    size_t elementsToMove = (vec->length - index - 1);

    memmove(insertDest + vec->data_size, src, elementsToMove * vec->data_size);
    memcpy(insertDest, item, vec->data_size);
}


/// Removes an item from the vector at the index
void vec_remove(vector* vec, size_t index) {
    if (index >= vec->length - 1) {
        vec_pop(vec);
        return;
    }

    // Destination pointer to the index of which we would like to remove
    char* targetDest = calculate_index_dest_ptr(vec, index);

    // Destination pointer to the index of which we would like to move our memory from
    char* src = calculate_index_dest_ptr(vec, index + 1);

    // The amount of elements that we need to move in the vector
    size_t elementsToMove = (vec->length - index - 1);

    memmove(targetDest, src, elementsToMove * vec->data_size);

    // Reallocates enough memory to hold what is needed for the vector
    vec->length--;
    vec->data = realloc(vec->data, vec->length * vec->data_size);
}

/// Removes the item from the vector at the last index
void vec_pop(vector* vec) {
    if (vec->length == 0) return;
    vec->length--;

    // Reallocates and frees the last index in the memory block
    vec->data = realloc(vec->data, vec->length * vec->data_size);
}

/// Clears the vector and removes all of the items
void vec_clear(vector* vec) {
    if (vec->length == 0) return;
    vec->data = realloc(vec->data, 0);
    vec->length = 0;
}

/// Frees the items and the vector itself
void vec_free(vector* vec) {
    free(vec->data);
    free(vec);
}

