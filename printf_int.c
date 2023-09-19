#include "main.h"
/**
 * printf_int - prints integers
 * @list: va_list
 * Return: 1 for success
 */
int printf_int(va_list list)
{
	int number;
	int count = 0;

	number = va_arg(list, int);
	base_conversion(number, 10, &count);
	count++;
	return (count);
}
