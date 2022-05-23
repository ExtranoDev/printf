#include "main.h"

/**
 * print_char - output char to stdout
 * @arg: argument
 *
 * Return: 1 on success else -1 with 
 * appropriate errno
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_str - output a string to stdout
 * @arg: argument
 *
 * Return: number of char printed
 */
int print_str(va_list arg)
{
	int num;
	char *str = va_arg(arg, char*);

	if (!str)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (num = 0; str[num] != '\0'; num++)
		_putchar(str[num]);

	return (num);
}
