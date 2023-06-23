#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char line[MAX_LINE_LENGTH];
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				int value;

				value = atoi(strtok(NULL, " \t\n"));
				if (push(&stack, value, line_number) == NULL)
			       	{
					fprintf(stderr, "Error: malloc failed\n");
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(&stack, line_number);
			else if (strcmp(opcode, "pop") == 0)
				pop(&stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(file);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}

	return (0);
}

