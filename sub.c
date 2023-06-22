#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 * Description: Subtract top element from second top element and update stack.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	result = top->n - second->n;

	second->n = result;

	*stack = second;
	second->prev = NULL;

	free(top);
}

