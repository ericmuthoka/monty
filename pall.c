#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the pall opcode is encountered.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number; /* Unused parameter */

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

