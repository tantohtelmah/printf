#include "main.h"
/**
 * printf_octal - prints integers in base 8
 * @n: int
 * Return: 1 for success
 */
int printf_octal(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		putchar('0');
	}
	else
	{
		/* print the leftmost digits first */
		print_int(n / 18);

		/* print the rightmost digit */
		_putchar(n % 8 + '0');
	}
	return (1);
}