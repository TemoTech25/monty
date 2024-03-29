#include "monty.h"

/**
 * t_mul - multiplies the 2nd top element of the stack with top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */

void t_mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
