#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *line = get_lines()[line_number - 1];
	char *opname = NULL, *arg = NULL, data_mode = DF_LIFO;
	int o = 0, arg_int = 0;

	opname = read_word(line, &o);
	arg = read_word(line, &o);
	free(opname);
	if ((arg != NULL) && is_integer(arg))
	{
		arg_int = atoi(arg);
		free(arg);
		data_mode = *get_data_mode();
		if (data_mode == DF_LIFO)
		{
			push(stack, arg_int);
		}
		else if (data_mode == DF_FIFO)
		{
			enqueue(stack, arg_int);
		}
	}
	else
	{
		if (arg != NULL)
			free(arg);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_(EXIT_FAILURE);
	}
}

/**
 * _pall - Prints all the values, starting from the top of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		while ((node != NULL))
		{
			printf("%d\n", node->n);
			node = node->prev;
		}
	}
	(void)line_number;
}

/**
 * _pint - Prints the value at the top of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		if (node != NULL)
		{
			printf("%d\n", node->n);
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_(EXIT_FAILURE);
	}
}

/**
 * op_pop - Removes the top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	if ((stack != NULL) && (*stack != NULL))
	{
		_pop(stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_(EXIT_FAILURE);
	}
}

/**
 * _swap - Swaps the top two elements of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int tmp = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		top1 = top0->prev;
		if (top1 != NULL)
		{
			tmp = top1->n;
			top1->n = top0->n;
			top0->n = tmp;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_(EXIT_FAILURE);
	}
}
