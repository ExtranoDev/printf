#include "main.h"

/**
 * conv_to_bin - prints binary representation of a number
 * @num: number
 * @nump: number of char to be printed
 */
void conv_to_bin(unsigned int num, unsigned int *nump)

{
	
	if (num > 1)
	{
		*nump += 1;
		conv_to_bin(num >> 1, nump);
	}
	_putchar((num & 1) + '0');

}
