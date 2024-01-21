#include "monty.h"

/**
 * push - Opcode to push an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;

    token = strtok(NULL, " \n\t");
    if (!token)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(token);

    if (value == 0 && token[0] != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, value);
}

