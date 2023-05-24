#include "main.h"
/**
 * exitt - to exit function
 * @line: ptr of the input command
 */
void exitt(char *line)
{
	int status = 0;

	status = _atoi(&line[5]);
	freee(line);
	exit(status);
}

/**
 * freee - to free allocated memories
 * @line: one of the pointers
 * Return: nothin
 */
void freee(void *line)
{
	char *nptr = NULL, *format = NULL, *str = NULL, *value = NULL;
	char *path_copy = NULL, *full_path = NULL, **args = NULL;

	free(line);
	free(value);
	free(path_copy);
	free(full_path);
	free(args);
	free(nptr);
	free(format);
	free(str);
}
