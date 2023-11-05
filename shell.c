#include "shell.h"

/**
 * main - entry point
 * Return: Always 0
 */

int main(void)
{
	char *command;

	for (;;)

	{
		show_prompt();
		command = read_input();
		if (command == NULL)
		{
			break;
		}
		execute_command(command);
		free(command);
	}
	return (0);
}

/**
 * read_input - Reads a line from stdin
 * Return: String containing the user input.
 */

char *read_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_length;
	size_t len;

	getline_output = getline(&input, &input_size, stdin);

	if (getline_output == -1)
	{
		free(input);
		return (NULL);
	}

	len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
	{
		input[len - 1] = '\0';
	}
	if (len >= MAX_INPUT_SIZE)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
