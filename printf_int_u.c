#include "main.h"
/**
 * printf_unsignedint - prints integers
 * @n: int
 * Return: 1 for success
 */
int printf_unsignedint(int n)
{
	if (n == 0)
	{
		putchar('0');
	}
	else
	{
		/* print the leftmost digits first */
		print_int(n / 10);

		/* print the rightmost digit */
		_putchar(n % 10 + '0');
	}
	return (1);
}
