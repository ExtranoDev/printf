#include "main.h"

/**
 * print_STR - prints a string with a `S` (upper case) specificer
 * @arg: argument
 * Return: number of character printed
 */

int print_STR(va_list arg)
{
int i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
{
	if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		if (i < 16)
			_putchar('0');

		print_unsignedIntToHex(str[i], 'A');
	}
	else
		_putchar(str[i]);
}

return (i);
}



/**

 * print_rev - prints a string in reverse

 * @l: argument from _printf

 * @f: pointer to the struct flags that determines

 * if a flag is passed to _printf

 * Return: length of the printed string

 */

int print_rev(va_list l, flags_t *f)

{

	int i = 0, j;

	char *s = va_arg(l, char *);



	(void)f;

	if (!s)

		s = "(null)";



	while (s[i])

		i++;



	for (j = i - 1; j >= 0; j--)

		_putchar(s[j]);



	return (i);

}



/**

 * print_rot13 - prints a string using rot13

 * @l: list of arguments from _printf

 * @f: pointer to the struct flags that determines

 * if a flag is passed to _printf

 * Return: length of the printed string

 */

int print_rot13(va_list l, flags_t *f)

{

	int i, j;

	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	char *s = va_arg(l, char *);



	(void)f;

	for (j = 0; s[j]; j++)

	{

		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')

			_putchar(s[j]);

		else

		{

			for (i = 0; i <= 52; i++)

			{

				if (s[j] == rot13[i])

					_putchar(ROT13[i]);

			}

		}

	}



	return (j);

}



/**

 * print_percent - prints a percent

 * @l: va_list arguments from _printf

 * @f: pointer to the struct flags in which we turn the flags on

 * Return: number of char printed

 */

int print_percent(va_list l, flags_t *f)

{

	(void)l;

	(void)f;

	return (_putchar('%'));

}
