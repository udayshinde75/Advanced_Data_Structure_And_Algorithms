#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdio.h>

// Symbolic constant
#define SUCCESS 1;
#define TRUE 1;
#define FALSE 0;
#define VECTOR_EMPTY -1;
#define NULL_PTR -2;
#define MEMORY_ALLOCATION_FAILED -3;

typedef int data_t;
typedef struct vector_int vector_int_t;
typedef int status_t;

struct vector_int
{
    data_t* p_data;
    size_t size;
    size_t capacity;
};

vector_int_t* create_vector(void);
status_t release_vector(vector_int_t** pp_vector);

status_t push_back(vector_int_t* p_vector, data_t new_data);
status_t pop_back(vector_int_t* p_vector, data_t* p_popped_data);
status_t push_front(vector_int_t* p_vector, data_t new_data);
status_t pop_front(vector_int_t* p_vector, data_t* p_popped_data);

void show(vector_int_t* p_vector, const char* msg);

void* xmalloc(size_t size_in_bytes);
void* xrealloc(void* old_ptr, size_t new_size_in_bytes);


#endif