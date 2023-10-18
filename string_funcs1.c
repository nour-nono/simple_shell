#include "shell.h"

/**
 *  _strlen - Entry point
 *
 * @s: is a pointer
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}
/**
 * _strcpy - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if (!src || !dest)
		return (NULL);
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = src[j];
	return (dest);
}
/**
 * _strncpy - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * @n: a num
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	if (!src || !dest)
		return (NULL);
	while (src[j] != '\0' && n)
	{
		dest[i] = src[j];
		++i;
		++j;
		--n;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		--n;
		++i;
	}
	return (dest);
}
/**
 * _strcat - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	if (!dest)
		return (src);
	if (!src)
		return (dest);
	while (dest[i] != '\0')
		++i;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = src[j];
	return (dest);
}

