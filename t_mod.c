#include "monty.h"

/**
 * t_mod - computes the modulus of the 2nd top element of the stack
 * with the top element.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void t_mod(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = b % a;
	t_pop(stack, line_number);
}
