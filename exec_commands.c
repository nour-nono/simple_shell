#include "shell.h"

/**
 * search_for_command_in_paths - copy string in heap
 * @command: string
 *
 * Return: string.
 */
char *search_for_command_in_paths(char *command)
{
	char *path_copy = _get_env("PATH"), *search_in_this_path = NULL;
	char **all_paths = make_arr_of_str(path_copy, ":\n\t");
	int i = 0, flag = 0;

	free(path_copy);
	while (all_paths[i])
	{
		search_in_this_path = malloc(_strlen(all_paths[i]) + _strlen(command) + 2);
		if (search_in_this_path == NULL)
			return (NULL);
		_strcpy(search_in_this_path, all_paths[i]);
		_strcat(search_in_this_path, "/");
		_strcat(search_in_this_path, command);
		if (search_in_this_path && access(search_in_this_path, F_OK | X_OK) == 0)
		{
			flag = 1;
			break;
		}
		free(search_in_this_path);
		++i;
	}
	i = 0;
	free_array(all_paths);
	if (flag)
		return (search_in_this_path);
	else
		return (NULL);
}

/**
 * exec_command - copy string in heap
 * @command: string
 * @command_and_argu: string
 * @status: string
 * Return: string.
 */
void exec_command(char *command, char **command_and_argu, int *status)
{
	pid_t child_id = fork();

	if (child_id == -1)
		perror("");
	else if (child_id == 0)
	{
		if (execve(command, command_and_argu, NULL) == -1)
		{
			perror("");
			exit(2);
		}
	}
	else if (child_id > 0)
	{
		if (wait(status) == -1)
			perror("");
	}
}
