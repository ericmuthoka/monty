#include "monty.h"
/**
 * pchar - Print char at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the opcode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}

