#include "shell.h"

/**
 * is_delim - copy string in heap
 * @c: string
 * @delimiters: string
 *
 * Return: string.
 */
unsigned int is_delim(char c, char *delimiters)
{
	while (*delimiters != '\0')
	{
		if (c == *delimiters)
		return (1);
		delimiters++;
	}
	return (0);
}

/**
 * _strtok - copy string in heap
 * @str: string
 * @delimiters: string
 *
 * Return: string.
 */
char *_strtok(char *str, char *delimiters)
{
	static char *last_of_string;
	char *retur_of_the_rest = NULL;

	if (!str)
		str = last_of_string;
	if (!str)
		return (NULL);
	while (1)
	{
		if (is_delim(*str, delimiters))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	retur_of_the_rest = str;
	while (1)
	{
		if (*str == '\0')
		{
			last_of_string = str;
			return (retur_of_the_rest);
		}
		if (is_delim(*str, delimiters))
		{
			*str = '\0';
			last_of_string = str + 1;
			return (retur_of_the_rest);
		}
		str++;
	}
}
/**
 * make_arr_of_str - copy string in heap
 * @str: string
 * @delimiters: string
 *
 * Return: string.
 */
char **make_arr_of_str(char *str, char *delimiters)
{
	int i = 0;
	char *token, **arr_of_str = malloc(sizeof(char *) * 100);
	char *str_copy = _strdup(str);

	token = _strtok(str_copy, delimiters);
	while (token != NULL)
	{
		arr_of_str[i] = malloc(sizeof(char) * _strlen(token) + 1);
		_strcpy(arr_of_str[i], token);
		token = _strtok(NULL, delimiters);
		i++;
	}
	free(str_copy);
	arr_of_str[i] = NULL;
	return (arr_of_str);
}

/**
 * remove_comment - copy string in heap
 * @str: string
 *
 * Return: string.
 */
void remove_comment(char *str)
{
	int i = 0;

	if (!(str))
		return;
	while ((str)[i] != '\0')
	{
		if ((str)[i] == '#')
		{
			if (i == 0 || (str)[i - 1] == ' ')
			{
				(str)[i] = '\0';
				break;
			}
		}
		i++;
	}
}
