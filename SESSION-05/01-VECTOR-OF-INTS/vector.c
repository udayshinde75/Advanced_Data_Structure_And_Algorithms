#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

vector_int_t* create_vector(void)
{
    vector_int_t* p_new_vector = NULL;
    p_new_vector = (vector_int_t*)xmalloc(sizeof(vector_int_t));
    p_new_vector->p_data = NULL;
    p_new_vector->size = 0;
    return (p_new_vector);
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
    p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (p_vector->size+1)*sizeof(data_t));
    p_vector->size += 1;
    p_vector->p_data[p_vector->size - 1] = new_data;
    return SUCCESS;
}

void show(vector_int_t* p_vector, const char* msg)
{
    if (msg)
    {
        printf("%s",msg);
    }

    int i;
    for (i = 0; i < p_vector->size; ++i)
    {
        printf("array[%d]:%d\n", i, p_vector->p_data[i]);
    }
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;
    ptr = malloc(size_in_bytes);
    if (NULL == ptr)
    {
        fprintf(stderr, "fatal:malloc errrrrrrrrrr");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}
void* xrealloc(void* old_ptr, size_t new_size_in_bytes)
{
    void* ptr = NULL;
    ptr = realloc(old_ptr, new_size_in_bytes);
    if (NULL == ptr)
    {
        fprintf(stderr, "fatal:ralloc errrrrrrrrrr");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}