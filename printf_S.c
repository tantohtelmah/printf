#include "main.h"
/**
 * printf_S - prints a string with non-printable characters
 * @list: arguments
 * Return: string length
 */

int printf_S(va_list list)
{
	char *s;
	int i, count;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; i < count; i++)
	{
		if (!isprint(s[i]))
		{
			count += 2;
			_putchar('\\');
			_putchar('x');
			hex_converter(s[i], &count, 'X');
		}
		else
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
