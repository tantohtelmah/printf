#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int _printf(const char *format, ...);
int printf_percent(void);
int printf_string(va_list list);
int printf_char(va_list list);
int printf_address(va_list list);
int printf_hex(va_list list);
int printf_hexX(va_list list);
int printf_int(va_list list);
int printf_dec(va_list, list);
int printf_binary(va_list list);
int printf_octal(va_list list);
int printf_unsigned_int(va_list list);

/* putchar.c */
int _putchar(char c);
int buffering(char);

/*utils.c */
int _strlen(char *s);
int _strlenconst(const char *s);
void hex_converterX(int n, int *counter);
void hex_converter(int64_t n, int *counter);
void base_conversion(int number, int base, int *counter);

/*utils2.c*/
void base_conversion8(int number, int base, int *counter);
void binary_conversion(int bi_num, int *counter);
void unsigned_con(int num, int *counter);

/**
 * struct _format - structure
 * @type: char
 * @f: int (function pointer)
*/
typedef struct _format
{
	char *type;
	int (*f)();
} input_form;



#endif /* MAIN_H */
