#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Forward declarations — internal helpers */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete);
static node_t* search_node(list_t* p_list, data_t s_data);
static node_t* get_node(data_t new_data);
static void* xmalloc(size_t nr_bytes);

/* Interface Routines */

list_t* create_list(void)
{
	node_t* p_head_node = NULL;

	p_head_node = get_node(0);
	p_head_node->prev = p_head_node;
	p_head_node->next = p_head_node;

	return (p_head_node);
}

status_t insert_start(list_t* p_list, data_t new_data)
{
	generic_insert(p_list, get_node(new_data), p_list->next);
	return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_node(new_data), p_list);
	return (SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* p_existing = NULL;

	p_existing = search_node(p_list, e_data);
	if(p_existing == NULL)
		return (LIST_DATA_NOT_FOUND);
	generic_insert(p_existing, get_node(new_data), p_existing->next);

	return (SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* p_existing = NULL;

	p_existing = search_node(p_list, e_data);
	if(p_existing == NULL)
		return (LIST_DATA_NOT_FOUND);
	generic_insert(p_existing->prev, get_node(new_data), p_existing);

	return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	*p_start_data = p_list->next->data;
	return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	*p_end_data = p_list->prev->data;
	return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	*p_start_data = p_list->next->data;
	generic_delete(p_list->next);

	return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	*p_end_data = p_list->prev->data;
	generic_delete(p_list->prev);

	return (SUCCESS);
}

status_t remove_start(list_t* p_list)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	generic_delete(p_list->next);
	return (SUCCESS);
}

