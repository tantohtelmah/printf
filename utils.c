#include "main.h"
/**
 * _strlen - calculates length of a string
 * @s: char pointer
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != 0)
		len++;
	return (len);
}

/**
 * _strlenconst - calculates length of a string but for a constant char
 * @s: char pointer
 * Return: length
 */
int _strlenconst(const char *s)
{
	int len = 0;

	while (s[len] != 0)
		len++;
	return (len);
}
