#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "prio_queue.h"

int main(void)
{
	prio_queue_t* p_pq = NULL;
	data_t arr[] = {100, 40, 20, 10, 80, 90, 75, 52, 23};
	data_t data;
	int i;

	p_pq = create_prio_queue();
	assert(p_pq);

	assert(is_prio_queue_empty(p_pq) == TRUE);
	assert(prio_dequeue_min(p_pq, &data) == PRIO_QUEUE_EMPTY);

	for(i = 0; i < (int)(sizeof(arr) / sizeof(arr[0])); ++i)
		assert(prio_enqueue(p_pq, arr[i]) == SUCCESS);
	show_prio_queue(p_pq, "After enqueue:");

	assert(is_prio_queue_empty(p_pq) == FALSE);

	puts("Dequeuing in priority order:");
	while(is_prio_queue_empty(p_pq) != TRUE)
	{
		data = -1;
		assert(prio_dequeue_min(p_pq, &data) == SUCCESS);
		printf("  min = %d\n", data);
	}

	assert(is_prio_queue_empty(p_pq) == TRUE);
	assert(destroy_prio_queue(&p_pq) == SUCCESS && p_pq == NULL);

	puts("Priority Queue: Implementation successful");
	return (EXIT_SUCCESS);
}
