#include "shell.h"


/**
 * handle_sigint - copy string in heap
 *
 * @sign: string
 *
 * Return: string.
 */
void handle_sigint(int sign)
{
	(void) sign;
	exit(0);
}
/**
 * get_line - copy string in heap
 *
 * @lineptr: string
 * @n: string
 * @fd: string
 * @flag1: string
 *
 * Return: string.
 */
ssize_t get_line(char **lineptr, size_t *n, int fd, int flag1)
{
	static char buffer[8192];
	static int sz = 0, i = 0, flag = 1;
	size_t j = 0;

	if (flag1)
		i = 0;
	signal(SIGINT, handle_sigint);
	if (flag1 || flag)
		sz = read(fd, buffer, 8180), flag = 0;
	if (sz == -1)
	{
		perror("");
		return (-1);
	}
	buffer[sz] = '\0';
	if (!(*lineptr))
		(*lineptr) = malloc(sizeof(char) * 1024);
	while (buffer[i] != '\0' && buffer[i] != '\n' && j < 1024)
	{
		if (buffer[i] == '\n' || buffer[i] == ' ' || buffer[i] == '\t')
		{
			if (buffer[i + 1] == '\n' || buffer[i + 1] == ' ' || buffer[i + 1] == '\t')
			{
				++i;
				continue;
			}
		}
		(*lineptr)[j++] = buffer[i++];
	}
	if (j == 0)
	{
		free((*lineptr));
		return (-1);
	}
	while (buffer[i] == '\n' || buffer[i] == ' ' || buffer[i] == '\t')
		++i;
	(*lineptr)[j] = '\0';
	*n = j;
	return (*n);
}
