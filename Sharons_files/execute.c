#include "main.h"

/**
 * show_prompt - displays prompt
 */

void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
}

/**
 * execute_command - Executes commands passed to the program
 * @args: command to be executed
 * Return: 1 (success) otherwise return 0(fail)
 */

int execute_command(char **args)
{
	int status;
	pid_t pid;

	/*char *command_path = if_command_path(args[0]);*/

	if (access(args[0], X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("./hsh");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			wait(&status);
			return (0);
		}
	}
	perror("./hsh");
	return (1);
}
