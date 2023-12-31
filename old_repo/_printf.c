#include "main.h"
/**
* _printf - prints output to standard output according to a format
* @format: character
* Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int input_size = 0;
	int pattern_size = 10;
	int i = 0, j;
	short found = 0;

	input_form pattern[] = {
		{"%s", printf_string},
		{"%c", printf_char},
		{"%%", printf_percent},
		{"%p", printf_address},
		{"%x", printf_hex},
		{"%X", printf_hexX},
		{"%i", printf_int},
		{"%d", printf_int},
		{"%b", printf_binary},
		{"%o", printf_octal},
		{"%u", printf_unsigned_int}
	};
	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		j = pattern_size;
		found = 0;
		while (j >= 0)
		{
			if (pattern[j].type[0] == format[i] && pattern[j].type[1] == format[i + 1])
			{
				input_size += pattern[j].f(ap);
				i = i + 2;
				found = 1;
				break;
			}
			j--;
		}
		if (!found)
		{
			_putchar(format[i]);
			i++;
			input_size++;
		}
		
	}
	va_end(ap);
	return (input_size);
}
