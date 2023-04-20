#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on the format string provided
 * @format: The format string representing the types of arguments
 *   - 'c' for char
 *   - 'i' for integer
 *   - 'f' for float (as double in C89)
 *   - 's' for char *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char c;
	int i_val;
	double f_val;
	char *s_val;

	va_start(args, format);

	while (format && format[i])
	{
		if (i > 0)
			printf(", ");

		switch (format[i])
		{
		case 'c':
			c = va_arg(args, int);
			printf("%c", c);
			break;
		case 'i':
			i_val = va_arg(args, int);
			printf("%d", i_val);
			break;
		case 'f':
			f_val = va_arg(args, double);
			printf("%f", f_val);
			break;
		case 's':
			s_val = va_arg(args, char *);
			if (s_val == NULL)
				s_val = "(nil)";
			printf("%s", s_val);
			break;
		default:
			break;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}
