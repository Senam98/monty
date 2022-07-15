#include "monty.h"

/**
 * read_file - Reads the lines in a file froma file path
 * @path: The location of the file
 * @lines_count: A pointer to the lines in the file
 * Return: The lines of the file, otherwise NULL
 */
char **read_file(char *path, int *lines_count)
{
	char buf[1024] = {0}, stop = FALSE, *str = NULL;
	struct stat file_stat;
	int fd = -1, n = 0;

	stat(path, &file_stat);
	fd = open(path, O_RDONLY);
	if ((fd >= 0) && S_ISREG(file_stat.st_mode))
	{
		while (!stop)
		{
			mem_set(buf, 1024 - 1, '\0');
			n = read(fd, (void *)buf, 1024 - 1);
			if ((n <= 0) || (n < 1024 - 1))
				stop = TRUE;
			buf[n] = '\0';
			str = str_cat(str, buf, 2);
		}
		close(fd);
		return (str_split(str, '\n', lines_count, 1));
	}
	else
	{
		if (fd >= 0)
			close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit_(EXIT_FAILURE);
	}
	return (NULL);
}

/**
 * read_word - Reads a word from the given string
 * @str: The string to read from
 * @offset: The offset into the string
 * Return: The string read, otherwise NULL
 */
char *read_word(char *str, int *offset)
{
	int i = 0, a = -1, len;
	char *word = NULL;

	for (i = 0; (str != NULL) && (str[i + *offset] != '\0'); i++)
	{
		a = !is_whitespace(str[i + *offset]) && (a == -1) ? i : a;
		if ((a != -1) && is_whitespace(str[i + *offset]))
			break;
	}
	len = a > -1 ? i - a : 0;
	if (len > 0)
	{
		word = _realloc(word, 0, sizeof(char) * (len + 1));
		for (i = 0; i < len; i++, a++)
			word[i] = str[a + *offset];
		word[i] = '\0';
	}
	*offset = len > 0 ? a : i + *offset;
	return (word);
}

