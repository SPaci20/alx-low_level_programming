#include "main.h"
/**
 * _is_prime_recursion - using recursion to check primality
 * is_prime_number - checks if an integer is prime
 *
 * @n: the number to check
 * @divisor: the current divisor being tested for primality
 * Return: 1 if n is prime, 0 otherwise
 */

int _is_prime_recursion(int n, int divisor)
{
	if (n <= 1)
	{
		return (0);
	}
	if (divisor == 1)
	{
		return (1);
	}
	if (n % divisor == 0)
	{
		return (0);
	}
	return (_is_prime_recursion(n, divisor - 1));
}

int is_prime_number(int n)
{
	return (_is_prime_recursion(n, n - 1));
}

