#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dequeue.h"

int main(void)
{
	dequeue_t* p_dq = NULL;
	data_t data;

	p_dq = create_dequeue();
	assert(p_dq);

	assert(is_dequeue_empty(p_dq) == TRUE);
	assert(peek_front(p_dq, &data) == DEQUEUE_EMPTY);
	assert(peek_rear(p_dq, &data) == DEQUEUE_EMPTY);
	assert(delete_front(p_dq, &data) == DEQUEUE_EMPTY);
	assert(delete_rear(p_dq, &data) == DEQUEUE_EMPTY);

	for(data = 1; data <= 5; ++data)
		assert(insert_rear(p_dq, data * 10) == SUCCESS);
	show_dequeue(p_dq, "After insert_rear 10..50:");

	for(data = 1; data <= 3; ++data)
		assert(insert_front(p_dq, data * 100) == SUCCESS);
	show_dequeue(p_dq, "After insert_front 100,200,300:");

	assert(is_dequeue_empty(p_dq) == FALSE);

	data = -1;
	assert(peek_front(p_dq, &data) == SUCCESS);
	printf("Front: %d\n", data);

	data = -1;
	assert(peek_rear(p_dq, &data) == SUCCESS);
	printf("Rear: %d\n", data);

	assert(delete_front(p_dq, &data) == SUCCESS);
	printf("Deleted front: %d\n", data);
	show_dequeue(p_dq, "After delete_front:");

	assert(delete_rear(p_dq, &data) == SUCCESS);
	printf("Deleted rear: %d\n", data);
	show_dequeue(p_dq, "After delete_rear:");

	while(is_dequeue_empty(p_dq) != TRUE)
	{
		assert(delete_front(p_dq, &data) == SUCCESS);
		printf("Drained: %d\n", data);
	}

	assert(is_dequeue_empty(p_dq) == TRUE);
	assert(destroy_dequeue(&p_dq) == SUCCESS && p_dq == NULL);

	puts("Dequeue: Implementation successful");
	return (EXIT_SUCCESS);
}
