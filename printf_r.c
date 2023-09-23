#include "main.h"
/**
 * printf_string_r - prints a string
 * @list: arguments
 * Return: string length
 */

int printf_string_r(va_list list)
{
	char *s;
	int i, count;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	count = strlen(s);
	for (i = count; i >= 0; i--)
		_putchar(s[i]);
	return (count);
}
