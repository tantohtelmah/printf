#include "main.h"
/**
 * printf_hexX - prints integers
 * @list: va_list
 * Return: count for success
 */
int printf_hexX(va_list list)
{
	int count = 0;
	int hexaX;

	hexaX = va_arg(list, int);
	_putchar('0');
	_putchar('x');
	count += 2;
	hex_converterX(hexaX, &count);
	return (count);
}
