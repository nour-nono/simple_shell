#include "shell.h"

/**
 * _pow - function that print integer if %d or %i found
 *
 * @a: the number to be printed
 * @b: int
 * Return: int
 */
int _pow(int a, int b)
{
	int c = a;

	if (b == 0)
	{
		a = 1;
		return (a);
	}
	while (--b)
		a *= c;
	return (a);
}

/**
 * int_to_string - function that print integer if %d or %i found
 *
 * @arr: the number to be printed
 * @zz: the number to be printed
 *
 * Return: Nothing
 */
void int_to_string(char *arr, int zz)
{
	int num = zz, x, i = 0, a = 0, is_negative = 0, j = 0;
	char c;

	x = num;
	while (x >= 10)
		x /= 10, i++;
	while (i >= 0)
	{
		a = num / _pow(10, i);
		if (i == 0 && is_negative == 1)
			c = (a % 10) + '1';
		else
			c = (a % 10) + '0';
		arr[j] = c;
		i--, ++j;
	}
	arr[j] = '\0';
}

/**
 * show_error - function that print integer if %d or %i found
 *
 * @program_name : the number to be printed
 * @i : the number to be printed
 * @command : the number to be printed
 * @err : the number to be printed
 *
 * Return: Nothing
 */
void show_error(char *program_name, int i, char *command, char *err)
{
	char *out_put = NULL, *arr = NULL, *token = _strtok(command, " \n\t");
	int size = _strlen(program_name) + _strlen(command) + 7;

	arr = (char *)malloc(sizeof(char) * 16);
	if (arr == NULL)
	{
		return;
	}
	int_to_string(arr, i);
	size += _strlen(arr) + _strlen(err);
	out_put = (char *)malloc(sizeof(char) * size);
	out_put = _strcpy(out_put, program_name);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, arr);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, token);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, err);
	write(2, out_put, size);
	free(out_put);
	free(arr);
}
