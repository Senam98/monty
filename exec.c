#include "monty.h"

/**
 * get_handlers - Retrieves an array of supported instructions
 * Return: arr of instructions
 */

instruction_t *get_handlers(void)
{
	static instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", op_pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, 0},
	};
	return (func);
}


/**
 * _execute - Executes a line of code
 * @line: The line to execute
 * @line_num: The line number of the line being executed
 * @stack_values: The stack of values of the program
 */

void _execute(char *line, int line_num, stack_t **stack_values)
{
	instruction_t *opcode_handlers = get_handlers();
	int i = 0, j;
	char *opcode = read_word(line, &i);

	if (opcode != NULL)
	{
		if ((opcode[0] != '#') && (opcode[0] != '\0'))
		{
			for (j = 0; opcode_handlers[j].opcode != NULL; j++)
			{
				if (strcmp(opcode, opcode_handlers[j].opcode) == 0)
				{
					free(opcode), opcode_handlers[j].f(stack_values, line_num);
					return;
				}
			}
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			free(opcode), exit_(EXIT_FAILURE);
		}
		free(opcode);
	}
}
