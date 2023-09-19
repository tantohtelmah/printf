#include "main.h"
/**
 * printf_octal - prints integers in base 8
 * @list: va_list
 * Return: 1 for success
 */
int printf_octal(va_list list)
{
	int number;
	int count = 0;

	number = va_arg(list, int);
	base_conversion8(number, 8, &count);
	count++;
	return (count);
}
