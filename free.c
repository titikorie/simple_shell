#include "main.h"
/**
 * freee - to free allocated memories
 * @line: one of the pointers
 * Return: nothin
 */
void freee(void *line)
{
	char *nptr = NULL, *format = NULL, *str = NULL;
	char *value = NULL, *path_copy = NULL, *full_path = NULL, **args = NULL;

	free(line);
	free(value);
	free(value);
	free(path_copy);
	free(full_path);
	free(args);
	free(nptr);
	free(format);
	free(str);
}
