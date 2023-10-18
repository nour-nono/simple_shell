#include "shell.h"

/**
 * print_env - print environment
 *
 * Description: function that print the environment
 *
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;
	char c = '\n';

	while (*(environ + i) != NULL)
	{
		write(1, *(environ + i), strlen(*(environ + i)));
		write(1, &c, 1);
		i++;
	}
}
/**
 * is_exit - out if is exit
 *
 * @arr: is a pointer
 * @status: is a pointer
 * @i: is a pointer
 * @program_name: is a pointer
 * Description: this program prints "_putchar"
 *
 * Return: nothing
 */

void is_exit(char **arr, int status, int i, char *program_name)
{
	int j = -1;
	char *error = NULL;

	if (arr == NULL || arr[1] == NULL)
	{
		exit(status);
	}
	j = _atoi(arr[1]);
	if (j >= 0)
	{
		free_array(arr);
		exit(j);
	}
	else
	{
		error = malloc(sizeof(char) * 1024);
		if (error == NULL)
			exit(2);
		_strcpy(error, "Illegal number");
		_strcat(error, ": ");
		_strcat(error, arr[1]);
		_strcat(error, "\n");
		show_error(program_name, i, arr[0], error);
		free(error);
		free_array(arr);
		exit(2);
	}
}
