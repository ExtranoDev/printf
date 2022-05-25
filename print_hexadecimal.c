#include "main.h"

/**
 * print_hex_base - base function for printing hexadecimal numbers
 * @arg: argument list containing hexadecimal
 * @_case: a  in caps on lower, printing the hex number in caps in lower
 * Return: number of digits printed
 */

int print_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = print_unsignedIntToHex(num, _case);

	return (nbrCharacters);
}

/**
 * print_hex - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */
int print_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}

/**
 * print_HEX - prints a hexadecimal in upper case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int print_HEX(va_list arg)
{
	return (print_hex_base(arg, 'A'));
}

/**
 * print_oct - prints number in octal base.
 * @arg: list of num in octal base
 * Return: number of octals printed
 */

int print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int dup;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (_putchar('0'));
	for (dup = num; dup != 0; j++)
	{
		dup /= 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}
