#include "main.h"
/**
 * printf_string - prints a string
 * @list: arguments
 * Return: string length
 */

int printf_string(va_list list)
{
	char *s;
	int i, count;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	count = strlen(s);
	for (i = 0; i < count; i++)
		_putchar(s[i]);
	return (count);
}
