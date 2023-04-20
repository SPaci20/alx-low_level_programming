#include <stdio.h>
#include <stdarg.h>
/**
 * sum_them_all - Calculate the sum of n numbers.
 * @n: The number of arguments to sum.
 * @...: Variable number of arguments to sum.
 * Return: The sum of the n numbers.
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int sum;

	va_start(ap, n);
	sum = 0;
	for (i=0; i < n ; i++)
		sum += va_arg (ap, int);
	va_end (ap);

		return sum;
}
