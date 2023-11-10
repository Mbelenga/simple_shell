#include "main.h"

/**
 * my_strlen - calculates the length of string
 * @my_str: my string
 * Return: number of characters
 */
size_t my_strlen(const char *my_str)
{
	size_t length = 0;

	while (my_str[length] != '\0')
	{
	length++;
	}

	return (length);
}
