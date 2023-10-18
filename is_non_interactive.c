#include "shell.h"

/**
 * is_non_interactive - Entry point
 *
 * @program_name: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
void is_non_interactive(char *program_name)
{
	int  i = 1, status = 0;
	char *buff = NULL, *command = NULL, **arr = NULL;
	size_t sz = 0;

	while (get_line(&buff, &sz, STDIN_FILENO, 0) != -1)
	{
		remove_comment(buff);
		arr = make_arr_of_str(buff, " \n\t");
		arr = replace_var(arr, status);
		free(buff);
		if (search_in_implemented(arr, &status, i, program_name))
		{
			if (arr[0] && access(arr[0], F_OK | X_OK) == 0)
				exec_command(arr[0], arr, &status);
			else
			{
				command = search_for_command_in_paths(arr[0]);
				if (!command)
				{
					show_error(program_name, i, arr[0], "not found\n");
					status = 127;
				}
				else
					exec_command(command, arr, &status);
			}
			free_array(arr);
			free(command);
			++i;
			buff = NULL, command = NULL, arr = NULL, sz = 0;
		}
	}
	is_exit(NULL, status, i, program_name);
}
