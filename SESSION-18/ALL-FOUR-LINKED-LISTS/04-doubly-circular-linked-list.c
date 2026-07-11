//  Standard C header files 
#include <stdio.h>      //  For declaration of printf(), puts() 
#include <stdlib.h>     //  For declaration of malloc(), free(), rand(), exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>     //  For declaration of memset() 
#include <assert.h>     //  For definition of assert() macro 
#include <stdbool.h>    //  For definition of bool data type 

//  Symbolic constants 
#define TRUE                    (1) 
#define FALSE                   (0) 
#define SUCCESS                 (1) 
#define LIST_DATA_NOT_FOUND     (-1) 
#define LIST_EMPTY              (-2)
#define INVALID_LIST            (-3)
#define INVALID_ARRAY           (-4)

//  Typedefs 
typedef int data_t; 
typedef int status_t; 
typedef int len_t; 
typedef struct node node_t; 
typedef node_t list_t; 

//  Data layout definitions 
struct node 
{
    data_t data; 
    node_t* prev; 
    node_t* next; 
}; 

//  Interface function declarations 
//  Create & destroy routines 
list_t* create_list(void); 
status_t destroy_list(list_t** pp_list); 

//  Insert Routines 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

//  Get and pop routines 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

//  remove routines 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

//  Miscellaneous routines 
status_t find(list_t* p_list, data_t find_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
status_t show_list(list_t* p_list, const char* msg); 

//  Interlist and advanced functions 
status_t concat_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_concatenated_lists); 
status_t append(list_t* p_list_1, list_t** pp_list_2); 
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_lists); 
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list); 
status_t reverse(list_t* p_list); 
status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_size); 
status_t to_list(data_t* p_array, size_t size, list_t** pp_list); 

//  Auxillary / Helper function declarations
void generic_insert(node_t* beg_node, node_t* mid_node, node_t* end_node);  
void generic_delete(node_t* p_delete_node);
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

    //  Testing of interlist routines 
    list_t* p_list_1 = create_list(); 
    list_t* p_list_2 = create_list(); 

    for(data = 10; data <= 50; data = data + 10)
    {
        status = insert_end(p_list_1, data); 
        assert(status == SUCCESS); 
    }

    for(data = 5; data <= 95; data = data + 10)
    {
        status = insert_end(p_list_2, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list_1, "Initial state of p_list_1:"); 
    show_list(p_list_2, "Initial state of p_list_2:"); 

    list_t* p_concat_list = NULL; 
    status = concat_lists(p_list_1, p_list_2, &p_concat_list); 
    assert(status == SUCCESS); 
    show_list(p_concat_list, "Concatenated list of p_list_1 & p_list_2:"); 

    list_t* p_merged_list = NULL; 
    status = merge_lists(p_list_1, p_list_2, &p_merged_list); 
    assert(status == SUCCESS); 
    show_list(p_merged_list, "Merged list of p_list_1 & p_list_2:"); 

    list_t* p_reversed_list_1 = NULL; 
    status = get_reversed_list(p_list_1, &p_reversed_list_1); 
    assert(status == SUCCESS); 
    show_list(p_reversed_list_1, "Reversed version of p_list_1:"); 

    show_list(p_list_2, "p_list_2 before in-place reversal:"); 
    status = reverse(p_list_2); 
    show_list(p_list_2, "p_list_2 after in-place reversal:"); 

    status = append(p_list_1, &p_list_2); 
    assert(status == SUCCESS && p_list_2 == NULL); 
    show_list(p_list_1, "p_list_1 after appending p_list_2 to it:"); 

    status = destroy_list(&p_list_1); 
    assert(status == SUCCESS && p_list_1 == NULL); 

    puts("p_list_1 destroyed successfully"); 
    puts("Doubly Circular Linked List Testing Succeeded"); 

    exit(EXIT_SUCCESS); 
}

//  Interface functions 
list_t* create_list(void)
{
    list_t* p_list = get_node(0); 
    
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
}

