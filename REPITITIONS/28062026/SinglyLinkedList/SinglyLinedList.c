#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define TRUE (1)
#define FALSE (0)
#define SUCCESS (1)
#define LIST_DATA_NOT_FOUND (-1)
#define LIST_EMPTY (-2)
#define INVALID_LIST (-3)

typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    node_t* next;
};

list_t* create_list(void);

status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

status_t find(list_t* p_list, data_t find_data);
status_t is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
status_t show_list(list_t* p_list, const char* msg);
status_t destroy_list(list_t** p_list);

node_t* search_node(list_t* p_list, data_t search_data);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size_in_bytes);

int main(void)
{

}

list_t* create_list(void)
{
    return get_node(0);
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    node_t* new_node = get_node(new_data);

    new_node->next = p_list->next;
    p_list->next = new_node;

    return SUCCESS;
}
status_t insert_end(list_t* p_list, data_t new_data)
{
    if (p_list ==NULL)
    {
        return (INVALID_LIST);
    }

    node_t* run = p_list;
    while (run->next != NULL)
    {
        run = run->next;
    }
    node_t* new_node = get_node(new_data);
    run->next = new_node;

    return (SUCCESS);
}
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    node_t* existing_node = search_node(p_list, existing_data);
    if (existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    node_t* new_node = get_node(new_data);
    new_node->next = existing_node -> next;
    existing_node->next = new_node;

    return(SUCCESS);
}
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

status_t find(list_t* p_list, data_t find_data);
status_t is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
status_t show_list(list_t* p_list, const char* msg);
status_t destroy_list(list_t** p_list);

node_t* search_node(list_t* p_list, data_t search_data)
{
    if (p_list == NULL)
    {
        return (NULL);
    }
    
    node_t* run = NULL;

    run = p_list->next;
    while (run != NULL)
    {
        if (run->data == search_data)
        {
            break;
        }
        run = run->next;
    }
    
    return (NULL);
}
node_t* get_node(data_t new_data)
{
    node_t* node = NULL;
    node = (node_t*)xmalloc(sizeof(node_t));
    node->data = new_data;
    node->next = NULL;
    return node;
}
void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;
    ptr = malloc(size_in_bytes);
    if (NULL == ptr && size_in_bytes != 0)
    {
        fprintf(stderr, "FATAL : mallac() out of memory");
        exit (EXIT_FAILURE);
    }
    
    return(ptr);
}

