#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char *rep;
    static char buffer[50];
    char *ptr;

    rep = (lowercase)
? "0123456789abcdef"
: "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';
    do
    {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
    int i = 0;

    switch (s)
    {
    case '+':
        f->plus = 1;
        i = 1;
        break;
    case ' ':
        f->space = 1;
        i = 1;
        break;
    case '#':
        f->hash = 1;
        i = 1;
        break;
    }

    return (i);
}
