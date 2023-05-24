#include "main.h"
/**
 * exitt - to exit the child process
 * @line: read input command
 * @args: points the argumentss
 */
void exitt(char *line, char **args)
{
	int status = 0;

	status = _atoi(&line[5]);
	free(args);
	free(line);
	exit(status);
}
