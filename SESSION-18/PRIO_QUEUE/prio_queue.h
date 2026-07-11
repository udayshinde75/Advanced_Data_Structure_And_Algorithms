#pragma once

#include "list.h"

#define PRIO_QUEUE_EMPTY LIST_EMPTY

typedef list_t prio_queue_t;

prio_queue_t* create_prio_queue(void);
status_t prio_enqueue(prio_queue_t* p_prio_queue, data_t new_data);
status_t prio_dequeue_min(prio_queue_t* p_prio_queue, data_t* p_min_data);
status_t is_prio_queue_empty(prio_queue_t* p_prio_queue);
void show_prio_queue(prio_queue_t* p_prio_queue, const char* msg);
status_t destroy_prio_queue(prio_queue_t** pp_prio_queue);
