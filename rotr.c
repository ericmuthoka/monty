#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack (head)
 * @line_number: current line number in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *temp;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		temp = last->prev;
		temp->next = NULL;

		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}

