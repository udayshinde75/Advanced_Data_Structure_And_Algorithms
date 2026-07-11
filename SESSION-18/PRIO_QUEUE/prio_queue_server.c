#include "prio_queue.h"

prio_queue_t* create_prio_queue(void)
{
	return (create_list());
}

status_t prio_enqueue(prio_queue_t* p_prio_queue, data_t new_data)
{
	return (insert_end(p_prio_queue, new_data));
}

status_t prio_dequeue_min(prio_queue_t* p_prio_queue, data_t* p_min_data)
{
	node_t* p_run = NULL;
	node_t* p_min_node = NULL;
	data_t current_min;

	if(is_prio_queue_empty(p_prio_queue) == TRUE)
		return (PRIO_QUEUE_EMPTY);

	p_min_node = p_prio_queue->next;
	current_min = p_min_node->data;

	for(p_run = p_prio_queue->next; p_run != (node_t*)p_prio_queue; p_run = p_run->next)
	{
		if(p_run->data < current_min)
		{
			current_min = p_run->data;
			p_min_node = p_run;
		}
	}

	*p_min_data = current_min;

	p_min_node->prev->next = p_min_node->next;
	p_min_node->next->prev = p_min_node->prev;
	free(p_min_node);

	return (SUCCESS);
}

status_t is_prio_queue_empty(prio_queue_t* p_prio_queue)
{
	return (is_list_empty(p_prio_queue));
}

void show_prio_queue(prio_queue_t* p_prio_queue, const char* msg)
{
	show_list(p_prio_queue, msg);
}

status_t destroy_prio_queue(prio_queue_t** pp_prio_queue)
{
	return (destroy_list(pp_prio_queue));
}
