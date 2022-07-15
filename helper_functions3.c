#include "monty.h"

/**
 * str_len - Computes the length of a string
 * @str: The source string
 * Return: The length of the string.
 */

int str_len(const char *str)
{
	int len = 0;

	while ((str != NULL) && (*(str + len) != '\0'))
		len++;
	return (len);
}

/**
 * str_cat - Concatenates two strings
 * @left: The left string
 * @right: The right string
 * @can_free: Specifies which free-able parameters can be freed
 * Return: A pointer to the concatenated string
 */

char *str_cat(char *left, char *right, char can_free)
{
	int left_length = str_len(left);
	int right_length = str_len(right);
	int i;
	char *str = NULL;

	str = _realloc(str, 0, sizeof(char) * (left_length + right_length + 1));
	for (i = 0; left != NULL && *(left + i) != '\0'; i++)
		*(str + i) = *(left + i);
	for (i = 0; right != NULL && *(right + i) != '\0'; i++)
		*(str + left_length + i) = *(right + i);
	*(str + left_length + i) = '\0';
	if (((can_free >> 1) & TRUE) && (left != NULL))
		free(left);
	if ((can_free & TRUE) && (right != NULL))
		free(right);
	return (str);
}

/**
 * str_split - Splits a string into smaller strings at a given character
 * @str: The string to split
 * @c: The character at which to perform the split
 * @len_out: The pointer which would contain the number of smaller strings
 * @can_free: Specifies which free-able parameters can be freed
 * Return: A pointer to the first string in the array of strings
*/

char **str_split(char *str, char c, int *len_out, char can_free)
{
	int i = 0, j = 0, o = 0, s = 0, n = 0;
	char **strs = NULL;

	if (str == NULL)
		return (NULL);
	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (((*(str + i) == c))
			|| ((*(str + i) != c) && (*(str + i + 1) == '\0')))
		{
			strs = _realloc(strs, sizeof(void *) * n, sizeof(void *) * (n + 1));
			s = *(str + i) == c ? i - j : i - j + 1;
			*(strs + n) = NULL;
			*(strs + n) = _realloc(*(strs + n), 0, sizeof(char) * (s + 1));
			for (o = 0; o < s; o++)
				*(*(strs + n) + o) = *(str + j + o);
			*(*(strs + n) + o) = '\0';
			j = i + 1;
			n++;
		}
	}
	if (len_out != NULL)
		*len_out = n;
	if (can_free & TRUE)
		free(str);
	return (strs);
}
