#include "main.h"
/**
 * printf_int - prints integers
 * @n: int
 * Return: 1 for success
 */
int printf_int(int n)
{
	int rem;

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
		print_int(n / 16);
		rem = n % 16;
		if (rem > 10)
			_putchar(rem + '0');
		else
			_putchar(rem - 10 + 'A');
	}
	return (1);
}
