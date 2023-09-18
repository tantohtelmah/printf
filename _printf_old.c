#include <stdarg.h>
#include <stdio.h>

/**
* _printf - prints output to standard output according to a format
* @format: character
* Return: number of printed characters
*/

int _printf_old(const char *format, ...)
{
	/* Declaring variables */
	va_list ap;
	int input_size;

	if (format == NULL)
		return (-1);

	input_size = _strlen(format);
	if (input_size <= 0)
		return (0);

	va_start(ap, format);
	input_size = helper(format, ap);

	_putchar(-1);
	va_end(ap);

	return (input_size);
}
