#pragma once

#include "list.h"

#define STACK_EMPTY LIST_EMPTY

typedef list_t stack_t;

stack_t* create_stack(void);
status_t push(stack_t* p_stack, data_t new_data);
status_t top(stack_t* p_stack, data_t* p_top_data);
status_t pop(stack_t* p_stack, data_t* p_pop_data);
status_t is_stack_empty(stack_t* p_stack);
void show_stack(stack_t* p_stack, const char* msg);
status_t destroy_stack(stack_t** pp_stack);
