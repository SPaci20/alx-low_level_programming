#include "main.h"
/**
 * _pow_recursion - Return the value of x raised by the power of y
 *@x : value that will be powered
 * @y: any given integer that will be used as power
 * Return: Value of x powered by y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1); /* negative exponent not allowed */
	}
	if (y == 0)
	{
		return (1);/* Any nber exposed by 0 is 1 */
	}
	return (x * _pow_recursion(x, y - 1));
}
