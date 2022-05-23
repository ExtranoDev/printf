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
	char *str = va_arg(arg, char *);

	if (!str)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (num = 0; str[num] != '\0'; num++)
		_putchar(str[num]);

	return (num);
}

/**
 * print_int - prints number
 * @arg: argument
 *
 * Return: number of char printed
 */
int print_int(va_list arg)
{
	unsigned int i, j = 1, cp = 0, temp;
	int num = va_arg(arg, int);

	if (num < 0)
	{
		_putchar('-');
		cp++;
		num *= -1;
	}

	for (i = 0; num / j > 9; i++, j *= 10)
		;
	for ( ; j >= 1; num %= j, j /= 10, cp++)
	{
		temp = num / j;
		_putchar('0' + temp);
	}
	return (cp);
}

/**
 * print_bin - print binary representation of a num
 * @arg: argument
 * Return: Always 0
 */
int print_bin(va_list arg)
{
	unsigned int nump, num = va_arg(arg, unsigned int);

	conv_to_bin(num, &nump);

	return (nump);
}

