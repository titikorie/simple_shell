#include "main.h"
/**
 * _atoi - convert string to an integer
 * @nptr: points to the string
 * Return: number of strings changed
 */

int _atoi(const char *nptr)
{
	int i = 0, sign = 1, j = 0;

	if (nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '+')
	{
		i++;
	}
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = j * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * j);
}

/**
 * sig_handler - check the signal
 * @signal: integer
 */
void sig_handler(int signal)
{

	if (signal == SIGINT)
	{
		_puts("\n$ ");
	}
}
/**
 * _EOF - end of line reached
 * @bytes: what getline read
 * @line: pointer to char
 */

void _EOF(int bytes, char *line)
{
	if (bytes == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(line);
		}
		exit(0);
	}
	
}

/**
 * _isatty - brings the sign
 * Return: none
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
