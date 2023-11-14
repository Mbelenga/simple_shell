#include "main.h"

/**
 * show_prompt - displays prompt
 */

void show_prompt()
{
	printf("$ ");
	fflush(stdout);
}

/**
 * execute_command - Executes commands passed to the program
 * @input: command to be executed
 */

void execute_command(char *input)
{
	pid_t pid;
	int status;

	char *args[2];

	args[0] = input;
	args[1] = NULL;

	pid = fork();

	if (pid == 0)

	{
		if (execve(input, args, NULL) == -1)
		{
			perror("./hsh");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}
}
