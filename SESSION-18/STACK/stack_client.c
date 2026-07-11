#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main(void)
{
	stack_t* p_stack = NULL;
	data_t data;

	p_stack = create_stack();
	assert(p_stack);

	assert(is_stack_empty(p_stack) == TRUE);
	assert(top(p_stack, &data) == STACK_EMPTY);
	assert(pop(p_stack, &data) == STACK_EMPTY);

	for(data = 0; data < 10; ++data)
		assert(push(p_stack, data) == SUCCESS);
	show_stack(p_stack, "After pushing 0..9:");

	data = -1;
	assert(top(p_stack, &data) == SUCCESS);
	printf("Top data: %d\n", data);

	assert(is_stack_empty(p_stack) == FALSE);

	while(is_stack_empty(p_stack) != TRUE)
	{
		assert(pop(p_stack, &data) == SUCCESS);
		printf("Popped: %d\n", data);
	}

	assert(is_stack_empty(p_stack) == TRUE);
	assert(destroy_stack(&p_stack) == SUCCESS && p_stack == NULL);

	puts("Stack: Implementation successful");
	return (EXIT_SUCCESS);
}
