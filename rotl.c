#include "monty.h"

/**
 * rotl - Rotate the stack to the top
 * @stack: Double pointer to the top of the stack
 */
void rotl(stack_t **stack)
{
	stack_t *top = *stack;
	stack_t *second = top->next;

	if (top == NULL || second == NULL) {
		return;
	}

	/* Move the top element to the end of the stack */
	second->next = top->next;
	top->next = NULL;

	/* Move the second element to the top of the stack */
	*stack = second;

	/* Update the prev pointer of the second element */
	second->prev = NULL;
}

