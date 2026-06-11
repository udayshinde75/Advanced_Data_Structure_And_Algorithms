#include "vector.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

vector_int_t* create_vector(void)
{
    vector_int_t* p_vector = NULL;
    p_vector = (vector_int_t*)xmalloc(sizeof(vector_int_t));
    p_vector->size = 0;
    p_vector->capacity = 0;
    p_vector->p_data = NULL;
    return (p_vector);
}

status_t release_vector(vector_int_t** pp_vector)
{
    vector_int_t* p_vector = NULL;
    if (pp_vector)
    {
        p_vector = *pp_vector;
        if (p_vector)
        {
            free(p_vector->p_data);
            p_vector->p_data = NULL;
        }

        free(p_vector);
        p_vector = NULL;
        *pp_vector = NULL;
    }
    return SUCCESS;
}

status_t push_back(vector_int_t* p_vector, data_t new_data)
{
    if (NULL == p_vector)
    {
        return NULL_PTR;
    }

    if ((p_vector->size+1) > SIZE_MAX / sizeof(data_t))
    {
        return VECTOR_FULL;
    }
    
    if (p_vector->size == p_vector->capacity)
    {
        size_t new_capacity = p_vector->size == 0 ? 2 : p_vector->capacity * 2;

        p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (new_capacity)*sizeof(data_t));
        p_vector->capacity = new_capacity;
    }
    
    p_vector->p_data[p_vector->size] = new_data;
    p_vector->size += 1;
    return SUCCESS;
}

status_t pop_back(vector_int_t* p_vector, data_t* p_popped_data)
{
    if (NULL == p_vector || NULL == p_popped_data)
    {
        return NULL_PTR;
    }

    if (p_vector->size == 0)
    {
        return VECTOR_EMPTY;
    }

    *p_popped_data = p_vector->p_data[--(p_vector->size)];

    if (p_vector->size <= (p_vector->capacity) / 4)
    {
        size_t new_capacity = (p_vector->size) * 2;
        p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (new_capacity)*sizeof(data_t));
        p_vector->capacity = new_capacity;
    }
    
    return SUCCESS;
}

status_t push_front(vector_int_t* p_vector, data_t new_data)
{
    if (NULL == p_vector)
    {
        return NULL_PTR;
    }

    if ((p_vector->size + 1) > SIZE_MAX / sizeof(data_t))
    {
        return VECTOR_FULL;
    }

    if (p_vector->size == p_vector->capacity)
    {
        size_t new_capacity = p_vector->size == 0 ? 2 : p_vector->capacity * 2;

        p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (new_capacity)*sizeof(data_t));
        p_vector->capacity = new_capacity;
    }
    
    (p_vector->size)++;

    //for (int i = p_vector->size-2; i >= 0; --i)
    //{
    //    p_vector->p_data[i+1] = p_vector->p_data[i];
    //}

    memmove(p_vector->p_data + 1, p_vector->p_data, (p_vector->size - 1) * sizeof(data_t));

    p_vector->p_data[0] = new_data;

    return SUCCESS;
}

status_t pop_front(vector_int_t* p_vector, data_t* p_popped_data)
{
    if (NULL == p_vector || NULL == p_popped_data)
    {
        return NULL_PTR;
    }

    if (p_vector->size == 0)
    {
        return VECTOR_EMPTY;
    }

    *p_popped_data = p_vector->p_data[0];

    memmove(p_vector->p_data, (p_vector->p_data+1), (p_vector->size - 1) * sizeof(data_t));

    (p_vector->size)--;

    if (p_vector->size <= (p_vector->capacity) / 4)
    {
        size_t new_capacity = p_vector->size * 2;
        p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (new_capacity)*sizeof(data_t));
        p_vector->capacity = new_capacity;
    }
    
    return SUCCESS;
}

void show(vector_int_t* p_vector, const char* msg)
{
    if (msg)
    {
        printf("%s\n",msg);
    }

    size_t i;
    for (i = 0; i < p_vector->size; ++i)
    {
        printf("array[%zu]:%d,", i, p_vector->p_data[i]);
    }
    printf("\nvector size : %zu\n", p_vector->size);
    printf("vector capacity : %zu\n", p_vector->capacity);
}

void* xmalloc(size_t size_in_bytes)
{
    if (size_in_bytes == 0)
    {
        return NULL;
    }

    void* ptr = malloc(size_in_bytes);

    if (NULL == ptr)    
    {
        fprintf(stderr, "FATAL : malloc() : memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return(ptr);
    
}

void* xrealloc(void* old_ptr, size_t new_size_in_bytes)
{
    // On macOS, when reallocation is called to allocate zero bytes, it returns pointer to the minimum sized object which we need to free
    if (new_size_in_bytes == 0)
    {
        free(old_ptr);
        return NULL;
    }

    void* ptr = realloc(old_ptr, new_size_in_bytes);

    if (NULL == ptr && new_size_in_bytes > 0)
    {
        fprintf(stderr, "FATAL : ralloc : memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return ptr;
}