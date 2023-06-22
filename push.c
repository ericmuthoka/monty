#include "monty.h"
/**
 * push - push an integer onto the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Description:
 *   - parses the second argument as an integer
 *   - pushes the integer onto the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	int flag = 0;
	int i = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		{
			i++;
		}
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push(stack, line_number);
}

