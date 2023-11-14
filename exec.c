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

size_t tokenize_input(char *input, char *tokens[]);

void execute_command(char *input)
{
	pid_t pid;
	int status;

	char *args[MAX_ARGS];

	tokenize_input(input, args);
	pid = fork();
	
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
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
