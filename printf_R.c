#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * rot13 - decrption
 * @list: va_list
 * Return: int
*/
int rot13(va_list list)
{
	int i;
	char *str, _case;
	int count = 0;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			_case = str[i] >= 'a' ? 'a' : 'A';
			_putchar(((str[i] - _case) + 13) % 26 + _case);
			count++;
		}
		else
		{
			_putchar(str[i] + 1);
			count++;
		}
	}
	return (count);
}
