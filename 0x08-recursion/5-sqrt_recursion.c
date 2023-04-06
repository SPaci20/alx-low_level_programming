#include "main.h"
int _sqrt_recursion_helper(int n, int low, int high);

/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: The number whose square root is to be calculated
 *
 * Return: The natural square root of the number if it exists, otherwise -1.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);/* Invalid input */
	}
	return (_sqrt_recursion_helper(n, 0, n));/* Call helper function */
}
/**
 * _sqrt_recursion_helper - Helper function for calculating natural square root
 * @n: The number whose square root is to be calculated
 * @low: The lower end of the range to search
 * @high: The higher end of the range to search
 *
 * Return: The natural square root of the number if it exists, otherwise -1.
 */
int _sqrt_recursion_helper(int n, int low, int high)
{
	int mid = (low + high) / 2;
	int square = mid * mid;

	if (low > high)
	{
		return (-1);/* Number does not have a natural square root */
	}
	else if (square == n) /* Found natural square root */
	{
		return (mid);
	}
	else if (square < n) /* Search upper half of range */
	{
		return (_sqrt_recursion_helper(n, mid + 1, high));
	}
	else /* Search lower half of range */
	{
		return (_sqrt_recursion_helper(n, low, mid - 1));
	}
}