status_t insert_end(list_t* p_list, data_t new_data) 
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    generic_insert(p_list->prev, get_node(new_data), p_list);
    return (SUCCESS); 
}

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    node_t* existing_node = search_node(p_list, existing_data); 
    if(NULL == existing_node)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(existing_node, get_node(new_data), existing_node->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    node_t* existing_node = search_node(p_list, existing_data); 
    if(NULL == existing_node)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(existing_node->prev, get_node(new_data), existing_node); 
    return (SUCCESS); 
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    generic_delete(p_list->next); 

    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    generic_delete(p_list->prev); 

    return (SUCCESS); 
}

status_t remove_start(list_t* p_list)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
}

status_t remove_end(list_t* p_list)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    if(is_list_empty(p_list))
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    node_t* r_node = search_node(p_list, r_data); 
    if(NULL == r_node)
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(r_node); 

    return (SUCCESS); 
}

status_t find(list_t* p_list, data_t find_data)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    node_t* find_node = search_node(p_list, find_data); 

    return (find_node != NULL); 
}

status_t is_list_empty(list_t* p_list)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    return (p_list->prev == p_list && p_list->next == p_list); 
}

len_t get_list_length(list_t* p_list)
{
    len_t len = 0; 
    node_t* run; 

    for(run = p_list->next; run != p_list; run = run->next)
        ++len; 

    return (len);
}

status_t show_list(list_t* p_list, const char* msg)
{
    if(NULL == p_list)  
        return (INVALID_LIST); 

    if(msg)
        puts(msg); 

    printf("[START]<->"); 
    
    node_t* run; 
    for(run = p_list->next; run != p_list; run = run->next)
        printf("[%d]<->", run->data); 
    puts("[END]"); 

    return (SUCCESS); 
}

status_t destroy_list(list_t** pp_list)
{
    if(pp_list)
    {
        list_t* p_list = *pp_list;
        if(p_list)
        {
            node_t* run = p_list->next, *run_next = p_list;
            while(run != p_list)
            {
                run_next = run->next; 
                free(run); 
                run = run_next; 
            } 

            free(p_list); 
            p_list = NULL; 
            *pp_list = NULL; 
        } 
        else 
        {
            return (INVALID_LIST); 
        }
    }
    else 
    {
        return (INVALID_LIST); 
    }

    return (SUCCESS); 
}

//  Immutable concatenation // must do 
status_t concat_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_concatenated_lists)
{
    list_t* p_concat_list = create_list(); 
    node_t* run = NULL; 
    status_t status; 

    if(p_list_1 == NULL || p_list_2 == NULL)
        return (INVALID_LIST); 

    run = p_list_1->next; 
    while(run != p_list_1)
    {
        status = insert_end(p_concat_list, run->data); 
        assert(status == SUCCESS); 
        run = run->next; 
    }

    run = p_list_2->next; 
    while(run != p_list_2)
    {
        status = insert_end(p_concat_list, run->data); 
        assert(status == SUCCESS); 
        run = run->next; 
    }

    *pp_concatenated_lists = p_concat_list; 

    return (SUCCESS); 
}

//  Mutable concatenation 
status_t append(list_t* p_list_1, list_t** pp_list_2)
{
    if(p_list_1 == NULL || pp_list_2 == NULL) 
        return (INVALID_LIST); 

    list_t* p_list_2 = *pp_list_2; 

    if(!is_list_empty(p_list_2))
    {
        p_list_1->prev->next = p_list_2->next; 
        p_list_2->next->prev = p_list_1->prev; 
        p_list_2->prev->next = p_list_1; 
        p_list_1->prev = p_list_2->prev; 
    }

    free(p_list_2); 
    *pp_list_2 = NULL; 

    return (SUCCESS); 
}

