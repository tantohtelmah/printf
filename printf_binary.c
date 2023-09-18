#include "main.h"
#include <stdio.h>

/**
 * printf_binary - prints binary numbers of decimal numbers
 * @n: integer
 * Return: int
*/
int printf_binary(int n)
{
	if (n == 0)
	{
		return (0);
	}
	printf_binary(n / 2);
	_putchar(n % 2 + '0');
}
