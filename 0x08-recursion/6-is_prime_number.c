#include "main.h"
/**
 * _is_prime_number - Return 1 for prime number otherwise 0
 * @n: Value of number
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	int i;

	if (n <= 1)
	{
		return (0);
	}
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}
