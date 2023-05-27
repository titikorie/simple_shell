#include "main.h"
/**
 * change_directory - halndle cd command
 * @args: pointer to arguments
 */
void change_directory(char **args)
{
	char *dir = args[1], *oldpwd = _getenv("PWD");
	char *home = _getenv("HOME"), *pwd = malloc(1024);

	if (pwd == NULL)
	{
		perror("fatal error"), exit(127);
	}
	if (dir == NULL)
	{
		dir = home;
		if (dir == NULL)
			dir = ".";
	}
	if (args[1] && _strcmp(args[1] + 1, "-") == 0)
	{
		dir = oldpwd;
		if (dir == NULL)
			dir = ".";
		_puts(dir), _puts("\n");
	}
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		if (oldpwd != NULL)
		{
			if (setenv("OLDPWD", oldpwd, 1) == -1)
			{
				perror("setenv");
				exit(127);
			}
		}
		getcwd(pwd, 1024);
		if (setenv("PWD", pwd, 1) == -1)
		{
			perror("setenv");
			exit(127);
		}
	}
	free(pwd), free(home), free(oldpwd);
}

/**
 * execute_semicolon - handle
 * @line: input pointer
 * @argv: name of program
 * @numm: counter
 */
void execute_semicolon(char *line, char **argv, int numm)
{
	char **args = NULL, *saveptr, *command = _strtok(line, ";", &saveptr);
	int num = 0, len = 0;

	len = _strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (command != NULL)
	{
		args = malloc(sizeof(char *) * (len + 1));
		if (args == NULL)
			exit(1);
		parse_input(command, args, &num);
		if (_strncmp(command, "exit", 4) == 0)
			exitt(command, args, argv, numm);
		else if (_strncmp(command, "cd", 3) == 0)
			change_directory(args);
		else
			execute_command(command, args, argv, numm);
		free(args), args = NULL, num = 0;
		command = _strtok(NULL, ";", &saveptr);
	}
}
