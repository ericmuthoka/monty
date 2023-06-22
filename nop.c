#include "monty.h"
/**
 * nop - Does nothing.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 * Description: This opcode doesn't perform any action.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

