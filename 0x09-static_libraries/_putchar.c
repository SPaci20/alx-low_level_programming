#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: On success, return the character written, otherwise -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
