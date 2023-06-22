#include "monty.h"

/**
 * sub - Subtracts top element of stack from the second top element.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

