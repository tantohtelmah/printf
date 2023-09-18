#include <stdarg.h>
#include <stdio.h>

/**
* _printf - prints output to standard output according to a format
* @format: character
* Return: integer
*/

int _printf(const char *format, ...)
{
	/* Declaring variables */
	va_list args;

	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
	return (0);
}
