#include "main.h"



/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */

int print_unsigned(va_list arg)
{
int div = 1, i, pstr;
unsigned int n = va_arg(arg, unsigned int);

for (i = 0; n / div > 9; i++, div *= 10)
;

for (; div >= 1; n %= div, div /= 10)
{
	pstr = n / div;
	_putchar('0' + pstr);
}
return (i + 1);
}



/**

 * print_number - helper function that loops through

 * an integer and prints all its digits

 * @n: integer to be printed

 */

void print_number(int n)

{

    unsigned int n1;



    if (n < 0)

    {

        _putchar('-');

        n1 = -n;

    }

    else

        n1 = n;



    if (n1 / 10)

        print_number(n1 / 10);

    _putchar((n1 % 10) + '0');

}



/**

 * count_digit - returns the number of digits in an integer

 * for _printf

 * @i: integer to evaluate

 * Return: number of digits

 */

int count_digit(int i)

{

    unsigned int d = 0;

    unsigned int u;



    if (i < 0)

        u = i * -1;

    else

        u = i;

    while (u != 0)

    {

        u /= 10;

        d++;

    }

    return (d);

}
