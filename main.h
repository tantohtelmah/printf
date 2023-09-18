#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int _printf(const char *format, ...);
int printf_percent(void);
int printf_string(va_list list);
int printf_char(va_list list);

/* putchar.c */
int _putchar(char);
int buffering(char);

/*utils.c */
int _strlen(char *s);
int _strlenconst(const char *s);

typedef struct _format
{
	char *type;
	int (*f)();
} input_form;



#endif /* MAIN_H */
