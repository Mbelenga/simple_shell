#include "main.h"

/**
 * execute_command - Executes commands passed to the program
 * @input: 2nd parameter
 */

void execute_command(char *input)
{
	int status;
	char *args[2];

	args[0] = input;
	args[1] = NULL;

	pid_t pid = fork();

	if (pid == 0)

	{
		execve(input, args, environ);
		perror("execve error");
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	if (WIFEXITED(status))
	{
		printf("pid exited normally with %d\n", WEXITSTATUS(status));
	}
}
