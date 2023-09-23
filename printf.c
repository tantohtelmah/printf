#include "main.h"

int _printf(const char *format, ...);

/**
* _printf - prints output to standard output according to a format
* @format: character
* Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int i = 0;
	short options[5];
	char *tmp;
	option opt_vals;
	int start_mark;
	int percent_found;
	int64_t temp;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			percent_found = i;
			init_opts(options);
			init_opt_vals(&opt_vals);
			while (1)
			{
				i++;
				if (strchr(FLAGS, format[i]))
				{
					if (options[o_width] || options[o_pres] || options[o_len])
						break;
					switch (format[i])
					{
					case '#':
						opt_vals.hash = 1;
						break;
					case '0':
						opt_vals.zero = 1;
						break;
					case '-':
						opt_vals.minus = 1;
						break;
					case ' ':
						opt_vals.space = 1;
						break;
					case '+':
						opt_vals.plus = 1;
						break;
					default:
						break;
					}
					options[o_flag] = 1;
				}
				else if (isdigit(format[i]) || format[i] == '*')
				{
					if (options[o_width] || options[o_pres] || options[o_len])
						break;
					if (format[i] == '*')
					{
						opt_vals.width = va_arg(ap, int);
						options[o_width] = 1;
						continue;
					}
					start_mark = i++;
					while (isdigit(format[i]))
						i++;
					tmp = malloc(i - start_mark + 1);
					bzero(tmp, i - start_mark + 1);
					strncpy(tmp, &format[start_mark], i - start_mark);
					opt_vals.width = atoi(tmp);
					free(tmp);
					i--;
					options[o_width] = 1;
				}
				else if (format[i] == '.' && format[i + 1] != '.')
				{
					if (options[o_pres] || options[o_len])
						break;
					i++;
					if (format[i] == '*')
					{
						opt_vals.presion = va_arg(ap, int);
						options[o_pres] = 1;
						continue;
					}
					else if (!isdigit(format[i]))
					{
						i--;
						continue;
					}
					start_mark = i++;
					while (isdigit(format[i++]))
						;
					tmp = malloc(i - start_mark + 1);
					bzero(tmp, i - start_mark + 1);
					strncpy(tmp, &format[start_mark], i - start_mark);
					opt_vals.presion = atoi(tmp);
					free(tmp);
					i--;
				}
				else if (strchr(LENGTH_MODIFIER, format[i]))
				{
					if (options[o_len])
						break;
					switch (format[i])
					{
					case 'l':
						opt_vals._long = 1;
						break;
					case 'h':
						opt_vals._short = 1;
						break;
					default:
						break;
					}
					options[o_len] = 1;
				}
				else if (strchr(CONVERSION, format[i]))
				{
					options[o_conv] = 1;
					break;
				}
				else
				{
					break;
				}
			}
			if (!options[o_conv])
			{
				_putchar(format[percent_found]);
				if (format[i] == '%')
					i = percent_found + 1;
				else
					i = percent_found;
				count++;
			}
			switch (format[i])
			{
			case 'd':
			case 'i':
				if (options[o_len] && opt_vals._long)
					temp = va_arg(ap, int64_t);
				else if (options[o_len] && (opt_vals._short))
					temp = (short)va_arg(ap, int);
				else
					temp = va_arg(ap, int);
				if (temp < 0)
				{
					_putchar('-');
					count++;
					temp *= -1;
				}
				base_conversion(temp, BASE10, &count);
				break;
			case 'x':
				hex_converter(va_arg(ap, unsigned int), &count, 'x');
				break;
			case 'X':
				hex_converter(va_arg(ap, unsigned int), &count, 'X');
				break;
			case 'o':
				base_conversion(va_arg(ap, unsigned int), BASE8, &count);
				break;
			case 'p':
				count += printf_address(ap);
				break;
			case 'b':
				base_conversion(va_arg(ap, unsigned int), BASE2, &count);
				break;
			case 'c':
				_putchar(va_arg(ap, int));
				count++;
				break;
			case 's':
				count += printf_string(ap);
				break;
			case 'S':
				count += printf_S(ap);
				break;
			case 'u':
				if (options[o_len] && opt_vals._long)
					base_conversion(va_arg(ap, uint64_t), BASE10, &count);
				else if (options[o_len] && (opt_vals._short))
					base_conversion((unsigned short)va_arg(ap, uint64_t), BASE10, &count);
				else
					base_conversion(va_arg(ap, unsigned int), BASE10, &count);
				break;
			case 'r':
				count += printf_string_r(ap);
				break;
			case 'R':
				count += rot13(ap);
				break;
			default:
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
