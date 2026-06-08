#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

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
    p_vector->p_data = (data_t*)xrealloc(p_vector->p_data, (p_vector->size+1)*sizeof(data_t));
    p_vector->size += 1;
    p_vector->p_data[p_vector->size - 1] = new_data;
    return SUCCESS;
}

status_t pop_back(vector_int_t* p_vector, data_t* p_popped_data)
{

}
status_t push_front(vector_int_t* p_vector, data_t new_data);
status_t pop_front(vector_int_t* p_vector, data_t* p_popped_data);

void show(vector_int_t* p_vector, const char* msg);

void* xmalloc(size_t size_in_bytes)
{
    
}
void* xrealloc(void* old_ptr, size_t new_size_in_bytes);