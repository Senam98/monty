#include "monty.h"

/**
 * push - Adds an item at the end of the given stack
 * @stack: The pointer to the stack of values
 * @n: The data stored by the stack's new item
 */
void push(stack_t **stack, int n)
{
	stack_t *node = NULL, *new_node = NULL;

	if (stack != NULL)
	{
		new_node = _realloc(new_node, 0, sizeof(stack_t));
		new_node->prev = NULL;
		new_node->n = n;
		new_node->next = NULL;
		node = *stack;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
		if (node != NULL)
		{
			node->next = new_node;
			new_node->prev = node;
		}
		else
		{
			*stack = new_node;
		}
	}
}

/**
 * _pop - Removes an item at the top of the given stack
 * @stack: The pointer to the stack of values
 * Return: The data stored by the removed item if there were any
 */

int _pop(stack_t **stack)
{
	stack_t *node = NULL;
	int val = 0;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
		if (node != NULL)
		{
			val = node->n;
			if (node->prev != NULL)
				node->prev->next = NULL;
			if ((node->prev == NULL) && (node->next == NULL))
				*stack = NULL;
			free(node);
			node = NULL;
		}
	}
	return (val);
}

/**
 * enqueue - Adds an item at the end of the given stack-like queue
 * @stack: The pointer to the stack of values
 * @n: The data stored by the stack's new item
 */

void enqueue(stack_t **stack, int n)
{
	stack_t *node = NULL, *new_node = NULL;

	if (stack != NULL)
	{
		new_node = _realloc(new_node, 0, sizeof(stack_t));
		new_node->prev = NULL;
		new_node->n = n;
		new_node->next = NULL;
		node = *stack;
		while ((node != NULL) && (node->prev != NULL))
			node = node->prev;
		if (node != NULL)
		{
			node->prev = new_node;
			new_node->next = node;
		}
		else
		{
			*stack = new_node;
		}
	}
}

/**
 * get_top_element - Retrieves the item at the top of the stack based \
 * on the data format (stack or queue)
 * @stack: The pointer to the stack of values
 * Return: The node at the top, otherwise NULL
 */

stack_t *get_top_element(stack_t **stack)
{
	char stop = FALSE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (!stop))
		{
			stop = node->next == NULL ? TRUE : FALSE;
			node = node->next == NULL ? node : node->next;
		}
	}
	return (node);
}

/**
 * get_bottom_element - Retrieves the item at the bottom of the stack based \
 * on the data format (stack or queue)
 * @stack: The pointer to the stack of values
 * Return: The node at the bottom, otherwise NULL
 */

stack_t *get_bottom_element(stack_t **stack)
{
	char stop = FALSE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (!stop))
		{
			stop = node->prev == NULL ? TRUE : FALSE;
			node = node->prev == NULL ? node : node->prev;
		}
	}
	return (node);
}
