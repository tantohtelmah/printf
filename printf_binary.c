#include "main.h"
#include <stdio.h>

/**
 * printf_binary - prints binary numbers of decimal numbers
 * @list: va_list
 * Return: int
*/
int printf_binary(va_list list)
{
	int bi_num;
	int count = 0;

	bi_num = va_arg(list, int);
	binary_conversion(bi_num, &count);
	return (count);
}
