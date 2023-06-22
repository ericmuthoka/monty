#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 * Description: If the stack contains fewer than two elements,
 * it prints an error message and exits with status EXIT_FAILURE.
 * Otherwise, it swaps the values of the top two elements on the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	/* Swap the values of top and second */
	temp = top->n;
	top->n = second->n;
	second->n = temp;
}

