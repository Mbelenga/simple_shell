#include "main.h"

/**
 * execute_command - Executes commands passed to the program
 * @input: 2nd parameter
 */

void execute_command(char *input)
{
	int status;

	pid_t pid = fork();

	char *args[2];

	args[0] = input;
	args[1] = NULL;

	if (pid == 0)

	{
		execve(input, args, environ);
		perror("Error");
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		if (!isatty(fileno(stdin)))
		{
		}
		{
			waitpid(pid, &status, 0);
		}
	}
}
