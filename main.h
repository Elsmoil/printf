#ifndef _PRINTF_H
#define _PRUNTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED 	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @plus_flag: on if plus_flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * l_modifier: on if l_modifier is specified
 * h_modifier: on if h_modifier is specified
 */
typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int l_modifier		: 1;
	unsigned int h_modifier		: 1;
} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: The function
 */
typedef struct specifier
{
	char *specifier;
	int (*f) (va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

#endif
