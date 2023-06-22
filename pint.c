#include "monty.h"
/**
 * pint - pint the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Description:
 *   - checks if the stack is empty
 *   - if not, prints the value at the top of the stack
 *   - if the stack is empty, prints an error message and exits
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	printf("%d\n", top->n);
}

