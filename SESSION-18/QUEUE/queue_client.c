#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main(void)
{
	queue_t* p_queue = NULL;
	data_t data;

	p_queue = create_queue();
	assert(p_queue);

	assert(is_queue_empty(p_queue) == TRUE);
	assert(peek(p_queue, &data) == QUEUE_EMPTY);
	assert(dequeue(p_queue, &data) == QUEUE_EMPTY);

	for(data = 0; data < 8; ++data)
		assert(enqueue(p_queue, (data + 1) * 10) == SUCCESS);
	show_queue(p_queue, "After enqueue 10..80:");

	assert(is_queue_empty(p_queue) == FALSE);

	data = -1;
	assert(peek(p_queue, &data) == SUCCESS);
	printf("Front: %d\n", data);

	while(is_queue_empty(p_queue) != TRUE)
	{
		assert(dequeue(p_queue, &data) == SUCCESS);
		printf("Dequeued: %d\n", data);
	}

	assert(is_queue_empty(p_queue) == TRUE);
	assert(destroy_queue(&p_queue) == SUCCESS && p_queue == NULL);

	puts("Queue: Implementation successful");
	return (EXIT_SUCCESS);
}
