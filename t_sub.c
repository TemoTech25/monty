#include "monty.h"

/**
 * t_sub - sub the top element of the stack from the 2nd top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */

void t_sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
