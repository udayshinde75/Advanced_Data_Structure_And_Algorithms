// Standard C header files
#include <stdio.h>   // for declaration of printf(), puts().
#include <stdlib.h>  // for malloc, free, rand, exit, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>  // for memset
#include <assert.h>  // for definition of assert() macro.
#include <stdbool.h> // for bool

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

// Interface function declaration

/// @brief function name : create_list();   
/// @return function creates a new instance of a singly linked list by allocationg a dummy node, initializing the data member and the next member to 0 and NULL respectively and returns the address of the allocated node
list_t* create_list(void);

//Insert routines

/// @brief insert start function allocates new node containing @new_data and attaches it as the starting position of the list pointed by @p_list
/// @param p_list which linked list
/// @param new_data which data value to be added
/// @return status of function
status_t insert_start(list_t* p_list, data_t new_data);

/// @brief insert end function allocates new node containing @new_data and attaches it as the ending position of the list pointed by @p_list
/// @param p_list which linked list
/// @param new_data which data value to be added
/// @return status of function
status_t insert_end(list_t* p_list, data_t new_data);

/// @brief the algorithm searches @p_list for the occurances of @existing_data. if search fails it returns an error code LIST_DAT_NOT_FOUND. it allocates new node, populates it with @new_data and inserts a new node after existing node in the @p_list contaiing the first occurence of @existing_data and returns the status
/// @param p_list which linked list
/// @param existing_data existing data in the linked list after which @new_data must be inserted
/// @param new_data new data value to be inserted
/// @return status of the function
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);

/// @brief the algorithm searches @p_list for the occurances of @existing_data. if search fails it returns an error code LIST_DAT_NOT_FOUND. it allocates new node, populates it with @new_data and inserts a new node before existing node in the @p_list contaiing the first occurence of @existing_data and returns the status
/// @param p_list which linked list
/// @param existing_data existing data in the linked list after which @new_data must be inserted
/// @param new_data new data value to be inserted
/// @return status of the function
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);

// Get And pop routines

/// @brief Check if the p_list is empty. If true, return LIST_EMPTY. Otherwise, return data from firt node with data node via @p_start_data and return SUCCESS
/// @param p_list which linked list
/// @param p_start_data this is an out parameter. address of data_t variable used to return the start data
/// @return Status of the function
status_t get_start(list_t* p_list, data_t* p_start_data);

/// @brief Check if the p_list is empty. If true, return LIST_EMPTY. Otherwise, return data from last node with data node via @p_end_data and return SUCCESS
/// @param p_list which linked list
/// @param p_start_data this is an out parameter. address of data_t variable used to return the start data
/// @return Status of the function
status_t get_end(list_t* p_list, data_t* p_end_data);

/// @brief Check if the p_list is empty. If true, return LIST_EMPTY. Otherwise, return data from firt node with data node via @p_start_data, delete the first with data and return SUCCESS
/// @param p_list which linked list
/// @param p_start_data this is an out parameter. address of data_t variable used to return the start data
/// @return Status of the function
status_t pop_start(list_t* p_list, data_t* p_start_data);

/// @brief Check if the p_list is empty. If true, return LIST_EMPTY. Otherwise, return data from last node with data node via @p_end_data ,delete the last with dataand return SUCCESS
/// @param p_list which linked list
/// @param p_start_data this is an out parameter. address of data_t variable used to return the start data
/// @return Status of the function
status_t pop_end(list_t* p_list, data_t* p_end_data);

// Remove routines

/// @brief check if the p_list is emoty. if true then return error code list_empty. Other wise delete the first node with data and return success
/// @param p_list which linked list
/// @return status of function
status_t remove_start(list_t* p_list);

/// @brief check if the p_list is emoty. if true then return error code list_empty. Other wise delete the last node with data and return success
/// @param p_list which linked list
/// @return status of function
status_t remove_end(list_t* p_list);

/// @brief Search for the occurance of r_data in the lis. if not found retunr LIST_DATA_NOT_FOUND. Else the delete the first node of the first occurance will be removed
/// @param p_list which linked list
/// @param r_data data value to be removed from p*list
/// @return status of function
status_t remove_data(list_t* p_list, data_t r_data);

//Miscellaneous routines

/// @brief searches @find_data in the @p_list. if found returns true, false otherwise
/// @param p_list which linked list
/// @param find_data data value whose membership must be checked int the @p_list
/// @return bool value
bool find(list_t* p_list, data_t find_data);

/// @brief checks if there is any other node than the dummy node
/// @param p_list which linked list
/// @return bool value
bool is_list_empty(list_t* p_list);

/// @brief Counts the total number of nodes excluding the dummy nofe and returns the count
/// @param p_list which linked list
/// @return len_t value
len_t get_list_length(list_t* p_list);

/// @brief prints the list on console by going through all non dummy nodes.
/// @param p_list which linked list
/// @param msg message to be displayed
void show_list(list_t* p_list, const char* msg);

// destroy

/// @brief Get the address of the headnode of the linked list to be destroyed by derefernencing pp_list. Free all nodes including the dummy node. Write NULL in the pointer variable whoes ddress present in @pp_list. Return SUCCESS
/// @param pp_list Address of headenode of the linked list to be destroyed.
/// @return status
status_t destroy_list(list_t** pp_list);

// helper

/// @brief search for search_data in the @p_list. if found return the address of the furst node
/// @param p_list Which linked list
/// @param search_data data element to be searched
/// @return node_t*
node_t* search_node(list_t* p_list, data_t search_data);

/// @brief allocate a new dynamic instance of node_t and store new_data in its data member and return the address to the newly allocated node.
/// @param new_data 
/// @return node_t*
node_t* get_node(data_t new_data);

/// @brief Allocate dyanmic memory block of @size_in_bytes bytes on heap using malloc. do the sanity check for the return value of malloc. if the sanity fails emit error on std error device and exit from the application
/// @param size_in_bytes 
/// @return pointer
void* xmalloc(size_t size_in_bytes);



int main()
{
    return 0;
}
