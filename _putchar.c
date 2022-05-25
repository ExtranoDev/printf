#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return:( str-a)
 */
int _puts(char *str)
{
	char *a = str;/*declaration of variables*/

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
	write(1, buf, i);
		i = 0;
}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}

	params->precision = d;
	return (p);
}
/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
