#pragma once

#include "list.h"

#define QUEUE_EMPTY LIST_EMPTY

typedef list_t queue_t;

queue_t* create_queue(void);
status_t enqueue(queue_t* p_queue, data_t new_data);
status_t peek(queue_t* p_queue, data_t* p_peek_data);
status_t dequeue(queue_t* p_queue, data_t* p_dequeued_data);
status_t is_queue_empty(queue_t* p_queue);
void show_queue(queue_t* p_queue, const char* msg);
status_t destroy_queue(queue_t** pp_queue);
