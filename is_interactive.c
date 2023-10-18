#include "shell.h"

/**
 * is_interactive - Entry point
 * @program_name:str
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
void is_interactive(char *program_name)
{
	int  i = 1, status = 0;
	char *prompt = "$ ", *buff = NULL, *command = NULL, **arr = NULL;
	size_t sz = 0;

	while (1)
	{
		buff = NULL, command = NULL, arr = NULL, sz = 0;
		write(1, prompt, 2);
		if (get_line(&buff, &sz, STDIN_FILENO, 1) == -1)
			free(buff), exit(0);
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
			free(command);
			free_array(arr);
			++i;
		}
	}
	is_exit(NULL, status, i, program_name);
}
