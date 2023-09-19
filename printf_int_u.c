#include "main.h"
/**
 * printf_unsigned_int - prints integers
 * @list: va_list
 * Return: 1 for success
 */
int printf_unsigned_int(va_list list)
{
	int n;
	int count = 0;

	n = va_arg(list, int);
	unsigned_con(n, &count);
	return (count);
}
