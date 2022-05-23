#include "main.h"

/**
 * _printf - prints formatted string
 * @format: formatted string
 * Description: function works on displaying formatted string appropriately
 */

int _printf(const char *format, ...)
{
	unsigned int n;
	va_list args;
	int count = 0, countID = 0;

	va_start(args, format);

	for (n = 0; format[n]; n++)
	{
		if (format[n] != '%')
		{
			_putchar(format[n]);
			count++;
			continue;
		}
		if (format[n + 1] == '%')
		{
			_putchar('%');
			n++;
			count++;
			continue;
		}
		if (format[n + 1] == '\0')
			return (-1);
		countID = printID(format[n + 1], args);
		if (countID == -1 || countID != 0)
			n++;
		if (countID > 0)
			count += countID;

		if (countID == 0)
		{
			_putchar('%');
			count++;
		}
	}
	va_end(args);
	return (count);
}
