#include "main.h"
/**
 * freee - to free allocated memories
 * @line: one of the pointers
 * @args: pointer
 * @path_copy: pointer
 * @full_path: pointer
 * Return: nothin
 */
void freee(char *line, char **args, char *path_copy, char *full_path)
{

	free(line);
	free(path_copy);
	free(full_path);
	free(args);
}
