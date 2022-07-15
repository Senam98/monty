#include "monty.h"

static stack_t *Values;
static char **Lines;
static int Count;
static int Curr_Line;
static char Data_Format;

/**
 * main - Entry_ Monty ByteCode interpreter
 * @argc: lenght of arguments
 * @argv: array of arguments
 * Return: int
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Data_Format = DF_LIFO;
		Lines = read_file(argv[1], &Count);
		while (Curr_Line < Count)
		{
			_execute(Lines[Curr_Line], Curr_Line + 1, &Values);
			Curr_Line++;
		}
	}
	else
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	clean_mem();
	return (EXIT_SUCCESS);
}

/**
 * clean_mem - Frees dynamically allocated memory blocks
 */

void clean_mem(void)
{
	stack_t *node = Values, *tmp = NULL;
	int i;

	if (Lines != NULL)
	{
		for (i = 0; i < Count; i++)
		{
			if (Lines[i] != NULL)
				free(Lines[i]);
		}
		if (Lines != NULL)
			free(Lines);
	}
	if (node != NULL)
	{
		while ((node != NULL) && (node->prev != NULL))
			node = node->prev;
		while (node != NULL)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
	}
}

/**
 * exit_ - exits the program
 * @status: The exit code
 */

void exit_(int status)
{
	clean_mem();
	exit(status);
}

/**
 * get_data_mode - Returns a pointer to the interpreter's mode flag
 * Return: A pointer to the interpreter's mode flag
 */

char *get_data_mode(void)
{
	return (&Data_Format);
}

/**
 * get_lines - Retrieves the lines of the current file
 * Return: The lines of the current file
 */

char **get_lines(void)
{
	return (Lines);
}
