#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 * Description: If the stack contains less than two elements,
 * it prints an error message and exits with status EXIT_FAILURE.
 * Otherwise, it adds the top two elements and stores the result
 * in the second top element. The top element is then removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	result = second->n + top->n;
	second->n = result;

	*stack = second;
	second->prev = NULL;

	free(top);
}

