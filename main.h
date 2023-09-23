#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define FLAGS "#0-+ "
#define CONVERSION "cdipuxXsSrRob"
#define LENGTH_MODIFIER "lh"
#define BASE2 2
#define BASE8 8
#define BASE10 10

/**
 * struct options - structure
 * @hash: int
 * @plus: int
 * @minus: int
 * @space: int
 * @zero: int
 * @width: int
 * @presion: int
 * @_short: int
 * @_long: int
*/

typedef struct options
{
	int hash;
	int plus;
	int minus;
	int space;
	int zero;
	int width;
	int presion;
	int _short;
	int _long;
} option;

/**
 * enum opt - enum
 * @o_flag: opt
 * @o_width: opt
 * @o_pres: opt
 * @o_len: opt
 * @o_conv: opt
 * @opt: opt
*/

typedef enum opt
{
	o_flag, o_width, o_pres, o_len, o_conv
} opt;

int _putchar(char c);

int _printf(const char *format, ...);
int printf_percent(void);
int printf_string(va_list list);
int printf_char(va_list list);
int printf_address(va_list list);
int printf_hex(va_list list, char);
int printf_int(int64_t number);
int printf_int_u(uint64_t number);
int printf_decimal(va_list list);
int printf_binary(va_list list);
int printf_octal(va_list list);
int printf_string_r(va_list list);
int rot13(va_list list);
int printf_S(va_list list);

/* structDeclare */
void pattern(void);

/* putchar.c */

int buffering(char);

/*utils.c */
void init_opts(short *options);
void init_opt_vals(option *options);
void hex_converter(int64_t n, int *counter, char _case);
void base_conversion(uint64_t number, unsigned short base, int *counter);

/*utils2.c*/





#endif /* MAIN_H */
