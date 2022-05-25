#ifndef SMARTPRINT_H
#define SMARTPRINT_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char s);
int _printf(const char *format, ...);
int printID(char format1, va_list args);
int print_char(va_list arg);
int print_str(va_list arg);
int print_int(va_list arg);
int print_bin(va_list arg);
void conv_to_bin(unsigned int num, unsigned int *nump);

/**
 * struct structID - structure definition
 * @ID: type
 * @outter: function to print
 */
typedef struct structID
{
	char *ID;
	int (*outter)(va_list);
} structID;

#endif
