#include "monty.h"

/**
 * t_add - adds the elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void t_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	t_pop(stack, line_number);
}
