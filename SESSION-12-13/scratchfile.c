// Symbolic constants
#define TRUE                      (1)
#define FALSE                     (0)
#define SUCCESS                   (1)
#define LIST_DATA_NOT_FOUND       (-1)
#define LIST_EMPTY                (-2)

// typedefs
typedef int data_t;
typedef int status_t;
typedef struct node node_t;
typedef node_t list_t;
typedef int len_t;

// Data layout definitions
struct node
{
    data_t data;
    node_t* next;
};

//Insert routines
status_t insert_start(list_t* p_list, data_t new_data)
{
    // case 1: lined list is empty
    if (p_list->next == NULL)
    {
        p_list->next = get_node(new_data);
        return SUCCESS;
    }
    else
    {
        node_t* new_node = get_node(new_data);
        new_node->next = p_list->next;
        p_list->next = new_node;
        return SUCCESS;
    }
}

// V2
status_t insert_start(list_t* p_list, data_t new_data)
{
    node_t* new_node = get_node(new_data);

    if (p_list->next == NULL)
    {
        // case 1: lined list is empty
        p_list->next = new_node;
    }
    else
    {
        // case 2 : Lined list is not empty
        new_node->next = p_list->next;
        p_list->next = new_node;
    }

    return SUCCESS;
}

// V3
status_t insert_start(list_t* p_list, data_t new_data)
{
    node_t* new_node = get_node(new_data);

    new_node->next = p_list->next;
    p_list->next = new_node;

    return SUCCESS;
}