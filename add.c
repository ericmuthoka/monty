#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number of the instruction being executed.
 *
 * Description: If the stack has less than 2 elements, prints an error
 * and exits. Otherwise, pops the top two elements, adds the values,
 * and pushes the result back to the stack.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	result = temp->n;
	free(temp);

	temp = *stack;
	*stack = (*stack)->next;
	result += temp->n;
	free(temp);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = result;
	temp->next = *stack;
	*stack = temp;
}

