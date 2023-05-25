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

	_puts(argv[0]);
	_puts(": ");
	number = _changer(list->number, numm);
	_puts(number);
	free(number);
	_puts(": ");
	_puts(list->args[0]);
	if (string != NULL)
	{
		_puts(string);
	}
}
