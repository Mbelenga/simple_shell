#include "main.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	ssize_t getline_output;
	char *token;
	char *args[MAX_INPUT];
	int i = 0;
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		show_prompt();
		getline_output = getline(&input, &input_size, stdin);

		if (getline_output == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		i = 0;

		token = strtok(input, "\n ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "\n ");
			i++;
		}
		args[i] = NULL;

		if (strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(0);
		}
		else
		{
			execute_command(args);
		}
	}
	return (0);
}