status_t remove_end(list_t* p_list)
{
	if(is_list_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	generic_delete(p_list->prev);
	return (SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
	node_t* p_node = NULL;

	p_node = search_node(p_list, r_data);
	if(p_node == NULL)
		return (LIST_DATA_NOT_FOUND);
	generic_delete(p_node);

	return (SUCCESS);
}

status_t clear_list(list_t* p_list)
{
	node_t* p_run = NULL;
	node_t* p_run_next = NULL;

	for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
	{
		p_run_next = p_run->next;
		free(p_run);
	}
	p_list->prev = p_list;
	p_list->next = p_list;

	return (SUCCESS);
}

status_t is_list_empty(list_t* p_list)
{
	return (p_list->prev == p_list && p_list->next == p_list);
}

status_t find_in_list(list_t* p_list, data_t f_data)
{
	return (search_node(p_list, f_data) != NULL);
}

len_t get_list_length(list_t* p_list)
{
	node_t* p_run = NULL;
	len_t len = 0;

	for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
		++len;

	return (len);
}

void show_list(list_t* p_list, const char* msg)
{
	node_t* p_run = NULL;

	if(msg)
		puts(msg);

	printf("[START]<->");
	for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
		printf("[%d]<->", p_run->data);
	puts("[END]");
}

status_t destroy_list(list_t** pp_list)
{
	list_t* p_list = NULL;
	node_t* p_run = NULL;
	node_t* p_run_next = NULL;

	p_list = *pp_list;
	for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
	{
		p_run_next = p_run->next;
		free(p_run);
	}

	free(p_list);
	*pp_list = NULL;

	return (SUCCESS);
}

list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2)
{
	list_t* p_new_list = NULL;
	node_t* p_run = NULL;

	p_new_list = create_list();
	for(p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
		insert_end(p_new_list, p_run->data);
	for(p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
		insert_end(p_new_list, p_run->data);

	return (p_new_list);
}

status_t concat_lists(list_t* p_list_1, list_t** pp_list_2)
{
	list_t* p_list_2 = NULL;

	p_list_2 = *pp_list_2;

	if(is_list_empty(p_list_2) == TRUE)
	{
		free(p_list_2);
		*pp_list_2 = NULL;
		return (SUCCESS);
	}

	p_list_1->prev->next = p_list_2->next;
	p_list_2->next->prev = p_list_1->prev;
	p_list_2->prev->next = p_list_1;
	p_list_1->prev = p_list_2->prev;

	free(p_list_2);
	*pp_list_2 = NULL;

	return (SUCCESS);
}

list_t* merge_lists(list_t* p_list_1, list_t* p_list_2)
{
	node_t* p_run_1 = NULL;
	node_t* p_run_2 = NULL;
	list_t* p_merged = NULL;

	p_merged = create_list();
	p_run_1 = p_list_1->next;
	p_run_2 = p_list_2->next;

	while(TRUE)
	{
		if(p_run_1 == p_list_1)
		{
			for(; p_run_2 != p_list_2; p_run_2 = p_run_2->next)
				insert_end(p_merged, p_run_2->data);
			break;
		}

		if(p_run_2 == p_list_2)
		{
			for(; p_run_1 != p_list_1; p_run_1 = p_run_1->next)
				insert_end(p_merged, p_run_1->data);
			break;
		}

		if(p_run_1->data <= p_run_2->data)
		{
			insert_end(p_merged, p_run_1->data);
			p_run_1 = p_run_1->next;
		}
		else
		{
			insert_end(p_merged, p_run_2->data);
			p_run_2 = p_run_2->next;
		}
	}

	return (p_merged);
}

list_t* get_reversed_list(list_t* p_list)
{
	list_t* p_reversed = NULL;
	node_t* p_run = NULL;

	p_reversed = create_list();
	for(p_run = p_list->prev; p_run != p_list; p_run = p_run->prev)
		insert_end(p_reversed, p_run->data);

	return (p_reversed);
}

status_t reverse_list(list_t* p_list)
{
	node_t* p_run = NULL;
	node_t* p_run_next = NULL;
	node_t* p_temp = NULL;

	if(p_list->next == p_list || p_list->next->next == p_list)
		return (SUCCESS);

	for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
	{
		p_run_next = p_run->next;
		p_temp = p_run->next;
		p_run->next = p_run->prev;
		p_run->prev = p_temp;
	}

	p_temp = p_list->next;
	p_list->next = p_list->prev;
	p_list->prev = p_temp;

	return (SUCCESS);
}

void to_array(list_t* p_list, data_t** pp_array, len_t* p_length)
{
	data_t* p_array = NULL;
	node_t* p_run = NULL;
	len_t len = 0;
	int i = 0;

	len = get_list_length(p_list);
	if(len == 0)
	{
		*pp_array = NULL;
		*p_length = 0;
		return;
	}

	p_array = (data_t*)xmalloc(len * sizeof(data_t));
	for(p_run = p_list->next, i = 0; p_run != p_list; p_run = p_run->next, ++i)
		p_array[i] = p_run->data;

	*pp_array = p_array;
	*p_length = len;
}

list_t* to_list(data_t* p_array, len_t length)
{
	list_t* p_list = NULL;
	len_t i;

	p_list = create_list();
	for(i = 0; i < length; ++i)
		insert_end(p_list, p_array[i]);

	return (p_list);
}

/* Internal Helper Routines */

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->next = p_end;
	p_mid->prev = p_beg;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete)
{
	p_delete->prev->next = p_delete->next;
	p_delete->next->prev = p_delete->prev;
	free(p_delete);
}

static node_t* search_node(list_t* p_list, data_t s_data)
{
	node_t* p_run = NULL;

	for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
		if(p_run->data == s_data)
			return (p_run);

	return (NULL);
}

static node_t* get_node(data_t new_data)
{
	node_t* p_node = NULL;

	p_node = (node_t*)xmalloc(sizeof(node_t));
	p_node->data = new_data;
	p_node->prev = NULL;
	p_node->next = NULL;

	return (p_node);
}

static void* xmalloc(size_t nr_bytes)
{
	void* p = NULL;

	p = malloc(nr_bytes);
	if(p == NULL)
	{
		fprintf(stderr, "fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}

	return (p);
}
