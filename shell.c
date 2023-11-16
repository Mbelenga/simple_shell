#include "main.h"

/**
 * main - entry point
 * Return: Always 0
 */

int main(void)
{
<<<<<<< HEAD
        ssize_t getline_output;
	char *token;

	char **args = malloc(sizeof(char *));
	
	int i = 0;

	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		show_prompt();
		getline_output = getline(&input, &input_size, stdin);

		if (getline_output == -1)
			exit(1);
		token = strtok(input, "\n ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "\n ");
			i++;
		}
		args[i] = '\0';

		if (strcmp(args[0], "exit") == 0)
		{
			exit(1);
		}
		else if (strcmp(args[0], "/bin/ls") == 0)
		{
			execute_command(args);
		}
		else if (strcmp(args[0], "ls") == 0)
		{
			/*args[0] = "/bin/ls";*/
			execute_command(args);
		}
		else
		{
			/*execute_command(args);*/
		}
		
	free (args);
	}
	free(input);

	return (0);
=======
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
	ssize_t getline_output;
	size_t len;

	getline_output = getline(&input, &input_size, stdin);

	if (getline_output == -1)
	{
		free(input);
		if (feof(stdin))
		{
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
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
>>>>>>> d17b50ff0ca40ea4e2267b1a0f35b0525f6b8d09
}
