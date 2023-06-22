#include "monty.h"
/**
 * push - Adds a node to the stack.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: The line number where the push operation is being performed.
 * Return: No return value.
 */
static void push(stack_t **stack, unsigned int line_number)
{
	if (!bus.arg) {
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	int value = atoi(bus.arg);
	stack_push(stack, value, line_number);
}

