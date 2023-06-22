#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the pop opcode is encountered.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

