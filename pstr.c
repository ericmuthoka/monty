#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the Monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int c;

	(void)line_number;

	top = *stack;

	if (top == NULL) {
		printf("\n");
		return;
	}

	while (top != NULL) {
		c = top->n;
		if (c == 0) {
			break;
		}

		if (c < 32 || c > 126) {
			break;
		}

		printf("%c", c);

		top = top->next;
	}

	printf("\n");
}

