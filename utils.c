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

/**
 * hex_converter - converts decimals to hexadecimals
 * @n: int64_t
 * @counter: int
 * Return: integer
*/
void hex_converter(int64_t n, int *counter)
{
	int rem;

	if (n < 10)
	{
		_putchar(n + '0');
		*counter += 1;
	}
	else
	{
		hex_converter(n / 16, counter);
		rem = n % 16;
		if (rem < 10)
			_putchar(rem + '0');
		else
			_putchar(rem - 10 + 'a');
		*counter += 1;
	}
}
