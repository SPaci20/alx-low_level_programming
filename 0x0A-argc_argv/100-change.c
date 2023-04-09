#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of coins to make change
 * for an amount of money
 *
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 if successful, 1 if there is an error
 */
int main(int argc, char *argv[])
{
	int cents, num_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	num_coins = 0;

	num_coins += cents / 25;
	cents %= 25;

	num_coins += cents / 10;
	cents %= 10;

	num_coins += cents / 5;
	cents %= 5;

	num_coins += cents / 2;
	cents %= 2;

	num_coins += cents;

	printf("%d\n", num_coins);
	return (0);
}
