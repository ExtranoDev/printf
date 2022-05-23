#ifndef SMARTPRINT_H
#define SMARTPRINT_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char s);
int _printf(const char *format, ...);
int printID(char format1, va_list args);

typedef struct structID
{
	char *ID;
	int (*outter)(va_list);
} structID;

#endif
