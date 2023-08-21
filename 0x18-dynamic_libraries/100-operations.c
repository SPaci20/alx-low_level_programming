#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds two integers.
 * @a: The first integer
 * @b: The second integer
 * Return: The sum of a and b
 */
int add(int a, int b)
{
    return (a + b);
}

/**
 * sub - Subtracts two integers.
 * @a: The first integer
 * @b: The second integer
 * Return: The difference between a and b
 */
int sub(int a, int b)
{
    return (a - b);
}

/**
 * mul - Multiplies two integers.
 * @a: The first integer
 * @b: The second integer
 * Return: The product of a and b
 */
int mul(int a, int b)
{
    return (a * b);
}

/**
 * divide - Divides two integers.
 * @a: The first integer (dividend)
 * @b: The second integer (divisor)
 * Return: The quotient of a divided by b
 */
int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Cannot divide by zero\n");
        exit(EXIT_FAILURE);
    }
    return (a / b);
}

/**
 * mod - Computes the remainder of division of two integers.
 * @a: The first integer (dividend)
 * @b: The second integer (divisor)
 * Return: The remainder of a divided by b
 */
int mod(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Cannot divide by zero\n");
        exit(EXIT_FAILURE);
    }
    return (a % b);
}
