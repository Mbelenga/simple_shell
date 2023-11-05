#include "main.h"

/**
 * execute_command - Executes commands passed to the program
 * @command: 2nd parameter
 */

void execute_command(char *command)
{
	pid_t pid = fork();

	for (i = 0; i < 10; i++)

	if (pid == 0)

	{
		char *args[] = {input, NULL};

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
		int status;

		waitpid(pid, &pid, &status, 0);
	}
	if (WIFEXITED(status))
	{
		printf("pid exited normally with %d\n", WEXITSTATUS(status));
	}
	return (0);
}
