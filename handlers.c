#include "main.h"
#define SIZE 100
int handlers(char **commands, char **args)
{
	char *token, *line = NULL, *arg_token;
        int num_commands = 0, i, num_args = 0;

    if (_strchr(line, ';') == NULL) {
        return 0;
    }
    
    token = strtok(line, ";");
    while (token != NULL && num_commands < SIZE) {
        commands[num_commands++] = token;
        token = strtok(NULL, ";");
    }
    
    for (i = 0; i < num_commands; i++) {
        num_args = 0;
        arg_token = strtok(commands[i], " \t\n");
        while (arg_token != NULL && num_args < 100) {
            args[num_args++] = arg_token;
            arg_token = strtok(NULL, " \t\n");
        }
        args[num_args] = NULL;
        execute_command(args, commands);
   }
    
    return 1;
}

int cd_handler(char **args)
{
        int i = 0;
        char cwd[1024];
        char *newdir;

        if (args[1] == NULL)
        {
                if (chdir(_getenv("HOME")) == -1)
                {
                        perror(args[0]);
                        write(STDERR_FILENO, "cd: can't cd to home\n", 21);
                }
        }
        else
        {
                getcwd(cwd, 1024);
                while (cwd[i] != '\0')
                        i++;
                cwd[i++] = '/';
                cwd[i] = '\0';
                newdir = _strcat(cwd, args[1]);
                if (newdir == NULL)
                        return (0);
                if (chdir(newdir) == -1)
                {
                        perror(args[0]);
                        write(STDERR_FILENO, "can't cd into directory\n", 24);
                }
                free(newdir);
        }
        return (0);
}
int checkBuiltins(char **args)
{
        if (_strcmp((args[0]), "cd") == 0)
                return (cd_handler(args));
	return (0);
}

