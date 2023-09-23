#include "main.h"

/**
 * printf_address - prints the address
 * @list: char
 * Return: int
*/

int printf_address(va_list list)
{
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;
	hex_converter(va_arg(list, int64_t), &count, 'x');
	return (count);
}
