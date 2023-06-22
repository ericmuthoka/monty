#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the push opcode is encountered.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *valueStr = strtok(NULL, " ");

	if (!valueStr)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(valueStr);

	if (value == 0 && *valueStr != '0')
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;

	*stack = newNode;
}