//  Merging of two sorted lists 
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_lists)
{
    if(p_list_1 == NULL || p_list_2 == NULL || pp_merged_lists == NULL)
        return (INVALID_LIST); 

    list_t* p_merged_list = create_list(); 

    node_t* run1 = p_list_1->next; 
    node_t* run2 = p_list_2->next;

    status_t status; 

    while(TRUE)
    {
        if(run1 == p_list_1)
        {
            while(run2 != p_list_2)
            {
                status = insert_end(p_merged_list, run2->data); 
                assert(status); 
                run2 = run2->next; 
            }

            break; 
        }

        if(run2 == p_list_2)
        {
            while(run1 != p_list_1)
            {
                status = insert_end(p_merged_list, run1->data); 
                assert(status); 
                run1 = run1->next; 
            }
            break; 
        }

        if(run1->data <= run2->data)
        {
            status = insert_end(p_merged_list, run1->data); 
            assert(status); 
            run1 = run1->next; 
        }
        else 
        {
            status = insert_end(p_merged_list, run2->data); 
            assert(status); 
            run2 = run2->next; 
        }
    }

    *pp_merged_lists = p_merged_list; 

    return (SUCCESS);
}

//  get reversed list // must do 
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list)
{
    if(p_list == NULL || pp_reversed_list == NULL)
        return (INVALID_LIST); 

    list_t* p_reversed_list = create_list();    
    node_t* run = p_list->next; 
    status_t status; 

    while(run != p_list)
    {
        status = insert_start(p_reversed_list, run->data); 
        assert(status); 
        run = run->next; 
    }

    *pp_reversed_list = p_reversed_list; 

    return (SUCCESS);
}

//  inplace reversal of given list 
status_t reverse(list_t* p_list)
{
    if(p_list == NULL)
        return (INVALID_LIST); 

    if(is_list_empty(p_list) || p_list->next->next == p_list)
        return (SUCCESS); 

    node_t* original_first_node = p_list->next; 

    node_t* run = original_first_node->next; 
    node_t* run_next; 

    while(run != p_list)
    {
        run_next = run->next; 
        generic_insert(p_list, run, p_list->next); 
        run = run_next; 
    }

    p_list->prev = original_first_node; 
    original_first_node->next = p_list; 

    return (SUCCESS); 
}

//  to_array // must do 
status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_size)
{
    if(p_list == NULL)
        return (INVALID_LIST); 
    
    if(pp_array == NULL)
        return (INVALID_ARRAY); 

    len_t length = get_list_length(p_list); 
    if(!length)
    {
        *pp_array = NULL; 
        *p_size = 0; 
    }

    data_t* p_array = (data_t*)xmalloc(sizeof(data_t) * length); 

    node_t* run = p_list->next; 
    size_t index = 0; 
    while(run != p_list)
    {
        p_array[index++] = run->data; 
        run = run->next; 
    }

    *pp_array = p_array; 
    *p_size = length; 

    return (SUCCESS); 
}

//  to_list 
status_t to_list(data_t* p_array, size_t size, list_t** pp_list)
{
    status_t status; 

    if(p_array == NULL || size == 0)
    {
        *pp_list = NULL; 
        return (INVALID_ARRAY); 
    } 

    list_t* p_list = create_list();

    for(size_t index = 0; index != size; ++index)
    {
        status = insert_end(p_list, p_array[index]); 
        assert(status);    
    }

    *pp_list = p_list; 

    return (SUCCESS); 
}

//  Helper/auxillary function definitions 

void generic_insert(node_t* beg_node, node_t* mid_node, node_t* end_node)
{
    //  assertion of @PRE-CONDITION 
    assert(beg_node && end_node && mid_node && beg_node->next == end_node && end_node->prev == beg_node); 

    mid_node->next = end_node; 
    mid_node->prev = beg_node; 
    beg_node->next = mid_node; 
    end_node->prev = mid_node; 

    //  assertion of @POST-CONDITION
    assert((beg_node && mid_node && end_node && beg_node->next == mid_node && mid_node->next == end_node &&
            end_node->prev == mid_node && mid_node->prev == beg_node)); 
}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
    p_delete_node = NULL; 
}

node_t* search_node(list_t* p_list, data_t search_data)
{
    node_t* run = p_list->next; 

    while(run != p_list)
    {
        if(run->data == search_data)
            return (run); 
        run = run->next; 
    }

    return (NULL); 
}

node_t* get_node(data_t new_data)
{
    node_t* p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    
    p_new_node->data = new_data; 
    p_new_node->prev = NULL; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL; 

    ptr = malloc(size_in_bytes); 
    if(NULL == ptr)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}