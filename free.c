#include "shell.h"
/**
 * free_2_pointer - a function that frees array of strings
 * @str: the array of strings
 * Return: void
 */
void free_2_pointer(char **pointer)
{
	int i;

	if (pointer == NULL)
		return;
	for (i = 0; pointer[i]; i++)
	{
		free(pointer[i]), pointer[i] = NULL;
	}
	free(pointer), pointer = NULL;
}
