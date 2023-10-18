#include "shell.h"

/**
 * _realloc - function that reallocates a memory block using malloc and free
 *
 * @ptr: a pointer to the memory previously allocated with a call
 * to malloc: malloc(old_size)
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size:  is the new size, in bytes of the new memory block
 *
 * Return: a pointer allocated with the new size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *pointer;
    unsigned int i;

    if (new_size == old_size)
        return (ptr);
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
    {
        pointer = malloc(new_size);
        if (pointer == NULL)
            return (NULL);
        return (pointer);
    }
    if (new_size > old_size)
    {
        pointer = malloc(new_size);
        if (pointer == NULL)
            return (NULL);
        for (i = 0; i < old_size && i < new_size; i++)
            *((char *)pointer + i) = *((char *)ptr + i);
        free(ptr);
    }
    return (pointer);
}

/**
 * free_array - Entry point
 *
 * @arr: pointer to array of strings
 *
 * Return: Always 0 (Success)
*/
void free_array(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
