#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @value: Value to be pushed.
 * @line_number: Line number where the push opcode is encountered.
 * Return: Pointer to the newly created node.
 */
stack_t *push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

