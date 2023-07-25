#pragma once

#include <stddef.h>

typedef struct {
    void* data;
    size_t length;
    size_t data_size;
} vector; 

vector* new_vec(size_t dataSize);
void vec_push(vector* vec, const void* item);
void vec_pop(vector* vec);
void vec_clear(vector* vec);
void vec_free(vector* vec);
void vec_insert(vector* vec, const void* item, size_t index);
void vec_remove(vector* vec, size_t index);
