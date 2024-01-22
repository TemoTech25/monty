#include "monty.h"

/**
 * execute_file - reads and executes opcodes from a file
 * @stack: pointer to the top of the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&glob.line, &len, glob.file)) != -1)
	{
		line_number++;
		opcode = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_opcode(opcode, stack, line_number);
	}
}

/**
 * execute_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", t_push},
		{"pall", t_pall},
		{"pint", t_pint},
		{"pop", t_pop},
		{"swap", t_swap},
		{"nop", t_nop},
		{"add", t_add},
		{"sub", t_sub},
		{"div", t_div},
		{"mul", t_mul},
		{"mod", t_mod},
		{"pchar", t_pchar},
		{"pstr", t_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
