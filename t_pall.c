#include "monty.h"

/**
 * t_pall - prints all the values
 * @stack: pointer to the top of the stack
 * @line_number: line no. of the opcode
 */
void t_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		(void)line_number;
	}

}
