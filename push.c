#include "monty.h"
/**
 * push - Adds a node to the stack.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: The line number where the push operation is being performed.
 * Return: No return value.
 */
void push(stack_t **stack, unsigned int line_number)
{
	{
		int value;

		if (argc != 2)
		{
			print_error(line_number, "usage: push integer");
			exit(EXIT_FAILURE);
		}

		value = atoi(argv[1]);

		stack_push(stack, value);
	}
}

