#include "dequeue.h"

dequeue_t* create_dequeue(void)
{
	return (create_list());
}

status_t insert_front(dequeue_t* p_dequeue, data_t new_data)
{
	return (insert_start(p_dequeue, new_data));
}

status_t insert_rear(dequeue_t* p_dequeue, data_t new_data)
{
	return (insert_end(p_dequeue, new_data));
}

status_t delete_front(dequeue_t* p_dequeue, data_t* p_data)
{
	return (pop_start(p_dequeue, p_data));
}

status_t delete_rear(dequeue_t* p_dequeue, data_t* p_data)
{
	return (pop_end(p_dequeue, p_data));
}

status_t peek_front(dequeue_t* p_dequeue, data_t* p_data)
{
	return (get_start(p_dequeue, p_data));
}

status_t peek_rear(dequeue_t* p_dequeue, data_t* p_data)
{
	return (get_end(p_dequeue, p_data));
}

status_t is_dequeue_empty(dequeue_t* p_dequeue)
{
	return (is_list_empty(p_dequeue));
}

void show_dequeue(dequeue_t* p_dequeue, const char* msg)
{
	show_list(p_dequeue, msg);
}

status_t destroy_dequeue(dequeue_t** pp_dequeue)
{
	return (destroy_list(pp_dequeue));
}
