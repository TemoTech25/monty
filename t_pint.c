#include "monty.h"

/**
 * t_pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line no. of the opcode
*/

void t_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
