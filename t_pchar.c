#include "monty.h"

/**
 * t_pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line no. of the opcode of the Monty file
 */

void t_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}
