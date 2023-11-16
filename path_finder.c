#include "main.h"

/**
 * command_path - checks if the command exists
 * @command: command being checked
 * Return: command type
 */

int if_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	int command_found = 0;

	while (dir != NULL)
	{
		char command_path[MAX_INPUT];
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);

		if (access(command_path, X_OK) == 0)
		{
			command_found = -1;
			break;
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);

	return (command_found);
}
