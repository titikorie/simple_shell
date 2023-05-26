#include "main.h"
/**
 * _changer - take unsigned int to return string
 * @number: unsignerd int
 * @numm: integer
 * Return: string changed
 */

char *_changer(unsigned int number, unsigned int numm)
{
	char *str;
	unsigned int num, i, j;

	num = number;
	i = 0;
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	str = (char *) malloc(sizeof(char) * (i + 1 + numm));
	if (str == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	j = 0;
	while (number != 0)
	{
		str[i - j - 1] = (number % 10) + '0';
		number /= 10;
		j++;
	}
	str[i] = '\0';
	return (str);
	free(str);
}

/**
 * _error - print the error message
 * @string: points to a string
 * @list: struct
 * @argv: pointer to name of program
 * @numm: counter
 * Return: nothing
 */
void _error(list_t *list, char *string, char **argv, int numm)
{
	char *number;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	number = _changer(list->number, numm);
	write(STDERR_FILENO, number, _strlen(number));
	free(number);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, list->args[0], _strlen(list->args[0]));
	if (string != NULL)
	{
		write(STDERR_FILENO, string, _strlen(string));
	}
}
