#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// Hash Table interface
hashq_t* create_hashq(size_t bucket_size)
{
    hashq_t* p_hashq = NULL;
    size_t i;

    if (bucket_size == 0)
    {
        return NULL;
    }
    
    p_hashq = (hashq_t*)xmalloc(sizeof(hashq_t));
    p_hashq->pp_list_arr = (list_t**)xmalloc(bucket_size*sizeof(list_t*));
    p_hashq->bucket_size = bucket_size;

    for (i = 0; i < bucket_size; ++i)
    {
        p_hashq->pp_list_arr[i] = create_list();
    }

    return (p_hashq);
}
status_t add_key(hashq_t* p_hashq, hkey_t key)
{
    size_t bucket_number;
    bucket_number = hash(key, p_hashq->bucket_size);
    return (insert_end(p_hashq->pp_list_arr[bucket_number], key));
}
status_t remove_key(hashq_t* p_hashq, hkey_t key)
{
    size_t bucket_number;
    node_t* p_node;

    bucket_number = hash(key, p_hashq->bucket_size);
    p_node = search_node(p_hashq->pp_list_arr[bucket_number], key);

    if (p_node == NULL)
    {
        return (BAD_KEY);
    }
    
    generic_delete(p_node);

    return(SUCCESS);
}
status_t search_key(hashq_t* p_hashq, hkey_t key)
{
    return (search_data(p_hashq->pp_list_arr[hash(key, p_hashq->bucket_size)], key));
}
void hash_stat(hashq_t* p_hashq)
{
    size_t i;
    printf("Bucket Size = %zu\n", p_hashq->bucket_size);
    for ( i = 0; i < p_hashq->bucket_size; i++)
    {
        printf("Bucket[%zu]:%zu\n", i, get_list_length(p_hashq->pp_list_arr[i]));
    }
}
status_t destroy_hashq(hashq_t** pp_hashq)
{
    hashq_t* p_hashq = NULL;
    size_t i;

    p_hashq = *pp_hashq;
    for (i = 0; i < p_hashq->bucket_size; i++)
    {
        destroy_list(p_hashq->pp_list_arr[i]);
    }
    free(p_hashq->pp_list_arr);
    free(p_hashq);

    *pp_hashq = NULL;

    return(SUCCESS);
}


/* Internal list routines */
list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(0);
    p_list->next = p_list;
    p_list->prev = p_list;

    return p_list;
}
status_t insert_end(list_t* p_list, hkey_t key);
status_t remove_data(list_t* p_list, hkey_t key);
status_t search_data(list_t* p_list, hkey_t key);
node_t* search_node(list_t* p_list, hkey_t key);
len_t get_list_length(list_t* p_list);
status_t destroy_list(list_t* p_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;
    
    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }
    free(p_list);
    return(SUCCESS);
}
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}
void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
}
node_t* get_node(hkey_t key)
{
    node_t* p_node = NULL;
    p_node = (node_t*)xmalloc(sizeof(node_t));
    p_node->key = key;
    p_node->next = NULL;
    p_node->prev = NULL;
    return p_node;
}
void* xmalloc(size_t nr_bytes)
{
    void* p = NULL;
    p = malloc(nr_bytes);
    if (p == NULL && nr_bytes != 0)
    {
        fprintf(stderr, "FATAL: Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return p;
}