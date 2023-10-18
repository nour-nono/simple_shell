#include "shell.h"

/**
 * replace_var - check the code
 *
 * @arr: bla bla
 * @status: bla bla
 *
 * Return: Always 0.
 */
char **replace_var(char **arr, int status)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		if (arr[i][0] == '$' && arr[i][1] != '\0')
		{
			if (arr[i][1] == '?')
				arr[i] = change_to_status(arr[i], status);
			else if (arr[i][1] == '$')
				arr[i] = change_to_pid(arr[i]);
			else
				arr[i] = change_to_env_var(arr[i]);
		}
		++i;
	}
	return (arr);
}
/**
 * change_to_status - check the code
 *
 * @arr_str: bla bla
 * @status: bla bla
 *
 * Return: Always 0.
 */
char *change_to_status(char *arr_str, int status)
{
	int i = 2, j = 0;
	size_t sz = 0;
	char *the_rest_of_str = NULL, *status_str = NULL;

	status_str = (char *)malloc(sizeof(char) * 32);
	the_rest_of_str = (char *)malloc(sizeof(char) * 512);
	if (status_str == NULL || the_rest_of_str == NULL)
	{
		/* code */
	}
	while (arr_str[i] != '\0')
		the_rest_of_str[j++] = arr_str[i++];
	the_rest_of_str[j] = '\0';
	int_to_string(status_str, status);
	sz = _strlen(status_str) + _strlen(the_rest_of_str) + 1;
	arr_str = _realloc(arr_str, sizeof(arr_str),sz);
	_strcpy(arr_str, status_str);
	_strcat(arr_str, the_rest_of_str);
	free(status_str);
	free(the_rest_of_str);
	return (arr_str);
}
/**
 * change_to_pid - check the code
 *
 * @arr_str: bla bla
 *
 * Return: Always 0.
 */
char *change_to_pid(char *arr_str)
{
	int i = 2, j = 0, pid_num = getpid();
	size_t sz = 0;
	char *the_rest_of_str = NULL, *pid_str = NULL;

	pid_str = (char *)malloc(sizeof(char) * 32);
	the_rest_of_str = (char *)malloc(sizeof(char) * 512);
	if (pid_str == NULL || the_rest_of_str == NULL)
	{
		/* code */
	}
	while (arr_str[i] != '\0')
		the_rest_of_str[j++] = arr_str[i++];
	the_rest_of_str[j] = '\0';
	int_to_string(pid_str, pid_num);
	sz = _strlen(pid_str) + _strlen(the_rest_of_str) + 1;
	arr_str = _realloc(arr_str, sizeof(arr_str), sz);
	_strcpy(arr_str, pid_str);
	_strcat(arr_str, the_rest_of_str);
	free(pid_str);
	free(the_rest_of_str);
	return (arr_str);
}
/**
 * change_to_env_var - check the code
 *
 * @arr_str: bla bla
 *
 * Return: Always 0.
 */
char *change_to_env_var(char *arr_str)
{
	int i = 1, j = 0;
	size_t sz = 0;
	char *the_rest_of_str = NULL, *env_str = NULL;

	the_rest_of_str = (char *)malloc(sizeof(char) * 512);
	if (the_rest_of_str == NULL)
		return (arr_str);
	while (arr_str[i] != '\0')
		the_rest_of_str[j++] = arr_str[i++];
	the_rest_of_str[j] = '\0';
	env_str = _get_env(the_rest_of_str);
	if (env_str == NULL)
	{
		free(the_rest_of_str);
		arr_str = _realloc(arr_str, sizeof(arr_str), 1);
		arr_str[0] = '\0';
		return (arr_str);
	}
	sz = _strlen(env_str) + 1;
	arr_str = _realloc(arr_str, sizeof(arr_str), sz);
	_strcpy(arr_str, env_str);
	free(env_str);
	free(the_rest_of_str);
	return (arr_str);
}
