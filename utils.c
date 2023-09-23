#include "main.h"

/**
 * init_opts - array
 * @options: short
*/
void init_opts(short *options)
{
	options[o_flag] = 0;
	options[o_width] = 0;
	options[o_pres] = 0;
	options[o_len] = 0;
	options[o_conv] = 0;
}

/**
 * init_opt_vals - array
 * @options: option
*/
void init_opt_vals(option *options)
{
	options->hash =  0;
	options->minus = 0;
	options->plus = 0;
	options->presion = 0;
	options->space = 0;
	options->width = 0;
	options->zero = 0;
	options->_long = 0;
	options->_short = 0;
}


/**
 * hex_converter - converts decimals to hexadecimals in lowercase
 * @n: int64_t
 * @counter: int
 * @_case: char
 * Return: integer
*/
void hex_converter(int64_t n, int *counter, char _case)
{
	int64_t rem;

	if (n < 10)
	{
		_putchar(n + '0');
		*counter += 1;
	}
	else
	{
		hex_converter(n / 16, counter, _case);
		rem = n % 16;
		if (rem < 10)
			_putchar(rem + '0');
		else
			_putchar(rem - 10 + (_case == 'x' ? 'a' : 'A'));
		*counter += 1;
	}
}

/**
 * base_conversion - converts from any base less
 * than or equal to ten  and prints results
 * @number: int
 * @base: int
 * @counter: int
 * Return: none
*/
void base_conversion(uint64_t number, unsigned short base, int *counter)
{
	if (number < base)
	{
		_putchar(number + '0');
		*counter += 1;
	}
	else
	{
		/* print the leftmost digits first */
		base_conversion(number / base, base, counter);

		/* print the rightmost digit */
		_putchar(number % base + '0');
		*counter += 1;
	}
}




