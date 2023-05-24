#include "main.h"
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/**
 * _changer - take unsigned int to return string
 * @number: unsignerd int
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
 * Return: nothing
 */
void _error(list_t *list, char *string, char **argv, unsigned int numm)
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

int print_d(int input, int fd)                             {                                                                  int (*__putchar)(char) = _putchar;
        int i, count = 0;                                          unsigned int _abs_, current;
        if (fd == STDERR_FILENO)
                __putchar = _eputchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                count++;
        }
        else
                _abs_ = input;
        current = _abs_;
        for (i = 1000000000; i > 1; i /= 10)
        {
                if (_abs_ / i)
                {
                        __putchar('0' + current / i);
                        count++;
                }
                current %= i;
        }
        __putchar('0' + current);
        count++;

        return (count);                                    }

int _eputchar(char c)                                      {                                                                  static int i;                                              static char buf[WRITE_BUF_SIZE];                                                                                      if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {                                                                  write(2, buf, i);
                i = 0;
        }                                                          if (c != BUF_FLUSH)                                                buf[i++] = c;                                      return (1);                                        }
