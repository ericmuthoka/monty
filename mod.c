#include "monty.h"
/**
 * mod - Computes the rest of the div of the 2nd top element by the top element
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the mod opcode is encountered.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top, second_top;
	/* Check if stack is too short */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second_top = (*stack)->next->n;
	top = (*stack)->n;

	/* Check for division by zero */
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Compute modulo and update stack */
	(*stack)->next->n = second_top % top;
	pop(stack, line_number);
}

