#include "monty.h"

/**
 * t_pstr - prints the string starting at top of stack
 * @stack: double pointer to the top of the stack.
 * @line_number: line no. of the opcode of the Monty file
 */

void t_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
