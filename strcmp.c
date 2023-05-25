#include "main.h"

/**
 * _strlen - to count the length of characters
 * @s: point to ths characters
 * Return: the number of length of characters
 */
size_t _strlen(const char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
	}
	return (i);
}

/**
 * _strcmp - to compare the similadities of two strings
 * @string1: array of chars for the 1st string
 * @string2: array of chars for the 2nd string
 * Return: integer
 */

int _strcmp(const char string1[], const char string2[])
{
	int i = 0;

	while (string1[i] == string2[i])
	{
		if (string1[i] == '\0' || string2[i] == '\0')
		{
			break;
		}
		i++;
	}
	if (string1[i] == '\0' && string2[i] == '\0')
		return (0);

	else
	return (0);
}

/**
 * _strncmp - compares the 1st n bytes
 * @s1: array of chars for the 1st string
 * @s2: array of chars for the 2st string
 * @n:n size of the byte we compare
 * Return: integer
 **/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (_strlen(s1) - _strlen(s2));
		}
	}

	return (0);
}

/**
 * _putchar - to print single char at a time
 * @c: the character to be printed
 * Return: character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - to print string
 * @str: pointer to the string
 * Return: nonnegative number on success, or EOF on error
 */

void _puts(char *str)
{
	int i, j = 0;

	while (str[j] != '\0')
	{
		j++;
	}
	for (i = 0; i < j; i++)
	{
		_putchar(str[i]);
	}
	if (i != j)
	{
		perror("errno");
		exit(1);
	}
}
