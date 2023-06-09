#include "main.h"
/**
 * exitt - to exit the child process
 * @line: read input command
 * @argv: name of program
 * @numm: counter
 * @args: points the arguments
 * Return: status
 */
int exitt(char *line, char **args, char **argv, int numm)
{
	int status = 0;
	list_t list;

	if (_strncmp(args[0], "exit", 4) == 0)
	{
		if (args[1] == NULL)
		{
			free(line);
			free(args);
			exit(0);
		}
		status = _atoi(args[1]);
		if (status >= 0)
		{
			free(args);
			free(line);
			exit(status);
		}
		else
		{
			list.args = args;
			list.number = numm++;
			_error(&list, ": Illegal number\n", argv, numm++);
			exit(2);
		}
	}
	return (status);
}
