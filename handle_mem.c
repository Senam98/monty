#include "monty.h"

/**
 * malloc_failure - Performs the malloc failure routines
 * @failed: Specifies if malloc failed
 */

void malloc_failure(char failed)
{
	if (failed)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit_(EXIT_FAILURE);
	}
}

/**
 * _realloc - Reallocates a memory block
 * @ptr: The pointer to the previous memory block
 * @old_size: The size of the old memory block
 * @new_size: The size of the new memory block
 *
 * Return: The pointer to the new memory block otherwise NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;
	unsigned int min_size = old_size < new_size ? old_size : new_size;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL)
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
		new_ptr = malloc(new_size);
		if (new_ptr != NULL)
		{
			for (i = 0; i < min_size; i++)
				*((char *)new_ptr + i) = *((char *)ptr + i);
			free(ptr);
			return (new_ptr);
		}
		free(ptr);
		malloc_failure(new_ptr == NULL);
		return (NULL);
	}
	else
	{
		new_ptr = malloc(new_size);
		malloc_failure(new_ptr == NULL);
		return (new_ptr);
	}
}

/**
 * mem_set - Fills a section of a buffer with a given byte
 * @str: The buffer containing the section to be filled
 * @n: The length of the buffer to fill
 * @c: The byte to fill the buffer's section with
 */

void mem_set(char *str, int n, char c)
{
	int i;

	for (i = 0; (str != NULL) && (i < n); i++)
		*(str + i) = c;
}
