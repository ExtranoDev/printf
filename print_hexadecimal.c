#include "main.h"



/**

 * print_hex - prints a number in hexadecimal base,

 * in lowercase

 * @l: va_list arguments from _printf

 * @f: pointer to the struct flags that determines

 * if a flag is passed to _printf

 * Description: the function calls convert() which in turns converts the input

 * number into the correct base and returns it as a string

 * Return: the number of char printed

 */

int print_hex(va_list l, flags_t *f)

{

    unsigned int num = va_arg(l, unsigned int);

    char *str = convert(num, 16, 1);

    int count = 0;



    if (f->hash == 1 && str[0] != '0')

        count += _puts("0x");

    count += _puts(str);

    return (count);

}



/**

 * print_hex_big - prints a number in hexadecimal base,

 * in uppercase

 * @l: va_list arguments from _printf

 * @f: pointer to the struct that determines

 * if a flag is passed to _printf

 * Description: the function calls convert() which in turns converts the input

 * number into the correct base and returns it as a string

 * Return: the number of char printed

 */

int print_hex_big(va_list l, flags_t *f)

{

    unsigned int num = va_arg(l, unsigned int);

    char *str = convert(num, 16, 0);

    int count = 0;



    if (f->hash == 1 && str[0] != '0')

        count += _puts("0X");

    count += _puts(str);

    return (count);

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
