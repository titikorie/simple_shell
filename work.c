#include "main.h"
/*
 * main - the main function fot other prototypes
 * @numm: integer
 * @argv: pointet to the arguments
 * Return: 0
 */
int main(int numm, char **argv)
{
	char **args = NULL, *line = NULL;
	int num = 0, len;
	size_t i = 0;
	ssize_t bytes = 0;

	numm = 0;
	signal(SIGINT, sig_handler);
	while (bytes != EOF)
	{
		numm++;
		_isatty();
		bytes = getline(&line, &i, stdin);
		_EOF(bytes, line);
		len = _strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		args = malloc(sizeof(char *) * (len + 1));
		parse_input(line, args, &num);
		if (_strncmp(line, "exit", 5) == 0)
		{
			exitt(line);
		}
		execute_command(args, argv);
		
		free(args);
		args = NULL;
		num = 0;
	}
	free(args);
	freee(line);
	return (0);
}

/**
 * parse_input - to devide the input using delim by strtok
 * @line: input command
 * @args: arrays of commands
 * @num: pointer to integer
 * Return: NULL
 **/
void parse_input(char *line, char **args, int *num)
{
	int size = 10;
	char *saveptr, *arg = _strtok(line, " ", &saveptr);

	while (arg != NULL)
	{
		args[*num] = arg;
		(*num)++;
		arg = _strtok(NULL, " ", &saveptr);
		if (*num >= size)
		{
			size *= 2;
			*args = realloc(*args, sizeof(char *) * size);
			if (*args == NULL)
			{
				free(args);
				perror("realloc");
				exit(1);
			}
		}
	}
	if (*num == 0)
	{
		args[*num] = "";
		(*num)++;
	}
	args[*num] = NULL;
}

/**
 * execute_command - fork and excute
 * @args: arrays of command
 * @argv: pointer to arguments
 * Return: none
 */
int execute_command(char **args, char **argv)
{
	
	int status;
	pid_t pid;
	unsigned int numm = 0;
	char *cmd, *dir = NULL, *path;
	list_t list;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		cmd = args[0];
		path = search_path(cmd);
		if (path == NULL)
		{
			list.args = args;
			list.number = 1;
			_error(&list, ": not found\n", argv, numm);
			_puts(dir);
			_puts("\n");
			exit(127);
		}
		args[0] = path;
		if (execve(args[0], args, environ) == -1)
		{
			list.args = args;
			list.number = 1;
			_error(&list, " \n", argv,  numm);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (WEXITSTATUS(status));
}

/**
 * search_path - search and find the path
 * @cmd: pointer to char
 * Return: pointer to path
 */
char *search_path(char *cmd)
{
	char *path, *path_copy, *dir, *full_path = NULL;

	if (_strchr(cmd, '/') != NULL)
	{
		return (cmd);
	}
	path = _getenv("PATH");
	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");
	full_path = malloc(_strlen(dir) + _strlen(cmd) + 2);

	while (dir != NULL)
	{
		if (full_path != NULL)
		{
			full_path[0] = '\0';
			_strcat(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, cmd);
		}

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(full_path);
	free(path_copy);
	return (NULL);
}
