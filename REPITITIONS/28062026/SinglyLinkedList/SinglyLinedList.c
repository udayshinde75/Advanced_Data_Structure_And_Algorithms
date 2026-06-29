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
    list_t* p_list = NULL; 
    status_t status; 
    data_t data; 

    p_list = create_list(); 

    show_list(p_list, "List after creation:"); 

    assert(get_start(p_list, &data) == LIST_EMPTY); 
    assert(get_end(p_list, &data) == LIST_EMPTY); 
    assert(pop_start(p_list, &data) == LIST_EMPTY); 
    assert(pop_end(p_list, &data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 

    for(data = 10; data <= 50; data = data + 10)
    {
        status = insert_start(p_list, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list, "List After inserting five elements at start:"); 

    for(data = 60; data <= 100; data += 10)
    {
        status = insert_end(p_list, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list, "Showing list after inserting at end:"); 

    status = insert_after(p_list, -50, 1000); 
    assert(status == LIST_DATA_NOT_FOUND); 

    status = insert_after(p_list, 10, 1000); 
    assert(status == SUCCESS); 

    show_list(p_list, "Showing list after insert_after():"); 

    status = insert_before(p_list, -100, 2000); 
    assert(status == LIST_DATA_NOT_FOUND);

    status = insert_before(p_list, 10, 2000); 
    assert(status == SUCCESS); 

    show_list(p_list, "Showing list after insert_before():"); 

    status = get_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("get_start():start_data = %d\n", data); 
    show_list(p_list, "Showing list after get_start():"); 

    status = get_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("get_end():End data = %d\n", data); 
    show_list(p_list, "Showing list after get_end():"); 

    status = pop_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("pop_start():Poped start_data = %d\n", data); 
    show_list(p_list, "Showing list after pop_start():"); 

    status = pop_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("pop_end():Poped End data = %d\n", data); 
    show_list(p_list, "Showing list after pop_end():"); 
    
    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start():"); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end():"); 

    status = remove_data(p_list, -100); 
    assert(status == LIST_DATA_NOT_FOUND); 

    status = remove_data(p_list, 10); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_data():"); 

    bool find_status = find(p_list, -100); 
    printf("find_status for -100 in p_list:%d\n", find_status); 

    find_status = find(p_list, 60); 
    printf("find_status for 60 in p_list:%d\n", find_status); 

    bool empty_status = is_list_empty(p_list); 
    printf("Empty status for p_list:%d\n", empty_status);

    len_t list_length = get_list_length(p_list); 
    printf("Length of p_list: %d\n", list_length); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 
    puts("The linked list destroyed successfully"); 

    exit(EXIT_SUCCESS); 
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
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    while (run != NULL)
    {
        if (run->data == existing_data)
        {
            break;
        }
        run_prev = run;
        run = run->next;
    }
    if (NULL == run)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    node_t* new_node = get_node(new_data);

    new_node->next = run;
    run_prev->next = new_node;

    return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if (NULL == p_list)
    {
        return (INVALID_LIST);
    }

    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }

    *p_start_data = p_list->next->data;
    
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if (NULL == p_list)
    {
        return (INVALID_LIST);
    }

    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }
    
    node_t* run = p_list->next;
    while (run->next != NULL)
    {
        run = run->next;
    }
    *p_end_data = run->data;
    return (SUCCESS);  
}
status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if (NULL == p_list)
    {
        return (INVALID_LIST);
    }
    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }

    *p_start_data = p_list->next->data;
    node_t* node_to_remove = p_list->next;
    p_list->next = node_to_remove->next;
    free(node_to_remove);
    return (SUCCESS);
}
status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if (NULL == p_list)
    {
        return (INVALID_LIST);
    }
    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }
    
    node_t* run = p_list->next;
    node_t* run_prev = p_list;

    while (run->next != NULL)
    {
        run_prev = run;
        run = run->next;
    }
    *p_end_data = run->data;
    run_prev->next = NULL;
    free(run);

    return (SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }
    node_t* node_to_remove = p_list->next;
    p_list->next = node_to_remove->next;
    free(node_to_remove);

    return (SUCCESS);
}
status_t remove_end(list_t* p_list)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    if (p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }
    node_t* run = p_list->next;
    node_t* run_prev = p_list;

    while (run->next != NULL)
    {
        run_prev = run;
        run = run->next;
    }
    run_prev->next = NULL;
    free(run);
    return (SUCCESS);
}
status_t remove_data(list_t* p_list, data_t r_data)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    node_t* run = p_list->next;
    node_t* run_prev = p_list;

    while (run != NULL)
    {
        if (run->data == r_data)
        {
            break;
        }
        run_prev = run;
        run = run->next;
    }
    if (NULL == run)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    run_prev->next = NULL;
    free(run);
    return (SUCCESS);
}

status_t find(list_t* p_list, data_t find_data)
{
    node_t* run =  NULL;
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    run = search_node(p_list, find_data);
    return(run != NULL);
}
status_t is_list_empty(list_t* p_list)
{
    if(p_list == NULL)
        return (INVALID_LIST); 

    return (p_list->next == NULL); 
}
len_t get_list_length(list_t* p_list)
{
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    len_t node_counter = 0;
    node_t* run = NULL;

    run = p_list->next;

    while (run != NULL)
    {
        node_counter+=1;
        run = run->next;
    }
    return (node_counter);
}
status_t show_list(list_t* p_list, const char* msg)
{
    node_t* run = NULL; 

    if(p_list == NULL)
        return (INVALID_LIST); 


    if(msg != NULL)
        puts(msg); 

    printf("[START]->"); 

    run = p_list->next; 
    while(run != NULL)
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }

    printf("[END]\n"); 

    return (SUCCESS);
}
status_t destroy_list(list_t** pp_list)
{
    node_t* run = NULL;
    node_t* run_next = NULL;
    list_t* p_list = NULL;

    if (*pp_list != NULL)
    {
        p_list = *pp_list;
    }
    else
    {
        return (INVALID_LIST);
    }
    
    run = p_list->next;
    while (run != NULL)
    {
        run_next = run->next;
        free(run);
        run = run_next;
    }
    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}

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
    
    return (run);
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

