#include "main.h"
#define BUFFER_SIZE 1024

void handle_semicolon(char *line, char **argv)
{
        char *command, **args;
        char *semicolon_ptr, *exit_status = NULL;
        int command_len, num;
        char line_copy[BUFFER_SIZE];
        char *command_copy = NULL;

        strcpy(line_copy, line);
        semicolon_ptr = strchr(line_copy, ';');

        if (semicolon_ptr != NULL)
        {
                command = strtok(line_copy, ";");
                while (command != NULL)
                {
			exit_status = 0;
                        command_len = strlen(command);
                        command_copy = malloc(sizeof(char) * (command_len + 1));
                        strcpy(command_copy, command);
                        args = malloc(sizeof(char *) * (command_len + 1));
                        parse_input(command_copy, args, &num);

                        command = strtok(NULL , ";");
			
			execute_command(args, argv);
                	free(args);
                	free(command_copy);
                	args = NULL;
                	num = 0;
			if(exit_status != 0){
				break;
			}
       		}
	}
}

