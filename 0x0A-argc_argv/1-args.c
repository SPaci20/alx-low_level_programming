#include <stdio.h>

/**
 * main - Entry point
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to strings containing the arguments
 * Return: 0 (Success)
 */
int main(int argc,__attribute__((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
