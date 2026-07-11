#pragma once

#include "list.h"

#define DEQUEUE_EMPTY LIST_EMPTY

typedef list_t dequeue_t;

dequeue_t* create_dequeue(void);
status_t insert_front(dequeue_t* p_dequeue, data_t new_data);
status_t insert_rear(dequeue_t* p_dequeue, data_t new_data);
status_t delete_front(dequeue_t* p_dequeue, data_t* p_data);
status_t delete_rear(dequeue_t* p_dequeue, data_t* p_data);
status_t peek_front(dequeue_t* p_dequeue, data_t* p_data);
status_t peek_rear(dequeue_t* p_dequeue, data_t* p_data);
status_t is_dequeue_empty(dequeue_t* p_dequeue);
void show_dequeue(dequeue_t* p_dequeue, const char* msg);
status_t destroy_dequeue(dequeue_t** pp_dequeue);
