#include <unistd.h>

/**
 * _putchar - output one byte of char
 * @s: the char to print
 * Return: always the char
 */
int _putchar(char s)
{
	return (write(1, &s, 1));
}
