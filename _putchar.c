#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (buffering(c));
}

/**
 * buffering - saves characters in a buffer before printing
 * @c: character to print
 *
 * Return: 1 on success
 */
int buffering(char c)
{
	static char buffer[1024];
	static int index;

	if (index == 1024 || c == -1)
	{
		write(1, buffer, index);
		index = 0;
	}

	if (c != -1)
		buffer[index++] = c;

	return (1);
}

