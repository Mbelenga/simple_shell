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
 */

int execute_command(char **args)
{
	int status;
	pid_t pid;

	if (access(args[0], X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("./hsh");
			return(1);
		}
		if (pid == 0)
		{
			execve(args[0], args, NULL);
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
